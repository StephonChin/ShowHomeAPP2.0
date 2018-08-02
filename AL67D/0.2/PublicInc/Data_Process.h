/*******************************************************************************
	*
	* FILE NAME
	*							Data_Process.h
	*
*******************************************************************************/
#ifndef __DATA_PROCESS_H__
#define __DATA_PROCESS_H__

/*<---------------- Include Files --------------------> */
#include "Type_Def.h"
#include "Flash_Prgrm.h"
#include "CSR1010.h"
#include "Led_Display.h"
#include "Motor.h"
#include "Ntc_Msr.h"
#include "Key_Scan.h"
#include "MCU_Config.h"
#include "BT_Control.h"


/*<---------------- Define ---------------------------> */
#define			R							0
#define			G							1
#define			B							2
#define         COLOR_MAX                   7





/*<---------------- Exported Function-----------------> */
void User_Data_Init(void);
void Data_Process(void);

/*<---------------- File Functions -------------------> */
static void 						Key_Process(void);
static void                         Tmprtr_Process(void);
static void 						Password_Process(void);
static void 						Syn_Process(void);
static void 						Count_Down_Process(void);
static void 						CSR1010_Process(void);
static void 						Color_Value_Get(_Uint8	ColorValBuf);
static _Uint16					    CRC16_Cal(_Uint8 Buffer[]);
static _Uint8						Hex_To_Char(_Uint8);



/*<---------------- Exported Parameters --------------> */
extern idata _Uint8						ChkSumH;
extern idata _Uint8						ChkSumL;
extern idata _Uint8						ChkSumRst;
extern idata _Uint8						ChkSumRstSave;
extern idata _Uint8						PowerOnNum;
extern idata _Flag                      TestFlag;




#endif
