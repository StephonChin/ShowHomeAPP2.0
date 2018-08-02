/*******************************************************************************
	*
	* FILENAME
	*						TypeDef.h
	*
	* BRIEF
	*						Data type redefine
	*						MCU header file
	*           Const value redefine
	*						Device type define
*******************************************************************************/
#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

/*-------------------------< Include Files >-----------------------------*/
#include "N76E885.h"
#include "Type_Private.h"


/*-------------------------< Data type redefine >-----------------------------*/
typedef 		unsigned char				_Uint8;
typedef 		unsigned short				_Uint16;
typedef			unsigned int				_Uint32;
typedef 		signed char					_Sint8;
typedef			signed short				_Sint16;
typedef			signed int					_Sint32;
typedef enum
{
    FALSE,
    TRUE
}_Flag;



/*-------------------------< Const Value Redefine >-----------------------------*/
#define		RESET						 (0)
#define		SET							 (1)
#define     FALSE                        (0)
#define     TRUE                         (1)




/*-------------------------< Device Type Redefine >-----------------------------*/
#define DEVICE_NAME_ONE		'L'
#define DEVICE_NAME_TWO		'A'
#define	DEVICE_NUM			'1'
#define HORSE_SYN_CNT		1


//----------------------------------------------------------------
// Version Information
//----------------------------------------------------------------
#define		SOFT_VER					0x10
#define		PROTOCOL_VER			    0x19


#endif
