/*
 *  File 	   : PushButton.h
 *  Created on : April 9, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef PUSHBUTTON_INC_PUSHBUTTON_H_
#define PUSHBUTTON_INC_PUSHBUTTON_H_


/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/

typedef uint8 PushButton_IdType;
#define PUSHBUTTON_ID0                                     (PushButton_IdType)0
#define PUSHBUTTON_ID1                                     (PushButton_IdType)1
#define PUSHBUTTON_ID2                                     (PushButton_IdType)2
#define PUSHBUTTON_ID3                                     (PushButton_IdType)3
#define PUSHBUTTON_ID4                                     (PushButton_IdType)4
#define PUSHBUTTON_ID5                                     (PushButton_IdType)5
#define PUSHBUTTON_ID6                                     (PushButton_IdType)6
#define PUSHBUTTON_ID7                                     (PushButton_IdType)7
#define PUSHBUTTON_ID8                                     (PushButton_IdType)8
#define PUSHBUTTON_ID9                                     (PushButton_IdType)9
#define PUSHBUTTON_ID10                                    (PushButton_IdType)10
#define PUSHBUTTON_ID11                                    (PushButton_IdType)11
#define PUSHBUTTON_ID12                                    (PushButton_IdType)12
#define PUSHBUTTON_ID13                                    (PushButton_IdType)13
#define PUSHBUTTON_ID14                                    (PushButton_IdType)14
#define PUSHBUTTON_ID15                                    (PushButton_IdType)15
#define PUSHBUTTON_ID16                                    (PushButton_IdType)16
#define PUSHBUTTON_ID17                                    (PushButton_IdType)17
#define PUSHBUTTON_ID18                                    (PushButton_IdType)18
#define PUSHBUTTON_ID19                                    (PushButton_IdType)19
#define PUSHBUTTON_ID20                                    (PushButton_IdType)20
#define PUSHBUTTON_ID21                                    (PushButton_IdType)21
#define PUSHBUTTON_ID22                                    (PushButton_IdType)22
#define PUSHBUTTON_ID23                                    (PushButton_IdType)23
#define PUSHBUTTON_ID24                                    (PushButton_IdType)24
#define PUSHBUTTON_ID25                                    (PushButton_IdType)25
#define PUSHBUTTON_ID26                                    (PushButton_IdType)26
#define PUSHBUTTON_ID27                                    (PushButton_IdType)27
#define PUSHBUTTON_ID28                                    (PushButton_IdType)28
#define PUSHBUTTON_ID29                                    (PushButton_IdType)29
#define PUSHBUTTON_ID30                                    (PushButton_IdType)30
#define PUSHBUTTON_ID31                                    (PushButton_IdType)31
#define PUSHBUTTON_ID32                                    (PushButton_IdType)32
#define PUSHBUTTON_ID33                                    (PushButton_IdType)33
#define PUSHBUTTON_ID34                                    (PushButton_IdType)34
#define PUSHBUTTON_ID35                                    (PushButton_IdType)35
#define PUSHBUTTON_ID36                                    (PushButton_IdType)36
#define PUSHBUTTON_ID37                                    (PushButton_IdType)37
#define PUSHBUTTON_ID38                                    (PushButton_IdType)38
#define PUSHBUTTON_ID39                                    (PushButton_IdType)39
#define PUSHBUTTON_ID40                                    (PushButton_IdType)40

/*
 * Error state macros
 * */
typedef uint8 PushButton_ErrorStateType;
#define PUSHBUTTON_E_OK                                    (PushButton_ErrorStateType)0
#define PUSHBUTTON_E_NOT_OK                                (PushButton_ErrorStateType)1
#define PUSHBUTTON_ID_OUTOFRANGE                           (PushButton_ErrorStateType)2
#define PUSHBUTTON_ACTIVE_TYPE_IS_NOT_DEFINED              (PushButton_ErrorStateType)3
#define PUSHBUTTON_NULL_POINTER                            (PushButton_ErrorStateType)4
#define PUSHBUTTON_UNDEFINED_STATE                         (PushButton_ErrorStateType)5


#ifdef PUSHBUTTON_PERIODIC_UPDATE

/*
 * states used in case of real time usage or periodic check on the switch
 * */

typedef uint8 PushButton_StateType;
#define PUSHBUTTON_RELEASED_STATE                           (PushButton_StateType)0
#define PUSHBUTTON_PRE_PRESSED_STATE                       (PushButton_StateType)1
#define PUSHBUTTON_PRESSED_STATE                           (PushButton_StateType)2
#define PUSHBUTTON_PRE_RELEASED_STATE                      (PushButton_StateType)3

/*
 * pointer to function to execute function from upper layer when current state is reached
 * */

typedef void (*PushButton_PtrToFunctionType)(void);


#else

typedef uint8 PushButton_StateType;
#define PUSHBUTTON_RELEASED_STATE                          (PushButton_StateType)0
#define PUSHBUTTON_PRESSED_STATE                           (PushButton_StateType)2

#endif

/************************************************************************/

/************************************************************************
 *                    PushButton functions' prototype                   *
 ************************************************************************/

/*
 * uses configuration parameter to enable periodic check functions or use just the normal read state funciton
 * for super loop systems
 * */
#ifndef PUSHBUTTON_PERIODIC_UPDATE

/**************************************************************************************************************************************
 *  Function : PushButton_ReadButtonLevel                                                                                             *
 *  Param    : IN     : Name / PushButton_Id                                                                                          *
 *                      Type / PushButton_IdType                                                                                      *
 *                      Desc / predefine macro for PushButton id                                                                      *
 *                                                                                                                                    *
 *             Output : Name / State                                                                                                  *
 *                      Type / PushButton_StateType*                                                                                  *
 *                      Desc / this pointer is used to return state to the caller function through pointer (pressed or released)      *
 *                                                                                                                                    *
 *  Return   : PushButton_ErrorStateType                                                                                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function reads the current level of the button and return the obtained level(used in                              *
 *             one time get value not on periodic matter) return only two states (pressed or released)                                *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

PushButton_ErrorStateType PushButton_ReadButtonState(PushButton_IdType PushButton_Id , PushButton_StateType* State);

#else

/**************************************************************************************************************************************
 *  Function : PushButton_Init                                                                                                        *
 *  Param    : IN     : Name / none                                                                                                   *
 *                      Type / void                                                                                                   *
 *                      Desc / none                                                                                                   *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : none                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function initialize the local structure used to store details for each switch used with periodic                  *
 *             update configuration                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void PushButton_Init(void);

/**************************************************************************************************************************************
 *  Function : PushButton_GetCurrentState                                                                                             *
 *  Param    : IN     : Name / PushButton_Id                                                                                          *
 *                      Type / PushButton_IdType                                                                                      *
 *                      Desc / predefine macro for PushButton id                                                                      *
 *                                                                                                                                    *
 *             Output : Name / State                                                                                                  *
 *                      Type / PushButton_StateType*                                                                                  *
 *                      Desc / this pointer is used to return current state to the caller function through pointer                    *
 *                                                                                                                                    *
 *  Return   : PushButton_ErrorStateType                                                                                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the current state for the selected Push Button used in periodic check systems                     *
 *             returns on of the four states of the switch                                                                            *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

PushButton_ErrorStateType PushButton_GetCurrentState(PushButton_IdType PushButton_Id , PushButton_StateType* State);

/**************************************************************************************************************************************
 *  Function : PushButton_GetCurrentState                                                                                             *
 *  Param    : IN     : Name / PushButton_Id                                                                                          *
 *                      Type / PushButton_IdType                                                                                      *
 *                      Desc / predefine macro for PushButton id                                                                      *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : PushButton_ErrorStateType                                                                                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function used with periodic calls to update the state of certain switch                                           *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

PushButton_ErrorStateType PushButton_UpdateState(PushButton_IdType PushButton_Id);

/**************************************************************************************************************************************
 *  Function : PushButton_SetCallBackFunction                                                                                         *
 *  Param    : IN     : Name / PushButton_Id                                                                                          *
 *                      Type / PushButton_IdType                                                                                      *
 *                      Desc / predefine macro for PushButton id                                                                      *
 *                                                                                                                                    *
 *                      Name / PtrToFunction                                                                                          *
 *                      Type / PushButton_PtrToFunctionType                                                                           *
 *                      Desc / takes Pointer to function which wanted to be executed when certain state is reached                    *
 *                                                                                                                                    *
 *                      Name / State                                                                                                  *
 *                      Type / PushButton_StateType                                                                                   *
 *                      Desc / predefine macro for PushButton state                                                                   *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : PushButton_ErrorStateType                                                                                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function used with periodic calls to set callback functions for PushButton for certain state                      *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

PushButton_ErrorStateType PushButton_SetCallBackFunction(PushButton_IdType PushButton_Id , PushButton_PtrToFunctionType PtrToFunction  , PushButton_StateType  State);


#endif
/**************************************************************************************************************************************/


#endif /* PUSHBUTTON_INC_PUSHBUTTON_H_ */
