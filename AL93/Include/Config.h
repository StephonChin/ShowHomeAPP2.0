/**************************************************************************************
	*
	* @FileName	Config.h
	* 
***************************************************************************************/
#ifndef __CONFIG_H__
#define __CONFIG_H__


/* <--------Include Files---------> */
#include "System.h"



/* <---------- Bits Define ----------> */
#define BIT0			(0x1 << 0)
#define BIT1			(0x1 << 1)
#define BIT2			(0x1 << 2)
#define BIT3			(0x1 << 3)
#define BIT4			(0x1 << 4)
#define BIT5			(0x1 << 5)
#define BIT6			(0x1 << 6)
#define BIT7			(0x1 << 7)



/* <------------ Port Define -------------> */
#define PORT_MOTOR							P23
#define PORT_R_1								P02
#define PORT_R_2								P05
#define PORT_R_3 								P22
#define PORT_B_1 								P03
#define PORT_B_2								P06
#define PORT_B_3 								P20
#define PORT_G_1 								P01
#define PORT_G_2								P07
#define PORT_G_3 								P21
#define PORT_W_1 								P00
#define PORT_W_2 								P04
#define PORT_W_3 								P26




/***
	* @Exported Functions
***/
void MCU_Config(void);


/***
	* @File FUnctions
***/
static void CLK_Init(void);
static void GPIO_Init(void);
static void TIM_Init(void);
static void UART_Init(void);




#endif
