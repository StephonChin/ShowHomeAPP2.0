/************************************************************
	*
	* File Name:　Motor.c
	* Description: 步进马达控制
	*
**************************************************************/
#include "Motor.h"


/* gloable variables ---------------------------------------------------------*/
_TypeStructMotor		MotorData;



/* file variables ------------------------------------------------------------*/
idata _Uint8		MotorDuty;
idata _Uint8		MotorDutyCnt;
idata _Uint8		MotorTime;
idata _Uint8		MotorStep;
_Uint8 const MOTOR_DATA[8] = {0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};



/**
	* @FunctionName			Motor_Duty_Control
	* @Parameters			None
	* @Return				None
	*/
void Motor_Duty_Control(void)
{
	if (MotorData.Mode == 0)		return;
	
	MotorDutyCnt++;
	if (MotorDutyCnt > 20)
	{
		MotorDutyCnt = 0;
	}
	
	if (MotorDutyCnt < 15)
	{
		PORT_A =  MOTOR_DATA[MotorStep] & 0x01;
        PORT_B = (MOTOR_DATA[MotorStep] & 0x02) >> 1;
        PORT_C = (MOTOR_DATA[MotorStep] & 0x04) >> 2;
        PORT_D = (MOTOR_DATA[MotorStep] & 0x08) >> 3;
	}
	else
	{
		PORT_A = 0;
		PORT_B = 0;
		PORT_C = 0;
		PORT_D = 0;
	}
	
	MotorTime++;
	if (MotorTime > MotorDuty)
	{
		MotorTime = 0;
		MotorStep++;
		if (MotorStep > 7)
		{
			MotorStep = 0;
		}
	}
  
}

/**
	* @FunctionName		Motor_Control
	* @Parameters		None
	* @Return			None
	*/
void Motor_Control(void)
{
	if (MotorData.InitFlag == TRUE)
	{
		MotorData.InitFlag = FALSE;
		
		if (MotorData.Mode == 0)
		{
			PORT_A		= RESET;
			PORT_B		= RESET;
			PORT_C		= RESET;
			PORT_D		= RESET;
			return;
		}
		
		MotorStep = 0;
		
		switch (MotorData.Mode)
		{	
			case 1:			MotorDuty	= SPEED_1;		break;
			case 2:			MotorDuty	= SPEED_2;		break;
			default:		MotorDuty	= SPEED_1;		break;
		}
	}
}
