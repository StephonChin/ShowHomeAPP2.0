/*************************************************************
	*
	* @FileName	Data_Process
	*
**************************************************************/
#include "Data_Process.h"

//Global arguments
_Uint8					ChkSumH;
_Uint8					ChkSumL;
_Uint8					ChkSumRst;
_Uint8					ChkSumRstSave;
_Uint8					PowerOnNum;
_Uint8					ChkSumRst;
_Uint8					ChkSumRstSave;
_Uint8					PowerOnNum;
_Flag						WdtRstFlag;

//File arguments
_Uint8					NewChkSumH;
_Uint8					NewChkSumL;
_Uint8					ChkSumRstTime;
_Flag						PasswordFlag;						//Allow set the password flag



/************************************************************
	*
	* @FunctionName	User_Init
	*
*************************************************************/
void User_Init(void)
{
	//Get the power on status from APROM
	PowerOnNum						= Byte_Read_From_APROM(APROM_POWERON);

	//First time to power on
	if (PowerOnNum != 0xAa){
		LedData.Mode			= 0x8;
		LedData.ModeBuf		= 0x8;
		LedData.Color			= 0x7;
		TimerData.CntDwnHour = 0x6;
		PowerOnNum				= 0xAA;
		ChkSumH						= 0x0;
		ChkSumL						= 0x0;

		LeData.InitFlag		= TRUE;
		Color_Value_Get(LedData.Color);
		TimerData.InitFlag = TRUE;
		FlashSaveFlag			= TRUE;

		return;
	}

	// Get the mode ,color ,password, count down hours from APROM
	LedData.ModeBuf				= Byte_Read_From_APROM(APROM_MODE);
	LedData.Color					= Byte_Read_From_APROM(APROM_COLOR);
	TimerData.CntDwnHour	= Byte_Read_From_APROM(APROM_TIMER);
	ChkSumH								= Byte_Read_From_APROM(APROM_CHKSUMH);
	ChkSumL								= Byte_Read_From_APROM(APROM_CHKSUML);
	ChkSumRst							= Byte_Read_From_APROM(APROM_CHKSUMRST);


	/* Check the mode */
	if ((LedData.ModeBuf > MODE_MAX) || (LedData.ModeBuf == 0x0)){
		LedData.ModeBuf	= 0x8;
		FlashSaveFlag		= TRUE;					// if the mode value isn't valid
	}
	LedData.Mode				= LedData.ModeBuf;
	LedData.InitFlag		= TRUE;
	if (LedData.ModeBuf == 0x8)		LedData.CircleInitFlag	= TRUE;


	/* Check the color */
	if (LedData.Color == 0x0 || LedData.Color > COLOR_MAX){
		LedData.Color	= 0x7;
		FlashSaveFlag = TRUE;
	}
	Color_Value_Get(LedData.Color);


	/* Check the count down hour*/
	if (TimerData.CntDwnHour > 0x8){
		TimerData.CntDwnHour		= 0x6;
		FlashSaveFlag = TRUE;
	}
	TimerData.InitFlag		= TRUE;

	//----------------------------------------------------------------------
	// Check the count
	// if power on 3 times in 5 seconds, reset the checksum
	// 1 -> write 0x55
	// 2 -> write 0xAA
	// 3 -> Reset
	//----------------------------------------------------------------------
	if (WdtRstFlag == FALSE)
	{
		if (ChkSumRst == 0){
			ChkSumRstSave 		= 0x55;
			FlashSaveFlag			= TRUE;
		}
		else if (ChkSumRst == 0x55){
			ChkSumRstSave 		= 0xAA;
			FlashSaveFlag			= TRUE;
		}
		else if (ChkSumRst == 0xAA){
			ChkSumH 			= 0;
			ChkSumL 			= 0;
			ChkSumRstSave = 0;
			ChkSumRst			= 0;
			FlashSaveFlag = TRUE;

			LedData.Mode 			= 0xFD;
			LedData.InitFlag 	= TRUE;
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
	if (ChkSumRst != 0){
		ChkSumRstTime++;
		if (ChkSumRstTime >= 250){
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
	if (PasswordFlag){
		PasswordTime++;
		if (PasswordTime >= 250)				PasswordFlag = FALSE;
	}
	else{
		PasswordTime = 0;
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
	if (HexBuf < 0xA){
		return (HexBuf + '0');
	}

	// Hex = 0xA,0xB ... 0xF
	HexBuf -= 0xA;
	return (HexBuf + 'A');
}


/************************************************************
	*
	* @FunctionName	Data_Process
	*
****/
void Data_Process(void)
{
	/* Timer Process */
	Count_Down_Process();

	/* CSR1010 Process */
	CSR1010_Process();

	Password_Process();
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
	if (TimerData.Status == TIM_OPEN){
		TimerData.Status	= TIM_IDLE;
		LedData.Mode			= LedData.ModeBuf;
		LedData.InitFlag	= TRUE;
		return;
	}

	/* Close */
	if (TimerData.Status == TIM_CLOSE){
		TimerData.Status	= TIM_IDLE;
		LedData.Mode			= 0x0;
		LedData.InitFlag	= TRUE;
		return;
	}
}



/************************************************************
	*
	* @FunctonName	CSR1010_Process
	*
*****/
static void CSR1010_Process(void)
{
	static 	_Uint8 		FlagClrTime = 0;
	static bit 				FlagClrFlag = FALSE;
	static 	bit 			BtInitFlag 	= FALSE;				// CSR1010 initialize flag
	static 	_Uint8		CmdFlagNum 	= 0xFF;					// Rcv command flag
					_Uint8		temp				= 0;
					_Uint8		cmd					= 0;

	//Clear the flag after 500ms
	if (FlagClrFlag == TRUE){
		FlagClrTime++;
		if (FlagClrTime >= 25){
			FlagClrTime = 0;
			FlagClrFlag = FALSE;
			CmdFlagNum  = 0xFF;
		}
	}
	else{
		FlagClrTime = 0;
	}


	/* When RcvDoneFlag equals FALSE, there's no data received from CSR1010
		 Then, exit function */
	if (RcvFlag == FALSE){
		return;
	}
	/* When RcvDoneFlag equals TRUE, CSR1010 has send data to MCU.Under this
		 condition, process the data */
	RcvDoneFlag	= FALSE;							// clear receive flag



	//Check the package head
	if (RcvData[0] != 0xFD)			return;



	/*+++ CSR1010 initialization is complete	+++*/
	if ((RcvData[1] == 0xF0) && (BtInitFlag == FALSE))
	{
		SndData[0] = 0xfc;
		SndData[1] = DEVICE_NAME_ONE;
		SndData[2] = DEVICE_NAME_TWO;
		SndData[3] = DEVICE_NUM;
		SndData[4] = Hex_To_Char(ChkSumH >> 4);
		SndData[5] = Hex_To_Char(ChkSumH & 0x0F);
		SndData[6] = Hex_To_Char(ChkSumL >> 4);
		SndData[7] = Hex_To_Char(ChkSumL & 0x0F);
		SndData[8] = 0xfe;
		CSR1010Csr1010_Snd_Data(SndData, 9);
		return;
	}


	/*+++Check the command flag number, if reply ,then exit ++++*/
	if (CmdFlagNum == (RcvData[1] & 0xF0)){
		return;
	}
	CmdFlagNum	= RcvData[1] & 0xF0;			// if not equal, replaced
	FlagClrFlag	= TRUE;
	FlagClrTime = 0;


	//Get the command
	cmd = RcvData[1] & 0x0f;


	//process the command
	switch (cmd){
		//power on or inquire command
		case 0x1:
		case 0x2:{
			SndData[0] = 0xfd;
			SndData[1] = 0x1;
			SndData[2] = 'L';
			SndData[3] = 'A';
			SndData[4] = 'D';
			SndData[5] = LedData.ModeBuf;
			SndData[6] = LedData.Color;
			SndData[7] = ChkSumH;
			SndData[8] = ChkSumL;
			SndData[9] = 0xfe;
			Csr1010_Snd_Data(SndData, 10);
		}break;

		//control the mode and color
		case 0x3:{
			// turn off
			if (RcvData[2] == 0x0){
				LedData.Mode			= 0x0;
				LedData.InitFlag	= TRUE;
			}

			// turn on
			else if (RcvData[2] == 0xFF){
				LedData.Mode			= LedData.ModeBuf;
				LedData.InitFlag	= TRUE;
				Color_Value_Get(LedData.Color);
			}

			// normal mode
			else
			{
				// overflow
				if (RcvData[2] > MODE_MAX){
					RcvData[2]	= 0x8;
				}
				LedData.ModeBuf		= RcvData[2];
				LedData.Mode			= LedData.ModeBuf;
				LedData.InitFlag	= TRUE;
				if (LedData.ModeBuf == 0x8)		LedData.CircleInitFlag	= TRUE;


				// color
				if (RcvData[3] == 0x0 || RcvData[3] > 0xF){
					RcvData[3] = 0x7;
				}
				LedData.Color	= RcvData[3];
				Color_Value_Get(LedData.Color);

				FlashSaveFlag = TRUE;
			}
		} break;

		//---------------------------------------------------------------------------
		// FD xA MODE COLOR 00 00 00 FE
		// Set the show mode, color
		//---------------------------------------------------------------------------
		case 0xA:
		{
			// Err check
			// LedData.Mode 		= 0x0~0xA || 0xFF
			// ColorNum		= 0x0 ~ 0x1C
			if (RcvData[2] > 0x3) || RcvData[2] == 0x0))		break;
			if RcvData[3] > 0x8)																			break;

			// Get the mode value
			#error  "----"
			LedData.Mode				= RcvData[2] + 0xA;
			LedData.ModeBuf			= LedData.Mode;
			LedData.InitFlag 		= TRUE;

			// Get the color
			#error  "----"
			LedData.ColorValue 		= RcvData[3];
			Color_Value_Get(LedData.Color);

			FlashSaveFlag							= TRUE;
		} break;

		//Set Timer
		case 0x5:{
			// when the data is error ,exit
			if (RcvData[2] > 8)
			{
				RcvData[2]	= 8;
			}

			LedData.WarningFlag		= TRUE;
			LedData.InitFlag			= TRUE;

			TimerData.CntDwnHour	= RcvData[2];
			TimerData.InitFlag		= TRUE;

			FlashSaveFlag = TRUE;
		} break;

		//---------------------------------------------------------------------------
		// process the synchronizaton data
		// All products would be synchronize when display mode is 0xB | 0xC | 0xD
		// Only AL91 and AL94(Horse Enable) products would be synchronize when mode is 0x6
		//---------------------------------------------------------------------------
		case 0xF:
		{
			// if the device's mode or theme isn't as same as received data
			// Change the device's mode or color
			if (RcvData[1] > 0xA && LedData.Mode != 0)
			{
				if (LedData.Mode != RcvData[2])
				{
					LedData.Mode 			= RcvData[2];
					LedData.ModeBuf 	= RcvData[2];
					LedData.InitFlag 	= TRUE;
					FlashSaveFlag					= TRUE;
					Color_Value_Get(LedData.Color);
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
				if ((RcvData[2] ^ RcvData[3] ^ RcvData[4] ^ RcvData[5]) != RcvData[6])		// Password is wrong
				{
					LedData.Mode = 0xFF;
					LedData.InitFlag = TRUE;

					SndData[0] = 0xfd;
					SndData[1] = 0x8;
					SndData[2] = 0x4;
					SndData[3] = 0;
					SndData[4] = 0;
					SndData[5] = NewChkSumH;
					SndData[6] = NewChkSumL;
					SndData[7] = ChkSumH;
					SndData[8] = ChkSumL;
					SndData[9] = 0xfe;
					CSR1010Csr1010_Snd_Data(SndData, 10);
					break;
				}

				ChkSumBuf = CRC16_Cal(&RcvData[2]);
				if (ChkSumBuf != (_Uint16)(((_Uint16)NewChkSumH * 256) + (_Uint16)NewChkSumL))
				{
					LedData.Mode = 0xFF;
					LedData.InitFlag = TRUE;				//ID1 ID2 ID3 ID4 CRC16-CCITT-FALSE  isn't equal the new checksum

					SndData[0] = 0xfd;
					SndData[1] = 0x8;
					SndData[2] = 0x4;
					SndData[3] = 0;
					SndData[4] = 0;
					SndData[5] = NewChkSumH;
					SndData[6] = NewChkSumL;
					SndData[7] = ChkSumH;
					SndData[8] = ChkSumL;
					SndData[9] = 0xfe;
					CSR1010Csr1010_Snd_Data(SndData, 10);
					break;
				}

				//send broadcast name
				SndData[0] = 00xfc;
				SndData[1] = DEVICE_NAME_ONE;
				SndData[2] = DEVICE_NAME_TWO;
				SndData[3] = DEVICE_NUM;
				SndData[4] = Hex_To_Char(NewChkSumH >> 4);
				SndData[5] = Hex_To_Char(NewChkSumH & 0x0F);
				SndData[6] = Hex_To_Char(NewChkSumL >> 4);
				SndData[7] = Hex_To_Char(NewChkSumL & 0x0F);
				SndData[8] = 0xfe;
				CSR1010Csr1010_Snd_Data(SndData, 9);

				// Reponse to APP
				SndData[0] = 0xfd;
				SndData[1] = 0x8;
				SndData[2] = 0x3;
				SndData[3] = 0;
				SndData[4] = 0;
				SndData[5] = NewChkSumH;
				SndData[6] = NewChkSumL;
				SndData[7] = ChkSumH;
				SndData[8] = ChkSumL;
				SndData[9] = 0xfe;
				CSR1010Csr1010_Snd_Data(SndData, 10);

				ChkSumH 						= NewChkSumH;
				ChkSumL 						= NewChkSumL;
				NewChkSumH 					= 0;
				NewChkSumL 					= 0;

				LedData.Mode 			= 0xFD;
				LedData.InitFlag 	= TRUE;
				FlashSaveFlag					= TRUE;
			}

			// time out
			else
			{
				SndData[0] = 0xfd;
				SndData[1] = 0x8;
				SndData[2] = 0x4;
				SndData[3] = 0;
				SndData[4] = 0;
				SndData[5] = NewChkSumH;
				SndData[6] = NewChkSumL;
				SndData[7] = ChkSumH;
				SndData[8] = ChkSumL;
				SndData[9] = 0xfe;
				CSR1010Csr1010_Snd_Data(SndData, 10);
			}
		} break;

		case 0x8:
		{
			if (RcvData[2] == 0x1)
			{
				LedData.Mode 			= 0xFB;
				LedData.InitFlag 	= TRUE;
			}
			else if (RcvData[2] == 0x2)
			{
				PasswordFlag = TRUE;								// Allow set the password within 5 seconds

				NewChkSumH = RcvData[3];
				NewChkSumL = RcvData[4];

				SndData[0] = 0xfd;
				SndData[1] = 0x8;
				SndData[2] = 0x2;
				SndData[3] = 0;
				SndData[4] = 0;
				SndData[5] = NewChkSumH;
				SndData[6] = NewChkSumL;
				SndData[7] = ChkSumH;
				SndData[8] = ChkSumL;
				SndData[9] = 0xfe;
				CSR1010Csr1010_Snd_Data(SndData, 10);
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
			if (RcvData[1] == 0x0)
			{
				SndData[0] = 0xfd;
				SndData[1] = 0xd;
				SndData[2] = DEVICE_NAME_ONE;
				SndData[3] = DEVICE_NAME_TWO;
				SndData[4] = DEVICE_NUM;
				SndData[5] = 0;
				SndData[6] = TimerData.CntDwnHour;
				SndData[7] = ChkSumH;
				SndData[8] = ChkSumL;
				SndData[9] = 0xfe;
				CSR1010Csr1010_Snd_Data(SndData, 10);
				break;
			}

			if (RcvData[1] == 0x1)
			{
			/*	SndData[0] = 0xfd;
				SndData[1] = 0xd;
				SndData[2] = DEVICE_NAME_ONE;
				SndData[3] = DEVICE_NAME_TWO;
				SndData[4] = DEVICE_NUM;
				SndData[5] = 0;
				SndData[6] = TimerData.CntDwnHour;
				SndData[7] = ChkSumH;
				SndData[8] = ChkSumL;
				SndData[9] = 0xfe;
				CSR1010Csr1010_Snd_Data(SndData, 10);
				SndData.SndStatus 	= SND_NORMAL;
				SndData.DataBuf[0]	= 0xD;
				SndData.DataBuf[1] 	= HseStatus;							// HSE status
				SndData.DataBuf[2] 	= WdtRstFlag;							// Watch Dog status
				SndData.DataBuf[3] 	= PROTOCOL_VER;						// Protocol version
				SndData.DataBuf[4] 	= SOFT_VER;								// Software version
				SndData.DataBuf[5]	= 0x18;										// Year 2018
				SndData.DataBuf[6]	= 'W';										// Company Willis Co.
				SndData.DataBuf[7]	= 'C';										// Author DS.Chin(James.Chin or Jim.C)*/
			}
		} break;
	}

}



/**************************************************************
	*
	* @FunctionName		Color_Value_Get
	*
*****/
static void Color_Value_Get(_Uint8	ColorValBuf)
{
	_Uint8 TempCnt = 0;

	for (TempCnt = 0; TempCnt < 6; TempCnt++)
	{
		Color[TempCnt] = 0;
	}

	switch (ColorValBuf)
	{
		case 0x1:
			Color[0] = &RedDuty[0];
			Color[2] = &RedDuty[1];
			Color[4] = &RedDuty[2];
		 break;

		 /* green */
		 case 0x2:
			Color[0] = &GreenDuty[0];
			Color[2] = &GreenDuty[1];
			Color[4] = &GreenDuty[2];
		 break;

		 /* RRRGGG*/
		case 0x3:
			Color[0] = &RedDuty[0];
			Color[1] = &GreenDuty[0];
			Color[2] = &RedDuty[1];
			Color[3] = &GreenDuty[1];
			Color[4] = &RedDuty[2];
			Color[5] = &GreenDuty[2];
		break;

		 /* blue */
		 case 4:
			Color[0] = &BlueDuty[0];
			Color[2] = &BlueDuty[1];
			Color[4] = &BlueDuty[2];
		 break;


		/* RRRBBB*/
		case 0x5:
			Color[0] = &RedDuty[0];
			Color[1] = &BlueDuty[0];
			Color[2] = &RedDuty[1];
			Color[3] = &BlueDuty[1];
			Color[4] = &RedDuty[2];
			Color[5] = &BlueDuty[2];
		break;

		/* GGGBBB*/
		case 0x6:
			Color[0] = &GreenDuty[0];
			Color[1] = &BlueDuty[0];
			Color[2] = &GreenDuty[1];
			Color[3] = &BlueDuty[1];
			Color[4] = &GreenDuty[2];
			Color[5] = &BlueDuty[2];
		break;

		/* RRGGBB */
		case 0x7:
			Color[0] = &RedDuty[0];
			Color[1] = &BlueDuty[0];
			Color[2] = &RedDuty[1];
			Color[3] = &GreenDuty[1];
			Color[4] = &GreenDuty[2];
			Color[5] = &BlueDuty[2];
		break;


		 /* white */
		 case 8:
			Color[0] = &WhiteDuty[0];
			Color[2] = &WhiteDuty[1];
			Color[4] = &WhiteDuty[2];
		 break;


		 /* RRRWWW */
		case 0x9:
			Color[0] = &RedDuty[0];
			Color[1] = &WhiteDuty[0];
			Color[2] = &RedDuty[1];
			Color[3] = &WhiteDuty[1];
			Color[4] = &RedDuty[2];
			Color[5] = &WhiteDuty[2];
		break;

		/* GGGWWW */
		case 0xA:
			Color[0] = &GreenDuty[0];
			Color[1] = &WhiteDuty[0];
			Color[2] = &GreenDuty[1];
			Color[3] = &WhiteDuty[1];
			Color[4] = &GreenDuty[2];
			Color[5] = &WhiteDuty[2];
		break;

		/* RRGGWW */
		case 0xB:
			Color[0] = &RedDuty[0];
			Color[1] = &WhiteDuty[0];
			Color[2] = &RedDuty[1];
			Color[3] = &GreenDuty[1];
			Color[4] = &GreenDuty[2];
			Color[5] = &WhiteDuty[2];
		break;


		/* BBBWWW */
		case 0xC:
			Color[0] = &BlueDuty[0];
			Color[1] = &WhiteDuty[0];
			Color[2] = &BlueDuty[1];
			Color[3] = &WhiteDuty[1];
			Color[4] = &BlueDuty[2];
			Color[5] = &WhiteDuty[2];
		break;


		/* RRBBWW */
		case 0xD:
			Color[0] = &RedDuty[0];
			Color[1] = &WhiteDuty[0];
			Color[2] = &RedDuty[1];
			Color[3] = &BlueDuty[1];
			Color[4] = &BlueDuty[2];
			Color[5] = &WhiteDuty[2];
		break;

		/* GGBBWW */
		case 0xE:
			Color[0] = &BlueDuty[0];
			Color[1] = &WhiteDuty[0];
			Color[2] = &BlueDuty[1];
			Color[3] = &GreenDuty[1];
			Color[4] = &GreenDuty[2];
			Color[5] = &WhiteDuty[2];
		break;


		/* RGBWW */
		case 0xF:
			Color[0] = &RedDuty[0];
			Color[1] = &WhiteDuty[0];
			Color[2] = &GreenDuty[1];
			Color[3] = &WhiteDuty[1];
			Color[4] = &BlueDuty[2];
			Color[5] = &WhiteDuty[2];
		break;

	} //set color
}
