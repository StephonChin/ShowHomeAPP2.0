/**************************************************************************************
	*
	* @FileName	System.h
	* 
***************************************************************************************/
#ifndef __SYSTEM_H__
#define __SYSTEM_H__


/* <----------- Include Files ----------> */
#include "N76E885.h"


/* <---------- Type Defines ----------> */
typedef unsigned char				_Uint8;
typedef unsigned int				_Uint16;
typedef unsigned long				_Uint32;
typedef signed char					_Sint8;
typedef signed int					_Sint16;
typedef signed long 				_Sint32;
typedef enum _FLAG_TYPE_DEF
{
	FALSE,
	TRUE = !FALSE
} _Flag;

#define SET					1
#define RESET				0


#endif
