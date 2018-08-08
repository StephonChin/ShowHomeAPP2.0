/*************************************************************************
	*
	* FileName		MCU_Config.c
	*
**************************************************************************/
#include "Config.h"

bit BIT_TMP;

/*****************************************
	* FunctionName    MCU_Config
******************************************/
void MCU_Config(void)
{
	IE &= ~BIT7;
	CLK_Init();
	GPIO_Init();
	TIM_Init();
	IE |= BIT7;
}



/********************************************
	* CLK_Init()
*********************************************/
static void CLK_Init(void)
{
	CKSWT	= 0x00;
	CKDIV	= 0x00;
}

/********************************************
	* GPIO_Init()
*********************************************/
static void GPIO_Init(void)
{
  //P11,P12,P13,P14
  P1M1 &= ~(BIT1 | BIT2 | BIT3 | BIT4);
	P1M2 |= (BIT1 | BIT2 | BIT3 | BIT4);
	P1   &= ~(BIT1 | BIT2 | BIT3 | BIT4);
  
	
	// Close the BOD
	TA = 0xAA;
	TA = 0x55;
	BODCON0 = 0x0;
}



/********************************************
	* TIM_Init()
*********************************************/
static void TIM_Init(void)
{
	/* TIMER 0 */
	TMOD    = 0x2;
	CKCON  &= ~BIT3;    //1.3333M
  TL0     = 122;
  TH0     = 122;   //184 / 1.333 = 100us
	ET0     = 1;
	TR0     = 1;
	
	/* TIMER 2 */
	T2CON 	= 0x0;
	T2MOD 	= 0xA0;     //16 / 16 = 1M

  RCMP2L 	= 0xF0;
  RCMP2H 	= 0xD8;			//10ms
	TR2 	= 1;
}

