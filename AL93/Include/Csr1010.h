/**************************************************************************************
	*
	* @FileName	Csr1010.h
	*
***************************************************************************************/
#ifndef __CSR1010_H__
#define __CSR1010_H__


/* <-----------Include Files---------------> */
#include "System.h"


/* <-----------define---------------------> */
#define 	BUFFER_MAX					15
#define 	USART_TIME_DIFF			3				// 3 * 20ms = 60ms




/***
	* @Brief Exported Functions
	*/
void Csr1010_Rcv_Data(void);
void Csr1010_Snd_Data(_Uint8 *pBuf, _Uint8 len);


/***
	* @Brief File Functions
	*/
static bit Csr1010_Rcv_Byte(void);
static bit Csr1010_Snd_Byte(_Uint8 SndBuf);

/***
	* @Brief Exported Variables
	*/
  extern _Uint8 					 RcvData[BUFFER_MAX];
  extern _Uint8 					 SndData[BUFFER_MAX];
  extern bit 						   RcvFlag = FALSE;



#endif
