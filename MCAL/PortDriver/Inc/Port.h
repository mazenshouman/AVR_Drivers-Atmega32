/*
 *  File 	   : Port.h
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef PORTDRIVER_INC_PORT_H_
#define PORTDRIVER_INC_PORT_H_


#include "Port_Cfg.h"
/************************************************************************
 *                           Error macros                               *
 ************************************************************************/
typedef uint8 Port_ErrorStatus_t;
#define E_OK                         (Port_ErrorStatus_t)0
#define E_NOT_OK                     (Port_ErrorStatus_t)1
#define PORT_PULL_UP_RES_WRONG_USE   (Port_ErrorStatus_t)2
#define PORT_PIN_NUMBER_OUT_OF_RANGE (Port_ErrorStatus_t)3

/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/

typedef uint8 Port_PortType;
#define PORTD                 (Port_PortType)0
#define PORTC                 (Port_PortType)1
#define PORTB                 (Port_PortType)2
#define PORTA                 (Port_PortType)3

/************************************************************************/

/************************************************************************
 *                    PORT functions' prototypes                        *
 ************************************************************************/

/**************************************************************************************************************************************
 *  Function : Port_Init                                                                                                        *
 *  Param    : IN     : Name / None                                                                                                   *
 *                      Type / void                                                                                                   *
 *                      Desc / None                                                                                                   *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : ErrorStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function uses linking configuration structure to configure pins define in                                         *
 *             PORT_LCFG and externed here to configure pins                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Port_ErrorStatus_t Port_Init(void);

#if PortSetPinDirectionApi
Port_ErrorStatus_t Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);
#endif

#endif /* PORTDRIVER_INC_PORT_H_ */
