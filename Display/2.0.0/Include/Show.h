/***********************************************************************
 *
 * FILE NAME		| Show.h
 * DATE					| 01 NOV. 2017
 * BRIEF				| The head file for the show_1.c show_2.c show_3.c
 *
************************************************************************/
#ifndef __SHOW_H__
#define __SHOW_H__

/*
 * Include Files
 */
#include "TypeDef.h"
#include "Led_Class.h"
#include "Data_Process.h"
#include "stdlib.h"


/*
 * Const Value Define
 */
#define		RAND()				srand(RndSeed);RndSeed+=29;

/*
 * TypeDef
 */

typedef struct _DISPLAY_TYPE
{
	_Uint8	Mode;
	_Uint8	ModeBuf;
	_Uint8	ColorValue;
	_Flag		InitFlag;
}_Type_Display;


/*
 * Exported Functions
 */
void All_Off(void);
void Power_On(void);
void All_Color(_Uint8, _Uint8, _Uint8);

void		Show_1(void);
void 		Show_1_0(void);
void 		Show_1_1(void);
void 		Show_1_2(void);
void 		Show_1_3(void);

void 		Show_2(void);
void 		Show_2_0(void);
void 		Show_2_1(void);
void 		Show_2_2(void);
void 		Show_2_3(void);
void 		Show_2_4(void);

void 		Show_3(void);
void 		Show_3_0(void);
void 		Show_3_1(void);
void 		Show_3_2(void);
void 		Show_3_3(void);
void 		Show_3_4(void);






/*
 * Exported Parameters
 */
extern _Type_Display		DisplayData;
extern _Uint8					ColorData[16][3];
extern _Uint8					ColorNum;
extern _Uint8					TempCnt;
extern _Uint8					TempLed;

extern _Uint8					RndCnt30;
extern _Uint8					RndCnt40;
extern _Uint8					RndCnt24;
extern _Uint8					RndCnt10;
extern _Uint8					RndCnts30;
extern _Uint8					RndCnts24;
extern _Uint8					RndCnts36;
extern _Uint8					RndCntTree;
extern _Uint8					RndCntSnow;
extern _Uint8					RndCntCane;
extern _Uint8					RndCntBall;
extern _Uint8					RndCntSpot;

extern _Uint8					ModeLed30[30];
extern _Uint8					ModeLed40[40];
extern _Uint8					ModeLed24[24];
extern _Uint8					ModeLed10[10];
extern _Uint8					ModeLeds30[30];
extern _Uint8					ModeLeds24[24];
extern _Uint8					ModeLeds36[36];
extern _Uint8					ModeLedTree[3];
extern _Uint8					ModeLedSnow[3];
extern _Uint8					ModeLedCane[6];
extern _Uint8					ModeLedBall;
extern _Uint8					ModeLedSpot[3];

extern _Uint8					ModeColor10[10];
extern _Uint8					ModeColor24[24];
extern _Uint8					ModeColor30[30];
extern _Uint8					ModeColor40[40];
extern _Uint8					ModeColors30[30];
extern _Uint8					ModeColors24[24];
extern _Uint8					ModeColors36[36];
extern _Uint8					ModeColorTree[3];
extern _Uint8					ModeColorSnow[3];
extern _Uint8					ModeColorCane[6];
extern _Uint8					ModeColorBall;
extern _Uint8					ModeColorSpot[3];

extern _Uint8					ModeStep10[10];
extern _Uint8					ModeStep24[24];
extern _Uint8					ModeStep30[30];
extern _Uint8					ModeStep40[40];
extern _Uint8					ModeSteps30[30];
extern _Uint8					ModeSteps24[24];
extern _Uint8					ModeSteps36[36];
extern _Uint8					ModeStepTree[3];
extern _Uint8					ModeStepSnow[3];
extern _Uint8					ModeStepCane[6];
extern _Uint8					ModeStepBall;
extern _Uint8					ModeStepSpot[3];

extern _Uint8					ModeTime10[10];
extern _Uint8					ModeTime24[24];
extern _Uint8					ModeTime30[30];
extern _Uint8					ModeTime40[40];
extern _Uint8					ModeTimes30[30];
extern _Uint8					ModeTimes24[24];
extern _Uint8					ModeTimes36[36];
extern _Uint8					ModeTimeTree[3];
extern _Uint8					ModeTimeSnow[3];
extern _Uint8					ModeTimeCane[6];
extern _Uint8					ModeTimeBall;
extern _Uint8					ModeTimeSpot[3];

extern _Uint8					HoldTime10[10];
extern _Uint8					HoldTime24[24];
extern _Uint8					HoldTime30[30];
extern _Uint8					HoldTime40[40];
extern _Uint8					HoldTimes30[30];
extern _Uint8					HoldTimes24[24];
extern _Uint8					HoldTimes36[36];
extern _Uint8					HoldTimeTree[3];
extern _Uint8					HoldTimeSnow[3];
extern _Uint8					HoldTimeCane[6];
extern _Uint8					HoldTimeBall;
extern _Uint8					HoldTimeSpot[3];

extern _Uint8					TempColor;
extern _Uint8					TempR;
extern _Uint8					TempG;
extern _Uint8					TempB;
extern _Uint8					FadeR;
extern _Uint8					FadeG;
extern _Uint8					FadeB;
extern _Uint8					HoldTime;
extern _Uint8					KeepTime;

extern _Uint8					SpeedTime;
extern _Uint16					RndSeed;
extern _Uint8					ShowMode;
extern _Flag						ShowInit;
extern _Uint16					TimeLine;
extern _Uint8					TempStep;








#endif /* #ifndef __SHOW_H__ */
