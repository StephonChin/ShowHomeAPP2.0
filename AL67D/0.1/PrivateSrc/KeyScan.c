/****************************************************************
	*
	* key_scan.c
	*
*****/
#include "Key_Scan.h"

/* gloable variables----------------------------------------------------------*/
idata _TypeEnumKey		KeyStatus = KEY_IDLE;


idata _Uint8		KeyTime = 0;
idata _Flag		    KeyLongFlag = FALSE;


/**
	* @Function Name		Key_Scan
	* @Parameters			None
	* @Return				None
	*/
void Key_Scan(void)
{
    if (TestFlag == TRUE)       return;
    
	if (PORT_KEY == 0)
	{
		KeyTime++;
		if (KeyTime > 75)
		{
			KeyTime	= 0;
			if (KeyLongFlag == FALSE)
			{
				KeyLongFlag = TRUE;
				KeyStatus	= KEY_LONG;
			}
		}
	}
	
	
	else
	{
		if (KeyLongFlag == FALSE && KeyTime > 0)
		{
			KeyStatus	= KEY_SHORT;
		}
		
		KeyLongFlag 	= FALSE;
		KeyTime		= 0;
	}
	
	
}
