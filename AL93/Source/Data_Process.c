/*************************************************************
	*
	* @FileName	Data_Process
	*
**************************************************************/
#include "Data_Process.h"



/************************************************************
	*
	* @FunctionName	User_Init
	*
*************************************************************/
void User_Init(void)
{
	/* Restore the mode value , color value and count down hour from APROM */
	LedData.ModeBuf				= Byte_Read_From_APROM(APROM_MODE);
	LedData.Color					= Byte_Read_From_APROM(APROM_COLOR);
	TimerData.CntDwnHour	= Byte_Read_From_APROM(APROM_TIMER);
	APData.Mode						=	LedData.ModeBuf;
	APData.Color					= LedData.Color;
	APData.CntDwnHour			= TimerData.CntDwnHour;
	
	/* Check the mode */
	if ((LedData.ModeBuf > 0x8) || (LedData.ModeBuf == 0x0))		
	{
		LedData.ModeBuf	= 0x8;
		APData.Mode			= 0x8;
		Byte_Write_To_APROM();					// if the mode value isn't valid
	}
	LedData.Mode				= LedData.ModeBuf;
	LedData.InitFlag		= TRUE;
	if (LedData.ModeBuf == 0x8)		LedData.CircleInitFlag	= TRUE;	
	
	
	/* Check the color */
	if (LedData.Color == 0x0 || LedData.Color > 0xF)
	{
		LedData.Color	= 0x7;
		APData.Color	= 0x7;
		Byte_Write_To_APROM();
	}
	Color_Value_Get(LedData.Color);
	
	
	/* Check the count down hour*/
	if ((TimerData.CntDwnHour > 0x8) || (TimerData.CntDwnHour % 2 != 0))
	{
		TimerData.CntDwnHour		= 0x0;
		APData.CntDwnHour				= 0x0;
		Byte_Write_To_APROM();
	}
	TimerData.InitFlag		= TRUE;
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
		TimerData.Status	= TIM_IDLE;
		LedData.Mode			= LedData.ModeBuf;
		LedData.InitFlag	= TRUE;
		return;
	}
	
	/* Close */
	if (TimerData.Status == TIM_CLOSE)
	{
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
	static 	_Flag			BtInitFlag 	= FALSE;				// CSR1010 initialize flag
	static 	_Uint8		CmdFlagNum 	= 0xFF;					// Rcv command flag
					_Uint8		TempCnt			= 0;
	
	
	
	
	/* When RcvDoneFlag equals FALSE, there's no data received from CSR1010 
		 Then, exit function */
	if (RcvDoneFlag == FALSE)			
	{		
		return;
	}
	
	
	
	
	
	/* When RcvDoneFlag equals TRUE, CSR1010 has send data to MCU.Under this
		 condition, process the data */
	RcvDoneFlag	= FALSE;							// clear receive flag
	
	
	
	
	
	
	/*+++ CSR1010 initialization is complete	+++*/
	if ((RcvData.DataBuf[0] == 0xF0) && (BtInitFlag == FALSE))		
	{
		SndData.SndStatus = SND_TYPE;		// type send
		return;
	}
	
	
	
	
	
	/*+++Check the command flag number, if reply ,then exit ++++*/
	if (CmdFlagNum == (RcvData.DataBuf[0] & 0xF0))
	{
		return;
	}
	CmdFlagNum	= RcvData.DataBuf[0] & 0xF0;			// if not equal, replaced
	
	
	
	
	
	/*+++	When received the below command, MCU will reply x1 00 00 00 00 00 00 00 to CSR1010
				in order to declare itselft
	*/
	if ((RcvData.DataBuf[0] & 0x0F) == 0x1)
	{
		SndData.SndStatus		= SND_NORMAL;
		SndData.DataBuf[0]	= RcvData.DataBuf[0];
		for (TempCnt = 1; TempCnt < 8; TempCnt++)			
		{
			SndData.DataBuf[TempCnt]	= 0x0;
		}
		return;
	}
	
	
	
	
	/*+++	Status command , reply AL93's mode, color, count down hour' value+++*/
	if ((RcvData.DataBuf[0] & 0xF) == 0x2)
	{
		SndData.SndStatus		= SND_NORMAL;
		SndData.DataBuf[0]	= RcvData.DataBuf[0];
		SndData.DataBuf[1]	= LedData.ModeBuf;
		SndData.DataBuf[2]	= LedData.Color;
		SndData.DataBuf[3]	= TimerData.CntDwnHour;
		if (LedData.Mode == 0x0)		SndData.DataBuf[4]	= 0x0;
		else												SndData.DataBuf[4]	= 0x1;
		for (TempCnt = 5; TempCnt < 8; TempCnt++)		
		{
			SndData.DataBuf[TempCnt]	= 0x0;
		}
		return;
	}
	
	
	
	
	/*<--Online command, when received the command 0xE, reply to APP as same as received-->*/
	if ((RcvData.DataBuf[0] & 0xF) == 0xE)
	{
		SndData.SndStatus		= SND_NORMAL;
		SndData.DataBuf[0]	= RcvData.DataBuf[0];
		for (TempCnt = 1; TempCnt < 8; TempCnt++)		RcvData.DataBuf[TempCnt]	= 0;
		return;
	}
	
	
	
	
	/*+++ The below command set the projector's mode+++ */
	if ((RcvData.DataBuf[0] & 0x0F) == 0x3)
	{
		// turn off
		if (RcvData.DataBuf[1] == 0x0)
		{
			LedData.Mode			= 0x0;
			LedData.InitFlag	= TRUE;
		}
		
		// turn on
		else if (RcvData.DataBuf[1] == 0xFF)
		{
			LedData.Mode			= LedData.ModeBuf;
			LedData.InitFlag	= TRUE;
		}
		
		// normal
		else
		{
			// overflow
			if (RcvData.DataBuf[1] > 0x8)
			{
				RcvData.DataBuf[1]	= 0x8;
			}
			
			LedData.ModeBuf		= RcvData.DataBuf[1];
			LedData.Mode			= LedData.ModeBuf;
			LedData.InitFlag	= TRUE;
			if (LedData.ModeBuf == 0x8)		LedData.CircleInitFlag	= TRUE;	
			APData.Mode				= LedData.ModeBuf;
			Byte_Write_To_APROM();
		}
		
		return;
	}
	
	
	
	
	/*+++ The below command set the projector's color+++ */
	if ((RcvData.DataBuf[0] & 0x0F)	== 0x4)
	{
		// when the data
		if (RcvData.DataBuf[1] == 0x0 || RcvData.DataBuf[1] > 0xF)
		{
			return;
		}
		LedData.Color	= RcvData.DataBuf[1];
		APData.Color	= LedData.Color;
		Color_Value_Get(LedData.Color);
		LedData.InitFlag	= TRUE;
		if (LedData.ModeBuf == 0x8)		LedData.CircleInitFlag	= TRUE;	
		Byte_Write_To_APROM();
		
		return;
	}
	
	
	/*+++ The below command set the projector's count down hour +++*/
	if ((RcvData.DataBuf[0] & 0x0F) == 0x5)
	{
		// when the data is error ,exit
		if ((RcvData.DataBuf[2] > 8) || (RcvData.DataBuf[2] % 2 != 0))
		{
			return;
		}
		
		LedData.WarningFlag		= TRUE;
		LedData.InitFlag			= TRUE;
		
		TimerData.CntDwnHour	= RcvData.DataBuf[2];
		TimerData.InitFlag		= TRUE;
		APData.CntDwnHour			= TimerData.CntDwnHour;
		Byte_Write_To_APROM();
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


