/*******************************************************************************
	*
	*		FILE NAME
	*								Led_Display.c
	*
*******************************************************************************/
#include "Display_Ctrl.h"

/*<--------------------------- Gloable Files -------------------------------> */
_Type_Display		DisplayData;

#if AL96
_Uint8					ColorData[16][4];
_Uint8					TempW;
_Uint8					FadeW;
#else
_Uint8					ColorData[16][3];
#endif

_Uint8					ColorNum;
_Uint8					TempCnt;
_Uint8					TempLed;
_Uint8					LedCnt;
_Uint8					TempR;
_Uint8					TempG;
_Uint8					TempB;
_Uint8					TempDuty;
_Uint8					FadeR;
_Uint8					FadeG;
_Uint8					FadeB;
_Uint8					TempColor;
_Uint8					ModeTime[50];
_Uint8					ModeStep[50];
_Uint8					HoldTime[50];
_Uint8					ModeColor[50];
_Uint8					ModeLed[50];
_Uint8					TempGrp;
_Uint8					SpeedTime;
_Uint8					KeepTime;
_Uint16					RndSeed;
_Uint8					ShowMode;
_Flag						ShowInit;
_Uint8					HorseCnt;
_Uint8					EndCnt;
_Uint8					RndCnt;
_Uint8					SteadyTime;
_Uint16					TimeLine;
_Uint8					TempStep;



_Uint8					TempGrp;
_Uint8					SteadyTime;
_Uint8					StepCnt;


_Uint16					HorseOrder;
_Uint16					HorseTotal;
_Uint16					HorseWaitCnt;
_Uint16					HorseWaitTime;
_Uint16					HorseStep;
_Flag						ModeSynFlag;

#if AL99
_Uint8					LedNum[6][GRP_LED];
#endif








/**
	* FunctionName		Led_Display
	*/
void Led_Display(void)
{
	RndSeed += 17;
	switch (DisplayData.Mode)
	{
		case 0x0:			All_Off();							break;
		case 0x1:			Steady();								break;
		case 0x2:			Blink();								break;
		case 0x3:			Sparkle();							break;
		case 0x4:			Instead();							break;
		case 0x5:			Sea_Wave();							break;
		case 0x6:			Roll();									break;
		case 0x7:			Ripple();								break;
		case 0x8:			Flower_Bloom();					break;
		case 0x9:			Polar_Light();					break;
		case 0xA:			Color_Show();						break;
		case 0xB:			Show_1();								break;
		case 0xC:			Show_2();								break;
		case 0xD:			Show_3();								break;
		
		case 0xFB:		Blue_Flash();						break;
		case 0xFD:		Green_Flash();					break;
		case 0xFF:		Red_Flash();						break;
		
		#if AL91 | AL94
		case 0xFC:		Direct_Set();						break;
		case 0xFE:		Horse_Whole_Test();			break;
		#endif
		
		default:			DisplayData.Mode = 0xA;	break;
	}
	
	
	#if AL99
	for (TempLed = 0; TempLed < 6; TempLed++)
	{
		ColorBuffer[GRP_SEVEN][TempLed].DutyR			= ColorBuffer[GRP_ONE][37].DutyR;
		ColorBuffer[GRP_SEVEN][TempLed].DutyG 	= ColorBuffer[GRP_ONE][37].DutyB;
		ColorBuffer[GRP_SEVEN][TempLed].DutyB 		= ColorBuffer[GRP_ONE][37].DutyG;
	}
	#endif
}






