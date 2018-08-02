/*******************************************************************************
	*
	* FILE NAME
	*						Data_Process.c
	*
	* NODE
	*						About horse run mode
	*							if the mode is run mode, ripple mode, flower bloom mode, polar light mode, color show mode,
	*							only AL91 or AL94 have horse function.
	*
	*							if the mode is show1, show2, or show3
	*							all the product have horse function.
	*
*******************************************************************************/
#include "Data_Process.h"

//----------------------------------------------------------------------------
// Gloable Parameters
//----------------------------------------------------------------------------
idata _Uint8					ChkSumH;
idata _Uint8					ChkSumL;
idata _Uint8					ChkSumRst;
idata _Uint8					ChkSumRstSave;
idata _Uint8					PowerOnNum;




//----------------------------------------------------------------------------
// File Parameters
//----------------------------------------------------------------------------
idata _Uint8					NewChkSumH;
idata _Uint8					NewChkSumL;
idata _Uint8					ChkSumRstTime;
idata _Flag					    PasswordFlag;						//Allow set the password flag
idata _Flag					    SynRcvFlag;
idata _Uint8					FlagChkTime;
idata _Flag					    FlagChkFlag;

idata _Uint8	                NtcBanTime[2];
idata _Flag		                NtcBanFlag;
idata _Flag		                NtcBanInit;






/******************************************************************************
	*
	* COLOR_TABLE
	*
	* DESCRIPTION
	*								Color value combine with R value, G value and B value,
	*								or  with R value, G value , B value and W value
	*
*******************************************************************************/
const _Uint8 COLOR_VECTOR[8][3] =
{
	100,		0,			0,
    100,		0,			0,      			//1:red
    0,			100,		0,      			//2:green 
	100,		100,		0,     				//3:r g
    0,			0,			100,     			//4:blue
    100,		0,			100,   				//5:r b
    0,			100,		100,     			//6:g b
    100,		100,		100    				//7:r g b
};



/************************************************************************************
	*
	* FUNCTION NAME		|	User_Data_Init
	* INPUT			    |	None
	* OUTPUT			|	None
	* BRIEF				|	Initialize the user data after power on, include display
	*						mode, color theme, time count down hour and others
	*
*************************************************************************************/
void User_Data_Init(void)
{
	//-----------------------------------------------------------------
	// if the first time to power on
	//-----------------------------------------------------------------
    PowerOnNum = Byte_Read_From_APROM(APROM_POWER_ON_NUM);
	if (PowerOnNum != 0xAA)
	{
		DisplayData.ModeBuf 		= 0x1;
		DisplayData.ColorValue		= 0x7;
		TimerData.CntDwnHour		= 0x6;
        MotorData.ModeBuf           = 0x1;
		ChkSumH						= 0;
		ChkSumL						= 0;
		ChkSumReply[0] 				= '0';
		ChkSumReply[1] 				= '0';
		ChkSumReply[2] 				= '0';
		ChkSumReply[3] 				= '0';
		ChkSumRst					= 0;
		PowerOnNum					= 0xAA;
		ChkSumRstSave				= 0;
		FlashSaveFlag				= TRUE;
		
		DisplayData.Mode 			= 0x1;
		DisplayData.InitFlag		= TRUE;
        MotorData.Mode              = 0x1;
        MotorData.InitFlag          = TRUE;
        TimerData.InitFlag	        = TRUE;
		Color_Value_Get(DisplayData.ColorValue);
		return;
	}
	
	//-----------------------------------------------------------------
	// Get the mode from eprom after power on
	// When display mode equl 0 (means turn off all leds, then set
	// the mode to 0xA (color show), and save it to eprom
	//-----------------------------------------------------------------
    DisplayData.ModeBuf = Byte_Read_From_APROM(APROM_MODE);
	if (DisplayData.ModeBuf == 0 || (DisplayData.ModeBuf > 0x3 && DisplayData.ModeBuf < 0xB) || DisplayData.ModeBuf > 0xD)
	{
		DisplayData.ModeBuf 	= 0x1;
		FlashSaveFlag			= TRUE;
	}
	DisplayData.Mode			= DisplayData.ModeBuf;
	DisplayData.InitFlag		= TRUE;
	
	
	//---------------------------------------------------------------------
	// Get the color value from eprom after power on
	// When the color value is more than the COLOR_MAX, set it to COLOR_MAX
	// and save the value to eprom 
	//----------------------------------------------------------------------
    DisplayData.ColorValue  = Byte_Read_From_APROM(APROM_COLOR);
	if (DisplayData.ColorValue > COLOR_MAX)
	{
		DisplayData.ColorValue 	= COLOR_MAX;
		FlashSaveFlag			= TRUE;
	}
	Color_Value_Get(DisplayData.ColorValue);
	
	
	//----------------------------------------------------------------------
	// Get the count down hour from eprom after power on,
	// if valid value is more than 8 , seit it to 6,
	// and save6 to eprom
	// Set the OnOffFlag
	//----------------------------------------------------------------------
    TimerData.CntDwnHour = Byte_Read_From_APROM(APROM_CNTDWN_HOUR);
	if (TimerData.CntDwnHour > 8 || (TimerData.CntDwnHour % 2 == 1))
	{
		TimerData.CntDwnHour	= 6;
		FlashSaveFlag			= TRUE;
	}
	TimerData.InitFlag	= TRUE;
	TimerData.OnOffFlag = TRUE;
	
	
	
    
    //-------------------------------------------------------------------------
	// Get the motor value from eprom
    //-------------------------------------------------------------------------
	MotorData.ModeBuf	= Byte_Read_From_APROM(APROM_MOTOR);
	if (MotorData.ModeBuf > 2)
	{
		MotorData.ModeBuf   = 1;
		FlashSaveFlag	    = TRUE;
	}
	MotorData.Mode 			= MotorData.ModeBuf;
	MotorData.InitFlag		= TRUE;
	

		
		
    //----------------------------------------------------------------------
    // Check the count
    // if power on 3 times in 5 seconds, reset the checksum
    // 1 -> write 0x55
    // 2 -> write 0xAA
    // 3 -> Reset
    //----------------------------------------------------------------------
    ChkSumRst   = Byte_Read_From_APROM(APROM_CHK_RST_CNT);
    ChkSumH     = Byte_Read_From_APROM(APROM_CHKSUM_H);
    ChkSumL     = Byte_Read_From_APROM(APROM_CHKSUM_L);
    if (ChkSumRst == 0)
    {
        ChkSumRstSave 		= 0x55;
        FlashSaveFlag		= TRUE;
    }
    else if (ChkSumRst == 0x55)
    {
        ChkSumRstSave 		= 0xAA;
        FlashSaveFlag		= TRUE;
    }
    else if (ChkSumRst == 0xAA)
    {
        ChkSumH 			= 0;
        ChkSumL 			= 0;
        ChkSumRstSave = 0;
        ChkSumRst			= 0;
        FlashSaveFlag = TRUE;
        
        DisplayData.Mode 	    = 0xFD;
        DisplayData.InitFlag 	= TRUE;
    }
    
    ChkSumReply[0] = Hex_To_Char(ChkSumH >> 4);
    ChkSumReply[1] = Hex_To_Char(ChkSumH & 0x0F);
    ChkSumReply[2] = Hex_To_Char(ChkSumL >> 4);
    ChkSumReply[3] = Hex_To_Char(ChkSumL & 0x0F);	
}



/*************************************************************************************
	*
	* FUNCTION NAME		|	Data_Process
	* INPUT						|	None
	* OUTPUT					|	None
	* DESCRIPTION			|	Process all the data here. change the mode , color, timer or
	*										other parameters after received valid data from CSR1010
	*
***************************************************************************************/
void Data_Process(void)
{
	/* Key Process */
	Key_Process();
    
    /* Detect the temperature */
    Tmprtr_Process();
	
	/* Timer Process */
	Count_Down_Process();
	
	/* Password Process */
	Password_Process();
	
	/* Synchronize Process */
	Syn_Process();
	
	/* CSR1010 Process */
	CSR1010_Process();
}

/************************************************************
	*
	* @FunctonName	Key_Process
	* @Brief		Process the key
	* 				Change the color and mode after short key
	*/
static void Key_Process(void)
{
	//------------------------------------------------------
	// When key status is idle, return
	//------------------------------------------------------
	if (KeyStatus == KEY_IDLE)		return;

	
	//-------------------------------------------------------
	// Short Press
	//-------------------------------------------------------
	if (KeyStatus == KEY_SHORT)
	{
		//Temperature Ban
		NtcBanFlag = TRUE;
		NtcBanInit = TRUE;
		
		//clear the status
		KeyStatus = KEY_IDLE;
		
		//set data intialize flag
		DisplayData.InitFlag	= TRUE;
		
		// power on
		if (DisplayData.Mode == 0)
		{
			DisplayData.Mode		= DisplayData.ModeBuf;
			MotorData.Mode			= MotorData.ModeBuf;
			MotorData.InitFlag	    = TRUE;
			
			if (DisplayData.ColorValue == 0x0 || DisplayData.ColorValue > 0x7)
			{
				DisplayData.ColorValue  = 0x7;
				FlashSaveFlag           = TRUE;
			}
			Color_Value_Get(DisplayData.ColorValue);	
		}
		
		
        else if (DisplayData.Mode > 0xA)
        {
            DisplayData.ModeBuf++;
            DisplayData.Mode = DisplayData.ModeBuf;
            if (DisplayData.ModeBuf > 0xD)
            {
                DisplayData.Mode            = 0;
                MotorData.Mode              = 0;
                MotorData.InitFlag          = TRUE;
                DisplayData.ModeBuf         = 1;
                DisplayData.ColorValue      = 1;
            }
            FlashSaveFlag                   = TRUE;
        }
        
        // change thecolor
		else
		{	
			// change color
            DisplayData.ModeBuf = 1;
			DisplayData.ColorValue++;
			if (DisplayData.ColorValue > COLOR_MAX)
			{
				DisplayData.ColorValue = 0x1;
				DisplayData.ModeBuf = 0xB;
			}
            DisplayData.Mode    = DisplayData.ModeBuf;
			FlashSaveFlag       = TRUE;
		}
        
		Color_Value_Get(DisplayData.ColorValue);
	}
	
	//long press to power off
	else
	if (KeyStatus == KEY_LONG)
	{
		KeyStatus	= KEY_IDLE;
		if (DisplayData.Mode != 0)
		{
			DisplayData.Mode 		= 0;
			DisplayData.InitFlag	= TRUE;
			MotorData.Mode			= 0;
			MotorData.InitFlag		= TRUE;
		}
	}
}



/**********************************************************************************
	*
	* FUNCTIONNAME			| Tmprtr_Process
	*	INPUT							| None
	* OUTPUT						| None
	* DESCRIPTION				| Detect the environment temperature
************************************************************************************/
static void Tmprtr_Process(void)
{
	//-------------------------------------------------------
	// The Temperature is less than 55
	//-------------------------------------------------------
	if (NtcStatus == NTC_IDLE || NtcStatus == NTC_HOT)
	{
		NtcBanTime[0] = 0;
		NtcBanTime[1] = 0;
		NtcBanFlag	  = FALSE;
		return;
	}
	
	//-------------------------------------------------------
	// The Temperature is greater than 55 
	//-------------------------------------------------------
	if (NtcStatus == NTC_BAN)
	{
		if (NtcBanFlag == TRUE)
		{
			if (NtcBanInit == TRUE)
			{
				NtcBanInit = FALSE;
				NtcBanTime[0] = 0;
				NtcBanTime[1] = 0;
			}
			
			NtcBanTime[0]++;
			if (NtcBanTime[0] >= 50) //1s
			{
				NtcBanTime[0] = 0;
				NtcBanTime[1]++;
				if (NtcBanTime[1] >= 20) //20s
				{
					NtcBanTime[1] = 0;
					NtcBanFlag = FALSE;
				}
			}
		}
		
		//-----------------------------------------------------
		// after 20 seconds, turn off the LED & Motor
		//-----------------------------------------------------
		else
		{
			DisplayData.Mode 		= 0;
			DisplayData.InitFlag 	= TRUE;
			MotorData.Mode 			= 0;
			MotorData.InitFlag 		= TRUE;
		}
	}
	
	//------------------------------------------------------
	// When Temperature is less than 50 after 1h
	//------------------------------------------------------
	if (NtcStatus == NTC_BAN_EXIT)
	{
		NtcStatus = NTC_IDLE;
		//restore the Led & Motor work mode
		if (TimerData.OnOffFlag == TRUE)
		{
			DisplayData.Mode		= DisplayData.ModeBuf;
			DisplayData.InitFlag	= TRUE;
			MotorData.Mode			= MotorData.ModeBuf;
			MotorData.InitFlag		= TRUE;
		}
	}
}




/************************************************************
	*
	* @FunctonName	Password_Process
	*
*****/
static void Password_Process(void)
{
	static	_Uint8			PasswordTime;	
	
	// Reset checksum time caculate
	if (ChkSumRst != 0)
	{
		ChkSumRstTime++;
		if (ChkSumRstTime >= 250)
		{
			ChkSumRstTime = 0;
			ChkSumRst 		= 0;
			ChkSumRstSave	= 0;
			FlashSaveFlag = TRUE;
		}
	}
	
	
	//----------------------------------------------------------------------------------------
	// About Password Set
	//
	// * When received the single that allow set the password, then caculate 5 seconds
	//   if haven't received any password, reset the allow flag
	//-----------------------------------------------------------------------------------------
	if (PasswordFlag)
	{
		PasswordTime++;
		if (PasswordTime >= 250)				PasswordFlag = FALSE;
	}
	else
	{
		PasswordTime = 0;
	}
}


/****************************************************************************
 *
 * @FunctonName	Syn_Process
 * if SynRcvFlag is TRUE(when received synchronize single),
   the next 3 seconds do not allowed to receive the same command
 
 * if the flag of synchronization is true, send data mode + serias + checksum

 * SynData[2] used for horse mode under AL91 or AL94
 *
******************************************************************************/
static void Syn_Process(void)
{
		static	_Uint8			SynRcvTime	= 0;
	
	//-------------------------------------------------------------------------------------
	// About synchronizing single
	//
	
	//--------------------------------------------------------------------------------------
	if (SynRcvFlag == TRUE)
	{
		SynRcvTime++;
		if (SynRcvTime > 150)
		{
			SynRcvTime = 0;
			SynRcvFlag = FALSE;
		}
	}
	else
	{
		SynRcvTime = 0;
	}
}



/************************************************************
	*
	* @FunctonName	Count_Down_Process
	*
*****/
static void Count_Down_Process(void)
{
	/* When TimerData.Status equals TIM_IDLE, exit this function */
	if (TimerData.Status == TIM_IDLE)	return;
	
	/* Open */
	if (TimerData.Status == TIM_OPEN)	
	{
		TimerData.Status		= TIM_IDLE;
		DisplayData.Mode		= DisplayData.ModeBuf;
		DisplayData.InitFlag	= TRUE;
        
        MotorData.Mode          = MotorData.ModeBuf;
        MotorData.InitFlag      = TRUE;
		return;
	}
	
	/* Close */
	if (TimerData.Status == TIM_CLOSE)
	{
		TimerData.Status	    = TIM_IDLE;
		DisplayData.Mode		= 0x0;
		DisplayData.InitFlag	= TRUE;
        
        MotorData.Mode          = 0;
        MotorData.InitFlag      = TRUE;
		return;
	}
}


/****************************************************************************************
	*
	* FUNCTIONNAME		| CSR1010_Process
	* INPUT			    | None
	* OUTPUT			| None
	* DESCRIPTION		| Send data to or received data from CSR1010
	*
*****************************************************************************************/
static void CSR1010_Process(void)
{
	static	_Uint8		TypeReplyTime;
	static 	_Flag       BtInitFlag;         //bluetooth intialization' flag
	static 	_Uint8		FlagBuffer 	= 0xFF;
			_Uint16		ChkSumBuf = 0;
		
	
	//----------------------------------------------------------------------
	// if device haven't received command FD F0 FE within 1 second after power on,
	// send the type to CSR1010
	//-----------------------------------------------------------------------
	if (BtInitFlag == FALSE)
	{
		TypeReplyTime++;
		if (TypeReplyTime >= 50)
		{
			BtInitFlag 			= TRUE;              
			SndData.SndStatus	= SND_TYPE;
			SndData.DataBuf[0]	= 0x01;
			SndData.DataBuf[1]	= DEVICE_NAME_ONE;
			SndData.DataBuf[2]	= DEVICE_NAME_TWO;
			SndData.DataBuf[3]	= DEVICE_NUM;
			SndData.DataBuf[4]  = MotorData.Mode;
			SndData.DataBuf[5]  = DisplayData.ColorValue;
			SndData.DataBuf[6]	= ChkSumH;
			SndData.DataBuf[7]	= ChkSumL;
		}
	}
	
	
	
	//-----------------------------------------------------------------------
	// if device haven't received any command within 500ms,
	// clear the flagstatus
	//-----------------------------------------------------------------------
	if (FlagChkFlag)
	{
		FlagChkTime++;
		if (FlagChkTime >= 25)
		{
			FlagChkTime 	= 0;
			FlagBuffer 		= 0xFF;
			FlagChkFlag 	= FALSE;
		}
	}
	

	
	/* Check the received flag, when it is false, return */
	if (RcvFlag == FALSE)		return;
	
	
	/* Received the command from CSR1010
	 * Clear the received flag 				
	 */
	RcvFlag 			= FALSE;
	FlagChkFlag		= TRUE;
	FlagChkTime		= 0;
	
	
	/* CSR1010 Initialize					*/
	if (BtInitFlag == FALSE)
	{
		if (RcvData.DataBuf[0] == 0xF0)
		{
			BtInitFlag 			= TRUE;              
			SndData.SndStatus	= SND_TYPE;
			SndData.DataBuf[0]	= 0x01;
			SndData.DataBuf[1]	= DEVICE_NAME_ONE;
			SndData.DataBuf[2]	= DEVICE_NAME_TWO;
			SndData.DataBuf[3]	= DEVICE_NUM;
			SndData.DataBuf[4]  = MotorData.Mode;
			SndData.DataBuf[5]  = DisplayData.ColorValue;
			SndData.DataBuf[6]	= ChkSumH;
			SndData.DataBuf[7]	= ChkSumL;
			return;
		}
	}
	

	/* CheckSum 									
	 * if the command is not 0x7(set the password),
	 * check the password if checksum isn't default value 0x0000
	 */
	if ((RcvData.DataBuf[0]& 0x0F) != 0x7)
	{
		if ((RcvData.DataBuf[4] != ChkSumH) || (RcvData.DataBuf[5] != ChkSumL))
		{
			return;
		}
	}
	
	/* Normal Command 															*/
	/* Check the Flag                               */
	/* If the command is not synchronize single			*/
	if (RcvData.DataBuf[0] != 0x0F)			
	{
		if (FlagBuffer == (RcvData.DataBuf[0] >> 4))		return;
		FlagBuffer = RcvData.DataBuf[0] >> 4;
	}
	
	
	/* Received command															*
	 * FD xE 00 00 00 00 00 FE											*
	 * FD x3 MODE COLOR SPEED 00 00 FE              *
	 * FD x4 HOUR 00 00 00 00                       */
	switch (RcvData.DataBuf[0] & 0x0F)
	{
		/* FD x1 00 00 00 00 00 FE 				*/
		/* FD x2 00 00 00 00 00 FE				*/
		/* Seach Command									*/
		case 0x1:
		case 0x2:
		{
			SndData.SndStatus	= SND_NORMAL;
			SndData.DataBuf[0]	= 0x01;
			SndData.DataBuf[1]	= DEVICE_NAME_ONE;
			SndData.DataBuf[2]	= DEVICE_NAME_TWO;
			SndData.DataBuf[3]	= DEVICE_NUM;
			SndData.DataBuf[4]  = MotorData.Mode;
			SndData.DataBuf[5]  = DisplayData.ColorValue;
			SndData.DataBuf[6]	= ChkSumH;
			SndData.DataBuf[7]	= ChkSumL;
		} break;
		
		
		 
		/* FD x3 MODE COLOR 00 00 00 FE 	*/
		/* Set the mode, color 				*/
		case 0x3:
		{
			// Err check
			// DisplayData.Mode 		= 0x0~0xA || 0xFF
			// ColorNum		= 0x0 ~ 0x1C
			if ((RcvData.DataBuf[1] > 0x3) && (RcvData.DataBuf[1] != 0xFF))		break;
			if (RcvData.DataBuf[2] > 0x7)										break;
			 
			// Get the mode value
			DisplayData.Mode			= RcvData.DataBuf[1];
			DisplayData.InitFlag 		= TRUE;
			switch (DisplayData.Mode)
			{
				case 0x0:	
				{
                    MotorData.Mode          = 0x0;
                    MotorData.InitFlag      = TRUE;
				}
				break;
				
				case 0xFF:			
				{
					DisplayData.Mode 		= DisplayData.ModeBuf;
                    MotorData.Mode          = MotorData.ModeBuf;
                    MotorData.InitFlag      = TRUE;
				} break;
				
				default:			
				{
					// Get the color
					DisplayData.ColorValue 		= RcvData.DataBuf[2];
					Color_Value_Get(DisplayData.ColorValue);
					 
					// Save
					DisplayData.ModeBuf 		= DisplayData.Mode;	
					FlashSaveFlag				= TRUE;
					
				} break;
			}
		} break;
        
        //----------------------------------------------------------------------------
		// FD x4 MOTOR 00 00 00 00 FE
		// Set the motor speed
		case 0x4:
		{
			MotorData.ModeBuf 	= RcvData.DataBuf[1];
			if (MotorData.ModeBuf > 0x2)		
            {
                MotorData.ModeBuf = 2;
            }
			MotorData.Mode		= MotorData.ModeBuf;
			MotorData.InitFlag	= TRUE;
			FlashSaveFlag       = TRUE;
		} break;
		
		
		 
		//---------------------------------------------------------------------------
		// FD x5 HOUR 00 00 00 00 FE      
		// Set the timer                   
		//---------------------------------------------------------------------------
		case 0x5:
		{
			if (RcvData.DataBuf[2] > 8 || (RcvData.DataBuf[2] % 2 == 1))			break;
			TimerData.CntDwnHour		= RcvData.DataBuf[2];
			TimerData.InitFlag			= TRUE;
			FlashSaveFlag				= TRUE;
			
			DisplayData.Mode			= 0xFB;
			DisplayData.InitFlag	    = TRUE;
		} break;
		
		//---------------------------------------------------------------------------
		// FD xA MODE COLOR 00 00 00 FE 	
		// Set the show mode, color 		
		//---------------------------------------------------------------------------
		case 0xA:
		{
			// Err check
			// DisplayData.Mode 		= 0x0~0xA || 0xFF
			// ColorNum		= 0x0 ~ 0x1C
			if ((RcvData.DataBuf[1] > 0x3) || (RcvData.DataBuf[1] == 0x0))		break;
			if (RcvData.DataBuf[2] > 0x8)																			break;
			 
			// Get the mode value
			DisplayData.Mode			= RcvData.DataBuf[1] + 0xA;
			DisplayData.ModeBuf			= DisplayData.Mode;
			DisplayData.InitFlag 		= TRUE;
			 
			// Get the color
			DisplayData.ColorValue 		= 0x7;
			Color_Value_Get(DisplayData.ColorValue);
			
			FlashSaveFlag				= TRUE;
		} break;
		
		
		
		
		//---------------------------------------------------------------------------
		// process the synchronizaton data 
		// if the device's mode or theme isn't as same as received data
		// Change the device's mode or color
		//---------------------------------------------------------------------------
		case 0xF:
		{
			if (RcvData.DataBuf[1] > 0xA && DisplayData.Mode != 0)
			{
				if (DisplayData.Mode != RcvData.DataBuf[1])
				{
					DisplayData.Mode 		= RcvData.DataBuf[1];
					DisplayData.ModeBuf 	= RcvData.DataBuf[1];
					DisplayData.InitFlag 	= TRUE;
					FlashSaveFlag			= TRUE;
                    DisplayData.ColorValue  = 0x7;
					Color_Value_Get(0x7);
				}
			}
		} break;
		
			
		/*
		 * Password Set
		 * Test -  x8 01 CRCH CRCL 00 00  --- BLUE Flash
		 * Set Confirm - x8 02 CRCH CRCL 00 00, return x8 02 CRCH CRCL 
		 * Set Password - x7 ID1 ID2 ID3 ID4 CHK
		 * Successfully - GREEN FLASH
		 */
		case 0x7:
		{
			if (PasswordFlag == TRUE)
			{
				PasswordFlag = FALSE;
				if ((RcvData.DataBuf[1] ^ RcvData.DataBuf[2] ^ RcvData.DataBuf[3] ^ RcvData.DataBuf[4]) != RcvData.DataBuf[5])		// Password is wrong
				{
					DisplayData.Mode = 0xFF;
					DisplayData.InitFlag = TRUE;
					SndData.SndStatus 	= SND_NORMAL;
					SndData.DataBuf[0]	= 0x8;
					SndData.DataBuf[1]	= 0x4;
					SndData.DataBuf[2]	= 0;
					SndData.DataBuf[3]	= 0;
					SndData.DataBuf[4]	= NewChkSumH;
					SndData.DataBuf[5]	= NewChkSumL;
					SndData.DataBuf[6]	= ChkSumH;
					SndData.DataBuf[7]	= ChkSumL;
					break;
				}
				
				ChkSumBuf = CRC16_Cal(&RcvData.DataBuf[1]);
				if (ChkSumBuf != (_Uint16)(((_Uint16)NewChkSumH << 8) + (_Uint16)NewChkSumL))
				{
					DisplayData.Mode = 0xFF;
					DisplayData.InitFlag = TRUE;				//ID1 ID2 ID3 ID4 CRC16-CCITT-FALSE  isn't equal the new checksum
					SndData.SndStatus 	= SND_NORMAL;
					SndData.DataBuf[0]	= 0x8;
					SndData.DataBuf[1]	= 0x4;
					SndData.DataBuf[2]	= 0;
					SndData.DataBuf[3]	= 0;
					SndData.DataBuf[4]	= NewChkSumH;
					SndData.DataBuf[5]	= NewChkSumL;
					SndData.DataBuf[6]	= ChkSumH;
					SndData.DataBuf[7]	= ChkSumL;
                    break;
				}
				
				// Set the pass word
				ChkSumReply[0] 		= Hex_To_Char(NewChkSumH >> 4);
				ChkSumReply[1] 		= Hex_To_Char(NewChkSumH & 0x0F);
				ChkSumReply[2] 		= Hex_To_Char(NewChkSumL >> 4);
				ChkSumReply[3] 		= Hex_To_Char(NewChkSumL & 0x0F);
				SndData.SndStatus 	= SND_TYPE;								// First send FC 'L' 'B' 'NUM' FE to change the broadcast name, then reply the APP
				SndData.DataBuf[0]	= 0x8;
				SndData.DataBuf[1]	= 0x3;
				SndData.DataBuf[2]	= 0;
				SndData.DataBuf[3]	= 0;
				SndData.DataBuf[4]	= NewChkSumH;
				SndData.DataBuf[5]	= NewChkSumL;
				SndData.DataBuf[6]	= ChkSumH;
				SndData.DataBuf[7]	= ChkSumL;
				ChkSumH 			= NewChkSumH;
				ChkSumL 			= NewChkSumL;
				NewChkSumH 			= 0;
				NewChkSumL 			= 0;
				
				DisplayData.Mode 	    = 0xFD;
				DisplayData.InitFlag 	= TRUE;
				FlashSaveFlag			= TRUE;
			}
			
			// time out
			else
			{
				SndData.SndStatus 	= SND_NORMAL;
				SndData.DataBuf[0]	= 0x8;
				SndData.DataBuf[1]	= 0x4;
				SndData.DataBuf[2]	= 0;
				SndData.DataBuf[3]	= 0;
				SndData.DataBuf[4]	= NewChkSumH;
				SndData.DataBuf[5]	= NewChkSumL;
				SndData.DataBuf[6]	= ChkSumH;
				SndData.DataBuf[7]	= ChkSumL;
			}
		} break;
		
		case 0x8:
		{
			if (RcvData.DataBuf[1] == 0x1)
			{
				DisplayData.Mode 		= 0xFB;
				DisplayData.InitFlag 	= TRUE;
			}
			else if (RcvData.DataBuf[1] == 0x2)
			{
				PasswordFlag = TRUE;								// Allow set the password within 5 seconds
				
				NewChkSumH = RcvData.DataBuf[2];
				NewChkSumL = RcvData.DataBuf[3];
				SndData.SndStatus 	= SND_NORMAL;
				SndData.DataBuf[0]	= RcvData.DataBuf[0];
				SndData.DataBuf[1]	= 0x2;
				SndData.DataBuf[2]	= 0;
				SndData.DataBuf[3]	= 0;
				SndData.DataBuf[4]	= NewChkSumH;
				SndData.DataBuf[5]	= NewChkSumL;
				SndData.DataBuf[6]	= ChkSumH;
				SndData.DataBuf[7]	= ChkSumL;
			}
		} break;
		
		
		/*
		 * TEST command 1,2...
		 * xD 00 00 00 00 00
		 * xD 01 00 00 00 00
		 * Reply the equipment type and HSE status, version number...
		 */
		case 0xD:
		{
			if (RcvData.DataBuf[1] == 0x0)
			{
				SndData.SndStatus 	= SND_NORMAL;
				SndData.DataBuf[0]	= 0xD;
				SndData.DataBuf[1] 	= DEVICE_NAME_ONE;
				SndData.DataBuf[2] 	= DEVICE_NAME_TWO;
				SndData.DataBuf[3] 	= DEVICE_NUM;
				SndData.DataBuf[4] 	= 0;			
				SndData.DataBuf[5]	= TimerData.CntDwnHour;
				SndData.DataBuf[6]	= ChkSumH;
				SndData.DataBuf[7]	= ChkSumL;
				break;
			}
			
			if (RcvData.DataBuf[1] == 0x1)
			{
				SndData.SndStatus 	= SND_NORMAL;
				SndData.DataBuf[0]	= 0xD;
				SndData.DataBuf[1] 	= HseStatus;							// HSE status
				SndData.DataBuf[2] 	= 0;							// Watch Dog status
				SndData.DataBuf[3] 	= PROTOCOL_VER;						    // Protocol version
				SndData.DataBuf[4] 	= SOFT_VER;								// Software version
				SndData.DataBuf[5]	= 0x18;									// Year 2018									
				SndData.DataBuf[6]	= 'W';									// Company Willis Co.
				SndData.DataBuf[7]	= 'C';									// Author DS.Chin(James.Chin or Jim.C)
			}
		} break;
	}
}


/*******************************************************************************
	*
 	* FunctionName		CRC16_Cal
	*
********************************************************************************/
_Uint16	CRC16_Cal(_Uint8 Buffer[])
{
	_Uint16		ResultBuf   = 0x0000;
	_Uint8		CntBuf      = 0;
	_Uint8		BitBuf      = 0;
	
	for (CntBuf = 0; CntBuf < 4; CntBuf++)
	{
		ResultBuf ^= ((_Uint16)Buffer[CntBuf] << 8);
		
		for (BitBuf = 0; BitBuf < 8; BitBuf++)
		{
			if ((ResultBuf & 0x8000) == 0x8000)
			{
				ResultBuf = (ResultBuf << 1) ^ 0x1021;
			}
			else
			{
				ResultBuf <<= 1;
			}
		}
	}
	
	return ResultBuf;
}

/****************************************************************************
 * Color_Value_Get
 */
void Color_Value_Get(_Uint8 ColorNumBuf)
{
	_Uint8	TempCnt = 0;
	
	if (DisplayData.Mode > 0xA)
	{
		for (TempCnt = 0; TempCnt < 7; TempCnt++)
		{
			ColorData[TempCnt][0] = COLOR_VECTOR[TempCnt + 1][0];
			ColorData[TempCnt][1] = COLOR_VECTOR[TempCnt + 1][1];
			ColorData[TempCnt][2] = COLOR_VECTOR[TempCnt + 1][2];
		}
	}
	else
	{
		ColorData[0][0]	= COLOR_VECTOR[ColorNumBuf][0];
		ColorData[0][1]	= COLOR_VECTOR[ColorNumBuf][1];
		ColorData[0][2]	= COLOR_VECTOR[ColorNumBuf][2];
	}
}






/************************************************************************
 *
 * FunctionName   Hex_To_Char
 *
 *  Input					 HexBuf
 *								 HexBuf < 0x10
*************************************************************************/
static _Uint8		Hex_To_Char(_Uint8 HexBuf)
{
	if (HexBuf > 0x0F)		HexBuf &= 0x0F;
	
	//Hex = 0x0,0x1...0x9
	if (HexBuf < 0xA) 
	{
		return (HexBuf + '0');
	}
	
	// Hex = 0xA,0xB ... 0xF
	HexBuf -= 0xA;
	return (HexBuf + 'A');
}



