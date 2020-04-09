/*
 *  File 	   : PushButton_Lcfg.h
 *  Created on : April 8, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */


#ifndef PUSHBUTTON_INC_PUSHBUTTON_LCFG_H_
#define PUSHBUTTON_INC_PUSHBUTTON_LCFG_H_


/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/

/*
 * this type is used to set the current position of the Push Button in terms of current
 * flow (sinking or sourcing)
 *
 * */
typedef uint8 PushButton_ActiveStateType;
#define PUSHBUTTON_ACTIVE_LOW                                (PushButton_ActiveStateType)0
#define PUSHBUTTON_ACTIVE_HIGH                               (PushButton_ActiveStateType)1

/************************************************************************
 *                      Configuration Structure                         *
 ************************************************************************/

typedef struct{
	PushButton_ChannelType                   PushButton_Channel;
	PushButton_ActiveStateType               PushButton_ActiveState;
}PushButton_ConfigType;

/************************************************************************
 *                      extern for Configuration Structure              *
 ************************************************************************/

extern PushButton_ConfigType gastr_PushButtonConfigArr[];


/************************************************************************/

#endif
