/********************************************************************
  *
  * FILE NAME      Config.h
  *
*********************************************************************/
#ifndef __CONFIG_H__
#define __CONFIG_H__


//----------------------< Include Fiels >---------------------------
#include "TypeDef.h"


//--------------------< Bit Define >------------------------------
#define  BIT0         (1<<0)
#define  BIT1         (1<<1)
#define  BIT2         (1<<2)
#define  BIT3         (1<<3)
#define  BIT4         (1<<4)
#define  BIT5         (1<<5)
#define  BIT6         (1<<6)
#define  BIT7         (1<<7)


//--------------------< PORT Define >------------------------------
#define PORT_KEY_1      P26
#define PORT_KEY_2      P07
#define PORT_R          P04
#define PORT_G          P05
#define PORT_B          P06
#define PORT_BT_DT      P21
#define PORT_BT_CE      P23
#define PORT_TX         P25
#define PORT_RX         P24


//--------------------< Exported Functions >----------------------
void MCU_Config(void);


//--------------------< File Functions >---------------------------
static void CLK_Init(void);
static void GPIO_Init(void);
static void TIM_Init(void);
static void USART_Init(void);
static void IWDG_Init(void);



#endif
