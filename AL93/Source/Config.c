/********************************************************************************
	*
	* @FileName	Config.c
	* 
*********************************************************************************/
#include "Config.h"



/**************************************************************
	*
	* @FunctionName	MCU_Config
	* @Output				None
	* @Input				None
	*
****/
void MCU_Config(void)
{
	/* Disable Interrupt */
	IE &= ~BIT7;
	
	/* Clock Initialize */
	CLK_Init();
	
	/* General I/O Initialize */
	GPIO_Init();
	
	/* Timer Initialize */
	TIM_Init();
	
	/* UART Initialize */
	UART_Init();
	
	/* Enable Interrupt */
	IE |= BIT7;
}


/****************************************************************
	*
	* @FunctionName CLK_Init
	* @Output 			None
	* @Input				None
	*
****/
static void CLK_Init(void)
{
	_Uint16	ClkChgTime = 10000;
	
	TA		= 0xAA;
	TA		= 0x55;
	CKEN	|= BIT7;					// change clock to HXT
	
	
	while ( !(CKSWT & 0x80) && (ClkChgTime != 0))					ClkChgTime--;		/* Wait HXT stable */
	
	/* HXT open successfully */
	if (ClkChgTime > 0)  
	{
		TA		= 0xAA;
		TA		= 0x55;
		CKSWT = 0x2;				// switch source to HXT
		
		TA		= 0xAA;
		TA		= 0x55;
		CKEN &= ~BIT5;			// Close HIRC
	}
	
	/* HXT open faily */
	else
	{
		TA		= 0xAA;
		TA		= 0x55;
		CKSWT &= ~(BIT1 | BIT0);	
	}
}


/**************************************************************
	*
	* @FunctionName GPIO_Init
	* @Output 			None
	* @Input				None
	*
****/
static void GPIO_Init(void)
{
	_Uint8	Temp = 0;
	
	/* P00 ~ P07 P-P output */
	P0M1 	= 0x00;
	P0M2 	= 0xFF;
	P0		= 0xFF;
	
	/* P20 P21 P22 P23 P26 P-P output */
	P2M1	&= ~(BIT0 | BIT1 | BIT2 | BIT3 | BIT6);
	P2M2	|= (BIT0 | BIT1 | BIT2 | BIT3 | BIT6);
	P2 		|= (BIT0 | BIT1 | BIT2 | BIT6);
	P2		|= BIT3; 
}



/******************************************
	*
	* @FunctionName TIM_Init
	* @Output 			None
	* @Input				None
	*
****/
static void TIM_Init(void)
{
	/* TIMER 0 */
	TMOD = 0x2;
	CKCON |= BIT3;
	TL0 = 56;
	TH0 = 56;
	ET0	 = 1;
	TCON |= BIT4;
	
	
	
	/* TIMER 2 */
	T2CON 	= 0x0;
	T2MOD 	= 0xA0;
	RCMP2L 	= 0xEF;
	RCMP2H 	= 0xD8;				// 10ms
	TR2 	= 1;
}



/******************************************
	*
	* @FunctionName UART_Init
	* @Output 			None
	* @Input				None
	*
****/
static void UART_Init(void)
{
	/* P24 Rxd, P25 Txd*/
	P2M1	&= ~(BIT4 | BIT5);
	P2M2	&= ~(BIT4 | BIT5);
	P2		|= (BIT4 | BIT5);  		// P24 = 1, P25 = 1
	
	/* Set Uart */
	SCON_1 = 0x50;		// work at mode 1
	T3CON	|= BIT7;
	T3CON &= ~BIT6;
	
	/* Bond Rate 9600 */
	T3CON	&= ~(BIT0 | BIT1 | BIT2);
	RH3		= 0xFF;
	RL3 	= 0x98;								// Rate = 16M / (16 * (0xffff - 0xff98))	= 16M / (16 * 104) = 9600;
	T3CON |= BIT3;
	
	EIP1	|= BIT0;
	EIPH1	|= BIT0;
	

	/* Rcv Interrupt Enable */
	EIE1 |= BIT0;
}








