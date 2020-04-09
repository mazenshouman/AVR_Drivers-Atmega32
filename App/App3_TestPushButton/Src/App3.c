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
#include "PushButton_Wrapper.h"
#include "PushButton_Lcfg.h"
#include "PushButton.h"

void App3(void)
{
	Port_Init();
	Led_Init();
	PushButton_StateType currentState;
	while(1)
	{
		PushButton_ReadButtonState(PUSHBUTTON_ID0 , &currentState);
		if(currentState==PUSHBUTTON_PRESSED_STATE)
		{
			Led_Toggle(LED_ID0);
			do{
				PushButton_ReadButtonState(PUSHBUTTON_ID0 , &currentState);
			}
			while(currentState==PUSHBUTTON_PRESSED_STATE);
		}
	}
}
