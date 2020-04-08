/*
 *  File 	   : PushButton_Lcfg.h
 *  Created on : April 8, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */


#ifndef PUSHBUTTON_INC_PUSHBUTTON_LCFG_H_
#define PUSHBUTTON_INC_PUSHBUTTON_LCFG_H_


#include "PushButton_Wrapper.h"
#include "PushButton_Cfg.h"
/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/

/*
 * states used in case of real time usage or periodic check on the switch
 * */

typedef uint8 PushButton_StateType;
#define PUSHBUTTON_RELESED_STATE                           (PushButton_StateType)0
#define PUSHBUTTON_PRE_PRESSED_STATE                       (PushButton_StateType)1
#define PUSHBUTTON_PRESSED_STATE                           (PushButton_StateType)2
#define PUSHBUTTON_PRE_RELEASED_STATE                      (PushButton_StateType)3

/*
 * pointer to function to execute function from upper layer when current state is reached
 * */

typedef void (*PushButton_PtrToFunctionType)(void);


/*
 * this type is used to set the current position of the Push Button in terms of current
 * flow (sinking or sourcing)
 *
 * */
typedef uint8 PushButton_CurrentDirectionType;
#define PushButton_SOURCING                                (PushButton_CurrentDirectionType)0
#define PushButton_SINKING                                 (PushButton_CurrentDirectionType)1

/************************************************************************
 *                      Configuration Structure                         *
 ************************************************************************/
#ifndef PUSHBUTTON_PERIODIC_UPDATE
typedef struct{
	PushButton_ChannelType                   PushButton_Channel;
	PushButton_CurrentDirectionType          PushButton_CurrentDirection;
}PushButton_ConfigType;

#else

typedef struct{
	PushButton_ChannelType                   PushButton_Channel;
	PushButton_CurrentDirectionType          PushButton_CurrentDirection;
	PushButton_StateType					 PushButton_CurrentState;
	PushButton_PtrToFunctionType			 PushButton_ArrPtrToFunction[PUSHBUTTON_NUMBER_OF_STATES];
}PushButton_ConfigType;

#endif
/************************************************************************
 *                      extern for Configuration Structure              *
 ************************************************************************/

extern PushButton_ConfigType gastr_PushButtonConfigArr[];


/************************************************************************/

