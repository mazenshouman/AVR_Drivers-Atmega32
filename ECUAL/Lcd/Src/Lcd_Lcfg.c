/*
 *  File 	   : Lcd_Lcfg.c
 *  Created on : April 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_types.h"
#include "Dio_Lcfg.h"
#include "Dio.h"
#include "Lcd_Wrapper.h"
#include "Lcd_Cfg.h"
#include "Lcd.h"
#include "Lcd_Lcfg.h"

/************************************************************************
 *      creating instance and initializing configuration structure      *
 ************************************************************************/

Lcd_ConfigType gastr_LcdConfigArr[LCD_NUMBER_OF_CONFIGURED_KEYPADS]=
{
		/*                                                   DataPins                                                                                                      ControlPins                                   CursorOrDiplayShiftCommand                                EntryModeCommand 	                         FunctionSetCommand                                   DisplayContorlCommand        */
		/*First LCD*/
		{ {DIO_CHANNEL_C0 , DIO_CHANNEL_C1 , DIO_CHANNEL_C2 , DIO_CHANNEL_C3 , DIO_CHANNEL_C4 , DIO_CHANNEL_C5 , DIO_CHANNEL_C6 , DIO_CHANNEL_C7} , {DIO_CHANNEL_D0 , DIO_CHANNEL_D1 , DIO_CHANNEL_D2} ,    (LCD_DISPLAY_OR_CURSOR_SHIFT_LEFT|LCD_DISPLAY_SHIFT) , (LCD_DISPLAY_SHIFT_OFF|LCD_ADDRESS_INCREMENT) , (LCD_FONT_5_8|LCD_TWO_DISPLAY_LINE|LCD_8_BIT_DATA_MODE) ,   (LCD_DISPLAY_ON|LCD_BLINKING_OFF|LCD_CURSOR_ON)   }

		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
};

