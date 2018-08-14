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

#define     SET_SFRPAGE       BitTemp=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;EA=BitTemp;
#define     CLR_SFRPAGE       BitTemp=EA;EA=0;TA=0xAA;TA=0x55;SFRS&=~0x01;EA=BitTemp;


//--------------------< PORT Define >------------------------------
#define PORT_COMM       P07
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



#endif
