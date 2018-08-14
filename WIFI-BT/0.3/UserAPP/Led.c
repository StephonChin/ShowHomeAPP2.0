/********************************************************************
  *
  * FILE NAME      Led.c
  *
*********************************************************************/
#include "Led.h"


//Global arguments
_Uint8    LedMode = LED_WIFI_STANDBY;
bit       LedInit = TRUE;


//File arguments
_TypeLed_U   xdata  LedData;
bit       UpdateFlag;
_Uint8    LedStep;
_Uint8    LedTime;
_uint8    TempR;
_uint8    TempG;
_uint8    TempB;
bit       DirectFlag;
_uint8    HorseCnt;


_uint8 code B_FADE[][3]={
  0, 0, 250,
  0, 10, 250,
  0, 20, 250,
  0, 30, 250,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
};

_uint8 code R_FADE[][3]={
  250, 0, 0,
  250, 10, 0,
  250, 20, 0,
  250, 30, 0,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
  0, 0, 0,
};


/**
  * Led_Updae
  *   > Update the led driver data
  *   > Led type: SK6812MINI-3535
  *   > 0: 0.3u + 0.9u    1: 0.9u + 0.3u
  */
static void Led_Update(void)
{
  _uint8  bitCnt    = 0;
  _uint8  byteCnt   = 0;
  _uint8  tempBuf   = 0;
  _uint8  * pBuf    = 0;
  _uint8  volatile delay     = 0;

  if (UpdateFlag == FALSE)    return;
  UpdateFlag = FALSE;

  pBuf = &LedData.SendBuf;
  for (byteCnt = 0;byteCnt < COLOR_TOTAL;byteCnt++){
    tempBuf = *pBuf;
    pBuf++;
    for (bitCnt = 0; bitCnt < 8; bitCnt++){
      if ((tempBuf & 0x80) != 0x80){
        PORT_COMM = SET;
        delay = 0;
        PORT_COMM = RESET;
      }
      else{
        PORT_COMM = SET;
        delay = 0;delay = 0;delay = 0;delay = 0;
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
  //LedMode = LED_WIFI_STANDBY;
  switch (LedMode){
    case LED_OFF:               Led_Off();              break;
    case LED_WIFI_STANDBY:      Wifi_Standby();         break;
    case LED_WIFI_DISCONNECT:   Wifi_Disconnect();      break;
    case LED_WIFI_CONNECTED:    Wifi_Connected();       break;
    case LED_NORMAL:            Led_Normal();           break;
    case LED_ERROR:             Led_Err();              break;
  }
  
  Led_Update();
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
    
    UpdateFlag = TRUE;
  }
}

/**
  * Led_Normal
  */
static void Led_Normal(void)
{
  _uint8  temp = 0;
  if (LedInit == TRUE){
    LedInit = FALSE;
    for (temp = 0; temp < LED_TOTAL; temp++){
      LedData.Buffer[temp].DutyR = 0;
      LedData.Buffer[temp].DutyG = 0;
      LedData.Buffer[temp].DutyB = 0;
    }
    UpdateFlag = TRUE;
    LedTime = 0;
    LedStep = 0;
    TempR = 0;
    TempG = 0;
    TempB = 0;
  }
  
  
  switch (LedStep){
    case 0:{
      LedTime++;
      if (LedTime > 3){
        LedTime = 0;
        TempR = 0;  TempG = 240; TempB = 0;
        HorseCnt++;
        if (HorseCnt > 10){
          HorseCnt = 0;
          LedStep++;
        }
        
        for (temp = 9; temp > 0; temp--){
          LedData.Buffer[temp].DutyR = LedData.Buffer[temp - 1].DutyR;
          LedData.Buffer[temp].DutyG = LedData.Buffer[temp - 1].DutyG;
          LedData.Buffer[temp].DutyB = LedData.Buffer[temp - 1].DutyB;
        }
        LedData.Buffer[0].DutyR = TempR;
        LedData.Buffer[0].DutyG = TempG;
        LedData.Buffer[0].DutyB = TempB;
      }
    } break;
    
    case 1:{
      if (TempG > 0)    TempG -= 3;
      else{
        LedMode = LED_OFF;
        LedInit = TRUE;
      }
      
      for (temp = 0; temp < LED_TOTAL; temp++){
        LedData.Buffer[temp].DutyR = TempR;
        LedData.Buffer[temp].DutyG = TempG;
        LedData.Buffer[temp].DutyB = TempB;
      }
    } break;
  }
  
  
  
  
  
  
  UpdateFlag = TRUE;
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
  _uint8  temp = 0;
  if (LedInit == TRUE){
    LedInit = FALSE;
    for (temp = 0; temp < LED_TOTAL; temp++){
      LedData.Buffer[temp].DutyR = 255;
      LedData.Buffer[temp].DutyG = 0;
      LedData.Buffer[temp].DutyB = 0;
    }
    UpdateFlag = TRUE;
    LedTime = 0;
    LedStep = 0;
    TempR = 255;
    TempG = 0;
    TempB = 0;
    HorseCnt = 0;
  }
 
  if (LedTime < 4){
    LedTime++;
    return;
  }
  LedTime = 0;
 
  switch (LedStep){
    case 0:{
      if (TempG < 255)    TempG += 15;
      else                LedStep++;
    } break;
    
    case 1:{
      if (TempR > 0)      TempR -= 15;
      else                LedStep++;
    } break;
    
    case 2:{
      if (TempB < 255)    TempB += 15;
      else                LedStep++;
    } break;
    
    case 3:{
      if (TempG > 0)      TempG -= 15;
      else                LedStep++;
    } break;
    
    case 4:{
      if (TempR < 255)    TempR += 15;
      else                LedStep++;
    } break;
    
    case 5:{
      if (TempB > 0)      TempB -= 15;
      else                LedStep = 0;
    } break;
  }
  
  for (temp = LED_TOTAL - 1; temp > 0; temp--){
    LedData.Buffer[temp].DutyR = LedData.Buffer[temp - 1].DutyR;
    LedData.Buffer[temp].DutyG = LedData.Buffer[temp - 1].DutyG;
    LedData.Buffer[temp].DutyB = LedData.Buffer[temp - 1].DutyB;
  }
  LedData.Buffer[0].DutyR = TempR;
  LedData.Buffer[0].DutyG = TempG;
  LedData.Buffer[0].DutyB = TempB;
  
  UpdateFlag = TRUE;
}


/**
  * Wifi_Connected
  */
static void Wifi_Connected(void)
{
  _uint8  temp = 0;
  if (LedInit == TRUE){
    LedInit = FALSE;
    
    LedTime = 0;
    LedStep = 0;
    TempR = 0;
    TempG = 0;
    TempB = 240;
    for (temp = 0; temp < LED_TOTAL; temp++){
      LedData.Buffer[temp].DutyR = TempR;
      LedData.Buffer[temp].DutyG = TempG;
      LedData.Buffer[temp].DutyB = TempB;
    }
    UpdateFlag = TRUE;
  }
  
  
  if (LedTime < 100){
    LedTime++;
    return;
  }
  
  
  if (TempB > 0)   TempB -= 3;
  else{
    LedMode = LED_OFF;
    LedInit = TRUE;
  }

  
  
  for (temp = 0; temp < LED_TOTAL; temp++){
    LedData.Buffer[temp].DutyR = TempR;
    LedData.Buffer[temp].DutyG = TempG;
    LedData.Buffer[temp].DutyB = TempB;
  }
  
  UpdateFlag = TRUE;
}


/**
  * Wifi_Connecting
  */
static void Wifi_Disconnect(void)
{
  _uint8  temp = 0;
  if (LedInit == TRUE){
    LedInit = FALSE;
    for (temp = 0; temp < LED_TOTAL; temp++){
      LedData.Buffer[temp].DutyR = R_FADE[temp][0];
      LedData.Buffer[temp].DutyG = R_FADE[temp][1];
      LedData.Buffer[temp].DutyB = R_FADE[temp][2];
    }
    UpdateFlag = TRUE;
    LedTime = 0;
    LedStep = 0;
    TempR   = 0;
    TempG   = 0;
    TempB   = 0;
  }
  
  if (LedTime < 10){
    LedTime++;
    return;
  }
  LedTime = 0;
  
  TempR = LedData.Buffer[LED_TOTAL - 1].DutyR;
  TempG = LedData.Buffer[LED_TOTAL - 1].DutyG;
  TempB = LedData.Buffer[LED_TOTAL - 1].DutyB;
  for (temp = LED_TOTAL - 1; temp > 0; temp--){
    LedData.Buffer[temp].DutyR = LedData.Buffer[temp - 1].DutyR;
    LedData.Buffer[temp].DutyG = LedData.Buffer[temp - 1].DutyG;
    LedData.Buffer[temp].DutyB = LedData.Buffer[temp - 1].DutyB;
  }
  LedData.Buffer[0].DutyR = TempR;
  LedData.Buffer[0].DutyG = TempG;
  LedData.Buffer[0].DutyB = TempB;

  
  
  UpdateFlag = TRUE;
}


