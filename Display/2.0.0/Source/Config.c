/********************************************************************
	*
	* FILE NAME
	*									Config.c
	* DATE
	*									01 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									STM32F103C8T6 Configuration
	*
*********************************************************************/
#include "Config.h"

/*
 * FunctionName		MCU_Config
 */
void MCU_Config(void)
{
	CLK_Initialize();
	GPIO_Initialize();
	TIM_Initialize();
	IWDG_Initialize();
}

/*
 * FunctionName		CLK_Initialize
 */
static void CLK_Initialize(void)
{
	ErrorStatus HSEStartUpStatus;
	
	/* 时钟初始化 */
	RCC_DeInit();
	
	/* 使能外部晶振 */
	RCC_HSEConfig(RCC_HSE_ON);
	
	/* 等待外部晶振起振与稳定 */
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	/* 外部晶振失败 */
	if(HSEStartUpStatus != SUCCESS)
	{
		RCC_DeInit();
	}
	
	/* 倍频9倍,晶振为48M */
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_6);
	
	/* 使能PLL */
	RCC_PLLCmd(ENABLE);
	
	
	/* 选择PLL为系统时钟 */
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	
	
	/* 设置了AHB时钟 */
	RCC_HCLKConfig(RCC_SYSCLK_Div1);
	
	/* PCLK1 */
	RCC_PCLK2Config(RCC_HCLK_Div1);
	
	/* PCLK2 */
	RCC_PCLK1Config(RCC_HCLK_Div2);
	
	
	/* 检测是否使用了外部晶振作为时钟源 */
	if(RCC_GetSYSCLKSource() != 0x04)
	{
		;
	}
}

/*
 * FunctionName		GPIO_Initialize
 */
static void GPIO_Initialize(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC , ENABLE);
	
	/*
	 * Config the KEY PORT
	 * KEY1- PA3 KEY2-PA4 KEY3-PA5
	 * Input & No Pull(floating)
	 */
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;							
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/*
	 * Config the communication port & key input
	 * PA8
	 * Output & Open drain(there are 1k resistance pulled up)
	 */
	GPIO_InitStructure.GPIO_Pin   	=  GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode  	= GPIO_Mode_IPU;						
	GPIO_InitStructure.GPIO_Speed  	= GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	/*
	 * Config the communication port
	 * PC13 PB12 PB13 PB14 PB15
	 */
	GPIO_InitStructure.GPIO_Pin   	= GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode  	= GPIO_Mode_Out_OD;						
	GPIO_InitStructure.GPIO_Speed  	= GPIO_Speed_50MHz;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin   	= GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode  	= GPIO_Mode_Out_OD;						
	GPIO_InitStructure.GPIO_Speed  	= GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


/*
 * FunctionName		TIM_Initialize
 */
static void TIM_Initialize(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_TimeBaseStructure.TIM_ClockDivision	 	= 0;	
	TIM_TimeBaseStructure.TIM_Prescaler 	 		= 47;						// 48M / (48 + 1) = 1M
	TIM_TimeBaseStructure.TIM_CounterMode    	= TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period         	= 20000;					
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	TIM_Cmd(TIM3,ENABLE);
}


/*
 * FunctionName		IWDG_Initialize
 */
static void IWDG_Initialize(void)
{
	
}










