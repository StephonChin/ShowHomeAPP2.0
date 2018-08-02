/***********************************************************************
 *
 * FILE NAME		| Led_Class.h
 * DATE					| 01 NOV. 2017
 * BRIEF				| The head file for Led communicate file
 *
************************************************************************/
#ifndef __LED_CLASS_H__
#define __LED_CLASS_H__

/*
 * Include Files
 */
#include "TypeDef.h"
#include "stm32f10x_gpio.h"
#include "Show.h"
#include "Key.h"

/*
 * Define
 */
#define		GRP_RIGHT					52
#define		BYTE_RIGHT				156

#define		GRP_MIDDLE				63
#define		BYTE_MIDDLE				189

#define		GRP_LEFT					56
#define		BYTE_LEFT					168

#define		GRP_MIX_R					50
#define		BYTE_MIX_R				150

#define		GPR_MIX_L					35
#define		BYTE_MIX_L				105

#define		GRP_TREE					10
#define		BYTE_TREE					30

#define		DIP_LEVEL					3
#define		SMT_LEVEL					3

/*
 * Type Redefine
 */
typedef struct _LED_TYPE
{
	_Uint8 DutyR;
	_Uint8 DutyG;
	_Uint8 DutyB;
}_TypeLed;

typedef struct _GROUND_TYPE
{
	_TypeLed	Snow[21];
	_TypeLed	Tree[27];
	_TypeLed	Ball[4];
	_TypeLed	Cane[30];
	_TypeLed	Spot[3];
}_TypeGround;



/*
 * Exported Functions
 */
void Led_Update(void);


/*
 * File Functions
 */
static void Send_Data_Process(void);


/*
 * Exported Parameters
 */
extern _TypeLed	Roof30[];
extern _TypeLed	Roof40[];
extern _TypeLed	Roof24[];
extern _TypeLed	Roof10[];
extern _TypeLed String30[];
extern _TypeLed	String24[];
extern _TypeLed String36[];
extern _TypeGround 		Grd;
 











#endif /* #ifndef __LED_CLASS_H__ */
