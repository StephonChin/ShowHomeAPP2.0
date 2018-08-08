/******************************************************
  *
  * FileName    LY6686.c
  *
*******************************************************/
#include "Mini93Motor.h"




_Uint8  const MOTOR_DATA[8] = {0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
_Uint8  MotorStep;
_Uint8  MotorDutyCnt;
_Uint8  MotorTime;


/*******************************************************
	*
	* Function Name		| TIM0_Interrupt_Handler
	* Description		  | TIM0 100us
	*
*****/
void TIM0_Interrupt_Handler(void) interrupt 1
{
	_Uint16 buf = 0;
  
  TF0 = 0;
  
  MotorDutyCnt++;
	if (MotorDutyCnt > 30)
	{
		MotorDutyCnt = 0;
	}
	
	if (MotorDutyCnt < 20)
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
	if (MotorTime > 40)
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
	* Programm Entrance
	*/
void main(void)
{
	MCU_Config();
  
	while (1)
	{
		if (TF2 == 1)
		{
			TF2 = 0;
 
      TA			= 0xAA;
      TA			= 0x55;
      WDCON   |= BIT6;        //WDCLR = 1, clear the WDT 
      
      
		}
	}
}




