/*
 * App4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */


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
#include "Keypad_Lcfg.h"
#include "Keypad.h"



void App4(void)
{
	Port_Init();
	Led_Init();
	Keypad_Init();

	keypad_OutputDataType  key;
	while(1)
	{
		Keypad_GetKeyAfterRelease(KEYPAD_ID0 , &key);
		if(key=='1')
		{
			Led_Toggle(LED_ID0);
		}
		else if(key=='2')
		{
			Led_Toggle(LED_ID1);
		}
	}
}
