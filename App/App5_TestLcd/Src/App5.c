/*
 * App5.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */

#include <util/delay.h>
#include "Std_types.h"
#include "Port_Lcfg.h"
#include "Port.h"
#include "Dio_Lcfg.h"
#include "Dio.h"
#include "Led_Wrapper.h"
#include "Led_Lcfg.h"
#include "Led.h"
#include "Keypad_Wrapper.h"
#include "Keypad_Cfg.h"
#include "Keypad.h"
#include "Lcd_Wrapper.h"
#include "Lcd_Cfg.h"
#include "Lcd.h"



void App5(void)
{
	Port_Init();
	Led_Init();
	Keypad_Init();
	Lcd_Init();

	keypad_OutputDataType  key;
	while(1)
	{
		Keypad_GetKeyAfterRelease(KEYPAD_ID0 , &key);
		if(key=='1')
		{
			Led_Toggle(LED_ID0);
			Lcd_Write(LCD_ID0 , LCD_WRITE_DATA , 'A');
		}
		else if(key=='2')
		{
			Led_Toggle(LED_ID1);
		}
	}


}
