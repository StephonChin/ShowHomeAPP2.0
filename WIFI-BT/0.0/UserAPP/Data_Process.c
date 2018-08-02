/********************************************************************
  *
  * FILE NAME      Data_Process.c
  *
*********************************************************************/
#include "Data_Process.h"


_Uint8    CurrentMode;
_Uint8    ProductMode;
_Uint8    ProductShowMode;
_Uint8    ProductColor;
_Uint8    ProductTheme;

_Uint8					FlagChkTime;
_Flag						FlagChkFlag;


/********************************************************************
  *
  * FunctionName    User_Data_Init
  *
*********************************************************************/
void User_Data_Init(void)
{
  ProductMode     = 0x1;
  ProductShowMode = 0x0;
  ProductTheme    = 0x0;
  ProductColor    = 0x0;
  CurrentMode     = 0x1;
}



/********************************************************************
  *
  * FunctionName    Data_Process
  *
*********************************************************************/
void Data_Process(void)
{
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
  
  CmdBuffer     = RcvData[0].DataBuf[2];
  LengthBuffer  = RcvData[0].DataBuf[4];
  InfoBuffer    = RcvData[0].DataBuf[5];
  
  if (LengthBuffer > 0)
  {
    switch (CmdBuffer)
    {
      // Change the theme or color to next one  |  Setting specific color or theme
      case CMD_THEME_SET:
      {
        if (InfoBuffer == 0)
        {
          if (CurrentMode <= 0xA)
          {
            ProductColor++;
            if (ProductColor > COLOR_MAX)
            {
              ProductColor = 0;
            }
            
            if (CurrentMode >= 0x9)   CurrentMode = 0x1;
            SndData[1].SndStatus  = SND_BROADCAST;
            SndData[1].DataBuf[0] = 0x23;
            SndData[1].DataBuf[1] = 0x00;
            SndData[1].DataBuf[2] = 0xFF;
            SndData[1].DataBuf[3] = 0xFF;
            SndData[1].DataBuf[4] = 0x03  | (FlagByte << 4);
            SndData[1].DataBuf[5] = CurrentMode;
            SndData[1].DataBuf[6] = ProductColor;
            SndData[1].DataBuf[7] = 0;
            SndData[1].DataBuf[8] = 0;
            SndData[1].DataBuf[9] = 0;
            
            FlagChgFlag = TRUE;
          }
          else
          {
            ProductTheme++;
            if (ProductTheme > SHOW_THEME_MAX)   ProductTheme = 1;
            SndData[1].SndStatus  = SND_BROADCAST;
            SndData[1].DataBuf[0] = 0x23;
            SndData[1].DataBuf[1] = 0x00;
            SndData[1].DataBuf[2] = 0xFF;
            SndData[1].DataBuf[3] = 0xFF;
            SndData[1].DataBuf[4] = 0x0A  | (FlagByte << 4);
            SndData[1].DataBuf[5] = CurrentMode;
            SndData[1].DataBuf[6] = ProductTheme;
            SndData[1].DataBuf[7] = 0;
            SndData[1].DataBuf[8] = 0;
            SndData[1].DataBuf[9] = 0;
            
            FlagChgFlag = TRUE;
          }
        }
        
        
        else
        {
          if (CurrentMode <= 0xA)
          {
            if (InfoBuffer <= (COLOR_MAX + 1))
            {
              ProductColor = InfoBuffer - 1;
              
              if (CurrentMode >= 0x9)   CurrentMode = 0x1;
              
              SndData[1].SndStatus  = SND_BROADCAST;
              SndData[1].DataBuf[0] = 0x23;
              SndData[1].DataBuf[1] = 0x00;
              SndData[1].DataBuf[2] = 0xFF;
              SndData[1].DataBuf[3] = 0xFF;
              SndData[1].DataBuf[4] = 0x03  | (FlagByte << 4);
              SndData[1].DataBuf[5] = CurrentMode;
              SndData[1].DataBuf[6] = ProductColor;
              SndData[1].DataBuf[7] = 0;
              SndData[1].DataBuf[8] = 0;
              SndData[1].DataBuf[9] = 0;
              
              FlagChgFlag = TRUE;
            }
            else
            {
              ErrFlag = TRUE;
            }
          }
          else
          {
            if (InfoBuffer <= SHOW_THEME_MAX && InfoBuffer >= SHOW_THEME_MIN)
            {
              ProductTheme = InfoBuffer;
              SndData[1].SndStatus  = SND_BROADCAST;
              SndData[1].DataBuf[0] = 0x23;
              SndData[1].DataBuf[1] = 0x00;
              SndData[1].DataBuf[2] = 0xFF;
              SndData[1].DataBuf[3] = 0xFF;
              SndData[1].DataBuf[4] = 0x0A  | (FlagByte << 4);
              SndData[1].DataBuf[5] = CurrentMode - 0xA;
              SndData[1].DataBuf[6] = ProductTheme - 0x15;
              SndData[1].DataBuf[7] = 0;
              SndData[1].DataBuf[8] = 0;
              SndData[1].DataBuf[9] = 0;
              
              FlagChgFlag = TRUE;
            }
            else
            {
              ErrFlag = TRUE;
            }
          }
        }
      } break;
      
      
       // Change the mode to next one  |  Setting specific mode
      case CMD_MODE_CHG:
      {
        if (InfoBuffer == 0)
        {
          ProductMode++;
          if (ProductMode > MODE_MAX)   ProductMode = 0x1;
          CurrentMode = ProductMode;
          SndData[1].SndStatus  = SND_BROADCAST;
          SndData[1].DataBuf[0] = 0x23;
          SndData[1].DataBuf[1] = 0x00;
          SndData[1].DataBuf[2] = 0xFF;
          SndData[1].DataBuf[3] = 0xFF;
          SndData[1].DataBuf[4] = 0x03 | (FlagByte << 4);
          SndData[1].DataBuf[5] = ProductMode;
          SndData[1].DataBuf[6] = ProductColor;
          SndData[1].DataBuf[7] = 0;
          SndData[1].DataBuf[8] = 0;
          SndData[1].DataBuf[9] = 0;
          
          FlagChgFlag = TRUE;
        }
        
        else if (InfoBuffer <= MODE_MAX)
        {
          ProductMode = InfoBuffer;
          CurrentMode = ProductMode;
          SndData[1].SndStatus  = SND_BROADCAST;
          SndData[1].DataBuf[0] = 0x23;
          SndData[1].DataBuf[1] = 0x00;
          SndData[1].DataBuf[2] = 0xFF;
          SndData[1].DataBuf[3] = 0xFF;
          SndData[1].DataBuf[4] = 0x03 | (FlagByte << 4);
          SndData[1].DataBuf[5] = ProductMode;
          SndData[1].DataBuf[6] = ProductColor;
          SndData[1].DataBuf[7] = 0;
          SndData[1].DataBuf[8] = 0;
          SndData[1].DataBuf[9] = 0;
          
          FlagChgFlag = TRUE;
        }
        else
        {
          ErrFlag = TRUE;
        }
        
      } break;
      
       // Change the show mode to next one  |  Setting specific show mode
      case CMD_SHOW_MODE:
      {
        if (InfoBuffer == 0)
        {
          ProductShowMode++;
          if (ProductShowMode > SHOW_MODE_MAX)   ProductShowMode = 0x0;
          CurrentMode = ProductMode + 0xA;
          SndData[1].SndStatus  = SND_BROADCAST;
          SndData[1].DataBuf[0] = 0x23;
          SndData[1].DataBuf[1] = 0x00;
          SndData[1].DataBuf[2] = 0xFF;
          SndData[1].DataBuf[3] = 0xFF;
          SndData[1].DataBuf[4] = 0x0A | (FlagByte << 4);
          SndData[1].DataBuf[5] = ProductShowMode;
          SndData[1].DataBuf[6] = ProductTheme;
          SndData[1].DataBuf[7] = 0;
          SndData[1].DataBuf[8] = 0;
          SndData[1].DataBuf[9] = 0;
          
          FlagChgFlag = TRUE;
        }
        
        else if (InfoBuffer <= SHOW_MODE_MAX)
        {
          ProductShowMode = InfoBuffer;
          CurrentMode = ProductMode + 0xA;
          SndData[1].SndStatus  = SND_BROADCAST;
          SndData[1].DataBuf[0] = 0x23;
          SndData[1].DataBuf[1] = 0x00;
          SndData[1].DataBuf[2] = 0xFF;
          SndData[1].DataBuf[3] = 0xFF;
          SndData[1].DataBuf[4] = 0x0A | (FlagByte << 4);
          SndData[1].DataBuf[5] = ProductShowMode;
          SndData[1].DataBuf[6] = ProductTheme;
          SndData[1].DataBuf[7] = 0;
          SndData[1].DataBuf[8] = 0;
          SndData[1].DataBuf[9] = 0;
          
          FlagChgFlag = TRUE;
        }
        else
        {
          ErrFlag = TRUE;
        }
      } break;
      
      // Setting timer
      case CMD_TIMER_SET:
      {
        if ((InfoBuffer < 10) && ((InfoBuffer % 2) == 1))
        {
          SndData[1].SndStatus  = SND_BROADCAST;
          SndData[1].DataBuf[0] = 0x23;
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
        }
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
    if (CmdBuffer == CMD_SOCKET_OFF)
    {
      SndData[1].SndStatus  = SND_BROADCAST;
      SndData[1].DataBuf[0] = 0x23;
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
    }
    
    // Turn On
    else if (CmdBuffer == CMD_SOCKET_ON)
    {
      SndData[1].SndStatus  = SND_BROADCAST;
      SndData[1].DataBuf[0] = 0x23;
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
    }
    
    // Error
    else
    {
      ErrFlag = TRUE;
    }
  }
  
  
  // Error occur
  if (ErrFlag)
  {
    
  }
  
  if (FlagChgFlag)
  {
    FlagByte++;
    if (FlagByte > 16)  FlagByte = 1;
  }
}


