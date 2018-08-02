/********************************************************************
  *
  * FILE NAME      TypeDef.h
  *
*********************************************************************/
#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

//---------------------------< Include Files >----------------------//
#include "N76E885.h"


//---------------------------< Type Define >-----------------------//
typedef unsigned char       _Uint8;
typedef unsigned int        _Uint16;
typedef unsigned long       _Uint32;
typedef enum
{
  FALSE = 0,
  TRUE = !FALSE
}_Flag;


//--------------------------< Const Value Define >---------------//
#define     SET       (1)
#define     RESET     (0)


#endif

