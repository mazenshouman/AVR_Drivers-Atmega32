/*
 *  File 	   : Port_Lcfg.h
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */


#ifndef PORTDRIVER_INC_PORT_LCFG_H_
#define PORTDRIVER_INC_PORT_LCFG_H_


/************************************************************************
 *				 			Macros And Types                   			*
 ************************************************************************/

typedef uint8 Port_PinType;

#define PORT_CHANNEL_D0				(Port_PinType)0
#define PORT_CHANNEL_D1				(Port_PinType)1
#define PORT_CHANNEL_D2				(Port_PinType)2
#define PORT_CHANNEL_D3				(Port_PinType)3
#define PORT_CHANNEL_D4				(Port_PinType)4
#define PORT_CHANNEL_D5				(Port_PinType)5
#define PORT_CHANNEL_D6				(Port_PinType)6
#define PORT_CHANNEL_D7				(Port_PinType)7

#define PORT_CHANNEL_C0				(Port_PinType)8
#define PORT_CHANNEL_C1				(Port_PinType)9
#define PORT_CHANNEL_C2				(Port_PinType)10
#define PORT_CHANNEL_C3				(Port_PinType)11
#define PORT_CHANNEL_C4				(Port_PinType)12
#define PORT_CHANNEL_C5				(Port_PinType)13
#define PORT_CHANNEL_C6				(Port_PinType)14
#define PORT_CHANNEL_C7				(Port_PinType)15

#define PORT_CHANNEL_B0				(Port_PinType)16
#define PORT_CHANNEL_B1				(Port_PinType)17
#define PORT_CHANNEL_B2				(Port_PinType)18
#define PORT_CHANNEL_B3				(Port_PinType)19
#define PORT_CHANNEL_B4				(Port_PinType)20
#define PORT_CHANNEL_B5				(Port_PinType)21
#define PORT_CHANNEL_B6				(Port_PinType)22
#define PORT_CHANNEL_B7				(Port_PinType)23

#define PORT_CHANNEL_A0				(Port_PinType)24
#define PORT_CHANNEL_A1				(Port_PinType)25
#define PORT_CHANNEL_A2				(Port_PinType)26
#define PORT_CHANNEL_A3				(Port_PinType)27
#define PORT_CHANNEL_A4				(Port_PinType)28
#define PORT_CHANNEL_A5				(Port_PinType)29
#define PORT_CHANNEL_A6				(Port_PinType)30
#define PORT_CHANNEL_A7				(Port_PinType)31


typedef enum{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef enum{
	NO_RES,
	PULL_UP_RES
}Port_PinAttachmentType;


/************************************************************************
 *				 		Configuration Structure 						*
 ************************************************************************/
typedef struct{
	Port_PinType 			Channel_ID:6;
	Port_PinDirectionType	Channel_Direction:1;
	Port_PinAttachmentType	channel_Attachment:1;
}Port_ConfigType;

/************************************************************************
 *				 		Externed Structure instance               		*
 ************************************************************************/

extern Port_ConfigType gastr_ConfigArr[];


/************************************************************************/

#endif /* PORTDRIVER_INC_PORT_LCFG_H_ */
