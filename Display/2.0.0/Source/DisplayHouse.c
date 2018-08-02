/**************************************************************************************************
	*
	* PROJECT NAME
	*									DisplayHouse.proj
	* DATE
	*									01 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									Display products on the little paper house
	
	*-------------------------------------------------------------------------------------
	*
	* Ver 0.2
	* 			New Display House
	
	
	* Ver0.4
	* 			Add AL99B Display
****************************************************************************************************/
#include "DisplayHouse.h"


/*
 * FunctionName  	main
 * Brief					programm entrance
 */
int main(void)
{
	MCU_Config();
	
	User_Data_Init();
	
	while(1)
	{		
		if (TIM_GetFlagStatus(TIM3, TIM_FLAG_Update) != RESET) //20ms
		{
			TIM_ClearFlag(TIM3, TIM_FLAG_Update);
			
			Key_Scan();
			
			Data_Process();
			
			Led_Update();
		}
	}
}

