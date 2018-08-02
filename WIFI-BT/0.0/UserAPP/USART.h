/********************************************************************
  *
  * FILE NAME      USART.h
  *
*********************************************************************/
#ifndef __USART_H__
#define __USART_H__

//-------------------< Include File >-------------------------------
#include "TypeDef.h"



//-------------------< Define >-------------------------------------
#define 	RCV_BYTE_MAX	    20
#define   PROTOCOL_VER      0x55
#define   CRC_VAL           10


//-------------------< Type Redefine >------------------------------
typedef struct RCV_DATA_TYPE
{
	_Flag		RcvDoneFlag;
	_Uint8 	DataBuf[15];
}_TypeStructRcv;


typedef struct SND_DATA_TYPE
{
	enum SND_STATUS
	{
		SND_IDLE,	SND_TYPE,	SND_NORMAL, SND_BROADCAST
	}SndStatus;
	_Flag 		SndByteDoneFlag;
	_Uint8 		DataBuf[15];
}_TypeStructSnd;


typedef enum UART_CMD_T{
    /* switch command */
    CMD_NONE                = 0x00,     // None
    CMD_SOCKET_ON			      = 0x30,     // Switch on / off
    CMD_SOCKET_OFF			    = 0x31,	
    
    
    /* ShowHome APP products commands */
    CMD_THEME_SET           = 0x32,     // Change color or theme
                                        // len = 1  >> Value(0 ~ 29)
                                        //          >> if Value = 0,   change the color or theme to the next one
                                        //          >> else , select the specific color or theme as fallow table
                                        //                      0x01 - Red (Color)
                                        //                      0x02 - Green (Color)
                                        //                      0x03 - Blue (Color)
                                        //                      0x04 - Orange (Color)
                                        //                      0x05 - Hot pink (Color)
                                        //                      0x06 - Spring Green (Color)
                                        //                      0x07 - Gold (Color)
                                        //                      0x08 - Deep Pink (Color)
                                        //                      0x09 - Lawn Green (Color)
                                        //                      0x0A - Magenta (Color)
                                        //                      0x0B - Cyan (Color)
                                        //                      0x0C - Yellow (Color)
                                        //                      0x0D - Purple (Color)
                                        //                      0x0E - Pure White (Color)
                                        //                      0x0F - Cold White (Color)
                                        //                      0x10 - Warm White (Color)
                                        //                      0x11 - Spring (Theme)
                                        //                      0x12 - Summer (Theme)
                                        //                      0x13 - Autumn (Theme)
                                        //                      0x14 - Winter (Theme)
                                        //                      0x15 - Christmas Day (Theme)
                                        //                      0x16 - Valentines' Day (Theme)
                                        //                      0x17 - Independence Day (Theme)
                                        //                      0x18 - Thanksgiving Day (Theme)
                                        //                      0x19 - St. Patrick's Day (Theme)
                                        //                      0x1A - Halloween (Theme)
                                        //                      0x1B - Sun (Theme)
                                        //                      0x1C - Earth (Theme)
                                        //                      0x1D - Multi Color (Theme)
                       

    CMD_MODE_CHG            = 0x33,     // Change mode
                                        // len = 1  >> Value (0 ~ 11)
                                        //          >> if Value = 0, change the mode to next one
                                        //          // else , select the specific mode as fallow table
                                        //                      0x01 - Steady
                                        //                      0x02 - Blink
                                        //                      0x03 - Sparkle
                                        //                      0x04 - Instead
                                        //                      0x05 - Sea Wave
                                        //                      0x06 - Roll
                                        //                      0x07 - Ripple
                                        //                      0x08 - Flower Bloom
                                        //                      0x09 - Polar Light
                                        //                      0x0A - Color Show
                                        
                                        
    CMD_SHOW_MODE           = 0x34,     // Select Show Mode
                                        // len = 1  >> Value (0 ~ 3)
                                        //          >> if Value = 0, change the show mode to next one
                                        //          >> else , select the specific show mode as fallow table
                                        //          >>          0x01 - Show 1
                                        //          >>          0x02 - Show 2
                                        //          >>          0x03 - Show 3
                                        
    CMD_TIMER_SET           = 0x35,     // Set timer
                                        // len = 1  >> Value (2, 4, 6, 8) as set 2/4/6/8 hours timer
    
	
	CMD_MAX
}UART_Cmd_T;


//-------------------< Exported Functions >------------------------
void USART_Data_Init(void);
void Csr1010_Snd_Data(void);
void Csr1010_Rcv_Data(void);
void Wifi_Snd_Data(void);
void Wifi_Rcv_Data(void);
	

//-------------------< File Functions >----------------------------
static void USART0_Rcv_Byte(void);
static void USART1_Rcv_Byte(void);
static void USART0_Snd_Byte(_Uint8 SndBuf);
static void USART1_Snd_Byte(_Uint8 SndBuf);


/***
	* @Brief Exported Variables
	*/
extern _TypeStructRcv 		RcvData[2];
extern _TypeStructSnd 		SndData[2];
extern _Flag				      RcvFlag[2];


#endif
