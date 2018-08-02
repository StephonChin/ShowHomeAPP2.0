/*******************************************************************************
	*
	* @File Name		Configuration.h
	* @Date					2016.12.19
	* @Author				DS.Chin
	* @CopyRight		(C) CopyRight  @2016 ~ 2026 Willis Ltd. Co.
	* @Description	This file contains all the function prototyped for the config
	*								fimer library
	*
*******************************************************************************/
#ifndef __MCU_CONFIG_H__
#define __MCU_CONFIG_H__


/*-----------------------< Include files >----------------------*/
#include "Type_Def.h"



/*----------------< I/O define & Bits define >------------------*/
#define				BIT0					(0x1 << 0)
#define				BIT1					(0x1 << 1)
#define				BIT2					(0x1 << 2)
#define				BIT3					(0x1 << 3)
#define				BIT4					(0x1 << 4)
#define				BIT5					(0x1 << 5)
#define				BIT6					(0x1 << 6)
#define				BIT7					(0x1 << 7)

#define				PORT_HOT			    P02
#define				PORT_KEY			    P26
#define				PORT_BLUE			    P05
#define				PORT_GREEN		        P06
#define				PORT_RED			    P07
#define				PORT_A					P20
#define				PORT_B					P21
#define				PORT_C					P22
#define				PORT_D					P23
#define             PORT_BT_CE              P01
#define             PORT_BT_DT              P04
#define             PORT_RX                 P25
#define             PORT_TX                 P24


/*----------------< File Function >------------------*/
static void CLK_Init(void);
static void GPIO_Init(void);
static void TIM_Init(void);
static void ADC_Init(void);
static void UART_Init(void);
static void WDT_Init(void);



/*----------------< Exported Function >------------------*/
void MCU_Config(void);


/*----------------< Exported Parameters >------------------*/
extern _Uint8			HseStatus;


#endif

