/*************************************************************
	*
	* @FileName			Timer_Ctrl.c
	* @Date					2017.03.17
	* @Author				DS.Chin
	* @Description	Timer through 24 hours
	*
**************************************************************/
#include "Timer_Ctrl.h"


/* @Brief Gloable Variables */
_TypeStructTime		TimerData;

xdata _Uint16   TimerChk;



/*****************************************************
	*
	* @FunctionName		Count_Down_Control
	*
*****/
void Count_Down_Control(void)
{
	/* if count down hour equals 0, then exit this function */
	if (TimerData.CntDwnHour == 0)			return;
	
	
	/* if count down hour unequals 0, then start the time */
	// Initial the real time
	if (TimerData.InitFlag == TRUE)
	{
		TimerData.InitFlag = FALSE;
		TimerData.RealTime.MicroSec		= 0;
		TimerData.RealTime.Second			= 0;
		TimerData.RealTime.Minute			= 0;
		TimerData.RealTime.Hour				= 0;
    TimerChk = 0;
	}
	
	
	/* Real Time */
	TimerData.RealTime.MicroSec++;
	if (TimerData.RealTime.MicroSec >= 50)		// 1s
	{
		TimerData.RealTime.MicroSec		= 0;
    TimerChk++;
		if (TimerChk >= 24000)
		{
			TimerChk = 0;
			return;
		}
		TimerData.RealTime.Second	++;
		if (TimerData.RealTime.Second >= 60)		// 1minute
		{
			TimerData.RealTime.Second		= 0;
			TimerData.RealTime.Minute ++;
			if (TimerData.RealTime.Minute >= 60)	// 1hour
			{
				TimerData.RealTime.Minute	= 0;
				TimerData.RealTime.Hour	++;
				if (TimerData.RealTime.Hour >= 24)	// 1day
				{
					TimerData.RealTime.Hour	= 0;
				}
			}
		}
	}
	
	
	/* Get the timer hour status */
	if (TimerData.RealTime.MicroSec		== 0
		&&TimerData.RealTime.Second			== 0
		&&TimerData.RealTime.Minute			== 0
		&&TimerData.RealTime.Hour				== 0)
	{
		TimerData.Status		= TIM_OPEN;
		TimerData.OnOffFlag	= TRUE;
	}
	
	else
	if (TimerData.RealTime.MicroSec		== 0
		&&TimerData.RealTime.Second			== 0
		&&TimerData.RealTime.Minute			== 0
		&&TimerData.RealTime.Hour				== TimerData.CntDwnHour)
	{
		TimerData.Status		= TIM_CLOSE;
		TimerData.OnOffFlag = FALSE;
	}
}










