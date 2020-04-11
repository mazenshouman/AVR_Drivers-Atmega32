/*
 * App3.c
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
#include "Pushbutton_Wrapper.h"
#include "Pushbutton_Cfg.h"
#include "Pushbutton_Lcfg.h"
#include "Pushbutton.h"

void App3(void)
{
	Port_Init();
	Led_Init();
	Pushbutton_StateType currentState;
	while(1)
	{
		Pushbutton_ReadButtonState(PUSHBUTTON_ID0 , &currentState);
		if(currentState==PUSHBUTTON_PRESSED_STATE)
		{
			Led_Toggle(LED_ID0);
			do{
				Pushbutton_ReadButtonState(PUSHBUTTON_ID0 , &currentState);
			}
			while(currentState==PUSHBUTTON_PRESSED_STATE);
		}
	}
}
