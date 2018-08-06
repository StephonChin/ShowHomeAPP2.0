/********************************************************************
  *
  * FILE NAME      WifiBt.c
  *
  * Modify by      Desheng.Chin
  *                07.25  2018
  *                Update the protocol
*********************************************************************/
#include "WifiBt.h"



//-------------------------------------------------------------------
// FunctionName     main()
// Brief            program entrance
//-------------------------------------------------------------------
void main(void)
{
  MCU_Config();
  
  USART_Data_Init();
  
  User_Data_Init();
  
  while (1)
	{
		if (TF2 == SET)
		{
			TF2 = RESET;
            
      TA			= 0xAA;
      TA			= 0x55;
      WDCON       |= BIT6;        //WDCLR = 1, clear the WDT 
      
      Csr1010_Snd_Data();
      
      Csr1010_Rcv_Data();
      
      Wifi_Snd_Data();
      
      Wifi_Rcv_Data();
      
      Key_Scan();
      
      Data_Process();
      
      //BT_Work_Detect();
      
      Byte_Write_To_APROM();
    }
  }
}