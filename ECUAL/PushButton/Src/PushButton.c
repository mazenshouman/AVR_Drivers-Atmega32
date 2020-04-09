/*
 *  File 	   : PushButton.c
 *  Created on : April 9, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */


/************************************************************************
 *                              Includes                                *
 ************************************************************************/
#include "Std_types.h"
#include "Dio_Lcfg.h"
#include "Dio.h"
#include "PushButton_Wrapper.h"
#include "PushButton_Cfg.h"
#include "PushButton_Lcfg.h"
#include "PushButton.h"



/************************************************************************
 *              private structure used to save PushButton status        *
 *                  and their callback functions                        *
 ************************************************************************/

#ifdef PUSHBUTTON_PERIODIC_UPDATE
typedef struct{
	PushButton_StateType					 PushButton_CurrentState;
	PushButton_StateCounterType				 PushButton_StateCounter;
	PushButton_PtrToFunctionType			 PushButton_ArrPtrToFunction[PUSHBUTTON_NUMBER_OF_STATES];
}PushButton_LocalButtonDetailsType;


/************************************************************************
 *                create instance of the local button details           *
 *                               structure                              *
 ************************************************************************/

PushButton_LocalButtonDetailsType     astr_PushButtonDetails[PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS];
#endif
/************************************************************************/

/************************************************************************
 *                     Function's Implementation                        *
 ************************************************************************/

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

PushButton_ErrorStateType PushButton_ReadButtonState(PushButton_IdType PushButton_Id , PushButton_StateType* State)
{

	PushButton_ErrorStateType    returnErrorState=PUSHBUTTON_E_OK;

	/*
	 * check the pointer for null pointer error
	 * */

	if(State == NULL)
	{
		returnErrorState=PUSHBUTTON_NULL_POINTER;
	}
	else
	{
		/*
		 * check if the pushButton ID is out of the limit or not
		 * */

		if(PushButton_Id >= PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS)
		{
			returnErrorState = PUSHBUTTON_ID_OUTOFRANGE;
		}
		else
		{
			/*
			 * read the active type of the pushbutton
			 * */
			switch(gastr_PushButtonConfigArr[PushButton_Id].PushButton_ActiveState)
			{
				/*
				 * return the state of the pushbutton
				 *
				 * */
				case PUSHBUTTON_ACTIVE_LOW:
					if(PushButton_ReadChannel(gastr_PushButtonConfigArr[PushButton_Id].PushButton_Channel)==STD_LOW)
					{
						*State=PUSHBUTTON_PRESSED_STATE;
					}
					else
					{
						*State=PUSHBUTTON_RELEASED_STATE;
					}
					break;
				case PUSHBUTTON_ACTIVE_HIGH:
					if(PushButton_ReadChannel(gastr_PushButtonConfigArr[PushButton_Id].PushButton_Channel)==STD_HIGH)
					{
						*State=PUSHBUTTON_PRESSED_STATE;
					}
					else
					{
						*State=PUSHBUTTON_RELEASED_STATE;
					}
					break;
				default:
					returnErrorState= PUSHBUTTON_ACTIVE_TYPE_IS_NOT_DEFINED;
			}
		}
	}
	return returnErrorState;
}

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

void PushButton_Init(void)
{
	/*
	 * initialize the local structure with the initial values
	 * */
	PushButton_ConfigurationStrSizeType u8_LocalCounter=0;
	uint8 u8_LocalCounterForStates=0;


	for(u8_LocalCounter=0 ; u8_LocalCounter<PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS ; ++u8_LocalCounter)
	{
		astr_PushButtonDetails[u8_LocalCounter].PushButton_CurrentState=PUSHBUTTON_RELEASED_STATE;
		astr_PushButtonDetails[u8_LocalCounter].PushButton_StateCounter=NUMBER_ZERO;
		for(u8_LocalCounterForStates=0 ; u8_LocalCounterForStates<PUSHBUTTON_NUMBER_OF_STATES ; ++u8_LocalCounterForStates)
		{
			astr_PushButtonDetails[u8_LocalCounter].PushButton_ArrPtrToFunction[u8_LocalCounterForStates]=NULL;
		}
	}
}

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

PushButton_ErrorStateType PushButton_GetCurrentState(PushButton_IdType PushButton_Id , PushButton_StateType* State)
{
	PushButton_ErrorStateType    returnErrorState=PUSHBUTTON_E_OK;

	/*
	 * check the pointer for null pointer error
	 * */

	if(State == NULL)
	{
		returnErrorState=PUSHBUTTON_NULL_POINTER;
	}
	else
	{
		/*
		 * check if the pushButton ID is out of the limit or not
		 * */

		if(PushButton_Id >= PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS)
		{
			returnErrorState = PUSHBUTTON_ID_OUTOFRANGE;
		}

		/*
		 * return the current state from the local arr of str
		 * */

		*State=astr_PushButtonDetails[PushButton_Id].PushButton_CurrentState;
	}
	return returnErrorState;
}


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

PushButton_ErrorStateType PushButton_UpdateState(PushButton_IdType PushButton_Id)
{
	PushButton_ErrorStateType    returnErrorState=PUSHBUTTON_E_OK;
	PushButton_ConfigurationStrSizeType u8_LocalCounter=0;
	PushButton_StateType u8_localStateType;

	/*
	 * check if the pushButton ID is out of the limit or not
	 * */

	if(PushButton_Id >= PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS)
	{
		returnErrorState = PUSHBUTTON_ID_OUTOFRANGE;
	}
	else
	{
		/*loop on all switches and check their:
		 * 1-Active Type to determine state
		 * 2-read the current state from the Dio Pin
		 * 3-update the counter or move to the next state
		 * */
		for(u8_LocalCounter=0 ; u8_LocalCounter<PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS ; ++u8_LocalCounter)
		{
			switch(gastr_PushButtonConfigArr[PushButton_Id].PushButton_ActiveState)
			{
				/*
				 * depending on the active type of the switch get the state of it from two states (pressed/notpressed)
				 * save it to local variable as it will be used in the next switch case to determine the action to
				 * be taken (move to the next state or continue on the current state)
				 * */
				case PUSHBUTTON_ACTIVE_LOW:
					if(PushButton_ReadChannel(gastr_PushButtonConfigArr[PushButton_Id].PushButton_Channel)==STD_LOW)
					{
						u8_localStateType=PUSHBUTTON_PRESSED_STATE;
					}
					else
					{
						u8_localStateType=PUSHBUTTON_RELEASED_STATE;
					}
					break;
				case PUSHBUTTON_ACTIVE_HIGH:
					if(PushButton_ReadChannel(gastr_PushButtonConfigArr[PushButton_Id].PushButton_Channel)==STD_HIGH)
					{
						u8_localStateType=PUSHBUTTON_PRESSED_STATE;
					}
					else
					{
						u8_localStateType=PUSHBUTTON_RELEASED_STATE;
					}
					break;
				default:
					returnErrorState= PUSHBUTTON_ACTIVE_TYPE_IS_NOT_DEFINED;
			}
			/*
			 * if there is no error
			 * */
			if(returnErrorState==PUSHBUTTON_E_OK)
			{
				/*
				 * check the current state to update it
				 * */
				switch(astr_PushButtonDetails[PushButton_Id].PushButton_CurrentState)
				{
					case PUSHBUTTON_RELEASED_STATE:
						/*if the push button detected as pressed*/
						if(u8_localStateType==PUSHBUTTON_PRESSED_STATE)
						{
							/*increase counter*/
							++astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter;
							/*check if the counter reached the number of counts needed to move to the next state*/
							if(astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter>=PUSHBUTTON_COUNTER_VALUE)
							{
								/*
								 * if there is function to be executed for the next state lunch it
								 * */
								if(astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_PRE_PRESSED_STATE]!=NULL)
								{
									astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_PRE_PRESSED_STATE]();
								}
								/*
								 * then change the current state to the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_CurrentState = PUSHBUTTON_PRE_PRESSED_STATE;
								/*
								 *reset the counter of the state to start from zero for the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
							}
						}
						/*
						 * if the pushbutton state was released then start from beginning for this state
						 * */
						else
						{
							astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
						}
						break;
					case PUSHBUTTON_PRE_PRESSED_STATE:
						/*if the push button detected as pressed*/
						if(u8_localStateType==PUSHBUTTON_PRESSED_STATE)
						{
							/*increase counter*/
							++astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter;
							/*check if the counter reached the number of counts needed to move to the next state*/
							if(astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter>=PUSHBUTTON_COUNTER_VALUE)
							{
								/*
								 * if there is function to be executed here lunch it
								 * */
								if(astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_PRESSED_STATE]!=NULL)
								{
									astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_PRESSED_STATE]();
								}
								/*
								 * then change the current state to the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_CurrentState = PUSHBUTTON_PRESSED_STATE;
								/*
								 *reset the counter of the state to start from zero for the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
							}
						}
						/*
						 * if the pushbutton state was released then start from beginning for this state
						 * */
						else
						{
							astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
						}
						break;
					case PUSHBUTTON_PRESSED_STATE:
						/*if the push button detected as Released*/
						if(u8_localStateType==PUSHBUTTON_RELEASED_STATE)
						{
							/*increase counter*/
							++astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter;
							/*check if the counter reached the number of counts needed to move to the next state*/
							if(astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter>=PUSHBUTTON_COUNTER_VALUE)
							{
								/*
								 * if there is function to be executed here lunch it
								 * */
								if(astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_PRE_RELEASED_STATE]!=NULL)
								{
									/*the function must be as small as possible for performance and accuracy wise*/
									astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_PRE_RELEASED_STATE]();
								}
								/*
								 * then change the current state to the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_CurrentState = PUSHBUTTON_PRE_RELEASED_STATE;
								/*
								 *reset the counter of the state to start from zero for the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
							}
						}
						/*
						 * if the pushbutton state was released then start from beginning for this state
						 * */
						else
						{
							astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
						}
						break;
					case PUSHBUTTON_PRE_RELEASED_STATE:
						/*if the push button detected as Released*/
						if(u8_localStateType==PUSHBUTTON_RELEASED_STATE)
						{
							/*increase counter*/
							++astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter;
							/*check if the counter reached the number of counts needed to move to the next state*/
							if(astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter>=PUSHBUTTON_COUNTER_VALUE)
							{
								/*
								 * if there is function to be executed here lunch it
								 * */
								if(astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_RELEASED_STATE]!=NULL)
								{
									/*the function must be as small as possible for performance and accuracy wise*/
									astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[PUSHBUTTON_RELEASED_STATE]();
								}
								/*
								 * then change the current state to the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_CurrentState = PUSHBUTTON_RELEASED_STATE;
								/*
								 *reset the counter of the state to start from zero for the next state
								 * */
								astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
							}
						}
						/*
						 * if the pushbutton state was released then start from beginning for this state
						 * */
						else
						{
							astr_PushButtonDetails[PushButton_Id].PushButton_StateCounter=0;
						}
						break;
					default:
						/*no error can be happened here*/
						break;
				}
			}
		}

	}
	return returnErrorState;
}

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

PushButton_ErrorStateType PushButton_SetCallBackFunction(PushButton_IdType PushButton_Id , PushButton_PtrToFunctionType PtrToFunction  , PushButton_StateType  State)
{
	PushButton_ErrorStateType    returnErrorState=PUSHBUTTON_E_OK;

	/*
	 * check the pointer for null pointer error
	 * */

	if(PtrToFunction==NULL)
	{
		returnErrorState=PUSHBUTTON_NULL_POINTER;
	}
	else
	{
		/*
		 * check if the pushButton ID is out of the limit or not
		 * */

		if(PushButton_Id >= PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS)
		{
			returnErrorState = PUSHBUTTON_ID_OUTOFRANGE;
		}
		else
		{
			/*
			 * check the given state if it was in range or undefined
			 * */
			if(State<PUSHBUTTON_RELEASED_STATE || State>=PUSHBUTTON_NUMBER_OF_STATES)
			{
				returnErrorState=PUSHBUTTON_UNDEFINED_STATE;
			}
			else
			{
				/*
				 * add pointer to function to the array
				 * */
				astr_PushButtonDetails[PushButton_Id].PushButton_ArrPtrToFunction[State]=PtrToFunction;
			}
		}
	}
	return returnErrorState;
}

#endif
