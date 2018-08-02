/***********************************************************************
 *
 * FILE NAME		| Config.h
 * DATE					| 01 NOV. 2017
 * BRIEF				| The head file for the configuration of the STM32F103C8T6
 *
************************************************************************/
#ifndef __CONFIG_H__
#define __CONFIG_H__

/*
 * Include File
 */
#include "TypeDef.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_iwdg.h"

/*
 * Port Define
 */
#define		PORT_KEY				GPIOA,GPIO_Pin_8


/*
 * Exported Functions
 */
void MCU_Config(void);

/*
 * File Functions
 */
static void CLK_Initialize(void);
static void GPIO_Initialize(void);
static void TIM_Initialize(void);
static void IWDG_Initialize(void);

















#endif /* #ifndef __CONFIG_H__ */
