/********************************************************************
	*
	* FILE NAME
	*									Show_2.c
	* DATE
	*									02 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									Display Show 2
	*
*********************************************************************/
#include "Show.h"


/**
	* FunctionName	Show_2
	*/
void Show_2(void)
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
	else if (TimeLine == 1640)					{ShowMode = 1;			ShowInit = TRUE;	}
	else if (TimeLine == 3200)					{ShowMode = 2;			ShowInit = TRUE;	}
	else if (TimeLine == 3720)					{ShowMode = 3;			ShowInit = TRUE;	}
	else if (TimeLine == 4725)					{ShowMode = 4;			ShowInit = TRUE;	}
	else if (TimeLine == 6500)					{TimeLine = 0;			DisplayData.InitFlag = TRUE;}

	switch (ShowMode)
	{
		case 0:			Show_2_1();		break;
		case 1:			Show_2_0();		break;
		case 2:			Show_2_2();		break;
		case 3:			Show_2_3();		break;
		case 4:			Show_2_4();		break;
	}
}


/*
 * FunctionName		Show_2_0
 * Duration				TimeLine += 1560
 */
void Show_2_0(void)
{
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		TempColor		= 3;
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
		return;
	}
	
	SpeedTime++;
	if (SpeedTime >= 5)
	{
		SpeedTime = 0;
		
		switch (TempStep)
		{
			case 0:
			{
						/* Icicle */
						if (RndCnt30 < 30)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 30;
							} while (ModeLed30[TempLed] == 1);
							ModeLed30[TempLed] = 1;
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
							
							Grd.Snow[ModeLedSnow[0]].DutyR	= ColorData[TempColor][R];
							Grd.Snow[ModeLedSnow[0]].DutyG	= ColorData[TempColor][G];
							Grd.Snow[ModeLedSnow[0]].DutyB	= ColorData[TempColor][B];

							Grd.Snow[ModeLedSnow[1]].DutyR	= ColorData[TempColor][R];
							Grd.Snow[ModeLedSnow[1]].DutyG	= ColorData[TempColor][G];
							Grd.Snow[ModeLedSnow[1]].DutyB	= ColorData[TempColor][B];
							
							Grd.Snow[ModeLedSnow[2]].DutyR	= ColorData[TempColor][R];
							Grd.Snow[ModeLedSnow[2]].DutyG	= ColorData[TempColor][G];
							Grd.Snow[ModeLedSnow[2]].DutyB	= ColorData[TempColor][B];
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
						
						/* Spot */
						if (RndCntSpot < 3)
						{
							Grd.Spot[RndCntSpot].DutyR	= ColorData[TempColor][R];
							Grd.Spot[RndCntSpot].DutyG	= ColorData[TempColor][G];
							Grd.Spot[RndCntSpot].DutyB	= ColorData[TempColor + 1][B];
							RndCntSpot++;
						}
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = ColorData[TempColor][R];
							Grd.Ball[TempCnt].DutyG = ColorData[TempColor][G];
							Grd.Ball[TempCnt].DutyB = ColorData[TempColor][B];
						}
						
						
						if (RndCnt40 >= 40)
						{
							TempStep++;
							for (TempLed = 0; TempLed < 10; TempLed++)
							{
								RAND();
								HoldTime10[TempLed] = (_Uint8)rand() % 20;
								ModeStep10[TempLed] = 1;
								ModeTime10[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								RAND();
								HoldTime24[TempLed] = (_Uint8)rand() % 20;
								ModeStep24[TempLed] = 1;
								ModeTime24[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								RAND();
								HoldTime30[TempLed] = (_Uint8)rand() % 20;
								ModeStep30[TempLed] = 1;
								ModeTime30[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 40; TempLed++)
							{
								RAND();
								HoldTime40[TempLed] = (_Uint8)rand() % 20;
								ModeStep40[TempLed] = 1;
								ModeTime40[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								RAND();
								HoldTimes30[TempLed] = (_Uint8)rand() % 20;
								ModeSteps30[TempLed] = 1;
								ModeTimes30[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								RAND();
								HoldTimes24[TempLed] = (_Uint8)rand() % 20;
								ModeSteps24[TempLed] = 1;
								ModeTimes24[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 36; TempLed++)
							{
								RAND();
								HoldTimes36[TempLed] = (_Uint8)rand() % 20;
								ModeSteps36[TempLed] = 1;
								ModeTimes36[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								RAND();
								HoldTimeTree[TempLed] = (_Uint8)rand() % 20;
								ModeStepTree[TempLed] = 1;
								ModeTimeTree[TempLed] = 0;
								RAND();
								HoldTimeSnow[TempLed] = (_Uint8)rand() % 20;
								ModeStepSnow[TempLed] = 1;
								ModeTimeSnow[TempLed] = 0;
								RAND();
								HoldTimeSpot[TempLed] = (_Uint8)rand() % 20;
								ModeStepSpot[TempLed] = 1;
								ModeTimeSpot[TempLed] = 0;
							}
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								RAND();
								HoldTimeCane[TempLed] = (_Uint8)rand() % 20;
								ModeStepCane[TempLed] = 1;
								ModeTimeCane[TempLed] = 0;
							}
							
							RAND();
							HoldTimeBall = (_Uint8)rand() % 20;
							ModeStepBall = 1;
							ModeTimeBall = 0;
							
							HoldTime = 0;
							KeepTime = 0;
						}
			} break;
			
			
			case 1:
			{
							/* Roof10 */
							for (TempLed = 0; TempLed < 10; TempLed++)
							{
								switch (ModeStep10[TempLed])
								{
									case 0:
									{
										Roof10[TempLed].DutyR		= ColorData[TempColor][R];
										Roof10[TempLed].DutyG		= ColorData[TempColor][G];
										Roof10[TempLed].DutyB		= ColorData[TempColor][B];
										ModeStep10[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTime10[TempLed]++;
										if (ModeTime10[TempLed] > HoldTime10[TempLed])
										{
											ModeTime10[TempLed] = 0;
											RAND();
											HoldTime10[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStep10[TempLed]++;
										}
									} break;
									
									default:
									{
										Roof10[TempLed].DutyR		= 0;
										Roof10[TempLed].DutyG		= 0;
										Roof10[TempLed].DutyB		= 0;
										ModeStep10[TempLed] = 0;
									} break;
								}
							}
							
							/* Roof24 */
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								switch (ModeStep24[TempLed])
								{
									case 0:
									{
										Roof24[TempLed].DutyR		= ColorData[TempColor][R];
										Roof24[TempLed].DutyG		= ColorData[TempColor][G];
										Roof24[TempLed].DutyB		= ColorData[TempColor][B];
										ModeStep24[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTime24[TempLed]++;
										if (ModeTime24[TempLed] > HoldTime24[TempLed])
										{
											ModeTime24[TempLed] = 0;
											RAND();
											HoldTime24[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStep24[TempLed]++;
										}
									} break;
									
									default:
									{
										Roof24[TempLed].DutyR		= 0;
										Roof24[TempLed].DutyG		= 0;
										Roof24[TempLed].DutyB		= 0;
										ModeStep24[TempLed] = 0;
									} break;
								}
							}
							
							/* Roof30 */
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								switch (ModeStep30[TempLed])
								{
									case 0:
									{
										Roof30[TempLed].DutyR		= ColorData[TempColor][R];
										Roof30[TempLed].DutyG		= ColorData[TempColor][G];
										Roof30[TempLed].DutyB		= ColorData[TempColor][B];
										ModeStep30[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTime30[TempLed]++;
										if (ModeTime30[TempLed] > HoldTime30[TempLed])
										{
											ModeTime30[TempLed] = 0;
											RAND();
											HoldTime30[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStep30[TempLed]++;
										}
									} break;
									
									default:
									{
										Roof30[TempLed].DutyR		= 0;
										Roof30[TempLed].DutyG		= 0;
										Roof30[TempLed].DutyB		= 0;
										ModeStep30[TempLed] = 0;
									} break;
								}
							}
							
							/* Roof40 */
							for (TempLed = 0; TempLed < 40; TempLed++)
							{
								switch (ModeStep40[TempLed])
								{
									case 0:
									{
										Roof40[TempLed].DutyR		= ColorData[TempColor][R];
										Roof40[TempLed].DutyG		= ColorData[TempColor][G];
										Roof40[TempLed].DutyB		= ColorData[TempColor][B];
										ModeStep40[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTime40[TempLed]++;
										if (ModeTime40[TempLed] > HoldTime40[TempLed])
										{
											ModeTime40[TempLed] = 0;
											RAND();
											HoldTime40[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStep40[TempLed]++;
										}
									} break;
									
									default:
									{
										Roof40[TempLed].DutyR		= 0;
										Roof40[TempLed].DutyG		= 0;
										Roof40[TempLed].DutyB		= 0;
										ModeStep40[TempLed] = 0;
									} break;
								}
							}
							
							/* String30 */
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								switch (ModeSteps30[TempLed])
								{
									case 0:
									{
										String30[TempLed].DutyR		= ColorData[TempColor][R];
										String30[TempLed].DutyG		= ColorData[TempColor][G];
										String30[TempLed].DutyB		= ColorData[TempColor][B];
										ModeSteps30[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTimes30[TempLed]++;
										if (ModeTimes30[TempLed] > HoldTimes30[TempLed])
										{
											ModeTimes30[TempLed] = 0;
											RAND();
											HoldTimes30[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeSteps30[TempLed]++;
										}
									} break;
									
									default:
									{
										String30[TempLed].DutyR		= 0;
										String30[TempLed].DutyG		= 0;
										String30[TempLed].DutyB		= 0;
										ModeSteps30[TempLed] = 0;
									} break;
								}
							}
							
							/* String24 */
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								switch (ModeSteps24[TempLed])
								{
									case 0:
									{
										String24[TempLed].DutyR		= ColorData[TempColor][R];
										String24[TempLed].DutyG		= ColorData[TempColor][G];
										String24[TempLed].DutyB		= ColorData[TempColor][B];
										ModeSteps24[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTimes24[TempLed]++;
										if (ModeTimes24[TempLed] > HoldTimes24[TempLed])
										{
											ModeTimes24[TempLed] = 0;
											RAND();
											HoldTimes24[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeSteps24[TempLed]++;
										}
									} break;
									
									default:
									{
										String24[TempLed].DutyR		= 0;
										String24[TempLed].DutyG		= 0;
										String24[TempLed].DutyB		= 0;
										ModeSteps24[TempLed] = 0;
									} break;
								}
							}
							
							/* String36 */
							for (TempLed = 0; TempLed < 36; TempLed++)
							{
								switch (ModeSteps36[TempLed])
								{
									case 0:
									{
										String36[TempLed].DutyR		= ColorData[TempColor][R];
										String36[TempLed].DutyG		= ColorData[TempColor][G];
										String36[TempLed].DutyB		= ColorData[TempColor][B];
										ModeSteps36[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTimes36[TempLed]++;
										if (ModeTimes36[TempLed] > HoldTimes36[TempLed])
										{
											ModeTimes36[TempLed] = 0;
											RAND();
											HoldTimes36[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeSteps36[TempLed]++;
										}
									} break;
									
									default:
									{
										String36[TempLed].DutyR		= 0;
										String36[TempLed].DutyG		= 0;
										String36[TempLed].DutyB		= 0;
										ModeSteps36[TempLed] = 0;
									} break;
								}
							}
							
							/* Tree */
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								switch (ModeStepTree[TempLed])
								{
									case 0:
									{
										for (TempCnt = 0; TempCnt < 9; TempCnt++)
										{
											Grd.Tree[TempLed * 9 + TempCnt].DutyR		= ColorData[TempColor][R];
											Grd.Tree[TempLed * 9 + TempCnt].DutyG		= ColorData[TempColor][G];
											Grd.Tree[TempLed * 9 + TempCnt].DutyB		= ColorData[TempColor][B];
										}
										ModeStepTree[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTimeTree[TempLed]++;
										if (ModeTimeTree[TempLed] > HoldTimeTree[TempLed])
										{
											ModeTimeTree[TempLed] = 0;
											RAND();
											HoldTimeTree[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStepTree[TempLed]++;
										}
									} break;
									
									default:
									{
										for (TempCnt = 0; TempCnt < 9; TempCnt++)
										{
											Grd.Tree[TempCnt + TempLed * 9].DutyR		= 0;
											Grd.Tree[TempCnt + TempLed * 9].DutyG		= 0;
											Grd.Tree[TempCnt + TempLed * 9].DutyB		= 0;
										}
										ModeStepTree[TempLed] = 0;
									} break;
								}
							}
							
							/* Snow */
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								switch (ModeStepSnow[TempLed])
								{
									case 0:
									{
										for (TempCnt = 0; TempCnt < 7; TempCnt++)
										{
											Grd.Snow[TempCnt + TempLed * 7].DutyR		= ColorData[TempColor][R];
											Grd.Snow[TempCnt + TempLed * 7].DutyG		= ColorData[TempColor][G];
											Grd.Snow[TempCnt + TempLed * 7].DutyB		= ColorData[TempColor][B];
										}
										ModeStepSnow[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTimeSnow[TempLed]++;
										if (ModeTimeSnow[TempLed] > HoldTimeSnow[TempLed])
										{
											ModeTimeSnow[TempLed] = 0;
											RAND();
											HoldTimeSnow[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStepSnow[TempLed]++;
										}
									} break;
									
									default:
									{
										for (TempCnt = 0; TempCnt < 7; TempCnt++)
										{
											Grd.Snow[TempCnt + TempLed * 7].DutyR		= 0;
											Grd.Snow[TempCnt + TempLed * 7].DutyG		= 0;
											Grd.Snow[TempCnt + TempLed * 7].DutyB		= 0;
										}
										ModeStepSnow[TempLed] = 0;
									} break;
								}
							}
							
							/* Cane */
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								switch (ModeStepCane[TempLed])
								{
									case 0:
									{
										for (TempCnt = 0; TempCnt < 5; TempCnt++)
										{
											Grd.Cane[TempCnt + TempLed * 5].DutyR		= ColorData[TempColor][R];
											Grd.Cane[TempCnt + TempLed * 5].DutyG		= ColorData[TempColor][G];
											Grd.Cane[TempCnt + TempLed * 5].DutyB		= ColorData[TempColor][B];
										}
										ModeStepCane[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTimeCane[TempLed]++;
										if (ModeTimeCane[TempLed] > HoldTimeCane[TempLed])
										{
											ModeTimeCane[TempLed] = 0;
											RAND();
											HoldTimeCane[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStepCane[TempLed]++;
										}
									} break;
									
									default:
									{
										for (TempCnt = 0; TempCnt < 5;TempCnt++)
										{
											Grd.Cane[TempCnt + TempLed * 5].DutyR		= 0;
											Grd.Cane[TempCnt + TempLed * 5].DutyG		= 0;
											Grd.Cane[TempCnt + TempLed * 5].DutyB		= 0;
										}
										ModeStepCane[TempLed] = 0;
									} break;
								}
							}
							
							/* Spot */
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								switch (ModeStepSpot[TempLed])
								{
									case 0:
									{
										Grd.Spot[TempLed].DutyR		= ColorData[TempColor][R];
										Grd.Spot[TempLed].DutyG		= ColorData[TempColor][G];
										Grd.Spot[TempLed].DutyB		= ColorData[TempColor][B];
										ModeStepSpot[TempLed] ++;
									} break;
									
									case 1:
									{
										ModeTimeSpot[TempLed]++;
										if (ModeTimeSpot[TempLed] > HoldTimeSpot[TempLed])
										{
											ModeTimeSpot[TempLed] = 0;
											RAND();
											HoldTimeSpot[TempLed] = (_Uint8)rand() % 20 + 20;
											ModeStepSpot[TempLed]++;
										}
									} break;
									
									default:
									{
										Grd.Spot[TempLed].DutyR		= 0;
										Grd.Spot[TempLed].DutyG		= 0;
										Grd.Spot[TempLed].DutyB		= 0;
										ModeStepSpot[TempLed] = 0;
									} break;
								}
							}
							
							/* Ball */
							switch (ModeStepBall)
							{
								case 0:
								{
									for (TempCnt = 0; TempCnt < 4; TempCnt++)
									{
										Grd.Ball[TempCnt].DutyR		= ColorData[TempColor][R];
										Grd.Ball[TempCnt].DutyG		= ColorData[TempColor][G];
										Grd.Ball[TempCnt].DutyB		= ColorData[TempColor][B];
									}
									ModeStepBall ++;
								} break;
								
								case 1:
								{
									ModeTimeBall++;
									if (ModeTimeBall > HoldTimeBall)
									{
										ModeTimeBall = 0;
										RAND();
										HoldTimeBall = (_Uint8)rand() % 20 + 20;
										ModeStepBall++;
									}
								} break;
								
								default:
								{
									for (TempCnt = 0; TempCnt < 4; TempCnt++)
									{
										Grd.Ball[TempCnt].DutyR		= 0;
										Grd.Ball[TempCnt].DutyG		= 0;
										Grd.Ball[TempCnt].DutyB		= 0;
									}

									ModeStepBall = 0;
								} break;
							}
							
							
							HoldTime++;
							if (HoldTime > 50)
							{
								HoldTime 			= 0;
								TempStep			= 0;

								TempR	= ColorData[TempColor][R];
								TempG	= ColorData[TempColor][G];
								TempB = ColorData[TempColor][B];
								All_Color(TempR, TempG, TempB);
								
								
								
								TempColor++;
								if (TempColor > 5)	
								{
									TempStep		= 2;
								}
								
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
			} break;
			
			default:
			{
							/* Icicle */
						if (RndCnt30 < 30)		
						{
							do
							{
								RAND();
								TempLed = (_Uint8)rand() % 30;
							} while (ModeLed30[TempLed] == 1);
							ModeLed30[TempLed] = 1;
							
							TempColor = TempLed % ColorNum;
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
							
							TempColor = TempLed % ColorNum;
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
							
							TempColor = TempLed % ColorNum;
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
							
							TempColor = TempLed % ColorNum;
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
							
							TempColor = TempLed % ColorNum;
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
							
							TempColor = TempLed % ColorNum;
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
							
							TempColor = TempLed % ColorNum;
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
							
							TempColor = (RndCntTree - 1) / 4;
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
						if (RndCntSnow < 12)
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
							
							TempColor = ModeLedSnow[0] / 7;
							Grd.Snow[ModeLedSnow[0]].DutyR	= ColorData[TempColor][R];
							Grd.Snow[ModeLedSnow[0]].DutyG	= ColorData[TempColor][G];
							Grd.Snow[ModeLedSnow[0]].DutyB	= ColorData[TempColor][B];
							
							TempColor = ModeLedSnow[1] / 7;
							Grd.Snow[ModeLedSnow[1]].DutyR	= ColorData[TempColor][R];
							Grd.Snow[ModeLedSnow[1]].DutyG	= ColorData[TempColor][G];
							Grd.Snow[ModeLedSnow[1]].DutyB	= ColorData[TempColor][B];
							
							TempColor = ModeLedSnow[2] / 7;
							Grd.Snow[ModeLedSnow[2]].DutyR	= ColorData[TempColor][R];
							Grd.Snow[ModeLedSnow[2]].DutyG	= ColorData[TempColor][G];
							Grd.Snow[ModeLedSnow[2]].DutyB	= ColorData[TempColor][B];
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
							Grd.Ball[TempCnt].DutyR = ColorData[1][R];
							Grd.Ball[TempCnt].DutyG = ColorData[1][G];
							Grd.Ball[TempCnt].DutyB = ColorData[1][B];
						}
						
						
						if (RndCnt40 >= 40)
						{
							TempStep = 0xFF;
						}
			} break;
		}
	}
}


/*
 * FunctionName		Show_2_1
 * Duration				TimeLine += 3200
 */
void Show_2_1(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		TempColor		= 0;
		SpeedTime		= 0;
		TempStep		= 0;
		
		for (TempLed = 0; TempLed < 10; TempLed++)
		{
			TempColor = TempLed % ColorNum;
			Roof10[TempLed].DutyR = ColorData[TempColor][R];
			Roof10[TempLed].DutyG = ColorData[TempColor][G];
			Roof10[TempLed].DutyB = ColorData[TempColor][B];
		}
		
		for (TempLed = 0; TempLed < 24; TempLed++)
		{
			TempColor = TempLed % ColorNum;
			Roof24[TempLed].DutyR = ColorData[TempColor][R];
			Roof24[TempLed].DutyG = ColorData[TempColor][G];
			Roof24[TempLed].DutyB = ColorData[TempColor][B];
		}
		
		for (TempLed = 0; TempLed < 30; TempLed++)
		{
			TempColor = TempLed % ColorNum;
			Roof30[TempLed].DutyR = ColorData[TempColor][R];
			Roof30[TempLed].DutyG = ColorData[TempColor][G];
			Roof30[TempLed].DutyB = ColorData[TempColor][B];
		}
		
		for (TempLed = 0; TempLed < 40; TempLed++)
		{
			TempColor = TempLed % ColorNum;
			Roof40[TempLed].DutyR = ColorData[TempColor][R];
			Roof40[TempLed].DutyG = ColorData[TempColor][G];
			Roof40[TempLed].DutyB = ColorData[TempColor][B];
		}
		
		for (TempLed = 0; TempLed < 30; TempLed++)
		{
			TempColor = TempLed % ColorNum;
			String30[TempLed].DutyR = ColorData[TempColor][R];
			String30[TempLed].DutyG = ColorData[TempColor][G];
			String30[TempLed].DutyB = ColorData[TempColor][B];
		}
		
		for (TempLed = 0; TempLed < 24; TempLed++)
		{
			TempColor = TempLed % ColorNum;
			String24[TempLed].DutyR = ColorData[TempColor][R];
			String24[TempLed].DutyG = ColorData[TempColor][G];
			String24[TempLed].DutyB = ColorData[TempColor][B];
		}
		
		for (TempLed = 0; TempLed < 36; TempLed++)
		{
			TempColor = TempLed % ColorNum;
			String36[TempLed].DutyR = ColorData[TempColor][R];
			String36[TempLed].DutyG = ColorData[TempColor][G];
			String36[TempLed].DutyB = ColorData[TempColor][B];
		}
		
		for (TempCnt = 0; TempCnt < 3; TempCnt++)
		{
			TempColor = TempCnt % ColorNum;
			for (TempLed = 0; TempLed < 9; TempLed++)
			{
				Grd.Tree[TempCnt * 9 + TempLed].DutyR = ColorData[TempColor][R];
				Grd.Tree[TempCnt * 9 + TempLed].DutyG = ColorData[TempColor][G];
				Grd.Tree[TempCnt * 9 + TempLed].DutyB = ColorData[TempColor][B];
			}
		}
		
		for (TempCnt = 0; TempCnt < 3; TempCnt++)
		{
			TempColor = TempCnt % ColorNum;
			for (TempLed = 0; TempLed < 7; TempLed++)
			{
				Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[TempColor][R];
				Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[TempColor][G];
				Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[TempColor][B];
			}
		}
		
		for (TempCnt = 0; TempCnt < 6; TempCnt++)
		{
			TempColor = TempCnt % ColorNum;
			for (TempLed = 0; TempLed < 5; TempLed++)
			{
				Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[TempColor][R];
				Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[TempColor][G];
				Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[TempColor][B];
			}
		}
		
		for (TempCnt = 0; TempCnt < 3; TempCnt++)
		{
			TempColor = TempCnt % ColorNum;
			Grd.Spot[TempCnt].DutyR = ColorData[TempColor][R];
			Grd.Spot[TempCnt].DutyG = ColorData[TempColor][G];
			Grd.Spot[TempCnt].DutyB = ColorData[TempColor][B];
		}
		
		for (TempCnt = 0; TempCnt < 4; TempCnt++)
		{
			Grd.Ball[TempCnt].DutyR = ColorData[0][R];
			Grd.Ball[TempCnt].DutyG = ColorData[0][G];
			Grd.Ball[TempCnt].DutyB = ColorData[0][B];
		}
		
		
		HoldTime		= 0;
		return;
	}
	
	
	switch (TempStep)
	{
		case 0:
		{
						SpeedTime++;
						if (SpeedTime >= 20)
						{
							SpeedTime = 0;
							
							/* Roof10 */
							TempR = Roof10[0].DutyR;
							TempG = Roof10[0].DutyG;
							TempB = Roof10[0].DutyB;
							for (TempLed = 0; TempLed < 9; TempLed++)
							{
								Roof10[TempLed].DutyR = Roof10[TempLed + 1].DutyR;
								Roof10[TempLed].DutyG = Roof10[TempLed + 1].DutyG;
								Roof10[TempLed].DutyB = Roof10[TempLed + 1].DutyB;
							}
							Roof10[9].DutyR = TempR;
							Roof10[9].DutyG = TempG;
							Roof10[9].DutyB = TempB;
							
							/* Roof24 */
							TempR = Roof24[0].DutyR;
							TempG = Roof24[0].DutyG;
							TempB = Roof24[0].DutyB;
							for (TempLed = 0; TempLed < 23; TempLed++)
							{
								Roof24[TempLed].DutyR = Roof24[TempLed + 1].DutyR;
								Roof24[TempLed].DutyG = Roof24[TempLed + 1].DutyG;
								Roof24[TempLed].DutyB = Roof24[TempLed + 1].DutyB;
							}
							Roof24[23].DutyR = TempR;
							Roof24[23].DutyG = TempG;
							Roof24[23].DutyB = TempB;
							
							/* Roof30 */
							TempR = Roof30[0].DutyR;
							TempG = Roof30[0].DutyG;
							TempB = Roof30[0].DutyB;
							for (TempLed = 0; TempLed < 29; TempLed++)
							{
								Roof30[TempLed].DutyR = Roof30[TempLed + 1].DutyR;
								Roof30[TempLed].DutyG = Roof30[TempLed + 1].DutyG;
								Roof30[TempLed].DutyB = Roof30[TempLed + 1].DutyB;
							}
							Roof30[29].DutyR = TempR;
							Roof30[29].DutyG = TempG;
							Roof30[29].DutyB = TempB;
							
							/* Roof40 */
							TempR = Roof40[0].DutyR;
							TempG = Roof40[0].DutyG;
							TempB = Roof40[0].DutyB;
							for (TempLed = 0; TempLed < 39; TempLed++)
							{
								Roof40[TempLed].DutyR = Roof40[TempLed + 1].DutyR;
								Roof40[TempLed].DutyG = Roof40[TempLed + 1].DutyG;
								Roof40[TempLed].DutyB = Roof40[TempLed + 1].DutyB;
							}
							Roof40[39].DutyR = TempR;
							Roof40[39].DutyG = TempG;
							Roof40[39].DutyB = TempB;
							
							/* String30 */
							TempR = String30[0].DutyR;
							TempG = String30[0].DutyG;
							TempB = String30[0].DutyB;
							for (TempLed = 0; TempLed < 29; TempLed++)
							{
								String30[TempLed].DutyR = String30[TempLed + 1].DutyR;
								String30[TempLed].DutyG = String30[TempLed + 1].DutyG;
								String30[TempLed].DutyB = String30[TempLed + 1].DutyB;
							}
							String30[29].DutyR = TempR;
							String30[29].DutyG = TempG;
							String30[29].DutyB = TempB;
							
							/* String24 */
							TempR = String24[0].DutyR;
							TempG = String24[0].DutyG;
							TempB = String24[0].DutyB;
							for (TempLed = 0; TempLed < 23; TempLed++)
							{
								String24[TempLed].DutyR = String24[TempLed + 1].DutyR;
								String24[TempLed].DutyG = String24[TempLed + 1].DutyG;
								String24[TempLed].DutyB = String24[TempLed + 1].DutyB;
							}
							String24[23].DutyR = TempR;
							String24[23].DutyG = TempG;
							String24[23].DutyB = TempB;
							
							/* String36 */
							TempR = String36[0].DutyR;
							TempG = String36[0].DutyG;
							TempB = String36[0].DutyB;
							for (TempLed = 0; TempLed < 35; TempLed++)
							{
								String36[TempLed].DutyR = String36[TempLed + 1].DutyR;
								String36[TempLed].DutyG = String36[TempLed + 1].DutyG;
								String36[TempLed].DutyB = String36[TempLed + 1].DutyB;
							}
							String36[35].DutyR = TempR;
							String36[35].DutyG = TempG;
							String36[35].DutyB = TempB;
							
							/* Tree */
							TempR = Grd.Tree[0].DutyR;
							TempG = Grd.Tree[0].DutyG;
							TempB = Grd.Tree[0].DutyB;
							for (TempCnt = 0; TempCnt < 2; TempCnt++)
							{
								for (TempLed = 0; TempLed < 9; TempLed++)
								{
									Grd.Tree[TempLed + TempCnt * 9].DutyR = Grd.Tree[TempLed + TempCnt * 9 + 9].DutyR;
									Grd.Tree[TempLed + TempCnt * 9].DutyG = Grd.Tree[TempLed + TempCnt * 9 + 9].DutyG;
									Grd.Tree[TempLed + TempCnt * 9].DutyB = Grd.Tree[TempLed + TempCnt * 9 + 9].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 9; TempLed++)
							{
								Grd.Tree[TempLed + 18].DutyR = TempR;
								Grd.Tree[TempLed + 18].DutyG = TempG;
								Grd.Tree[TempLed + 18].DutyB = TempB;
							}
							
							/* Snow */
							TempR = Grd.Snow[0].DutyR;
							TempG = Grd.Snow[0].DutyG;
							TempB = Grd.Snow[0].DutyB;
							for (TempCnt = 0; TempCnt < 2; TempCnt++)
							{
								for (TempLed = 0; TempLed < 7; TempLed++)
								{
									Grd.Snow[TempLed + TempCnt * 7].DutyR = Grd.Snow[TempLed + TempCnt * 7 + 7].DutyR;
									Grd.Snow[TempLed + TempCnt * 7].DutyG = Grd.Snow[TempLed + TempCnt * 7 + 7].DutyG;
									Grd.Snow[TempLed + TempCnt * 7].DutyB = Grd.Snow[TempLed + TempCnt * 7 + 7].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 7; TempLed++)
							{
								Grd.Snow[TempLed + 14].DutyR = TempR;
								Grd.Snow[TempLed + 14].DutyG = TempG;
								Grd.Snow[TempLed + 14].DutyB = TempB;
							}
							
							/* Spot */
							TempR = Grd.Spot[0].DutyR;
							TempG = Grd.Spot[0].DutyG;
							TempB = Grd.Spot[0].DutyB;
							for (TempCnt = 0; TempCnt < 2; TempCnt++)
							{
								for (TempLed = 0; TempLed < 7; TempLed++)
								{
									Grd.Spot[TempLed + TempCnt * 7].DutyR = Grd.Spot[TempLed + TempCnt * 7 + 7].DutyR;
									Grd.Spot[TempLed + TempCnt * 7].DutyG = Grd.Spot[TempLed + TempCnt * 7 + 7].DutyG;
									Grd.Spot[TempLed + TempCnt * 7].DutyB = Grd.Spot[TempLed + TempCnt * 7 + 7].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 7; TempLed++)
							{
								Grd.Spot[TempLed + 14].DutyR = TempR;
								Grd.Spot[TempLed + 14].DutyG = TempG;
								Grd.Spot[TempLed + 14].DutyB = TempB;
							}
							
							/* Cane */
							TempR = Grd.Cane[0].DutyR;
							TempG = Grd.Cane[0].DutyG;
							TempB = Grd.Cane[0].DutyB;
							for (TempCnt = 0; TempCnt < 6; TempCnt++)
							{
								for (TempLed = 0; TempLed < 5; TempLed++)
								{
									Grd.Cane[TempLed + TempCnt * 5].DutyR = Grd.Cane[TempLed + TempCnt * 5 + 5].DutyR;
									Grd.Cane[TempLed + TempCnt * 5].DutyG = Grd.Cane[TempLed + TempCnt * 5 + 5].DutyG;
									Grd.Cane[TempLed + TempCnt * 5].DutyB = Grd.Cane[TempLed + TempCnt * 5 + 5].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Grd.Cane[TempLed + 25].DutyR = TempR;
								Grd.Cane[TempLed + 25].DutyG = TempG;
								Grd.Cane[TempLed + 25].DutyB = TempB;
							}
							
							/* Ball */
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								Grd.Ball[TempLed].DutyR = Grd.Snow[14].DutyR;
								Grd.Ball[TempLed].DutyG = Grd.Snow[14].DutyG;
								Grd.Ball[TempLed].DutyB = Grd.Snow[14].DutyB;
							}
							
							
							HoldTime++;
							if (HoldTime >= 20)
							{
								HoldTime = 0;
								TempStep++;
								TempColor = 0;
								RndCnt10 = 0;
								
								ModeStepTree[0] 	= 0;
								ModeColorTree[0] 	= 0;
								ModeStepSnow[0] 	= 0;
								ModeColorSnow[0] 	= 0;
								ModeStepSpot[0] 	= 0;
								ModeColorSpot[0] 	= 0;
								ModeStepCane[0]		= 0;
								ModeColorCane[0]	= 0;
								ModeColorBall			= 0;
								ModeStepBall			= 0;
							}
						}		
		} break;
		
		
		case 1:
		{
						SpeedTime++;
						if (SpeedTime >= 10)
						{
							SpeedTime = 0;
							
							/* Roof10 */
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
							for (TempLed = 29; TempLed > 0; TempLed--)
							{
								Roof30[TempLed].DutyR = Roof30[TempLed - 1].DutyR;
								Roof30[TempLed].DutyG = Roof30[TempLed - 1].DutyG;
								Roof30[TempLed].DutyB = Roof30[TempLed - 1].DutyB;
							}
							Roof30[0].DutyR = TempR;
							Roof30[0].DutyG = TempG;
							Roof30[0].DutyB = TempB;
							
							/* Roof40 */
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
							for (TempLed = 39; TempLed > 0; TempLed--)
							{
								Roof40[TempLed].DutyR = Roof40[TempLed - 1].DutyR;
								Roof40[TempLed].DutyG = Roof40[TempLed - 1].DutyG;
								Roof40[TempLed].DutyB = Roof40[TempLed - 1].DutyB;
							}
							Roof40[0].DutyR = TempR;
							Roof40[0].DutyG = TempG;
							Roof40[0].DutyB = TempB;
							
							/* String30 */
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
							for (TempLed = 35; TempLed > 0; TempLed--)
							{
								String36[TempLed].DutyR = String36[TempLed - 1].DutyR;
								String36[TempLed].DutyG = String36[TempLed - 1].DutyG;
								String36[TempLed].DutyB = String36[TempLed - 1].DutyB;
							}
							String36[0].DutyR = TempR;
							String36[0].DutyG = TempG;
							String36[0].DutyB = TempB;
							
							RndCnt10++;
							if(RndCnt10 > 5)
							{
								RndCnt10 = 0; 
								TempColor++;
								if (TempColor >= ColorNum)		TempColor = 0;
							}
							
							
							/* Tree */
							switch (ModeStepTree[0])
							{
								case 0:
								{
											TempCnt = 0;
											for (TempLed = 0; TempLed < 9; TempLed++)
											{
												Grd.Tree[TempLed + TempCnt * 9].DutyR = ColorData[ModeColorTree[0]][R];
												Grd.Tree[TempLed + TempCnt * 9].DutyG = ColorData[ModeColorTree[0]][G];
												Grd.Tree[TempLed + TempCnt * 9].DutyB = ColorData[ModeColorTree[0]][B];
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0]++;
								} break;
								
								case 1:
								{
											TempCnt = 2;
											for (TempLed = 0; TempLed < 9; TempLed++)
											{
												Grd.Tree[TempLed + TempCnt * 9].DutyR = ColorData[ModeColorTree[0]][R];
												Grd.Tree[TempLed + TempCnt * 9].DutyG = ColorData[ModeColorTree[0]][G];
												Grd.Tree[TempLed + TempCnt * 9].DutyB = ColorData[ModeColorTree[0]][B];
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0]++;
								} break;
								
								case 2:
								{
											TempCnt = 1;
											for (TempLed = 0; TempLed < 9; TempLed++)
											{
												Grd.Tree[TempLed + TempCnt * 9].DutyR = ColorData[ModeColorTree[0]][R];
												Grd.Tree[TempLed + TempCnt * 9].DutyG = ColorData[ModeColorTree[0]][G];
												Grd.Tree[TempLed + TempCnt * 9].DutyB = ColorData[ModeColorTree[0]][B];
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 3; TempCnt++)
											{
												for (TempLed = 0; TempLed < 9; TempLed++)
												{
													Grd.Tree[TempCnt * 9 + TempLed].DutyR = ColorData[ModeColorTree[0]][R];
													Grd.Tree[TempCnt * 9 + TempLed].DutyG = ColorData[ModeColorTree[0]][G];
													Grd.Tree[TempCnt * 9 + TempLed].DutyB = ColorData[ModeColorTree[0]][B];
												}
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0] = 0;
								} break;
							}
							
							/* Snow */
							switch (ModeStepSnow[0])
							{
								case 0:
								{
											TempCnt = 2;
											for (TempLed = 0; TempLed < 7; TempLed++)
											{
												Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
												Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
												Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0]++;
								} break;
								
								case 1:
								{
											TempCnt = 0;
											for (TempLed = 0; TempLed < 7; TempLed++)
											{
												Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
												Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
												Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0]++;
								} break;
								
								case 2:
								{
											TempCnt = 1;
											for (TempLed = 0; TempLed < 7; TempLed++)
											{
												Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
												Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
												Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 3; TempCnt++)
											{
												for (TempLed = 0; TempLed < 7; TempLed++)
												{
													Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
													Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
													Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
												}
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0] = 0;
								} break;
							}
							
							/* Spot */
							switch (ModeStepSpot[0])
							{
								case 0:
								{
											Grd.Spot[0].DutyR = ColorData[ModeColorSpot[0]][R];
											Grd.Spot[0].DutyG = ColorData[ModeColorSpot[0]][G];
											Grd.Spot[0].DutyB = ColorData[ModeColorSpot[0]][B];
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0]++;
								} break;
								
								case 1:
								{
											Grd.Spot[2].DutyR = ColorData[ModeColorSpot[0]][R];
											Grd.Spot[2].DutyG = ColorData[ModeColorSpot[0]][G];
											Grd.Spot[2].DutyB = ColorData[ModeColorSpot[0]][B];
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0]++;
								} break;
								
								case 2:
								{
											Grd.Spot[1].DutyR = ColorData[ModeColorSpot[0]][R];
											Grd.Spot[1].DutyG = ColorData[ModeColorSpot[0]][G];
											Grd.Spot[1].DutyB = ColorData[ModeColorSpot[0]][B];
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 3; TempCnt++)
											{
												Grd.Spot[TempCnt].DutyR = ColorData[ModeColorSpot[0]][R];
												Grd.Spot[TempCnt].DutyG = ColorData[ModeColorSpot[0]][G];
												Grd.Spot[TempCnt].DutyB = ColorData[ModeColorSpot[0]][B];
											}
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0] = 0;
								} break;
							}
							
							/* Cane */
							switch (ModeStepCane[0])
							{
								case 0:
								{
											TempCnt = 0;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 1:
								{
											TempCnt = 2;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 2:
								{
											TempCnt = 1;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 3:
								{
											TempCnt = 5;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 4:
								{
											TempCnt = 3;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 5:
								{
											TempCnt = 4;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 6; TempCnt++)
											{
												for (TempLed = 0; TempLed < 5; TempLed++)
												{
													Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
													Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
													Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
												}
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0] = 0;
								} break;
							}
							
							/* Ball */
							switch (ModeStepBall)
							{
								case 0:
								case 2:
								{
											for (TempCnt = 0; TempCnt < 4; TempCnt++)
											{
												Grd.Ball[TempCnt].DutyR = ColorData[ModeColorBall][R];
												Grd.Ball[TempCnt].DutyG = ColorData[ModeColorBall][G];
												Grd.Ball[TempCnt].DutyB = ColorData[ModeColorBall][B];
											}
											ModeStepBall++;
								} break;
								
								case 1:
								case 3:
								{
											ModeColorBall++;
											if (ModeColorBall >= ColorNum)		ModeColorBall = 0;
											ModeStepBall++;
								} break;
								
								case 4:
								case 5:
								case 6:
								{
											for (TempCnt = 0; TempCnt < 4; TempCnt++)
											{
												Grd.Ball[TempCnt].DutyR = ColorData[ModeColorBall][R];
												Grd.Ball[TempCnt].DutyG = ColorData[ModeColorBall][G];
												Grd.Ball[TempCnt].DutyB = ColorData[ModeColorBall][B];
											}
											ModeStepBall++;
								} break;
								

								default:
								{
											ModeColorBall++;
											if (ModeColorBall >= ColorNum)		ModeColorBall = 0;
											ModeStepBall = 0;
								} break;
							}
							
							HoldTime++;
							if (HoldTime >= 100)
							{
								HoldTime = 0;
								TempStep++;
							}
						}		
		} break;
		
		default:
		{
						SpeedTime++;
						if (SpeedTime >= 10)
						{
							SpeedTime = 0;
							
							/* Roof10 */
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
							for (TempLed = 29; TempLed > 0; TempLed--)
							{
								Roof30[TempLed].DutyR = Roof30[TempLed - 1].DutyR;
								Roof30[TempLed].DutyG = Roof30[TempLed - 1].DutyG;
								Roof30[TempLed].DutyB = Roof30[TempLed - 1].DutyB;
							}
							Roof30[0].DutyR = TempR;
							Roof30[0].DutyG = TempG;
							Roof30[0].DutyB = TempB;
							
							/* Roof40 */
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
							for (TempLed = 39; TempLed > 0; TempLed--)
							{
								Roof40[TempLed].DutyR = Roof40[TempLed - 1].DutyR;
								Roof40[TempLed].DutyG = Roof40[TempLed - 1].DutyG;
								Roof40[TempLed].DutyB = Roof40[TempLed - 1].DutyB;
							}
							Roof40[0].DutyR = TempR;
							Roof40[0].DutyG = TempG;
							Roof40[0].DutyB = TempB;
							
							/* String30 */
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
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
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
							for (TempLed = 35; TempLed > 0; TempLed--)
							{
								String36[TempLed].DutyR = String36[TempLed - 1].DutyR;
								String36[TempLed].DutyG = String36[TempLed - 1].DutyG;
								String36[TempLed].DutyB = String36[TempLed - 1].DutyB;
							}
							String36[0].DutyR = TempR;
							String36[0].DutyG = TempG;
							String36[0].DutyB = TempB;
							
							RndCnt10++;
							if(RndCnt10 > 12)
							{
								RndCnt10 = 0; 
								TempColor++;
								if (TempColor >= ColorNum)		TempColor = 0;
							}
							
							/* Tree */
							switch (ModeStepTree[0])
							{
								case 0:
								{
											TempCnt = 0;
											for (TempLed = 0; TempLed < 9; TempLed++)
											{
												Grd.Tree[TempLed + TempCnt * 9].DutyR = ColorData[ModeColorTree[0]][R];
												Grd.Tree[TempLed + TempCnt * 9].DutyG = ColorData[ModeColorTree[0]][G];
												Grd.Tree[TempLed + TempCnt * 9].DutyB = ColorData[ModeColorTree[0]][B];
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0]++;
								} break;
								
								case 1:
								{
											TempCnt = 2;
											for (TempLed = 0; TempLed < 9; TempLed++)
											{
												Grd.Tree[TempLed + TempCnt * 9].DutyR = ColorData[ModeColorTree[0]][R];
												Grd.Tree[TempLed + TempCnt * 9].DutyG = ColorData[ModeColorTree[0]][G];
												Grd.Tree[TempLed + TempCnt * 9].DutyB = ColorData[ModeColorTree[0]][B];
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0]++;
								} break;
								
								case 2:
								{
											TempCnt = 1;
											for (TempLed = 0; TempLed < 9; TempLed++)
											{
												Grd.Tree[TempLed + TempCnt * 9].DutyR = ColorData[ModeColorTree[0]][R];
												Grd.Tree[TempLed + TempCnt * 9].DutyG = ColorData[ModeColorTree[0]][G];
												Grd.Tree[TempLed + TempCnt * 9].DutyB = ColorData[ModeColorTree[0]][B];
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 3; TempCnt++)
											{
												for (TempLed = 0; TempLed < 9; TempLed++)
												{
													Grd.Tree[TempCnt * 9 + TempLed].DutyR = ColorData[ModeColorTree[0]][R];
													Grd.Tree[TempCnt * 9 + TempLed].DutyG = ColorData[ModeColorTree[0]][G];
													Grd.Tree[TempCnt * 9 + TempLed].DutyB = ColorData[ModeColorTree[0]][B];
												}
											}
											ModeColorTree[0]++;
											if (ModeColorTree[0] >= ColorNum)		ModeColorTree[0] = 0;
											ModeStepTree[0] = 0;
								} break;
							}
							
							/* Snow */
							switch (ModeStepSnow[0])
							{
								case 0:
								{
											TempCnt = 2;
											for (TempLed = 0; TempLed < 7; TempLed++)
											{
												Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
												Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
												Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0]++;
								} break;
								
								case 1:
								{
											TempCnt = 0;
											for (TempLed = 0; TempLed < 7; TempLed++)
											{
												Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
												Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
												Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0]++;
								} break;
								
								case 2:
								{
											TempCnt = 1;
											for (TempLed = 0; TempLed < 7; TempLed++)
											{
												Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
												Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
												Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 3; TempCnt++)
											{
												for (TempLed = 0; TempLed < 7; TempLed++)
												{
													Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[ModeColorSnow[0]][R];
													Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[ModeColorSnow[0]][G];
													Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[ModeColorSnow[0]][B];
												}
											}
											ModeColorSnow[0]++;
											if (ModeColorSnow[0] >= ColorNum)		ModeColorSnow[0] = 0;
											ModeStepSnow[0] = 0;
								} break;
							}
							
							/* Spot */
							switch (ModeStepSpot[0])
							{
								case 0:
								{
											Grd.Spot[0].DutyR = ColorData[ModeColorSpot[0]][R];
											Grd.Spot[0].DutyG = ColorData[ModeColorSpot[0]][G];
											Grd.Spot[0].DutyB = ColorData[ModeColorSpot[0]][B];
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0]++;
								} break;
								
								case 1:
								{
											Grd.Spot[2].DutyR = ColorData[ModeColorSpot[0]][R];
											Grd.Spot[2].DutyG = ColorData[ModeColorSpot[0]][G];
											Grd.Spot[2].DutyB = ColorData[ModeColorSpot[0]][B];
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0]++;
								} break;
								
								case 2:
								{
											Grd.Spot[1].DutyR = ColorData[ModeColorSpot[0]][R];
											Grd.Spot[1].DutyG = ColorData[ModeColorSpot[0]][G];
											Grd.Spot[1].DutyB = ColorData[ModeColorSpot[0]][B];
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 3; TempCnt++)
											{
												Grd.Spot[TempCnt].DutyR = ColorData[ModeColorSpot[0]][R];
												Grd.Spot[TempCnt].DutyG = ColorData[ModeColorSpot[0]][G];
												Grd.Spot[TempCnt].DutyB = ColorData[ModeColorSpot[0]][B];
											}
											ModeColorSpot[0]++;
											if (ModeColorSpot[0] >= ColorNum)		ModeColorSpot[0] = 0;
											ModeStepSpot[0] = 0;
								} break;
							}
							
							/* Cane */
							switch (ModeStepCane[0])
							{
								case 0:
								{
											TempCnt = 0;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 1:
								{
											TempCnt = 2;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 2:
								{
											TempCnt = 1;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 3:
								{
											TempCnt = 5;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 4:
								{
											TempCnt = 3;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								case 5:
								{
											TempCnt = 4;
											for (TempLed = 0; TempLed < 5; TempLed++)
											{
												Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
												Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
												Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0]++;
								} break;
								
								default:
								{
											for (TempCnt = 0; TempCnt < 6; TempCnt++)
											{
												for (TempLed = 0; TempLed < 5; TempLed++)
												{
													Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[ModeColorCane[0]][R];
													Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[ModeColorCane[0]][G];
													Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[ModeColorCane[0]][B];
												}
											}
											ModeColorCane[0]++;
											if (ModeColorCane[0] >= ColorNum)		ModeColorCane[0] = 0;
											ModeStepCane[0] = 0;
								} break;
							}
							
							/* Ball */
							switch (ModeStepBall)
							{
								case 0:
								case 2:
								{
											for (TempCnt = 0; TempCnt < 4; TempCnt++)
											{
												Grd.Ball[TempCnt].DutyR = ColorData[ModeColorBall][R];
												Grd.Ball[TempCnt].DutyG = ColorData[ModeColorBall][G];
												Grd.Ball[TempCnt].DutyB = ColorData[ModeColorBall][B];
											}
											ModeStepBall++;
								} break;
								
								case 1:
								case 3:
								{
											ModeColorBall++;
											if (ModeColorBall >= ColorNum)		ModeColorBall = 0;
											ModeStepBall++;
								} break;
								
								case 4:
								case 5:
								case 6:
								{
											for (TempCnt = 0; TempCnt < 4; TempCnt++)
											{
												Grd.Ball[TempCnt].DutyR = ColorData[ModeColorBall][R];
												Grd.Ball[TempCnt].DutyG = ColorData[ModeColorBall][G];
												Grd.Ball[TempCnt].DutyB = ColorData[ModeColorBall][B];
											}
											ModeStepBall++;
								} break;

								default:
								{
											ModeColorBall++;
											if (ModeColorBall >= ColorNum)		ModeColorBall = 0;
											ModeStepBall = 0;
								} break;
							}
						}
		} break;
	}
}



/*
 * FunctionName	Show_2_2
 * TimeLine		+= 3720
 */
void Show_2_2(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		TempColor		= 0;
		SpeedTime		= 0;
		TempStep		= 0;
		HoldTime		= 0;
		ModeStep10[0] = 0;
		return;
	}
	
	
	switch (TempStep)
	{
		case 0:
		{
						/* Roof10 */
						for (TempLed = 0; TempLed < 10; TempLed++)
						{
							if (TempLed % 3 == 0)
							{
								Roof10[TempLed].DutyR = ColorData[TempColor][R];
								Roof10[TempLed].DutyG = ColorData[TempColor][G];
								Roof10[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof24 */
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							if (TempLed % 3 == 0)
							{
								Roof24[TempLed].DutyR = ColorData[TempColor][R];
								Roof24[TempLed].DutyG = ColorData[TempColor][G];
								Roof24[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof30 */
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							if (TempLed % 3 == 0)
							{
								Roof30[TempLed].DutyR = ColorData[TempColor][R];
								Roof30[TempLed].DutyG = ColorData[TempColor][G];
								Roof30[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof40 */
						for (TempLed = 0; TempLed < 40; TempLed++)
						{
							if (TempLed % 3 == 0)
							{
								Roof40[TempLed].DutyR = ColorData[TempColor][R];
								Roof40[TempLed].DutyG = ColorData[TempColor][G];
								Roof40[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String30 */
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							if (TempLed % 3 == 0)
							{
								String30[TempLed].DutyR = ColorData[TempColor][R];
								String30[TempLed].DutyG = ColorData[TempColor][G];
								String30[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String24 */
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							if (TempLed % 3 == 0)
							{
								String24[TempLed].DutyR = ColorData[TempColor][R];
								String24[TempLed].DutyG = ColorData[TempColor][G];
								String24[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String36 */
						for (TempLed = 0; TempLed < 36; TempLed++)
						{
							if (TempLed % 3 == 0)
							{
								String36[TempLed].DutyR = ColorData[TempColor][R];
								String36[TempLed].DutyG = ColorData[TempColor][G];
								String36[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Tree */
						TempCnt = 0;
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Grd.Tree[TempCnt * 9 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Tree[TempCnt * 9 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Tree[TempCnt * 9 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Snow */
						TempCnt = 0;
						for (TempLed = 0; TempLed < 7; TempLed++)
						{
							Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Spot */
						Grd.Spot[0].DutyR = ColorData[TempColor][R];
						Grd.Spot[0].DutyG = ColorData[TempColor][G];
						Grd.Spot[0].DutyB = ColorData[TempColor][B];
						
						/* Cane */
						TempCnt = 0;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[TempColor][B];
						}
						TempCnt = 3;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = ColorData[TempColor][R];
							Grd.Ball[TempCnt].DutyG = ColorData[TempColor][G];
							Grd.Ball[TempCnt].DutyB = ColorData[TempColor][B];
						}
						
						HoldTime++;
						if (HoldTime >= 20)
						{
							HoldTime = 0;
							TempColor++;
							if (TempColor >= ColorNum)	TempColor = 0;
							TempStep++;
						}
		} break;
		
		
		case 1:
		{
						/* Roof10 */
						for (TempLed = 0; TempLed < 10; TempLed++)
						{
							if (TempLed % 3 == 1)
							{
								Roof10[TempLed].DutyR = ColorData[TempColor][R];
								Roof10[TempLed].DutyG = ColorData[TempColor][G];
								Roof10[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof24 */
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							if (TempLed % 3 == 1)
							{
								Roof24[TempLed].DutyR = ColorData[TempColor][R];
								Roof24[TempLed].DutyG = ColorData[TempColor][G];
								Roof24[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof30 */
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							if (TempLed % 3 == 1)
							{
								Roof30[TempLed].DutyR = ColorData[TempColor][R];
								Roof30[TempLed].DutyG = ColorData[TempColor][G];
								Roof30[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof40 */
						for (TempLed = 0; TempLed < 40; TempLed++)
						{
							if (TempLed % 3 == 1)
							{
								Roof40[TempLed].DutyR = ColorData[TempColor][R];
								Roof40[TempLed].DutyG = ColorData[TempColor][G];
								Roof40[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String30 */
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							if (TempLed % 3 == 1)
							{
								String30[TempLed].DutyR = ColorData[TempColor][R];
								String30[TempLed].DutyG = ColorData[TempColor][G];
								String30[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String24 */
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							if (TempLed % 3 == 1)
							{
								String24[TempLed].DutyR = ColorData[TempColor][R];
								String24[TempLed].DutyG = ColorData[TempColor][G];
								String24[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String36 */
						for (TempLed = 0; TempLed < 36; TempLed++)
						{
							if (TempLed % 3 == 1)
							{
								String36[TempLed].DutyR = ColorData[TempColor][R];
								String36[TempLed].DutyG = ColorData[TempColor][G];
								String36[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Tree */
						TempCnt = 1;
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Grd.Tree[TempCnt * 9 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Tree[TempCnt * 9 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Tree[TempCnt * 9 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Snow */
						TempCnt = 1;
						for (TempLed = 0; TempLed < 7; TempLed++)
						{
							Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Spot */
						Grd.Spot[1].DutyR = ColorData[TempColor][R];
						Grd.Spot[1].DutyG = ColorData[TempColor][G];
						Grd.Spot[1].DutyB = ColorData[TempColor][B];
						
						/* Cane */
						TempCnt = 1;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[TempColor][B];
						}
						TempCnt = 4;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = ColorData[TempColor][R];
							Grd.Ball[TempCnt].DutyG = ColorData[TempColor][G];
							Grd.Ball[TempCnt].DutyB = ColorData[TempColor][B];
						}
						
						HoldTime++;
						if (HoldTime >= 20)
						{
							HoldTime = 0;
							TempColor++;
							if (TempColor >= ColorNum)	TempColor = 0;
							TempStep++;
						}
		} break;
		
		case 2:
		{
						/* Roof10 */
						for (TempLed = 0; TempLed < 10; TempLed++)
						{
							if (TempLed % 3 == 2)
							{
								Roof10[TempLed].DutyR = ColorData[TempColor][R];
								Roof10[TempLed].DutyG = ColorData[TempColor][G];
								Roof10[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof24 */
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							if (TempLed % 3 == 2)
							{
								Roof24[TempLed].DutyR = ColorData[TempColor][R];
								Roof24[TempLed].DutyG = ColorData[TempColor][G];
								Roof24[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof30 */
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							if (TempLed % 3 == 2)
							{
								Roof30[TempLed].DutyR = ColorData[TempColor][R];
								Roof30[TempLed].DutyG = ColorData[TempColor][G];
								Roof30[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Roof40 */
						for (TempLed = 0; TempLed < 40; TempLed++)
						{
							if (TempLed % 3 == 2)
							{
								Roof40[TempLed].DutyR = ColorData[TempColor][R];
								Roof40[TempLed].DutyG = ColorData[TempColor][G];
								Roof40[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String30 */
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							if (TempLed % 3 == 2)
							{
								String30[TempLed].DutyR = ColorData[TempColor][R];
								String30[TempLed].DutyG = ColorData[TempColor][G];
								String30[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String24 */
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							if (TempLed % 3 == 2)
							{
								String24[TempLed].DutyR = ColorData[TempColor][R];
								String24[TempLed].DutyG = ColorData[TempColor][G];
								String24[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* String36 */
						for (TempLed = 0; TempLed < 36; TempLed++)
						{
							if (TempLed % 3 == 2)
							{
								String36[TempLed].DutyR = ColorData[TempColor][R];
								String36[TempLed].DutyG = ColorData[TempColor][G];
								String36[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						/* Tree */
						TempCnt = 2;
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Grd.Tree[TempCnt * 9 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Tree[TempCnt * 9 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Tree[TempCnt * 9 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Snow */
						TempCnt = 2;
						for (TempLed = 0; TempLed < 7; TempLed++)
						{
							Grd.Snow[TempCnt * 7 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Snow[TempCnt * 7 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Snow[TempCnt * 7 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Spot */
						Grd.Spot[2].DutyR = ColorData[TempColor][R];
						Grd.Spot[2].DutyG = ColorData[TempColor][G];
						Grd.Spot[2].DutyB = ColorData[TempColor][B];
						
						/* Cane */
						TempCnt = 2;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[TempColor][B];
						}
						TempCnt = 5;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = ColorData[TempColor][R];
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = ColorData[TempColor][G];
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = ColorData[TempColor][B];
						}
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = ColorData[TempColor][R];
							Grd.Ball[TempCnt].DutyG = ColorData[TempColor][G];
							Grd.Ball[TempCnt].DutyB = ColorData[TempColor][B];
						}
						
						HoldTime++;
						if (HoldTime >= 20)
						{
							HoldTime = 0;
							TempColor++;
							if (TempColor >= ColorNum)	TempColor = 0;
							TempStep++;
							RndCnt10 = 0;
						}
		} break;
		
		
		
		case 3:
		{	
						SpeedTime++;
						if (SpeedTime >= 2)
						{
							SpeedTime = 0;
							
							
							if (Roof10[0].DutyR > 0 || Roof10[0].DutyG > 0 || Roof10[0].DutyB > 0)
							{
								FadeR = ColorData[0 + ModeStep10[0]][R] / 25;
								FadeG = ColorData[0 + ModeStep10[0]][G] / 25;
								FadeB = ColorData[0 + ModeStep10[0]][B] / 25;
								
								/* Roof10*/
								for (TempLed = 0; TempLed < 10; TempLed++)
								{
									if (TempLed % 3 == 0)
									{
										Roof10[TempLed].DutyR -= FadeR;
										Roof10[TempLed].DutyG -= FadeG;
										Roof10[TempLed].DutyB -= FadeB; 
									}
								}
								
								/* Roof24*/
								for (TempLed = 0; TempLed < 24; TempLed++)
								{
									if (TempLed % 3 == 0)
									{
										Roof24[TempLed].DutyR -= FadeR;
										Roof24[TempLed].DutyG -= FadeG;
										Roof24[TempLed].DutyB -= FadeB; 
									}
								}
								
								/* Roof30*/
								for (TempLed = 0; TempLed < 30; TempLed++)
								{
									if (TempLed % 3 == 0)
									{
										Roof30[TempLed].DutyR -= FadeR;
										Roof30[TempLed].DutyG -= FadeG;
										Roof30[TempLed].DutyB -= FadeB; 
									}
								}
								
								/* Roof40*/
								for (TempLed = 0; TempLed < 40; TempLed++)
								{
									if (TempLed % 3 == 0)
									{
										Roof40[TempLed].DutyR -= FadeR;
										Roof40[TempLed].DutyG -= FadeG;
										Roof40[TempLed].DutyB -= FadeB; 
									}
								}
								
								/* String30*/
								for (TempLed = 0; TempLed < 30; TempLed++)
								{
									if (TempLed % 3 == 0)
									{
										String30[TempLed].DutyR -= FadeR;
										String30[TempLed].DutyG -= FadeG;
										String30[TempLed].DutyB -= FadeB; 
									}
								}
								
								/* String24*/
								for (TempLed = 0; TempLed < 24; TempLed++)
								{
									if (TempLed % 3 == 0)
									{
										String24[TempLed].DutyR -= FadeR;
										String24[TempLed].DutyG -= FadeG;
										String24[TempLed].DutyB -= FadeB; 
									}
								}
								
								/* String36*/
								for (TempLed = 0; TempLed < 36; TempLed++)
								{
									if (TempLed % 3 == 0)
									{
										String36[TempLed].DutyR -= FadeR;
										String36[TempLed].DutyG -= FadeG;
										String36[TempLed].DutyB -= FadeB; 
									}
								}
								
								/* Tree */
								TempCnt = 0;
								for (TempLed = 0; TempLed < 9; TempLed++)
								{
									Grd.Tree[TempCnt * 9 + TempLed].DutyR -= FadeR;
									Grd.Tree[TempCnt * 9 + TempLed].DutyG -= FadeG;
									Grd.Tree[TempCnt * 9 + TempLed].DutyB -= FadeB;
								}
								
								/* Snow */
								TempCnt = 0;
								for (TempLed = 0; TempLed < 7; TempLed++)
								{
									Grd.Snow[TempCnt * 7 + TempLed].DutyR -= FadeR;
									Grd.Snow[TempCnt * 7 + TempLed].DutyG -= FadeG;
									Grd.Snow[TempCnt * 7 + TempLed].DutyB -= FadeB;
								}
								
								/* Spot */
								Grd.Spot[0].DutyR -= FadeR;
								Grd.Spot[0].DutyG -= FadeG;
								Grd.Spot[0].DutyB -= FadeB;
								
								/* Cane */
								TempCnt = 0;
								for (TempLed = 0; TempLed < 5; TempLed++)
								{
									Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
									Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
									Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
								}
								TempCnt = 3;
								for (TempLed = 0; TempLed < 5; TempLed++)
								{
									Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
									Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
									Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
								}
							}

							
							if (RndCnt10 >= 15)
							{
								if (Roof10[1].DutyR > 0 || Roof10[1].DutyG > 0 || Roof10[1].DutyB > 0)
								{
									FadeR = ColorData[1 + ModeStep10[0]][R] / 25;
									FadeG = ColorData[1 + ModeStep10[0]][G] / 25;
									FadeB = ColorData[1 + ModeStep10[0]][B] / 25;
									
									/* Roof10*/
									for (TempLed = 0; TempLed < 10; TempLed++)
									{
										if (TempLed % 3 == 1)
										{
											Roof10[TempLed].DutyR -= FadeR;
											Roof10[TempLed].DutyG -= FadeG;
											Roof10[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Roof24*/
									for (TempLed = 0; TempLed < 24; TempLed++)
									{
										if (TempLed % 3 == 1)
										{
											Roof24[TempLed].DutyR -= FadeR;
											Roof24[TempLed].DutyG -= FadeG;
											Roof24[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Roof30*/
									for (TempLed = 0; TempLed < 30; TempLed++)
									{
										if (TempLed % 3 == 1)
										{
											Roof30[TempLed].DutyR -= FadeR;
											Roof30[TempLed].DutyG -= FadeG;
											Roof30[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Roof40*/
									for (TempLed = 0; TempLed < 40; TempLed++)
									{
										if (TempLed % 3 == 1)
										{
											Roof40[TempLed].DutyR -= FadeR;
											Roof40[TempLed].DutyG -= FadeG;
											Roof40[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* String30*/
									for (TempLed = 0; TempLed < 30; TempLed++)
									{
										if (TempLed % 3 == 1)
										{
											String30[TempLed].DutyR -= FadeR;
											String30[TempLed].DutyG -= FadeG;
											String30[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* String24*/
									for (TempLed = 0; TempLed < 24; TempLed++)
									{
										if (TempLed % 3 == 1)
										{
											String24[TempLed].DutyR -= FadeR;
											String24[TempLed].DutyG -= FadeG;
											String24[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* String36*/
									for (TempLed = 0; TempLed < 36; TempLed++)
									{
										if (TempLed % 3 == 1)
										{
											String36[TempLed].DutyR -= FadeR;
											String36[TempLed].DutyG -= FadeG;
											String36[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Tree */
									TempCnt = 1;
									for (TempLed = 0; TempLed < 9; TempLed++)
									{
										Grd.Tree[TempCnt * 9 + TempLed].DutyR -= FadeR;
										Grd.Tree[TempCnt * 9 + TempLed].DutyG -= FadeG;
										Grd.Tree[TempCnt * 9 + TempLed].DutyB -= FadeB;
									}
									
									/* Snow */
									TempCnt = 1;
									for (TempLed = 0; TempLed < 7; TempLed++)
									{
										Grd.Snow[TempCnt * 7 + TempLed].DutyR -= FadeR;
										Grd.Snow[TempCnt * 7 + TempLed].DutyG -= FadeG;
										Grd.Snow[TempCnt * 7 + TempLed].DutyB -= FadeB;
									}
									
									/* Spot */
									Grd.Spot[1].DutyR -= FadeR;
									Grd.Spot[1].DutyG -= FadeG;
									Grd.Spot[1].DutyB -= FadeB;
									
									/* Cane */
									TempCnt = 1;
									for (TempLed = 0; TempLed < 5; TempLed++)
									{
										Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
										Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
										Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
									}
									TempCnt = 4;
									for (TempLed = 0; TempLed < 5; TempLed++)
									{
										Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
										Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
										Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
									}
								}
							}
							
							if (RndCnt10 >= 30)
							{
								if (Roof10[2].DutyR > 0 || Roof10[2].DutyG > 0 || Roof10[2].DutyB > 0)
								{
									FadeR = ColorData[2 + ModeStep10[0]][R] / 25;
									FadeG = ColorData[2 + ModeStep10[0]][G] / 25;
									FadeB = ColorData[2 + ModeStep10[0]][B] / 25;
									
									/* Roof10*/
									for (TempLed = 0; TempLed < 10; TempLed++)
									{
										if (TempLed % 3 == 2)
										{
											Roof10[TempLed].DutyR -= FadeR;
											Roof10[TempLed].DutyG -= FadeG;
											Roof10[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Roof24*/
									for (TempLed = 0; TempLed < 24; TempLed++)
									{
										if (TempLed % 3 == 2)
										{
											Roof24[TempLed].DutyR -= FadeR;
											Roof24[TempLed].DutyG -= FadeG;
											Roof24[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Roof30*/
									for (TempLed = 0; TempLed < 30; TempLed++)
									{
										if (TempLed % 3 == 2)
										{
											Roof30[TempLed].DutyR -= FadeR;
											Roof30[TempLed].DutyG -= FadeG;
											Roof30[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Roof40*/
									for (TempLed = 0; TempLed < 40; TempLed++)
									{
										if (TempLed % 3 == 2)
										{
											Roof40[TempLed].DutyR -= FadeR;
											Roof40[TempLed].DutyG -= FadeG;
											Roof40[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* String30*/
									for (TempLed = 0; TempLed < 30; TempLed++)
									{
										if (TempLed % 3 == 2)
										{
											String30[TempLed].DutyR -= FadeR;
											String30[TempLed].DutyG -= FadeG;
											String30[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* String24*/
									for (TempLed = 0; TempLed < 24; TempLed++)
									{
										if (TempLed % 3 == 2)
										{
											String24[TempLed].DutyR -= FadeR;
											String24[TempLed].DutyG -= FadeG;
											String24[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* String36*/
									for (TempLed = 0; TempLed < 36; TempLed++)
									{
										if (TempLed % 3 == 2)
										{
											String36[TempLed].DutyR -= FadeR;
											String36[TempLed].DutyG -= FadeG;
											String36[TempLed].DutyB -= FadeB; 
										}
									}
									
									/* Tree */
									TempCnt = 2;
									for (TempLed = 0; TempLed < 9; TempLed++)
									{
										Grd.Tree[TempCnt * 9 + TempLed].DutyR -= FadeR;
										Grd.Tree[TempCnt * 9 + TempLed].DutyG -= FadeG;
										Grd.Tree[TempCnt * 9 + TempLed].DutyB -= FadeB;
									}
									
									/* Snow */
									TempCnt = 2;
									for (TempLed = 0; TempLed < 7; TempLed++)
									{
										Grd.Snow[TempCnt * 7 + TempLed].DutyR -= FadeR;
										Grd.Snow[TempCnt * 7 + TempLed].DutyG -= FadeG;
										Grd.Snow[TempCnt * 7 + TempLed].DutyB -= FadeB;
									}
									
									/* Spot */
									Grd.Spot[2].DutyR -= FadeR;
									Grd.Spot[2].DutyG -= FadeG;
									Grd.Spot[2].DutyB -= FadeB;
									
									/* Cane */
									TempCnt = 2;
									for (TempLed = 0; TempLed < 5; TempLed++)
									{
										Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
										Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
										Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
									}
									TempCnt = 5;
									for (TempLed = 0; TempLed < 5; TempLed++)
									{
										Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
										Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
										Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
									}
									
									/* Ball */
									for (TempCnt = 0; TempCnt < 4; TempCnt++)
									{
										Grd.Ball[TempCnt].DutyR -= FadeR;
										Grd.Ball[TempCnt].DutyG -= FadeG;
										Grd.Ball[TempCnt].DutyB -= FadeB;
									}
								}
								else
								{
									TempStep = 0;
									ModeStep10[0] += 3;
									if (ModeStep10[0] >= 9)		TempStep = 4;
									RndCnt10 = 0;
								}
							}
							
							if (RndCnt10 < 31)		RndCnt10++;
						}
		} break;
		
		default:
		{
						TempStep = 5;
		} break;
	}
}

/*
 * FunctionName		Show_2_3
 * Duration				TimeLine += 1030 
 */
void Show_2_3(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		TempColor		= 0;
		SpeedTime		= 0;
		TempStep		= 0;
		RndCnt10		= 0;
		KeepTime		= 0;
		
		TempR = 0;
		TempG = 0;
		TempB = 0;
		
		FadeR = ColorData[TempColor][R] / 25;
		FadeG = ColorData[TempColor][G] / 25;
		FadeB = ColorData[TempColor][B] / 25;
		
		KeepTime = 0;
		return;
	}
	
	
	switch (TempStep)
	{
		case 0:
		{
						TempR += FadeR;
						TempG += FadeG;
						TempB += FadeB;
						All_Color(TempR, TempG, TempB);
						RndCnt10++;
						if (RndCnt10 >= 25)  
						{
							TempStep++;
							FadeR = ColorData[TempColor][R] / 25;
							FadeG = ColorData[TempColor][G] / 25;
							FadeB = ColorData[TempColor][B] / 25;
							RndCnt10 = 0;
							RndCnt24 = 0;
							RndCnt30 = 0;
							RndCnt40 = 0;
							RndCnts30 = 0;
							RndCnts24 = 0;
							RndCnts36 = 0;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
							RndCntSpot = 0;
							RndCntBall = 0;
							
							for (TempLed = 0; TempLed < 10; TempLed++)
							{
								ModeLed10[TempLed] = 0;
								RAND();
								HoldTime10[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								ModeLed24[TempLed] = 0;
								RAND();
								HoldTime24[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								ModeLed30[TempLed] = 0;
								RAND();
								HoldTime30[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 40; TempLed++)
							{
								ModeLed40[TempLed] = 0;
								RAND();
								HoldTime40[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								ModeLeds30[TempLed] = 0;
								RAND();
								HoldTimes30[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								ModeLeds24[TempLed] = 0;
								RAND();
								HoldTimes24[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 36; TempLed++)
							{
								ModeLeds36[TempLed] = 0;
								RAND();
								HoldTimes36[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								ModeLedTree[TempLed] = 0;
								RAND();
								HoldTimeTree[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								ModeLedSnow[TempLed] = 0;
								RAND();
								HoldTimeSnow[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								ModeLedSpot[TempLed] = 0;
								RAND();
								HoldTimeSpot[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								ModeLedCane[TempLed] = 0;
								RAND();
								HoldTimeCane[TempLed] = (_Uint8)rand() % 10;
							}
							
							RAND();
							HoldTimeBall = (_Uint8)rand() % 10;
						}
		} break;
		
		
		case 1:
		{
						/* Roof10 */
						if (RndCnt10 < 10)
						{
							for (TempLed = 0; TempLed < 10; TempLed++)
							{
								if (ModeLed10[TempLed] == 1) continue;
								
								ModeTime10[TempLed]++;
								if (ModeTime10[TempLed] >= HoldTime10[TempLed])
								{
									ModeTime10[TempLed] = 0;
									Roof10[TempLed].DutyR -= FadeR;
									Roof10[TempLed].DutyG -= FadeG;
									Roof10[TempLed].DutyB -= FadeB;
								}
								
								if (Roof10[TempLed].DutyR == 0 && Roof10[TempLed].DutyG == 0 && Roof10[TempLed].DutyB == 0)
								{
									RndCnt10++;
									ModeLed10[TempLed] = 1;
								}
							}
						}
						
						/* Roof24 */
						if (RndCnt24 < 24)
						{
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								if (ModeLed24[TempLed] == 1) continue;
								
								ModeTime24[TempLed]++;
								if (ModeTime24[TempLed] >= HoldTime24[TempLed])
								{
									ModeTime24[TempLed] = 0;
									Roof24[TempLed].DutyR -= FadeR;
									Roof24[TempLed].DutyG -= FadeG;
									Roof24[TempLed].DutyB -= FadeB;
								}
								
								if (Roof24[TempLed].DutyR == 0 && Roof24[TempLed].DutyG == 0 && Roof24[TempLed].DutyB == 0)
								{
									RndCnt24++;
									ModeLed24[TempLed] = 1;
								}
							}
						}
						
						/* Roof30 */
						if (RndCnt30 < 30)
						{
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								if (ModeLed30[TempLed] == 1) continue;
								
								ModeTime30[TempLed]++;
								if (ModeTime30[TempLed] >= HoldTime30[TempLed])
								{
									ModeTime30[TempLed] = 0;
									Roof30[TempLed].DutyR -= FadeR;
									Roof30[TempLed].DutyG -= FadeG;
									Roof30[TempLed].DutyB -= FadeB;
								}
								
								if (Roof30[TempLed].DutyR == 0 && Roof30[TempLed].DutyG == 0 && Roof30[TempLed].DutyB == 0)
								{
									RndCnt30++;
									ModeLed30[TempLed] = 1;
								}
							}
						}
						
						/* Roof40 */
						if (RndCnt40 < 40)
						{
							for (TempLed = 0; TempLed < 40; TempLed++)
							{
								if (ModeLed40[TempLed] == 1) continue;
								
								ModeTime40[TempLed]++;
								if (ModeTime40[TempLed] >= HoldTime40[TempLed])
								{
									ModeTime40[TempLed] = 0;
									Roof40[TempLed].DutyR -= FadeR;
									Roof40[TempLed].DutyG -= FadeG;
									Roof40[TempLed].DutyB -= FadeB;
								}
								
								if (Roof40[TempLed].DutyR == 0 && Roof40[TempLed].DutyG == 0 && Roof40[TempLed].DutyB == 0)
								{
									RndCnt40++;
									ModeLed40[TempLed] = 1;
								}
							}
						}
						
						/* String30 */
						if (RndCnts30 < 30)
						{
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								if (ModeLeds30[TempLed] == 1) continue;
								
								ModeTimes30[TempLed]++;
								if (ModeTimes30[TempLed] >= HoldTimes30[TempLed])
								{
									ModeTimes30[TempLed] = 0;
									String30[TempLed].DutyR -= FadeR;
									String30[TempLed].DutyG -= FadeG;
									String30[TempLed].DutyB -= FadeB;
								}
								
								if (String30[TempLed].DutyR == 0 && String30[TempLed].DutyG == 0 && String30[TempLed].DutyB == 0)
								{
									RndCnts30++;
									ModeLeds30[TempLed] = 1;
								}
							}
						}
						
						
						/* String24 */
						if (RndCnts24 < 24)
						{
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								if (ModeLeds24[TempLed] == 1) continue;
								
								ModeTimes24[TempLed]++;
								if (ModeTimes24[TempLed] >= HoldTimes24[TempLed])
								{
									ModeTimes24[TempLed] = 0;
									String24[TempLed].DutyR -= FadeR;
									String24[TempLed].DutyG -= FadeG;
									String24[TempLed].DutyB -= FadeB;
								}
								
								if (String24[TempLed].DutyR == 0 && String24[TempLed].DutyG == 0 && String24[TempLed].DutyB == 0)
								{
									RndCnts24++;
									ModeLeds24[TempLed] = 1;
								}
							}
						}
						
						/* String36 */
						if (RndCnts36 < 36)
						{
							for (TempLed = 0; TempLed < 36; TempLed++)
							{
								if (ModeLeds36[TempLed] == 1) continue;
								
								ModeTimes36[TempLed]++;
								if (ModeTimes36[TempLed] >= HoldTimes36[TempLed])
								{
									ModeTimes36[TempLed] = 0;
									String36[TempLed].DutyR -= FadeR;
									String36[TempLed].DutyG -= FadeG;
									String36[TempLed].DutyB -= FadeB;
								}
								
								if (String36[TempLed].DutyR == 0 && String36[TempLed].DutyG == 0 && String36[TempLed].DutyB == 0)
								{
									RndCnts36++;
									ModeLeds36[TempLed] = 1;
								}
							}
						}
						
						/* Tree */
						if (RndCntTree < 3)
						{
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								if (ModeLedTree[TempLed] == 1) continue;
								
								ModeTimeTree[TempLed]++;
								if (ModeTimeTree[TempLed] >= HoldTimeTree[TempLed])
								{
									ModeTimeTree[TempLed] = 0;
									for (TempCnt = 0; TempCnt < 9; TempCnt++)
									{
										Grd.Tree[TempCnt + TempLed * 9].DutyR -= FadeR;
										Grd.Tree[TempCnt + TempLed * 9].DutyG -= FadeG;
										Grd.Tree[TempCnt + TempLed * 9].DutyB -= FadeB;
									}
								}
								
								if (Grd.Tree[TempLed * 9].DutyR == 0 && Grd.Tree[TempLed * 9].DutyG == 0 && Grd.Tree[TempLed * 9].DutyB == 0)
								{
									RndCntTree++;
									ModeLedTree[TempLed] = 1;
								}
							}
						}
						
						/* Snow */
						if (RndCntSnow < 3)
						{
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								if (ModeLedSnow[TempLed] == 1) continue;
								
								ModeTimeSnow[TempLed]++;
								if (ModeTimeSnow[TempLed] >= HoldTimeSnow[TempLed])
								{
									ModeTimeSnow[TempLed] = 0;
									for (TempCnt = 0; TempCnt < 7; TempCnt++)
									{
										Grd.Snow[TempLed * 7 + TempCnt].DutyR -= FadeR;
										Grd.Snow[TempLed * 7 + TempCnt].DutyG -= FadeG;
										Grd.Snow[TempLed * 7 + TempCnt].DutyB -= FadeB;
									}
								}
								
								if (Grd.Snow[TempLed * 7].DutyR == 0 && Grd.Snow[TempLed * 7].DutyG == 0 && Grd.Snow[TempLed * 7].DutyB == 0)
								{
									RndCntSnow++;
									ModeLedSnow[TempLed] = 1;
								}
							}
						}
						
						/* Spot */
						if (RndCntSpot < 3)
						{
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								if (ModeLedSpot[TempLed] == 1) continue;
								
								ModeTimeSpot[TempLed]++;
								if (ModeTimeSpot[TempLed] >= HoldTimeSpot[TempLed])
								{
									ModeTimeSpot[TempLed] = 0;
									Grd.Spot[TempLed].DutyR -= FadeR;
									Grd.Spot[TempLed].DutyG -= FadeG;
									Grd.Spot[TempLed].DutyB -= FadeB;
								}
								
								if (Grd.Spot[TempLed].DutyR == 0 && Grd.Spot[TempLed].DutyG == 0 && Grd.Spot[TempLed].DutyB == 0)
								{
									RndCntSpot++;
									ModeLedSpot[TempLed] = 1;
								}
							}
						}
						
						/* Cane */
						if (RndCntCane < 6)
						{
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								if (ModeLedCane[TempLed] == 1) continue;
								
								ModeTimeCane[TempLed]++;
								if (ModeTimeCane[TempLed] >= HoldTimeCane[TempLed])
								{
									ModeTimeCane[TempLed] = 0;
									for (TempCnt = 0; TempCnt < 5; TempCnt++)
									{
										Grd.Cane[TempCnt + TempLed * 5].DutyR -= FadeR;
										Grd.Cane[TempCnt + TempLed * 5].DutyG -= FadeG;
										Grd.Cane[TempCnt + TempLed * 5].DutyB -= FadeB;
									}
								}
								
								if (Grd.Cane[TempLed * 5].DutyR == 0 && Grd.Cane[TempLed * 5].DutyG == 0 && Grd.Cane[TempLed * 5].DutyB == 0)
								{
									RndCntCane++;
									ModeLedCane[TempLed] = 1;
								}
							}
						}
						
						/* Ball */
						if (Grd.Ball[0].DutyR > 0 || Grd.Ball[0].DutyG > 0 || Grd.Ball[0].DutyB > 0)
						{
							for (TempCnt = 0; TempCnt < 4; TempCnt++)
							{
								Grd.Ball[TempCnt].DutyR -= FadeR;
								Grd.Ball[TempCnt].DutyG -= FadeG;
								Grd.Ball[TempCnt].DutyB -= FadeB;
							}
						}
						

						if (RndCnt40 >= 40)
						{
							TempStep++;
							TempColor++;
							if (TempColor >= ColorNum)		TempColor = 0;
							FadeR = ColorData[TempColor][R] / 25;
							FadeG = ColorData[TempColor][G] / 25;
							FadeB = ColorData[TempColor][B] / 25;
							RndCnt10 = 0;
							RndCnt24 = 0;
							RndCnt30 = 0;
							RndCnt40 = 0;
							RndCnts30 = 0;
							RndCnts24 = 0;
							RndCnts36 = 0;
							RndCntTree = 0;
							RndCntSnow = 0;
							RndCntCane = 0;
							RndCntSpot = 0;
							RndCntBall = 0;
							
							for (TempLed = 0; TempLed < 10; TempLed++)
							{
								ModeLed10[TempLed] = 0;
								RAND();
								HoldTime10[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								ModeLed24[TempLed] = 0;
								RAND();
								HoldTime24[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								ModeLed30[TempLed] = 0;
								RAND();
								HoldTime30[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 40; TempLed++)
							{
								ModeLed40[TempLed] = 0;
								RAND();
								HoldTime40[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								ModeLeds30[TempLed] = 0;
								RAND();
								HoldTimes30[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								ModeLeds24[TempLed] = 0;
								RAND();
								HoldTimes24[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 36; TempLed++)
							{
								ModeLeds36[TempLed] = 0;
								RAND();
								HoldTimes36[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								ModeLedTree[TempLed] = 0;
								RAND();
								HoldTimeTree[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								ModeLedSnow[TempLed] = 0;
								RAND();
								HoldTimeSnow[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								ModeLedSpot[TempLed] = 0;
								RAND();
								HoldTimeSpot[TempLed] = (_Uint8)rand() % 10;
							}
							
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								ModeLedCane[TempLed] = 0;
								RAND();
								HoldTimeCane[TempLed] = (_Uint8)rand() % 10;
							}
							
							RAND();
							HoldTimeBall = (_Uint8)rand() % 10;
						}
		} break;
		
		case 2:
		{
						/* Roof10 */
						if (RndCnt10 < 10)
						{
							for (TempLed = 0; TempLed < 10; TempLed++)
							{
								if (ModeLed10[TempLed] == 1) continue;
								
								ModeTime10[TempLed]++;
								if (ModeTime10[TempLed] >= HoldTime10[TempLed])
								{
									ModeTime10[TempLed] = 0;
									Roof10[TempLed].DutyR += FadeR;
									Roof10[TempLed].DutyG += FadeG;
									Roof10[TempLed].DutyB += FadeB;
								}
								
								if (Roof10[TempLed].DutyR == ColorData[TempColor][R] && Roof10[TempLed].DutyG == ColorData[TempColor][G] && Roof10[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCnt10++;
									ModeLed10[TempLed] = 1;
								}
							}
						}
						
						/* Roof24 */
						if (RndCnt24 < 24)
						{
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								if (ModeLed24[TempLed] == 1) continue;
								
								ModeTime24[TempLed]++;
								if (ModeTime24[TempLed] >= HoldTime24[TempLed])
								{
									ModeTime24[TempLed] = 0;
									Roof24[TempLed].DutyR += FadeR;
									Roof24[TempLed].DutyG += FadeG;
									Roof24[TempLed].DutyB += FadeB;
								}
								
								if (Roof24[TempLed].DutyR == ColorData[TempColor][R] && Roof24[TempLed].DutyG == ColorData[TempColor][G] && Roof24[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCnt24++;
									ModeLed24[TempLed] = 1;
								}
							}
						}
						
						/* Roof30 */
						if (RndCnt30 < 30)
						{
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								if (ModeLed30[TempLed] == 1) continue;
								
								ModeTime30[TempLed]++;
								if (ModeTime30[TempLed] >= HoldTime30[TempLed])
								{
									ModeTime30[TempLed] = 0;
									Roof30[TempLed].DutyR += FadeR;
									Roof30[TempLed].DutyG += FadeG;
									Roof30[TempLed].DutyB += FadeB;
								}
								
								if (Roof30[TempLed].DutyR == ColorData[TempColor][R] && Roof30[TempLed].DutyG == ColorData[TempColor][G] && Roof30[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCnt30++;
									ModeLed30[TempLed] = 1;
								}
							}
						}
						
						/* Roof40 */
						if (RndCnt40 < 40)
						{
							for (TempLed = 0; TempLed < 40; TempLed++)
							{
								if (ModeLed40[TempLed] == 1) continue;
								
								ModeTime40[TempLed]++;
								if (ModeTime40[TempLed] >= HoldTime40[TempLed])
								{
									ModeTime40[TempLed] = 0;
									Roof40[TempLed].DutyR += FadeR;
									Roof40[TempLed].DutyG += FadeG;
									Roof40[TempLed].DutyB += FadeB;
								}
								
								if (Roof40[TempLed].DutyR == ColorData[TempColor][R] && Roof40[TempLed].DutyG == ColorData[TempColor][G] && Roof40[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCnt40++;
									ModeLed40[TempLed] = 1;
								}
							}
						}
						
						/* String30 */
						if (RndCnts30 < 30)
						{
							for (TempLed = 0; TempLed < 30; TempLed++)
							{
								if (ModeLeds30[TempLed] == 1) continue;
								
								ModeTimes30[TempLed]++;
								if (ModeTimes30[TempLed] >= HoldTimes30[TempLed])
								{
									ModeTimes30[TempLed] = 0;
									String30[TempLed].DutyR += FadeR;
									String30[TempLed].DutyG += FadeG;
									String30[TempLed].DutyB += FadeB;
								}
								
								if (String30[TempLed].DutyR == ColorData[TempColor][R] && String30[TempLed].DutyG == ColorData[TempColor][G] && String30[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCnts30++;
									ModeLeds30[TempLed] = 1;
								}
							}
						}
						
						/* String24 */
						if (RndCnts24 < 24)
						{
							for (TempLed = 0; TempLed < 24; TempLed++)
							{
								if (ModeLeds24[TempLed] == 1) continue;
								
								ModeTimes24[TempLed]++;
								if (ModeTimes24[TempLed] >= HoldTimes24[TempLed])
								{
									ModeTimes24[TempLed] = 0;
									String24[TempLed].DutyR += FadeR;
									String24[TempLed].DutyG += FadeG;
									String24[TempLed].DutyB += FadeB;
								}
								
								if (String24[TempLed].DutyR == ColorData[TempColor][R] && String24[TempLed].DutyG == ColorData[TempColor][G] && String24[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCnts24++;
									ModeLeds24[TempLed] = 1;
								}
							}
						}
						
						/* String36 */
						if (RndCnts36 < 36)
						{
							for (TempLed = 0; TempLed < 36; TempLed++)
							{
								if (ModeLeds36[TempLed] == 1) continue;
								
								ModeTimes36[TempLed]++;
								if (ModeTimes36[TempLed] >= HoldTimes36[TempLed])
								{
									ModeTimes36[TempLed] = 0;
									String36[TempLed].DutyR += FadeR;
									String36[TempLed].DutyG += FadeG;
									String36[TempLed].DutyB += FadeB;
								}
								
								if (String36[TempLed].DutyR == ColorData[TempColor][R] && String36[TempLed].DutyG == ColorData[TempColor][G] && String36[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCnts36++;
									ModeLeds36[TempLed] = 1;
								}
							}
						}
						
						/* Tree */
						if (RndCntTree < 3)
						{
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								if (ModeLedTree[TempLed] == 1) continue;
								
								ModeTimeTree[TempLed]++;
								if (ModeTimeTree[TempLed] >= HoldTimeTree[TempLed])
								{
									ModeTimeTree[TempLed] = 0;
									for (TempCnt = 0; TempCnt < 9; TempCnt++)
									{
										Grd.Tree[TempCnt + TempLed * 9].DutyR += FadeR;
										Grd.Tree[TempCnt + TempLed * 9].DutyG += FadeG;
										Grd.Tree[TempCnt + TempLed * 9].DutyB += FadeB;
									}
								}
								
								if (Grd.Tree[TempLed * 9].DutyR == ColorData[TempColor][R] && Grd.Tree[TempLed * 9].DutyG == ColorData[TempColor][G] && Grd.Tree[TempLed * 9].DutyB == ColorData[TempColor][B])
								{
									RndCntTree++;
									ModeLedTree[TempLed] = 1;
								}
							}
						}
						
						/* Snow */
						if (RndCntSnow < 3)
						{
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								if (ModeLedSnow[TempLed] == 1) continue;
								
								ModeTimeSnow[TempLed]++;
								if (ModeTimeSnow[TempLed] >= HoldTimeSnow[TempLed])
								{
									ModeTimeSnow[TempLed] = 0;
									for (TempCnt = 0; TempCnt < 7; TempCnt++)
									{
										Grd.Snow[TempLed * 7 + TempCnt].DutyR += FadeR;
										Grd.Snow[TempLed * 7 + TempCnt].DutyG += FadeG;
										Grd.Snow[TempLed * 7 + TempCnt].DutyB += FadeB;
									}
								}
								
								if (Grd.Snow[TempLed * 7].DutyR == ColorData[TempColor][R] && Grd.Snow[TempLed * 7].DutyG == ColorData[TempColor][G] && Grd.Snow[TempLed * 7].DutyB == ColorData[TempColor][B])
								{
									RndCntSnow++;
									ModeLedSnow[TempLed] = 1;
								}
							}
						}
						
						/* Spot */
						if (RndCntSpot < 3)
						{
							for (TempLed = 0; TempLed < 3; TempLed++)
							{
								if (ModeLedSpot[TempLed] == 1) continue;
								
								ModeTimeSpot[TempLed]++;
								if (ModeTimeSpot[TempLed] >= HoldTimeSpot[TempLed])
								{
									ModeTimeSpot[TempLed] = 0;
									Grd.Spot[TempLed].DutyR += FadeR;
									Grd.Spot[TempLed].DutyG += FadeG;
									Grd.Spot[TempLed].DutyB += FadeB;
								}
								
								if (Grd.Spot[TempLed].DutyR == ColorData[TempColor][R] && Grd.Spot[TempLed].DutyG == ColorData[TempColor][G] && Grd.Spot[TempLed].DutyB == ColorData[TempColor][B])
								{
									RndCntSpot++;
									ModeLedSpot[TempLed] = 1;
								}
							}
						}
						
						/* Cane */
						if (RndCntCane < 6)
						{
							for (TempLed = 0; TempLed < 6; TempLed++)
							{
								if (ModeLedCane[TempLed] == 1) continue;
								
								ModeTimeCane[TempLed]++;
								if (ModeTimeCane[TempLed] >= HoldTimeCane[TempLed])
								{
									ModeTimeCane[TempLed] = 0;
									for (TempCnt = 0; TempCnt < 5; TempCnt++)
									{
										Grd.Cane[TempLed * 5 + TempCnt].DutyR += FadeR;
										Grd.Cane[TempLed * 5 + TempCnt].DutyG += FadeG;
										Grd.Cane[TempLed * 5 + TempCnt].DutyB += FadeB;
									}
								}
								
								if (Grd.Cane[TempLed * 5].DutyR == ColorData[TempColor][R] && Grd.Cane[TempLed * 5].DutyG == ColorData[TempColor][G] && Grd.Cane[TempLed * 5].DutyB == ColorData[TempColor][B])
								{
									RndCntCane++;
									ModeLedCane[TempLed] = 1;
								}
							}
						}
						
						/* Ball */
						if (Grd.Ball[0].DutyR < ColorData[TempColor][R] || Grd.Ball[0].DutyG < ColorData[TempColor][G] || Grd.Ball[0].DutyB < ColorData[TempColor][B])
						{
							for (TempCnt = 0; TempCnt < 4; TempCnt++)
							{
								Grd.Ball[TempCnt].DutyR += FadeR;
								Grd.Ball[TempCnt].DutyG += FadeG;
								Grd.Ball[TempCnt].DutyB += FadeB;
							}
						}
						
						
						
						if (RndCnt40 >= 40)
						{
							TempStep++;
							FadeR = ColorData[TempColor][R] / 25;
							FadeG = ColorData[TempColor][G] / 25;
							FadeB = ColorData[TempColor][B] / 25;
							RndCnt10 = 0;
							TempR = ColorData[TempColor][R];
							TempG = ColorData[TempColor][G];
							TempB = ColorData[TempColor][B];
						}
		} break;
		
		
		
		case 3:
		{	
						TempR -= FadeR;
						TempG -= FadeG;
						TempB -= FadeB;
						All_Color(TempR, TempG, TempB);
						RndCnt10++;
						if (RndCnt10 >= 25)  
						{
							RndCnt10 = 0;
							TempR = 0;
							TempG = 0;
							TempB = 0;
							TempStep = 0;
							TempColor++;
							if (TempColor >= ColorNum) TempColor = 0;
							
							FadeR = ColorData[TempColor][R] / 25;
							FadeG = ColorData[TempColor][G] / 25;
							FadeB = ColorData[TempColor][B] / 25;
							
							KeepTime++;
							if (KeepTime >= 2)		TempStep = 4;
						}
		} break;
		
		default:
		{
						TempStep = 4;
		} break;
	}
}

/*
 * FunctionName	Show_2_4
 * TimeLint
 */
void Show_2_4(void)
{
	if (ShowInit == TRUE)
	{
		ShowInit= FALSE;
		
		All_Color(0,0,0);
		
		TempColor		= 0;
		SpeedTime		= 0;
		TempStep		= 0;
		KeepTime		= 0;
		
		TempR = 0;
		TempG = 0;
		TempB = 0;
		
		ModeStepTree[0] = 0;
		ModeStepSnow[0] = 0;
		ModeStepCane[0] = 0;
		ModeStepSpot[0] = 0;
		ModeStepBall		= 0;
	}
	
	SpeedTime++;
	if (SpeedTime > 3)
	{
		SpeedTime = 0;
		
		KeepTime++;
		if (KeepTime > 40)
		{
			KeepTime = 0;
			TempStep++;
			if (TempStep > 5)	
			{
				TempStep = 0;
			}
		}
		
			
		switch (TempStep)
		{
			case 0:
			{
					TempB   = 0;
					TempR  += 5;
					TempG  -= 7;
			}	break;
				
			case 1:
			{
					TempG  	 = 0;
					TempB   -= 6;
					TempR   += 9;
			}	break;
					
			case 2:
			{
					TempR      = 0;
					TempG     += 7;
					TempB     -= 4;
			}	break;
			
			case 3:
			{
					TempB   = 0;
					TempR  -= 5;
					TempG  += 8;
			}	break;
				
			case 4:
			{
					TempG  	 = 0;
					TempB   += 3;
					TempR   -= 7;
			}	break;
					
			case 5:
			{
					TempR      = 0;
					TempG     -= 8;
					TempB     += 3;
			}	break;
		}
		
		
		//-----------------------------------------------------------------
		// Led Data Get
		//------------------------------------------------------------------
		/* Roof10*/
		for (TempLed = 9; TempLed > 0; TempLed--)
		{
			Roof10[TempLed].DutyG	= Roof10[TempLed - 1].DutyG;
			Roof10[TempLed].DutyR	= Roof10[TempLed - 1].DutyR;
			Roof10[TempLed].DutyB	= Roof10[TempLed - 1].DutyB;
		}
		Roof10[0].DutyR	= TempR;
		Roof10[0].DutyG	= TempG;
		Roof10[0].DutyB	= TempB;
		
		/* Roof24*/
		for (TempLed = 23; TempLed > 0; TempLed--)
		{
			Roof24[TempLed].DutyG	= Roof24[TempLed - 1].DutyG;
			Roof24[TempLed].DutyR	= Roof24[TempLed - 1].DutyR;
			Roof24[TempLed].DutyB	= Roof24[TempLed - 1].DutyB;
		}
		Roof24[0].DutyR	= TempR;
		Roof24[0].DutyG	= TempG;
		Roof24[0].DutyB	= TempB;
		
		/* Roof30*/
		for (TempLed = 29; TempLed > 0; TempLed--)
		{
			Roof30[TempLed].DutyG	= Roof30[TempLed - 1].DutyG;
			Roof30[TempLed].DutyR	= Roof30[TempLed - 1].DutyR;
			Roof30[TempLed].DutyB	= Roof30[TempLed - 1].DutyB;
		}
		Roof30[0].DutyR	= TempR;
		Roof30[0].DutyG	= TempG;
		Roof30[0].DutyB	= TempB;
		
		/* Roof40*/
		for (TempLed = 39; TempLed > 0; TempLed--)
		{
			Roof40[TempLed].DutyG	= Roof40[TempLed - 1].DutyG;
			Roof40[TempLed].DutyR	= Roof40[TempLed - 1].DutyR;
			Roof40[TempLed].DutyB	= Roof40[TempLed - 1].DutyB;
		}
		Roof40[0].DutyR	= TempR;
		Roof40[0].DutyG	= TempG;
		Roof40[0].DutyB	= TempB;
		
		/* String30*/
		for (TempLed = 29; TempLed > 0; TempLed--)
		{
			String30[TempLed].DutyG	= String30[TempLed - 1].DutyG;
			String30[TempLed].DutyR	= String30[TempLed - 1].DutyR;
			String30[TempLed].DutyB	= String30[TempLed - 1].DutyB;
		}
		String30[0].DutyR	= TempR;
		String30[0].DutyG	= TempG;
		String30[0].DutyB	= TempB;
		
		/* String24*/
		for (TempLed = 23; TempLed > 0; TempLed--)
		{
			String24[TempLed].DutyG	= String24[TempLed - 1].DutyG;
			String24[TempLed].DutyR	= String24[TempLed - 1].DutyR;
			String24[TempLed].DutyB	= String24[TempLed - 1].DutyB;
		}
		String24[0].DutyR	= TempR;
		String24[0].DutyG	= TempG;
		String24[0].DutyB	= TempB;
		
		/* String36*/
		for (TempLed = 35; TempLed > 0; TempLed--)
		{
			String36[TempLed].DutyG	= String36[TempLed - 1].DutyG;
			String36[TempLed].DutyR	= String36[TempLed - 1].DutyR;
			String36[TempLed].DutyB	= String36[TempLed - 1].DutyB;
		}
		String36[0].DutyR	= TempR;
		String36[0].DutyG	= TempG;
		String36[0].DutyB	= TempB;
		
		/* Tree */
		switch (ModeStepTree[0])
		{
			case 0:
			{
						TempCnt = 0;
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Grd.Tree[TempCnt * 9 + TempLed].DutyR = TempR;
							Grd.Tree[TempCnt * 9 + TempLed].DutyG = TempG;
							Grd.Tree[TempCnt * 9 + TempLed].DutyB = TempB;
						}
						ModeStepTree[0]++;
			} break;
			
			case 1:
			{
						TempCnt = 2;
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Grd.Tree[TempCnt * 9 + TempLed].DutyR = TempR;
							Grd.Tree[TempCnt * 9 + TempLed].DutyG = TempG;
							Grd.Tree[TempCnt * 9 + TempLed].DutyB = TempB;
						}
						ModeStepTree[0]++;
			} break;
			
			case 2:
			{
						TempCnt = 1;
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Grd.Tree[TempCnt * 9 + TempLed].DutyR = TempR;
							Grd.Tree[TempCnt * 9 + TempLed].DutyG = TempG;
							Grd.Tree[TempCnt * 9 + TempLed].DutyB = TempB;
						}
						ModeStepTree[0]++;
			} break;
			
			default:
			{
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							for (TempLed = 0; TempLed < 9; TempLed++)
							{
								Grd.Tree[TempCnt * 9 + TempLed].DutyR = TempR;
								Grd.Tree[TempCnt * 9 + TempLed].DutyG = TempG;
								Grd.Tree[TempCnt * 9 + TempLed].DutyB = TempB;
							}
						}
						ModeStepTree[0] = 0;
			} break;
		}
		
		/* Snow */
		switch (ModeStepSnow[0])
		{
			case 0:
			{
						TempCnt = 2;
						for (TempLed = 0; TempLed < 7; TempLed++)
						{
							Grd.Snow[TempCnt * 7 + TempLed].DutyR = TempR;
							Grd.Snow[TempCnt * 7 + TempLed].DutyG = TempG;
							Grd.Snow[TempCnt * 7 + TempLed].DutyB = TempB;
						}
						ModeStepSnow[0]++;
			} break;
			
			case 1:
			{
						TempCnt = 0;
						for (TempLed = 0; TempLed < 7; TempLed++)
						{
							Grd.Snow[TempCnt * 7 + TempLed].DutyR = TempR;
							Grd.Snow[TempCnt * 7 + TempLed].DutyG = TempG;
							Grd.Snow[TempCnt * 7 + TempLed].DutyB = TempB;
						}
						ModeStepSnow[0]++;
			} break;
			
			case 2:
			{
						TempCnt = 1;
						for (TempLed = 0; TempLed < 7; TempLed++)
						{
							Grd.Snow[TempCnt * 7 + TempLed].DutyR = TempR;
							Grd.Snow[TempCnt * 7 + TempLed].DutyG = TempG;
							Grd.Snow[TempCnt * 7 + TempLed].DutyB = TempB;
						}
						ModeStepSnow[0]++;
			} break;
			
			default:
			{
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							for (TempLed = 0; TempLed < 7; TempLed++)
							{
								Grd.Snow[TempCnt * 7 + TempLed].DutyR = TempR;
								Grd.Snow[TempCnt * 7 + TempLed].DutyG = TempG;
								Grd.Snow[TempCnt * 7 + TempLed].DutyB = TempB;
							}
						}
						ModeStepSnow[0] = 0;
			} break;
		}
		
		/* Spot */
		switch (ModeStepSpot[0])
		{
			case 0:
			{
						Grd.Spot[0].DutyR = TempR;
						Grd.Spot[0].DutyG = TempG;
						Grd.Spot[0].DutyB = TempB;
						ModeStepSpot[0]++;
			} break;
			
			case 1:
			{
						Grd.Spot[2].DutyR = TempR;
						Grd.Spot[2].DutyG = TempG;
						Grd.Spot[2].DutyB = TempB;
						ModeStepSpot[0]++;
			} break;
			
			case 2:
			{
						Grd.Spot[1].DutyR = TempR;
						Grd.Spot[1].DutyG = TempG;
						Grd.Spot[1].DutyB = TempB;
						ModeStepSpot[0]++;
			} break;
			
			default:
			{
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							Grd.Spot[TempCnt].DutyR = TempR;
							Grd.Spot[TempCnt].DutyG = TempG;
							Grd.Spot[TempCnt].DutyB = TempB;
						}
						ModeStepSpot[0] = 0;
			} break;
		}
		
		/* Cane */
		switch (ModeStepCane[0])
		{
			case 0:
			{			
						TempCnt = 0;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = TempR;
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = TempG;
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = TempB;
						}
						ModeStepCane[0]++;
			} break;
			
			case 1:
			{
						TempCnt = 2;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = TempR;
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = TempG;
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = TempB;
						}
						ModeStepCane[0]++;
			} break;
			
			case 2:
			{
						TempCnt = 1;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = TempR;
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = TempG;
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = TempB;
						}
						ModeStepCane[0]++;
			} break;
			
			case 3:
			{
						TempCnt = 5;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = TempR;
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = TempG;
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = TempB;
						}
						ModeStepCane[0]++;
			} break;
			
			case 4:
			{
						TempCnt = 3;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = TempR;
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = TempG;
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = TempB;
						}
						ModeStepCane[0]++;
			} break;
			
			case 5:
			{
						TempCnt = 4;
						for (TempLed = 0; TempLed < 5; TempLed++)
						{
							Grd.Cane[TempCnt * 5 + TempLed].DutyR = TempR;
							Grd.Cane[TempCnt * 5 + TempLed].DutyG = TempG;
							Grd.Cane[TempCnt * 5 + TempLed].DutyB = TempB;
						}
						ModeStepCane[0]++;
			} break;
			
			default:
			{
						for (TempCnt = 0; TempCnt < 6; TempCnt++)
						{
							for (TempLed = 0; TempLed < 5; TempLed++)
							{
								Grd.Cane[TempCnt * 5 + TempLed].DutyR = TempR;
								Grd.Cane[TempCnt * 5 + TempLed].DutyG = TempG;
								Grd.Cane[TempCnt * 5 + TempLed].DutyB = TempB;
							}
						}
						ModeStepCane[0] = 0;
			} break;
		}
		
		/* Ball */
		switch (ModeStepBall)
		{
			case 0:
			{
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = TempR;
							Grd.Ball[TempCnt].DutyG = TempG;
							Grd.Ball[TempCnt].DutyB = TempB;
						}
			} break;
			
			case 5:
			{
						ModeColorBall = 0;
			} break;


			default:
			{
						ModeColorBall++;
			} break;
		}
	}
}










