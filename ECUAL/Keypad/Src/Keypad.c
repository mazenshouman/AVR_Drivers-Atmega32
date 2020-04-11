/*
 *  File 	   : Keypad.c
 *  Created on : April 11, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/
#include "Std_types.h"
#include "Dio_Lcfg.h"
#include "Dio.h"
#include "keypad_Wrapper.h"
#include "keypad_Cfg.h"
#include "keypad_Lcfg.h"
#include "keypad.h"



/************************************************************************
 *              private structure used to save keypad status            *
 ************************************************************************/
#ifdef KEYPAD_PERIODIC_UPDATE
typedef struct{
	Keypad_StateType					 Keypad_CurrentState;
	Keypad_StateCounterType				 Keypad_StateCounter;
}Keypad_LocalDetailsType;


/************************************************************************
 *                create instance of the local Keypad details           *
 *                               structure                              *
 ************************************************************************/

static Keypad_LocalDetailsType     astr_KeypadDetails[KEYPAD_NUMBER_OF_CONFIGURED_KEYPADS][KEYPAD_NUMBER_OF_ROWS][KEYPAD_NUMBER_OF_COLUMNS];
#endif
/************************************************************************/

/************************************************************************/

/************************************************************************
 *                     Function's Implementation                        *
 ************************************************************************/

/**************************************************************************************************************************************
 *  Function : Keypad_Init                                                                                                            *
 *  Param    : IN     : Name / none                                                                                                   *
 *                      Type / void                                                                                                   *
 *                      Desc / none                                                                                                   *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : none                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function initialize the output pins with high value and if the periodic check function is activated then          *
 *             it will init the local array which holds the states of the keys                                                        *                                           *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void Keypad_Init(void)
{
	Keypad_NumberOfPinsType u8_localCounterForId=0;
	Keypad_NumberOfPinsType u8_localCounterForRows=0;
#ifdef PUSHBUTTON_PERIODIC_UPDATE
	Keypad_NumberOfPinsType u8_localCounterForColumns=0;
#endif
	/*
	 * set output pins as high as initial value(Rows)
	 * */
	for(u8_localCounterForId=0 ; u8_localCounterForId<KEYPAD_NUMBER_OF_CONFIGURED_KEYPADS ; ++u8_localCounterForId)
	{
		for(u8_localCounterForRows=0 ; u8_localCounterForRows<KEYPAD_NUMBER_OF_ROWS ; ++u8_localCounterForRows)
		{

			Keypad_WriteChannel(gastr_KeypadConfigArr[u8_localCounterForId].Keypad_RowsChannelArr[u8_localCounterForRows],STD_HIGH);
		}
	}

#ifdef PUSHBUTTON_PERIODIC_UPDATE
	/*
	 * initialize the local state array if the periodic configuration parameter is activated
	 * */
	for(u8_localCounterForId=0 ; u8_localCounterForId<KEYPAD_NUMBER_OF_CONFIGURED_KEYPADS ; ++u8_localCounterForId)
	{
		for(u8_localCounterForRows=0 ; u8_localCounterForRows<KEYPAD_NUMBER_OF_ROWS ; ++u8_localCounterForRows)
		{
			for(u8_localCounterForColumns=0 ; u8_localCounterForColumns<KEYPAD_NUMBER_OF_COLUMNS ; ++u8_localCounterForColumns)
			{
				astr_KeypadDetails[u8_localCounterForId][u8_localCounterForRows][u8_localCounterForColumns]=KEYPAD_RELEASED_STATE;
			}
		}
	}
#endif
}

/**************************************************************************************************************************************
 *  Function : Keypad_GetKey                                                                                                          *
 *  Param    : IN     : Name / Keypad_Id                                                                                              *
 *                      Type / Keypad_IdType                                                                                          *
 *                      Desc / predefine macro for Keypad id                                                                          *
 *                                                                                                                                    *
 *             Output : Name / data                                                                                                   *
 *                      Type / keypad_OutputDataType*                                                                                 *
 *                      Desc / this pointer is used to return the data corresponding to the pressed key                               *
 *                                                                                                                                    *
 *  Return   : Keypad_ErrorStateType                                                                                                  *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return data corresponding to the pressed key if there is key pressed and it                              *
 *             won't block the system if there is no key pressed then this function will return pre-configured                        *
 *             symbol                                                                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Keypad_ErrorStateType Keypad_GetKey(Keypad_IdType  Keypad_Id , keypad_OutputDataType* data)
{
	Keypad_ErrorStateType returnState=KEYPAD_E_OK;
	Keypad_NumberOfPinsType u8_localCounterForRows=0;
	Keypad_NumberOfPinsType u8_localCounterForColumns=0;
	if(Keypad_Id>KEYPAD_NUMBER_OF_CONFIGURED_KEYPADS || Keypad_Id<0){
		returnState=KEYPAD_ID_OUTOFRANGE;
	}
	else
	{
		if(data==NULL)
		{
			returnState=KEYPAD_NULL_POINTER;
		}
		else
		{
			/*
			 * initialize the return variable with the preconfigured symbol so as if no key is pressed
			 * it will be returned to the caller function
			 * */
			*data=KEYPAD_NO_KEY_IS_PRESSED;

			for(u8_localCounterForRows=0 ; u8_localCounterForRows<KEYPAD_NUMBER_OF_ROWS ; ++u8_localCounterForRows)
			{
				/*
				 * set the each row to low with keeping all other rows as output high
				 * */
				Keypad_WriteChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_RowsChannelArr[u8_localCounterForRows],STD_LOW);
				/*
				 * check if any key is pressed by checking all input pins for low value
				 * */
				for(u8_localCounterForColumns=0 ; u8_localCounterForColumns<KEYPAD_NUMBER_OF_COLUMNS ; ++u8_localCounterForColumns)
				{
					if(Keypad_ReadChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_ColumnsChannelArr[u8_localCounterForColumns])==STD_LOW)
					{
						*data=gastr_KeypadConfigArr[Keypad_Id].Keypad_ArrOutputCharacters[u8_localCounterForRows][u8_localCounterForColumns];
						Keypad_WriteChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_RowsChannelArr[u8_localCounterForRows],STD_HIGH);
						break;
					}
				}
				Keypad_WriteChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_RowsChannelArr[u8_localCounterForRows],STD_HIGH);
			}
		}
	}
	return returnState;
}

/**************************************************************************************************************************************
 *  Function : Keypad_GetKeyAfterRelease                                                                                              *
 *  Param    : IN     : Name / Keypad_Id                                                                                              *
 *                      Type / Keypad_IdType                                                                                          *
 *                      Desc / predefine macro for Keypad id                                                                          *
 *                                                                                                                                    *
 *             Output : Name / data                                                                                                   *
 *                      Type / keypad_OutputDataType*                                                                                 *
 *                      Desc / this pointer is used to return the data corresponding to the pressed key                               *
 *                                                                                                                                    *
 *  Return   : Keypad_ErrorStateType                                                                                                  *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return data corresponding to the pressed key if there is key pressed and it                              *
 *             will block the system until the key is released. if there is no key pressed then this function will                    *
 *             return pre-configured symbol                                                                                           *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Keypad_ErrorStateType Keypad_GetKeyAfterRelease(Keypad_IdType  Keypad_Id , keypad_OutputDataType* data)
{
	Keypad_ErrorStateType returnState=KEYPAD_E_OK;
	Keypad_NumberOfPinsType u8_localCounterForRows=0;
	Keypad_NumberOfPinsType u8_localCounterForColumns=0;
	if(Keypad_Id>KEYPAD_NUMBER_OF_CONFIGURED_KEYPADS || Keypad_Id<0){
		returnState=KEYPAD_ID_OUTOFRANGE;
	}
	else
	{
		if(data==NULL)
		{
			returnState=KEYPAD_NULL_POINTER;
		}
		else
		{
			/*
			 * initialize the return variable with the preconfigured symbol so as if no key is pressed
			 * it will be returned to the caller function
			 * */
			*data=KEYPAD_NO_KEY_IS_PRESSED;

			for(u8_localCounterForRows=0 ; u8_localCounterForRows<KEYPAD_NUMBER_OF_ROWS ; ++u8_localCounterForRows)
			{
				/*
				 * set the each row to low with keeping all other rows as output high
				 * */
				Keypad_WriteChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_RowsChannelArr[u8_localCounterForRows],STD_LOW);
				/*
				 * check if any key is pressed by checking all input pins for low value
				 * */
				for(u8_localCounterForColumns=0 ; u8_localCounterForColumns<KEYPAD_NUMBER_OF_COLUMNS ; ++u8_localCounterForColumns)
				{
					if(Keypad_ReadChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_ColumnsChannelArr[u8_localCounterForColumns])==STD_LOW)
					{
						/*
						 * block the system until the key is released
						 * */
						while(Keypad_ReadChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_ColumnsChannelArr[u8_localCounterForColumns])==STD_HIGH);
						*data=gastr_KeypadConfigArr[Keypad_Id].Keypad_ArrOutputCharacters[u8_localCounterForRows][u8_localCounterForColumns];
						Keypad_WriteChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_RowsChannelArr[u8_localCounterForRows],STD_HIGH);
						break;
					}
				}
				Keypad_WriteChannel(gastr_KeypadConfigArr[Keypad_Id].Keypad_RowsChannelArr[u8_localCounterForRows],STD_HIGH);
			}
		}
	}
	return returnState;
}

/*
 * periodic check will need queue so i will implement the queue first and port RTOS to this drivers then and i will implement it

 * */
