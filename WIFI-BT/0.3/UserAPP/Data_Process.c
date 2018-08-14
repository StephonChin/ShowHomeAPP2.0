/********************************************************************
  *
  * FILE NAME      Data_Process.c
  *
*********************************************************************/
#include "Data_Process.h"

_Uint8        NormalMode;
_Uint8        ShowMode;
_Uint8        NormalColor;
_Uint8        ShowColor;


EN_ERR_NUM   ErrNum;

_Uint8			  FlagChkTime;
_Flag					FlagChkFlag;

_Sint16       RndSeed;


/********************************************************************
  *
  * FunctionName    User_Data_Init
  *
*********************************************************************/
void User_Data_Init(void)
{
  NormalMode    = Byte_Read_From_APROM(APROM_NORMAL_MODE);
  NormalColor   = Byte_Read_From_APROM(APROM_NORMAL_COLOR);
  ShowMode      = Byte_Read_From_APROM(APROM_SHOW_MODE);
  ShowColor     = Byte_Read_From_APROM(APROM_SHOW_COLOR);

  if (NormalMode > NORMAL_MODE_MAX){
    NormalMode = 1;
    FlashSaveFlag = TRUE;
  }

  if (NormalColor > NORMAL_COLOR_MAX){
    NormalColor = 0;
    FlashSaveFlag = TRUE;
  }

  if (ShowMode > SHOW_MODE_MAX){
    ShowMode = 1;
    FlashSaveFlag = TRUE;
  }

  if (ShowColor > SHOW_COLOR_MAX){
    NormalMode = 1;
    FlashSaveFlag = TRUE;
  }
}



/********************************************************************
  *
  * FunctionName    Data_Process
  *
*********************************************************************/
void Data_Process(void)
{
  RndSeed += 199;
  Key_Process();

  CSR1010_Process();

  Wifi_Process();
}


//-------------------------------------------------------------------
// FunctionName     Key_Process
//-------------------------------------------------------------------
static void Key_Process(void)
{
  if (KeyStatus == KEY_1_SHORT)
  {

  }
  else if (KeyStatus == KEY_2_SHORT)
  {

  }
  else
  {
    KeyStatus = KEY_IDLE;
  }
}


//-------------------------------------------------------------------
// FunctionName     CSR1010_Process
//-------------------------------------------------------------------
static void CSR1010_Process(void)
{
  static	_Uint8			TypeReplyTime;
	static 	_Flag       BtInitFlag;               //bluetooth intialization' flag
	static 	_Uint8			FlagBuffer 	= 0xFF;

	/* Initialize the CSR1010's broadcast name after 3 seconds*/
	if (BtInitFlag == FALSE)
	{
		//----------------------------------------------------------------------
		// if device haven't received command FD F0 FE within 1 second after power on,
		// send the type to CSR1010
		//-----------------------------------------------------------------------
		TypeReplyTime++;
		if (TypeReplyTime >= 150)
		{
			BtInitFlag 					= TRUE;
			SndData[1].SndStatus		= SND_TYPE;
		}
	}

	//-----------------------------------------------------------------------
	// if the device haven't received any command within 300ms,
	// clear the flagstatus
	//-----------------------------------------------------------------------
	if (FlagChkFlag)
	{
		FlagChkTime++;
		if (FlagChkTime >= 15)
		{
			FlagChkTime 	= 0;
			FlagBuffer 		= 0xFF;
			FlagChkFlag 	= FALSE;
		}
	}



	/* Check the received flag, when it is false, return */
	if (RcvFlag[1] == FALSE)		return;


	/* Received the command from CSR1010
	 * Clear the received flag
	 */
	RcvFlag[1] 			= FALSE;
	FlagChkFlag		= TRUE;
	FlagChkTime		= 0;
	BtRcvDataFlag	= TRUE;


	/* CSR1010 Initialize					*/
	if (BtInitFlag == FALSE)
	{
		if (RcvData[1].DataBuf[0] == 0xF0)
		{
      BtInitFlag = TRUE;
			SndData[1].SndStatus		= SND_TYPE;
			return;
		}
	}




}

//-------------------------------------------------------------------
// FunctionName     Wifi_Process
//-------------------------------------------------------------------
static void Wifi_Process(void)
{
  static _Uint8   FlagByte = 0x1;
  _Flag           FlagChgFlag = FALSE;
  UART_Cmd_T      CmdBuffer;
  _Uint8          LengthBuffer;
  _Uint8          InfoBuffer;
  _Flag           ErrFlag;

  if (RcvFlag[0] == FALSE)    return;
  RcvFlag[0] = FALSE;

  CmdBuffer     = RcvData[0].DataBuf[1];
  LengthBuffer  = RcvData[0].DataBuf[3];
  InfoBuffer    = RcvData[0].DataBuf[4];

  if (LengthBuffer > 0)
  {
    switch (CmdBuffer)
    {
      //About the wifi status
      case CMD_WIFI_STATUS:{
        if (InfoBuffer == 0x1){
          if (LedMode != LED_WIFI_STANDBY){
            LedMode   = LED_WIFI_STANDBY;
            LedInit   = TRUE;
          }
        }
        else if (InfoBuffer == 0x2){
          if (LedMode != LED_WIFI_DISCONNECT){
            LedMode   = LED_WIFI_DISCONNECT;
            LedInit   = TRUE;
          }
        }
        else if (InfoBuffer == 0x4){
          if (LedMode != LED_WIFI_CONNECTED){
            LedMode   = LED_WIFI_CONNECTED;
            LedInit   = TRUE;
          }
        }
      } break;

      //Setting specific color or theme
      case CMD_THEME_SET:{
        //Error check
        if (InfoBuffer > NORMAL_COLOR_MAX){
          ErrNum = ERR_COLOR_RANGE;
          break;
        }

        if (NormalMode > 0x8){
          NormalMode = 0x1;
        }

        //Change the color
        NormalColor = InfoBuffer;

        SndData[1].SndStatus  = SND_BROADCAST;
        SndData[1].DataBuf[0] = 0x3  | (FlagByte << 4);
        SndData[1].DataBuf[1] = 0x00;
        SndData[1].DataBuf[2] = 0xFF;
        SndData[1].DataBuf[3] = 0xFF;
        SndData[1].DataBuf[4] = 0x03  | (FlagByte << 4);
        SndData[1].DataBuf[5] = NormalMode;
        SndData[1].DataBuf[6] = NormalColor;
        SndData[1].DataBuf[7] = 0;
        SndData[1].DataBuf[8] = 0;
        SndData[1].DataBuf[9] = 0;

        FlagChgFlag = TRUE;
        FlashSaveFlag = TRUE;
        LedMode       = LED_NORMAL;
        LedInit       = TRUE;
      } break;



      //Setting specific mode
      case CMD_NORMAL_MODE:{
        //Error check
        if (InfoBuffer > NORMAL_MODE_MAX){
          ErrNum = ERR_MODE_RANGE;
          break;
        }

        //Setting mode
        NormalMode = InfoBuffer + 1;

        SndData[1].SndStatus  = SND_BROADCAST;
        SndData[1].DataBuf[0] = 0x3  | (FlagByte << 4);
        SndData[1].DataBuf[1] = 0x00;
        SndData[1].DataBuf[2] = 0xFF;
        SndData[1].DataBuf[3] = 0xFF;
        SndData[1].DataBuf[4] = 0x03  | (FlagByte << 4);
        SndData[1].DataBuf[5] = NormalMode;
        SndData[1].DataBuf[6] = NormalColor;
        SndData[1].DataBuf[7] = 0;
        SndData[1].DataBuf[8] = 0;
        SndData[1].DataBuf[9] = 0;

        FlagChgFlag = TRUE;
        FlashSaveFlag = TRUE;
        LedMode       = LED_NORMAL;
        LedInit       = TRUE;
      } break;


      //Show
      case CMD_SHOW_MODE:{
        //Error check
        if (InfoBuffer > SHOW_COLOR_MAX){
          ErrNum = ERR_SHOW_RANGE;
          break;
        }

        //Random one mode
        srand(RndSeed);
        ShowMode = ((_Uint8)rand()) % 3 + 1;

        //Setting show mode
        ShowColor = InfoBuffer;

        SndData[1].SndStatus  = SND_BROADCAST;
        SndData[1].DataBuf[0] = 0x3  | (FlagByte << 4);
        SndData[1].DataBuf[1] = 0x00;
        SndData[1].DataBuf[2] = 0xFF;
        SndData[1].DataBuf[3] = 0xFF;
        SndData[1].DataBuf[4] = 0x0A  | (FlagByte << 4);
        SndData[1].DataBuf[5] = ShowMode;
        SndData[1].DataBuf[6] = ShowColor;
        SndData[1].DataBuf[7] = 0;
        SndData[1].DataBuf[8] = 0;
        SndData[1].DataBuf[9] = 0;

        FlagChgFlag = TRUE;
        FlashSaveFlag = TRUE;
        LedMode       = LED_NORMAL;
        LedInit       = TRUE;
      } break;


      // Setting timer
      case CMD_TIMER_SET:{
        //Err check
//        if (InfoBuffer > 8 || (InfoBuffer % 2 == 1)){
//          ErrNum = ERR_TIMER_INVALID;
//          break;
//        }

        SndData[1].SndStatus  = SND_BROADCAST;
        SndData[1].DataBuf[0] = 0x3  | (FlagByte << 4);
        SndData[1].DataBuf[1] = 0x00;
        SndData[1].DataBuf[2] = 0xFF;
        SndData[1].DataBuf[3] = 0xFF;
        SndData[1].DataBuf[4] = 0x05 | (FlagByte << 4);
        SndData[1].DataBuf[5] = InfoBuffer;
        SndData[1].DataBuf[6] = 0x0;
        SndData[1].DataBuf[7] = 0;
        SndData[1].DataBuf[8] = 0;
        SndData[1].DataBuf[9] = 0;

        FlagChgFlag = TRUE;
        FlashSaveFlag = TRUE;
        LedMode       = LED_NORMAL;
        LedInit       = TRUE;
      } break;

      // Error
      default:
      {
        ErrFlag = TRUE;
      } break;
    }
  }

  else
  {
    // Turn Off
    if (CmdBuffer == CMD_SOCKET_OFF){
      SndData[1].SndStatus  = SND_BROADCAST;
      SndData[1].DataBuf[0] = 0x3  | (FlagByte << 4);
      SndData[1].DataBuf[1] = 0x00;
      SndData[1].DataBuf[2] = 0xFF;
      SndData[1].DataBuf[3] = 0xFF;
      SndData[1].DataBuf[4] = 0x03 | (FlagByte << 4);
      SndData[1].DataBuf[5] = 0x0;
      SndData[1].DataBuf[6] = 0x0;
      SndData[1].DataBuf[7] = 0;
      SndData[1].DataBuf[8] = 0;
      SndData[1].DataBuf[9] = 0;

      FlagChgFlag = TRUE;
      LedMode       = LED_NORMAL;
      LedInit       = TRUE;
    }

    // Turn On
    else if (CmdBuffer == CMD_SOCKET_ON){
      SndData[1].SndStatus  = SND_BROADCAST;
      SndData[1].DataBuf[0] = 0x3  | (FlagByte << 4);
      SndData[1].DataBuf[1] = 0x00;
      SndData[1].DataBuf[2] = 0xFF;
      SndData[1].DataBuf[3] = 0xFF;
      SndData[1].DataBuf[4] = 0x03 | (FlagByte << 4);
      SndData[1].DataBuf[5] = 0xFF;
      SndData[1].DataBuf[6] = 0x0;
      SndData[1].DataBuf[7] = 0;
      SndData[1].DataBuf[8] = 0;
      SndData[1].DataBuf[9] = 0;

      FlagChgFlag = TRUE;
      LedMode       = LED_NORMAL;
      LedInit       = TRUE;
    }

    // Error
    else
    {
      ErrNum = ERR_CMD_INVALID;
    }
  }


  // Error occur
  if (FlagChgFlag)
  {
    FlagByte++;
    if (FlagByte > 16)  FlagByte = 1;
  }
}
