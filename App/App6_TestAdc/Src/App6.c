/*
 * App6.c
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
#include "Adc.h"
#include "TempSensor.h"


void App6(void)
{
	Port_Init();
	Adc_Init();
	TempSensor_TempValueSize_t Value;
	while(1)
	{
//		Adc_StartConversion(ADC_ID0 , ADC_SINGLE_ENDED_ADC0 , &Value);
//
//		Dio_WriteChannel(DIO_CHANNEL_B0 , Value>>8);
//		Dio_WriteChannel(DIO_CHANNEL_B1 , Value>>9);
		TempSensor_GetTemperature(TEMPSENSOR_ID0 , &Value);
		Dio_WriteChannel(DIO_CHANNEL_B0 , STD_HIGH);
		Dio_WritePort(DIO_PORTC , Value);
		_delay_ms(1000);
	}
}
