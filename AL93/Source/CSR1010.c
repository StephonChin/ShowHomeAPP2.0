/*************************************************************************
	*
	* @FileName		Csr1010.c
	* @Date				2017.03.10
	* @Author			DS.Chin
	* @Description
	*							| Communicate to CSR1010
	*							| Receive data from APP
	* 						| Send dato to APP
	*
***************************************************************************/
#include "Csr1010.h"



/* <-------------Gloable Variables-------------------> */
_TypeStructRcv 	RcvData;
_TypeStructSnd 	SndData;
_Flag						RcvDoneFlag;


/* <-------------File Variables----------------------> */
_Uint8	RcvBuffer[RCV_BYTE_MAX];
enum
{
	RCV_IDLE,
	RCV_STT,
	RCV_END,
	RCV_ERR
}RcvByteStatus;



/*********************************************************
	*
	* @FunctionName	Csr1010_Init
	*
*****/
void Csr1010_Init(void)
{
	SndData.SndByteDoneFlag	= FALSE;
}


/**********************************************************
	*
	* @FunctionName	Uart_Interrupt
	*
****/
void Uart_Interrupt(void) interrupt 15
{
	/* When receive interrupt flag been set */
	if (RI_1)
	{
		RI_1 = RESET;
		Csr1010_Rcv_Byte();
	}
	
	/* When send interrput flag been set */
	if (TI_1)
	{
		TI_1 = RESET;
		SndData.SndByteDoneFlag = FALSE;
	}
	
	return;
}






/***********************************************************
	*
	* @FunctionName	Csr1010_Rcv_Byte
	*
****/
static void Csr1010_Rcv_Byte(void)
{
	static _Uint8		ByteCnt;
				 _Uint8		RcvBufferTemp = 0;
	
	
	// move receive data to RcvBuffer
	RcvBufferTemp = SBUF_1;
	
	// start to receive data when receive status is idle
	if (RcvByteStatus == RCV_IDLE)
	{
		if (RcvBufferTemp == 0xFD)
		{
			RcvByteStatus 	= RCV_STT;
			ByteCnt = 0;
		}
	}
	
	// receive the data 
	else if (RcvByteStatus == RCV_STT)
	{
		if (RcvBufferTemp == 0xFE)			RcvByteStatus 					= RCV_END;									/* Rcv End */
		else if (ByteCnt >= 6)					RcvByteStatus 					= RCV_ERR;									/* Rcv Err */		
		else														RcvBuffer[ByteCnt++] 		= RcvBufferTemp;						/* Rcving */ 
	}
}







/************************************************************
	*
	* @FunctionName	Csr1010_Rcv_Data
	*
****/
void Csr1010_Rcv_Data(void)
{
	static _Uint8		RcvSttHoldTime;		
				 _Uint8		TempCnt = 0;
	
	
	/* Exit when receive status is idle or working */
	if (RcvByteStatus == RCV_IDLE)
	{
		RcvSttHoldTime = 0;
		return;
	}
	
	
	/* Hold time after received, if timer > 1second, received err, then clear the data */
	if (RcvByteStatus == RCV_STT)
	{
		RcvSttHoldTime++;
		if (RcvSttHoldTime > 100)
		{
			RcvSttHoldTime 	= 0;
			RcvByteStatus		= RCV_IDLE;
		}
		return;
	}
	
	
	/* received error */
	if (RcvByteStatus == RCV_ERR)
	{
		for (TempCnt = 0; TempCnt < 6; TempCnt++)		RcvBuffer[TempCnt]	= 0;			// clear the buffer
		RcvByteStatus = RCV_IDLE;																									// clear the status
		return;
	}
	
	
	/* received success */
	if (RcvByteStatus == RCV_END)
	{
		RcvDoneFlag	= TRUE;
		for (TempCnt = 0; TempCnt < 6; TempCnt++)									// move the buffer to rcvdata
		{
			RcvData.DataBuf[TempCnt]	= RcvBuffer[TempCnt];
			RcvBuffer[TempCnt] 				= 0;
		}
		RcvByteStatus = RCV_IDLE;																	// clear status
	}
}










/***********************************************************
	*
	* @FunctionName	Csr1010_Snd_Data
	*
*****/
void Csr1010_Snd_Data(void)
{
	_Uint8	TempCnt = 0;
	
	/* when snd data is idle , exit */
	if (SndData.SndStatus == SND_IDLE)
	{
		SndData.SndByteDoneFlag 	= FALSE;
		SndData.SndCnt						= 0;
		SndData.InitFlag					= TRUE;
		SndData.TimeDelay					= 0;
		return;
	}
	
	/* type send LA1 */
	if (SndData.SndStatus == SND_TYPE)
	{
		// Send type command "LA1"
		Csr1010_Snd_Byte(0xFC);
		Csr1010_Snd_Byte('L');
		Csr1010_Snd_Byte('A');
		Csr1010_Snd_Byte('2');
		Csr1010_Snd_Byte(0xFE);
		
		// Send power on command after type command sent completed
		SndData.SndStatus = SND_NORMAL;	
		SndData.InitFlag	= TRUE;
		SndData.SndCnt		= 0;
		SndData.TimeDelay	= 0;
		for (TempCnt = 0; TempCnt < 8; TempCnt++)		SndData.DataBuf[TempCnt] = 0;
		SndData.DataBuf[0]	= 0x1;
		return;
	}
	
	
	/* Send normally */
	if (SndData.SndStatus == SND_NORMAL)
	{
		if (SndData.InitFlag == TRUE)
		{
			SndData.InitFlag	= FALSE;
			Csr1010_Snd_Byte(0xFD);
			for (TempCnt = 0; TempCnt < 8; TempCnt++)		Csr1010_Snd_Byte(SndData.DataBuf[TempCnt]);
			Csr1010_Snd_Byte(0xFE);
		}
		else
		{
			SndData.SndCnt++;
			if (SndData.SndCnt >= 2)
			{
				SndData.SndCnt = 0;
				SndData.SndStatus = SND_IDLE;
			}
			else
			{
				SndData.TimeDelay++;
				if (SndData.TimeDelay >= 10)
				{
					SndData.TimeDelay = 0;
					SndData.InitFlag	= TRUE;
				}
			}
		}
	}
}



/******************************************************
	*
	* @Function Name	Csr1010_Snd_Byte
	*
****/
static void Csr1010_Snd_Byte(_Uint8 SndBuf)
{
	while (SndData.SndByteDoneFlag);
	SBUF_1 = SndBuf;
	SndData.SndByteDoneFlag = TRUE;
}

