/***********************************************************************
 *
 * FILE NAME		| Data_Process.h
 * DATE					| 01 NOV. 2017
 * BRIEF				| The head file for the data process
 *
************************************************************************/
#ifndef __DATA_PROCESS_H__
#define __DATA_PROCESS_H__


/*
 * Include Files
 */
#include "TypeDef.h"
#include "Key.h"
#include "Show.h"
#include "Led_Class.h"


/*
 * Const value define
 */
#define     RED             				0x00
#define     GREEN           				0x01
#define     BLUE            				0x02
#define     ORANGE         					0x03
#define     PINK            				0x04
#define     SPRING_GREEN    				0x05
#define     GOLD            				0x06
#define     PEACH           				0x07
#define     LAWN_GREEN      				0x08
#define     CYAN            				0x09
#define     SKY_BLUE        				0x0a
#define     YELLOW          				0x0b
#define     PURPLE          				0x0c
#define     WHITE           				0x0d
#define			COLD_WHITE							0x0e
#define			WARM_WHITE							0x0f
#define 		DARK_GREEN 							0x10
#define			DARK_RED								0x11


/*
 * Exported Functions
 */
void Data_Process(void);
void User_Data_Init(void);











#endif /* #ifndef __DATA_PROCESS_H__ */
