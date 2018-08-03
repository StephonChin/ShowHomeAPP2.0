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
typedef unsigned char				_Uint8,_Flag;
typedef unsigned int				_Uint16;
typedef unsigned long				_Uint32;
typedef signed char					_Sint8;
typedef signed int					_Sint16;
typedef signed long 				_Sint32;


#ifndef SET
	#define SET					1
	#define RESET				0
#endif

#ifndef TRUE
	#define	TRUE				1
	#define	FALSE				0
#endif

#ifndef ENABLE
	#define	ENABLE			1
	#define DISABLE			0
#endif

//Device type define
#define 	DEVICE_NAME_ONE				'L'
#define 	DEVICE_NAME_TWO				'A'
#define 	DEVICE_NUM						'D'

#endif
