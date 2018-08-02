/***********************************************************
	*
	* File Name			| Ntc_Msr.c
	* Date					| 2016.11.22
	* Author				| DS.Chin
	* Description		| 检测环境度并加热
	*
************************************************************/

/* Include Files -------------------------------------------------------------*/
#include "Ntc_Msr.h"


/* Global Variables ----------------------------------------------------------*/
_TypeEnumNtc	NtcStatus;



/*--------------------------< File Parameters >-----------------------------*/
idata _Uint8			ProtectTime[3];
idata _Flag			    ProtectFlag;
idata _Flag			    ProtectInit;

/**
	* @Function Name			Ntc_Msr
	* @Parameters					None
	* @Return							None
	*/
void 	Ntc_Msr(void)
{
    _Uint8			TmprtrVal = 0;
	
	TmprtrVal = AD_Val_Get();	//取得温度值
	
	
	/* ERROR */
	if (TmprtrVal > T_MIN || TmprtrVal < T_MAX)
	{
		PORT_HOT	= HOT_OFF;
		NtcStatus = NTC_IDLE;
		return;
	}
	
	if (ProtectFlag == FALSE)
	{
		/* 当温度小于20度时,加热 */
		if (TmprtrVal > T_20 && ProtectFlag == FALSE)
		{
			PORT_HOT = HOT_ON;
			NtcStatus = NTC_HOT;
		}
		
		/* 当温度大于30度时,则停止加热 */
		if (TmprtrVal < T_30)
		{
			PORT_HOT = HOT_OFF;
			NtcStatus = NTC_IDLE;
		}
	}
	
	/* 当温度大于55度时,开启过温保护 */
	if (TmprtrVal < T_55)
	{
		NtcStatus = NTC_BAN;
		if (ProtectFlag == FALSE)
		{
			ProtectFlag = TRUE;
			ProtectInit = TRUE;
		}
		
		//关闭加热
		PORT_HOT	= HOT_OFF;
	}
	
	/* 过温保护计时,1h == 60min == 3600s */
	if (ProtectFlag == TRUE)
	{
		if (ProtectInit == TRUE)
		{
			ProtectInit = FALSE;
			ProtectTime[0] = 0;
			ProtectTime[1] = 0;
			ProtectTime[2] = 0;
		}
			
		ProtectTime[0]++;
		if (ProtectTime[0] >= 50)	//1s
		{
			ProtectTime[0] = 0;
			ProtectTime[1]++;
			if (ProtectTime[1] >= 60)	//1min
			{
				ProtectTime[1] = 0;
				ProtectTime[2]++;
				if (ProtectTime[2] >= 60)
				{
					ProtectTime[2] = 0;
					
					//一小时后温度高于50度,继续冷却
					if (TmprtrVal < T_50)
					{
						ProtectInit = TRUE;
					}
					
					//温度低于50度,则关闭温度保护
					else
					{
						ProtectFlag = FALSE;
						NtcStatus = NTC_BAN_EXIT;
					}
				}
			}
		}
	}
}

/**
	* @Function 		AD_Val_Get
	* @Parameters		None
	* @Return			None
	*/
static _Uint8	AD_Val_Get(void)
{
	_Uint8		AdCnt 	= 0;
	_Uint8		AdMax 	= 0;
	_Uint8		AdMin 	= 0xff;
	_Uint8		AdData 	= 0;
	_Uint16		AdSum	 	= 0;
	
	AdSum = 0;
	for (AdCnt = 0; AdCnt < 11; AdCnt++)
	{
		//Start
		ADCS = 1;
		
		//Wait
		while(!ADCF);
	
		AdData	= ADCRH;
	
		if (AdCnt > 0)		//抛弃第一次数据
		{
			if (AdMax < AdData)		AdMax = AdData;
			if (AdMin > AdData)		AdMin = AdData;
			AdSum += (_Uint16)AdData;
		}
	}
	
	// 取减去最大最小值后的平均值
	AdSum -= (AdMax + AdMin);
	AdSum >>= 3;
	
	return((_Uint8)AdSum);
}

