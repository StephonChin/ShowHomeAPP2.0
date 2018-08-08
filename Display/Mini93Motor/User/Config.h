/*******************************************************************
	*
	* FileName		MCU_Config.h
	*
*********************************************************************/
#ifndef __MCU_CONFIG_H__
#define __MCU_CONFIG_H__


/* Include files ---------------------------------------------------*/
#include "TypeDef.h"



/* Bits define -----------------------------------------------------*/
#define		BIT0		(0x1 << 0)
#define 	BIT1		(0x1 << 1)
#define 	BIT2		(0x1 << 2)
#define		BIT3		(0x1 << 3)
#define 	BIT4		(0x1 << 4)
#define 	BIT5		(0x1 << 5)
#define 	BIT6		(0x1 << 6)
#define		BIT7		(0x1 << 7)




/* Port define ------------------------------------*/
#define   PORT_A        P11
#define   PORT_B        P12
#define   PORT_C        P13
#define   PORT_D        P14

#define set_SFRPAGE  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS|=0x01;EA=BIT_TMP
#define clr_SFRPAGE  BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;SFRS&=~0x01;EA=BIT_TMP


/***
	* @Brief Exported Functions
	*/
void MCU_Config(void);



/***
	* @Brief File Functions
	*/
static void CLK_Init(void);
static void GPIO_Init(void);
static void TIM_Init(void);


extern bit BIT_TMP;


#endif
