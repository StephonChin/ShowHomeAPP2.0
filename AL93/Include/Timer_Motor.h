/**************************************************************
	*
	* @FileName	Timer_Motor.h
	* 
***************************************************************/
#ifndef __TIMER_MOTOR_H__
#define __TIMER_MOTOR_H__


/* @Brief Include Files */
#include "System.h"
#include "Config.h"
#include "Led_Display.h"



/* @Brief Type Defines */
typedef struct _TIMER_TYPE
{
	enum	_TIMER_STATUS
	{
		TIM_IDLE,
		TIM_OPEN,
		TIM_CLOSE
	}Status;
	struct _REAL_TIME
	{
		_Uint8	MicroSec;
		_Uint8	Second;
		_Uint8	Minute;
		_Uint8	Hour;
	}RealTime;
	_Flag			InitFlag;
	_Uint8		CntDwnHour;
}_TypeStructTime;





/* @Brief Exported Functions */
void Count_Down_Control(void);
void Motor_Control(void);






/*@Brief Exprted Variables */
extern _TypeStructTime		TimerData;


#endif
