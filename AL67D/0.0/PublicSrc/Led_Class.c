/************************************************************************************************************
	*
	* FileName			Led_Class.c
	*
	* Description
	*								The protocol about communicate with LED, such as LED with KM5020, LED with UCS1903BC,
	*								LED drived by PWM, LED drived by general I/O or LED drived by custom protol.
	*
*************************************************************************************************************/
#include "Led_Class.h"


/*------------------------< Gloable Parameters >----------------------------------*/
_Uint8  DutyR;
_Uint8  DutyG;
_Uint8  DutyB;


/**************************************************************************************
	*
	* FunctionName		Led_Update
	*
***************************************************************************************/
void Led_Update(void)
{
    static _Uint8		DutyCnt;
	
	DutyCnt++;
	if (DutyCnt >= 125)			DutyCnt = 0;
	
	if (DutyCnt < DutyR)		PORT_RED 	= SET;
	else						PORT_RED	= RESET;
	
	if (DutyCnt < DutyB)		PORT_BLUE 	= SET;
	else						PORT_BLUE	= RESET;
	
	if (DutyCnt < DutyG)		PORT_GREEN	= SET;
	else						PORT_GREEN	= RESET;
}

