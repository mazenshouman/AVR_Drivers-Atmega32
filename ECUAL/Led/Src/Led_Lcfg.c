/*
 *  File 	   : Led_Lcfg.c
 *  Created on : April 8, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */


/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_types.h"
#include "Dio_Lcfg.h"
#include "Dio.h"
#include "Led_Wrapper.h"
#include "Led_Cfg.h"
#include "Led_Lcfg.h"
#include "Led.h"

/************************************************************************
 *      creating instance and initializing configuration structure      *
 ************************************************************************/

Led_ConfigType gastr_LedConfigArr[LED_NUMBER_OF_CONFIGURED_LEDS]=
/*            channel ID                      CurrentDirection                          InitialState*/
{{          DIO_CHANNEL_A0         ,            LED_SOURCING                ,              LED_OFF                },
 {          DIO_CHANNEL_A1         ,            LED_SOURCING                ,              LED_ON                 },
 {          DIO_CHANNEL_A2         ,            LED_SINKING                 ,              LED_OFF                },
 {          DIO_CHANNEL_A3         ,            LED_SINKING                 ,              LED_ON                 }
};





/****************************************************************************/
