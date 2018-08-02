/*******************************************************************************
	*
	* @File Name		Key_Scan.h
	* @Date					2016.12.19
	* @Author				DS.Chin
	* @CopyRight		(C) CopyRight  @2016 ~ 2026 Willis Ltd. Co.
	* @Description	This file contains all the function prototyped for the Key Scan
	*								fimer library
	*
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_SCAN_H
#define __KEY_SCAN_H


/* Include files--------------------------------------------------------------*/
#include "Type_Def.h"
#include "MCU_Config.h"
#include "Data_Process.h"


/**
	* @Brief	Type Key Staus
	*/
typedef enum
{
	KEY_IDLE,
	KEY_SHORT,
	KEY_LONG
}_TypeEnumKey;




/**
	* @Brief Function For Key Scan
	*/
void Key_Scan(void);



/**
	* @Brief	Global Variables Extern
	*/
extern idata _TypeEnumKey		KeyStatus;


#endif