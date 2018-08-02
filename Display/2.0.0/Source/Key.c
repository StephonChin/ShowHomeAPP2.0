/********************************************************************
	*
	* FILE NAME
	*									Key.c
	* DATE
	*									01 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									Key Scan
	*
*********************************************************************/
#include "Key.h"


/*
 * Global Parameters
 */
_TypeKey		KeyStatus;
_Flag				KeyDetFlag;


/*
 * FunctionName		Key_Scan
 * Brief					Scan the four key to get the status,then change the
 *                Mode in data_prcess.c file
 */
void Key_Scan(void)
{
	static _Uint8		KeyTime;
	
	/*
	 * Show 1 Key Scan
	 */
	if (GPIO_ReadInputDataBit(PORT_KEY) == Bit_RESET)
	{
		KeyTime++;
		KeyDetFlag = TRUE;
	}
	else
	{
		if (KeyTime > 3 && KeyTime < 8)
		{
			KeyStatus = KEY_SHOW_ONE;
		}
		else if (KeyTime > 7 && KeyTime < 13)
		{
			KeyStatus = KEY_SHOW_TWO;
		}
		else if (KeyTime > 12 && KeyTime < 18)
		{
			KeyStatus = KEY_SHOW_THREE;
		}
		
		KeyTime = 0;
		KeyDetFlag = FALSE;
	}

}





