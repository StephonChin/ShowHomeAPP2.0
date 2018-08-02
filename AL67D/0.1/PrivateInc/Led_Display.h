/*******************************************************************************
	*
	* @File Name		LedDisplay.h
	* @Date					2016.12.19
	* @Author				DS.Chin
	* @CopyRight		(C) CopyRight  @2016 ~ 2026 Willis Ltd. Co.
	* @Description	This file contains all the function prototyped for the LedDisplay
	*								firmware library
	*
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LED_DISPLAY_H__
#define __LED_DISPLAY_H__


/* Include files--------------------------------------------------------------*/
#include "Type_Def.h"
#include "Led_Class.h"
#include "Data_Process.h"
#include "stdlib.h"

/* Define --------------------------------------------------------------*/
#define			DUTY_MAX				100
#define			DUTY_MIN				0
#define			FADE_LEVEL			    50


/*<-------------------- Type Redefine --------------------------------> */
typedef struct _DISPLAY_TYPE
{
	_Uint8	Mode;
	_Uint8	ModeBuf;
	_Uint8	ColorValue;
	_Flag	InitFlag;
}_Type_Display;

typedef struct
{
	_Uint8	Minute;
	_Uint8	Second;
	_Uint8	MicroSec;
}_MusicTimeType;




/**
	* @Brief 		File Functions
	*/
static void 		Blue_Flash(void);
static void 		Red_Flash(void);
static void 		Green_Flash(void);
static void 		All_Off(void);
static void 		Steady(void);
static void 		Fade_Init(void);
static void 		Flash_Init(void);
static void 		Fade(_Flag AllFlag);
static void 		Flash(_Flag AllFlag);
static void			Show_1(void);
static void 		Show_2(void);
static void 		Show_3(void);
static void 		Show_1_1(void);
static void 		Show_1_2(void);
static void 		Show_1_3(void);
static void			Show_1_4(void);
static void 		Show_2_1(void);
static void 		Show_2_2(void);
static void 		Show_2_3(void);
static void			Show_2_4(void);
static void 		Show_3_1(void);
static void 		Show_3_2(void);
static void 		Show_3_3(void);
static void			Show_3_4(void);


/**
	* @Brief 		Exported Functions
	*/
void Led_Display(void);


/**
	* @Brief	Exported Global Variables
	*/
extern _Type_Display				DisplayData;
extern _Uint8  						ColorData[8][3];  			


#endif