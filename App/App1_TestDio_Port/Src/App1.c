/*
 * App1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */

#include <util/delay.h>
#include "Bit_Math.h"
#include "Std_Types.h"
#include "Port_MemMap.h"
#include "Port_Lcfg.h"
#include "Port.h"
#include "Dio.h"



void App1(void){
	Port_Init();
	Dio_WritePort(DIO_PORTB , 0xF0);
	Dio_WriteChannel(DIO_CHANNEL_A5, STD_HIGH);
	Dio_ChannelGroupType newChannel = {0x1E,0x01,DIO_PORTC};
	Dio_WriteChannelGroup(&newChannel , 0x0F);

	while(1){
		if(!Dio_ReadPort(DIO_PORTD)){
			_delay_ms(1000);
			Dio_FlipChannel(DIO_CHANNEL_A0);
		}
	}
}









