/*********************************************************
	*
	* FILE NAME			BT_Control.c
	* BRIEF					Control the bluetooth power
	*
**********************************************************/
#include "BT_Control.h"



//------------------------< Gloable Parameters >-----------------------------//
idata _TypeBtCon	    BtConStatus;
idata _Flag				BtRcvDataFlag;
idata _Flag				BtPowerInitFlag;


idata _Uint8		BtTime;
idata _Uint8		PIO11_HighTime[2];
idata _Uint8		PIO11_LowTime[2];
idata _Uint8		BtRcvDataTime[3];

/**
	* FunctionName		Bt_Work_Detect
	*/
void BT_Work_Detect(void)
{

	// Detect the PIO11:it should be ouput PWM wave
	// 6s H + 6sL
	if (PORT_BT_DT == SET)
	{
		PIO11_LowTime[0] = 0;
		PIO11_LowTime[1] = 0;
		
		PIO11_HighTime[0]++;
		if (PIO11_HighTime[0] >= 50)			//20ms * 50 = 1s
		{	
			PIO11_HighTime[0] = 0;
			PIO11_HighTime[1]++;
			if (PIO11_HighTime[1] >= 10)		//10s
			{
				PIO11_HighTime[1] = 0;
				BtConStatus 	= BT_RESTART;
				BtPowerInitFlag = TRUE;
			}
		}
	}
	else
	{
		PIO11_HighTime[0] = 0;
		PIO11_HighTime[1] = 0;
		
		PIO11_LowTime[0]++;
		if (PIO11_LowTime[0] >= 50)			//20ms * 50 = 1s
		{	
			PIO11_LowTime[0] = 0;
			PIO11_LowTime[1]++;
			if (PIO11_LowTime[1] >= 10)		//10s
			{
				PIO11_LowTime[1] = 0;
				BtConStatus 		= BT_RESTART;
				BtPowerInitFlag = TRUE;
			}
		}
	}
	
	
	

	// if the bluetooth haven't receive command without 1hour, restart it.
	if (BtRcvDataFlag == TRUE)
	{
		BtRcvDataFlag = FALSE;
		BtRcvDataTime[0] = 0;
		BtRcvDataTime[1] = 0;
		BtRcvDataTime[2] = 0;
	}
	
	

    BtRcvDataTime[0]++;
    if (BtRcvDataTime[0] >= 50)	//20 * 50 = 1s
    {
        BtRcvDataTime[0] = 0;
        BtRcvDataTime[1]++;
        if (BtRcvDataTime[1] >= 60)		//1min
        {
            BtRcvDataTime[1] = 0;
            BtRcvDataTime[2]++;
            if (BtRcvDataTime[2] >= 60)		//1hour
            {
                BtRcvDataTime[2] = 0;
                BtConStatus 		= BT_RESTART;
                BtPowerInitFlag = TRUE;
            }
        }
    }
	
	
	//Control the BT power
	BT_Power_Control();
}




/************************************************************
	*
	* @FunctonName	BT_Power_Control
	* @Brief				Control the power of bluetooth
	* 							
	*/
static void BT_Power_Control(void)
{
	switch (BtConStatus)
	{
		case BT_IDLE:		break;
		
		case BT_POWER_ON:
		{
			if (BtPowerInitFlag == TRUE)
			{
				BtPowerInitFlag = FALSE;
				BtTime = 0;
				PORT_BT_CE = SET;
			}
			
			BtTime++;
			if (BtTime > 5)
			{
				BtTime = 0;
				BtConStatus = BT_IDLE;
                P2M1	&= ~(BIT4 | BIT5);
                P2M2	&= ~(BIT4 | BIT5);
                P2		|= (BIT4 | BIT5);  	// P24 = 1, P25 = 1
				SCON_1 = 0x50;		// work at mode 1
			}
		} break;
		
		case BT_POWER_OFF:
		{
				BtPowerInitFlag = FALSE;
				BtTime = 0;
				PORT_BT_CE = RESET;
				BtConStatus = BT_IDLE;
                SCON_1 = 0x00;
				P2M1	&= ~(BIT4 | BIT5);
                P2M2	|= (BIT4 | BIT5);
				PORT_RX = RESET;
				PORT_TX = RESET;
		} break;
		
		case BT_RESTART:
		{
			if (BtPowerInitFlag == TRUE)
			{
				BtPowerInitFlag = FALSE;
				BtTime = 0;
				PORT_BT_CE = RESET;
				SCON_1 = 0x00;
				P2M1	&= ~(BIT4 | BIT5);
                P2M2	|= (BIT4 | BIT5);
				PORT_RX = RESET;
				PORT_TX = RESET;
			}
			
			BtTime++;
			if (BtTime > 5)
			{
				BtTime = 0;
				BtConStatus = BT_POWER_ON;
				BtPowerInitFlag = TRUE;
			}
		} break;
	}
}




