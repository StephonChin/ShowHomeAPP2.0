/********************************************************************
	*
	* FILE NAME
	*									Led_Class.c
	* DATE
	*									01 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									LED Communicate 
	*
*********************************************************************/
#include "Led_Class.h"

/*
 * Gloable Parameters
 * 27 Leds -- icicle strings
 * 40 Leds -- Left Roof 10 Leds + Middle Roof 10 Leds + Right Roof 12 Leds
 * 15 Leds -- Middle 15 Leds
 * 10 Leds -- Second Left 7 Leds
 * 90 Leds -- Light Strings Right 9*2+12=30Leds , Middle 9*2+6=24Leds, Left 9*2+9*2=36Leds
 * 85 Leds -- Snow + Tree + Ball + Candy Cane + Spot Lights 
 */
//_TypeLed	Roof30[27];
//_TypeLed	Roof40[32];
//_TypeLed	Roof24[15];
//_TypeLed	Roof10[7];
//_TypeLed	String96[90];        // These are the really count number
_TypeLed	Roof30[30];
_TypeLed	Roof40[40];
_TypeLed	Roof24[24];
_TypeLed	Roof10[10];
_TypeLed 	String30[30];
_TypeLed	String24[24];
_TypeLed 	String36[36];
_TypeGround 	Grd;

/*
 * File Parameters
 */
_Uint8	SndBuffer_1[GRP_RIGHT][3];
_Uint8	SndBuffer_2[GRP_MIDDLE][3];
_Uint8	SndBuffer_3[GRP_LEFT][3];
_Uint8	SndBuffer_4[GRP_MIX_R][3];
_Uint8	SndBuffer_5[GPR_MIX_L][3];
_Uint8	SndBuffer_6[GRP_TREE][3];


/*
 * FunctionName   Led_Update
 */
void Led_Update(void)
{
	_Uint16	ColorTemp		= 0;
  _Uint8  BitTemp  		= 0;
	_Uint8	*DataBufAdd	= 0;
	_Uint8  DataBuf 		= 0;
	_Uint8	TimeTemp		= 0;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Send Data Process */
	Send_Data_Process();
	
	
	/* Change the I/O PA8 to output */
	if (KeyDetFlag == FALSE)
	{
		GPIO_InitStructure.GPIO_Pin   	= GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode  	= GPIO_Mode_Out_OD;						
		GPIO_InitStructure.GPIO_Speed  	= GPIO_Speed_50MHz;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIOA->BRR = GPIO_Pin_8;
	}
	
	
	/* Group 2 - Roof40*/
	DataBufAdd = SndBuffer_3[0];	
	for (ColorTemp = 0; ColorTemp < BYTE_LEFT; ColorTemp++)			
	{
		DataBuf = *DataBufAdd++;
					
		for (BitTemp = 0; BitTemp < 8; BitTemp++)	
		{
			if ((DataBuf & 0x80) != 0x80)
			{
				GPIOB->BSRR = GPIO_Pin_15;	
				__nop();__nop();__nop();__nop();__nop();
				GPIOB->BRR 	= GPIO_Pin_15;
				for (TimeTemp = 0; TimeTemp < 3; TimeTemp++);
			}
			else
			{
				GPIOB->BSRR = GPIO_Pin_15;
				for (TimeTemp = 0; TimeTemp < 6; TimeTemp++);
				GPIOB->BRR 	= GPIO_Pin_15;
			}
			TimeTemp = 3;
			while(TimeTemp--);
			DataBuf <<= 1;								
		}
	}
	
	/* Group 3 - Roof10 + Roof24*/
	DataBufAdd = SndBuffer_1[0];	
	for (ColorTemp = 0; ColorTemp < BYTE_RIGHT; ColorTemp++)			
	{
		DataBuf = *DataBufAdd++;
					
		for (BitTemp = 0; BitTemp < 8; BitTemp++)	
		{
			if ((DataBuf & 0x80) != 0x80)
			{
				GPIOB->BSRR = GPIO_Pin_14;	
				__nop();__nop();__nop();__nop();__nop();
				GPIOB->BRR 	= GPIO_Pin_14;
				for (TimeTemp = 0; TimeTemp < 3; TimeTemp++);
			}
			else
			{
				GPIOB->BSRR = GPIO_Pin_14;
				for (TimeTemp = 0; TimeTemp < 6; TimeTemp++);
				GPIOB->BRR 	= GPIO_Pin_14;
			}
			TimeTemp = 3;
			while(TimeTemp--);
			DataBuf <<= 1;								
		}
	}
	
	/* Group 4 - Grd*/
	DataBufAdd = SndBuffer_2[0];	
	for (ColorTemp = 0; ColorTemp < BYTE_MIDDLE; ColorTemp++)			
	{
		DataBuf = *DataBufAdd++;
					
		for (BitTemp = 0; BitTemp < 8; BitTemp++)	
		{
			if ((DataBuf & 0x80) != 0x80)
			{
				GPIOB->BSRR = GPIO_Pin_13;	
				__nop();__nop();__nop();__nop();__nop();
				GPIOB->BRR 	= GPIO_Pin_13;
				for (TimeTemp = 0; TimeTemp < 3; TimeTemp++);
			}
			else
			{
				GPIOB->BSRR = GPIO_Pin_13;
				for (TimeTemp = 0; TimeTemp < 6; TimeTemp++);
				GPIOB->BRR 	= GPIO_Pin_13;
			}
			TimeTemp = 3;
			while(TimeTemp--);
			DataBuf <<= 1;								
		}
	}
	
	if (KeyDetFlag == FALSE)
	{
		DataBufAdd = SndBuffer_4[0];	
		for (ColorTemp = 0; ColorTemp < BYTE_MIX_R; ColorTemp++)			
		{
			DataBuf = *DataBufAdd++;
						
			for (BitTemp = 0; BitTemp < 8; BitTemp++)	
			{
				if ((DataBuf & 0x80) != 0x80)
				{
					GPIOA->BSRR = GPIO_Pin_8;	
					__nop();__nop();__nop();__nop();__nop();
					GPIOA->BRR 	= GPIO_Pin_8;
					for (TimeTemp = 0; TimeTemp < 3; TimeTemp++);
				}
				else
				{
					GPIOA->BSRR = GPIO_Pin_8;
					for (TimeTemp = 0; TimeTemp < 6; TimeTemp++);
					GPIOA->BRR 	= GPIO_Pin_8;
				}
				TimeTemp = 3;
				while(TimeTemp--);
				DataBuf <<= 1;								
			}
		}
	}
	
	
	/* Group 5 - LihgtString*/
	DataBufAdd = SndBuffer_5[0];	
	for (ColorTemp = 0; ColorTemp < BYTE_MIX_L; ColorTemp++)			
	{
		DataBuf = *DataBufAdd++;
					
		for (BitTemp = 0; BitTemp < 8; BitTemp++)	
		{
			if ((DataBuf & 0x80) != 0x80)
			{
				GPIOB->BSRR = GPIO_Pin_12;	
				__nop();__nop();__nop();__nop();__nop();
				GPIOB->BRR 	= GPIO_Pin_12;
				for (TimeTemp = 0; TimeTemp < 3; TimeTemp++);
			}
			else
			{
				GPIOB->BSRR = GPIO_Pin_12;
				for (TimeTemp = 0; TimeTemp < 6; TimeTemp++);
				GPIOB->BRR 	= GPIO_Pin_12;
			}
			TimeTemp = 3;
			while(TimeTemp--);
			DataBuf <<= 1;								
		}
	}
	
	
		/* Group 6 - Mini Tree*/
	DataBufAdd = SndBuffer_6[0];	
	for (ColorTemp = 0; ColorTemp < BYTE_TREE; ColorTemp++)			
	{
		DataBuf = *DataBufAdd++;
					
		for (BitTemp = 0; BitTemp < 8; BitTemp++)	
		{
			if ((DataBuf & 0x80) != 0x80)
			{
				GPIOC->BSRR = GPIO_Pin_13;	
				__nop();__nop();__nop();__nop();__nop();
				GPIOC->BRR 	= GPIO_Pin_13;
				for (TimeTemp = 0; TimeTemp < 3; TimeTemp++);
			}
			else
			{
				GPIOC->BSRR = GPIO_Pin_13;
				for (TimeTemp = 0; TimeTemp < 6; TimeTemp++);
				GPIOC->BRR 	= GPIO_Pin_13;
			}
			TimeTemp = 3;
			while(TimeTemp--);
			DataBuf <<= 1;								
		}
	}
	
	DataBufAdd = 0;
	
	/* Change the I/O PA8 to Input */
	if (KeyDetFlag == FALSE)
	{
		GPIO_InitStructure.GPIO_Pin   	= GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode  	= GPIO_Mode_IPU;						
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
}


/*
 * FunctionName	Send_Data_Process
 */
static void Send_Data_Process(void)
{
	_Uint8	TempVar = 0;
	
	/* SndBuffer_1 Data Get */
	for (TempVar = 0; TempVar < 30; TempVar++)
	{
		SndBuffer_1[TempVar][R] = String30[TempVar].DutyG / SMT_LEVEL;
		SndBuffer_1[TempVar][G] = String30[TempVar].DutyR / SMT_LEVEL;
		SndBuffer_1[TempVar][B] = String30[TempVar].DutyB / SMT_LEVEL;
	}
	for (TempVar = 30; TempVar < 40; TempVar++)
	{
		SndBuffer_1[TempVar][R] = Roof30[39 - TempVar].DutyR / DIP_LEVEL;
		SndBuffer_1[TempVar][G] = Roof30[39 - TempVar].DutyG / DIP_LEVEL;
		SndBuffer_1[TempVar][B] = Roof30[39 - TempVar].DutyB / DIP_LEVEL;
	}
	for (TempVar = 40; TempVar < 52; TempVar++)
	{
		SndBuffer_1[TempVar][R] = Roof40[TempVar - 40].DutyR / DIP_LEVEL;
		SndBuffer_1[TempVar][G] = Roof40[TempVar - 40].DutyG / DIP_LEVEL;
		SndBuffer_1[TempVar][B] = Roof40[TempVar - 40].DutyB / DIP_LEVEL;
	}
	
	
	
	
	/* SndBuffer_2 Data Get */
	for (TempVar = 0; TempVar < 24; TempVar++)
	{
		SndBuffer_2[TempVar][R] = String24[23 - TempVar].DutyG / SMT_LEVEL;
		SndBuffer_2[TempVar][G] = String24[23 - TempVar].DutyR / SMT_LEVEL;
		SndBuffer_2[TempVar][B] = String24[23 - TempVar].DutyB / SMT_LEVEL;
	}
	for (TempVar = 24; TempVar < 31; TempVar++)
	{
		SndBuffer_2[TempVar][R] = Roof30[TempVar - 14].DutyR / DIP_LEVEL;
		SndBuffer_2[TempVar][G] = Roof30[TempVar - 14].DutyG / DIP_LEVEL;
		SndBuffer_2[TempVar][B] = Roof30[TempVar - 14].DutyB / DIP_LEVEL;
	}
	for (TempVar = 31; TempVar < 41; TempVar++)
	{
		SndBuffer_2[TempVar][R] = Roof40[52 - TempVar].DutyR / DIP_LEVEL;
		SndBuffer_2[TempVar][G] = Roof40[52 - TempVar].DutyG / DIP_LEVEL;
		SndBuffer_2[TempVar][B] = Roof40[52 - TempVar].DutyB / DIP_LEVEL;
	}
	for (TempVar = 41; TempVar < 56; TempVar++)
	{
		SndBuffer_2[TempVar][R] = Roof24[TempVar - 41].DutyR / DIP_LEVEL;
		SndBuffer_2[TempVar][G] = Roof24[TempVar - 41].DutyG / DIP_LEVEL;
		SndBuffer_2[TempVar][B] = Roof24[TempVar - 41].DutyB / DIP_LEVEL;
	}
	for (TempVar = 56; TempVar < 63; TempVar++)
	{
		SndBuffer_2[TempVar][R] = Roof40[62 - TempVar].DutyR / DIP_LEVEL;
		SndBuffer_2[TempVar][G] = Roof40[62 - TempVar].DutyG / DIP_LEVEL;
		SndBuffer_2[TempVar][B] = Roof40[62 - TempVar].DutyB / DIP_LEVEL;
	}
	
	
	
	
	/* SndBuffer_3 Data Get */
	for (TempVar = 0; TempVar < 36; TempVar++)
	{
		SndBuffer_3[TempVar][R] = String36[35 - TempVar].DutyG / SMT_LEVEL;
		SndBuffer_3[TempVar][G] = String36[35 - TempVar].DutyR / SMT_LEVEL;
		SndBuffer_3[TempVar][B] = String36[35 - TempVar].DutyB / SMT_LEVEL;
	}
	for (TempVar = 36; TempVar < 46; TempVar++)
	{
		SndBuffer_3[TempVar][R] = Roof30[TempVar - 19].DutyR / DIP_LEVEL;
		SndBuffer_3[TempVar][G] = Roof30[TempVar - 19].DutyG / DIP_LEVEL;
		SndBuffer_3[TempVar][B] = Roof30[TempVar - 19].DutyB / DIP_LEVEL;
	} 
	for (TempVar = 46; TempVar < 56; TempVar++)
	{
		SndBuffer_3[TempVar][R] = Roof40[77 - TempVar].DutyR / DIP_LEVEL;
		SndBuffer_3[TempVar][G] = Roof40[77 - TempVar].DutyG / DIP_LEVEL;
		SndBuffer_3[TempVar][B] = Roof40[77 - TempVar].DutyB / DIP_LEVEL;
	}
	
	
	
	
	
	
	/* SndBuffer_4 Data Get */
	for (TempVar = 0; TempVar < 27; TempVar++)
	{
		if (TempVar == 8 || TempVar == 17 || TempVar == 26)
		{
			SndBuffer_4[TempVar][R] = Grd.Tree[TempVar].DutyR / 3 * 2;
			SndBuffer_4[TempVar][G] = Grd.Tree[TempVar].DutyG / DIP_LEVEL;
			SndBuffer_4[TempVar][B] = Grd.Tree[TempVar].DutyB / DIP_LEVEL;
		}
		else
		{
			SndBuffer_4[TempVar][R] = Grd.Tree[TempVar].DutyR / DIP_LEVEL;
			SndBuffer_4[TempVar][G] = Grd.Tree[TempVar].DutyG / DIP_LEVEL;
			SndBuffer_4[TempVar][B] = Grd.Tree[TempVar].DutyB / DIP_LEVEL;
		}
	}

	
	for (TempVar = 27; TempVar < 29; TempVar++)
	{
		SndBuffer_4[TempVar][R] = 255 - Grd.Ball[TempVar - 27].DutyR / DIP_LEVEL;
		SndBuffer_4[TempVar][G] = 255 - Grd.Ball[TempVar - 27].DutyG / DIP_LEVEL;
		SndBuffer_4[TempVar][B] = 255 - Grd.Ball[TempVar - 27].DutyB / DIP_LEVEL;
	}
	
	for (TempVar = 29; TempVar < 50; TempVar++)
	{
		SndBuffer_4[TempVar][R] = Grd.Snow[TempVar - 29].DutyR / 2;
		SndBuffer_4[TempVar][G] = Grd.Snow[TempVar - 29].DutyG / DIP_LEVEL;
		SndBuffer_4[TempVar][B] = Grd.Snow[TempVar - 29].DutyB / DIP_LEVEL;
	}
	
	
	
	/* SndBuffer_5 Data Get */
	for (TempVar = 0; TempVar < 2; TempVar++)
	{
		SndBuffer_5[TempVar][R] = 255 - Grd.Ball[TempVar + 2].DutyR / DIP_LEVEL;
		SndBuffer_5[TempVar][G] = 255 - Grd.Ball[TempVar + 2].DutyG / DIP_LEVEL;
		SndBuffer_5[TempVar][B] = 255 - Grd.Ball[TempVar + 2].DutyB / DIP_LEVEL;
	}
	
	for (TempVar = 2; TempVar < 32; TempVar++)
	{
		SndBuffer_5[TempVar][R] = Grd.Cane[TempVar - 2].DutyR / DIP_LEVEL;
		SndBuffer_5[TempVar][G] = Grd.Cane[TempVar - 2].DutyG / DIP_LEVEL;
		SndBuffer_5[TempVar][B] = Grd.Cane[TempVar - 2].DutyB / DIP_LEVEL;
	}
	
	for (TempVar = 32; TempVar < 35; TempVar++)
	{
		SndBuffer_5[TempVar][R] = 255 - Grd.Spot[TempVar - 32].DutyR / DIP_LEVEL;
		SndBuffer_5[TempVar][G] = 255 - Grd.Spot[TempVar - 32].DutyG / DIP_LEVEL;
		SndBuffer_5[TempVar][B] = 255 - Grd.Spot[TempVar - 32].DutyB / DIP_LEVEL;
	}
	
	
	/* SndBuffer_6 Data Get */
	SndBuffer_6[0][R] = SndBuffer_1[0][G];
	SndBuffer_6[0][G] = SndBuffer_1[0][R];
	SndBuffer_6[0][B] = SndBuffer_1[0][B];
	for (TempVar = 1; TempVar < 10; TempVar++)
	{
		SndBuffer_6[TempVar][R] = SndBuffer_1[TempVar][R];
		SndBuffer_6[TempVar][G] = SndBuffer_1[TempVar][G];
		SndBuffer_6[TempVar][B] = SndBuffer_1[TempVar][B];
	}
}

























