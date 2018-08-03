/*******************************************************************
	*
	* @FileName		Led_Display.h
	*
********************************************************************/
#ifndef __LED_DISPLAY_H__
#define __LED_DISPLAY_H__


/* @Include Files */
#include "System.h"
#include "Config.h"
#include "stdlib.h"


/* Defines */
#define			LED_ON											0
#define			LED_OFF											1
#define			DUTY_MAX										100
#define			DUTY_MIN										0

#define     SPARKLE_TIME         				30
#define			SPARKLE_BASIC								40

#define     GLIMMER_TIME         				40
#define			GLIMMER_BASIC								80
#define     FADE_TIME               		1      	//10ms * FADE_TIME  = 20ms
#define     TWINKLE_FADE_TIME       		1     	//10ms * TWINKLE_FADE_TIME  = 10ms
#define     TWINKLE_DARK_TIME       		10     	//10ms * TWINKLE_DARK_TIME = 100ms
#define     TWINKLE_BRIGHT_TIME     		3      	//10ms * TWINKLE_BRIGHT_TIME = 30ms


#define			MODE_MAX										0xE
#define 		COLOR_MAX										7

/* @Type Define */
typedef struct _LED_TYPE
{
	_Uint8	Mode;
	_Uint8	ModeBuf;
	_Uint8	CircleInitFlag;
	_Uint8	Color;
	_Flag		InitFlag;
	_Flag		WarningFlag;
}_TypeStructLed;



/* @Exported Functions */
void Led_Display_Control(void);


/* @File Functions */
static void  	All_Off(void);
static void 	Warning_Mode(void);
static void 	Normal_Mode(_Uint8 ModeValBuf);
static void 	Power_Off(void);
static void 	Steady(void);
static void 	Flash(_Uint8 FlashSpeed, _Uint8	FlashBasic);
static void 	Fade(void);
static void 	Twinkle(void);
static void 	Fire(void);
static void 	Night(void);
static void 	Circle(void);

/* @Exported Variables */
extern _TypeStructLed		LedData;
extern _Uint8 					*Color[];
extern _Uint8     			RedDuty[3];
extern _Uint8     			GreenDuty[3];
extern _Uint8     			BlueDuty[3];
extern _Uint8     			WhiteDuty[3];


#endif
