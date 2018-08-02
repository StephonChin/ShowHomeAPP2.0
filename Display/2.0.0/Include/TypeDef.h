/***********************************************************************
 *
 * FILE NAME		| TypeDef.h
 * DATE					| 01 NOV. 2017
 * BRIEF				| The head file for the data type redefine and some
 *                const prameters redefine
 *
************************************************************************/
#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

/*
 * Include File
 */
#include "stm32f10x.h"


/*
 * Type Redefine
 */
typedef unsigned char					_Uint8;
typedef unsigned short				_Uint16;
typedef unsigned int					_Uint32;
typedef signed char						_Sint8;
typedef signed short					_Sint16;
typedef signed int						_Sint32;
typedef enum
{
	FALSE = 0,
	TRUE = !FALSE
}_Flag;

/*
 * Const value define
 */
#define		R		(0)
#define		G		(1)
#define		B		(2)



#endif /* #ifndef __TYPEDEF_H__ */
