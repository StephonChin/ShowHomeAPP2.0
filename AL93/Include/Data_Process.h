/******************************************************************
	*
	*	@FileName	Data_Process.h
	*
******************************************************************/
#ifndef __DATA_PROCESS_H__
#define __DATA_PROCESS_H__


/****************************************************************
	* @Include Files
	*/
#include "System.h"
#include "Csr1010.h"
#include "Led_Display.h"
#include "Timer_Motor.h"
#include "Eprom.h"
#include "Config.h"


/***************************************************************
	* Define
****/
#define	COLOR_R						0x01
#define	COLOR_G						0x02
#define	COLOR_B						0x04
#define	COLOR_W						0x08






/**
	* @Brief File Functions
	*/
static void Count_Down_Process(void);
static void CSR1010_Process(void);
static void Color_Value_Get(_Uint8	ColorValBuf);
static void Password_Process(void);
static _Uint8		Hex_To_Char(_Uint8 HexBuf);


/***
	* @Brief Exported Functions
	*/
void User_Init(void);
void Data_Process(void);


//Exported arguments
extern _Uint8					ChkSumH;
extern _Uint8					ChkSumL;
extern _Uint8					ChkSumRst;
extern _Uint8					ChkSumRstSave;
extern _Uint8					PowerOnNum;
extern _Uint8					ChkSumRst;
extern _Uint8					ChkSumRstSave;
extern _Uint8					PowerOnNum;
extern _Flag						WdtRstFlag;



#endif
