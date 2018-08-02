/***********************************************************************
 *
 * FILE NAME		| Key.h
 * DATE					| 01 NOV. 2017
 * BRIEF				| The head file for the key scan file
 *
************************************************************************/
#ifndef __KEY_H__
#define __KEY_H__

/*
 * Include Files
 */
#include "TypeDef.h"
#include "stm32f10x_gpio.h"
#include "Config.h"


/*
 * Type Redefine
 */
typedef enum _KEY_ENUM
{
	KEY_IDLE,
	KEY_SHOW_ONE,
	KEY_SHOW_TWO,
	KEY_SHOW_THREE,
	KEY_SHOW_FOUR
}_TypeKey;


/*
 * Exported Functions
 */
void Key_Scan(void);


/*
 * Exported Parameters
 */
extern _TypeKey			KeyStatus;
extern _Flag				KeyDetFlag;













#endif /* #ifndef __KEY_H__ */
