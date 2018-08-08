/********************************************************************
  *
  * FILE NAME      Led.c
  *
*********************************************************************/
#include "Led.h"


//Global arguments
_Uint8    LedMode;
bit       LedInit;


//File arguments
_TypeLed_U   xdata  LedData;
bit       UpdateFlag;
_Uint8    LedStep;
_Uint8    LedTime;



/**
  * Led_Updae
  *   > Update the led driver data
  *   > Led type: SK6812MINI-3535
  *   > 0: 0.3u + 0.9u    1: 0.9u + 0.3u
  */
static void Led_Updae(void)
{
  _uint8  bitCnt    = 0;
  _uint8  byteCnt   = 0;
  _uint8  tempBuf   = 0;
  _uint8  * pBuf    = 0;

  if (UpdateFlag == FALSE)    return;
  UpdateFlag = FALSE;

  pBuf = &LedData.SendBuf;
  for (byteCnt = 0;byteCnt < COLOR_TOTAL;byteCnt++){
    tempBuf = *pBuf;
    pBuf++;
    for (bitCnt = 0; bitCnt < 8; bitCnt++){
      if (tempBuf & 0x80 == 0x80){
        PORT_COMM = SET;
        ;;;;
        PORT_COMM = RESET;
        ;;;
      }
      else{
        PORT_COMM = SET;
        ;;;;;;;;;;;
        PORT_COMM = RESET;
      }

      tempBuf <<= 1;
    }
  }
}

/**
  * Led_Control
  *   > Control the led display mode
  */
void Led_Control(void)
{
  switch (LedMode){
    case LED_OFF:               Led_Off();              break;
    case LED_WIFI_STANDBY:      Wifi_Standby();         break;
    case LED_WIFI_CONNECTING:   Wifi_Connecting();      break;
    case LED_WIFI_CONNETED:     Wifi_Connected();       break;
    case LED_NORMAL:            Led_Normal();           break;
    case LED_ERROR:             Led_Err();              break;
  }
  
  Led_Updae();
}

/**
  * Led_Off
  */
static void Led_Off(void)
{
  _uint8  cnt = 0;
  if(LedInit == TRUE){
    LedInit = FALSE;
    for (cnt = 0; cnt < LED_TOTAL; cnt++){
      LedData.Buffer[cnt].DutyR = 0;
      LedData.Buffer[cnt].DutyG = 0;
      LedData.Buffer[cnt].DutyB = 0;
    }
  }
}

/**
  * Led_Normal
  */
static void Led_Normal(void)
{
  
}

/**
  * Led_Err
  */
static void Led_Err(void)
{

}

/**
  * Wifi_Standby
  */
static void Wifi_Standby(void)
{

}

/**
  * Wifi_Connected
  */
static void Wifi_Connected(void)
{

}


/**
  * Wifi_Connecting
  */
static void Wifi_Connecting(void)
{

}
