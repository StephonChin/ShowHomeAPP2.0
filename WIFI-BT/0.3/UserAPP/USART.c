/********************************************************************
  *
  * FILE NAME      USART.c
  *
*********************************************************************/
#include "USART.h"

//--------------------< Gloable Paramters >--------------------------
_TypeStructRcv 	RcvData[2];
_TypeStructSnd 	SndData[2];
_Flag			      RcvFlag[2];


//--------------------< File Paramters >--------------------------
idata _Uint8	RcvBuffer[2][RCV_BYTE_MAX];
enum ENUM_STATUS
{
	RCV_IDLE,
	RCV_STT,
	RCV_END,
	RCV_ERR
}RcvByteStatus[2];
_Uint8		RcvSttHoldTime[2];
_Uint8		Usart0ByteCnt;



/*********************************************************
	*
	* FunctionName	USART_Data_Init
	*
**********************************************************/
void USART_Data_Init(void)
{
  SndData[0].SndByteDoneFlag	= FALSE;
	SndData[1].SndByteDoneFlag	= FALSE;
  RcvSttHoldTime[0] = 0;
  RcvSttHoldTime[1] = 0;
  RcvByteStatus[0] = RCV_IDLE;
  RcvByteStatus[1] = RCV_IDLE;
}


/**********************************************************
	*
	* FunctionName	USART1_Interrupt
	*
***********************************************************/
void USART1_Interrupt(void) interrupt 15
{
	/* When receive interrupt flag been set */
	if (RI_1)
	{
		RI_1 = RESET;
		USART1_Rcv_Byte();
	}
	
	/* When send interrput flag been set */
	if (TI_1)
	{
		TI_1 = RESET;
		SndData[1].SndByteDoneFlag = FALSE;
	}
	
	return;
}



/**********************************************************
	*
	* FunctionName	USART0_Interrupt
	*
***********************************************************/
void USART0_Interrupt(void) interrupt 4
{
	/* When receive interrupt flag been set */
	if (RI)
	{
		RI = RESET;
		USART0_Rcv_Byte();
	}
	
	/* When send interrput flag been set */
	if (TI)
	{
		TI = RESET;
		SndData[0].SndByteDoneFlag = FALSE;
	}
	
	return;
}




//----------------------------------------------------------
// FunctionName	USART1_Rcv_Byte
//----------------------------------------------------------
static void USART1_Rcv_Byte(void)
{
	static _Uint8		Usart1ByteCnt;
				 _Uint8		RcvBufferTemp = 0;
	
	
	// move receive data to RcvBuffer
	RcvBufferTemp = SBUF_1;
  
  RcvSttHoldTime[1] = 0;
	
	// start to receive data when receive status is idle
	if (RcvByteStatus[1] == RCV_IDLE)
	{
		if (RcvBufferTemp == 0xFD)
		{
			RcvByteStatus[1] 	= RCV_STT;
			Usart1ByteCnt = 0;
		}
	}
	
	// receive the data 
	else if (RcvByteStatus[1] == RCV_STT)
	{
		if (RcvBufferTemp == 0xFE)			      RcvByteStatus[1] 		            = RCV_END;									// Rcv End
		else if (Usart1ByteCnt >= 6)				  RcvByteStatus[1] 	              = RCV_ERR;								  // Rcv Err	
		else								                  RcvBuffer[1][Usart1ByteCnt++] 	= RcvBufferTemp;						// Rcving
	}
}


//----------------------------------------------------------
// FunctionName	USART0_Rcv_Byte
//----------------------------------------------------------
static void USART0_Rcv_Byte(void)
{
	_Uint8		RcvBufferTemp = 0;
	
	
	// move receive data to RcvBuffer
	RcvBufferTemp = SBUF;
  
  RcvSttHoldTime[0] = 0;
	
	// start to receive data when receive status is idle
	if (RcvByteStatus[0] == RCV_IDLE)
	{
    RcvByteStatus[0] 	= RCV_STT;
    Usart0ByteCnt     = 0;
	}
	
	// receive the data 
	if (RcvByteStatus[0] == RCV_STT)
	{
    RcvBuffer[0][Usart0ByteCnt++] = RcvBufferTemp;
		if (Usart0ByteCnt >= RCV_BYTE_MAX)				  RcvByteStatus[0] = RCV_IDLE;								// Rcv Err	
	}
}




/************************************************************
	*
	* FunctionName	Csr1010_Rcv_Data
	*
*************************************************************/
void Csr1010_Rcv_Data(void)
{		
  _Uint8		TempCnt = 0;
	
	
	/* Exit when receive status is idle or working */
	if (RcvByteStatus[1] == RCV_IDLE)
	{
		RcvSttHoldTime[1] = 0;
		return;
	}
	
	
	/* Hold time after received, if timer > 1second, received err, then clear the data */
	if (RcvByteStatus[1] == RCV_STT)
	{
		RcvSttHoldTime[1]++;
		if (RcvSttHoldTime[1] > 5)  // 50ms
		{
			RcvSttHoldTime[1] 	= 0;
			RcvByteStatus[1]	= RCV_IDLE;
		}
		return;
	}
	
	
	/* received error */
	if (RcvByteStatus[1] == RCV_ERR)
	{
		for (TempCnt = 0; TempCnt < 6; TempCnt++)		RcvBuffer[1][TempCnt]	= 0;			// clear the buffer
		RcvByteStatus[1] = RCV_IDLE;																									// clear the status
		return;
	}
	
	
	/* received success */
	if (RcvByteStatus[1] == RCV_END)
	{
		RcvFlag[1]	= TRUE;
		for (TempCnt = 0; TempCnt < 6; TempCnt++)									// move the buffer to rcvdata
		{
			RcvData[1].DataBuf[TempCnt]	= RcvBuffer[1][TempCnt];
			RcvBuffer[1][TempCnt] 			= 0;
		}
		RcvByteStatus[1] = RCV_IDLE;																	// clear status
	}
}










/***********************************************************
	*
	* FunctionName	Csr1010_Snd_Data
	*
************************************************************/
void Csr1010_Snd_Data(void)
{
	_Uint8	TempCnt = 0;
	
	/* when snd data is idle , exit */
	if (SndData[1].SndStatus == SND_IDLE)
	{
		return;
	}
	
	/* type send LA1 */
	if (SndData[1].SndStatus == SND_TYPE)
	{
		// Send type command "LA1"
		USART1_Snd_Byte(0xFC);
		USART1_Snd_Byte('V');
		USART1_Snd_Byte('W');
		USART1_Snd_Byte('B');
    USART1_Snd_Byte('0');
    USART1_Snd_Byte('0');
    USART1_Snd_Byte('0');
    USART1_Snd_Byte('0');
		USART1_Snd_Byte(0xFE);
		
		// Send power on command after type command sent completed
		SndData[1].SndStatus = SND_IDLE;	
		return;
	}
	
	
	/* Send normally */
	if (SndData[1].SndStatus == SND_NORMAL)
	{
		USART1_Snd_Byte(0xFD);
		for (TempCnt = 0; TempCnt < 8; TempCnt++)		USART1_Snd_Byte(SndData[1].DataBuf[TempCnt]);
		USART1_Snd_Byte(0xFE);
		SndData[1].SndStatus = SND_IDLE;
    
    return;
	}
  
  /* Send Broadcast */
	if (SndData[1].SndStatus == SND_BROADCAST)
	{
		USART1_Snd_Byte(0xF9);
		for (TempCnt = 0; TempCnt < 10; TempCnt++)		USART1_Snd_Byte(SndData[1].DataBuf[TempCnt]);
		USART1_Snd_Byte(0xFE);
		SndData[1].SndStatus = SND_IDLE;
    
    return;
	}
}




/************************************************************
	*
	* FunctionName	Wifi_Rcv_Data
	*
*************************************************************/
void Wifi_Rcv_Data(void)
{		
  _Uint8		TempCnt = 0;
	
	
	/* Exit when receive status is idle or working */
	if (RcvByteStatus[0] == RCV_IDLE)
	{
		RcvSttHoldTime[0] = 0;
		return;
	}
	
	
	/* Hold time after received, if timer > 1second, received err, then clear the data */
	if (RcvByteStatus[0] == RCV_STT)
	{
		RcvSttHoldTime[0]++;
		if (RcvSttHoldTime[0] > 5) // 50ms
		{
			RcvSttHoldTime[0] 	= 0;
      
      if (RcvBuffer[0][0] == PROTOCOL_VER)
      {
        RcvByteStatus[0] = RCV_IDLE;
        RcvFlag[0]	= TRUE;
        for (TempCnt = 0; TempCnt < RCV_BYTE_MAX; TempCnt++)									// move the buffer to rcvdata
        {
          RcvData[0].DataBuf[TempCnt]	= RcvBuffer[0][TempCnt];
          RcvBuffer[0][TempCnt] 			= 0;
        }
      }
      else
      {
        RcvByteStatus[0]	= RCV_IDLE;
        for (TempCnt = 0; TempCnt < RCV_BYTE_MAX; TempCnt++)		RcvBuffer[0][TempCnt]	= 0;			  // clear the buffer
        RcvByteStatus[0] = RCV_IDLE;																									// clear the status
      }
		}
		return;
	}
}










/***********************************************************
	*
	* FunctionName	Wifi_Snd_Data
	*
************************************************************/
void Wifi_Snd_Data(void)
{
	_Uint8	TempCnt = 0;
	
	/* when snd data is idle , exit */
	if (SndData[0].SndStatus == SND_IDLE)
	{
		return;
	}
	
	/* type send LA1 */
	if (SndData[0].SndStatus == SND_TYPE)
	{
		// Send type command "LA1"
		USART0_Snd_Byte(0xFC);
		USART0_Snd_Byte(0xFE);
		
		// Send power on command after type command sent completed
		SndData[0].SndStatus = SND_NORMAL;	
		return;
	}
	
	
	/* Send normally */
	if (SndData[0].SndStatus == SND_NORMAL)
	{
		USART0_Snd_Byte(0xFD);
		for (TempCnt = 0; TempCnt < 8; TempCnt++)		USART0_Snd_Byte(SndData[0].DataBuf[TempCnt]);
		USART0_Snd_Byte(0xFE);
		SndData[0].SndStatus = SND_IDLE;
	}
}



//---------------------------------------------------
// FunctionName	USART1_Snd_Byte
//---------------------------------------------------
static void USART1_Snd_Byte(_Uint8 SndBuf)
{
	while (SndData[1].SndByteDoneFlag);
	SBUF_1 = SndBuf;
	SndData[1].SndByteDoneFlag = TRUE;
}


//---------------------------------------------------
// FunctionName	USART0_Snd_Byte
//---------------------------------------------------
static void USART0_Snd_Byte(_Uint8 SndBuf)
{
	while (SndData[0].SndByteDoneFlag);
	SBUF = SndBuf;
	SndData[0].SndByteDoneFlag = TRUE;
}
