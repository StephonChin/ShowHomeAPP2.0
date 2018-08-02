/**********************************************************************
	*
	* @FileName		Led_Display.c
	*
***********************************************************************/
#include "Led_Display.h"


/*	@Gloable Variables */
_TypeStructLed	LedData;
_Uint8				* Color[6];
_Uint8     			RedDuty[3];
_Uint8     			GreenDuty[3];
_Uint8     			BlueDuty[3];
_Uint8     			WhiteDuty[3];

/* @File variables */
_Uint8      		ModeTime[6];
_Uint8      		ModeStep[6];
_Uint8      		EachTime[6];
_Uint8					CircleTime[2];
_Sint16					RndSeed;
_Uint8					TargetDuty;


/********************************************************************************
 * FunctionName: Led_Duty_Control
 */
void Led_Duty_Control(void) interrupt 1
{
	static _Uint8			DutyCnt;
	
	TF0 = RESET;
	
	//led control
  DutyCnt++;
  if (DutyCnt > 99) 			DutyCnt = 0;
	
  //RED 1
  if (DutyCnt < RedDuty[0])        	PORT_R_1 = LED_ON;
  else															PORT_R_1 = LED_OFF;
    
	//RED 2
	if (DutyCnt < RedDuty[1])					PORT_R_2 = LED_ON;
	else															PORT_R_2 = LED_OFF;
    
  //RED 3
  if (DutyCnt < RedDuty[2])					PORT_R_3 = LED_ON;
  else															PORT_R_3 = LED_OFF;
    
  //GREEN 1
  if (DutyCnt < GreenDuty[0])				PORT_G_1 = LED_ON;
	else															PORT_G_1 = LED_OFF;
    
	//GREEN 2
	if (DutyCnt < GreenDuty[1])				PORT_G_2 = LED_ON;
	else															PORT_G_2 = LED_OFF;
    
	//GREEN 3
	if (DutyCnt < GreenDuty[2])				PORT_G_3 = LED_ON;
	else															PORT_G_3 = LED_OFF;
    
   //BLUE 1
   if (DutyCnt < BlueDuty[0])				PORT_B_1 = LED_ON;
   else 														PORT_B_1 = LED_OFF;
    
	//BLUE 2
	if (DutyCnt < BlueDuty[1])				PORT_B_2 = LED_ON;
	else															PORT_B_2 = LED_OFF;
	
	//BLUE 3
	if (DutyCnt < BlueDuty[2])				PORT_B_3 = LED_ON;
	else															PORT_B_3 = LED_OFF;

	
	//WHITE 1
	if (DutyCnt < WhiteDuty[0])				PORT_W_1 = LED_ON;
	else															PORT_W_1 = LED_OFF;

	//WHITE 2
	if (DutyCnt < WhiteDuty[1])				PORT_W_2 = LED_ON;
	else															PORT_W_2 = LED_OFF;
	
	//WHITE 3
	if (DutyCnt < WhiteDuty[2])				PORT_W_3 = LED_ON;
	else															PORT_W_3 = LED_OFF;
}

/********************************************************************************
	*
	* @ FunctionName: Led_Display_Control
	*
*****/
void Led_Display_Control(void)
{
    Normal_Mode(LedData.Mode);
}

/*********************************************************************************
	*
	* @ FunctionName: Normal_Mode
	*
*****/
static void Normal_Mode(_Uint8 ModeValBuf)
{
	/* The mode is warning for timer */
	if (LedData.WarningFlag == TRUE)
	{
		Warning_Mode();
		return;
	}
	
	RndSeed++;
	
	switch (ModeValBuf)
	{
			case 0x0:         Power_Off();													break;			/* power off 			*/
			case 0x1:		 			Steady(); 														break;			/* steady 				*/
			case 0x2:					Flash(SPARKLE_TIME, SPARKLE_BASIC);		break;			/* flash fast			*/
			case 0x3:					Flash(GLIMMER_TIME, GLIMMER_BASIC);		break;			/* flash slowly   */		
			case 0x4:			 		Fade();																break;			/* fade           */
			case 0x5:					Twinkle();														break;			/* twinkle        */
			case 0x6:					Fire();																break;			/* fire           */
			case 0x7:					Night();															break;			/* night          */
			default:					Circle();									break;			/* circle         */		
	}
}


/**********************************************************************************************
	*
	* @FunctionName		All_Off
	* @Description		Turn all the LEDs
	*
*****/
static void All_Off(void)
{
	_Uint8	TempCnt = 0;
	
	for (TempCnt = 0; TempCnt < 3; TempCnt++)
	{
		RedDuty[TempCnt]    = 0;
		GreenDuty[TempCnt]  = 0;
		BlueDuty[TempCnt]   = 0;
		WhiteDuty[TempCnt] 	= 0;
	}
}


/**********************************************************************************************
	*
	* @FunctionName		Warning_Mode
	* @Description		Turn all the LEDs
	*
*****/
static void Warning_Mode(void)
{
	_Uint8	TempCnt = 0;
	
	if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag 	= FALSE;
		ModeTime[0]				= 0x0;
		ModeStep[0]				= 0x0;
		return;
	}
	
	ModeTime[0]++;
	if (ModeTime[0] >= 15)
	{
		ModeTime[0]		= 0;
		ModeStep[0]++;
	}
	
	switch (ModeStep[0])
	{
		case 0:
		case 2:
		{
			for (TempCnt = 0; TempCnt < 3; TempCnt++)
			{
				RedDuty[TempCnt]    = 0;
				GreenDuty[TempCnt]  = 0;
				BlueDuty[TempCnt]   = 0;
				WhiteDuty[TempCnt] 	= 0;
			}
		} break;
		
		case 1:
		case 3:
		{
			for (TempCnt = 0; TempCnt < 3; TempCnt++)
			{
				RedDuty[TempCnt]    = 100;
				GreenDuty[TempCnt]  = 100;
				BlueDuty[TempCnt]   = 100;
				WhiteDuty[TempCnt] 	= 100;
			}
		} break;
		
		case 4:
		{
			for (TempCnt = 0; TempCnt < 3; TempCnt++)
			{
				RedDuty[TempCnt]    = 0;
				GreenDuty[TempCnt]  = 0;
				BlueDuty[TempCnt]   = 0;
				WhiteDuty[TempCnt] 	= 0;
			}
			
			LedData.WarningFlag		= FALSE;
			LedData.InitFlag			= TRUE;
		} break;
	}
}


/*********************************************************************************
 * Function: Power_Off
 */
static void Power_Off(void)
{
	if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag	= FALSE;	
		All_Off();
	}
}




/***********************************************************************************
 * Function: Steady
 */
static void Steady(void)
{
  _Uint8  TempCnt = 0;
    
	/* Mode initialize */
	if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag	= FALSE;	
    All_Off();
        
		/* Get value */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] != NULL)				*(Color[TempCnt]) = DUTY_MAX;
    }
  }
}

/***********************************************************************************
 * Function: Flash
 */
static void Flash(_Uint8 FlashSpeed, _Uint8	FlashBasic)
{
	_Uint8  TempCnt = 0;
	static _Uint8		FlashConst;
	
	if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag	= FALSE;	
		All_Off();
			
		/* initialize the time & step */
		ModeTime[0] = FlashSpeed;
		ModeTime[1] = 0;
		ModeStep[0] = 0;
		FlashConst	= 0;
			
		/* initialize the pointer */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] != NULL)			*(Color[TempCnt]) = DUTY_MAX;
		}
		
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			srand(RndSeed++);
			ModeStep[TempCnt]	= ((_Uint8)rand()) % FlashSpeed + FlashBasic;
		}
	}
	
	/* mode start */
	else
	{
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] == NULL)		continue;
			
			if (ModeTime[TempCnt]++ > ModeStep[TempCnt])
			{
				ModeTime[TempCnt] = 0;
				ModeStep[TempCnt]	= ((_Uint8)rand()) % FlashSpeed + FlashBasic;
				*(Color[TempCnt])	= DUTY_MAX - *(Color[TempCnt]);
			}
		}
		
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] == NULL)		continue;
			
			if (*(Color[TempCnt]) != 0)	return;
		}
		
		/* if all off, then select one to turn on */
		while (*Color[FlashConst] == NULL)
		{
			FlashConst++;
		}
		*(Color[0])	= DUTY_MAX;
		FlashConst++;
		if (FlashConst > 0x5)		FlashConst = 0;
	}
}

/**********************************************************************************
 * Function: Fade
 */
static void Fade(void)
{
  _Uint8  TempCnt = 0;
    
  if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag	= FALSE;	
		All_Off();
        
		/* initialize the time & step */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			ModeTime[TempCnt]	= 0;
			ModeStep[TempCnt]	= 0;
		}   
		
		
		
		srand(RndSeed);
		TargetDuty	= ((_Uint8)rand()) % 100;
		
		/* Initialize the pointer */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] != NULL) 			(*Color[TempCnt]) = TempCnt * 5;;
		}
	}
	
	
	
	/* mode fade */
	else
	{
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] == NULL)			continue;
			
			ModeTime[TempCnt]++;
			if (ModeTime[TempCnt] > 2)
			{
				ModeTime[TempCnt] = 0;
				
				switch (ModeStep[TempCnt])
				{
					case 0:
					{
						if ((*Color[TempCnt]) < DUTY_MAX)				(*Color[TempCnt])++;
						else																		ModeStep[TempCnt]++;
					} break;
					
					case 1:
					{
						if (*Color[TempCnt] > DUTY_MIN)					(*Color[TempCnt])--;
						else																		ModeStep[TempCnt] = 0;
					} break;
				} 
			}
		}
		
//		ModeTime[0]++;
//		if (ModeTime[0] >= FADE_TIME)    //5ms
//		{
//			ModeTime[0] = 0;
//			
//			switch (ModeStep[0])
//			{
//				/* fade out */
//				case 0:
//				{
//					if (*Color[ModeStep[1]] > TargetDuty)					(*Color[ModeStep[1]])--;
//					else																				ModeStep[0]++;
//				}	break;
//				
//				/* dark time */
//				case 1:
//				{
//					ModeTime[1]++;
//					if (ModeTime[1] > 200)
//					{
//						ModeTime[1] = 0;
//						ModeTime[2]++;
//						if (ModeTime[2] > 2)
//						{
//							ModeTime[2]	= 0;
//							ModeStep[0]++;
//							srand(RndSeed);
//							TargetDuty	= ((_Uint8)rand()) % 100;
//						}
//					}
//				}	break;
//				
//				/* fade in */
//				case 2:
//				{
//					if (*Color[ModeStep[1]] < TargetDuty)				(*Color[ModeStep[1]])++;
//					else																			ModeStep[0]++;
//				}	break;
//				
//				/* hold time */
//				case 3:
//				{
//					ModeTime[1]++;
//					if (ModeTime[1] > 200)
//					{
//						ModeTime[1] = 0;
//						
//						ModeTime[2]++;
//						if (ModeTime[2] > 3)
//						{
//							ModeTime[2]	= 0;;
//							ModeStep[0] = 0;
//							
//							srand(RndSeed);
//							TargetDuty	= ((_Uint8)rand()) % 100;
//							
//							/* LED color change */
//							ModeStep[1]++;
//							if (ModeStep[1] > 5)		ModeStep[1] = 0;
//							while (Color[ModeStep[1]] == NULL)
//							{
//								ModeStep[1]++;
//								if (ModeStep[1] > 5)		ModeStep[1] = 0;
//							}
//						}
//					}
//				}	break;
//			}
//		}
	}
}

/*************************************************************************************
 * Function : Twinkle
 */
static void Twinkle(void)
{
  _Uint8  TempCnt = 0;
	static _Uint8		TwinkleTime;
   
  if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag	= FALSE;	
		All_Off();
        
		/* Initialize time & step */
		ModeTime[0] = 0;
		ModeTime[1] = 0;
		ModeStep[0] = 0;
		ModeStep[1] = 0;
        
		/* Initialize pointer */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] != NULL) 		*Color[TempCnt] = DUTY_MAX;
    }
		
		srand(RndSeed);
		TargetDuty	= ((_Uint8)rand()) % 30 + 30;
		srand(RndSeed);
		TwinkleTime	= ((_Uint8)rand()) % 10 + 2;
  }
    
	/* Twinkle mode */
	else
	{
		ModeTime[0]++;
		if (ModeTime[0] > TwinkleTime)
		{
			ModeTime[0] = 0;
			switch (ModeStep[0])
			{
				case 0:
				{
					if (*Color[0] < TargetDuty)
					{
						for (TempCnt = 0; TempCnt < 6; TempCnt++)
						{
							if (Color[TempCnt] == NULL)			continue;
							
							(*Color[TempCnt])++;
						}
					}
					else
					{
						ModeStep[0]++;
						srand(RndSeed);
						TargetDuty	= ((_Uint8)rand()) % 30;
						srand(RndSeed);
						TwinkleTime	= ((_Uint8)rand()) % 3;
					}
				}break;
				
				case 1:
				{
					if (*Color[0] > TargetDuty)
					{
						for (TempCnt = 0; TempCnt < 6; TempCnt++)
						{
							if (Color[TempCnt] == NULL)			continue;
							
							(*Color[TempCnt])--;
						}
					}
					else
					{
						ModeStep[0] = 0;
						srand(RndSeed);
						TargetDuty	= ((_Uint8)rand()) % 70 + 30;
						srand(RndSeed);
						TwinkleTime	= ((_Uint8)rand()) % 3;
					}
				}break;
			}
		}
		
		
//		ModeTime[0]++;
//		if (ModeTime[0] >= TwinkleTime)
//		{
//			ModeTime[0] = 0;
//			
//			switch (ModeStep[0])
//			{
//				/* fade out */
//				case 0:
//				{
//					if (*Color[ModeStep[1]] > DUTY_MIN)					(*Color[ModeStep[1]]) -= 2;
//					else																				ModeStep[0]++;
//				}	break;
//				
//				/* dark hold */
//				case 1:
//				{
//					ModeTime[1]++;
//					if (ModeTime[1] >= TWINKLE_DARK_TIME)
//					{
//						ModeTime[1] = 0;
//						ModeStep[0]++;
//					}
//				}	break;
//				
//				/* fade in */
//				case 2:
//				{
//					if (*Color[ModeStep[1]] < DUTY_MAX)					(*Color[ModeStep[1]]) += 5;
//					else																				ModeStep[0]++;
//				}	break;
//				
//				/* bright hode and then back*/
//				case 3:
//				{
//					ModeTime[1]++;
//					if (ModeTime[1] > (TWINKLE_BRIGHT_TIME - 1))
//					{
//						ModeTime[1] = 0;
//						ModeStep[0] = 0;
//						
//						/* LED color change */
//						ModeStep[1]++;
//						if (ModeStep[1] > 5)			ModeStep[1] = 0;
//						while (Color[ModeStep[1]] == NULL)
//						{
//							ModeStep[1]++;
//							if (ModeStep[1] > 5)		ModeStep[1] = 0;
//						}
//					}
//				}	break;
//			}
//		}
	}
}

/************************************************************************************
 * Function: Fire
 */
static void Fire(void)
{
  _Uint8  TempCnt = 0;
    
	if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag	= FALSE;	
		All_Off();
        
		/* Initialize time & step */
		ModeTime[0] = 0;
		ModeTime[1] = 0;
		ModeStep[0] = 0;
		ModeStep[1] = 0;
        
		/* Initialize pointer */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] != NULL) 				*Color[TempCnt] = DUTY_MAX;
		}
  }
    
	/* fire mode */
	else
	{
		switch (ModeStep[0])
		{
			case 0:
			{
				ModeTime[0]++;
				if (ModeTime[0] > 2)
				{
					ModeTime[0] = 0;
					if (*Color[0] > DUTY_MIN)
					{
						for (TempCnt = 0; TempCnt < 6; TempCnt++)
						{
							if (Color[TempCnt] != NULL) 			(*Color[TempCnt])--;
						}
					}
					else
					{
						ModeStep[0]++;
					}
				}
			}	break;
			
			case 1:
			{
				(*Color[ModeStep[1]]) = DUTY_MAX;
				ModeTime[1]++;
				if (ModeTime[1] > 20)
				{
					ModeTime[1] = 0;
					
					ModeStep[1]++;
					if (ModeStep[1] > 5)						ModeStep[1] = 0;
					
					while(Color[ModeStep[1]] == NULL)
					{
						ModeStep[1]++;
						if (ModeStep[1] > 5)					ModeStep[1] = 0;
					}
					
					if (ModeStep[1] == 0)						ModeStep[0] = 0;
				}
			}	break;
		} //switch
	} // else
}

/***********************************************************************************
 * Function: Night
 */
static void Night(void)
{
	_Uint8               TempCnt = 0;
    
  if (LedData.InitFlag == TRUE)
	{
		LedData.InitFlag	= FALSE;	
		All_Off();
        
		/* initialize the time & step */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			ModeTime[TempCnt] = 0;
			ModeStep[TempCnt] = 0;
			srand(RndSeed++);
			EachTime[TempCnt]	= ((_Uint8)rand()) % 30 + 2;
		}
        
		/* initialize the pointer */
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] != NULL) 			*(Color[TempCnt]) = DUTY_MAX;
		}
  } 
    
	/* night mode */
	else
	{
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			if (Color[TempCnt] != NULL)
			{
				ModeTime[TempCnt]++;
				if (ModeTime[TempCnt] > EachTime[TempCnt])
				{
					ModeTime[TempCnt] = 0;
					EachTime[TempCnt]	= ((_Uint8)rand()) % 30 + 2;
					
					switch (ModeStep[TempCnt])
					{
						case 0:
						{
							if (*Color[TempCnt] > DUTY_MIN)
							{
								if (Color[TempCnt] != NULL) 				(*Color[TempCnt]) -= 10;
							}
							else
							{
									ModeStep[TempCnt]++;
							}
						}	break;
						
								
						case 1:
						{
							if (*Color[TempCnt] < DUTY_MAX)
							{
								if (Color[TempCnt] != NULL) 				(*Color[TempCnt]) += 10;
							}
							else
							{
								ModeStep[TempCnt] = 0;
							}
						}	break;
					}
				}
			}
		}
	}
}

/*************************************************************************************
 * Function: Circle
 */
static void Circle(void)
{
	_Uint8  TempCnt = 0;
	static _Uint8   CircleModeVal;
	static _Uint8   CircleTime[2];
    
	/* Mode Initialize */
	if (LedData.CircleInitFlag == TRUE)
	{
		/* clear flag */
		LedData.CircleInitFlag = FALSE;
		
		/* initialize the time & step */
		CircleTime[0] = 0;
		CircleTime[1] = 0;
		
		/* initialize the color& mode */
		CircleModeVal = 0x1;
		LedData.InitFlag = TRUE;
	} 
	
	/* circle mode */
	else
	{
			CircleTime[0]++;
			if (CircleTime[0] > 199)   //200 * 10ms = 2s
			{
				CircleTime[0] = 0;
				CircleTime[1]++;
				if (CircleTime[1] > 4)   //10s
				{
					CircleTime[1] = 0;

					LedData.InitFlag = TRUE;

					/* mode change */
					CircleModeVal++;
					if (CircleModeVal > 0x7)
					{
						CircleModeVal = 0x1;
					}
				}
			}
			
		switch (CircleModeVal)
		{
			case 0x0:         Power_Off();													break;			/* power off 			*/
			case 0x1:		 			Steady(); 														break;			/* steady 				*/
			case 0x2:					Flash(SPARKLE_TIME, SPARKLE_BASIC);		break;			/* flash fast			*/
			case 0x3:					Flash(GLIMMER_TIME, GLIMMER_BASIC);		break;			/* flash slowly   */		
			case 0x4:			 		Fade();																break;			/* fade           */
			case 0x5:					Twinkle();														break;			/* twinkle        */
			case 0x6:					Fire();																break;			/* fire           */
			case 0x7:					Night();															break;			/* night          */
		}
	}//else
}
