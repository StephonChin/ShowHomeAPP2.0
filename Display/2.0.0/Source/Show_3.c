/********************************************************************
	*
	* FILE NAME
	*									Show_3.c
	* DATE
	*									02 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									Display Show 3
	*
*********************************************************************/
#include "Show.h"


/**
	* FunctionName	Show_3
	*/
void Show_3(void)
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
	else if (TimeLine == 2605)					{ShowMode = 1;			ShowInit = TRUE;	}
	else if (TimeLine == 5000)					{ShowMode = 2;			ShowInit = TRUE;	}
	else if (TimeLine == 5300)					{ShowMode = 3;			ShowInit = TRUE;	}
	else if (TimeLine == 6210)					{ShowMode = 4;			ShowInit = TRUE;	}
	else if (TimeLine == 7500)					{TimeLine = 0;			DisplayData.InitFlag = TRUE;}

	switch (ShowMode)
	{
		case 0:			Show_3_0();		break;
		case 1:			Show_3_1();		break;
		case 2:			Show_3_2();		break;
		case 3:			Show_3_3();		break;
		case 4:			Show_3_4();		break;
	}
}


/*
 * FunctionName		Show_3_0
 * Duration				TimeLine += 1570
 */
void Show_3_0(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		TempStep 	= 0;
		TempColor	= 0;
		
		RndCnt10 = 0;
		ModeStep10[0] = 0;
		
		KeepTime = 0;
		
		RndCnt24 = 0;
		RndCnt30 = 0;
		return;
	}
	
	switch (TempStep)
	{
		case 0:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						/* Roof10 */
						for (TempLed = 9; TempLed > 0; TempLed--)
						{
							Roof10[TempLed].DutyR = Roof10[TempLed - 1].DutyR;
							Roof10[TempLed].DutyG = Roof10[TempLed - 1].DutyG;
							Roof10[TempLed].DutyB = Roof10[TempLed - 1].DutyB;
						}
						Roof10[0].DutyR = ColorData[TempColor][R];
						Roof10[0].DutyG = ColorData[TempColor][G];
						Roof10[0].DutyB = ColorData[TempColor][B];
						
						/* Roof24 */
						for (TempLed = 23; TempLed > 0; TempLed--)
						{
							Roof24[TempLed].DutyR = Roof24[TempLed - 1].DutyR;
							Roof24[TempLed].DutyG = Roof24[TempLed - 1].DutyG;
							Roof24[TempLed].DutyB = Roof24[TempLed - 1].DutyB;
						}
						Roof24[0].DutyR = ColorData[TempColor][R];
						Roof24[0].DutyG = ColorData[TempColor][G];
						Roof24[0].DutyB = ColorData[TempColor][B];
						
						/* Roof30 */
						for (TempLed = 29; TempLed > 0; TempLed--)
						{
							Roof30[TempLed].DutyR = Roof30[TempLed - 1].DutyR;
							Roof30[TempLed].DutyG = Roof30[TempLed - 1].DutyG;
							Roof30[TempLed].DutyB = Roof30[TempLed - 1].DutyB;
						}
						Roof30[0].DutyR = ColorData[TempColor][R];
						Roof30[0].DutyG = ColorData[TempColor][G];
						Roof30[0].DutyB = ColorData[TempColor][B];
						
						/* Roof40 */
						for (TempLed = 39; TempLed > 0; TempLed--)
						{
							Roof40[TempLed].DutyR = Roof40[TempLed - 1].DutyR;
							Roof40[TempLed].DutyG = Roof40[TempLed - 1].DutyG;
							Roof40[TempLed].DutyB = Roof40[TempLed - 1].DutyB;
						}
						Roof40[0].DutyR = ColorData[TempColor][R];
						Roof40[0].DutyG = ColorData[TempColor][G];
						Roof40[0].DutyB = ColorData[TempColor][B];
						
						/* String30 */
						for (TempLed = 29; TempLed > 0; TempLed--)
						{
							String30[TempLed].DutyR = String30[TempLed - 1].DutyR;
							String30[TempLed].DutyG = String30[TempLed - 1].DutyG;
							String30[TempLed].DutyB = String30[TempLed - 1].DutyB;
						}
						String30[0].DutyR = ColorData[TempColor][R];
						String30[0].DutyG = ColorData[TempColor][G];
						String30[0].DutyB = ColorData[TempColor][B];
						
						/* String24 */
						for (TempLed = 23; TempLed > 0; TempLed--)
						{
							String24[TempLed].DutyR = String24[TempLed - 1].DutyR;
							String24[TempLed].DutyG = String24[TempLed - 1].DutyG;
							String24[TempLed].DutyB = String24[TempLed - 1].DutyB;
						}
						String24[0].DutyR = ColorData[TempColor][R];
						String24[0].DutyG = ColorData[TempColor][G];
						String24[0].DutyB = ColorData[TempColor][B];
						
						/* String36 */
						for (TempLed = 35; TempLed > 0; TempLed--)
						{
							String36[TempLed].DutyR = String36[TempLed - 1].DutyR;
							String36[TempLed].DutyG = String36[TempLed - 1].DutyG;
							String36[TempLed].DutyB = String36[TempLed - 1].DutyB;
						}
						String36[0].DutyR = ColorData[TempColor][R];
						String36[0].DutyG = ColorData[TempColor][G];
						String36[0].DutyB = ColorData[TempColor][B];
						
						
						KeepTime++;
						if (KeepTime >= 5)
						{
							KeepTime = 0;
							/* Tree */
							for (TempCnt = 2; TempCnt > 0; TempCnt--)
							{
								for (TempLed = 0; TempLed < 9; TempLed++)
								{
									Grd.Tree[TempCnt * 9 + TempLed].DutyR = Grd.Tree[TempCnt * 9 + TempLed - 9].DutyR;
									Grd.Tree[TempCnt * 9 + TempLed].DutyG = Grd.Tree[TempCnt * 9 + TempLed - 9].DutyG;
									Grd.Tree[TempCnt * 9 + TempLed].DutyB = Grd.Tree[TempCnt * 9 + TempLed - 9].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 9; TempLed++)
							{
								Grd.Tree[TempLed].DutyR = ColorData[TempColor][R];
								Grd.Tree[TempLed].DutyG = ColorData[TempColor][G];
								Grd.Tree[TempLed].DutyB = ColorData[TempColor][B];
							}
							
							/* Snow */
							for (TempCnt = 2; TempCnt > 0; TempCnt--)
							{
								for (TempLed = 0; TempLed < 7; TempLed++)
								{
									Grd.Snow[TempCnt * 7 + TempLed].DutyR = Grd.Snow[TempCnt * 7 + TempLed - 7].DutyR;
									Grd.Snow[TempCnt * 7 + TempLed].DutyG = Grd.Snow[TempCnt * 7 + TempLed - 7].DutyG;
									Grd.Snow[TempCnt * 7 + TempLed].DutyB = Grd.Snow[TempCnt * 7 + TempLed - 7].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 7; TempLed++)
							{
								Grd.Snow[TempLed].DutyR = ColorData[TempColor][R];
								Grd.Snow[TempLed].DutyG = ColorData[TempColor][G];
								Grd.Snow[TempLed].DutyB = ColorData[TempColor][B];
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
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								Grd.Ball[TempLed].DutyR = ColorData[TempColor][R];
								Grd.Ball[TempLed].DutyG = ColorData[TempColor][G];
								Grd.Ball[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						
						RndCnt10++;
						if (RndCnt10 >= 40)
						{
							RndCnt10 = 0;
							TempStep++;
							TempColor++;
							if (TempColor >= ColorNum)		TempColor = 0;
						}
					}
		} break;
		
		case 1:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						/* Roof10 */
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Roof10[TempLed].DutyR = Roof10[TempLed + 1].DutyR;
							Roof10[TempLed].DutyG = Roof10[TempLed + 1].DutyG;
							Roof10[TempLed].DutyB = Roof10[TempLed + 1].DutyB;
						}
						Roof10[9].DutyR = ColorData[TempColor][R];
						Roof10[9].DutyG = ColorData[TempColor][G];
						Roof10[9].DutyB = ColorData[TempColor][B];
						
						/* Roof24 */
						for (TempLed = 0; TempLed < 23; TempLed++)
						{
							Roof24[TempLed].DutyR = Roof24[TempLed + 1].DutyR;
							Roof24[TempLed].DutyG = Roof24[TempLed + 1].DutyG;
							Roof24[TempLed].DutyB = Roof24[TempLed + 1].DutyB;
						}
						Roof24[23].DutyR = ColorData[TempColor][R];
						Roof24[23].DutyG = ColorData[TempColor][G];
						Roof24[23].DutyB = ColorData[TempColor][B];
						
						/* Roof30 */
						for (TempLed = 0; TempLed < 29; TempLed++)
						{
							Roof30[TempLed].DutyR = Roof30[TempLed + 1].DutyR;
							Roof30[TempLed].DutyG = Roof30[TempLed + 1].DutyG;
							Roof30[TempLed].DutyB = Roof30[TempLed + 1].DutyB;
						}
						Roof30[29].DutyR = ColorData[TempColor][R];
						Roof30[29].DutyG = ColorData[TempColor][G];
						Roof30[29].DutyB = ColorData[TempColor][B];
						
						/* Roof40 */
						for (TempLed = 0; TempLed < 39; TempLed++)
						{
							Roof40[TempLed].DutyR = Roof40[TempLed + 1].DutyR;
							Roof40[TempLed].DutyG = Roof40[TempLed + 1].DutyG;
							Roof40[TempLed].DutyB = Roof40[TempLed + 1].DutyB;
						}
						Roof40[39].DutyR = ColorData[TempColor][R];
						Roof40[39].DutyG = ColorData[TempColor][G];
						Roof40[39].DutyB = ColorData[TempColor][B];
						
						/* String30 */
						for (TempLed = 0; TempLed < 29; TempLed++)
						{
								String30[TempLed].DutyR = String30[TempLed + 1].DutyR;
								String30[TempLed].DutyG = String30[TempLed + 1].DutyG;
								String30[TempLed].DutyB = String30[TempLed + 1].DutyB;
						}
						String30[29].DutyR = ColorData[TempColor][R];
						String30[29].DutyG = ColorData[TempColor][G];
						String30[29].DutyB = ColorData[TempColor][B];
						
						/* String24 */
						for (TempLed = 0; TempLed < 23; TempLed++)
						{
								String24[TempLed].DutyR = String24[TempLed + 1].DutyR;
								String24[TempLed].DutyG = String24[TempLed + 1].DutyG;
								String24[TempLed].DutyB = String24[TempLed + 1].DutyB;
						}
						String24[23].DutyR = ColorData[TempColor][R];
						String24[23].DutyG = ColorData[TempColor][G];
						String24[23].DutyB = ColorData[TempColor][B];
						
						/* String36 */
						for (TempLed = 0; TempLed < 35; TempLed++)
						{
								String36[TempLed].DutyR = String36[TempLed + 1].DutyR;
								String36[TempLed].DutyG = String36[TempLed + 1].DutyG;
								String36[TempLed].DutyB = String36[TempLed + 1].DutyB;
						}
						String36[35].DutyR = ColorData[TempColor][R];
						String36[35].DutyG = ColorData[TempColor][G];
						String36[35].DutyB = ColorData[TempColor][B];
						
						KeepTime++;
						if (KeepTime >= 5)
						{
							KeepTime = 0;
							/* Tree */
							for (TempCnt = 0; TempCnt < 2; TempCnt++)
							{
								for (TempLed = 0; TempLed < 9; TempLed++)
								{
									Grd.Tree[TempCnt * 9 + TempLed].DutyR = Grd.Tree[TempCnt * 9 + TempLed + 9].DutyR;
									Grd.Tree[TempCnt * 9 + TempLed].DutyG = Grd.Tree[TempCnt * 9 + TempLed + 9].DutyG;
									Grd.Tree[TempCnt * 9 + TempLed].DutyB = Grd.Tree[TempCnt * 9 + TempLed + 9].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 9; TempLed++)
							{
								Grd.Tree[TempLed + 18].DutyR = ColorData[TempColor][R];
								Grd.Tree[TempLed + 18].DutyG = ColorData[TempColor][G];
								Grd.Tree[TempLed + 18].DutyB = ColorData[TempColor][B];
							}
							
							/* Snow */
							for (TempCnt = 0; TempCnt < 2; TempCnt++)
							{
								for (TempLed = 0; TempLed < 7; TempLed++)
								{
									Grd.Snow[TempCnt * 7 + TempLed].DutyR = Grd.Snow[TempCnt * 7 + TempLed + 7].DutyR;
									Grd.Snow[TempCnt * 7 + TempLed].DutyG = Grd.Snow[TempCnt * 7 + TempLed + 7].DutyG;
									Grd.Snow[TempCnt * 7 + TempLed].DutyB = Grd.Snow[TempCnt * 7 + TempLed + 7].DutyB;
								}
							}
							for (TempLed = 0; TempLed < 7; TempLed++)
							{
								Grd.Snow[TempLed + 14].DutyR = ColorData[TempColor][R];
								Grd.Snow[TempLed + 14].DutyG = ColorData[TempColor][G];
								Grd.Snow[TempLed + 14].DutyB = ColorData[TempColor][B];
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
							for (TempLed = 0; TempLed < 4; TempLed++)
							{
								Grd.Ball[TempLed].DutyR = ColorData[TempColor][R];
								Grd.Ball[TempLed].DutyG = ColorData[TempColor][G];
								Grd.Ball[TempLed].DutyB = ColorData[TempColor][B];
							}
						}
						
						
						RndCnt10++;
						if (RndCnt10 >= 40)
						{
							RndCnt10 = 0;
							TempColor++;
							if (TempColor >= ColorNum)		TempColor = 0;

							TempStep = 0;
							ModeStep10[0]++;
							if (ModeStep10[0] > 2)
							{
								ModeStep10[0] = 0;
								TempStep = 2;
								RndCnt10 = 0;
								RndCnt24 = 0;
								
								/* Tree */
								for (TempCnt = 0; TempCnt < 3; TempCnt++)
								{
									for (TempLed = 0; TempLed < 9; TempLed++)
									{
										Grd.Tree[TempCnt * 9 + TempLed].DutyR = 0;
										Grd.Tree[TempCnt * 9 + TempLed].DutyG = 0;
										Grd.Tree[TempCnt * 9 + TempLed].DutyB = 0;
									}
									ModeTimeTree[TempCnt] = 0;
									ModeStepTree[TempCnt] = 0;
									ModeColorTree[TempCnt] = TempCnt;
								}
								
								/* Snow */
								for (TempCnt = 0; TempCnt < 3; TempCnt++)
								{
									for (TempLed = 0; TempLed < 7; TempLed++)
									{
										Grd.Snow[TempCnt * 7 + TempLed].DutyR = 0;
										Grd.Snow[TempCnt * 7 + TempLed].DutyG = 0;
										Grd.Snow[TempCnt * 7 + TempLed].DutyB = 0;
									}
									ModeTimeSnow[TempCnt] = 0;
									ModeStepSnow[TempCnt] = 0;
									ModeColorSnow[TempCnt] = TempCnt;
								}
								
								/* Cane */
								for (TempCnt = 0; TempCnt < 6; TempCnt++)
								{
									for (TempLed = 0; TempLed < 5; TempLed++)
									{
										Grd.Cane[TempCnt * 5 + TempLed].DutyR = 0;
										Grd.Cane[TempCnt * 5 + TempLed].DutyG = 0;
										Grd.Cane[TempCnt * 5 + TempLed].DutyB = 0;
									}
									ModeTimeCane[TempCnt] = 0;
									ModeStepCane[TempCnt] = 0;
									ModeColorCane[TempCnt] = TempCnt;
								}
								
								/* Spot */
								for (TempCnt = 0; TempCnt < 3; TempCnt++)
								{
									Grd.Spot[TempCnt].DutyR = 0;
									Grd.Spot[TempCnt].DutyG = 0;
									Grd.Spot[TempCnt].DutyB = 0;
									ModeTimeSpot[TempCnt] = 0;
									ModeStepSpot[TempCnt] = 0;
									ModeColorSpot[TempCnt] = TempCnt;
								}
								
								/* Ball */
								ModeTimeBall = 0;
								ModeStepBall = 0;
								ModeColorBall = 0;
								for (TempCnt = 0; TempCnt < 4; TempCnt++)
								{
									Grd.Ball[TempCnt].DutyR = 0;
									Grd.Ball[TempCnt].DutyG = 0;
									Grd.Ball[TempCnt].DutyB = 0;
								}
							}
						}
					}
		} break;
		
		case 2:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						/* Roof10 */
						for (TempLed = 9; TempLed > 0; TempLed--)
						{
							Roof10[TempLed].DutyR = Roof10[TempLed - 1].DutyR;
							Roof10[TempLed].DutyG = Roof10[TempLed - 1].DutyG;
							Roof10[TempLed].DutyB = Roof10[TempLed - 1].DutyB;
						}
						Roof10[0].DutyR = ColorData[TempColor][R];
						Roof10[0].DutyG = ColorData[TempColor][G];
						Roof10[0].DutyB = ColorData[TempColor][B];
						
						/* Roof24 */
						for (TempLed = 23; TempLed > 0; TempLed--)
						{
							Roof24[TempLed].DutyR = Roof24[TempLed - 1].DutyR;
							Roof24[TempLed].DutyG = Roof24[TempLed - 1].DutyG;
							Roof24[TempLed].DutyB = Roof24[TempLed - 1].DutyB;
						}
						Roof24[0].DutyR = ColorData[TempColor][R];
						Roof24[0].DutyG = ColorData[TempColor][G];
						Roof24[0].DutyB = ColorData[TempColor][B];
						
						/* Roof30 */
						for (TempLed = 29; TempLed > 0; TempLed--)
						{
							Roof30[TempLed].DutyR = Roof30[TempLed - 1].DutyR;
							Roof30[TempLed].DutyG = Roof30[TempLed - 1].DutyG;
							Roof30[TempLed].DutyB = Roof30[TempLed - 1].DutyB;
						}
						Roof30[0].DutyR = ColorData[TempColor][R];
						Roof30[0].DutyG = ColorData[TempColor][G];
						Roof30[0].DutyB = ColorData[TempColor][B];
						
						/* Roof40 */
						for (TempLed = 39; TempLed > 0; TempLed--)
						{
							Roof40[TempLed].DutyR = Roof40[TempLed - 1].DutyR;
							Roof40[TempLed].DutyG = Roof40[TempLed - 1].DutyG;
							Roof40[TempLed].DutyB = Roof40[TempLed - 1].DutyB;
						}
						Roof40[0].DutyR = ColorData[TempColor][R];
						Roof40[0].DutyG = ColorData[TempColor][G];
						Roof40[0].DutyB = ColorData[TempColor][B];
						
						/* String30 */
						for (TempLed = 29; TempLed > 0; TempLed--)
						{
							String30[TempLed].DutyR = String30[TempLed - 1].DutyR;
							String30[TempLed].DutyG = String30[TempLed - 1].DutyG;
							String30[TempLed].DutyB = String30[TempLed - 1].DutyB;
						}
						String30[0].DutyR = ColorData[TempColor][R];
						String30[0].DutyG = ColorData[TempColor][G];
						String30[0].DutyB = ColorData[TempColor][B];
						
						/* String24 */
						for (TempLed = 23; TempLed > 0; TempLed--)
						{
							String24[TempLed].DutyR = String24[TempLed - 1].DutyR;
							String24[TempLed].DutyG = String24[TempLed - 1].DutyG;
							String24[TempLed].DutyB = String24[TempLed - 1].DutyB;
						}
						String24[0].DutyR = ColorData[TempColor][R];
						String24[0].DutyG = ColorData[TempColor][G];
						String24[0].DutyB = ColorData[TempColor][B];
						
						/* String36 */
						for (TempLed = 35; TempLed > 0; TempLed--)
						{
							String36[TempLed].DutyR = String36[TempLed - 1].DutyR;
							String36[TempLed].DutyG = String36[TempLed - 1].DutyG;
							String36[TempLed].DutyB = String36[TempLed - 1].DutyB;
						}
						String36[0].DutyR = ColorData[TempColor][R];
						String36[0].DutyG = ColorData[TempColor][G];
						String36[0].DutyB = ColorData[TempColor][B];
						
						RndCnt10++;
						if (RndCnt10 >= 6)
						{
							RndCnt10 = 0;
							TempColor++;
							if (TempColor >= ColorNum)		TempColor = 0;
						}
						
						/* Tree */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							ModeTimeTree[TempCnt]++;
							if (ModeTimeTree[TempCnt] >= TempCnt)
							{
								ModeTimeTree[TempCnt] = 0;
								switch (ModeStepTree[TempCnt])
								{
									case 0:
									{
											if (Grd.Tree[TempCnt * 9].DutyR < ColorData[ModeColorTree[TempCnt]][R]
												||Grd.Tree[TempCnt * 9].DutyG < ColorData[ModeColorTree[TempCnt]][G]
												||Grd.Tree[TempCnt * 9].DutyB < ColorData[ModeColorTree[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorTree[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorTree[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorTree[TempCnt]][B] / 25;
												for (TempLed = 0; TempLed < 9; TempLed++)
												{
													Grd.Tree[TempCnt * 9 + TempLed].DutyR += FadeR;
													Grd.Tree[TempCnt * 9 + TempLed].DutyG += FadeG;
													Grd.Tree[TempCnt * 9 + TempLed].DutyB += FadeB;
												}
											}
											else
											{
												ModeStepTree[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Tree[TempCnt * 9].DutyR > 0
													 ||Grd.Tree[TempCnt * 9].DutyG > 0
													 ||Grd.Tree[TempCnt * 9].DutyB > 0)
												{
													FadeR = ColorData[ModeColorTree[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorTree[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorTree[TempCnt]][B] / 25;
													for (TempLed = 0; TempLed < 9; TempLed++)
													{
														Grd.Tree[TempCnt * 9 + TempLed].DutyR -= FadeR;
														Grd.Tree[TempCnt * 9 + TempLed].DutyG -= FadeG;
														Grd.Tree[TempCnt * 9 + TempLed].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepTree[TempCnt] = 0;
													ModeColorTree[TempCnt]++;
													if (ModeColorTree[TempCnt] >= ColorNum)		ModeColorTree[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						/* Snow */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							ModeTimeSnow[TempCnt]++;
							if (ModeTimeSnow[TempCnt] >= 2 - TempCnt)
							{
								ModeTimeSnow[TempCnt] = 0;
								switch (ModeStepSnow[TempCnt])
								{
									case 0:
									{
											if (Grd.Snow[TempCnt * 7].DutyR < ColorData[ModeColorSnow[TempCnt]][R]
												||Grd.Snow[TempCnt * 7].DutyG < ColorData[ModeColorSnow[TempCnt]][G]
												||Grd.Snow[TempCnt * 7].DutyB < ColorData[ModeColorSnow[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorSnow[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorSnow[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorSnow[TempCnt]][B] / 25;
												for (TempLed = 0; TempLed < 7; TempLed++)
												{
													Grd.Snow[TempCnt * 7 + TempLed].DutyR += FadeR;
													Grd.Snow[TempCnt * 7 + TempLed].DutyG += FadeG;
													Grd.Snow[TempCnt * 7 + TempLed].DutyB += FadeB;
												}
											}
											else
											{
												ModeStepSnow[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Snow[TempCnt * 7].DutyR > 0
													 ||Grd.Snow[TempCnt * 7].DutyG > 0
													 ||Grd.Snow[TempCnt * 7].DutyB > 0)
												{
													FadeR = ColorData[ModeColorSnow[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorSnow[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorSnow[TempCnt]][B] / 25;
													for (TempLed = 0; TempLed < 7; TempLed++)
													{
														Grd.Snow[TempCnt * 7 + TempLed].DutyR -= FadeR;
														Grd.Snow[TempCnt * 7 + TempLed].DutyG -= FadeG;
														Grd.Snow[TempCnt * 7 + TempLed].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepSnow[TempCnt] = 0;
													ModeColorSnow[TempCnt]++;
													if (ModeColorSnow[TempCnt] >= ColorNum)		ModeColorSnow[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						/* Cane */
						for (TempCnt = 0; TempCnt < 6; TempCnt++)
						{
							ModeTimeCane[TempCnt]++;
							if (ModeTimeCane[TempCnt] >= TempCnt)
							{
								ModeTimeCane[TempCnt] = 0;
								switch (ModeStepCane[TempCnt])
								{
									case 0:
									{
											if (Grd.Cane[TempCnt * 5].DutyR < ColorData[ModeColorCane[TempCnt]][R]
												||Grd.Cane[TempCnt * 5].DutyG < ColorData[ModeColorCane[TempCnt]][G]
												||Grd.Cane[TempCnt * 5].DutyB < ColorData[ModeColorCane[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorCane[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorCane[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorCane[TempCnt]][B] / 25;
												for (TempLed = 0; TempLed < 5; TempLed++)
												{
													Grd.Cane[TempCnt * 5 + TempLed].DutyR += FadeR;
													Grd.Cane[TempCnt * 5 + TempLed].DutyG += FadeG;
													Grd.Cane[TempCnt * 5 + TempLed].DutyB += FadeB;
												}
											}
											else
											{
												ModeStepCane[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Cane[TempCnt * 5].DutyR > 0
													 ||Grd.Cane[TempCnt * 5].DutyG > 0
													 ||Grd.Cane[TempCnt * 5].DutyB > 0)
												{
													FadeR = ColorData[ModeColorCane[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorCane[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorCane[TempCnt]][B] / 25;
													for (TempLed = 0; TempLed < 5; TempLed++)
													{
														Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
														Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
														Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepCane[TempCnt] = 0;
													ModeColorCane[TempCnt]++;
													if (ModeColorCane[TempCnt] >= ColorNum)		ModeColorCane[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						
						/* Spot */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							ModeTimeSpot[TempCnt]++;
							if (ModeTimeSpot[TempCnt] >= TempCnt)
							{
								ModeTimeSpot[TempCnt] = 0;
								switch (ModeStepSpot[TempCnt])
								{
									case 0:
									{
											if (Grd.Spot[TempCnt].DutyR < ColorData[ModeColorSpot[TempCnt]][R]
												||Grd.Spot[TempCnt].DutyG < ColorData[ModeColorSpot[TempCnt]][G]
												||Grd.Spot[TempCnt].DutyB < ColorData[ModeColorSpot[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorSpot[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorSpot[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorSpot[TempCnt]][B] / 25;
												Grd.Spot[TempCnt].DutyR += FadeR;
												Grd.Spot[TempCnt].DutyG += FadeG;
												Grd.Spot[TempCnt].DutyB += FadeB;
											}
											else
											{
												ModeStepSpot[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Spot[TempCnt].DutyR > 0
													 ||Grd.Spot[TempCnt].DutyG > 0
													 ||Grd.Spot[TempCnt].DutyB > 0)
												{
													FadeR = ColorData[ModeColorSpot[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorSpot[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorSpot[TempCnt]][B] / 25;
													Grd.Spot[TempCnt].DutyR -= FadeR;
													Grd.Spot[TempCnt].DutyG -= FadeG;
													Grd.Spot[TempCnt].DutyB -= FadeB;
												}
												else
												{
													ModeStepSpot[TempCnt] = 0;
													ModeColorSpot[TempCnt]++;
													if (ModeColorSpot[TempCnt] >= ColorNum)		ModeColorSpot[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						/* Ball */
						ModeTimeBall++;
						if (ModeTimeBall >= 2)
						{
							ModeTimeBall = 0;
							switch (ModeStepBall)
							{
								case 0:
								{
										if (Grd.Ball[0].DutyR < ColorData[ModeColorBall][R]
											||Grd.Ball[0].DutyG < ColorData[ModeColorBall][G]
											||Grd.Ball[0].DutyB < ColorData[ModeColorBall][B])
										{
											FadeR = ColorData[ModeColorBall][R] / 25;
											FadeG = ColorData[ModeColorBall][G] / 25;
											FadeB = ColorData[ModeColorBall][B] / 25;
											for (TempLed = 0; TempLed < 4; TempLed++)
											{
												Grd.Ball[TempLed].DutyR += FadeR;
												Grd.Ball[TempLed].DutyG += FadeG;
												Grd.Ball[TempLed].DutyB += FadeB;
											}
										}
										else
										{
											ModeStepBall++;
										}
								} break;
								
								case 1:
								{
											if (Grd.Ball[0].DutyR > 0
												 ||Grd.Ball[0].DutyG > 0
												 ||Grd.Ball[0].DutyB > 0)
											{
												FadeR = ColorData[ModeColorBall][R] / 25;
												FadeG = ColorData[ModeColorBall][G] / 25;
												FadeB = ColorData[ModeColorBall][B] / 25;
												for (TempLed = 0; TempLed < 4; TempLed++)
												{
													Grd.Ball[TempLed].DutyR -= FadeR;
													Grd.Ball[TempLed].DutyG -= FadeG;
													Grd.Ball[TempLed].DutyB -= FadeB;
												}
											}
											else
											{
												ModeStepBall = 0;
												ModeColorBall++;
												if (ModeColorBall >= ColorNum)		ModeColorBall = 0;
											}
								} break;
							}
						}
						
						
						
						RndCnt24++;
						if (RndCnt24 >= 40)
						{
							RndCnt24 = 0;
							TempStep++;
						}
					}
		} break;
		
		case 3:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						/* Roof10 */
						for (TempLed = 0; TempLed < 9; TempLed++)
						{
							Roof10[TempLed].DutyR = Roof10[TempLed + 1].DutyR;
							Roof10[TempLed].DutyG = Roof10[TempLed + 1].DutyG;
							Roof10[TempLed].DutyB = Roof10[TempLed + 1].DutyB;
						}
						Roof10[9].DutyR = ColorData[TempColor][R];
						Roof10[9].DutyG = ColorData[TempColor][G];
						Roof10[9].DutyB = ColorData[TempColor][B];
						
						/* Roof24 */
						for (TempLed = 0; TempLed < 23; TempLed++)
						{
							Roof24[TempLed].DutyR = Roof24[TempLed + 1].DutyR;
							Roof24[TempLed].DutyG = Roof24[TempLed + 1].DutyG;
							Roof24[TempLed].DutyB = Roof24[TempLed + 1].DutyB;
						}
						Roof24[23].DutyR = ColorData[TempColor][R];
						Roof24[23].DutyG = ColorData[TempColor][G];
						Roof24[23].DutyB = ColorData[TempColor][B];
						
						/* Roof30 */
						for (TempLed = 0; TempLed < 29; TempLed++)
						{
							Roof30[TempLed].DutyR = Roof30[TempLed + 1].DutyR;
							Roof30[TempLed].DutyG = Roof30[TempLed + 1].DutyG;
							Roof30[TempLed].DutyB = Roof30[TempLed + 1].DutyB;
						}
						Roof30[29].DutyR = ColorData[TempColor][R];
						Roof30[29].DutyG = ColorData[TempColor][G];
						Roof30[29].DutyB = ColorData[TempColor][B];
						
						/* Roof40 */
						for (TempLed = 0; TempLed < 39; TempLed++)
						{
							Roof40[TempLed].DutyR = Roof40[TempLed + 1].DutyR;
							Roof40[TempLed].DutyG = Roof40[TempLed + 1].DutyG;
							Roof40[TempLed].DutyB = Roof40[TempLed + 1].DutyB;
						}
						Roof40[39].DutyR = ColorData[TempColor][R];
						Roof40[39].DutyG = ColorData[TempColor][G];
						Roof40[39].DutyB = ColorData[TempColor][B];
						
						/* String30 */
						for (TempLed = 0; TempLed < 29; TempLed++)
						{
							String30[TempLed].DutyR = String30[TempLed + 1].DutyR;
							String30[TempLed].DutyG = String30[TempLed + 1].DutyG;
							String30[TempLed].DutyB = String30[TempLed + 1].DutyB;
						}

						String30[29].DutyR = ColorData[TempColor][R];
						String30[29].DutyG = ColorData[TempColor][G];
						String30[29].DutyB = ColorData[TempColor][B];
						
						/* String24 */
						for (TempLed = 0; TempLed < 23; TempLed++)
						{
							String24[TempLed].DutyR = String24[TempLed + 1].DutyR;
							String24[TempLed].DutyG = String24[TempLed + 1].DutyG;
							String24[TempLed].DutyB = String24[TempLed + 1].DutyB;
						}

						String24[23].DutyR = ColorData[TempColor][R];
						String24[23].DutyG = ColorData[TempColor][G];
						String24[23].DutyB = ColorData[TempColor][B];
						
						
						/* String36 */
						for (TempLed = 0; TempLed < 35; TempLed++)
						{
							String36[TempLed].DutyR = String36[TempLed + 1].DutyR;
							String36[TempLed].DutyG = String36[TempLed + 1].DutyG;
							String36[TempLed].DutyB = String36[TempLed + 1].DutyB;
						}

						String36[35].DutyR = ColorData[TempColor][R];
						String36[35].DutyG = ColorData[TempColor][G];
						String36[35].DutyB = ColorData[TempColor][B];

						
						RndCnt10++;
						if (RndCnt10 >= 6)
						{
							RndCnt10 = 0;
							TempColor++;
							if (TempColor >= ColorNum)		TempColor = 0;
						}
						
						/* Tree */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							ModeTimeTree[TempCnt]++;
							if (ModeTimeTree[TempCnt] >= TempCnt)
							{
								ModeTimeTree[TempCnt] = 0;
								switch (ModeStepTree[TempCnt])
								{
									case 0:
									{
											if (Grd.Tree[TempCnt * 9].DutyR < ColorData[ModeColorTree[TempCnt]][R]
												||Grd.Tree[TempCnt * 9].DutyG < ColorData[ModeColorTree[TempCnt]][G]
												||Grd.Tree[TempCnt * 9].DutyB < ColorData[ModeColorTree[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorTree[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorTree[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorTree[TempCnt]][B] / 25;
												for (TempLed = 0; TempLed < 9; TempLed++)
												{
													Grd.Tree[TempCnt * 9 + TempLed].DutyR += FadeR;
													Grd.Tree[TempCnt * 9 + TempLed].DutyG += FadeG;
													Grd.Tree[TempCnt * 9 + TempLed].DutyB += FadeB;
												}
											}
											else
											{
												ModeStepTree[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Tree[TempCnt * 9].DutyR > 0
													 ||Grd.Tree[TempCnt * 9].DutyG > 0
													 ||Grd.Tree[TempCnt * 9].DutyB > 0)
												{
													FadeR = ColorData[ModeColorTree[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorTree[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorTree[TempCnt]][B] / 25;
													for (TempLed = 0; TempLed < 9; TempLed++)
													{
														Grd.Tree[TempCnt * 9 + TempLed].DutyR -= FadeR;
														Grd.Tree[TempCnt * 9 + TempLed].DutyG -= FadeG;
														Grd.Tree[TempCnt * 9 + TempLed].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepTree[TempCnt] = 0;
													ModeColorTree[TempCnt]++;
													if (ModeColorTree[TempCnt] >= ColorNum)		ModeColorTree[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						/* Snow */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							ModeTimeSnow[TempCnt]++;
							if (ModeTimeSnow[TempCnt] >= 2 - TempCnt)
							{
								ModeTimeSnow[TempCnt] = 0;
								switch (ModeStepSnow[TempCnt])
								{
									case 0:
									{
											if (Grd.Snow[TempCnt * 7].DutyR < ColorData[ModeColorSnow[TempCnt]][R]
												||Grd.Snow[TempCnt * 7].DutyG < ColorData[ModeColorSnow[TempCnt]][G]
												||Grd.Snow[TempCnt * 7].DutyB < ColorData[ModeColorSnow[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorSnow[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorSnow[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorSnow[TempCnt]][B] / 25;
												for (TempLed = 0; TempLed < 7; TempLed++)
												{
													Grd.Snow[TempCnt * 7 + TempLed].DutyR += FadeR;
													Grd.Snow[TempCnt * 7 + TempLed].DutyG += FadeG;
													Grd.Snow[TempCnt * 7 + TempLed].DutyB += FadeB;
												}
											}
											else
											{
												ModeStepSnow[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Snow[TempCnt * 7].DutyR > 0
													 ||Grd.Snow[TempCnt * 7].DutyG > 0
													 ||Grd.Snow[TempCnt * 7].DutyB > 0)
												{
													FadeR = ColorData[ModeColorSnow[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorSnow[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorSnow[TempCnt]][B] / 25;
													for (TempLed = 0; TempLed < 7; TempLed++)
													{
														Grd.Snow[TempCnt * 7 + TempLed].DutyR -= FadeR;
														Grd.Snow[TempCnt * 7 + TempLed].DutyG -= FadeG;
														Grd.Snow[TempCnt * 7 + TempLed].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepSnow[TempCnt] = 0;
													ModeColorSnow[TempCnt]++;
													if (ModeColorSnow[TempCnt] >= ColorNum)		ModeColorSnow[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						/* Cane */
						for (TempCnt = 0; TempCnt < 6; TempCnt++)
						{
							ModeTimeCane[TempCnt]++;
							if (ModeTimeCane[TempCnt] >= TempCnt)
							{
								ModeTimeCane[TempCnt] = 0;
								switch (ModeStepCane[TempCnt])
								{
									case 0:
									{
											if (Grd.Cane[TempCnt * 5].DutyR < ColorData[ModeColorCane[TempCnt]][R]
												||Grd.Cane[TempCnt * 5].DutyG < ColorData[ModeColorCane[TempCnt]][G]
												||Grd.Cane[TempCnt * 5].DutyB < ColorData[ModeColorCane[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorCane[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorCane[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorCane[TempCnt]][B] / 25;
												for (TempLed = 0; TempLed < 5; TempLed++)
												{
													Grd.Cane[TempCnt * 5 + TempLed].DutyR += FadeR;
													Grd.Cane[TempCnt * 5 + TempLed].DutyG += FadeG;
													Grd.Cane[TempCnt * 5 + TempLed].DutyB += FadeB;
												}
											}
											else
											{
												ModeStepCane[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Cane[TempCnt * 5].DutyR > 0
													 ||Grd.Cane[TempCnt * 5].DutyG > 0
													 ||Grd.Cane[TempCnt * 5].DutyB > 0)
												{
													FadeR = ColorData[ModeColorCane[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorCane[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorCane[TempCnt]][B] / 25;
													for (TempLed = 0; TempLed < 5; TempLed++)
													{
														Grd.Cane[TempCnt * 5 + TempLed].DutyR -= FadeR;
														Grd.Cane[TempCnt * 5 + TempLed].DutyG -= FadeG;
														Grd.Cane[TempCnt * 5 + TempLed].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepCane[TempCnt] = 0;
													ModeColorCane[TempCnt]++;
													if (ModeColorCane[TempCnt] >= ColorNum)		ModeColorCane[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						
						/* Spot */
						for (TempCnt = 0; TempCnt < 3; TempCnt++)
						{
							ModeTimeSpot[TempCnt]++;
							if (ModeTimeSpot[TempCnt] >= TempCnt)
							{
								ModeTimeSpot[TempCnt] = 0;
								switch (ModeStepSpot[TempCnt])
								{
									case 0:
									{
											if (Grd.Spot[TempCnt].DutyR < ColorData[ModeColorSpot[TempCnt]][R]
												||Grd.Spot[TempCnt].DutyG < ColorData[ModeColorSpot[TempCnt]][G]
												||Grd.Spot[TempCnt].DutyB < ColorData[ModeColorSpot[TempCnt]][B])
											{
												FadeR = ColorData[ModeColorSpot[TempCnt]][R] / 25;
												FadeG = ColorData[ModeColorSpot[TempCnt]][G] / 25;
												FadeB = ColorData[ModeColorSpot[TempCnt]][B] / 25;
												Grd.Spot[TempCnt].DutyR += FadeR;
												Grd.Spot[TempCnt].DutyG += FadeG;
												Grd.Spot[TempCnt].DutyB += FadeB;
											}
											else
											{
												ModeStepSpot[TempCnt]++;
											}
									} break;
									
									case 1:
									{
												if (Grd.Spot[TempCnt].DutyR > 0
													 ||Grd.Spot[TempCnt].DutyG > 0
													 ||Grd.Spot[TempCnt].DutyB > 0)
												{
													FadeR = ColorData[ModeColorSpot[TempCnt]][R] / 25;
													FadeG = ColorData[ModeColorSpot[TempCnt]][G] / 25;
													FadeB = ColorData[ModeColorSpot[TempCnt]][B] / 25;
													Grd.Spot[TempCnt].DutyR -= FadeR;
													Grd.Spot[TempCnt].DutyG -= FadeG;
													Grd.Spot[TempCnt].DutyB -= FadeB;
												}
												else
												{
													ModeStepSpot[TempCnt] = 0;
													ModeColorSpot[TempCnt]++;
													if (ModeColorSpot[TempCnt] >= ColorNum)		ModeColorSpot[TempCnt] = 0;
												}
									} break;
								}
							}
						}
						
						/* Ball */
						ModeTimeBall++;
						if (ModeTimeBall >= 2)
						{
							ModeTimeBall = 0;
							switch (ModeStepBall)
							{
								case 0:
								{
										if (Grd.Ball[0].DutyR < ColorData[ModeColorBall][R]
											||Grd.Ball[0].DutyG < ColorData[ModeColorBall][G]
											||Grd.Ball[0].DutyB < ColorData[ModeColorBall][B])
										{
											FadeR = ColorData[ModeColorBall][R] / 25;
											FadeG = ColorData[ModeColorBall][G] / 25;
											FadeB = ColorData[ModeColorBall][B] / 25;
											for (TempLed = 0; TempLed < 4; TempLed++)
											{
												Grd.Ball[TempLed].DutyR += FadeR;
												Grd.Ball[TempLed].DutyG += FadeG;
												Grd.Ball[TempLed].DutyB += FadeB;
											}
										}
										else
										{
											ModeStepBall++;
										}
								} break;
								
								case 1:
								{
											if (Grd.Ball[0].DutyR > 0
												 ||Grd.Ball[0].DutyG > 0
												 ||Grd.Ball[0].DutyB > 0)
											{
												FadeR = ColorData[ModeColorBall][R] / 25;
												FadeG = ColorData[ModeColorBall][G] / 25;
												FadeB = ColorData[ModeColorBall][B] / 25;
												for (TempLed = 0; TempLed < 4; TempLed++)
												{
													Grd.Ball[TempLed].DutyR -= FadeR;
													Grd.Ball[TempLed].DutyG -= FadeG;
													Grd.Ball[TempLed].DutyB -= FadeB;
												}
											}
											else
											{
												ModeStepBall = 0;
												ModeColorBall++;
												if (ModeColorBall >= ColorNum)		ModeColorBall = 0;
											}
								} break;
							}
						}
						
						
						
						RndCnt24++;
						if (RndCnt24 >= 40)
						{
							RndCnt24 = 0;
							TempStep = 2;
							RndCnt30++;
							if (RndCnt30 > 2)
							{
								TempStep = 4;
								
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
					}
		} break;
		
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
		
		default:
		{
					TempStep = 0xFF;
		} break;
	}
}


/*
 * FunctionName		Show_3_1
 * Duration				TimeLine += 1830
 */
void Show_3_1(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		All_Color(0,0,0);
		
		TempStep 	= 0;
		TempColor	= 0;
		
		SpeedTime = 0;
		KeepTime	= 0;
		
		FadeR = ColorData[TempColor][R] / 25;
		FadeG = ColorData[TempColor][G] / 25;
		FadeB = ColorData[TempColor][B] / 25;
		return;
	}
	
	switch (TempStep)
	{
		case 0:
		{
					TempR = FadeR * 5;
					TempG = FadeG * 5;
					TempB = FadeB * 5;
					All_Color(TempR, TempG, TempB);
					
					SpeedTime++;
					if (SpeedTime > 10)
					{
						SpeedTime = 0;
						TempStep++;
						RndCnt10 = 0;
					}
		} break;
		
		case 1:
		{
					TempR += FadeR;
					TempG += FadeG;
					TempB += FadeB;
					All_Color(TempR, TempG, TempB);
					
					RndCnt10++;
					if (RndCnt10 >= 20)
					{
						RndCnt10 = 0;
						TempStep++;
						
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
							TempStep = 0;
							SpeedTime = 0;
							TempColor++;
							if (TempColor >= ColorNum)		TempColor = 0;
							FadeR = ColorData[TempColor][R] / 25;
							FadeG = ColorData[TempColor][G] / 25;
							FadeB = ColorData[TempColor][B] / 25;
							RndCnt10 = 0;
							SpeedTime = 0;
							
							KeepTime++;
							if (KeepTime > 2)
							{
								KeepTime = 0;
								TempStep = 3;
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
								
								for (TempCnt = 0; TempCnt < 3; TempCnt++)
								{
									ModeLedTree[TempCnt] = 0;
									ModeLedSnow[TempCnt] = 0;
									ModeLedSpot[TempCnt] = 0;
								}
								
								for (TempCnt = 0; TempCnt < 6; TempCnt++)
								{
									ModeLedCane[TempCnt] = 0;
								}
							}
						}
		} break;
		
		case 3:
		{
					/* Roof10 */
					if (RndCnt10 < 10)
					{
						do
						{
							RAND();
							ModeStep10[0] = (_Uint8)rand() % 10;
						} while(ModeLed10[ModeStep10[0]] == 1);
						ModeLed10[ModeStep10[0]] = 1;
						RndCnt10++;
					}
					else
					{
						RndCnt10 = 11;
					}
					
					/* Roof24 */
					if (RndCnt24 < 24)
					{
						do
						{
							RAND();
							ModeStep24[0] = (_Uint8)rand() % 24;
						} while(ModeLed24[ModeStep24[0]] == 1);
						ModeLed24[ModeStep24[0]] = 1;
						RndCnt24++;
					}
					else
					{
						RndCnt24 = 25;
					}
					
					/* Roof30 */
					if (RndCnt30 < 30)
					{
						do
						{
							RAND();
							ModeStep30[0] = (_Uint8)rand() % 30;
						} while(ModeLed30[ModeStep30[0]] == 1);
						ModeLed30[ModeStep30[0]] = 1;
						RndCnt30++;
					}
					else
					{
						RndCnt30 = 31;
					}
					
					/* Roof40 */
					if (RndCnt40 < 40)
					{
						do
						{
							RAND();
							ModeStep40[0] = (_Uint8)rand() % 40;
						} while(ModeLed40[ModeStep40[0]] == 1);
						ModeLed40[ModeStep40[0]] = 1;
						RndCnt40++;
					}
					else
					{
						RndCnt40 = 41;
					}
					
					/* String30 */
					if (RndCnts30 < 30)
					{
						do
						{
							RAND();
							ModeSteps30[0] = (_Uint8)rand() % 30;
						} while(ModeLeds30[ModeSteps30[0]] == 1);
						ModeLeds30[ModeSteps30[0]] = 1;
						RndCnts30++;
					}
					else
					{
						RndCnts30 = 31;
					}
					
					/* String24 */
					if (RndCnts24 < 24)
					{
						do
						{
							RAND();
							ModeSteps24[0] = (_Uint8)rand() % 24;
						} while(ModeLeds24[ModeSteps24[0]] == 1);
						ModeLeds24[ModeSteps24[0]] = 1;
						RndCnts24++;
					}
					else
					{
						RndCnts24 = 25;
					}
					
					/* String36 */
					if (RndCnts36 < 36)
					{
						do
						{
							RAND();
							ModeSteps36[0] = (_Uint8)rand() % 36;
						} while(ModeLeds36[ModeSteps36[0]] == 1);
						ModeLeds36[ModeSteps36[0]] = 1;
						RndCnts36++;
					}
					else
					{
						RndCnts36 = 37;
					}
					
					/* Tree */
					if (RndCntTree < 3)
					{
						do
						{
							RAND();
							ModeStepTree[0] = (_Uint8)rand() % 3;
						} while(ModeLedTree[ModeStepTree[0]] == 1);
						ModeLedTree[ModeStepTree[0]] = 1;
						RndCntTree++;
					}
					else
					{
						RndCntTree = 4;
					}
					
					/* Snow */
					if (RndCntSnow < 3)
					{
						do
						{
							RAND();
							ModeStepSnow[0] = (_Uint8)rand() % 3;
						} while(ModeLedSnow[ModeStepSnow[0]] == 1);
						ModeLedSnow[ModeStepSnow[0]] = 1;
						RndCntSnow++;
					}
					else
					{
						RndCntSnow = 4;
					}
					
					/* Spot */
					if (RndCntSpot < 3)
					{
						do
						{
							RAND();
							ModeStepSpot[0] = (_Uint8)rand() % 3;
						} while(ModeLedSpot[ModeStepSpot[0]] == 1);
						ModeLedSpot[ModeStepSpot[0]] = 1;
						RndCntSpot++;
					}
					else
					{
						RndCntSpot = 4;
					}
					
					
					/* Cane */
					if (RndCntCane < 6)
					{
						do
						{
							RAND();
							ModeStepCane[0] = (_Uint8)rand() % 6;
						} while(ModeLedCane[ModeStepCane[0]] == 1);
						ModeLedCane[ModeStepCane[0]] = 1;
						RndCntCane++;
					}
					else
					{
						RndCntCane = 7;
					}
					
					TempStep++;
					KeepTime = 0;
					TempR = 0;
					TempG = 0;
					TempB = 0;
					FadeR = ColorData[TempColor][R] / 25;
					FadeG = ColorData[TempColor][G] / 25;
					FadeB = ColorData[TempColor][B] / 25;
					
					if (RndCnt40 >= 40)
					{
						TempStep = 5;
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
							HoldTime10[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							ModeLed24[TempLed] = 0;
							RAND();
							HoldTime24[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							ModeLed30[TempLed] = 0;
							RAND();
							HoldTime30[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 40; TempLed++)
						{
							ModeLed40[TempLed] = 0;
							RAND();
							HoldTime40[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 30; TempLed++)
						{
							ModeLeds30[TempLed] = 0;
							RAND();
							HoldTimes30[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 24; TempLed++)
						{
							ModeLeds24[TempLed] = 0;
							RAND();
							HoldTimes24[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 36; TempLed++)
						{
							ModeLeds36[TempLed] = 0;
							RAND();
							HoldTimes36[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 3; TempLed++)
						{
							ModeLedTree[TempLed] = 0;
							RAND();
							HoldTimeTree[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 3; TempLed++)
						{
							ModeLedSnow[TempLed] = 0;
							RAND();
							HoldTimeSnow[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 3; TempLed++)
						{
							ModeLedSpot[TempLed] = 0;
							RAND();
							HoldTimeSpot[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						for (TempLed = 0; TempLed < 6; TempLed++)
						{
							ModeLedCane[TempLed] = 0;
							RAND();
							HoldTimeCane[TempLed] = (_Uint8)rand() % 20 + 10;
						}
						
						RAND();
						HoldTimeBall = (_Uint8)rand() % 10;
					}
		} break;
		
		case 4:
		{
					TempR += FadeR;
					TempG += FadeG;
					TempB += FadeB;
					
					if (RndCnt10 <= 10)
					{
						Roof10[ModeStep10[0]].DutyR += FadeR;
						Roof10[ModeStep10[0]].DutyG += FadeG;
						Roof10[ModeStep10[0]].DutyB += FadeB;
					}
					
					if (RndCnt24 <= 24)
					{
						Roof24[ModeStep24[0]].DutyR += FadeR;
						Roof24[ModeStep24[0]].DutyG += FadeG;
						Roof24[ModeStep24[0]].DutyB += FadeB;
					}
					
					if (RndCnt30 <= 30)
					{
						Roof30[ModeStep30[0]].DutyR += FadeR;
						Roof30[ModeStep30[0]].DutyG += FadeG;
						Roof30[ModeStep30[0]].DutyB += FadeB;
					}
					
					if (RndCnt40 <= 40)
					{
						Roof40[ModeStep40[0]].DutyR += FadeR;
						Roof40[ModeStep40[0]].DutyG += FadeG;
						Roof40[ModeStep40[0]].DutyB += FadeB;
					}
					
					if (RndCnts30 <= 30)
					{
							String30[ModeSteps30[0]].DutyR += FadeR;
							String30[ModeSteps30[0]].DutyG += FadeG;
							String30[ModeSteps30[0]].DutyB += FadeB;
					}
					
					if (RndCnts24 <= 24)
					{
							String24[ModeSteps24[0]].DutyR += FadeR;
							String24[ModeSteps24[0]].DutyG += FadeG;
							String24[ModeSteps24[0]].DutyB += FadeB;
					}
					
					if (RndCnts36 <= 36)
					{
							String36[ModeSteps36[0]].DutyR += FadeR;
							String36[ModeSteps36[0]].DutyG += FadeG;
							String36[ModeSteps36[0]].DutyB += FadeB;
					}
					
					if (RndCntTree <= 3)
					{
						for (TempCnt = 0; TempCnt < 9; TempCnt++)
						{
							Grd.Tree[TempCnt + ModeStepTree[0] * 9].DutyR += FadeR;
							Grd.Tree[TempCnt + ModeStepTree[0] * 9].DutyG += FadeG;
							Grd.Tree[TempCnt + ModeStepTree[0] * 9].DutyB += FadeB;
						}
					}
					
					if (RndCntSnow <= 3)
					{
						for (TempCnt = 0; TempCnt < 7; TempCnt++)
						{
							Grd.Snow[TempCnt + ModeStepSnow[0] * 7].DutyR += FadeR;
							Grd.Snow[TempCnt + ModeStepSnow[0] * 7].DutyG += FadeG;
							Grd.Snow[TempCnt + ModeStepSnow[0] * 7].DutyB += FadeB;
						}
					}
					
					if (RndCntCane <= 6)
					{
						for (TempCnt = 0; TempCnt < 5; TempCnt++)
						{
							Grd.Cane[TempCnt + ModeStepCane[0] * 5].DutyR += FadeR;
							Grd.Cane[TempCnt + ModeStepCane[0] * 5].DutyG += FadeG;
							Grd.Cane[TempCnt + ModeStepCane[0] * 5].DutyB += FadeB;
						}
					}
						
					if (RndCntSpot <= 3)
					{
						Grd.Spot[ModeStepSpot[0]].DutyR += FadeR;
						Grd.Spot[ModeStepSpot[0]].DutyG += FadeG;
						Grd.Spot[ModeStepSpot[0]].DutyB += FadeB;
					}
					
					if (RndCntBall <= 1)
					{
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR += FadeR;
							Grd.Ball[TempCnt].DutyG += FadeG;
							Grd.Ball[TempCnt].DutyB += FadeB;
						}
					}
					
					
					KeepTime++;
					if (KeepTime >= 25)
					{
						TempStep = 3;
						RndCntBall = 2;
						TempColor++;
						if (TempColor >= ColorNum)  TempColor = 0;
					}
		} break;
		
		case 5:
		{
					All_Color(0,0,0);
					TempStep++;
		} break;
		
		case 6:
		case 7:
		case 8:
		{
					/* Roof10 */
					for (TempLed = 0; TempLed < 10; TempLed++)
					{
						if (TempLed % 2 == 0)
						{
							ModeTime10[TempLed]++;
							if (ModeTime10[TempLed] >= 3)
							{
								ModeTime10[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStep10[TempLed])
								{
									case 0:
									{
												if (Roof10[TempLed].DutyR > 0
														|| Roof10[TempLed].DutyG > 0
															|| Roof10[TempLed].DutyB > 0)
												{
													Roof10[TempLed].DutyR -= FadeR;
													Roof10[TempLed].DutyG -= FadeG;
													Roof10[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeStep10[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Roof10[TempLed].DutyR < ColorData[TempColor][R]
														|| Roof10[TempLed].DutyG < ColorData[TempColor][G]
															|| Roof10[TempLed].DutyB < ColorData[TempColor][B])
												{
													Roof10[TempLed].DutyR += FadeR;
													Roof10[TempLed].DutyG += FadeG;
													Roof10[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeStep10[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTime10[TempLed]++;
							if (ModeTime10[TempLed] > HoldTime10[TempLed])
							{
								ModeTime10[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStep10[TempLed])
								{
									case 0:
									{
												Roof10[TempLed].DutyR = ColorData[TempColor][R] / 2;
												Roof10[TempLed].DutyG = ColorData[TempColor][G] / 2;
												Roof10[TempLed].DutyB = ColorData[TempColor][B] / 2;
												ModeStep10[TempLed]++;
									} break;
									
									default:
									{
												Roof10[TempLed].DutyR = ColorData[TempColor][R];
												Roof10[TempLed].DutyG = ColorData[TempColor][G];
												Roof10[TempLed].DutyB = ColorData[TempColor][B];
												ModeStep10[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Roof24 */
					for (TempLed = 0; TempLed < 24; TempLed++)
					{
						if (TempLed % 2 == 0)
						{
							ModeTime24[TempLed]++;
							if (ModeTime24[TempLed] >= 3)
							{
								ModeTime24[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStep24[TempLed])
								{
									case 0:
									{
												if (Roof24[TempLed].DutyR > 0
														|| Roof24[TempLed].DutyG > 0
															|| Roof24[TempLed].DutyB > 0)
												{
													Roof24[TempLed].DutyR -= FadeR;
													Roof24[TempLed].DutyG -= FadeG;
													Roof24[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeStep24[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Roof24[TempLed].DutyR < ColorData[TempColor][R]
														|| Roof24[TempLed].DutyG < ColorData[TempColor][G]
															|| Roof24[TempLed].DutyB < ColorData[TempColor][B])
												{
													Roof24[TempLed].DutyR += FadeR;
													Roof24[TempLed].DutyG += FadeG;
													Roof24[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeStep24[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTime24[TempLed]++;
							if (ModeTime24[TempLed] > HoldTime24[TempLed])
							{
								ModeTime24[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStep24[TempLed])
								{
									case 0:
									{
												Roof24[TempLed].DutyR = ColorData[TempColor][R] / 2;
												Roof24[TempLed].DutyG = ColorData[TempColor][G] / 2;
												Roof24[TempLed].DutyB = ColorData[TempColor][B] / 2;
												ModeStep24[TempLed]++;
									} break;
									
									default:
									{
												Roof24[TempLed].DutyR = ColorData[TempColor][R];
												Roof24[TempLed].DutyG = ColorData[TempColor][G];
												Roof24[TempLed].DutyB = ColorData[TempColor][B];
												ModeStep24[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Roof30 */
					for (TempLed = 0; TempLed < 30; TempLed++)
					{
						if (TempLed % 2 == 0)
						{
							ModeTime30[TempLed]++;
							if (ModeTime30[TempLed] >= 3)
							{
								ModeTime30[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStep30[TempLed])
								{
									case 0:
									{
												if (Roof30[TempLed].DutyR > 0
														|| Roof30[TempLed].DutyG > 0
															|| Roof30[TempLed].DutyB > 0)
												{
													Roof30[TempLed].DutyR -= FadeR;
													Roof30[TempLed].DutyG -= FadeG;
													Roof30[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeStep30[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Roof30[TempLed].DutyR < ColorData[TempColor][R]
														|| Roof30[TempLed].DutyG < ColorData[TempColor][G]
															|| Roof30[TempLed].DutyB < ColorData[TempColor][B])
												{
													Roof30[TempLed].DutyR += FadeR;
													Roof30[TempLed].DutyG += FadeG;
													Roof30[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeStep30[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTime30[TempLed]++;
							if (ModeTime30[TempLed] > HoldTime30[TempLed])
							{
								ModeTime30[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStep30[TempLed])
								{
									case 0:
									{
												Roof30[TempLed].DutyR = ColorData[TempColor][R] / 2;
												Roof30[TempLed].DutyG = ColorData[TempColor][G] / 2;
												Roof30[TempLed].DutyB = ColorData[TempColor][B] / 2;
												ModeStep30[TempLed]++;
									} break;
									
									default:
									{
												Roof30[TempLed].DutyR = ColorData[TempColor][R];
												Roof30[TempLed].DutyG = ColorData[TempColor][G];
												Roof30[TempLed].DutyB = ColorData[TempColor][B];
												ModeStep30[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Roof40 */
					for (TempLed = 0; TempLed < 40; TempLed++)
					{
						if (TempLed % 2 == 0)
						{
							ModeTime40[TempLed]++;
							if (ModeTime40[TempLed] >= 3)
							{
								ModeTime40[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStep40[TempLed])
								{
									case 0:
									{
												if (Roof40[TempLed].DutyR > 0
														|| Roof40[TempLed].DutyG > 0
															|| Roof40[TempLed].DutyB > 0)
												{
													Roof40[TempLed].DutyR -= FadeR;
													Roof40[TempLed].DutyG -= FadeG;
													Roof40[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeStep40[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Roof40[TempLed].DutyR < ColorData[TempColor][R]
														|| Roof40[TempLed].DutyG < ColorData[TempColor][G]
															|| Roof40[TempLed].DutyB < ColorData[TempColor][B])
												{
													Roof40[TempLed].DutyR += FadeR;
													Roof40[TempLed].DutyG += FadeG;
													Roof40[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeStep40[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTime40[TempLed]++;
							if (ModeTime40[TempLed] > HoldTime40[TempLed])
							{
								ModeTime40[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStep40[TempLed])
								{
									case 0:
									{
												Roof40[TempLed].DutyR = ColorData[TempColor][R] / 2;
												Roof40[TempLed].DutyG = ColorData[TempColor][G] / 2;
												Roof40[TempLed].DutyB = ColorData[TempColor][B] / 2;
												ModeStep40[TempLed]++;
									} break;
									
									default:
									{
												Roof40[TempLed].DutyR = ColorData[TempColor][R];
												Roof40[TempLed].DutyG = ColorData[TempColor][G];
												Roof40[TempLed].DutyB = ColorData[TempColor][B];
												ModeStep40[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* String30 */
					for (TempLed = 0; TempLed < 30; TempLed++)
					{
						if (TempLed % 2 == 0)
						{
							ModeTimes30[TempLed]++;
							if (ModeTimes30[TempLed] >= 3)
							{
								ModeTimes30[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeSteps30[TempLed])
								{
									case 0:
									{
												if (String30[TempLed].DutyR > 0
														|| String30[TempLed].DutyG > 0
															|| String30[TempLed].DutyB > 0)
												{
														String30[TempLed].DutyR -= FadeR;
														String30[TempLed].DutyG -= FadeG;
														String30[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeSteps30[TempLed]++;
												}
									} break;
									
									default:
									{
												if (String30[TempLed].DutyR < ColorData[TempColor][R]
														|| String30[TempLed].DutyG < ColorData[TempColor][G]
															|| String30[TempLed].DutyB < ColorData[TempColor][B])
												{
														String30[TempLed].DutyR += FadeR;
														String30[TempLed].DutyG += FadeG;
														String30[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeSteps30[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTimes30[TempLed]++;
							if (ModeTimes30[TempLed] > HoldTimes30[TempLed])
							{
								ModeTimes30[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeSteps30[TempLed])
								{
									case 0:
									{
												String30[TempLed].DutyR = ColorData[TempColor][R] / 2;
												String30[TempLed].DutyG = ColorData[TempColor][G] / 2;
												String30[TempLed].DutyB = ColorData[TempColor][B] / 2;
												ModeSteps30[TempLed]++;
									} break;
									
									default:
									{
												String30[TempLed].DutyR = ColorData[TempColor][R];
												String30[TempLed].DutyG = ColorData[TempColor][G];
												String30[TempLed].DutyB = ColorData[TempColor][B];
												ModeSteps30[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* String24 */
					for (TempLed = 0; TempLed < 24; TempLed++)
					{
						if (TempLed % 2 == 0)
						{
							ModeTimes24[TempLed]++;
							if (ModeTimes24[TempLed] >= 3)
							{
								ModeTimes24[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeSteps24[TempLed])
								{
									case 0:
									{
												if (String24[TempLed].DutyR > 0
														|| String24[TempLed].DutyG > 0
															|| String24[TempLed].DutyB > 0)
												{
														String24[TempLed].DutyR -= FadeR;
														String24[TempLed].DutyG -= FadeG;
														String24[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeSteps24[TempLed]++;
												}
									} break;
									
									default:
									{
												if (String24[TempLed].DutyR < ColorData[TempColor][R]
														|| String24[TempLed].DutyG < ColorData[TempColor][G]
															|| String24[TempLed].DutyB < ColorData[TempColor][B])
												{
														String24[TempLed].DutyR += FadeR;
														String24[TempLed].DutyG += FadeG;
														String24[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeSteps24[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTimes24[TempLed]++;
							if (ModeTimes24[TempLed] > HoldTimes24[TempLed])
							{
								ModeTimes24[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeSteps24[TempLed])
								{
									case 0:
									{
												String24[TempLed].DutyR = ColorData[TempColor][R] / 2;
												String24[TempLed].DutyG = ColorData[TempColor][G] / 2;
												String24[TempLed].DutyB = ColorData[TempColor][B] / 2;
												ModeSteps24[TempLed]++;
									} break;
									
									default:
									{
												String24[TempLed].DutyR = ColorData[TempColor][R];
												String24[TempLed].DutyG = ColorData[TempColor][G];
												String24[TempLed].DutyB = ColorData[TempColor][B];
												ModeSteps24[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* String36 */
					for (TempLed = 0; TempLed < 36; TempLed++)
					{
						if (TempLed % 2 == 0)
						{
							ModeTimes36[TempLed]++;
							if (ModeTimes36[TempLed] >= 3)
							{
								ModeTimes36[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeSteps36[TempLed])
								{
									case 0:
									{
												if (String36[TempLed].DutyR > 0
														|| String36[TempLed].DutyG > 0
															|| String36[TempLed].DutyB > 0)
												{
														String36[TempLed].DutyR -= FadeR;
														String36[TempLed].DutyG -= FadeG;
														String36[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeSteps36[TempLed]++;
												}
									} break;
									
									default:
									{
												if (String36[TempLed].DutyR < ColorData[TempColor][R]
														|| String36[TempLed].DutyG < ColorData[TempColor][G]
															|| String36[TempLed].DutyB < ColorData[TempColor][B])
												{
														String36[TempLed].DutyR += FadeR;
														String36[TempLed].DutyG += FadeG;
														String36[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeSteps36[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTimes36[TempLed]++;
							if (ModeTimes36[TempLed] > HoldTimes36[TempLed])
							{
								ModeTimes36[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeSteps36[TempLed])
								{
									case 0:
									{
												String36[TempLed].DutyR = ColorData[TempColor][R] / 2;
												String36[TempLed].DutyG = ColorData[TempColor][G] / 2;
												String36[TempLed].DutyB = ColorData[TempColor][B] / 2;
												ModeSteps36[TempLed]++;
									} break;
									
									default:
									{
												String36[TempLed].DutyR = ColorData[TempColor][R];
												String36[TempLed].DutyG = ColorData[TempColor][G];
												String36[TempLed].DutyB = ColorData[TempColor][B];
												ModeSteps36[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Tree */
					for (TempLed = 0; TempLed < 3; TempLed++)
					{
						if (TempLed % 3 == 1)
						{
							ModeTimeTree[TempLed]++;
							if (ModeTimeTree[TempLed] >= 3)
							{
								ModeTimeTree[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStepTree[TempLed])
								{
									case 0:
									{
												if (Grd.Tree[TempLed * 9].DutyR > 0
														|| Grd.Tree[TempLed * 9].DutyG > 0
															|| Grd.Tree[TempLed * 9].DutyB > 0)
												{
													for (TempCnt = 0; TempCnt < 9; TempCnt++)
													{
														Grd.Tree[TempLed * 9 + TempCnt].DutyR -= FadeR;
														Grd.Tree[TempLed * 9 + TempCnt].DutyG -= FadeG;
														Grd.Tree[TempLed * 9 + TempCnt].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepTree[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Grd.Tree[TempLed * 9].DutyR < ColorData[TempColor][R]
														|| Grd.Tree[TempLed * 9].DutyG < ColorData[TempColor][G]
															|| Grd.Tree[TempLed * 9].DutyB < ColorData[TempColor][B])
												{
													for (TempCnt = 0; TempCnt < 9; TempCnt++)
													{
														Grd.Tree[TempLed * 9 + TempCnt].DutyR += FadeR;
														Grd.Tree[TempLed * 9 + TempCnt].DutyG += FadeG;
														Grd.Tree[TempLed * 9 + TempCnt].DutyB += FadeB;
													}
												}
												else
												{
													ModeStepTree[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTimeTree[TempLed]++;
							if (ModeTimeTree[TempLed] > HoldTimeTree[TempLed])
							{
								ModeTimeTree[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStepTree[TempLed])
								{
									case 0:
									{
												for (TempCnt = 0; TempCnt < 9; TempCnt++)
												{
													Grd.Tree[TempLed * 9 + TempCnt].DutyR = ColorData[TempColor][R] / 2;
													Grd.Tree[TempLed * 9 + TempCnt].DutyG = ColorData[TempColor][G] / 2;
													Grd.Tree[TempLed * 9 + TempCnt].DutyB = ColorData[TempColor][B] / 2;
												}
												ModeStepTree[TempLed]++;
									} break;
									
									default:
									{
												for (TempCnt = 0; TempCnt < 9; TempCnt++)
												{
													Grd.Tree[TempLed * 9 + TempCnt].DutyR = ColorData[TempColor][R];
													Grd.Tree[TempLed * 9 + TempCnt].DutyG = ColorData[TempColor][G];
													Grd.Tree[TempLed * 9 + TempCnt].DutyB = ColorData[TempColor][B];
												}
												ModeStepTree[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Snow */
					for (TempLed = 0; TempLed < 3; TempLed++)
					{
						if (TempLed % 3 == 1)
						{
							ModeTimeSnow[TempLed]++;
							if (ModeTimeSnow[TempLed] >= 3)
							{
								ModeTimeSnow[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStepSnow[TempLed])
								{
									case 0:
									{
												if (Grd.Snow[TempLed * 7].DutyR > 0
														|| Grd.Snow[TempLed * 7].DutyG > 0
															|| Grd.Snow[TempLed * 7].DutyB > 0)
												{
													for (TempCnt = 0; TempCnt < 7; TempCnt++)
													{
														Grd.Snow[TempLed * 7 + TempCnt].DutyR -= FadeR;
														Grd.Snow[TempLed * 7 + TempCnt].DutyG -= FadeG;
														Grd.Snow[TempLed * 7 + TempCnt].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepSnow[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Grd.Snow[TempLed * 7].DutyR < ColorData[TempColor][R]
														|| Grd.Snow[TempLed * 7].DutyG < ColorData[TempColor][G]
															|| Grd.Snow[TempLed * 7].DutyB < ColorData[TempColor][B])
												{
													for (TempCnt = 0; TempCnt < 7; TempCnt++)
													{
														Grd.Snow[TempLed * 7 + TempCnt].DutyR += FadeR;
														Grd.Snow[TempLed * 7 + TempCnt].DutyG += FadeG;
														Grd.Snow[TempLed * 7 + TempCnt].DutyB += FadeB;
													}
												}
												else
												{
													ModeStepSnow[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTimeSnow[TempLed]++;
							if (ModeTimeSnow[TempLed] > HoldTimeSnow[TempLed])
							{
								ModeTimeSnow[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStepSnow[TempLed])
								{
									case 0:
									{
												for (TempCnt = 0; TempCnt < 7; TempCnt++)
												{
													Grd.Snow[TempLed * 7 + TempCnt].DutyR = ColorData[TempColor][R] / 2;
													Grd.Snow[TempLed * 7 + TempCnt].DutyG = ColorData[TempColor][G] / 2;
													Grd.Snow[TempLed * 7 + TempCnt].DutyB = ColorData[TempColor][B] / 2;
												}
												ModeStepSnow[TempLed]++;
									} break;
									
									default:
									{
												for (TempCnt = 0; TempCnt < 7; TempCnt++)
												{
													Grd.Snow[TempLed * 7 + TempCnt].DutyR = ColorData[TempColor][R];
													Grd.Snow[TempLed * 7 + TempCnt].DutyG = ColorData[TempColor][G];
													Grd.Snow[TempLed * 7 + TempCnt].DutyB = ColorData[TempColor][B];
												}
												ModeStepSnow[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Cane */
					for (TempLed = 0; TempLed < 6; TempLed++)
					{
						if (TempLed % 3 == 1)
						{
							ModeTimeCane[TempLed]++;
							if (ModeTimeCane[TempLed] >= 3)
							{
								ModeTimeCane[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStepCane[TempLed])
								{
									case 0:
									{
												if (Grd.Cane[TempLed * 5].DutyR > 0
														|| Grd.Cane[TempLed * 5].DutyG > 0
															|| Grd.Cane[TempLed * 5].DutyB > 0)
												{
													for (TempCnt = 0; TempCnt < 5; TempCnt++)
													{
														Grd.Cane[TempLed * 5 + TempCnt].DutyR -= FadeR;
														Grd.Cane[TempLed * 5 + TempCnt].DutyG -= FadeG;
														Grd.Cane[TempLed * 5 + TempCnt].DutyB -= FadeB;
													}
												}
												else
												{
													ModeStepCane[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Grd.Cane[TempLed * 5].DutyR < ColorData[TempColor][R]
														|| Grd.Cane[TempLed * 5].DutyG < ColorData[TempColor][G]
															|| Grd.Cane[TempLed * 5].DutyB < ColorData[TempColor][B])
												{
													for (TempCnt = 0; TempCnt < 5; TempCnt++)
													{
														Grd.Cane[TempLed * 5 + TempCnt].DutyR += FadeR;
														Grd.Cane[TempLed * 5 + TempCnt].DutyG += FadeG;
														Grd.Cane[TempLed * 5 + TempCnt].DutyB += FadeB;
													}
												}
												else
												{
													ModeStepCane[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTimeCane[TempLed]++;
							if (ModeTimeCane[TempLed] > HoldTimeCane[TempLed])
							{
								ModeTimeCane[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStepCane[TempLed])
								{
									case 0:
									{
												for (TempCnt = 0; TempCnt < 5; TempCnt++)
												{
													Grd.Cane[TempLed * 5 + TempCnt].DutyR = ColorData[TempColor][R] / 2;
													Grd.Cane[TempLed * 5 + TempCnt].DutyG = ColorData[TempColor][G] / 2;
													Grd.Cane[TempLed * 5 + TempCnt].DutyB = ColorData[TempColor][B] / 2;
												}
												ModeStepCane[TempLed]++;
									} break;
									
									default:
									{
												for (TempCnt = 0; TempCnt < 5; TempCnt++)
												{
													Grd.Cane[TempLed * 5 + TempCnt].DutyR = ColorData[TempColor][R];
													Grd.Cane[TempLed * 5 + TempCnt].DutyG = ColorData[TempColor][G];
													Grd.Cane[TempLed * 5 + TempCnt].DutyB = ColorData[TempColor][B];
												}
												ModeStepCane[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Spot */
					for (TempLed = 0; TempLed < 3; TempLed++)
					{
						if (TempLed % 3 == 1)
						{
							ModeTimeSpot[TempLed]++;
							if (ModeTimeSpot[TempLed] >= 3)
							{
								ModeTimeSpot[TempLed] = 0;
								TempColor = TempLed % ColorNum;
								FadeR = ColorData[TempColor][R] / 25;
								FadeG = ColorData[TempColor][G] / 25;
								FadeB = ColorData[TempColor][B] / 25;
								
								switch (ModeStepSpot[TempLed])
								{
									case 0:
									{
												if (Grd.Spot[TempLed].DutyR > 0
														|| Grd.Spot[TempLed].DutyG > 0
															|| Grd.Spot[TempLed].DutyB > 0)
												{
													Grd.Spot[TempLed].DutyR -= FadeR;
													Grd.Spot[TempLed].DutyG -= FadeG;
													Grd.Spot[TempLed].DutyB -= FadeB;
												}
												else
												{
													ModeStepSpot[TempLed]++;
												}
									} break;
									
									default:
									{
												if (Grd.Spot[TempLed].DutyR < ColorData[TempColor][R]
														|| Grd.Spot[TempLed].DutyG < ColorData[TempColor][G]
															|| Grd.Spot[TempLed].DutyB < ColorData[TempColor][B])
												{
														Grd.Spot[TempLed].DutyR += FadeR;
														Grd.Spot[TempLed].DutyG += FadeG;
														Grd.Spot[TempLed].DutyB += FadeB;
												}
												else
												{
													ModeStepSpot[TempLed] = 0;
												}
									} break;
								}
							}
						}
						
						else
						{
							ModeTimeSpot[TempLed]++;
							if (ModeTimeSpot[TempLed] > HoldTimeSpot[TempLed])
							{
								ModeTimeSpot[TempLed] = 0;
								TempColor = TempLed % ColorNum;
	
								switch (ModeStepSpot[TempLed])
								{
									case 0:
									{
												Grd.Spot[TempLed].DutyR += ColorData[TempColor][R] / 2;
												Grd.Spot[TempLed].DutyG += ColorData[TempColor][G] / 2;
												Grd.Spot[TempLed].DutyB += ColorData[TempColor][B] / 2;
												ModeStepSpot[TempLed]++;
									} break;
									
									default:
									{
												Grd.Spot[TempLed].DutyR += ColorData[TempColor][R];
												Grd.Spot[TempLed].DutyG += ColorData[TempColor][G];
												Grd.Spot[TempLed].DutyB += ColorData[TempColor][B];
												ModeStepSpot[TempLed] = 0;
									} break;
								}
							}
						}
					}
					
					/* Ball */
					ModeTimeBall++;
					if (ModeTimeBall >= 3)
					{
						ModeTimeBall = 0;
						FadeR = ColorData[0][R] / 25;
						FadeG = ColorData[0][G] / 25;
						FadeB = ColorData[0][B] / 25;
						
						switch (ModeStepBall)
						{
							case 0:
							{
										if (Grd.Ball[0].DutyR > 0
												|| Grd.Ball[0].DutyG > 0
													|| Grd.Ball[0].DutyB > 0)
										{
											for (TempLed = 0; TempLed < 4; TempLed++)
											{
												Grd.Ball[TempLed].DutyR -= FadeR;
												Grd.Ball[TempLed].DutyG -= FadeG;
												Grd.Ball[TempLed].DutyB -= FadeB;
											}
										}
										else
										{
											ModeStepBall++;
										}
							} break;
							
							default:
							{
										if (Grd.Ball[0].DutyR < ColorData[0][R]
												|| Grd.Ball[0].DutyG < ColorData[0][G]
													|| Grd.Ball[0].DutyB < ColorData[0][B])
										{
											for (TempLed = 0; TempLed < 4; TempLed++)
											{
												Grd.Ball[TempLed].DutyR += FadeR;
												Grd.Ball[TempLed].DutyG += FadeG;
												Grd.Ball[TempLed].DutyB += FadeB;
											}
										}
										else
										{
											ModeStepBall = 0;
										}
							} break;
						}
					}
					
					
					
					
					SpeedTime++;
					if (SpeedTime > 200)
					{
						SpeedTime = 0;
						TempStep++;
					}
		} break;
		
		default:
		{
					TempStep = 0xFF;		
		} break;
	}
}



/*
 * FunctionName	Show_3_2
 * TimeLine		+= 1410
 */
void Show_3_2(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		TempStep 	= 0;
		SpeedTime = 0;
		TempR			= 255;
		TempG			= 0;
		TempB			= 0;
		KeepTime	= 0;
		
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
	
	switch (TempStep)
	{
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
						
						Roof30[TempLed].DutyR	= TempR;
						Roof30[TempLed].DutyG	= TempG;
						Roof30[TempLed].DutyB	= TempB;
						
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
						
						Roof10[TempLed].DutyR	= TempR;
						Roof10[TempLed].DutyG	= TempG;
						Roof10[TempLed].DutyB	= TempB;
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
						
						Roof24[TempLed].DutyR	= TempR;
						Roof24[TempLed].DutyG	= TempG;
						Roof24[TempLed].DutyB	= TempB;
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
						
						Roof40[TempLed].DutyR	= TempR;
						Roof40[TempLed].DutyG	= TempG;
						Roof40[TempLed].DutyB	= TempB;
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

						String30[TempLed].DutyR	= TempR;
						String30[TempLed].DutyG	= TempG;
						String30[TempLed].DutyB	= TempB;
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

						String24[TempLed].DutyR	= TempR;
						String24[TempLed].DutyG	= TempG;
						String24[TempLed].DutyB	= TempB;
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

						String36[TempLed].DutyR	= TempR;
						String36[TempLed].DutyG	= TempG;
						String36[TempLed].DutyB	= TempB;
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
						
						Grd.Snow[ModeLedSnow[0]].DutyR	= TempR;
						Grd.Snow[ModeLedSnow[0]].DutyG	= TempG;
						Grd.Snow[ModeLedSnow[0]].DutyB	= TempB;

						Grd.Snow[ModeLedSnow[1]].DutyR	= TempR;
						Grd.Snow[ModeLedSnow[1]].DutyG	= TempG;
						Grd.Snow[ModeLedSnow[1]].DutyB	= TempB;
						
						Grd.Snow[ModeLedSnow[2]].DutyR	= TempR;
						Grd.Snow[ModeLedSnow[2]].DutyG	= TempG;
						Grd.Snow[ModeLedSnow[2]].DutyB	= TempB;
					}
					
					/* Cane */
					if (RndCntCane < 6)
					{
						for (TempCnt = 0; TempCnt < 5; TempCnt++)
						{
							Grd.Cane[RndCntCane * 5 + TempCnt].DutyR	= TempR;
							Grd.Cane[RndCntCane * 5 + TempCnt].DutyG	= TempG;
							Grd.Cane[RndCntCane * 5 + TempCnt].DutyB	= TempB;
						}
						
						RndCntCane++;
					}
					
					/* Spot */
					if (RndCntSpot < 3)
					{
						Grd.Spot[RndCntSpot].DutyR	= TempR;
						Grd.Spot[RndCntSpot].DutyG	= TempG;
						Grd.Spot[RndCntSpot].DutyB	= TempB;
						RndCntSpot++;
					}
					
					/* Ball */
					for (TempCnt = 0; TempCnt < 4; TempCnt++)
					{
						Grd.Ball[TempCnt].DutyR = TempR;
						Grd.Ball[TempCnt].DutyG = TempG;
						Grd.Ball[TempCnt].DutyB = TempB;
					}
					
					if (RndCnt40 >= 40)
					{
						TempStep++;
					}
				}
		} break;
		
		case 1:
		{
					if (TempG < 255)			TempG += 15;
					else									TempStep++;
					
					All_Color(TempR, TempG, TempB);
		} break;
		
		case 2:
		{
					if (TempR > 0)				TempR -= 15;
					else									TempStep++;
					
					All_Color(TempR, TempG, TempB);
		} break;
		
		case 3:
		{
					if (TempB < 255)			TempB += 15;
					else									TempStep++;
					
					All_Color(TempR, TempG, TempB);
		} break;
		
		case 4:
		{
					if (TempG > 0)				TempG -= 15;
					else									TempStep++;
					
					All_Color(TempR, TempG, TempB);
		} break;
		
		case 5:
		{
					if (TempR < 255)			TempR += 15;
					else									TempStep++;
					
					All_Color(TempR, TempG, TempB);
		} break;
		
		default:
		{
					TempStep = 0xFF;		
		} break;
	}
}

/*
 * FunctionName		Show_3_3
 * Duration				TimeLine += 900 
 */
void Show_3_3(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		TempStep 	= 0;
		TempColor	= 0;
		SpeedTime = 0;
		KeepTime	= 0;
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
					
					/* Tree */
					Grd.Spot[0].DutyR = ColorData[TempColor][R];
					Grd.Spot[0].DutyG = ColorData[TempColor][G];
					Grd.Spot[0].DutyB = ColorData[TempColor][B];
					
					/* Ball */
					for (TempLed = 0; TempLed < 4; TempLed++)
					{
						Grd.Ball[TempLed].DutyR = ColorData[TempColor][R];
						Grd.Ball[TempLed].DutyG = ColorData[TempColor][G];
						Grd.Ball[TempLed].DutyB = ColorData[TempColor][B];
					}
					
					KeepTime++;
					if (KeepTime >= 50)
					{
						KeepTime = 0;
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
					
					/* Tree */
					Grd.Spot[1].DutyR = ColorData[TempColor][R];
					Grd.Spot[1].DutyG = ColorData[TempColor][G];
					Grd.Spot[1].DutyB = ColorData[TempColor][B];
					
					/* Ball */
					for (TempLed = 0; TempLed < 4; TempLed++)
					{
						Grd.Ball[TempLed].DutyR = ColorData[TempColor][R];
						Grd.Ball[TempLed].DutyG = ColorData[TempColor][G];
						Grd.Ball[TempLed].DutyB = ColorData[TempColor][B];
					}
					
					KeepTime++;
					if (KeepTime >= 50)
					{
						KeepTime = 0;
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
					
					/* Tree */
					Grd.Spot[2].DutyR = ColorData[TempColor][R];
					Grd.Spot[2].DutyG = ColorData[TempColor][G];
					Grd.Spot[2].DutyB = ColorData[TempColor][B];
					
					/* Ball */
					for (TempLed = 0; TempLed < 4; TempLed++)
					{
						Grd.Ball[TempLed].DutyR = ColorData[TempColor][R];
						Grd.Ball[TempLed].DutyG = ColorData[TempColor][G];
						Grd.Ball[TempLed].DutyB = ColorData[TempColor][B];
					}
					
					KeepTime++;
					if (KeepTime >= 50)
					{
						KeepTime = 0;
						TempColor++;
						if (TempColor >= ColorNum)	TempColor = 0;
						TempStep++;
					}
		} break;
		
		case 3:
		{
					TempR = ColorData[TempColor][R];
					TempG = ColorData[TempColor][G];
					TempB = ColorData[TempColor][B];
					All_Color(TempR, TempG, TempB);
					
					KeepTime++;
					if (KeepTime >= 50)
					{
						KeepTime = 0;
						FadeR = ColorData[TempColor][R] / 25;
						FadeG = ColorData[TempColor][G] / 25;
						FadeB = ColorData[TempColor][B] / 25;
						TempStep++;
						RndCnt10 = 0;
					}
		} break;
		
		case 4:
		{
					TempR -= FadeR;
					TempG -= FadeG;
					TempB -= FadeB;
					All_Color(TempR, TempG, TempB);
					RndCnt10++;
					if (RndCnt10 >= 25)
					{
						RndCnt10 = 0;
						TempStep = 0;
						TempColor++;
						if (TempColor >= ColorNum)  TempColor = 0;
						SpeedTime++;
						if (SpeedTime > 3)
						{
							TempStep = 5;
						}
					}
		} break;
		
		default:
		{
					TempStep = 0xFF;		
		} break;
	}
}


/**
 * FunctionName  Show_3_4
 * TimeLine
 */
void Show_3_4(void)
{
	/* Initalize */
	if (ShowInit == TRUE)
	{
		ShowInit = FALSE;
		
		
		
		TempStep 	= 0;
		TempColor	= 0;
		SpeedTime = 0;
		KeepTime	= 0;
		
		TempR = 255;
		TempG = 0;
		TempB = 0;
		
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
	
	switch (TempStep)
	{
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
							
							Roof30[TempLed].DutyR	= TempR;
							Roof30[TempLed].DutyG	= TempG;
							Roof30[TempLed].DutyB	= TempB;
							
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
							
							Roof10[TempLed].DutyR	= TempR;
							Roof10[TempLed].DutyG	= TempG;
							Roof10[TempLed].DutyB	= TempB;
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
							
							Roof24[TempLed].DutyR	= TempR;
							Roof24[TempLed].DutyG	= TempG;
							Roof24[TempLed].DutyB	= TempB;
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
							
							Roof40[TempLed].DutyR	= TempR;
							Roof40[TempLed].DutyG	= TempG;
							Roof40[TempLed].DutyB	= TempB;
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
							
							String30[TempLed].DutyR	= TempR;
							String30[TempLed].DutyG	= TempG;
							String30[TempLed].DutyB	= TempB;
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
							
							String24[TempLed].DutyR	= TempR;
							String24[TempLed].DutyG	= TempG;
							String24[TempLed].DutyB	= TempB;
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
							
							String36[TempLed].DutyR	= TempR;
							String36[TempLed].DutyG	= TempG;
							String36[TempLed].DutyB	= TempB;
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
							
							Grd.Snow[ModeLedSnow[0]].DutyR	= TempR;
							Grd.Snow[ModeLedSnow[0]].DutyG	= TempG;
							Grd.Snow[ModeLedSnow[0]].DutyB	= TempB;

							Grd.Snow[ModeLedSnow[1]].DutyR	= TempR;
							Grd.Snow[ModeLedSnow[1]].DutyG	= TempG;
							Grd.Snow[ModeLedSnow[1]].DutyB	= TempB;
							
							Grd.Snow[ModeLedSnow[2]].DutyR	= TempR;
							Grd.Snow[ModeLedSnow[2]].DutyG	= TempG;
							Grd.Snow[ModeLedSnow[2]].DutyB	= TempB;
						}
						
						/* Cane */
						if (RndCntCane < 6)
						{
							for (TempCnt = 0; TempCnt < 5; TempCnt++)
							{
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyR	= TempR;
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyG	= TempG;
								Grd.Cane[RndCntCane * 5 + TempCnt].DutyB	= TempB;
							}
							
							RndCntCane++;
						}
						
						/* Spot */
						if (RndCntSpot < 3)
						{
							Grd.Spot[RndCntSpot].DutyR	= TempR;
							Grd.Spot[RndCntSpot].DutyG	= TempG;
							Grd.Spot[RndCntSpot].DutyB	= TempB;
							RndCntSpot++;
						}
						
						/* Ball */
						for (TempCnt = 0; TempCnt < 4; TempCnt++)
						{
							Grd.Ball[TempCnt].DutyR = TempR;
							Grd.Ball[TempCnt].DutyG = TempG;
							Grd.Ball[TempCnt].DutyB = TempB;
						}
						
						if (RndCnt40 >= 40)
						{
							TempStep++;
							TempColor = 1;
							ModeColor10[0] = 0;
							ModeColor10[1] = 1;
							for (TempCnt = 0;TempCnt < 8; TempCnt++)
							{
								ModeLed10[TempCnt] = 0;
								ModeLed24[TempCnt] = 0;
								ModeLeds30[TempCnt] = 0;
								ModeLeds24[TempCnt] = 0;
								ModeLeds36[TempCnt] = 0;
								ModeLed30[TempCnt] = 0;
								ModeLed40[TempCnt] = 0;
							}
							KeepTime = 0;
						}
					}
		} break;
		
		case 1:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						
						TempR = ColorData[ModeColor10[0]][R];
						TempG = ColorData[ModeColor10[0]][G];
						TempB = ColorData[ModeColor10[0]][B];
						All_Color(TempR, TempG, TempB);
						for (TempLed = 0; TempLed < 8; TempLed++)
						{
							/* Roof10 */
							if (ModeLed10[TempLed] < 10)
							{
								Roof10[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof10[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof10[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Roof24 */
							if (ModeLed24[TempLed] < 24)
							{
								Roof24[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof24[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof24[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Roof30 */
							if (ModeLed10[TempLed] < 30)
							{
								Roof30[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof30[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof30[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Roof40 */
							if (ModeLed10[TempLed] < 40)
							{
								Roof40[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof40[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof40[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* String30 */
							if (ModeLed10[TempLed] < 30)
							{
								String30[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								String30[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								String30[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* String24 */
							if (ModeLed10[TempLed] < 24)
							{
								String24[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								String24[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								String24[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* String36 */
							if (ModeLed10[TempLed] < 36)
							{
								String36[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								String36[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								String36[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Tree */
							if (ModeLed10[TempLed] < 3)
							{
								for (TempCnt = 0; TempCnt < 9; TempCnt++)
								{
									Grd.Tree[ModeLed10[TempLed] * 9 + TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Tree[ModeLed10[TempLed] * 9 + TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Tree[ModeLed10[TempLed] * 9 + TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
							
							/* Snow */
							if (ModeLed10[TempLed] < 3)
							{
								for (TempCnt = 0; TempCnt < 7; TempCnt++)
								{
									Grd.Snow[ModeLed10[TempLed] * 7 + TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Snow[ModeLed10[TempLed] * 7 + TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Snow[ModeLed10[TempLed] * 7 + TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
							
							/* Cane */
							if (ModeLed10[TempLed] < 6)
							{
								for (TempCnt = 0; TempCnt < 5; TempCnt++)
								{
									Grd.Cane[ModeLed10[TempLed] * 5 + TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Cane[ModeLed10[TempLed] * 5 + TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Cane[ModeLed10[TempLed] * 5 + TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
							
							/* Spot */
							if (ModeLed10[TempLed] < 3)
							{
								Grd.Spot[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Grd.Spot[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Grd.Spot[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Ball */
							if (ModeLed10[TempLed] < 10)
							{
								for (TempCnt = 0; TempCnt < 4; TempCnt++)
								{
									Grd.Ball[TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Ball[TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Ball[TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
						}
						
						
						ModeLed10[0]++;
						if (ModeLed10[0] >= 41)		ModeLed10[0] = 41;
						for (TempLed = 7; TempLed > 0; TempLed--)
						{
							ModeLed10[TempLed] = ModeLed10[TempLed - 1];
						}

						
						if (ModeLed10[7] >= 41)
						{
							ModeColor10[1]++;
							if (ModeColor10[1] >= ColorNum)  ModeColor10[1] = 1;
							for (TempLed = 0; TempLed < 8; TempLed++)
							{
								ModeLed10[TempLed] = 0;
							}
							KeepTime++;
							if (KeepTime >= 3)
							{
								KeepTime = 0;
								TempStep++;
								ModeColor10[0] = ModeColor10[1];
								ModeColor10[1]++;
								if (ModeColor10[1] >= ColorNum)  ModeColor10[1] = 1; 
							}
						}
					}
		} break;
		

		case 2:
		{
					SpeedTime++;
					if (SpeedTime >= 5)
					{
						SpeedTime = 0;
						
						for (TempLed = 0; TempLed < 8; TempLed++)
						{
							/* Roof10 */
							if (ModeLed10[TempLed] < 10)
							{
								Roof10[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof10[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof10[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Roof24 */
							if (ModeLed24[TempLed] < 24)
							{
								Roof24[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof24[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof24[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Roof30 */
							if (ModeLed10[TempLed] < 30)
							{
								Roof30[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof30[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof30[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Roof40 */
							if (ModeLed10[TempLed] < 40)
							{
								Roof40[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Roof40[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Roof40[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* String30 */
							if (ModeLed10[TempLed] < 30)
							{
								String30[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								String30[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								String30[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* String24 */
							if (ModeLed10[TempLed] < 24)
							{
								String24[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								String24[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								String24[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* String36 */
							if (ModeLed10[TempLed] < 36)
							{
								String36[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								String36[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								String36[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Tree */
							if (ModeLed10[TempLed] < 3)
							{
								for (TempCnt = 0; TempCnt < 9; TempCnt++)
								{
									Grd.Tree[ModeLed10[TempLed] * 9 + TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Tree[ModeLed10[TempLed] * 9 + TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Tree[ModeLed10[TempLed] * 9 + TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
							
							/* Snow */
							if (ModeLed10[TempLed] < 3)
							{
								for (TempCnt = 0; TempCnt < 7; TempCnt++)
								{
									Grd.Snow[ModeLed10[TempLed] * 7 + TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Snow[ModeLed10[TempLed] * 7 + TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Snow[ModeLed10[TempLed] * 7 + TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
							
							/* Cane */
							if (ModeLed10[TempLed] < 6)
							{
								for (TempCnt = 0; TempCnt < 5; TempCnt++)
								{
									Grd.Cane[ModeLed10[TempLed] * 5 + TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Cane[ModeLed10[TempLed] * 5 + TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Cane[ModeLed10[TempLed] * 5 + TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
							
							/* Spot */
							if (ModeLed10[TempLed] < 3)
							{
								Grd.Spot[ModeLed10[TempLed]].DutyR = ColorData[ModeColor10[1]][R];
								Grd.Spot[ModeLed10[TempLed]].DutyG = ColorData[ModeColor10[1]][G];
								Grd.Spot[ModeLed10[TempLed]].DutyB = ColorData[ModeColor10[1]][B];
							}
							
							/* Ball */
							if (ModeLed10[TempLed] < 10)
							{
								for (TempCnt = 0; TempCnt < 4; TempCnt++)
								{
									Grd.Ball[TempCnt].DutyR = ColorData[ModeColor10[1]][R];
									Grd.Ball[TempCnt].DutyG = ColorData[ModeColor10[1]][G];
									Grd.Ball[TempCnt].DutyB = ColorData[ModeColor10[1]][B];
								}
							}
						}
						
						
						ModeLed10[0]++;
						if (ModeLed10[0] >= 41)		ModeLed10[0] = 41;
						for (TempLed = 7; TempLed > 0; TempLed--)
						{
							ModeLed10[TempLed] = ModeLed10[TempLed - 1];
						}

						
						if (ModeLed10[7] >= 41)
						{
							ModeColor10[1]++;
							if (ModeColor10[1] >= ColorNum)  ModeColor10[1] = 1;
							for (TempLed = 0; TempLed < 8; TempLed++)
							{
								ModeLed10[TempLed] = 0;
							}

							TempStep = 1;
						}
					}
						
		} break;
			
		default:
		{
					TempStep = 0xFF;		
		} break;
	}
}








