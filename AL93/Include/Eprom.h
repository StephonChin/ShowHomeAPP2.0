/*******************************************************************
	*
	* @FileName		Eprom.h
	*
********************************************************************/
#ifndef __EPROM_H__
#define __EPROM_H__


/* @Include Files */
#include "System.h"
#include "Config.h"
#include "Led_Display.h"


/* @Define */
#define	APROM_ERASE			0x22
#define APROM_WRITE			0x21
#define	APROM_READ			0x00
#define	LDROM_ERASE			0x62
#define	LDROM_WRITE			0x61
#define	LDROM_READ			0x40
#define CONFIG_ERASE		0xE2
#define	CONFIG_WRITE		0xE1
#define	CONFIG_READ			0xC0


/* @Type Define */
typedef enum _EPROM_SAVE_TYPE
{
	APROM_MODE,
	APROM_COLOR,
	APROM_TIMER
}_TypeEnumEprom;


typedef struct _APROM_WRITE_DATA
{
	_Uint8		Mode;
	_Uint8		Color;
	_Uint8		CntDwnHour;
}_TypeStructAP;




/* @Exported Functions */
void Byte_Write_To_APROM(void);
_Uint8 Byte_Read_From_APROM(_TypeEnumEprom);


/* @Exported variables */
extern _TypeStructAP 	APData;


#endif
