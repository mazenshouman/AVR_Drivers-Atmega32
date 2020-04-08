/*
 * App2.c
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


void App2(void)
{
	Port_Init();
	Led_Init();
	Led_Toggle(LED_ID2);
	while(1)
	{

	}
}
