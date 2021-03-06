/********************************************************************
  *
  * FILE NAME      Config.c
  *
*********************************************************************/
#include "Config.h"

/********************************************************************
  *
  * FunctioName    MCU_Config()
  *
*********************************************************************/
void MCU_Config(void)
{
  // Disable Interrupt
	IE &= ~BIT7;
  
  CLK_Init();
  
  GPIO_Init();
  
  TIM_Init();
  
  USART_Init();
  
  IWDG_Init();
  
  // Enable Interrupt
	IE |= BIT7;
}



//-----------------------------------------------------------------
// FunctionName   CLK_Init
//-----------------------------------------------------------------
static void CLK_Init(void)
{
  TA		  = 0xAA;
  TA		  = 0x55
  CKSWT  &= ~(BIT1 | BIT0);	      //Select HIRC as system clock Sys_Clk = 22.118M
}


//-----------------------------------------------------------------
// FunctionName   GPIO_Init
//-----------------------------------------------------------------
static void GPIO_Init(void)
{
  //P26 - Key1, P21 - PIO11
  P2M1  |= (BIT1 | BIT6);
  P2M2  &= ~(BIT1 | BIT6);
  
  //P23 - VDD_CE
  P2M1 &= ~BIT3;
  P2M2 |= BIT3;
  
  //P04 - R, P05 - G, P06 - B
  P0M1 &= ~(BIT4 | BIT5 | BIT6);
  P0M2 |= (BIT4 | BIT5 | BIT6);
  P0 &= ~(BIT4 | BIT5 | BIT6);
  
  PORT_BT_CE = SET;
}


//-----------------------------------------------------------------
// FunctionName   TIM_Init
//-----------------------------------------------------------------
static void TIM_Init(void)
{
  T2CON 	= 0x0;
	T2MOD 	= 0xA0;     // 22.118 / 16 = 1.382375M
    
  RCMP2L 	= 0x00;
  RCMP2H 	= 0xCA;			// 10ms
  
	TR2 	= 1;
  
  TMOD 	= 0x20;     // 8bit timers1 anto reload
	TCON 	= 0;        
  CKCON = 0x00;     // Syst = 22.118M / 12 = 1.84316666...
  TL1	= 0x00;
  TH1 	= 250;			// 1.84316666M / ((256 - 250) * 32) = 9600
  
	TR1 	= 1;
}


//-----------------------------------------------------------------
// FunctionName   USART_Init
//-----------------------------------------------------------------
static void USART_Init(void)
{
  // P24 Rx_1, P25 Tx_1, P20 Rx_0
	P2M1	&= ~(BIT0 | BIT4 | BIT5);
	P2M2	&= ~(BIT0 | BIT4 | BIT5);
	P2		|= (BIT0 | BIT4 | BIT5);  	// P24 = 1, P25 = 1
  
  //P03 Tx_0
  P0M1	&= ~BIT3;
	P0M2	&= ~BIT3;
	P0		|= BIT3;  	// P03 = 1
  
  
	
	// Set USART0 & USART1
  SCON    = 0x50;
	SCON_1  = 0x50;		// work at mode 1
	T3CON	  |= BIT7;
	T3CON   &= ~BIT6;
	
	/* Bond Rate 9600 */
	T3CON	&= ~(BIT0 | BIT1 | BIT2);
  RH3		= 0xFF;
  RL3 	= 0x70;		// Rate = 22.118M / (16 * (0xffff - 0xff70 + 1))	= 22.118M / (16 * 144) = 9600;
	T3CON |= BIT3;
	
	EIP1	|= BIT0;
	EIPH1	|= BIT0;
	

	/* Receive Interrupt Enable */
  IE    |= BIT4;
	EIE1  |= BIT0;
}


//-----------------------------------------------------------------
// FunctionName   IWDG_Init
//-----------------------------------------------------------------
static void IWDG_Init(void)
{
  TA			= 0xAA;
  TA			= 0x55;
  WDCON   = 0xC3;     // 102.4ms
}

