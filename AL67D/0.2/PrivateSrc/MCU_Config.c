/********************************************************************
	*
 	* File Name				= Configuration.c
 	* Date						= 2016.10.28
 	* Author					= DS.Chin
	*
*********************************************************************/
#include "MCU_Config.h"

_Uint8			HseStatus = 0;


/******************************************************************
	*
	* Function Name			MCU_Config
	*
******************************************************************/
void MCU_Config(void)
{
    /* Disable Interrupt */
	IE &= ~BIT7;
    
	CLK_Init();
	
	GPIO_Init();
	
	TIM_Init();
	
	ADC_Init();
	
	UART_Init();
    
    WDT_Init();
    
    /* Enable Interrupt */
	IE |= BIT7;
}

/******************************************************************
	*
	* Function Name			CLK_Init
	*
******************************************************************/
static void CLK_Init(void)
{
	_Uint16	ClkChgTime = 10000;
	
	TA		= 0xAA;
	TA		= 0x55;
	CKEN|= BIT7;					// change clock to HXT
	
	
	while ( !(CKSWT & 0x80) && (ClkChgTime != 0))					ClkChgTime--;		/* Wait HXT stable */
	
	/* HXT open successfully */
	if (ClkChgTime > 0)  
	{
		TA      = 0xAA;
		TA      = 0x55;
		CKSWT   = 0x2;				// switch source to HXT
		
		TA		= 0xAA;
		TA		= 0x55;
		CKEN   &= ~BIT5;			// Close HIRC
		
		HseStatus = 1;
	}
	
	/* HXT open fail */
	else
	{
		TA		= 0xAA;
		TA		= 0x55;
		CKSWT  &= ~(BIT1 | BIT0);	
		HseStatus = 0;
	}
}

/******************************************************************
	*
	* Function Name			GPIO_Init
	*
******************************************************************/
static void GPIO_Init(void)
{
	//P20 P21 P22 P23 output P-P
	P2M1 &= ~(BIT0 | BIT1 | BIT2 | BIT3);
	P2M2 |= (BIT0 | BIT1 | BIT2 | BIT3);
	P2   &= ~(BIT0 | BIT1 | BIT2 | BIT3);
	
	//P02 P05 P06 P07 output P-P
    P0M1 &= ~(BIT2 | BIT5 | BIT6 | BIT7);
    P0M2 |= (BIT2 | BIT5 | BIT6 | BIT7);
    P0   &= ~(BIT2 | BIT5 | BIT6 | BIT7);
    
    //P26 Input
    P2M1 |= BIT6;
    P2M2 &= ~BIT6;
    
    //PIO11_T P04, VDD_CE P01
    P0M1 &= ~BIT1;
    P0M2 |= BIT1;
    P0   |= BIT1;
    P0M1 |= BIT4;
    P0M2 &= ~BIT4;
    
}

/******************************************************************
	*
	* Function Name			TIM_Init
	*
******************************************************************/
static void TIM_Init(void)
{
	/* TIMER 0 */
	TMOD    = 0x2;
	CKCON  &= ~BIT3;    //8/12 = 2/3M or 1.843M
    if (HseStatus > 0)  //external 8M crystal
    {
        TL0     = 190;
        TH0     = 190;  //66 * 3 / 2 = 100us
    }
    else
    {
        TL0     = 72;
        TH0     = 72;   //184 / 1.843 = 100us
    }
	ET0     = 1;
	TCON   |= BIT4;
	
	/* TIMER 2 */
	T2CON 	= 0x0;
	T2MOD 	= 0xA0;     //8/16 = 0.5M = 2us or 22.118 / 16 = 1.382375M
    
    if (HseStatus > 0)
    {
        
        RCMP2L 	= 0xF0;
        RCMP2H 	= 0xD8;				//20ms
    }
    else
    {
        RCMP2L 	= 0x00;
        RCMP2H 	= 0x94;				//20ms
    }
	TR2 	= 1;
}


/*******************************************************************
	*
	* Function Name			ADC_Init
	*
******************************************************************/
static void ADC_Init(void)
{
    //P03 Selected as A/D input
	P0M1 |= BIT3;
    P0M2 &= ~BIT3;
    
    //A/D configuration
    ADCCON0     = 0x03;         //Channel 3
    ADCCON1     = 0x21;         //Vref = VDD, Fadc = Fsys / 4,  ADC enable
    ADCCON2     = 0x0;
    ADCAQT      = 14;           // 20 cycle
    ADCS        = 1;            // Start to converse A/D value 
}


/******************************************************************
    *
	* FUNCTION NAME			UART_Init
	* INPUT					None
	* OUTPUT				None
    *
******************************************************************/
static void UART_Init(void)
{
	/* P24 Rx, P25 Tx*/
	P2M1	&= ~(BIT4 | BIT5);
	P2M2	&= ~(BIT4 | BIT5);
	P2		|= (BIT4 | BIT5);  	// P24 = 1, P25 = 1
	
	/* Set UART */
	SCON_1 = 0x50;		// work at mode 1
	T3CON	|= BIT7;
	T3CON &= ~BIT6;
	
	/* Bond Rate 9600 */
	T3CON	&= ~(BIT0 | BIT1 | BIT2);
    if (HseStatus > 0)
    {
        RH3		= 0xFF;
        RL3 	= 0xCC;			// Rate = 8M / (16 * (0xffff - 0xffCB + 1))	= 8M / (16 * 52) = 9600;
    }
    else
    {
        RH3		= 0xFF;
        RL3 	= 0x70;		// Rate = 22.118M / (16 * (0xffff - 0xff70 + 1))	= 22.118M / (16 * 144) = 9600;
    }
	T3CON |= BIT3;
	
	EIP1	|= BIT0;
	EIPH1	|= BIT0;
	

	/* Receive Interrupt Enable */
	EIE1 |= BIT0;
}

/******************************************************************
    *
	* FUNCTION NAME			WDT_Init
	* INPUT					None
	* OUTPUT				None
    *
******************************************************************/
static void WDT_Init(void)
{
    TA			= 0xAA;
    TA			= 0x55;
    WDCON       = 0xC3;     // 102.4ms
}





