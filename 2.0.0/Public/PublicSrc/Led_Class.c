/************************************************************************************************************
	*
	* FileName			Led_Class.c
	*
	* Description
	*								The protocol about communicate with LED, such as LED with KM5020, LED with UCS1903BC,
	*								LED drived by PWM, LED drived by general I/O or LED drived by custom protol.
	*
*************************************************************************************************************/
#include "Led_Class.h"

/* Gloable Parameters */
_Flag						DirectFlag;

#if AL91 | AL92 | AL94 | AL95
	_Type_Led 			LedData;

#elif AL96
	_Uint8			DutyR;
	_Uint8			DutyG;
	_Uint8			DutyB;
	_Uint8			DutyW;
#elif AL99
	_TypeLed_ST			ColorBuffer[GROUP_TOTAL][GROUP_CNT];

#endif


#if AL95 | AL96
	_Uint8				RedEn = 0xFF;
	_Uint8				GrnEn = 0xFF;
	_Uint8				BleEn = 0xFF;
	_Uint8				WhtEn = 0xFF;
#endif


/**************************************************************************************
	*
	* FunctionName		Led_Update
	* 
	*	Brief
	*									Include KM5020's LED driver protocol
 	*									Include UCS1903BC's Led driver protocol
	*									Include MCU PWM driver
	*									Include custom protocol
	*
***************************************************************************************/
void Led_Update(void)
{
//UCS1903BC---------------------------------AL94--------------------------------
#if AL94
	_Uint16	TempCnt 		= 0;
	_Uint8	TempColor		= 0;
  _Uint8  TempBit  		= 0;
	_Uint8	*DataBufAdd	= 0;
	_Uint8  DataBuf 		= 0;
	
	/* run from the header to tail */
	if (DirectFlag == FALSE)
	{																					
		for (TempCnt = 0; TempCnt < LED_TOTAL; TempCnt++)			/* Circle count caculated													*/
		{
			DataBufAdd = &LedData.Buffer[TempCnt].DutyG;
			
			for (TempColor = 0; TempColor < 3; TempColor++)
			{
				DataBuf = *DataBufAdd++;
				DataBuf /= 2;
				/* Address increase																*/
				for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
				{
					if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
					{
						PORT_COMM = SET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");
						PORT_COMM = RESET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
					}
					else																								/* Bit0 data send																	*/
					{
						PORT_COMM = SET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");
						PORT_COMM = RESET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
					}
					DataBuf <<= 1;																			/* move one bit to the left 											*/					
				}
			}
		}
	}
	
	/* Run from the tail to header */
	else
	{
		for (TempCnt = LED_TOTAL; TempCnt > 0; TempCnt--)			/* Circle count caculated													*/
		{
			DataBufAdd = &LedData.Buffer[TempCnt - 1].DutyG;
			
			for (TempColor = 0; TempColor < 3; TempColor++)
			{
				DataBuf = *DataBufAdd++;
				DataBuf /= 2;
				
				/* Address increase																*/
				for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
				{
					if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
					{
						PORT_COMM = SET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");
						PORT_COMM = RESET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
					}
					else																								/* Bit0 data send																	*/
					{
						PORT_COMM = SET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");
						PORT_COMM = RESET;
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
						__asm("nop");__asm("nop");__asm("nop");__asm("nop");
					}
					DataBuf <<= 1;																			/* move one bit to the left 											*/					
				}
			}
		}
	}
	PORT_COMM = RESET;
	DataBufAdd = 0;
	

	
//KM5020-----------------------------------------AL91 AL92----------------------------
#elif	AL91 | AL92
	_Uint8		TempCnt 		= 0;
  _Uint8  	TempBit  		= 0;
	_Uint8  	DataBuf 		= 0;
	_Uint8		*DataBufAdd	= 0;
	_Uint8		TempColor		= 0;
	_Uint8		TimeDelay		= 0;
	
	
	/* run from the tail to header */
	if (DirectFlag == TRUE)
	{
		for (TempCnt = 0; TempCnt < LED_TOTAL; TempCnt++)			/* Circle count caculated													*/
		{
			DataBufAdd = &LedData.Buffer[TempCnt].DutyB;
			
			for (TempColor = 0; TempColor < 3; TempColor++)
			{
				DataBuf = *DataBufAdd++;
				
				/* Address increase																*/
				for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
				{
					if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
					{
						PORT_COMM = SET;
						TimeDelay = 10;
						while (TimeDelay--);
						__asm("nop"); __asm("nop");__asm("nop"); __asm("nop");
						__asm("nop"); __asm("nop");__asm("nop"); __asm("nop");
						PORT_COMM = RESET;
					}
					else																																/* Bit 0 delay																		*/
					{	
						PORT_COMM = SET;
						TimeDelay = 2;
						while (TimeDelay--);
						__asm("nop"); __asm("nop");__asm("nop"); __asm("nop");
						PORT_COMM = RESET;
					}
					
					TimeDelay = 25;
					while (TimeDelay--);
					DataBuf <<= 1;																											/* move one bit to the left 											*/
				}
			}
		}
	}
	
	
	/* Run from the header to tail */
	else
	{
		for (TempCnt = LED_TOTAL; TempCnt > 0; TempCnt--)			/* Circle count caculated													*/
		{
			DataBufAdd = &LedData.Buffer[TempCnt - 1].DutyB;
			
			for (TempColor = 0; TempColor < 3; TempColor++)
			{
				DataBuf = *DataBufAdd++;
				
				/* Address increase																*/
				for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
				{
					if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
					{
						PORT_COMM = SET;
						TimeDelay = 10;
						while (TimeDelay--);
						__asm("nop"); __asm("nop");__asm("nop"); __asm("nop");
						__asm("nop"); __asm("nop");__asm("nop"); __asm("nop");
						PORT_COMM = RESET;
					}
					else																																/* Bit 0 delay																		*/
					{	
						PORT_COMM = SET;
						TimeDelay = 2;
						while (TimeDelay--);
						__asm("nop"); __asm("nop");__asm("nop"); __asm("nop");
						PORT_COMM = RESET;
					}
					
					TimeDelay = 25;
					while (TimeDelay--);
					DataBuf <<= 1;																											/* move one bit to the left 											*/
				}
			}
		}
	}
	
	
	DataBufAdd = 0;
	
	
	
	
//---------------------AL95---------------------------------------------
#elif	AL95
	_Uint8	TempCnt 		= 0;
	_Uint8	TempColor		= 0;
  _Uint8  DataBuf 		= 0;
  _Uint8  TempBit  		= 0;
	_Uint8	*DataBufAdd	= 0;
	
    
	for (TempCnt = 1; TempCnt < LED_TOTAL; TempCnt++)			/* Circle count caculated													*/
	{
		DataBufAdd = &LedData.Buffer[TempCnt].DutyR;
		
		for (TempColor = 0; TempColor < 3; TempColor++)
		{
			DataBuf = *DataBufAdd++;
			/* Address increase																*/
			for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) != 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;		 											
		}
		}
	}
	DataBuf = 0;
	
	
	if (LedData.Buffer[0].DutyG == 0)
	{
		if (GrnEn != 0x0)
		{
			GrnEn = 0x0;
			PWM->PHCHG &= ~(BIT13 | BIT5);
		}
	}
	else
	{
		if (GrnEn != 0x1)
		{
			GrnEn = 0x1;
			PWM->PHCHG |= BIT13;
		}
		PWM->CMPDAT5 	= LedData.Buffer[0].DutyG;
	}
	
	
	if (LedData.Buffer[0].DutyR == 0)
	{
		if (RedEn != 0x0)
		{
			RedEn = 0x0;
			PWM->PHCHG &= ~(BIT9 | BIT1);
		}
	}
	else
	{
		if (RedEn != 0x1)
		{
			RedEn = 0x1;
			PWM->PHCHG |= BIT9;
		}
		PWM->CMPDAT1 	= LedData.Buffer[0].DutyR;
	}
	
	
	
	if (LedData.Buffer[0].DutyB == 0)
	{
		if (BleEn != 0x0)
		{
			BleEn = 0x0;
			PWM->PHCHG &= ~(BIT12 | BIT4);
		}
	}
	else
	{
		if (BleEn != 0x1)
		{
			BleEn = 0x1;
			PWM->PHCHG |= BIT12;
		}
		PWM->CMPDAT4 	= LedData.Buffer[0].DutyB;
	}
	
	
	
// MCU pwm--------------------------------AL96---------------------------------------------
// BIT8  	CH0
// BIT9		CH1
// BIT10	CH2
// BIT11	CH3
// BIT12	CH4
// BIT13	CH5
#elif		AL96
	
	if (DutyG == 0)
	{
		if (GrnEn != 0x0)
		{
			GrnEn = 0x0;
			PWM->PHCHG &= ~(BIT8 | BIT0);
		}
	}
	else
	{
		if (GrnEn != 0x1)
		{
			GrnEn = 0x1;
			PWM->PHCHG |= BIT8;
		}
		PWM->CMPDAT0 	= DutyG;
	}
	
	
	if (DutyR == 0)
	{
		if (RedEn != 0x0)
		{
			RedEn = 0x0;
			PWM->PHCHG &= ~(BIT9 | BIT1);
		}
	}
	else
	{
		if (RedEn != 0x1)
		{
			RedEn = 0x1;
			PWM->PHCHG |= BIT9;
		}
		PWM->CMPDAT1 	= DutyR;
	}
	
	
	
	if (DutyB == 0)
	{
		if (BleEn != 0x0)
		{
			BleEn = 0x0;
			PWM->PHCHG &= ~(BIT12 | BIT4);
		}
	}
	else
	{
		if (BleEn != 0x1)
		{
			BleEn = 0x1;
			PWM->PHCHG |= BIT12;
		}
		PWM->CMPDAT4 	= DutyB;
	}
	
	if (DutyW == 0)
	{
		if (WhtEn != 0x0)
		{
			WhtEn = 0x0;
			PWM->PHCHG &= ~(BIT13 | BIT5);
		}
	}
	else
	{
		if (WhtEn != 0x1)
		{
			WhtEn = 0x1;
			PWM->PHCHG |= BIT13;
		}
		PWM->CMPDAT5 	= DutyW;
	}

	
// ------------------------------------AL99-------------------------------------------------
#elif AL99
	_Uint8	ColorTemp		= 0;
  _Uint8  TempBit  		= 0;
	_Uint8	*DataBufAdd	= 0;
	_Uint8  DataBuf 		= 0;
	_Uint8	TimeTemp		= 0;
	
	
	DataBufAdd = (_Uint8 *)ColorBuffer[0];	
	
	TimeTemp = 100;
	while(TimeTemp--);
	
	/* Group 1 */
	/* 按地址加1的方式发送一组灯的所有颜色数据 */
	for (ColorTemp = 0; ColorTemp < GROUP_COLOR_TOTAL; ColorTemp++)			//select LED
	{
		DataBuf = *DataBufAdd++;
		DataBuf /= LIGHT_LEVEL;
					
		for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM_1 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_1 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM_1 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_1 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;																			/* move one bit to the left 											*/					
		}
	}
	
	
	
	/* Group 2 */
	TimeTemp = 100;
	while(TimeTemp--);
	
	/* 按地址加1的方式发送一组灯的所有颜色数据 */
	for (ColorTemp = 0; ColorTemp < GROUP_COLOR_TOTAL; ColorTemp++)			//select LED
	{
		DataBuf = *DataBufAdd++;
		DataBuf /= LIGHT_LEVEL;
					
		for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM_2 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_2 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM_2 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_2 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;																			/* move one bit to the left 											*/					
		}
	}
	
	
	
	/* Group 3 */	
	TimeTemp = 100;
	while(TimeTemp--);
	
	/* 按地址加1的方式发送一组灯的所有颜色数据 */
	for (ColorTemp = 0; ColorTemp < GROUP_COLOR_TOTAL; ColorTemp++)			//select LED
	{
		DataBuf = *DataBufAdd++;
		DataBuf /= LIGHT_LEVEL;
					
		for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM_3 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_3 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM_3 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_3 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;																			/* move one bit to the left 											*/					
		}
	}
	
	
	
	/* Group 4 */
	TimeTemp = 100;
	while(TimeTemp--);
	
	/* 按地址加1的方式发送一组灯的所有颜色数据 */
	for (ColorTemp = 0; ColorTemp < GROUP_COLOR_TOTAL; ColorTemp++)			//select LED
	{
		DataBuf = *DataBufAdd++;
		DataBuf /= LIGHT_LEVEL;
					
		for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM_4 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_4 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM_4 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_4 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;																			/* move one bit to the left 											*/					
		}
	}
	
	
	/* Group 5 */
	/* 按地址加1的方式发送一组灯的所有颜色数据 */
	for (ColorTemp = 0; ColorTemp < GROUP_COLOR_TOTAL; ColorTemp++)			//select LED
	{
		DataBuf = *DataBufAdd++;
		DataBuf /= LIGHT_LEVEL;
					
		for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM_5 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_5 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM_5 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_5 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;																			/* move one bit to the left 											*/					
		}
	}
	
	
	
	/* Group 6 */
	TimeTemp = 100;
	while(TimeTemp--);
	
	/* 按地址加1的方式发送一组灯的所有颜色数据 */
	for (ColorTemp = 0; ColorTemp < GROUP_COLOR_TOTAL; ColorTemp++)			//select LED
	{
		DataBuf = *DataBufAdd++;
		DataBuf /= LIGHT_LEVEL;
					
		for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM_6 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_6 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM_6 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_6 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;																			/* move one bit to the left 											*/					
		}
	}
	
	/* Group 7 */
	TimeTemp = 100;
	while(TimeTemp--);
	
	/* 按地址加1的方式发送一组灯的所有颜色数据 */
	for (ColorTemp = 0; ColorTemp < 18; ColorTemp++)			//select LED
	{
		DataBuf = *DataBufAdd++;
					
		for (TempBit = 0; TempBit < 8; TempBit++)							/* Send the bit data one bye one									*/
		{
			if ((DataBuf & 0x80) == 0x80)												/* Bit 1 data send																*/
			{
				PORT_COMM_7 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");	
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_7 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			else																								/* Bit0 data send																	*/
			{
				PORT_COMM_7 = SET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");
				PORT_COMM_7 = RESET;
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
				__asm("nop");__asm("nop");__asm("nop");__asm("nop");
			}
			DataBuf <<= 1;		 											
		}
	}
	
	DataBufAdd = 0;

#endif
}

