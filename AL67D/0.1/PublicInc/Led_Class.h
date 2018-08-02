/*******************************************************************************
	*
	* FILE NAME
	*						 	LedClass.h
	* BRIEF
	*							Communicate with LED
	*
*******************************************************************************/
#ifndef __LED_CLASS_H__
#define __LED_CLASS_H__

/* < -----------------Include Files --------------------> */
#include "Type_Def.h"
#include "MCU_Config.h"
#include "Led_Display.h"

/*<---------------- Exported Function ------------------> */
void Led_Update(void);


/*------------------------< Exported Gloable Parameters >----------------------------------*/
extern _Uint8  DutyR;
extern _Uint8  DutyG;
extern _Uint8  DutyB;



#endif
