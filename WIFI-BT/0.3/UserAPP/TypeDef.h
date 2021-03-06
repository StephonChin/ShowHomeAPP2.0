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
typedef unsigned char       _Uint8,_Flag,_uint8,uint8;
typedef unsigned int        _Uint16,_uint16,uint16;
typedef unsigned long       _Uint32,_uint32,uint32;
typedef signed int          _Sint16;


//--------------------------< Const Value Define >---------------//
#ifndef SET
  #define     SET       (1)
  #define     RESET     (0)
#endif

#ifndef TRUE
  #define     TRUE        (1)
  #define     FALSE       (0)
#endif


#endif
