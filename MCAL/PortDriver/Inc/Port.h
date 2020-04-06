/*
 *  File 	   : Port.h
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef PORTDRIVER_INC_PORT_H_
#define PORTDRIVER_INC_PORT_H_


/************************************************************************
 *                           Error macros                               *
 ************************************************************************/
typedef uint8 ErrorStatus_t;
#define E_OK 				         (ErrorStatus_t)0
#define E_NOT_OK			         (ErrorStatus_t)1
#define PORT_PULL_UP_RES_WRONG_USE	 (ErrorStatus_t)2

/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/

typedef uint8 Port_PortType;
#define PORTD	              (Port_PortType)0
#define PORTC	              (Port_PortType)1
#define PORTB	              (Port_PortType)2
#define PORTA	              (Port_PortType)3

/************************************************************************/

/************************************************************************
 *                    PORT functions' prototypes                        *
 ************************************************************************/

/**************************************************************************************************************************************
 *  Function : Dio_ReadChannel                                                                                                        *
 *  Param    : IN     : Name / None                                                                                                   *
 *                      Type / void                                                                                                   *
 *                      Desc / None                                                                                                   *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *	Return   : ErrorStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *	Desc     : This function uses linking configuration structure to configure pins define in                                         *
 *				PORT_LCFG and externed here to configure pins                                                                         *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

ErrorStatus_t Port_Init(void);

#if PortSetPinDirectionApi
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);
#endif

#endif /* PORTDRIVER_INC_PORT_H_ */
