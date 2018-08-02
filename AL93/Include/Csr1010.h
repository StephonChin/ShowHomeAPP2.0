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
#define 	RCV_BYTE_MAX	10


/* <-----------Type Define-------------> */
typedef struct RCV_DATA_TYPE
{
	_Flag			RcvDoneFlag;
	_Uint8 		DataBuf[6];
}_TypeStructRcv;


typedef struct SND_DATA_TYPE
{
	enum SND_STATUS
	{
		SND_IDLE,	SND_TYPE,	SND_NORMAL
	}SndStatus;
	_Flag 		SndByteDoneFlag;
	_Uint8 		DataBuf[8];
	_Flag			InitFlag;
	_Uint8		SndCnt;
	_Uint8		TimeDelay;
}_TypeStructSnd;


/***
	* @Brief Exported Functions
	*/
void Csr1010_Init(void);
void Csr1010_Snd_Data(void);
void Csr1010_Rcv_Data(void);
	

/***
	* @Brief File Functions
	*/
static void Csr1010_Rcv_Byte(void);
static void Csr1010_Snd_Byte(_Uint8);


/***
	* @Brief Exported Variables
	*/
extern _TypeStructRcv 		RcvData;
extern _TypeStructSnd 		SndData;
extern _Flag							RcvDoneFlag;



#endif
