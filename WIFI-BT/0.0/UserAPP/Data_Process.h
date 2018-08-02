/********************************************************************
  *
  * FILE NAME      Data_Process.h
  *
*********************************************************************/
#ifndef __DATA_PROCESS_H__
#define __DATA_PROCESS_H__

//--------------------< Include Files >-------------------------------
#include "USART.h"
#include "Key_Scan.h"
#include "BT_Control.h"


//--------------------< Const Value Define >--------------------------
#define     COLOR_MAX           0x1C
#define     MODE_MAX            0x0A
#define     SHOW_MODE_MAX       0x2
#define     SHOW_THEME_MAX      0x1D
#define     SHOW_THEME_MIN      0x15


//--------------------< Exported Function >---------------------------
void User_Data_Init(void);
void Data_Process(void);

//--------------------< File Functions >------------------------------
static void Key_Process(void);
static void CSR1010_Process(void);
static void Wifi_Process(void);



#endif
