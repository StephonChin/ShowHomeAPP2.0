/************************************************************
 	*
	* @File Name			LedDisplay.c
	* @Description		This file contains prototyped function for controllng the 
	*									Led mode
	*
*******************************************************************************/

/* Includes-------------------------------------------------------------------*/
#include "Led_Display.h"

/* Global Variables ----------------------------------------------------------*/
_Type_Display					DisplayData;
_Uint8  						ColorData[8][3];   				// color data


/* File Variables ------------------------------------------------------------*/
idata _Uint8					TempCnt;
idata _Uint8					TempLed;
idata _Uint8					TempColor;
idata _Uint8					LedCnt;
idata _Uint8					TempR;
idata _Uint8					TempG;
idata _Uint8					TempB;
idata _Uint8					FadeR;
idata _Uint8					FadeG;
idata _Uint8					FadeB;
idata _Uint8			        ModeTime[3];
idata _Uint8			        ModeStep[3];
idata _Uint8			        HoldTime[3];
idata _Uint8			        ModeColor[3];
idata _Uint8			        ModeLed[3];
idata _Uint8			        SpeedTime;
idata _Uint16			        RndSeed;
idata _Uint16			        ModeMicroSec;
idata _Uint8			        ShowMode;
idata _Flag				        ShowInit;
idata _Uint16			        TimeLine;


/**********************************************************
	*
 	* Function: Led_Display
 	* Author: Annncle.Chin
 	* Date: 2016.04.18
 	* Description: to select Circle or normal mode
 	*
********/
void Led_Display(void)
{
	switch (DisplayData.Mode)
	{
		case 0x0:			All_Off();							break;
		case 0x1:			Steady();							break;
		case 0x2:			Flash(FALSE);						break;
		case 0x3:			Fade(FALSE);						break;
		
		case 0xB:			Show_1();							break;
		case 0xC:			Show_2();							break;
		case 0xD:			Show_3();							break;
		
		case 0xFB:		    Blue_Flash();		                break;
		case 0xFD:		    Green_Flash();		                break;
		case 0xFF:		    Red_Flash();		                break;
		default:			
		{
                            DisplayData.ModeBuf = 0x1;
                            DisplayData.Mode	= 0x1;
		} break;
	}
}


/**
	* FunctionName	Blue_Flash
	*/
static void Blue_Flash(void)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		TempR = 0;
		TempG = 0;
		TempB = 0;
		DutyR = TempR;
		DutyG = TempG;
		DutyB = TempB;
		SpeedTime = 0;
		ModeStep[0] = 0;
		
		return;
	}
	
	/* Speed Control */
	if (SpeedTime < 4)
	{
		SpeedTime++;
		return;
	}
	SpeedTime = 0;
	
	/* Flash Three Times */
	if (ModeStep[0] % 2 == 0)		TempB = 255;
	else							TempB = 0;

	/* Restore the mode */
	ModeStep[0]++;
	if (ModeStep[0] > 5)
	{
		DisplayData.Mode 		= DisplayData.ModeBuf;
		DisplayData.InitFlag 	= TRUE;
	}
	
	/* Led Data Update */
	DutyR = TempR;
	DutyG = TempG;
	DutyB = TempB;
}

/**
	* FunctionName	Green_Flash
	*/
static void Green_Flash(void)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		TempR = 0;
		TempG = 0;
		TempB = 0;
		DutyR = TempR;
		DutyG = TempG;
		DutyB = TempB;
		SpeedTime = 0;
		ModeStep[0] = 0;
		
		return;
	}
	
	/* Speed Control */
	if (SpeedTime < 4)
	{
		SpeedTime++;
		return;
	}
	SpeedTime = 0;
	
	/* Flash Three Times */
	if (ModeStep[0] % 2 == 0)		TempG = 255;
	else							TempG = 0;

	/* Restore the mode */
	ModeStep[0]++;
	if (ModeStep[0] > 5)
	{
		DisplayData.Mode 		= DisplayData.ModeBuf;
		DisplayData.InitFlag 	= TRUE;
	}
	
	/* Led Data Update */
	DutyR = TempR;
	DutyG = TempG;
	DutyB = TempB;
}


/**
	* FunctionName	Red_Flash
	*/
static void Red_Flash(void)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		TempR = 0;
		TempG = 0;
		TempB = 0;
		DutyR = TempR;
		DutyG = TempG;
		DutyB = TempB;
		SpeedTime = 0;
		ModeStep[0] = 0;
		
		return;
	}
	
	/* Speed Control */
	if (SpeedTime < 4)
	{
		SpeedTime++;
		return;
	}
	SpeedTime = 0;
	
	/* Flash Three Times */
	if (ModeStep[0] % 2 == 0)		TempR = 255;
	else							TempR = 0;

	/* Restore the mode */
	ModeStep[0]++;
	if (ModeStep[0] > 5)
	{
		DisplayData.Mode 		= DisplayData.ModeBuf;
		DisplayData.InitFlag 	= TRUE;
	}
	
	/* Led Data Update */
	DutyR = TempR;
	DutyG = TempG;
	DutyB = TempB;
}

/************************************************************
	* 
	* All_Off
	*
*****/
static void All_Off(void)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag 	= FALSE;
		DutyR		= 0;
		DutyG		= 0;
		DutyB		= 0;
	}
}

/************************************************************
	* 
	* Steady
	*
*****/
static void Steady(void)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag 	= FALSE;
		DutyR		= ColorData[0][R];
		DutyG		= ColorData[0][G];
		DutyB		= ColorData[0][B];
	}
}



/**
	* FunctionName	Flash_Init
	*/
static void Flash_Init(void)
{
	DutyR 	= 0;
	DutyG		= 0;
	DutyB  	= 0;
	ModeTime[0] = 100;
	ModeTime[1] = 100;
	ModeTime[2] = 100;
}

/**
	* FunctionName	Fade_Init
	*/
static void Fade_Init(void)
{
	DutyR 	= 0;
	DutyG		= 0;
	DutyB  	= 0;
	ModeTime[0] = 0;
	ModeTime[1] = 0;
	ModeTime[2] = 0;
	ModeStep[0]	= 0;
	ModeStep[1] = 0;
	ModeStep[2] = 0;
}

/************************************************************
	* 
	* Flash
	*
*****/
static void Flash(_Flag AllFlag)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag	= FALSE;

		Flash_Init();
		return;
	}
	
	if (ColorData[0][R] == 100 || AllFlag == TRUE)
	{
		ModeTime[0]++;
		if (ModeTime[0] == 93)
		{	
			DutyR = 0;
		}
		else if (ModeTime[0] == 103)
		{
			DutyR = DUTY_MAX;
			ModeTime[0] = 0;
		}
	}

	if (ColorData[0][G] == 100 || AllFlag == TRUE)
	{
		ModeTime[1]++;
		if (ModeTime[1] == 103)
		{	
			DutyG = 0;
		}
		else if (ModeTime[1] == 119)
		{
			DutyG = DUTY_MAX;
			ModeTime[1] = 0;
		}
	}
	
	if (ColorData[0][B] == 100 || AllFlag == TRUE)
	{
		ModeTime[2]++;
		if (ModeTime[2] == 119)	
		{
			DutyB = 0;
		}
		else if (ModeTime[2] == 133)
		{
			DutyB = DUTY_MAX;
			ModeTime[2] = 0;
		}
	}
}



/**
	* FunctionName		Fade
	*/
static void Fade(_Flag AllFlag)
{
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag	= FALSE;
		
		Fade_Init();
		return;
	}
	
	
	if (ColorData[0][R] == 100 || AllFlag == TRUE)
	{
		ModeTime[0]++;
		if (ModeTime[0] >= 3)
		{	
			ModeTime[0] = 0;
			switch (ModeStep[0])
			{
				case 0:
				{
								if (DutyR < DUTY_MAX)		DutyR++;
								else										ModeStep[0]++;
				} break;
				
				default:
				{
							if (DutyR > DUTY_MIN)		DutyR--;
							else										ModeStep[0] = 0;
				} break;
			}
		}
	}
	
	if (ColorData[0][G] == 100 || AllFlag == TRUE)	
	{
		ModeTime[1]++;
		if (ModeTime[1] >= 4)
		{	
			ModeTime[1] = 0;
			switch (ModeStep[1])
			{
				case 0:
				{
								if (DutyG < DUTY_MAX)		DutyG++;
								else										ModeStep[1]++;
				} break;
				
				default:
				{
							if (DutyG> DUTY_MIN)		DutyG--;
							else										ModeStep[1] = 0;
				} break;
			}
		}
	}

	
	if (ColorData[0][B] == 100 || AllFlag == TRUE)
	{
		ModeTime[2]++;
		if (ModeTime[2] >= 5)
		{	
			ModeTime[2] = 0;
			switch (ModeStep[2])
			{
				case 0:
				{
								if (DutyB < DUTY_MAX)		DutyB++;
								else										ModeStep[2]++;
				} break;
				
				default:
				{
							if (DutyB > DUTY_MIN)		DutyB--;
							else										ModeStep[2] = 0;
				} break;
			}
		}
	}

}







/**
	* FunctionName	Show_1
	*/
static void Show_1(void)
{
	/* Initalize */
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		ShowMode = 0;
		
		TimeLine = 0;
		if (MotorData.Mode == 0)
		{
			MotorData.Mode 			= 1;
			MotorData.InitFlag		= TRUE;
		}
		DutyR	= 0;
		DutyG	= 0;
		DutyB = 0;
	}
	
	
	//music start
	else
	{
			TimeLine++;
			if (TimeLine == 1)									{ShowMode = 1;			ShowInit = TRUE;	}
			else if (TimeLine == 460)						{ShowMode = 2;			ShowInit = TRUE;	}
			else if (TimeLine == 2560)					{ShowMode = 3;			ShowInit = TRUE;	}
			else if (TimeLine == 3460)					{ShowMode = 4;			ShowInit = TRUE;	}
			else if (TimeLine == 4500)					
			{
				TimeLine = 0;			
				DisplayData.InitFlag = TRUE; 
			}

		
		
		/* Mode Control */
		switch (ShowMode)
		{
			case 0:
				All_Off();
			break;
			
			case 1:
				Show_1_1();
			break;
			
			case 2:
				Show_1_2();
			break;
			
			case 3:
				Show_1_3();
			break;
			
			case 4:
				Show_1_4();
			break;
		}
	}
}

/**
	* FunctionName		Show_1_1
	*/
static void Show_1_1(void)
{
	/* Initialize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;

		ModeMicroSec	= 0;
		Flash_Init();
		return;
	}
	
	/* -----------------Mode Start ---------------*/
	if (ModeMicroSec < 4950)
	{
		Flash(TRUE);;
	}
	
	else
	{
		DutyR = 0;
		DutyG = 0;
		DutyB	= 0;
	}
	
	//=============================================================
	// time control
	ModeMicroSec++;
}

/**
	* FunctionName		Show_1_2
	*/
static void Show_1_2(void)
{
	/* Initialize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		Fade_Init();
		
		ModeMicroSec	= 0;
		return;
	}
	
	/* Mode Start */
	if (ModeMicroSec < 1500)
	{
		Fade(TRUE);
	}
	
	else if (ModeMicroSec == 1500)
	{
		Flash_Init();
	}
	else if (ModeMicroSec < 3000)
	{
		Flash(TRUE);;
	}
	
	else if (ModeMicroSec == 3000)
	{
		SpeedTime = 0;
		TempColor = 0;
	}
	else if (ModeMicroSec < 4500)
	{
		SpeedTime++;
		if (SpeedTime > 50)
		{
			SpeedTime = 0;
			DutyR	= ColorData[TempColor][R];
			DutyG	= ColorData[TempColor][G];
			DutyB	= ColorData[TempColor][B];
			TempColor++;
			if (TempColor >= 7)		TempColor = 0;
		}
	}
	
	else if (ModeMicroSec == 4500)
	{
		Flash_Init();
	}
	else if (ModeMicroSec < 5000)
	{
		Flash(TRUE);;
	}
	else
	{
		TempR = 0;
		TempB = 0;
		TempG = 0;
	}
	
	ModeMicroSec++;
}

/**
	* FunctionName		Show_1_3
	*/
static void Show_1_3(void)
{
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		ModeMicroSec = 0;
		
		Flash_Init();
		return;
	}
	
	if (ModeMicroSec < 4450)
	{
		Flash(TRUE);;
	}
	
	else
	{
		DutyR = 0;
		DutyG = 0;
		DutyB = 0;
	}
	
	ModeMicroSec++;
}

/**
	* FunctionName		Show_1_4
	*/
static void Show_1_4(void)
{
	/* Initialize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		Fade_Init();
		
		ModeMicroSec = 0;
		return;
	}
	
	
	if (ModeMicroSec < 1000)
	{
		Fade(TRUE);
	}
	
	else if (ModeMicroSec == 1000)
	{
		ModeTime[0] = 0;
		TempColor 	= 0;
	}
	else if (ModeMicroSec < 1500)
	{
		ModeTime[0]++;
		if (ModeTime[0] > 200)
		{
			ModeTime[0] = 0;
			
			DutyR	= ColorData[TempColor][R];
			DutyG	= ColorData[TempColor][G];
			DutyB	= ColorData[TempColor][B];

			TempColor++;
			if (TempColor >= 7)
			{
				TempColor = 0;
			}
		}
	}
	
	else
	{
		ModeTime[0]++;
		if (ModeTime[0] >= 30)
		{
			ModeTime[0] = 0;
			
			DutyR	= ColorData[TempColor][R];
			DutyG	= ColorData[TempColor][G];
			DutyB	= ColorData[TempColor][B];

			TempColor++;
			if (TempColor >= 7)
			{
				TempColor = 0;
			}
		}
	}
	
	ModeMicroSec++;
}


















/***********************************************************************************************
 * Music_One
 */
void Show_2(void)
{
	// intialize
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		ShowMode = 0;
		//clear time parameters
		TimeLine = 0;
		if (MotorData.Mode == 0)
		{
			MotorData.Mode 			= 1;
			MotorData.InitFlag		= TRUE;
		}
	}
	
	
	//music start
	else
	{
			TimeLine++;
			if (TimeLine == 1)									{ShowMode = 1;			ShowInit = TRUE;	}
			else if (TimeLine == 1640)					{ShowMode = 2;			ShowInit = TRUE;	}
			else if (TimeLine == 3410)					{ShowMode = 3;			ShowInit = TRUE;	}
			else if (TimeLine == 3950)					{ShowMode = 4;			ShowInit = TRUE;	}
			else if (TimeLine == 5010)					{ShowMode = 4;			ShowInit = TRUE;	}
			else if (TimeLine == 7000)					
			{
				TimeLine = 0;			
				DisplayData.InitFlag = TRUE; 
			}
		

		/* Mode Control */
		switch (ShowMode)
		{
			case 0:
				All_Off();
			break;
			
			case 1:
				Show_2_1();
			break;
			
			case 2:
				Show_2_2();
			break;
			
			case 3:
				Show_2_3();
			break;
			
			case 4:
				Show_2_4();
			break;
		}
		
	} // else --- music start
}


/****************************************************************************************************************
 * Prelude
 */
static void Show_2_1(void)
{
    /* Initialize*/
    if (ShowInit == TRUE)
    {
		/* clear flag */
    	ShowInit = FALSE;
		
		/* turn off */
    	DutyR 	= 0;
    	DutyG 	= 0;
    	DutyB 	= 0;
		
		/* clear parameters */
    	ModeMicroSec 	= 0;
    	ModeTime[0] 	= 0;
		
		
		/* get the fade value */
    	FadeR 	= ColorData[0][R] / FADE_LEVEL;
    	FadeG 	= ColorData[0][G] / FADE_LEVEL;
    	FadeB 	= ColorData[0][B] / FADE_LEVEL;
    }

    /* mode start */
    else
    {
    	ModeTime[0]++;
    	if ( ModeTime[0] > 	20)
    	{
    		ModeTime[0] = 0;
			
    		if ( 	(DutyR < ColorData[0][R])
				||	(DutyG < ColorData[0][G])
				||	(DutyB < ColorData[0][B])
				)
    		{
	    		DutyR 	+= FadeR;
	    		DutyG 	+= FadeG;
	    		DutyB 	+= FadeB;
	    	}
    	}
    }
}



/******************************************************************************************************************
 * Interlude
 */
static void Show_2_2(void)
{
	/* Initialize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
			
		ModeStep[0] 	= 0;
		ModeTime[0] 	= 0;
		ModeColor[0] 	= 0;
		
		ModeMicroSec = 0;
		
		FadeR 	= ColorData[0][R] / FADE_LEVEL;
		FadeG 	= ColorData[0][G] / FADE_LEVEL;
		FadeB 	= ColorData[0][B] / FADE_LEVEL;
	}

	/* 模式开始 */
	else
	{
		//=============================================================
		// fade in
		if ( ModeMicroSec < 200)
		{
			ModeTime[0]++;
			if ( ModeTime[0] > 	20)
			{
				ModeTime[0] = 0;
	
				if ( 	(DutyR < ColorData[0][R])
					||	(DutyG < ColorData[0][G])
					||	(DutyB < ColorData[0][B])
					)
				{
					DutyR 	+= FadeR;
					DutyG 	+= FadeG;
					DutyB 	+= FadeB;
				}
			}
		}

		//==============================================================
		// instead
		else if (ModeMicroSec == 200)
		{
			ModeTime[0] = 0;
			LedCnt 			= 0;
			TempColor 	= 0;
			HoldTime[0]	= 0;
		}
		else
		if (ModeMicroSec < 2200)
		{
			ModeTime[0]++;
			if (ModeTime[0] > 10) 
			{
				ModeTime[0] = 0;
				HoldTime[0]++;
				if (HoldTime[0] == 1)
				{
					DutyR = ColorData[TempColor][R];
					DutyG = ColorData[TempColor][G];
					DutyB = ColorData[TempColor][B];
				}
				else if (HoldTime[0] > 50)
				{
					HoldTime[0] = 0;
					TempColor++;
					if (TempColor >= 7)	TempColor = 0;
				}	
			}
		}


		//============================================================
		// fade out
		else
		if (ModeMicroSec == 2200)
		{
			ModeTime[0] = 0;
			DutyR 	= ColorData[TempColor][R];
			DutyG 	= ColorData[TempColor][G];
			DutyB 	= ColorData[TempColor][B];
			
			FadeR 	= DutyR / FADE_LEVEL;
			FadeG 	= DutyG / FADE_LEVEL;
			FadeB 	= DutyB / FADE_LEVEL;
		}
		else
		{
			ModeTime[0]++;
			if (ModeTime[0] > 3)
			{
				ModeTime[0] = 0;

				if (	(DutyB > 0)
					||	(DutyR > 0)
					|| 	(DutyG > 0)
					)
				{
					DutyR		-= FadeR;
					DutyG	-= FadeG;
					DutyB	-= FadeB;
				}
			}
		}

		//=============================================================
		// time control
		ModeMicroSec++;
	} /* 模式结束  */
}




/******************************************************************************************************************
 * Climax
 */
static void Show_2_3(void)
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// initialize
	if (ShowInit == TRUE)
	{
		//clear flag
		ShowInit = FALSE;

		//parameters
		ModeMicroSec 	= 0;
		ModeTime[0] 	= 0;
		ModeStep[0] 	= 0;
		ModeColor[0] 	= 0;

		FadeR 	= ColorData[0][R] / FADE_LEVEL;
		FadeG 	= ColorData[0][G] / FADE_LEVEL;
		FadeB 	= ColorData[0][B] / FADE_LEVEL;
	} // if --- initialize



	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// mode start
	else
	{
		//=============================================================
		// PART - I
		if (ModeMicroSec < 500)
		{
			//all change to white
			if (ModeMicroSec  > 449)
			{
					DutyR	= ColorData[6][R];
					DutyG	= ColorData[6][G];
					DutyB	= ColorData[6][B];
			} // PART - 1

			else
			{
				// color change  one
				if ( (ModeMicroSec % 40) == 0)
				{
					DutyR		= ColorData[ModeColor[0]][R];
					DutyG	= ColorData[ModeColor[0]][G];
					DutyB	= ColorData[ModeColor[0]][B];

					ModeColor[0]++;
					if (ModeColor[0] >= 7)
					{
						ModeColor[0] = 0;
					}
				}
			}
		}

		//==================================================================================
		// PART - II
		else
		if (ModeMicroSec < 1500)
		{
			Flash(TRUE);;
		}



		//========================================================================================
		// PART - III
		// shining initialize
		else
		if (ModeMicroSec == 1500)
		{
			ModeStep[0] = 0;
			ModeTime[0] = 0;

			FadeR 	= ColorData[6][R] / FADE_LEVEL;
			FadeG 	= ColorData[6][G] / FADE_LEVEL;
			FadeB 	= ColorData[6][B] / FADE_LEVEL;
		}

		//shining
		else
		if (ModeMicroSec < 3800)
		{
			switch (ModeStep[0])
            {
                case 0:
                case 2:
                case 4:
                case 6:
                case 8:
                {
                    DutyR 	+= FadeR;
                    DutyG 	+= FadeG;
                    DutyB 	+= FadeB;

                    if ( 	(DutyR == (FadeR * 50)) 
													&& (DutyG == (FadeG * 50)) 
													&& (DutyB == (FadeB * 50)) 
												)
                    {
                        ModeStep[0]++;
                        srand(RndSeed);
                        TempR = (_Uint8)(rand() % 20) + 5;
                    }
                } break;

                case 1:
                case 3:
                case 5:
                case 7:
                {
                    DutyR 	-= FadeR;
                    DutyG 	-= FadeG;
                    DutyB 	-= FadeB;

                    if (    (DutyR == (FadeR * TempR)) 
                         && (DutyG == (FadeG * TempR)) 
                         && (DutyB == (FadeB * TempR)) 
                       )
                    {
                        ModeStep[0]++;
                    }
                } break;

                case 9:
                {
                    DutyR 	-= FadeR;
                    DutyG 	-= FadeG;
                    DutyB 	-= FadeB;

                    if ( 			(DutyR == (FadeR * 0)) 
													&& 	(DutyG == (FadeG * 0)) 
													&& 	(DutyB == (FadeB * 0)) 
												)
                    {
                        ModeStep[0] = 0;
                    }
                } break;
            }
		}

		//=============================================================
		// last - fade out
		else
		if ( ModeMicroSec < 4100)
		{
			ModeTime[0]++;
			if (ModeTime[0] > 4)
			{
				ModeTime[0] = 0;

				if ( DutyR > 0)		DutyR		-= FadeR;
				if ( DutyG > 0)		DutyR		-= FadeG;
				if ( DutyB > 0)		DutyR		-= FadeB;
			}
		}


		//=============================================================
		// time control
		ModeMicroSec++;
	} /* 模式退出 */
} 



/******************************************************************************************************************
 * Coda
 */
static void Show_2_4(void)
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// initialize
	if (ShowInit == TRUE)
	{
		//clear flag
		ShowInit = FALSE;


		// led initialize
		DutyR		= 0;
		DutyG	= 0;
		DutyB	= 0;

		FadeR	= ColorData[0][R] / FADE_LEVEL;
		FadeG	= ColorData[0][G] / FADE_LEVEL;
		FadeB	= ColorData[0][B] / FADE_LEVEL;

		//parameters
		ModeMicroSec 	= 0;
		ModeTime[0] 	= 0;
		ModeColor[0] 	= 0;


	} // if --- initialize



	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// mode start
	else
	{
		//=============================================================
		// PART-I
		// fade in 
		if (ModeMicroSec < 1200)
		{
			ModeTime[0]++;
			if (ModeTime[0] > 30)
			{
				ModeTime[0] = 0;
				if ( 	(DutyR < ColorData[1][R])
					||	(DutyG < ColorData[1][G])
					||	(DutyB < ColorData[1][B])
					)
				{
					DutyR		+= FadeR;
					DutyG 	+= FadeG;
					DutyB 	+= FadeB;
				}
			}
		} // PART -I



		//===================================================================================
		// PART - II
		// 515

		// initialize
		else
		if (ModeMicroSec == 1300)
		{
			ModeColor[0] 	= 0;
			ModeStep[0]		= 0;
			ModeTime[0]		= 0;
		}
		else
		if (ModeMicroSec < 4500)
		{
			ModeTime[0]++;
			if (ModeTime[0] > 3)
			{
				ModeTime[0] = 0;

				switch (ModeStep[0])
				{
					case 0:
					{
						if ( 	(DutyR < ColorData[ModeColor[0]][R]) 
							|| 	(DutyG < ColorData[ModeColor[0]][G]) 
							|| 	(DutyB < ColorData[ModeColor[0]][B]) 
							)
						{
							DutyR	+= FadeR;
							DutyG	+= FadeG;
							DutyB	+= FadeB;
						}
						else
						{
							ModeStep[0]++;
						}
					} break;


					case 1:
					{
						ModeTime[1]++;
						DutyR 	= 0;
						DutyG 	= 0;
						DutyB 	= 0;
						
						if (ModeTime[1] > 10)
						{
							ModeTime[1] = 0;
							ModeStep[0] = 0;

							DutyR 	= 0;
							DutyG 	= 0;
							DutyB 	= 0;

							ModeColor[0]++;
							if (ModeColor[0] >= 7)
							{
								ModeColor[0] = 0;
							}

							FadeR 	= ColorData[ModeColor[0]][R] / FADE_LEVEL;
							FadeG 	= ColorData[ModeColor[0]][G] / FADE_LEVEL;
							FadeB 	= ColorData[ModeColor[0]][B] / FADE_LEVEL;
						}
					} break;
				}
			}
		} // PART - II



		//==============================================================
		// PART - III
		// turn to white
		else if (ModeMicroSec < 7600)
		{
			TempR = ColorData[6][R];
			TempG = ColorData[6][G];
			TempB = ColorData[6][B];
		}
		
		
		
		//--------------------------------------------------------------
		// END - Turn Off
		//--------------------------------------------------------------
		else if (ModeMicroSec == 7600)
		{
			DutyR	= ColorData[6][R];
			DutyG = ColorData[6][G];
			DutyB = ColorData[6][B];
		}
		else
		{
			if (DutyR > 0)		DutyR--;
			if (DutyG > 0)		DutyG--;
			if (DutyB > 0)		DutyB--;
		}

		//=============================================================
		// time control
		ModeMicroSec++;
	}
}








/***********************************************************************************************
 * Music_One
 */
void Show_3(void)
{
	// intialize
	if (DisplayData.InitFlag == TRUE)
	{
		DisplayData.InitFlag = FALSE;
		ShowMode = 0;
		//clear time parameters
		TimeLine = 0;
		
		if (MotorData.Mode == 0)
		{
			MotorData.Mode 			= 1;
			MotorData.InitFlag		= TRUE;
		}
	}
	
	
	//music start
	else
	{
		TimeLine++;
		if (TimeLine == 1)									{ShowMode = 1;			ShowInit = TRUE;	}
		else if (TimeLine == 2660)					{ShowMode = 2;			ShowInit = TRUE;	}
		else if (TimeLine == 5350)					{ShowMode = 3;			ShowInit = TRUE;	}
		else if (TimeLine == 5700)					{ShowMode = 4;			ShowInit = TRUE;	}
		else if (TimeLine == 6605)					{ShowMode = 4;			ShowInit = TRUE;	}
		else if (TimeLine == 8000)					
		{
			TimeLine = 0;			
			DisplayData.InitFlag = TRUE; 
		}
		
		/* Mode Control */
		switch (ShowMode)
		{
			case 0:
				All_Off();
			break;
			
			case 1:
				Show_3_1();
			break;
			
			case 2:
				Show_3_2();
			break;
			
			case 3:
				Show_3_3();
			break;
			
			case 4:
				Show_3_4();
			break;
		}
		
	} // else --- music start
}



/****************************************************************************************************************
 * Prelude
 */
static void Show_3_1(void)
{
    // initialize
    if (ShowInit == TRUE)
    {
			//clear flag
			ShowInit = FALSE;
		
			DutyR    = 0;
			DutyG  	= 0;
			DutyB   = 0;
	
			// prarametes
			ModeMicroSec	= 0;
			ModeColor[0]	= 0;
			ModeTime[0]	  = 0;
			LedCnt			  = 0;
			TempColor 		= 0;
			ModeStep[0]		= 0;
			HoldTime[0]		= 6;

			ModeColor[2]	 = 0;
		
		
    } // if --- initialize


    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Prelude
    else
    {
    	if (ModeMicroSec < 1500)
	    	{
	    		ModeTime[0]++;
					if (ModeTime[0] > HoldTime[0])
					{
						ModeTime[0] = 0;
						
						switch (ModeStep[0])
						{
							case 0:
							{
								DutyR = ColorData[TempColor][R];
								DutyG = ColorData[TempColor][G];
								DutyB = ColorData[TempColor][B];
								
								FadeR = ColorData[TempColor][R] / FADE_LEVEL;
								FadeG = ColorData[TempColor][G] / FADE_LEVEL;
								FadeB = ColorData[TempColor][B] / FADE_LEVEL;
								ModeStep[0]++;
							} break;
							
							case 1:
							{
								if (DutyR > 0 || DutyG > 0 || DutyB > 0)
								{
									DutyR -= FadeR;
									DutyG -= FadeG;
									DutyB -= FadeB;
								}
								else
								{
									ModeStep[0] = 0;
									TempColor++;
									if (TempColor >= 7)		TempColor = 0;
								}
							} break;
						}
					}

	    	} // PART - I



    	//=============================================================
    	// PART -III
    	// initizlize
    	else
    	if (ModeMicroSec == 1500)
    	{
				ModeTime[0]	 = 0;
				DutyR		= DUTY_MAX;
				DutyG		= DUTY_MAX;
				DutyB		= DUTY_MAX;
				FadeR		= DutyR / FADE_LEVEL;
				FadeG 	= DutyG / FADE_LEVEL;
				FadeB 	= DutyB / FADE_LEVEL;
    	}


    	else
    	if (ModeMicroSec < 2000)
    	{
    		ModeTime[0]++;
			if (ModeTime[0] > 9)
			{
				ModeTime[0] = 0;

				if ( 	(DutyR > 0)
					 ||	(DutyG > 0)
					 || (DutyB > 0)
					)
				{
					DutyR 	-= FadeR;
					DutyG 	-= FadeG;
					DutyB 	-= FadeB;
				}
    		}
    	}
    	//=============================================================
		// time control
		ModeMicroSec++;
    }
}



/******************************************************************************************************************
 * Interlude
 */
static void Show_3_2(void)
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// initialize
	if (ShowInit == TRUE)
	{
		//clear flag
		ShowInit = FALSE;

		DutyR	= 0;
		DutyG	= 0;
		DutyB	= 0;


		//parameters
		ModeMicroSec 	= 0;
		ModeColor[0] 	= 0;
		ModeStep[0] 	= 0;
		ModeTime[0] 	= 0;


		// fade
		FadeR	= ColorData[0][R] / FADE_LEVEL;
		FadeG	= ColorData[0][G] / FADE_LEVEL;
		FadeB	= ColorData[0][B] / FADE_LEVEL;

	} // if --- initialize



	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// mode start
	else
	{
		//===========================================================
		// PART - I
		// fade & color change
		if (ModeMicroSec < 2000)
		{
			ModeTime[0]++;
			if (ModeTime[0] > 2)
			{
				ModeTime[0] = 0;
				switch (ModeStep[0])
				{
					case 1:
					{
						if ( 	(DutyR > 0) 
							|| (DutyG > 0) 
							|| (DutyB > 0) 
							)
						{
							DutyR		-= FadeR;
							DutyG	-= FadeG;
							DutyB	-= FadeB;
						}

						else
						{
							ModeStep[0] = 0;
							ModeColor[0]++;
							if (ModeColor[0] > 5)
							{
								ModeColor[0] = 6;
							}
							
							FadeR	= ColorData[ModeColor[0]][R] / FADE_LEVEL;
							FadeG	= ColorData[ModeColor[0]][G] / FADE_LEVEL;
							FadeB	= ColorData[ModeColor[0]][B] / FADE_LEVEL;
						}
					} break;
					
					case 0:
					{
						if (	(DutyR < ColorData[ModeColor[0]][R]) 
							|| 	(DutyG < ColorData[ModeColor[0]][G]) 
							|| 	(DutyB < ColorData[ModeColor[0]][B]) 
							)
						{
							DutyR		+= FadeR;
							DutyG		+= FadeG;
							DutyB		+= FadeB;
						}
						
						else
						{
							if (ModeColor[0] < 6)
							{
								ModeStep[0]++;
							}
						}
					} break;
				}
			}
		}



		//=============================================================
		// FADE -II
		// flash

		// intialize
		else
		if (ModeMicroSec == 2000)
		{
			ModeTime[0] = 0;
			ModeStep[0] = 0;
			FadeR		= ColorData[6][R] / FADE_LEVEL;
			FadeG		= ColorData[6][G] / FADE_LEVEL;
			FadeB		= ColorData[6][B] / FADE_LEVEL;
		}
		else
		if (ModeMicroSec < 2500)
		{
			ModeTime[0]++;

			// turn off
			if (ModeTime[0] > 30)
			{
				ModeTime[0] = 0;

	            switch (ModeStep[0])
	            {
	                case 0:
	                {
	                    DutyR 	= FadeR * FADE_LEVEL;
	                    DutyG 	= FadeG * FADE_LEVEL;
	                    DutyB 	= FadeB * FADE_LEVEL;

											ModeStep[0]++;
											srand(RndSeed);
											RndSeed += 17;
											TempR = (_Uint8)(rand() % 20) + 5;
	                } break;

	                case 1:
	                {
	                    DutyR 	= FadeR * TempR;
	                    DutyG 	= FadeG * TempR; 
	                    DutyB 	= FadeB * TempR;

											ModeStep[0] = 0;
	                } break;
	            }
			}
		}



		//============================================================
		// fade out
		else
		if (ModeMicroSec == 2500)
		{
			ModeTime[0] = 0;
			DutyR	= ColorData[6][R];
			DutyG	= ColorData[6][G];
			DutyB	= ColorData[6][B];
			FadeR = DutyR / FADE_LEVEL;
			FadeG = DutyG / FADE_LEVEL;
			FadeB = DutyB / FADE_LEVEL;
		}
		else
		{
			ModeTime[0]++;
			if (ModeTime[0] > 7)
			{
				ModeTime[0] = 0;

				if ( (DutyR > 0) || (DutyG > 0) || (DutyB > 0) )
				{
					DutyR	-= FadeR;
					DutyG	-= FadeG;
					DutyB	-= FadeB;
				}
			}
		}




		//=============================================================
		// time control
		ModeMicroSec++;
	} //else -- mode start
}




/******************************************************************************************************************
 * Climax
 */
static void Show_3_3(void)
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// initialize
	if (ShowInit == TRUE)
	{
		//clear flag
		ShowInit = FALSE;


		// led initialize
		DutyR	= ColorData[6][R];
		DutyG	= ColorData[6][G];
		DutyB	= ColorData[6][B];
		FadeR = DutyR / FADE_LEVEL;
		FadeG = DutyG / FADE_LEVEL;
		FadeB = DutyB / FADE_LEVEL;


		//parameters
		ModeMicroSec 	= 0;
		ModeColor[0] 	= 0;
		ModeStep[0] 	= 0;
		ModeTime[0] 	= 0;
	} // if --- initialize



	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// mode start
	else
	{
		//==================================================================================
		// PART - II
		// sparkle
		if (ModeMicroSec < 1000)
		{
			ModeTime[0]++;
			if (ModeTime[0] > 30)
			{
					ModeTime[0] = 0;

					ModeColor[0]++;
					if (ModeColor[0] >= 7)
					{
							ModeColor[0] = 0;
					}

					DutyR   = ColorData[ModeColor[0]][R];
					DutyG   = ColorData[ModeColor[0]][G];
					DutyB   = ColorData[ModeColor[0]][B];
			}
		}



		//========================================================================================
		// PART - III
		// rolling
		else
		if (ModeMicroSec == 1000)
		{
			Flash_Init();
		}
		else
		if (ModeMicroSec < 3000)
		{
			Flash(TRUE);;
		}

		//=============================================================
		// time control
		ModeMicroSec++;

	} //else -- mode start
}



/******************************************************************************************************************
 * Coda
 */
static void Show_3_4(void)
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// initialize
	if (ShowInit == TRUE)
	{
		//clear flag
		ShowInit = FALSE;


		// led initialize
		DutyR	= 0;
		DutyG	= 0;
		DutyB	= 0;


		FadeR	= ColorData[0][R] / FADE_LEVEL;
		FadeG	= ColorData[0][G] /FADE_LEVEL;
		FadeB	= ColorData[0][B] /FADE_LEVEL;

		//parameters
		ModeMicroSec = 0;
		ModeTime[0] = 0;
		ModeStep[0] = 0;
		ModeColor[0]  = 0;

		Fade_Init();
	} // if --- initialize



	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// mode start
	else
	{
		//=============================================================
		// PART-I
		// fade in one by one
		if (ModeMicroSec < 1000)
		{
			Fade(TRUE);
		} // PART -I



		//===================================================================================
		// PART - II
		// COLOR 

		// initialize
		else
		if (ModeMicroSec == 1000)
		{
			ModeColor[0] = 0;

			DutyR	 = ColorData[0][R];
			DutyG	= ColorData[0][G];
			DutyB	= ColorData[0][B];

			ModeTime[0] = 0;

		}
		else
		if (ModeMicroSec < 3000)
		{
			ModeTime[0]++;
			if (ModeTime[0] > 60)
			{
				ModeTime[0] = 0;

				ModeColor[0]++;
				if (ModeColor[0] >= 7)
				{
					ModeColor[0] = 0;
				}

				DutyR		= ColorData[ModeColor[0]][R];
				DutyG	= ColorData[ModeColor[0]][G];
				DutyB	= ColorData[ModeColor[0]][B];
			}			
		} // PART - II



		//==================================================================
		// PART -III
		//initialize
		else
		if (ModeMicroSec == 3000)
		{
			TempColor = 0;
			DutyR	= 0;
			DutyG	= 0;
			DutyB	= 0;
			
			FadeR				= ColorData[TempColor][R] / FADE_LEVEL;
			FadeG				= ColorData[TempColor][G] / FADE_LEVEL;
			FadeB				= ColorData[TempColor][B] / FADE_LEVEL;
			ModeStep[0] = 0;
			ModeTime[0] = 0;
			
			SpeedTime = 0;
			LedCnt		= 0;
		}


		else
		if (ModeMicroSec < 4500)
		{
			SpeedTime++;
			if (SpeedTime > 5)
			{
				SpeedTime = 0;
				
				switch (ModeStep[0])
				{
					case 0:
					{
						if (		(DutyR < ColorData[TempColor][R] / 2)
									||(DutyG < ColorData[TempColor][G] / 2)
									||(DutyB < ColorData[TempColor][B] / 2)
						)
						{
							DutyR		+= FadeR;
							DutyG		+= FadeG;
							DutyB		+= FadeB;
						}
						else
						{
							ModeStep[0]++;
						}
					} break;
					
					case 1:
					{
						DutyR	= ColorData[TempColor][R];
						DutyG	= ColorData[TempColor][G];
						DutyB	= ColorData[TempColor][B];
						ModeStep[0]++;
					} break;
					
					
					default:
					{
						if
						(
								(DutyR > 0)
							||(DutyG > 0)
							||(DutyB > 0)
						)
						{
							DutyR		-= FadeR;
							DutyG		-= FadeG;
							DutyB		-= FadeB;
						}
						else
						{
							ModeStep[0] = 0;
							TempColor++;
							if(TempColor >= 7)			TempColor = 0;
							FadeR				= ColorData[TempColor][R] / FADE_LEVEL;
							FadeG				= ColorData[TempColor][G] / FADE_LEVEL;
							FadeB				= ColorData[TempColor][B] / FADE_LEVEL;
							ModeStep[0] = 0;
						}
					} break;
				}
			}
		}

		//==============================================================
		// PART - III
		// turn to white
		else
		if (ModeMicroSec < 4500)
		{
			Flash(TRUE);;
		} // PART - II



		//==============================================================
		// PART - III
		// turn to white
		else
		{
			Fade(TRUE);
		}
		

		//=============================================================
		// time control
		ModeMicroSec++;
	} //else -- mode start
}




