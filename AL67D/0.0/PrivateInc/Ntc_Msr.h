/*******************************************************************************
	*
	* @File Name		Ntc_Msr.h
	* @Date					2016.12.19
	* @Author				DS.Chin
	* @CopyRight		(C) CopyRight  @2016 ~ 2026 Willis Ltd. Co.
	* @Description	This file contains all the function prototyped for the Ntc Msr
	*								fimer library
	*
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NTC_MSR_H
#define __NTC_MSR_H


/* Include files--------------------------------------------------------------*/
#include "Type_Def.h"
#include "MCU_Config.h"



/**
	* @Brief Defines
	*/
#define				HOT_OFF							((_Uint8)0)
#define				HOT_ON							((_Uint8)1)


/**
	* @define
	*/
#define				TMPRTR_PROTECT_TIME			20
#define				T_20			            140
#define				T_30			            128
#define				T_MIN			            252
#define				T_MAX			            1
#define				T_55			            1
#define				T_50			            5
		

/**
	* @Type NTC Data
	*/
typedef enum NTC_TYPE
{
	NTC_IDLE,
	NTC_HOT,
	NTC_BAN,
	NTC_BAN_EXIT
}_TypeEnumNtc;

/**
	* @Ntc Msr exported function
	*/
void 	Ntc_Msr(void);


/**
	* @File Fucntion
	*/
static _Uint8 AD_Val_Get(void);


/**
	* @Ntc Msr exported global variables
	*/
extern _TypeEnumNtc	NtcStatus;


#endif
