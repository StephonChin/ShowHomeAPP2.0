/*************************************************************************************************
	*
	* @ProjectName	AL93
	* @KeyWords			CSR1010, RGBW, Motor, APP, Show Lights
	* @Author				DS.Chin
	* @Date					2017.03.07
	* @Description	Three RGB leds and three white leds are used in this project.It is controled
	*								by APP through CSR1010.
	*								This project is modified many times
	*								Used Nuton's mcu named N76E885(TSSOP20)
	*								
**************************************************************************************************/
#include "AL93.h"



/************************************************************************
	*
	* @FunctionName main
	* @Date					2017.03.07
	* @Author				DS.Chin
	* @Output				None
	* @Input				None
	*
*****/
void main(void)
{
	/* Configuration of MCU */
	MCU_Config();
	
	/* Read the mode, color and count down hour from APROM at 0x4000 */
	User_Init();
	
	/* Csr1010 Init | Send device type */
	Csr1010_Init();
	
	while (1)
	{
		/* scan every 10ms */
		if (TF2 == SET)
		{
			TF2 = RESET;
			
			/* Process the receive data from CSR1010 */
			Csr1010_Rcv_Data();
			
			/* Send data to CSR1010 */
			Csr1010_Snd_Data();
			
			/* Data Process */
			Data_Process();
			
			/* Timer*/
			Count_Down_Control();
			
			/* Motor */
			Motor_Control();
			
			/* Led Display */
			Led_Display_Control();
		}
	}
}