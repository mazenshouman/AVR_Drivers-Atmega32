/*
 *  File 	   : Led.Cfg.h
 *  Created on : April 8, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef PUSHBUTTON_INC_PUSHBUTTON_CFG_H_
#define PUSHBUTTON_INC_PUSHBUTTON_CFG_H_

/************************************************************************
 *                      Configuration macros                            *
 ************************************************************************/
/*
 * this configuration parameter used to determine the number of PushButtons that
 * will be configured in the PushButton_Lcfg.c file (array of structures)
 * */

typedef uint8 PushButton_ConfigurationStrSizeType;
#define PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS			(PushButton_ConfigurationStrSizeType)1



/*
 * this parameter will change the behaviour of the function depending if we have
 * want to use this driver for periodic update (RTOS/Timer) or not
 *
 * */

/*#define PUSHBUTTON_PERIODIC_UPDATE*/

/*
 * this parameter used as array of pointers to function size in configuration structure
 *
 * */

#ifdef PUSHBUTTON_PERIODIC_UPDATE
#define PUSHBUTTON_NUMBER_OF_STATES                     4

/*
 * this parameter is used as number of checks done in each state to check the correctness of the state
 * (number of check per state)depending on its value the periodic time must change
 * if it was configured as 1 then to check the switch full states it will take 4 cycles only
 * */
typedef uint8 PushButton_StateCounterType;
#define PUSHBUTTON_COUNTER_VALUE                        2

#endif
/************************************************************************/

#endif /* PUSHBUTTON_INC_PUSHBUTTON_CFG_H_ */
