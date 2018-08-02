/*******************************************************************************
	*
	* Project Name		AL67-3D
	* Date			    	2017.12.19
	* Author		    	DS.Chin
	* Description			AL67-3D controled by APP var CSR1010
	*
*******************************************************************************/
#include "AL67D.h"



/*******************************************************
	*
	* Function Name		| TIM0_Update_Interrupt
	* Description		| TIM0 100us中断服务函数
	*
*****/
void Led_Duty_Control(void) interrupt 1
{
	
	TF0 = RESET;

	/* LASER占空比控制 */
	Led_Update();
	
	/* Motor占空比控制 */
	Motor_Duty_Control();
}


/**
	* Programm Entrance
	*/
void main(void)
{
	/* Initialize the MCU peripheral */
	MCU_Config();
	
	/* Read the Mode, Coor & Timer after Power On */
	User_Data_Init();
    
    Csr1010_Init();

	while (1)
	{
		if (TF2 == SET)
		{
			TF2 = RESET;
            
            TA			= 0xAA;
            TA			= 0x55;
            WDCON       |= BIT6;        //WDCLR = 1, clear the WDT 
			
			Csr1010_Rcv_Data();
			
			Data_Process();
			
			Csr1010_Snd_Data();
			
			Led_Display();
			
			Ntc_Msr();
			
			Key_Scan();
			
			Motor_Control();
			
			Count_Down_Control();	
            
            Byte_Write_To_APROM();
		}
	}
}

