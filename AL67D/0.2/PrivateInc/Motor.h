/*******************************************************************************
	*
	* @File Name		Motor.h
	* @Date					2016.12.19
	* @Author				DS.Chin
	* @CopyRight		(C) CopyRight  @2016 ~ 2026 Willis Ltd. Co.
	* @Description	This file contains all the function prototyped for the Motor
	*								fimer library
	*
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MOTOR_H__
#define __MOTOR_H__


/* Include files--------------------------------------------------------------*/
#include "Type_Def.h"
#include "MCU_Config.h"



/**
	* @Type Motor Redefine
	*/
typedef struct
{
	_Uint8	Mode;
	_Uint8	ModeBuf;
	_Flag	InitFlag;
}_TypeStructMotor;


#define				SPEED_1					80
#define				SPEED_2					35
#define				MOTOR_MAX				2



/**
	* @Motor exported functions
	*/
void Motor_Duty_Control(void);
void Motor_Control(void);



/**
	* @ Motor exported global variables
	*/
extern _TypeStructMotor MotorData;

#endif /* __MOTOR_H__ */

