/********************************************************************
	*
	* FILE NAME
	*									Data_Process.c
	* DATE
	*									01 NOV. 2017
	* AUTHOR			
	*									DS.Chin
	* DESCRIPTION
	*									Data Process
	*
*********************************************************************/
#include "Data_Process.h"


/*
 * Color Vector Table
 */
const _Uint8 COLOR_VECTOR[18][3] =
{
    250,0,0,      		//0:red
    0,250,0,      		//1:green 
    0,0,250,      		//2:blue
    250,50,0,     		//3:orange
    250,50,100,   		//4:pink
    0,250,50,     		//5:spring green
    250,150,0,    		//6:gold
    250,0,50,     		//7:peach
    150,250,0,    		//8:lawn green
    250,0,250,    		//9:Cyan
    0,250,250,    		//a:sky blue
    250,250,0,    		//b:yellow
    150,0,250,     		//c:purple
		250,250,250,			//d:pure white
    150,250,250,  		//e: cold white
		250,250,50,				//f:warm white
		0,150,0,					// dark green
		50,0,100,					// DARK_RED
};


/*
 * FunctionName		User_Data_Init
 */
void User_Data_Init(void)
{
	DisplayData.Mode 				= 0x4;
	DisplayData.InitFlag 		= TRUE;
}


/*
 * FunctionName		Data_Process
 */
void Data_Process(void)
{
	_Uint8 TempVar = 0;
	
	//-------------------------------------------------------------
	// Key Data Process
	if (KeyStatus != KEY_IDLE)
	{
		switch (KeyStatus)
		{
			case KEY_IDLE:			break;
			
			/* Christmas */
			case KEY_SHOW_ONE:
			{
						if (DisplayData.Mode == 0x2)
						{
							DisplayData.Mode = 0x0;
						}
						else
						{
							DisplayData.Mode = 0x2;
							ColorNum = 12;
							for (TempVar = 0; TempVar < 16; TempVar++)
							{
								if ( (TempVar % 3) == 0)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[RED][0];
									ColorData[TempVar][1] = COLOR_VECTOR[RED][1];
									ColorData[TempVar][2] = COLOR_VECTOR[RED][2];
								}
								else
								if ((TempVar % 3) == 1)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[GREEN][0];
									ColorData[TempVar][1] = COLOR_VECTOR[GREEN][1];
									ColorData[TempVar][2] = COLOR_VECTOR[GREEN][2];
								}
								else
								if ((TempVar % 3) == 2)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[WHITE][0];
									ColorData[TempVar][1] = COLOR_VECTOR[WHITE][1];
									ColorData[TempVar][2] = COLOR_VECTOR[WHITE][2];
								}
							}
						}
						DisplayData.InitFlag		= TRUE;
						
						KeyStatus = KEY_IDLE;
			} break;
			
			/* Christmas */
			case KEY_SHOW_TWO:
			{
						if (DisplayData.Mode == 0x3)
						{
							DisplayData.Mode = 0x0;
						}
						else
						{
							DisplayData.Mode 				= 0x3;
							ColorNum = 12;
							for (TempVar = 0; TempVar < 16; TempVar++)
							{
								if ( (TempVar % 3) == 0)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[RED][0];
									ColorData[TempVar][1] = COLOR_VECTOR[RED][1];
									ColorData[TempVar][2] = COLOR_VECTOR[RED][2];
								}
								else
								if ((TempVar % 3) == 1)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[GREEN][0];
									ColorData[TempVar][1] = COLOR_VECTOR[GREEN][1];
									ColorData[TempVar][2] = COLOR_VECTOR[GREEN][2];
								}
								else
								if ((TempVar % 3) == 2)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[WHITE][0];
									ColorData[TempVar][1] = COLOR_VECTOR[WHITE][1];
									ColorData[TempVar][2] = COLOR_VECTOR[WHITE][2];
								}
							}
						}
						DisplayData.InitFlag		= TRUE;
						
						KeyStatus = KEY_IDLE;
			} break;
			
			/* Independence Day*/
			case KEY_SHOW_THREE:
			{
						if (DisplayData.Mode == 0x1)
						{
							DisplayData.Mode = 0x0;
						}
						else
						{
							DisplayData.Mode 	= 0x1;
							ColorNum = 12;
							for (TempVar = 0; TempVar < 16; TempVar++)
							{
								if ((TempVar % 3) == 0)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[RED][0];
									ColorData[TempVar][1] = COLOR_VECTOR[RED][1];
									ColorData[TempVar][2] = COLOR_VECTOR[RED][2];
								}
								else if ((TempVar % 3) == 1)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[BLUE][0];
									ColorData[TempVar][1] = COLOR_VECTOR[BLUE][1];
									ColorData[TempVar][2] = COLOR_VECTOR[BLUE][2];
								}
								else if ( (TempVar % 3) == 2)
								{
									ColorData[TempVar][0] = COLOR_VECTOR[COLD_WHITE][0];
									ColorData[TempVar][1] = COLOR_VECTOR[COLD_WHITE][1];
									ColorData[TempVar][2] = COLOR_VECTOR[COLD_WHITE][2];
								}
							}
						}
						DisplayData.InitFlag		= TRUE;
						
						KeyStatus = KEY_IDLE;
			} break;
			
			
			case KEY_SHOW_FOUR:
			{
						DisplayData.Mode	= 0x4;
						DisplayData.InitFlag = TRUE;
						KeyStatus = KEY_IDLE;
			} break;
		}
	}
	
	
	
	//-----------------------------------------------------------------
	// Display
	switch (DisplayData.Mode)
	{
		case 0:		All_Off();					break;
		case 1:		Show_1();						break;
		case 2:		Show_2();						break;
		case 3:		Show_3();						break;
		case 4:		Power_On();					break;
	}
}



 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


