/**********************************************************************
	*
	* @FunctionName	Eprom.c
	*
***********************************************************************/
#include "Eprom.h"


/* @Const Variables */
volatile _Uint8	code DataAPROM[128]	_at_ 0x0200;


/* @Gloable variables */
_TypeStructAP		APData;


/*****************************************************************************
	*
	* @FunctionName Byte_Write_To_APROM
	* @Output 			None
	* @Input				None
	*
****/
void Byte_Write_To_APROM(void)
{
	/* Disable the Interrupt */
	IE &= ~BIT7;
	
	/* Read CONFIG1' value */
	TA			= 0xAA;
	TA			= 0x55;
	CHPCON	|= BIT0;			// IAPEN = 1
	
	TA			= 0xAA;
	TA			= 0x55;
	IAPUEN	|= BIT0;			//APUEN	= 1
	
	IAPCN		= APROM_ERASE;
	IAPAH		= 0x02;
	IAPAL		= 0x00;
	IAPFD		= 0xFF;
	TA			= 0xAA;
	TA			= 0x55;
	IAPTRG	|= BIT0;

	
	/* Write mode value to 0x0200 */
	IAPCN		= APROM_WRITE;
	IAPAH		= 0x02;
	IAPAL		= 0x00;
	IAPFD		= APData.Mode;	
	TA			= 0xAA;
	TA			= 0x55;
	IAPTRG	|= BIT0;			// Start IAP
	
	/* Write color value to 0x0201 */
	IAPCN		= APROM_WRITE;
	IAPAH		= 0x02;
	IAPAL		= 0x01;
	IAPFD		= APData.Color;	
	TA			= 0xAA;
	TA			= 0x55;
	IAPTRG	|= BIT0;			// Start IAP
	
	
	/* Write count down hour to 0x0202 */
	IAPCN		= APROM_WRITE;
	IAPAH		= 0x02;
	IAPAL		= 0x02;
	IAPFD		= APData.CntDwnHour;	
	TA			= 0xAA;
	TA			= 0x55;
	IAPTRG	|= BIT0;			// Start IAP
	
	
	TA			= 0xAA;
	TA			= 0x55;
	IAPUEN	&= ~BIT0;
	
	TA			= 0xAA;
	TA			= 0x55;
	CHPCON	&= ~BIT0;
	
	/* Enable Interrupt */
	IE |= BIT7;
}


/********************************************************
	*
	* @FunctionName	Byte_Read_From_APROM
	*
*********************************************************/
_Uint8 Byte_Read_From_APROM(_TypeEnumEprom AddBuf)
{
	return(DataAPROM[AddBuf]);
}