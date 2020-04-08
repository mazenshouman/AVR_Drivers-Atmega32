/*
 *  File 	   : Led.Cfg.h
 *  Created on : April 8, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef LED_INC_LED_CFG_H_
#define LED_INC_LED_CFG_H_


/************************************************************************
 *                      Configuration macros                            *
 ************************************************************************/
/*
 * this configuration parameter used to determine the number of switches that
 * will be configured in the Led_Lcfg.c file (array of structure)
 * */

typedef uint8 Led_ConfigurationStrSizeType;
#define LED_NUMBER_OF_CONFIGURED_LEDS			(Led_ConfigurationStrSizeType)4


/************************************************************************/


#endif /* LED_INC_LED_CFG_H_ */
