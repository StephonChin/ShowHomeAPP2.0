/*************************************************************************
	*
	* FILE NAME			BT_Control.h
	* BRIEF					To control the power of bluetooth
	*
**************************************************************************/
#ifndef __BT_CONTROL_H__
#define __BT_CONTROL_H__

//--------------------------< Include Files >---------------------------//
#include "Type_Def.h"
#include "MCU_Config.h"


//--------------------------< Type Redefine >--------------------------//
typedef enum EN_BT_CON
{
	BT_IDLE,
	BT_POWER_ON,
	BT_POWER_OFF,
	BT_RESTART
}_TypeBtCon;


//-----------------------< Exported Functions >----------------------//
void BT_Work_Detect(void);



//-----------------------< Exported Parameters >---------------------//
extern idata _TypeBtCon			BtConStatus;
extern idata _Flag					BtRcvDataFlag;
extern idata _Flag					BtPowerInitFlag;


//-----------------------< File Parameters >------------------------//
static void BT_Power_Control(void);





#endif
