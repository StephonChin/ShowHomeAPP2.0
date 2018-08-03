/*************************************************************************
	*
	* @FileName		Csr1010.c
	* @Date				2017.03.10
	* @Author			DS.Chin
	* @Description
	*							| Communicate to CSR1010
	*							| Receive data from APP
	* 						| Send data to APP
	*
***************************************************************************/
#include "Csr1010.h"


//Global arguments
_Uint8 					RcvData[BUFFER_MAX];
_Uint8 					SndData[BUFFER_MAX];
bit 						RcvFlag = FALSE;


//File arguments
bit 						RcvingFlag = FALSE;
volatile bit		SndDoneFlag = FALSE;
_Uint8					RcvTimeOut = 0;;
_Uint8					RcvCnt = 0;


/**
	* Uart_Interrupt
	*		> Receive and send data interrput service for USART
  */
void Uart_Interrupt(void) interrupt 15
{
	/* When receive interrupt flag been set */
	if (RI_1)
	{
		RI_1 = RESET;
		RcvingFlag = Csr1010_Rcv_Byte();
	}

	/* When send interrput flag been set */
	if (TI_1)
	{
		TI_1 = RESET;
		SndDoneFlag = FALSE;
	}

	return;
}



/**
	* Csr1010_Rcv_Byte
	*		> Receive one byte
	*/
static bit Csr1010_Rcv_Byte(void)
{
	RcvTimeOut = 0;
	if (RcvCnt < BUFFER_MAX){
		*RcvData = SBUF;
		RcvData++;
		RcvCnt++;
	}
	else{
		return FALSE;
	}

	return TRUE;
}



/**
	* Csr1010_Rcv_Data
	*		> Receive data
	*/
void Csr1010_Rcv_Data(void)
{
	if (RcvingFlag){
		RcvTimeOut++;
		if (RcvTimeOut >= USART_TIME_DIFF){
			RcvingFlag = FALSE;
			RcvCnt = 0;
			RcvFlag = TRUE;
		}
	}
	else{
		RcvCnt = 0;
	}
}



/**
	* Csr1010_Snd_Data
	*		> Send data
	*/
void Csr1010_Snd_Data(_Uint8 *pBuf, _Uint8 len)
{
	while (len){
		Csr1010_Snd_Byte(*pBuf);
		pBuf++;
		len--;
	}
}



/**
	* Csr1010_Snd_Byte
	*		> Send one byte
	*		> if send successfully, return TRUE. if send failly return FALSE.
 	*/
static bit Csr1010_Snd_Byte(_Uint8 SndBuf)
{
	_Uint16		timeOut = 10000;

	SBUF_1 = SndBuf;
	while (SndDoneFlag && timeOut){
		timeOut--;
	};
	SndDoneFlag = TRUE;

	if (timeOut == 0) 	return FALSE;
	return TRUE;
}
