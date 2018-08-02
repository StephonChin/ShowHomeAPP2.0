/********************************************************************
	*
	* FILE NAME
	*									Show_1.c
	* DATE
	*									02 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									Display Show One Mode
	*                 All Off Mode
	*                 Power On Mode
	*                 Some Public Functions
	*
*********************************************************************/
#include "Show.h"

/* 
 * Gloable Parameters
 */
_Type_Display		DisplayData;
_Uint8					ColorData[16][3];
_Uint8					ColorNum;
_Uint8					TempCnt;
_Uint8					TempLed;

_Uint8					RndCnt30;
_Uint8					RndCnt40;
_Uint8					RndCnt24;
_Uint8					RndCnt10;
_Uint8					RndCnts30;
_Uint8					RndCnts24;
_Uint8					RndCnts36;
_Uint8					RndCntTree;
_Uint8					RndCntSnow;
_Uint8					RndCntCane;
_Uint8					RndCntBall;
_Uint8					RndCntSpot;

_Uint8					ModeLed30[30];
_Uint8					ModeLed40[40];
_Uint8					ModeLed24[24];
_Uint8					ModeLed10[10];
_Uint8					ModeLeds30[30];
_Uint8					ModeLeds24[24];
_Uint8					ModeLeds36[36];
_Uint8					ModeLedTree[3];
_Uint8					ModeLedSnow[3];
_Uint8					ModeLedCane[6];
_Uint8					ModeLedBall;
_Uint8					ModeLedSpot[3];

_Uint8					ModeColor10[10];
_Uint8					ModeColor24[24];
_Uint8					ModeColor30[30];
_Uint8					ModeColor40[40];
_Uint8					ModeColors30[30];
_Uint8					ModeColors24[24];
_Uint8					ModeColors36[36];
_Uint8					ModeColorTree[3];
_Uint8					ModeColorSnow[3];
_Uint8					ModeColorCane[6];
_Uint8					ModeColorBall;
_Uint8					ModeColorSpot[3];

_Uint8					ModeStep10[10];
_Uint8					ModeStep24[24];
_Uint8					ModeStep30[30];
_Uint8					ModeStep40[40];
_Uint8					ModeSteps30[30];
_Uint8					ModeSteps24[24];
_Uint8					ModeSteps36[36];
_Uint8					ModeStepTree[3];
_Uint8					ModeStepSnow[3];
_Uint8					ModeStepCane[6];
_Uint8					ModeStepBall;
_Uint8					ModeStepSpot[3];

_Uint8					ModeTime10[10];
_Uint8					ModeTime24[24];
_Uint8					ModeTime30[30];
_Uint8					ModeTime40[40];
_Uint8					ModeTimes30[30];
_Uint8					ModeTimes24[24];
_Uint8					ModeTimes36[36];
_Uint8					ModeTimeTree[3];
_Uint8					ModeTimeSnow[3];
_Uint8					ModeTimeCane[6];
_Uint8					ModeTimeBall;
_Uint8					ModeTimeSpot[3];

_Uint8					HoldTime10[10];
_Uint8					HoldTime24[24];
_Uint8					HoldTime30[30];
_Uint8					HoldTime40[40];
_Uint8					HoldTimes30[30];
_Uint8					HoldTimes24[24];
_Uint8					HoldTimes36[36];
_Uint8					HoldTimeTree[3];
_Uint8					HoldTimeSnow[3];
_Uint8					HoldTimeCane[6];
_Uint8					HoldTimeBall;
_Uint8					HoldTimeSpot[3];

_Uint8					TempColor;
_Uint8					TempR;
_Uint8					TempG;
_Uint8					TempB;
_Uint8					FadeR;
_Uint8					FadeG;
_Uint8					FadeB;
_Uint8					HoldTime;
_Uint8					KeepTime;

_Uint8					SpeedTime;
_Uint16					RndSeed;
_Uint8					ShowMode;
_Flag						ShowInit;
_Uint16					TimeLine;
_Uint8					TempStep;


/*
 * FunctionName		All_Color
 */
void All_Color(_Uint8 BufR, _Uint8 BufG, _Uint8 BufB)
{
	_Uint8		TempVar = 0;
	
	for (TempVar = 0; TempVar < 30; TempVar++)
		{
			Roof30[TempVar].DutyR = BufR;
			Roof30[TempVar].DutyG = BufG;
			Roof30[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 40; TempVar++)
		{
			Roof40[TempVar].DutyR = BufR;
			Roof40[TempVar].DutyG = BufG;
			Roof40[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 24; TempVar++)
		{
			Roof24[TempVar].DutyR = BufR;
			Roof24[TempVar].DutyG = BufG;
			Roof24[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 10; TempVar++)
		{
			Roof10[TempVar].DutyR = BufR;
			Roof10[TempVar].DutyG = BufG;
			Roof10[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 30; TempVar++)
		{
			String30[TempVar].DutyR = BufR;
			String30[TempVar].DutyG = BufG;
			String30[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 24; TempVar++)
		{
			String24[TempVar].DutyR = BufR;
			String24[TempVar].DutyG = BufG;
			String24[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 36; TempVar++)
		{
			String36[TempVar].DutyR = BufR;
			String36[TempVar].DutyG = BufG;
			String36[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 21; TempVar++)
		{
			Grd.Snow[TempVar].DutyR = BufR;
			Grd.Snow[TempVar].DutyG = BufG;
			Grd.Snow[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 27; TempVar++)
		{
			Grd.Tree[TempVar].DutyR = BufR;
			Grd.Tree[TempVar].DutyG = BufG;
			Grd.Tree[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 4; TempVar++)
		{
			Grd.Ball[TempVar].DutyR = BufR;
			Grd.Ball[TempVar].DutyG = BufG;
			Grd.Ball[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 30; TempVar++)
		{
			Grd.Cane[TempVar].DutyR = BufR;
			Grd.Cane[TempVar].DutyG = BufG;
			Grd.Cane[TempVar].DutyB = BufB;
		}
		
		for (TempVar = 0; TempVar < 3; TempVar++)
		{
			Grd.Spot[TempVar].DutyR = BufR;
			Grd.Spot[TempVar].DutyG = BufG;
			Grd.Spot[TempVar].DutyB = BufB;
		}
}


/*
 * FunctionName 		All_Off
 */
void All_Off(void)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		
		All_Color(0,0,0);
	}
}


/*
 * FunctionName			Power_On
 */
void Power_On(void)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		
		SpeedTime = 0;
		TempStep	= 0;
		
		All_Color(255,0,0);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		
		return;
	}
	
	SpeedTime++;
	if (SpeedTime >= 30)
	{
		SpeedTime = 0;
		
		switch (TempStep)
		{
			case 0:
			{
						All_Color(0,255,0);
						TempStep++;
			} break;
			
			case 1:
			{
						All_Color(0,0,255);
						TempStep++;
			} break;
			
			default:
			{
						All_Color(0,0,0);
						DisplayData.Mode = 0x0;
			} break;
		}
	}
}
 








/**
	* FunctionName	Show_1
	*/
void Show_1(void)
{
	/* Initalize */
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
			
		TimeLine = 0;
		ShowMode = 0;
		
		All_Color(0,0,0);
		
		return;
	}
	
	
	/* Mode Control */
	TimeLine++;
	if (TimeLine == 1)									{ShowMode = 0;			ShowInit = TRUE;	}
	else if (TimeLine == 460)						{ShowMode = 1;			ShowInit = TRUE;	}
	else if (TimeLine == 2510)					{ShowMode = 2;			ShowInit = TRUE;	}
	else if (TimeLine == 3345)					{ShowMode = 3;			ShowInit = TRUE;	}
	else if (TimeLine == 3850)					{TimeLine = 0;			DisplayData.InitFlag = TRUE;}

	switch (ShowMode)
	{
		case 0:			Show_1_0();		break;
		case 1:			Show_1_1();		break;
		case 2:			Show_1_2();		break;
		case 3:			Show_1_3();		break;
	}
}


/*
 * FunctionName		Show_1_0
 * Duration				TimeLine = 460
 */
void Show_1_0(void)
{
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		SpeedTime 			= 0;
		TempR						= 0;
		TempG						= 0;
		TempB						= 0;
		TempCnt					= 0;
		TempColor				= 0;
		
		TempStep = 0;
		
		return;
	}
	
	/* Speed Control */
	if (SpeedTime < 2)
	{
		SpeedTime++;
		return;
	}
	SpeedTime = 0;
	
	/* Mode Control
	 * Fade in from the middle led to head and tail
	 * then fade out.Three color will be display in
	 * this mode.
	 * At last, all turned off
	 */
	switch (TempStep)
	{
		case 0:
		{
			FadeR = ColorData[TempColor][R] / 25;
			FadeG = ColorData[TempColor][G] / 25;
			FadeB = ColorData[TempColor][B] / 25;
			
			TempR += FadeR;
			TempG += FadeG;
			TempB += FadeB;
			
			TempCnt++;
			if (TempCnt >= 25)
			{
				TempCnt = 0;
				TempStep++;
			}
		} break;
		
		case 1:
		{
			TempR -= FadeR;
			TempG -= FadeG;
			TempB -= FadeB;
			TempCnt++;
			if (TempCnt >= 25)
			{
				TempCnt = 0;
				TempStep = 0;
				TempColor++;
				if (TempColor > 2)
				{
					TempStep = 2;
				}
			}
		} break;
		
		
		default:			break;
	}
	
	/* Led Data Get */
	All_Color(TempR, TempG, TempB);
}


/*
 * FunctionName		Show_1_1
 * Duration				TimeLine = 2501
 */
void Show_1_1(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		SpeedTime		= 0;
		TempStep		= 0;
		
		for (TempCnt = 0; TempCnt < 30; TempCnt++)
		{
			ModeLed30[TempCnt] = 0;
		}
		
		for (TempCnt = 0; TempCnt < 10; TempCnt++)
		{
			ModeLed10[TempCnt] = 0;
		}
		
		for (TempCnt = 0; TempCnt < 24; TempCnt++)
		{
			ModeLed24[TempCnt] = 0;
		}
		
		for (TempCnt = 0; TempCnt < 40; TempCnt++)
		{
			ModeLed40[TempCnt] = 0;
		}
		
		for (TempCnt = 0; TempCnt < 30; TempCnt++)
		{
			ModeLeds30[TempCnt] = 0;
		}
		
		for (TempCnt = 0; TempCnt < 24; TempCnt++)
		{
			ModeLeds24[TempCnt] = 0;
		}
		
		for (TempCnt = 0; TempCnt < 36; TempCnt++)
		{
			ModeLeds36[TempCnt] = 0;
		}
		
		RndCnt10 	= 0;
		RndCnt24 	= 0;
		RndCnt30 	= 0;
		RndCnts30 = 0;
		RndCnts24 = 0;
		RndCnts36 = 0;
		RndCnt40 = 0;
		RndCntTree = 0;
		RndCntSnow = 0;
		RndCntCane = 0;
		RndCntSpot = 0;
		RndCntBall = 0;
		
		KeepTime = 0;
		return;
	}
	
	
	
	switch (TempStep)
	{
		/* Appear 
		 * Apear three color random follow the below simple
		 * 0,1,2 		- Color0
		 * 3,4,5 		- Color1
		 * 6,7,8		- Color2
		 * 9,10,11	- Color0
		 *...
		 */
		case 0:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						/* Icicle */
						if (RndCnt30 < 30)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 30;
							} while (ModeLed30[TempLed] == 1);
							ModeLed30[TempLed] = 1;
							
							TempColor = TempLed / 4;
							Roof30[TempLed].DutyR	= ColorData[TempColor][R];
							Roof30[TempLed].DutyG	= ColorData[TempColor][G];
							Roof30[TempLed].DutyB	= ColorData[TempColor][B];
							
							RndCnt30++;
						}
						
						if (RndCnt10 < 10)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 10;
							} while (ModeLed10[TempLed] == 1);
							ModeLed10[TempLed] = 1;
							
							TempColor = TempLed / 4;
							Roof10[TempLed].DutyR	= ColorData[TempColor][R];
							Roof10[TempLed].DutyG	= ColorData[TempColor][G];
							Roof10[TempLed].DutyB	= ColorData[TempColor][B];
							RndCnt10++;
						}
						
						if (RndCnt24 < 24)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 24;
							} while (ModeLed24[TempLed] == 1);
							ModeLed24[TempLed] = 1;
							
							TempColor = TempLed / 4;
							Roof24[TempLed].DutyR	= ColorData[TempColor][R];
							Roof24[TempLed].DutyG	= ColorData[TempColor][G];
							Roof24[TempLed].DutyB	= ColorData[TempColor][B];
							RndCnt24++;
						}
						
						if (RndCnt40 < 40)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 40;
							} while (ModeLed40[TempLed] == 1);
							ModeLed40[TempLed] = 1;
							
							TempColor = TempLed / 4;
							Roof40[TempLed].DutyR	= ColorData[TempColor][R];
							Roof40[TempLed].DutyG	= ColorData[TempColor][G];
							Roof40[TempLed].DutyB	= ColorData[TempColor][B];
							RndCnt40++;
						}
						
						if (RndCnts30 < 30)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 30;
							} while (ModeLeds30[TempLed] == 1);
							ModeLeds30[TempLed] = 1;
							
							TempColor = TempLed / 4;
							String30[TempLed].DutyR	= ColorData[TempColor][R];
							String30[TempLed].DutyG	= ColorData[TempColor][G];
							String30[TempLed].DutyB	= ColorData[TempColor][B];
							RndCnts30++;
						}
						
						if (RndCnts24 < 24)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 24;
							} while (ModeLeds24[TempLed] == 1);
							ModeLeds24[TempLed] = 1;
							
							TempColor = TempLed / 4;
							String24[TempLed].DutyR	= ColorData[TempColor][R];
							String24[TempLed].DutyG	= ColorData[TempColor][G];
							String24[TempLed].DutyB	= ColorData[TempColor][B];
							RndCnts24++;
						}
						
						if (RndCnts36 < 36)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 36;
							} while (ModeLeds36[TempLed] == 1);
							ModeLeds36[TempLed] = 1;
							
							TempColor = TempLed / 4;
							String36[TempLed].DutyR	= ColorData[TempColor][R];
							String36[TempLed].DutyG	= ColorData[TempColor][G];
							String36[TempLed].DutyB	= ColorData[TempColor][B];
							RndCnts36++;
						}
						
						/* Tree */
						if (RndCntTree < 12)
						{
							RndCntTree++;
							switch (RndCntTree)
							{
								case 1:			ModeLedTree[0] = 0;			ModeLedTree[1] = 1;	  	ModeLedTree[2] = 2;		 		break;
								case 2:			ModeLedTree[0] = 3;			ModeLedTree[1] = 4;	  	ModeLedTree[2] = 5;		 		break;
								case 3:			ModeLedTree[0] = 6;			ModeLedTree[1] = 7;	   														break;
								case 4:			ModeLedTree[2] = 8;		 																										break;
								case 5:			ModeLedTree[0] = 9;			ModeLedTree[1] = 10;	  ModeLedTree[2] = 11;		 	break;
								case 6:			ModeLedTree[0] = 12;		ModeLedTree[1] = 13;	  ModeLedTree[2] = 14;		 	break;
								case 7:			ModeLedTree[0] = 15;		ModeLedTree[1] = 16;	 														break;
								case 8:			ModeLedTree[2] = 17;		 																									break;
								case 9:			ModeLedTree[0] = 18;		ModeLedTree[1] = 19;	  ModeLedTree[2] = 20;		 	break;
								case 10:		ModeLedTree[0] = 21;		ModeLedTree[1] = 22;	  ModeLedTree[2] = 23;		 	break;
								case 11:		ModeLedTree[0] = 24;		ModeLedTree[1] = 25;	  													break;
								case 12:		ModeLedTree[2] = 26;		 																									break;
							}
							
							TempColor = (RndCntTree -1) / 4;
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
		
							Grd.Tree[ModeLedTree[0]].DutyR	= TempR;
							Grd.Tree[ModeLedTree[0]].DutyG	= TempG;
							Grd.Tree[ModeLedTree[0]].DutyB	= TempB;
							Grd.Tree[ModeLedTree[1]].DutyR	= TempR;
							Grd.Tree[ModeLedTree[1]].DutyG	= TempG;
							Grd.Tree[ModeLedTree[1]].DutyB	= TempB;
							Grd.Tree[ModeLedTree[2]].DutyR	= TempR;
							Grd.Tree[ModeLedTree[2]].DutyG	= TempG;
							Grd.Tree[ModeLedTree[2]].DutyB	= TempB;
						}
						
						/* Snow */
						if (RndCntSnow < 7)
						{
							RndCntSnow++;
							switch (RndCntSnow)
							{
								case 1:		ModeLedSnow[0] = 0;			ModeLedSnow[1] = 7;			 ModeLedSnow[2] = 14;	break;
								case 2:		ModeLedSnow[0] = 1;			ModeLedSnow[1] = 8;			 ModeLedSnow[2] = 15;	break;
								case 3:		ModeLedSnow[0] = 2;			ModeLedSnow[1] = 9;			 ModeLedSnow[2] = 16;	break;
								case 4:		ModeLedSnow[0] = 3;			ModeLedSnow[1] = 10;		 ModeLedSnow[2] = 17;	break;
								case 5:		ModeLedSnow[0] = 4;			ModeLedSnow[1] = 11;		 ModeLedSnow[2] = 18;	break;
								case 6:		ModeLedSnow[0] = 5;			ModeLedSnow[1] = 12;		 ModeLedSnow[2] = 19;	break;
								case 7:		ModeLedSnow[0] = 6;			ModeLedSnow[1] = 13;		 ModeLedSnow[2] = 20;	break;
							}
							
							Grd.Snow[ModeLedSnow[0]].DutyR	= ColorData[3][R];
							Grd.Snow[ModeLedSnow[0]].DutyG	= ColorData[3][G];
							Grd.Snow[ModeLedSnow[0]].DutyB	= ColorData[3][B];

							Grd.Snow[ModeLedSnow[1]].DutyR	= ColorData[4][R];
							Grd.Snow[ModeLedSnow[1]].DutyG	= ColorData[4][G];
							Grd.Snow[ModeLedSnow[1]].DutyB	= ColorData[4][B];
							
							Grd.Snow[ModeLedSnow[2]].DutyR	= ColorData[5][R];
							Grd.Snow[ModeLedSnow[2]].DutyG	= ColorData[5][G];
							Grd.Snow[ModeLedSnow[2]].DutyB	= ColorData[5][B];
						}
						
						/* Cane */
						if (RndCntCane < 6)
						{
							for (TempCnt = 0; TempCnt < 5; TempCnt++)
							{
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyR	= ColorData[RndCntCane][R];
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyG	= ColorData[RndCntCane][G];
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyB	= ColorData[RndCntCane][B];
							}
							
							RndCntCane++;
						}
						
						/* Spot */
						if (RndCntSpot < 3)
						{
							Grd.Spot[RndCntSpot].DutyR	= ColorData[RndCntSpot][R];
							Grd.Spot[RndCntSpot].DutyG	= ColorData[RndCntSpot][G];
							Grd.Spot[RndCntSpot].DutyB	= ColorData[RndCntSpot][B];
							RndCntSpot++;
						}
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = ColorData[0][R];
							Grd.Ball[TempCnt].DutyG = ColorData[0][G];
							Grd.Ball[TempCnt].DutyB = ColorData[0][B];
						}
						
						
						if (RndCnt40 >= 40)
						{
							TempStep++;
							ModeColorTree[0] = 1;
							ModeColorTree[1] = 2;
							ModeColorTree[2] = 3;
							ModeColorSnow[0] = 4;
							ModeColorSnow[1] = 5;
							ModeColorSnow[2] = 6;
							ModeColorCane[0] = 6;
							ModeColorSpot[0] = 4;
							ModeColorBall		 = 1;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
						}
					}
		} break;
		
		/* Rolling from head to tail circle*/
		case 1:
		{
					SpeedTime++;
					if (SpeedTime >= 10)
					{
						SpeedTime = 0;
			
						/* Roof10 */
						TempR = Roof10[9].DutyR;
						TempG = Roof10[9].DutyG;
						TempB = Roof10[9].DutyB;
						for (TempLed = 9; TempLed > 0; TempLed--)
						{
							Roof10[TempLed].DutyR = Roof10[TempLed - 1].DutyR;
							Roof10[TempLed].DutyG = Roof10[TempLed - 1].DutyG;
							Roof10[TempLed].DutyB = Roof10[TempLed - 1].DutyB;
						}
						Roof10[0].DutyR = TempR;
						Roof10[0].DutyG = TempG;
						Roof10[0].DutyB = TempB;
						
						/* Roof24 */
						TempR = Roof24[23].DutyR;
						TempG = Roof24[23].DutyG;
						TempB = Roof24[23].DutyB;
						for (TempLed = 23; TempLed > 0; TempLed--)
						{
							Roof24[TempLed].DutyR = Roof24[TempLed - 1].DutyR;
							Roof24[TempLed].DutyG = Roof24[TempLed - 1].DutyG;
							Roof24[TempLed].DutyB = Roof24[TempLed - 1].DutyB;
						}
						Roof24[0].DutyR = TempR;
						Roof24[0].DutyG = TempG;
						Roof24[0].DutyB = TempB;
						
						/* Roof30 */
						TempR = Roof30[29].DutyR;
						TempG = Roof30[29].DutyG;
						TempB = Roof30[29].DutyB;
						for (TempLed = 29; TempLed > 0; TempLed--)
						{
							Roof30[TempLed].DutyR = Roof30[TempLed - 1].DutyR;
							Roof30[TempLed].DutyG = Roof30[TempLed - 1].DutyG;
							Roof30[TempLed].DutyB = Roof30[TempLed - 1].DutyB;
						}
						Roof30[0].DutyR = TempR;
						Roof30[0].DutyG = TempG;
						Roof30[0].DutyB = TempB;
						
						/* String30 */
						TempR = String30[29].DutyR;
						TempG = String30[29].DutyG;
						TempB = String30[29].DutyB;
						for (TempLed = 29; TempLed > 0; TempLed--)
						{
							String30[TempLed].DutyR = String30[TempLed - 1].DutyR;
							String30[TempLed].DutyG = String30[TempLed - 1].DutyG;
							String30[TempLed].DutyB = String30[TempLed - 1].DutyB;
						}
						String30[0].DutyR = TempR;
						String30[0].DutyG = TempG;
						String30[0].DutyB = TempB;
						
						/* String24 */
						TempR = String24[23].DutyR;
						TempG = String24[23].DutyG;
						TempB = String24[23].DutyB;
						for (TempLed = 23; TempLed > 0; TempLed--)
						{
							String24[TempLed].DutyR = String24[TempLed - 1].DutyR;
							String24[TempLed].DutyG = String24[TempLed - 1].DutyG;
							String24[TempLed].DutyB = String24[TempLed - 1].DutyB;
						}
						String24[0].DutyR = TempR;
						String24[0].DutyG = TempG;
						String24[0].DutyB = TempB;
						
						/* String36 */
						TempR = String36[35].DutyR;
						TempG = String36[35].DutyG;
						TempB = String36[35].DutyB;
						for (TempLed = 35; TempLed > 0; TempLed--)
						{
							String36[TempLed].DutyR = String36[TempLed - 1].DutyR;
							String36[TempLed].DutyG = String36[TempLed - 1].DutyG;
							String36[TempLed].DutyB = String36[TempLed - 1].DutyB;
						}
						String36[0].DutyR = TempR;
						String36[0].DutyG = TempG;
						String36[0].DutyB = TempB;
						
						/* Roof40 */
						TempR = Roof40[39].DutyR;
						TempG = Roof40[39].DutyG;
						TempB = Roof40[39].DutyB;
						for (TempLed = 39; TempLed > 0; TempLed--)
						{
							Roof40[TempLed].DutyR = Roof40[TempLed - 1].DutyR;
							Roof40[TempLed].DutyG = Roof40[TempLed - 1].DutyG;
							Roof40[TempLed].DutyB = Roof40[TempLed - 1].DutyB;
						}
						Roof40[0].DutyR = TempR;
						Roof40[0].DutyG = TempG;
						Roof40[0].DutyB = TempB;
						
						
						KeepTime++;
						if (KeepTime >= 3)
						{
							KeepTime = 0;
						
							/* Tree */
							for (TempCnt = 0; TempCnt < 3; TempCnt++)
							{
								Grd.Tree[TempCnt * 9 + 8].DutyR = Grd.Tree[TempCnt * 9 + 7].DutyR;
								Grd.Tree[TempCnt * 9 + 8].DutyG = Grd.Tree[TempCnt * 9 + 7].DutyG;
								Grd.Tree[TempCnt * 9 + 8].DutyB = Grd.Tree[TempCnt * 9 + 7].DutyB;
								
								Grd.Tree[TempCnt * 9 + 7].DutyR = Grd.Tree[TempCnt * 9 + 5].DutyR;
								Grd.Tree[TempCnt * 9 + 7].DutyG = Grd.Tree[TempCnt * 9 + 5].DutyG;
								Grd.Tree[TempCnt * 9 + 7].DutyB = Grd.Tree[TempCnt * 9 + 5].DutyB;
								Grd.Tree[TempCnt * 9 + 6].DutyR = Grd.Tree[TempCnt * 9 + 5].DutyR;
								Grd.Tree[TempCnt * 9 + 6].DutyG = Grd.Tree[TempCnt * 9 + 5].DutyG;
								Grd.Tree[TempCnt * 9 + 6].DutyB = Grd.Tree[TempCnt * 9 + 5].DutyB;
								
								Grd.Tree[TempCnt * 9 + 5].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
								Grd.Tree[TempCnt * 9 + 5].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
								Grd.Tree[TempCnt * 9 + 5].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
								Grd.Tree[TempCnt * 9 + 4].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
								Grd.Tree[TempCnt * 9 + 4].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
								Grd.Tree[TempCnt * 9 + 4].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
								Grd.Tree[TempCnt * 9 + 3].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
								Grd.Tree[TempCnt * 9 + 3].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
								Grd.Tree[TempCnt * 9 + 3].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
								
								Grd.Tree[TempCnt * 9 + 2].DutyR = ColorData[ModeColorTree[0]][R];
								Grd.Tree[TempCnt * 9 + 2].DutyG = ColorData[ModeColorTree[0]][G];
								Grd.Tree[TempCnt * 9 + 2].DutyB = ColorData[ModeColorTree[0]][B];
								Grd.Tree[TempCnt * 9 + 1].DutyR = ColorData[ModeColorTree[0]][R];
								Grd.Tree[TempCnt * 9 + 1].DutyG = ColorData[ModeColorTree[0]][G];
								Grd.Tree[TempCnt * 9 + 1].DutyB = ColorData[ModeColorTree[0]][B];
								Grd.Tree[TempCnt * 9 + 0].DutyR = ColorData[ModeColorTree[0]][R];
								Grd.Tree[TempCnt * 9 + 0].DutyG = ColorData[ModeColorTree[0]][G];
								Grd.Tree[TempCnt * 9 + 0].DutyB = ColorData[ModeColorTree[0]][B];
							}
							
							RndCntTree++;
							if (RndCntTree >= 4)
							{
								RndCntTree = 0;
								ModeColorTree[0]++;
								if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
							}
							
							
							/* Snow */
							for (TempCnt = 0; TempCnt < 3; TempCnt++)
							{
								for (TempLed = 6; TempLed > 0; TempLed--)
								{
									Grd.Snow[TempCnt * 7 + TempLed].DutyR = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyR;
									Grd.Snow[TempCnt * 7 + TempLed].DutyG = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyG;
									Grd.Snow[TempCnt * 7 + TempLed].DutyB = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyB;
								}
								
								Grd.Snow[TempCnt * 7].DutyR = ColorData[ModeColorSnow[0]][R];
								Grd.Snow[TempCnt * 7].DutyG = ColorData[ModeColorSnow[0]][G];
								Grd.Snow[TempCnt * 7].DutyB = ColorData[ModeColorSnow[0]][B];
							}
							
							RndCntSnow++;
							if (RndCntSnow >= 7)
							{
								RndCntSnow = 0;
								for (TempCnt = 0; TempCnt < 3; TempCnt++)
								{
									ModeColorSnow[TempCnt]++;
									if (ModeColorSnow[TempCnt] >= ColorNum)		ModeColorSnow[TempCnt] = 0;
								}
							}
							
							/* Cane */
							for (TempCnt = 5; TempCnt > 0; TempCnt--)
							{
								for (TempLed = 0; TempLed < 5; TempLed++)
								{
									Grd.Cane[TempCnt * 5 + TempLed].DutyR = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyR;
									Grd.Cane[TempCnt * 5 + TempLed].DutyG = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyG;
									Grd.Cane[TempCnt * 5 + TempLed].DutyB = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Grd.Cane[TempLed].DutyR = ColorData[ModeColorCane[0]][R];
								Grd.Cane[TempLed].DutyG = ColorData[ModeColorCane[0]][G];
								Grd.Cane[TempLed].DutyB = ColorData[ModeColorCane[0]][B];
							}
							
							ModeColorCane[0]++;
							if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
							
							/* Spot */
							for (TempCnt = 2; TempCnt > 0; TempCnt--)
							{
								Grd.Spot[TempCnt].DutyR = Grd.Spot[TempCnt - 1].DutyR;
								Grd.Spot[TempCnt].DutyG = Grd.Spot[TempCnt - 1].DutyG;
								Grd.Spot[TempCnt].DutyB = Grd.Spot[TempCnt - 1].DutyB;
							}
							Grd.Spot[0].DutyR = ColorData[ModeColorSpot[0]][R];
							Grd.Spot[0].DutyG = ColorData[ModeColorSpot[0]][G];
							Grd.Spot[0].DutyB = ColorData[ModeColorSpot[0]][B];
							
							ModeColorSpot[0]++;
							if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
							
							/* Ball */
							for (TempCnt = 0; TempCnt < 4; TempCnt++)
							{
								Grd.Ball[TempCnt].DutyR = ColorData[ModeColorBall][R];
								Grd.Ball[TempCnt].DutyG = ColorData[ModeColorBall][G];
								Grd.Ball[TempCnt].DutyB = ColorData[ModeColorBall][B];
							}
							ModeColorBall++;
							if (ModeColorBall >= ColorNum)		ModeColorBall = 0;
						}

						
						/* Hold Time */
						HoldTime++;
						if (HoldTime >= 80)
						{
							HoldTime = 0;
							TempStep++;
							RndCnt10 = 0;
							RndCnt24 = 0;
							RndCnt30 = 0;
							RndCnts30 = 0;
							RndCnts24 = 0;
							RndCnts36 = 0;
							RndCnt40 = 0;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
							RndCntSpot = 0;
							RndCntBall = 0;

							TempColor = 0;
						}
					}
		} break;
		
		/* Instead several section 0~5 , 6~11, 12~17, 18~23*/
		case 2:
		case 4:
		case 6:
		{
					SpeedTime++;
					if (SpeedTime >= 20)
					{
						SpeedTime = 0;
						
						/* Roof 10 */
						if (RndCnt10 < 5)
						{
							for (TempLed = 0; TempLed < 2; TempLed++)
							{
								Roof10[TempLed * 5 + RndCnt10].DutyR = ColorData[TempColor][R];
								Roof10[TempLed * 5 + RndCnt10].DutyG = ColorData[TempColor][G];
								Roof10[TempLed * 5 + RndCnt10].DutyB = ColorData[TempColor][B];
							}
							RndCnt10++;
						}
						
						/* Roof 24 */
						if (RndCnt24 < 6)
						{
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								Roof24[TempLed * 6 + RndCnt24].DutyR = ColorData[TempColor][R];
								Roof24[TempLed * 6 + RndCnt24].DutyG = ColorData[TempColor][G];
								Roof24[TempLed * 6 + RndCnt24].DutyB = ColorData[TempColor][B];
							}
							RndCnt24++;
						}
						
						/* Roof 29 */
						if (RndCnt30 < 6)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								if (TempLed * 6 + RndCnt30 < 29)
								{
									Roof30[TempLed * 6 + RndCnt30].DutyR = ColorData[TempColor][R];
									Roof30[TempLed * 6 + RndCnt30].DutyG = ColorData[TempColor][G];
									Roof30[TempLed * 6 + RndCnt30].DutyB = ColorData[TempColor][B];
								}
							}
							RndCnt30++;
						}
						
						/* Roof 40 */
						if (RndCnt40 < 8)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Roof40[TempLed * 8 + RndCnt40].DutyR = ColorData[TempColor][R];
								Roof40[TempLed * 8 + RndCnt40].DutyG = ColorData[TempColor][G];
								Roof40[TempLed * 8 + RndCnt40].DutyB = ColorData[TempColor][B];
							}
							RndCnt40++;
						}
						
						/* String 30 */
						if (RndCnts30 < 6)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								String30[TempLed * 6 + RndCnts30].DutyR = ColorData[TempColor][R];
								String30[TempLed * 6 + RndCnts30].DutyG = ColorData[TempColor][G];
								String30[TempLed * 6 + RndCnts30].DutyB = ColorData[TempColor][B];
							}
							RndCnts30++;
						}
						
						/* String 24 */
						if (RndCnts24 < 6)
						{
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								String24[TempLed * 6 + RndCnts24].DutyR = ColorData[TempColor][R];
								String24[TempLed * 6 + RndCnts24].DutyG = ColorData[TempColor][G];
								String24[TempLed * 6 + RndCnts24].DutyB = ColorData[TempColor][B];
							}
							RndCnts24++;
						}
						
						/* String 36 */
						if (RndCnts36 < 6)
						{
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								String36[TempLed * 6 + RndCnts36].DutyR = ColorData[TempColor][R];
								String36[TempLed * 6 + RndCnts36].DutyG = ColorData[TempColor][G];
								String36[TempLed * 6 + RndCnts36].DutyB = ColorData[TempColor][B];
							}
							RndCnts36++;
						}
						
						
						/* Tree */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							Grd.Tree[TempCnt * 9 + 8].DutyR = Grd.Tree[TempCnt * 9 + 7].DutyR;
							Grd.Tree[TempCnt * 9 + 8].DutyG = Grd.Tree[TempCnt * 9 + 7].DutyG;
							Grd.Tree[TempCnt * 9 + 8].DutyB = Grd.Tree[TempCnt * 9 + 7].DutyB;
							
							Grd.Tree[TempCnt * 9 + 7].DutyR = Grd.Tree[TempCnt * 9 + 5].DutyR;
							Grd.Tree[TempCnt * 9 + 7].DutyG = Grd.Tree[TempCnt * 9 + 5].DutyG;
							Grd.Tree[TempCnt * 9 + 7].DutyB = Grd.Tree[TempCnt * 9 + 5].DutyB;
							Grd.Tree[TempCnt * 9 + 6].DutyR = Grd.Tree[TempCnt * 9 + 5].DutyR;
							Grd.Tree[TempCnt * 9 + 6].DutyG = Grd.Tree[TempCnt * 9 + 5].DutyG;
							Grd.Tree[TempCnt * 9 + 6].DutyB = Grd.Tree[TempCnt * 9 + 5].DutyB;
							
							Grd.Tree[TempCnt * 9 + 5].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
							Grd.Tree[TempCnt * 9 + 5].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
							Grd.Tree[TempCnt * 9 + 5].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
							Grd.Tree[TempCnt * 9 + 4].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
							Grd.Tree[TempCnt * 9 + 4].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
							Grd.Tree[TempCnt * 9 + 4].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
							Grd.Tree[TempCnt * 9 + 3].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
							Grd.Tree[TempCnt * 9 + 3].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
							Grd.Tree[TempCnt * 9 + 3].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
							
							Grd.Tree[TempCnt * 9 + 2].DutyR = ColorData[TempColor][R];
							Grd.Tree[TempCnt * 9 + 2].DutyG = ColorData[TempColor][G];
							Grd.Tree[TempCnt * 9 + 2].DutyB = ColorData[TempColor][B];
							Grd.Tree[TempCnt * 9 + 1].DutyR = ColorData[TempColor][R];
							Grd.Tree[TempCnt * 9 + 1].DutyG = ColorData[TempColor][G];
							Grd.Tree[TempCnt * 9 + 1].DutyB = ColorData[TempColor][B];
							Grd.Tree[TempCnt * 9 + 0].DutyR = ColorData[TempColor][R];
							Grd.Tree[TempCnt * 9 + 0].DutyG = ColorData[TempColor][G];
							Grd.Tree[TempCnt * 9 + 0].DutyB = ColorData[TempColor][B];
						}
						
						
						/* Snow */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							for (TempLed = 6; TempLed > 0; TempLed--)
							{
								Grd.Snow[TempCnt * 7 + TempLed].DutyR = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyR;
								Grd.Snow[TempCnt * 7 + TempLed].DutyG = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyG;
								Grd.Snow[TempCnt * 7 + TempLed].DutyB = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyB;
							}
							
							Grd.Snow[TempCnt * 7].DutyR = ColorData[TempColor][R];
							Grd.Snow[TempCnt * 7].DutyG = ColorData[TempColor][G];
							Grd.Snow[TempCnt * 7].DutyB = ColorData[TempColor][B];
						}
						
						/* Cane */
						for (TempCnt = 5; TempCnt > 0; TempCnt--)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Grd.Cane[TempCnt * 5 + TempLed].DutyR = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyR;
								Grd.Cane[TempCnt * 5 + TempLed].DutyG = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyG;
								Grd.Cane[TempCnt * 5 + TempLed].DutyB = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyB;
							}
						}
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempLed].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempLed].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempLed].DutyB = ColorData[TempColor][B];
						}
						
						
						/* Spot */
						for (TempCnt = 2; TempCnt > 0; TempCnt--)
						{
							Grd.Spot[TempCnt].DutyR = Grd.Spot[TempCnt - 1].DutyR;
							Grd.Spot[TempCnt].DutyG = Grd.Spot[TempCnt - 1].DutyG;
							Grd.Spot[TempCnt].DutyB = Grd.Spot[TempCnt - 1].DutyB;
						}
						Grd.Spot[0].DutyR = ColorData[TempColor][R];
						Grd.Spot[0].DutyG = ColorData[TempColor][G];
						Grd.Spot[0].DutyB = ColorData[TempColor][B];
						
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = ColorData[TempColor][R];
							Grd.Ball[TempCnt].DutyG = ColorData[TempColor][G];
							Grd.Ball[TempCnt].DutyB = ColorData[TempColor][B];
						}
					
						if (RndCnt40 >= 8)
						{
							TempStep++;
							TempColor++;
							if (TempColor >= ColorNum)	TempColor = 0;
							RndCnt10 = 0;
							RndCnt24 = 0;
							RndCnt30 = 0;
							RndCnts30 = 0;
							RndCnts24 = 0;
							RndCnts36 = 0;
							RndCnt40 = 0;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
							RndCntSpot = 0;
							RndCntBall = 0;
						}
					}
		} break;
		
		case 3:
		case 5:
		case 7:
		{
					SpeedTime++;
					if (SpeedTime >= 20)
					{
						SpeedTime = 0;
						
						/* Roof 10 */
						if (RndCnt10 < 5)
						{
							RndCnt10++;
							for (TempLed = 0; TempLed < 2; TempLed++)
							{
								Roof10[TempLed * 5 + 5 - RndCnt10].DutyR = ColorData[TempColor][R];
								Roof10[TempLed * 5 + 5 - RndCnt10].DutyG = ColorData[TempColor][G];
								Roof10[TempLed * 5 + 5 - RndCnt10].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof 24 */
						if (RndCnt24 < 6)
						{
							RndCnt24++;
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								Roof24[TempLed * 6 + 6 - RndCnt24].DutyR = ColorData[TempColor][R];
								Roof24[TempLed * 6 + 6 - RndCnt24].DutyG = ColorData[TempColor][G];
								Roof24[TempLed * 6 + 6 - RndCnt24].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof 29 */
						if (RndCnt30 < 6)
						{
							RndCnt30++;
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								if (TempLed * 6 + RndCnt30 < 29)
								{
									Roof30[TempLed * 6 + 6 - RndCnt30].DutyR = ColorData[TempColor][R];
									Roof30[TempLed * 6 + 6 - RndCnt30].DutyG = ColorData[TempColor][G];
									Roof30[TempLed * 6 + 6 - RndCnt30].DutyB = ColorData[TempColor][B];
								}
							}
						}
						
						/* Roof 40 */
						if (RndCnt40 < 8)
						{
							RndCnt40++;
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Roof40[TempLed * 8 + 8 - RndCnt40].DutyR = ColorData[TempColor][R];
								Roof40[TempLed * 8 + 8 - RndCnt40].DutyG = ColorData[TempColor][G];
								Roof40[TempLed * 8 + 8 - RndCnt40].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String 30 */
						if (RndCnts30 < 6)
						{
							RndCnts30++;
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								String30[TempLed * 6 + 6 - RndCnts30].DutyR = ColorData[TempColor][R];
								String30[TempLed * 6 + 6 - RndCnts30].DutyG = ColorData[TempColor][G];
								String30[TempLed * 6 + 6 - RndCnts30].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String 24 */
						if (RndCnts24 < 6)
						{
							RndCnts24++;
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								String24[TempLed * 6 + 6 - RndCnts24].DutyR = ColorData[TempColor][R];
								String24[TempLed * 6 + 6 - RndCnts24].DutyG = ColorData[TempColor][G];
								String24[TempLed * 6 + 6 - RndCnts24].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String 36 */
						if (RndCnts36 < 6)
						{
							RndCnts36++;
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								String36[TempLed * 6 + 6 - RndCnts36].DutyR = ColorData[TempColor][R];
								String36[TempLed * 6 + 6 - RndCnts36].DutyG = ColorData[TempColor][G];
								String36[TempLed * 6 + 6 - RndCnts36].DutyB = ColorData[TempColor][B];
							}
						}
						
						
						
						/* Tree */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							Grd.Tree[TempCnt * 9 + 2].DutyR = Grd.Tree[TempCnt * 9 + 3].DutyR;
							Grd.Tree[TempCnt * 9 + 2].DutyG = Grd.Tree[TempCnt * 9 + 3].DutyG;
							Grd.Tree[TempCnt * 9 + 2].DutyB = Grd.Tree[TempCnt * 9 + 3].DutyB;
							Grd.Tree[TempCnt * 9 + 1].DutyR = Grd.Tree[TempCnt * 9 + 3].DutyR;
							Grd.Tree[TempCnt * 9 + 1].DutyG = Grd.Tree[TempCnt * 9 + 3].DutyG;
							Grd.Tree[TempCnt * 9 + 1].DutyB = Grd.Tree[TempCnt * 9 + 3].DutyB;
							Grd.Tree[TempCnt * 9 + 0].DutyR = Grd.Tree[TempCnt * 9 + 3].DutyR;
							Grd.Tree[TempCnt * 9 + 0].DutyG = Grd.Tree[TempCnt * 9 + 3].DutyG;
							Grd.Tree[TempCnt * 9 + 0].DutyB = Grd.Tree[TempCnt * 9 + 3].DutyB;
							
							Grd.Tree[TempCnt * 9 + 5].DutyR = Grd.Tree[TempCnt * 9 + 6].DutyR;
							Grd.Tree[TempCnt * 9 + 5].DutyG = Grd.Tree[TempCnt * 9 + 6].DutyG;
							Grd.Tree[TempCnt * 9 + 5].DutyB = Grd.Tree[TempCnt * 9 + 6].DutyB;
							Grd.Tree[TempCnt * 9 + 4].DutyR = Grd.Tree[TempCnt * 9 + 6].DutyR;
							Grd.Tree[TempCnt * 9 + 4].DutyG = Grd.Tree[TempCnt * 9 + 6].DutyG;
							Grd.Tree[TempCnt * 9 + 4].DutyB = Grd.Tree[TempCnt * 9 + 6].DutyB;
							Grd.Tree[TempCnt * 9 + 3].DutyR = Grd.Tree[TempCnt * 9 + 6].DutyR;
							Grd.Tree[TempCnt * 9 + 3].DutyG = Grd.Tree[TempCnt * 9 + 6].DutyG;
							Grd.Tree[TempCnt * 9 + 3].DutyB = Grd.Tree[TempCnt * 9 + 6].DutyB;
							
							Grd.Tree[TempCnt * 9 + 7].DutyR = Grd.Tree[TempCnt * 9 + 8].DutyR;
							Grd.Tree[TempCnt * 9 + 7].DutyG = Grd.Tree[TempCnt * 9 + 8].DutyG;
							Grd.Tree[TempCnt * 9 + 7].DutyB = Grd.Tree[TempCnt * 9 + 8].DutyB;
							Grd.Tree[TempCnt * 9 + 6].DutyR = Grd.Tree[TempCnt * 9 + 8].DutyR;
							Grd.Tree[TempCnt * 9 + 6].DutyG = Grd.Tree[TempCnt * 9 + 8].DutyG;
							Grd.Tree[TempCnt * 9 + 6].DutyB = Grd.Tree[TempCnt * 9 + 8].DutyB;
							
							
							Grd.Tree[TempCnt * 9 + 8].DutyR = ColorData[TempColor][R];
							Grd.Tree[TempCnt * 9 + 8].DutyG = ColorData[TempColor][G];
							Grd.Tree[TempCnt * 9 + 8].DutyB = ColorData[TempColor][B];
						}
						
						
						/* Snow */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								Grd.Snow[TempCnt * 7 + TempLed].DutyR = Grd.Snow[TempCnt * 7 + TempLed + 1].DutyR;
								Grd.Snow[TempCnt * 7 + TempLed].DutyG = Grd.Snow[TempCnt * 7 + TempLed + 1].DutyG;
								Grd.Snow[TempCnt * 7 + TempLed].DutyB = Grd.Snow[TempCnt * 7 + TempLed + 1].DutyB;
							}
							
							Grd.Snow[TempCnt * 7 + 6].DutyR = ColorData[TempColor][R];
							Grd.Snow[TempCnt * 7 + 6].DutyG = ColorData[TempColor][G];
							Grd.Snow[TempCnt * 7 + 6].DutyB = ColorData[TempColor][B];
						}
						
						/* Cane */
						for (TempCnt = 0; TempCnt < 5; TempCnt++)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Grd.Cane[TempCnt * 5 + TempLed].DutyR = Grd.Cane[TempCnt * 5 + TempLed + 5].DutyR;
								Grd.Cane[TempCnt * 5 + TempLed].DutyG = Grd.Cane[TempCnt * 5 + TempLed + 5].DutyG;
								Grd.Cane[TempCnt * 5 + TempLed].DutyB = Grd.Cane[TempCnt * 5 + TempLed + 5].DutyB;
							}
						}
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempLed + 25].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempLed + 25].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempLed + 25].DutyB = ColorData[TempColor][B];
						}
						
						
						/* Spot */
						for (TempCnt = 0; TempCnt < 2; TempCnt++)
						{
							Grd.Spot[TempCnt].DutyR = Grd.Spot[TempCnt + 1].DutyR;
							Grd.Spot[TempCnt].DutyG = Grd.Spot[TempCnt + 1].DutyG;
							Grd.Spot[TempCnt].DutyB = Grd.Spot[TempCnt + 1].DutyB;
						}
						Grd.Spot[2].DutyR = ColorData[TempColor][R];
						Grd.Spot[2].DutyG = ColorData[TempColor][G];
						Grd.Spot[2].DutyB = ColorData[TempColor][B];
						
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = ColorData[TempColor][R];
							Grd.Ball[TempCnt].DutyG = ColorData[TempColor][G];
							Grd.Ball[TempCnt].DutyB = ColorData[TempColor][B];
						}
						
						if (RndCnt40 >= 8)
						{
							TempStep++;
							TempColor++;
							if (TempColor >= ColorNum)	TempColor = 0;
							RndCnt10 = 0;
							RndCnt24 = 0;
							RndCnt30 = 0;
							RndCnts30 = 0;
							RndCnts24 = 0;
							RndCnts36 = 0;
							RndCnt40 = 0;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
							RndCntSpot = 0;
							RndCntBall = 0;
						}
					}
		} break;
		
		case 8:
		{
					SpeedTime++;
					if (SpeedTime >= 10)
					{
						SpeedTime = 0;
						
						/* Roof 10 */
						if (RndCnt10 < 5)
						{
							for (TempLed = 0; TempLed < 2; TempLed++)
							{
								Roof10[TempLed * 5 + RndCnt10].DutyR = 0;
								Roof10[TempLed * 5 + RndCnt10].DutyG = 0;
								Roof10[TempLed * 5 + RndCnt10].DutyB = 0;
							}
							RndCnt10++;
						}
						
						/* Roof 24 */
						if (RndCnt24 < 6)
						{
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								Roof24[TempLed * 6 + RndCnt24].DutyR = 0;
								Roof24[TempLed * 6 + RndCnt24].DutyG = 0;
								Roof24[TempLed * 6 + RndCnt24].DutyB = 0;
							}
							RndCnt24++;
						}
						
						/* Roof 29 */
						if (RndCnt30 < 6)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								if (TempLed * 6 + RndCnt30 < 29)
								{
									Roof30[TempLed * 6 + RndCnt30].DutyR = 0;
									Roof30[TempLed * 6 + RndCnt30].DutyG = 0;
									Roof30[TempLed * 6 + RndCnt30].DutyB = 0;
								}
							}
							RndCnt30++;
						}
						
						/* Roof 40 */
						if (RndCnt40 < 8)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Roof40[TempLed * 8 + RndCnt40].DutyR = 0;
								Roof40[TempLed * 8 + RndCnt40].DutyG = 0;
								Roof40[TempLed * 8 + RndCnt40].DutyB = 0;
							}
							RndCnt40++;
						}
						
						/* String 30 */
						if (RndCnts30 < 6)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								String30[TempLed * 6 + RndCnts30].DutyR = 0;
								String30[TempLed * 6 + RndCnts30].DutyG = 0;
								String30[TempLed * 6 + RndCnts30].DutyB = 0;
							}
							RndCnts30++;
						}
						
						/* String 24 */
						if (RndCnts24 < 6)
						{
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								String24[TempLed * 6 + RndCnts24].DutyR = 0;
								String24[TempLed * 6 + RndCnts24].DutyG = 0;
								String24[TempLed * 6 + RndCnts24].DutyB = 0;
							}
							RndCnts24++;
						}
						
						/* String 36 */
						if (RndCnts36 < 6)
						{
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								String36[TempLed * 6 + RndCnts36].DutyR = 0;
								String36[TempLed * 6 + RndCnts36].DutyG = 0;
								String36[TempLed * 6 + RndCnts36].DutyB = 0;
							}
							RndCnts36++;
						}
						
						/* Tree */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							Grd.Tree[TempCnt * 9 + 8].DutyR = Grd.Tree[TempCnt * 9 + 7].DutyR;
							Grd.Tree[TempCnt * 9 + 8].DutyG = Grd.Tree[TempCnt * 9 + 7].DutyG;
							Grd.Tree[TempCnt * 9 + 8].DutyB = Grd.Tree[TempCnt * 9 + 7].DutyB;
							
							Grd.Tree[TempCnt * 9 + 7].DutyR = Grd.Tree[TempCnt * 9 + 5].DutyR;
							Grd.Tree[TempCnt * 9 + 7].DutyG = Grd.Tree[TempCnt * 9 + 5].DutyG;
							Grd.Tree[TempCnt * 9 + 7].DutyB = Grd.Tree[TempCnt * 9 + 5].DutyB;
							Grd.Tree[TempCnt * 9 + 6].DutyR = Grd.Tree[TempCnt * 9 + 5].DutyR;
							Grd.Tree[TempCnt * 9 + 6].DutyG = Grd.Tree[TempCnt * 9 + 5].DutyG;
							Grd.Tree[TempCnt * 9 + 6].DutyB = Grd.Tree[TempCnt * 9 + 5].DutyB;
							
							Grd.Tree[TempCnt * 9 + 5].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
							Grd.Tree[TempCnt * 9 + 5].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
							Grd.Tree[TempCnt * 9 + 5].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
							Grd.Tree[TempCnt * 9 + 4].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
							Grd.Tree[TempCnt * 9 + 4].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
							Grd.Tree[TempCnt * 9 + 4].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
							Grd.Tree[TempCnt * 9 + 3].DutyR = Grd.Tree[TempCnt * 9 + 2].DutyR;
							Grd.Tree[TempCnt * 9 + 3].DutyG = Grd.Tree[TempCnt * 9 + 2].DutyG;
							Grd.Tree[TempCnt * 9 + 3].DutyB = Grd.Tree[TempCnt * 9 + 2].DutyB;
							
							Grd.Tree[TempCnt * 9 + 2].DutyR = 0;
							Grd.Tree[TempCnt * 9 + 2].DutyG = 0;
							Grd.Tree[TempCnt * 9 + 2].DutyB = 0;
							Grd.Tree[TempCnt * 9 + 1].DutyR = 0;
							Grd.Tree[TempCnt * 9 + 1].DutyG = 0;
							Grd.Tree[TempCnt * 9 + 1].DutyB = 0;
							Grd.Tree[TempCnt * 9 + 0].DutyR = 0;
							Grd.Tree[TempCnt * 9 + 0].DutyG = 0;
							Grd.Tree[TempCnt * 9 + 0].DutyB = 0;
						}
						
						
						/* Snow */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							for (TempLed = 6; TempLed > 0; TempLed--)
							{
								Grd.Snow[TempCnt * 7 + TempLed].DutyR = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyR;
								Grd.Snow[TempCnt * 7 + TempLed].DutyG = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyG;
								Grd.Snow[TempCnt * 7 + TempLed].DutyB = Grd.Snow[TempCnt * 7 + TempLed - 1].DutyB;
							}
							
							Grd.Snow[TempCnt * 7].DutyR = 0;
							Grd.Snow[TempCnt * 7].DutyG = 0;
							Grd.Snow[TempCnt * 7].DutyB = 0;
						}
						
						/* Cane */
						for (TempCnt = 5; TempCnt > 0; TempCnt--)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Grd.Cane[TempCnt * 5 + TempLed].DutyR = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyR;
								Grd.Cane[TempCnt * 5 + TempLed].DutyG = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyG;
								Grd.Cane[TempCnt * 5 + TempLed].DutyB = Grd.Cane[TempCnt * 5 + TempLed - 5].DutyB;
							}
						}
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempLed].DutyR = 0;
							Grd.Cane[TempLed].DutyG = 0;
							Grd.Cane[TempLed].DutyB = 0;
						}
						
						
						/* Spot */
						for (TempCnt = 2; TempCnt > 0; TempCnt--)
						{
							Grd.Spot[TempCnt].DutyR = Grd.Spot[TempCnt - 1].DutyR;
							Grd.Spot[TempCnt].DutyG = Grd.Spot[TempCnt - 1].DutyG;
							Grd.Spot[TempCnt].DutyB = Grd.Spot[TempCnt - 1].DutyB;
						}
						Grd.Spot[0].DutyR = 0;
						Grd.Spot[0].DutyG = 0;
						Grd.Spot[0].DutyB = 0;
						
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = 0;
							Grd.Ball[TempCnt].DutyG = 0;
							Grd.Ball[TempCnt].DutyB = 0;
						}
						
						if (RndCnt40 >= 8)
						{
							TempStep++;
							RndCnt10 = 0;
							RndCnt24 = 0;
							RndCnt30 = 0;
							RndCnts30 = 0;
							RndCnts24 = 0;
							RndCnts36 = 0;
							RndCnt40 = 0;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
							RndCntSpot = 0;
							RndCntBall = 0;
						}
					}
		} break;
		
		default:		
		{
					TempStep = 0xFF;
		}break;
	}
}



/*
 * FunctionName	Show_1_2
 * TimeLine		 = 3345
 */
void Show_1_2(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		SpeedTime	= 0;
		TempStep	= 0;
		TempColor = 0;
		RndCnt10 = 0;
		RndCntTree = 0;
		RndCntSnow = 0;
		RndCntCane = 0;
		RndCntBall = 0;
		RndCntSpot = 0;
		HoldTime = 0;
		KeepTime = 0;
		return;
	}
	
	if (KeepTime >= 5)
	{
		SpeedTime++;
		if (SpeedTime >= 8)
		{
			SpeedTime = 0;
			
			// Roof10
			for (TempLed = 9; TempLed > 0; TempLed--)
			{
				Roof10[TempLed].DutyR = Roof10[TempLed - 1].DutyR;
				Roof10[TempLed].DutyG = Roof10[TempLed - 1].DutyG;
				Roof10[TempLed].DutyB = Roof10[TempLed - 1].DutyB;
			}
			
			Roof10[0].DutyR = 0;
			Roof10[0].DutyG = 0;
			Roof10[0].DutyB = 0;
			
			// Roof24
			for (TempLed = 23; TempLed > 0; TempLed--)
			{
				Roof24[TempLed].DutyR = Roof24[TempLed - 1].DutyR;
				Roof24[TempLed].DutyG = Roof24[TempLed - 1].DutyG;
				Roof24[TempLed].DutyB = Roof24[TempLed - 1].DutyB;
			}
			
			Roof24[0].DutyR = 0;
			Roof24[0].DutyG = 0;
			Roof24[0].DutyB = 0;
			
			// Roof30
			for (TempLed = 29; TempLed > 0; TempLed--)
			{
				Roof30[TempLed].DutyR = Roof30[TempLed - 1].DutyR;
				Roof30[TempLed].DutyG = Roof30[TempLed - 1].DutyG;
				Roof30[TempLed].DutyB = Roof30[TempLed - 1].DutyB;
			}
			
			Roof30[0].DutyR = 0;
			Roof30[0].DutyG = 0;
			Roof30[0].DutyB = 0;
			
			// Roof40
			for (TempLed = 39; TempLed > 0; TempLed--)
			{
				Roof40[TempLed].DutyR = Roof40[TempLed - 1].DutyR;
				Roof40[TempLed].DutyG = Roof40[TempLed - 1].DutyG;
				Roof40[TempLed].DutyB = Roof40[TempLed - 1].DutyB;
			}
			
			Roof40[0].DutyR = 0;
			Roof40[0].DutyG = 0;
			Roof40[0].DutyB = 0;
			
			//String30
			for (TempLed = 29; TempLed > 0; TempLed--)
			{
				String30[TempLed].DutyR = String30[TempLed - 1].DutyR;
				String30[TempLed].DutyG = String30[TempLed - 1].DutyG;
				String30[TempLed].DutyB = String30[TempLed - 1].DutyB;
			}
			
			String30[0].DutyR = 0;
			String30[0].DutyG = 0;
			String30[0].DutyB = 0;
			
			//String24
			for (TempLed = 23; TempLed > 0; TempLed--)
			{
				String24[TempLed].DutyR = String24[TempLed - 1].DutyR;
				String24[TempLed].DutyG = String24[TempLed - 1].DutyG;
				String24[TempLed].DutyB = String24[TempLed - 1].DutyB;
			}
			
			String24[0].DutyR = 0;
			String24[0].DutyG = 0;
			String24[0].DutyB = 0;
			
			
			//String36
			for (TempLed = 35; TempLed > 0; TempLed--)
			{
				String36[TempLed].DutyR = String36[TempLed - 1].DutyR;
				String36[TempLed].DutyG = String36[TempLed - 1].DutyG;
				String36[TempLed].DutyB = String36[TempLed - 1].DutyB;
			}
			
			String36[0].DutyR = 0;
			String36[0].DutyG = 0;
			String36[0].DutyB = 0;
			
			/* Tree */
			if (RndCntTree < 12)
			{
				RndCntTree++;
				switch (RndCntTree)
				{
					case 1:			ModeLedTree[0] = 0;			ModeLedTree[1] = 1;	  	ModeLedTree[2] = 2;		 		break;
					case 2:			ModeLedTree[0] = 3;			ModeLedTree[1] = 4;	  	ModeLedTree[2] = 5;		 		break;
					case 3:			ModeLedTree[0] = 6;			ModeLedTree[1] = 7;	   	ModeLedTree[2] = 7;				break;
					case 4:			ModeLedTree[0] = 8;		 	ModeLedTree[1] = 8;	   	ModeLedTree[2] = 8;				break;
					case 5:			ModeLedTree[0] = 9;			ModeLedTree[1] = 10;	  ModeLedTree[2] = 11;		 	break;
					case 6:			ModeLedTree[0] = 12;		ModeLedTree[1] = 13;	  ModeLedTree[2] = 14;		 	break;
					case 7:			ModeLedTree[0] = 15;		ModeLedTree[1] = 16;	 	ModeLedTree[2] = 16;			break;
					case 8:			ModeLedTree[2] = 17;		ModeLedTree[1] = 17;	  ModeLedTree[2] = 17;		 	break;
					case 9:			ModeLedTree[0] = 18;		ModeLedTree[1] = 19;	  ModeLedTree[2] = 20;		 	break;
					case 10:		ModeLedTree[0] = 21;		ModeLedTree[1] = 22;	  ModeLedTree[2] = 23;		 	break;
					case 11:		ModeLedTree[0] = 24;		ModeLedTree[1] = 25;	  ModeLedTree[2] = 25;		 	break;
					case 12:		ModeLedTree[2] = 26;		ModeLedTree[1] = 26;	  ModeLedTree[2] = 26;		 	break;
				}

				Grd.Tree[ModeLedTree[0]].DutyR	= 0;
				Grd.Tree[ModeLedTree[0]].DutyG	= 0;
				Grd.Tree[ModeLedTree[0]].DutyB	= 0;
				Grd.Tree[ModeLedTree[1]].DutyR	= 0;
				Grd.Tree[ModeLedTree[1]].DutyG	= 0;
				Grd.Tree[ModeLedTree[1]].DutyB	= 0;
				Grd.Tree[ModeLedTree[2]].DutyR	= 0;
				Grd.Tree[ModeLedTree[2]].DutyG	= 0;
				Grd.Tree[ModeLedTree[2]].DutyB	= 0;
			}
			
			/* Snow */
			if (RndCntSnow < 7)
			{
				RndCntSnow++;
				switch (RndCntSnow)
				{
					case 1:		ModeLedSnow[0] = 0;			ModeLedSnow[1] = 7;			 ModeLedSnow[2] = 14;	break;
					case 2:		ModeLedSnow[0] = 1;			ModeLedSnow[1] = 8;			 ModeLedSnow[2] = 15;	break;
					case 3:		ModeLedSnow[0] = 2;			ModeLedSnow[1] = 9;			 ModeLedSnow[2] = 16;	break;
					case 4:		ModeLedSnow[0] = 3;			ModeLedSnow[1] = 10;		 ModeLedSnow[2] = 17;	break;
					case 5:		ModeLedSnow[0] = 4;			ModeLedSnow[1] = 11;		 ModeLedSnow[2] = 18;	break;
					case 6:		ModeLedSnow[0] = 5;			ModeLedSnow[1] = 12;		 ModeLedSnow[2] = 19;	break;
					case 7:		ModeLedSnow[0] = 6;			ModeLedSnow[1] = 13;		 ModeLedSnow[2] = 20;	break;
				}
				
				Grd.Snow[ModeLedSnow[0]].DutyR	= 0;
				Grd.Snow[ModeLedSnow[0]].DutyG	= 0;
				Grd.Snow[ModeLedSnow[0]].DutyB	= 0;

				Grd.Snow[ModeLedSnow[1]].DutyR	= 0;
				Grd.Snow[ModeLedSnow[1]].DutyG	= 0;
				Grd.Snow[ModeLedSnow[1]].DutyB	= 0;
				
				Grd.Snow[ModeLedSnow[2]].DutyR	= 0;
				Grd.Snow[ModeLedSnow[2]].DutyG	= 0;
				Grd.Snow[ModeLedSnow[2]].DutyB	= 0;
			}
			
			/* Cane */
			if (RndCntCane < 6)
			{
				for (TempCnt = 0; TempCnt < 5; TempCnt++)
				{
					Grd.Cane[RndCntCane * 5 + TempCnt].DutyR	= 0;
					Grd.Cane[RndCntCane * 5 + TempCnt].DutyG	= 0;
					Grd.Cane[RndCntCane * 5 + TempCnt].DutyB	= 0;
				}
				
				RndCntCane++;
			}
			
			/* Spot */
			if (RndCntSpot < 3)
			{
				Grd.Spot[RndCntSpot].DutyR	= 0;
				Grd.Spot[RndCntSpot].DutyG	= 0;
				Grd.Spot[RndCntSpot].DutyB	= 0;
				RndCntSpot++;
			}
			
			/* Ball */
			for (TempCnt = 0; TempCnt < 4; TempCnt++)
			{
				Grd.Ball[TempCnt].DutyR = 0;
				Grd.Ball[TempCnt].DutyG = 0;
				Grd.Ball[TempCnt].DutyB = 0;
			}
		}
		return;
	}		
	
	SpeedTime++;
	if (SpeedTime >= 8)
	{
		SpeedTime = 0;
		
		
		// Roof10
		for (TempLed = 4; TempLed > 0; TempLed--)
		{
			Roof10[TempLed * 2].DutyR = Roof10[TempLed * 2 - 2].DutyR;
			Roof10[TempLed * 2].DutyG = Roof10[TempLed * 2 - 2].DutyG;
			Roof10[TempLed * 2].DutyB = Roof10[TempLed * 2 - 2].DutyB;
		}
		
		Roof10[0].DutyR = ColorData[TempColor][R];
		Roof10[0].DutyG = ColorData[TempColor][G];
		Roof10[0].DutyB = ColorData[TempColor][B];

		for (TempLed = 0; TempLed < 4; TempLed++)
		{
			Roof10[TempLed * 2 + 1].DutyR = Roof10[TempLed * 2 + 3].DutyR;
			Roof10[TempLed * 2 + 1].DutyG = Roof10[TempLed * 2 + 3].DutyG;
			Roof10[TempLed * 2 + 1].DutyB = Roof10[TempLed * 2 + 3].DutyB;
		}
		Roof10[9].DutyR = ColorData[TempColor + 1][R];
		Roof10[9].DutyG = ColorData[TempColor + 1][G];
		Roof10[9].DutyB = ColorData[TempColor + 1][B];
		
		// Roof24
		for (TempLed = 11; TempLed > 0; TempLed--)
		{
			Roof24[TempLed * 2].DutyR = Roof24[TempLed * 2 - 2].DutyR;
			Roof24[TempLed * 2].DutyG = Roof24[TempLed * 2 - 2].DutyG;
			Roof24[TempLed * 2].DutyB = Roof24[TempLed * 2 - 2].DutyB;
		}
		
		Roof24[0].DutyR = ColorData[TempColor][R];
		Roof24[0].DutyG = ColorData[TempColor][G];
		Roof24[0].DutyB = ColorData[TempColor][B];

		for (TempLed = 0; TempLed < 11; TempLed++)
		{
			Roof24[TempLed * 2 + 1].DutyR = Roof24[TempLed * 2 + 3].DutyR;
			Roof24[TempLed * 2 + 1].DutyG = Roof24[TempLed * 2 + 3].DutyG;
			Roof24[TempLed * 2 + 1].DutyB = Roof24[TempLed * 2 + 3].DutyB;
		}
		Roof24[23].DutyR = ColorData[TempColor + 1][R];
		Roof24[23].DutyG = ColorData[TempColor + 1][G];
		Roof24[23].DutyB = ColorData[TempColor + 1][B];
		
		// Roof30
		for (TempLed = 14; TempLed > 0; TempLed--)
		{
			Roof30[TempLed * 2].DutyR = Roof30[TempLed * 2 - 2].DutyR;
			Roof30[TempLed * 2].DutyG = Roof30[TempLed * 2 - 2].DutyG;
			Roof30[TempLed * 2].DutyB = Roof30[TempLed * 2 - 2].DutyB;
		}
		
		Roof30[0].DutyR = ColorData[TempColor][R];
		Roof30[0].DutyG = ColorData[TempColor][G];
		Roof30[0].DutyB = ColorData[TempColor][B];

		for (TempLed = 0; TempLed < 14; TempLed++)
		{
			Roof30[TempLed * 2 + 1].DutyR = Roof30[TempLed * 2 + 3].DutyR;
			Roof30[TempLed * 2 + 1].DutyG = Roof30[TempLed * 2 + 3].DutyG;
			Roof30[TempLed * 2 + 1].DutyB = Roof30[TempLed * 2 + 3].DutyB;
		}
		Roof30[29].DutyR = ColorData[TempColor + 1][R];
		Roof30[29].DutyG = ColorData[TempColor + 1][G];
		Roof30[29].DutyB = ColorData[TempColor + 1][B];
		
		// Roof40
		for (TempLed = 19; TempLed > 0; TempLed--)
		{
			Roof40[TempLed * 2].DutyR = Roof40[TempLed * 2 - 2].DutyR;
			Roof40[TempLed * 2].DutyG = Roof40[TempLed * 2 - 2].DutyG;
			Roof40[TempLed * 2].DutyB = Roof40[TempLed * 2 - 2].DutyB;
		}
		
		Roof40[0].DutyR = ColorData[TempColor][R];
		Roof40[0].DutyG = ColorData[TempColor][G];
		Roof40[0].DutyB = ColorData[TempColor][B];

		for (TempLed = 0; TempLed < 19; TempLed++)
		{
			Roof40[TempLed * 2 + 1].DutyR = Roof40[TempLed * 2 + 3].DutyR;
			Roof40[TempLed * 2 + 1].DutyG = Roof40[TempLed * 2 + 3].DutyG;
			Roof40[TempLed * 2 + 1].DutyB = Roof40[TempLed * 2 + 3].DutyB;
		}
		Roof40[39].DutyR = ColorData[TempColor + 1][R];
		Roof40[39].DutyG = ColorData[TempColor + 1][G];
		Roof40[39].DutyB = ColorData[TempColor + 1][B];
		
		//String30
		for (TempLed = 14; TempLed > 0; TempLed--)
		{
			String30[TempLed * 2].DutyR = String30[TempLed * 2 - 2].DutyR;
			String30[TempLed * 2].DutyG = String30[TempLed * 2 - 2].DutyG;
			String30[TempLed * 2].DutyB = String30[TempLed * 2 - 2].DutyB;
		}
		
		String30[0].DutyR = ColorData[TempColor][R];
		String30[0].DutyG = ColorData[TempColor][G];
		String30[0].DutyB = ColorData[TempColor][B];

		for (TempLed = 0; TempLed < 14; TempLed++)
		{
			String30[TempLed * 2 + 1].DutyR = String30[TempLed * 2 + 3].DutyR;
			String30[TempLed * 2 + 1].DutyG = String30[TempLed * 2 + 3].DutyG;
			String30[TempLed * 2 + 1].DutyB = String30[TempLed * 2 + 3].DutyB;
		}
		String30[29].DutyR = ColorData[TempColor + 1][R];
		String30[29].DutyG = ColorData[TempColor + 1][G];
		String30[29].DutyB = ColorData[TempColor + 1][B];
		
		//String24
		for (TempLed = 11; TempLed > 0; TempLed--)
		{
			String24[TempLed * 2].DutyR = String24[TempLed * 2 - 2].DutyR;
			String24[TempLed * 2].DutyG = String24[TempLed * 2 - 2].DutyG;
			String24[TempLed * 2].DutyB = String24[TempLed * 2 - 2].DutyB;
		}
		
		String24[0].DutyR = ColorData[TempColor][R];
		String24[0].DutyG = ColorData[TempColor][G];
		String24[0].DutyB = ColorData[TempColor][B];

		for (TempLed = 0; TempLed < 11; TempLed++)
		{
			String24[TempLed * 2 + 1].DutyR = String24[TempLed * 2 + 3].DutyR;
			String24[TempLed * 2 + 1].DutyG = String24[TempLed * 2 + 3].DutyG;
			String24[TempLed * 2 + 1].DutyB = String24[TempLed * 2 + 3].DutyB;
		}
		String24[23].DutyR = ColorData[TempColor + 1][R];
		String24[23].DutyG = ColorData[TempColor + 1][G];
		String24[23].DutyB = ColorData[TempColor + 1][B];
		
		//String36
		for (TempLed = 17; TempLed > 0; TempLed--)
		{
			String36[TempLed * 2].DutyR = String36[TempLed * 2 - 2].DutyR;
			String36[TempLed * 2].DutyG = String36[TempLed * 2 - 2].DutyG;
			String36[TempLed * 2].DutyB = String36[TempLed * 2 - 2].DutyB;
		}
		
		String36[0].DutyR = ColorData[TempColor][R];
		String36[0].DutyG = ColorData[TempColor][G];
		String36[0].DutyB = ColorData[TempColor][B];

		for (TempLed = 0; TempLed < 17; TempLed++)
		{
			String36[TempLed * 2 + 1].DutyR = String36[TempLed * 2 + 3].DutyR;
			String36[TempLed * 2 + 1].DutyG = String36[TempLed * 2 + 3].DutyG;
			String36[TempLed * 2 + 1].DutyB = String36[TempLed * 2 + 3].DutyB;
		}
		String36[35].DutyR = ColorData[TempColor + 1][R];
		String36[35].DutyG = ColorData[TempColor + 1][G];
		String36[35].DutyB = ColorData[TempColor + 1][B];
		
		/* Tree */
		if (RndCntTree < 12)
		{
			RndCntTree++;
			switch (RndCntTree)
			{
				case 1:			ModeLedTree[0] = 0;			ModeLedTree[1] = 1;	  	ModeLedTree[2] = 2;		 		break;
				case 2:			ModeLedTree[0] = 3;			ModeLedTree[1] = 4;	  	ModeLedTree[2] = 5;		 		break;
				case 3:			ModeLedTree[0] = 6;			ModeLedTree[1] = 7;	   	ModeLedTree[2] = 7;				break;
				case 4:			ModeLedTree[0] = 8;		 	ModeLedTree[1] = 8;	   	ModeLedTree[2] = 8;				break;
				case 5:			ModeLedTree[0] = 9;			ModeLedTree[1] = 10;	  ModeLedTree[2] = 11;		 	break;
				case 6:			ModeLedTree[0] = 12;		ModeLedTree[1] = 13;	  ModeLedTree[2] = 14;		 	break;
				case 7:			ModeLedTree[0] = 15;		ModeLedTree[1] = 16;	 	ModeLedTree[2] = 16;			break;
				case 8:			ModeLedTree[2] = 17;		ModeLedTree[1] = 17;	  ModeLedTree[2] = 17;		 	break;
				case 9:			ModeLedTree[0] = 18;		ModeLedTree[1] = 19;	  ModeLedTree[2] = 20;		 	break;
				case 10:		ModeLedTree[0] = 21;		ModeLedTree[1] = 22;	  ModeLedTree[2] = 23;		 	break;
				case 11:		ModeLedTree[0] = 24;		ModeLedTree[1] = 25;	  ModeLedTree[2] = 25;		 	break;
				case 12:		ModeLedTree[2] = 26;		ModeLedTree[1] = 26;	  ModeLedTree[2] = 26;		 	break;
			}

			Grd.Tree[ModeLedTree[0]].DutyR	= ColorData[ModeColorTree[0]][R];
			Grd.Tree[ModeLedTree[0]].DutyG	= ColorData[ModeColorTree[0]][G];
			Grd.Tree[ModeLedTree[0]].DutyB	= ColorData[ModeColorTree[0]][B];
			Grd.Tree[ModeLedTree[1]].DutyR	= ColorData[ModeColorTree[0]][R];
			Grd.Tree[ModeLedTree[1]].DutyG	= ColorData[ModeColorTree[0]][G];
			Grd.Tree[ModeLedTree[1]].DutyB	= ColorData[ModeColorTree[0]][B];
			Grd.Tree[ModeLedTree[2]].DutyR	= ColorData[ModeColorTree[0]][R];
			Grd.Tree[ModeLedTree[2]].DutyG	= ColorData[ModeColorTree[0]][G];
			Grd.Tree[ModeLedTree[2]].DutyB	= ColorData[ModeColorTree[0]][B];
		}
		else
		{
			RndCntTree = 0;
			ModeColorTree[0]++;
			if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
		}
		
		/* Snow */
		if (RndCntSnow < 7)
		{
			RndCntSnow++;
			switch (RndCntSnow)
			{
				case 1:		ModeLedSnow[0] = 0;			ModeLedSnow[1] = 7;			 ModeLedSnow[2] = 14;	break;
				case 2:		ModeLedSnow[0] = 1;			ModeLedSnow[1] = 8;			 ModeLedSnow[2] = 15;	break;
				case 3:		ModeLedSnow[0] = 2;			ModeLedSnow[1] = 9;			 ModeLedSnow[2] = 16;	break;
				case 4:		ModeLedSnow[0] = 3;			ModeLedSnow[1] = 10;		 ModeLedSnow[2] = 17;	break;
				case 5:		ModeLedSnow[0] = 4;			ModeLedSnow[1] = 11;		 ModeLedSnow[2] = 18;	break;
				case 6:		ModeLedSnow[0] = 5;			ModeLedSnow[1] = 12;		 ModeLedSnow[2] = 19;	break;
				case 7:		ModeLedSnow[0] = 6;			ModeLedSnow[1] = 13;		 ModeLedSnow[2] = 20;	break;
			}
			
			Grd.Snow[ModeLedSnow[0]].DutyR	= ColorData[ModeColorSnow[0]][R];
			Grd.Snow[ModeLedSnow[0]].DutyG	= ColorData[ModeColorSnow[0]][G];
			Grd.Snow[ModeLedSnow[0]].DutyB	= ColorData[ModeColorSnow[0]][B];

			Grd.Snow[ModeLedSnow[1]].DutyR	= ColorData[ModeColorSnow[0]][R];
			Grd.Snow[ModeLedSnow[1]].DutyG	= ColorData[ModeColorSnow[0]][G];
			Grd.Snow[ModeLedSnow[1]].DutyB	= ColorData[ModeColorSnow[0]][B];
			
			Grd.Snow[ModeLedSnow[2]].DutyR	= ColorData[ModeColorSnow[0]][R];
			Grd.Snow[ModeLedSnow[2]].DutyG	= ColorData[ModeColorSnow[0]][G];
			Grd.Snow[ModeLedSnow[2]].DutyB	= ColorData[ModeColorSnow[0]][B];
		}
		else
		{
			RndCntSnow = 0;
			ModeColorSnow[0]++;
			if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
		}
		
		/* Cane */
		if (RndCntCane < 6)
		{
			for (TempCnt = 0; TempCnt < 5; TempCnt++)
			{
				Grd.Cane[RndCntCane * 5 + TempCnt].DutyR	= ColorData[TempColor][R];
				Grd.Cane[RndCntCane * 5 + TempCnt].DutyG	= ColorData[TempColor][G];
				Grd.Cane[RndCntCane * 5 + TempCnt].DutyB	= ColorData[TempColor][B];
			}
			
			RndCntCane++;
		}
		else
		{
			RndCntCane = 0;
		}
		
		/* Spot */
		if (RndCntSpot < 3)
		{
			Grd.Spot[RndCntSpot].DutyR	= ColorData[TempColor][R];
			Grd.Spot[RndCntSpot].DutyG	= ColorData[TempColor][G];
			Grd.Spot[RndCntSpot].DutyB	= ColorData[TempColor][B];
			RndCntSpot++;
		}
		else
		{
			RndCntSpot = 0;
		}
		
		/* Ball */
		for (TempCnt = 0; TempCnt < 4; TempCnt++)
		{
			Grd.Ball[TempCnt].DutyR = ColorData[TempColor + 1][R];
			Grd.Ball[TempCnt].DutyG = ColorData[TempColor + 1][G];
			Grd.Ball[TempCnt].DutyB = ColorData[TempColor + 1][B];
		}
		
		
		RndCnt10++;
		if (RndCnt10 >= 6)
		{
			RndCnt10 = 0;
			TempColor++;
			if (TempColor >= ColorNum - 1)		TempColor = 0;
		}
	}
	
	/* Hold Time Control */
	HoldTime++;
	if (HoldTime >= 100)  //2s
	{
		HoldTime  = 0;
		KeepTime++;
		if (KeepTime >= 5)
		{
			RndCntTree = 0;
			RndCntSnow = 0;
			RndCntCane = 0;
			RndCntBall = 0;
			RndCntSpot = 0;
		}
	}
}

/*
 * FunctionName		Show_1_3
 * Duration				TimeLine += 2305 
 */
void Show_1_3(void)
{
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		SpeedTime			= 0;
		TempCnt				= 0;
		TempColor			= 0;
		TempStep			= 0;
		FadeR = ColorData[TempColor][R] / 25;
		FadeG = ColorData[TempColor][G] / 25;
		FadeB = ColorData[TempColor][B] / 25;
		TempR = 0;
		TempG = 0;
		TempB = 0;
		return;
	}
	
	switch (TempStep)
	{
		/* Fade in untill 40% */
		case 0:
		{
					SpeedTime++;
					if (SpeedTime >= 8)
					{
						SpeedTime = 0;
						
						TempR += FadeR;
						TempG += FadeG;
						TempB += FadeB;
						All_Color(TempR, TempG, TempB);
						TempCnt++;
						if (TempCnt > 10)
						{
							TempCnt = 0;
							TempStep++;
							HoldTime = 0;
							TempColor++;
							if (TempColor >= ColorNum)		TempColor = 0;
							FadeR = ColorData[TempColor][R] / 25;
							FadeG = ColorData[TempColor][G] / 25;
							FadeB = ColorData[TempColor][B] / 25;
						}
					}
		} break;
		
		/* Jump to Next Color 70% */
		case 1:
		{
					TempR	= FadeR * 15;
					TempG	= FadeG * 15;
					TempB	= FadeB * 15;
					
					All_Color(TempR, TempG, TempB);
					
					HoldTime++;
					if (HoldTime > 40)
					{
						HoldTime = 0;
						TempStep++;
						TempColor++;
						if (TempColor >= ColorNum)		TempColor = 0;
						FadeR = ColorData[TempColor][R] / 25;
						FadeG = ColorData[TempColor][G] / 25;
						FadeB = ColorData[TempColor][B] / 25;
					}
		} break;
		
		/* Jump to Next Color 100% */
		case 2:
		{
					TempR	= ColorData[TempColor][R];
					TempG	= ColorData[TempColor][G];
					TempB	= ColorData[TempColor][B];
					All_Color(TempR, TempG, TempB);
					
					HoldTime++;
					if (HoldTime > 80)
					{
						HoldTime = 0;
						TempStep++;
					}
		} break;
		
		/* Fade out until 40% */
		case 3:
		{
					SpeedTime++;
					if (SpeedTime >= 6)
					{
						SpeedTime = 0;
						
						TempR	-= FadeR;
						TempG	-= FadeG;
						TempB	-= FadeB;
						All_Color(TempR, TempG, TempB);
						
						TempCnt++;
						if (TempCnt > 15)
						{
							TempCnt = 0;
							TempStep++;
							HoldTime = 0;
							for (TempCnt = 0; TempCnt < 30; TempCnt++)
							{
								ModeLed30[TempCnt] = 0;
							}
							
							for (TempCnt = 0; TempCnt < 10; TempCnt++)
							{
								ModeLed10[TempCnt] = 0;
							}
							
							for (TempCnt = 0; TempCnt < 24; TempCnt++)
							{
								ModeLed24[TempCnt] = 0;
							}
							
							for (TempCnt = 0; TempCnt < 40; TempCnt++)
							{
								ModeLed40[TempCnt] = 0;
							}
							
							for (TempCnt = 0; TempCnt < 30; TempCnt++)
							{
								ModeLeds30[TempCnt] = 0;
							}
							
							for (TempCnt = 0; TempCnt < 24; TempCnt++)
							{
								ModeLeds24[TempCnt] = 0;
							}
							
							for (TempCnt = 0; TempCnt < 36; TempCnt++)
							{
								ModeLeds36[TempCnt] = 0;
							}
							
							RndCnt10 = 0;
							RndCnt24 = 0;
							RndCnt30 = 0;
							RndCnts30 = 0;
							RndCnts24 = 0;
							RndCnts36 = 0;
							RndCnt40 = 0;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
							RndCntSpot = 0;
							RndCntBall = 0;
						}
					}
		} break;
		
		/* Turn off random */
		case 4:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						/* Icicle */
						if (RndCnt30 < 30)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 30;
							} while (ModeLed30[TempLed] == 1);
							ModeLed30[TempLed] = 1;
							
							Roof30[TempLed].DutyR	= 0;
							Roof30[TempLed].DutyG	= 0;
							Roof30[TempLed].DutyB	= 0;
							
							RndCnt30++;
						}
						
						if (RndCnt10 < 10)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 10;
							} while (ModeLed10[TempLed] == 1);
							ModeLed10[TempLed] = 1;
							
							Roof10[TempLed].DutyR	= 0;
							Roof10[TempLed].DutyG	= 0;
							Roof10[TempLed].DutyB	= 0;
							RndCnt10++;
						}
						
						if (RndCnt24 < 24)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 24;
							} while (ModeLed24[TempLed] == 1);
							ModeLed24[TempLed] = 1;
							
							Roof24[TempLed].DutyR	= 0;
							Roof24[TempLed].DutyG	= 0;
							Roof24[TempLed].DutyB	= 0;
							RndCnt24++;
						}
						
						if (RndCnt40 < 40)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 40;
							} while (ModeLed40[TempLed] == 1);
							ModeLed40[TempLed] = 1;
							
							Roof40[TempLed].DutyR	= 0;
							Roof40[TempLed].DutyG	= 0;
							Roof40[TempLed].DutyB	= 0;
							RndCnt40++;
						}
						
						if (RndCnts30 < 30)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 30;
							} while (ModeLeds30[TempLed] == 1);
							ModeLeds30[TempLed] = 1;
							
							String30[TempLed].DutyR	= 0;
							String30[TempLed].DutyG	= 0;
							String30[TempLed].DutyB	= 0;
							RndCnts30++;
						}
						
						if (RndCnts24 < 24)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 24;
							} while (ModeLeds24[TempLed] == 1);
							ModeLeds24[TempLed] = 1;
							
							String24[TempLed].DutyR	= 0;
							String24[TempLed].DutyG	= 0;
							String24[TempLed].DutyB	= 0;
							RndCnts24++;
						}
						
						if (RndCnts36 < 36)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 36;
							} while (ModeLeds36[TempLed] == 1);
							ModeLeds36[TempLed] = 1;
							
							String36[TempLed].DutyR	= 0;
							String36[TempLed].DutyG	= 0;
							String36[TempLed].DutyB	= 0;
							RndCnts36++;
						}
						
						/* Tree */
						if (RndCntTree < 12)
						{
							RndCntTree++;
							switch (RndCntTree)
							{
								case 1:			ModeLedTree[0] = 0;			ModeLedTree[1] = 1;	  	ModeLedTree[2] = 2;		 		break;
								case 2:			ModeLedTree[0] = 3;			ModeLedTree[1] = 4;	  	ModeLedTree[2] = 5;		 		break;
								case 3:			ModeLedTree[0] = 6;			ModeLedTree[1] = 7;	   														break;
								case 4:			ModeLedTree[2] = 8;		 																										break;
								case 5:			ModeLedTree[0] = 9;			ModeLedTree[1] = 10;	  ModeLedTree[2] = 11;		 	break;
								case 6:			ModeLedTree[0] = 12;		ModeLedTree[1] = 13;	  ModeLedTree[2] = 14;		 	break;
								case 7:			ModeLedTree[0] = 15;		ModeLedTree[1] = 16;	 														break;
								case 8:			ModeLedTree[2] = 17;		 																									break;
								case 9:			ModeLedTree[0] = 18;		ModeLedTree[1] = 19;	  ModeLedTree[2] = 20;		 	break;
								case 10:		ModeLedTree[0] = 21;		ModeLedTree[1] = 22;	  ModeLedTree[2] = 23;		 	break;
								case 11:		ModeLedTree[0] = 24;		ModeLedTree[1] = 25;	  													break;
								case 12:		ModeLedTree[2] = 26;		 																									break;
							}
							
							TempR = 0;
							TempG = 0;
							TempB = 0;
		
							Grd.Tree[ModeLedTree[0]].DutyR	= TempR;
							Grd.Tree[ModeLedTree[0]].DutyG	= TempG;
							Grd.Tree[ModeLedTree[0]].DutyB	= TempB;
							Grd.Tree[ModeLedTree[1]].DutyR	= TempR;
							Grd.Tree[ModeLedTree[1]].DutyG	= TempG;
							Grd.Tree[ModeLedTree[1]].DutyB	= TempB;
							Grd.Tree[ModeLedTree[2]].DutyR	= TempR;
							Grd.Tree[ModeLedTree[2]].DutyG	= TempG;
							Grd.Tree[ModeLedTree[2]].DutyB	= TempB;
						}
						
						/* Snow */
						if (RndCntSnow < 7)
						{
							RndCntSnow++;
							switch (RndCntSnow)
							{
								case 1:		ModeLedSnow[0] = 0;			ModeLedSnow[1] = 7;			 ModeLedSnow[2] = 14;	break;
								case 2:		ModeLedSnow[0] = 1;			ModeLedSnow[1] = 8;			 ModeLedSnow[2] = 15;	break;
								case 3:		ModeLedSnow[0] = 2;			ModeLedSnow[1] = 9;			 ModeLedSnow[2] = 16;	break;
								case 4:		ModeLedSnow[0] = 3;			ModeLedSnow[1] = 10;		 ModeLedSnow[2] = 17;	break;
								case 5:		ModeLedSnow[0] = 4;			ModeLedSnow[1] = 11;		 ModeLedSnow[2] = 18;	break;
								case 6:		ModeLedSnow[0] = 5;			ModeLedSnow[1] = 12;		 ModeLedSnow[2] = 19;	break;
								case 7:		ModeLedSnow[0] = 6;			ModeLedSnow[1] = 13;		 ModeLedSnow[2] = 20;	break;
							}
							
							Grd.Snow[ModeLedSnow[0]].DutyR	= 0;
							Grd.Snow[ModeLedSnow[0]].DutyG	= 0;
							Grd.Snow[ModeLedSnow[0]].DutyB	= 0;

							Grd.Snow[ModeLedSnow[1]].DutyR	= 0;
							Grd.Snow[ModeLedSnow[1]].DutyG	= 0;
							Grd.Snow[ModeLedSnow[1]].DutyB	= 0;
							
							Grd.Snow[ModeLedSnow[2]].DutyR	= 0;
							Grd.Snow[ModeLedSnow[2]].DutyG	= 0;
							Grd.Snow[ModeLedSnow[2]].DutyB	= 0;
						}
						
						/* Cane */
						if (RndCntCane < 6)
						{
							for (TempCnt = 0; TempCnt < 5; TempCnt++)
							{
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyR	= 0;
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyG	= 0;
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyB	= 0;
							}
							
							RndCntCane++;
						}
						
						/* Spot */
						if (RndCntSpot < 3)
						{
							Grd.Spot[RndCntSpot].DutyR	= 0;
							Grd.Spot[RndCntSpot].DutyG	= 0;
							Grd.Spot[RndCntSpot].DutyB	= 0;
							RndCntSpot++;
						}
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = 0;
							Grd.Ball[TempCnt].DutyG = 0;
							Grd.Ball[TempCnt].DutyB = 0;
						}
						
						if (RndCnt40 >= 40)
						{
							TempStep++;
						}
					}
		} break;
		
		default:				break;
	}
}







 
 
