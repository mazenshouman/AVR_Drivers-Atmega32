/*
 *  File 	   : Adc.c
 *  Created on : July 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */




/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_types.h"
#include "Bit_Math.h"
#include "Adc.h"
#include "Adc_Lcfg.h"


/************************************************************************
 *                              Global Varibales                        *
 ************************************************************************/
/*we need to add pointer to function for each ADC*/
/*we need global variable for each ADC so that we Update the values for the conversion Register*/

/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/
#define ADC_SFIOR_MASK_VALUE						0x1F
#define ADC_RIGHT_ADJ_REG_OFFSET_VALUE              8
#define ADC_RIGHT_ADJ_LOW_PART_OFFSET_VALUE_8_BIT   2
#define ADC_RIGHT_ADJ_HIGH_PART_OFFSET_VALUE_8_BIT  6
#define ADC_LEFT_ADJ_HIGH_PART_SHIFT_OFFSET         2
#define ADC_LEFT_ADJ_LOW_PART_SHIFT_OFFSET          6

/************************************************************************/

/************************************************************************
 *                     Function's Implementation                        *
 ************************************************************************/

/**************************************************************************************************************************************
 *  Function : Adc_Init                                                                                                               *
 *  Param    : IN     : None                                                                                                          *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : void                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function initialize the ADC                                                                                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/
void Adc_Init(void)
{
	Adc_ConfigurationStrSizeType local_u8LoopCounter=0;
	for(local_u8LoopCounter=0 ; local_u8LoopCounter < ADC_NUMBER_OF_CONFIGURED_ADCS ; ++local_u8LoopCounter)
	{
		/*set ADMUX values*/
		ADC_BASE_ADDRESS -> ADMUX = (gastr_AdcConfigArr[local_u8LoopCounter].Adc_InitalChannel | gastr_AdcConfigArr[local_u8LoopCounter].Adc_RegisterAdjustment | gastr_AdcConfigArr[local_u8LoopCounter].Adc_VoltageReference);

		/*check AutoTrigger value of it's Enabled then select Set trigger source in SFIOR*/
		if(gastr_AdcConfigArr[local_u8LoopCounter].Adc_AutoTriggerState==ADC_AUTOTRIGGER_ENABLED)
		{
			/*set AutoTrigger source in the SFIOR*/
			SET_VALUE_REG(ADC_SFIOR , ADC_SFIOR_MASK_VALUE , gastr_AdcConfigArr[local_u8LoopCounter].Adc_AutoTriggerSources);
		}

		/*set Values in the ADCSRA */
		ADC_BASE_ADDRESS ->ADCSRA  = (gastr_AdcConfigArr[local_u8LoopCounter].Adc_Prescaler | gastr_AdcConfigArr[local_u8LoopCounter].Adc_InterruptState | gastr_AdcConfigArr[local_u8LoopCounter].Adc_AutoTriggerState | gastr_AdcConfigArr[local_u8LoopCounter].Adc_IntialState);
	}
}


/**************************************************************************************************************************************
 *  Function : Adc_StartConversionSync                                                                                                *
 *  Param    : IN     : Name / Adc_Id                                                                                                 *
 *                      Type / Adc_Id_t                                                                                                 *
 *                      Desc / take adc Id which is predefine macro                                                                   *
 *                                                                                                                                    *
 *                      Name / Adc_Channel                                                                                            *
 *                      Type / Adc_Channel_Gain_Select_t                                                                              *
 *                      Desc / take adc channel which is predefine macro                                                              *
 *                                                                                                                                    *
 *                      Name / RegisterSize                                                                                           *
 *                      Type / Adc_ReadingSize_t                                                                                      *
 *                      Desc / predefined macro used to specify the wanted part of the register(left only macro used                  *
 *                              just for left Adj configuration)                                                                      *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *             Output : Name / DigitalValue                                                                                           *
 *                      Type / Adc_RegSize_t*                                                                                         *
 *                      Desc / returns the value of the ADC register after conversion                                                 *
 *                                                                                                                                    *
 *  Return   : Adc_ErrorStatus_t                                                                                                      *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function is synchronous function which will initiate the conversion and wait for the result                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/
Adc_ErrorStatus_t Adc_StartConversion(Adc_Id_t  Adc_Id , Adc_Channel_Gain_Select_t Adc_Channel,Adc_RegSize_t* DigitalValue)
{
	Adc_ErrorStatus_t returnValue=ADC_E_OK;

	/*check if ADC is enabled or not if not enable it firstly*/
	if(!GET_BIT(ADC_BASE_ADDRESS -> ADCSRA , ADC_ENABLE_BIT))
	{
		ADC_BASE_ADDRESS -> ADCSRA |= ADC_CURRENT_STATE_ENABLED;
	}
	/*start conversion by setting the ADSC bit and pull on it*/
	SET_BIT(ADC_BASE_ADDRESS -> ADCSRA , ADC_START_CONVERTION_BIT);

	/*check if the current configuration for the ADc interrupt base or pulling*/
	if(Adc_GetsyncType(Adc_Id)==ADC_SYNC)
	{
		while(GET_BIT(ADC_BASE_ADDRESS -> ADCSRA , ADC_START_CONVERTION_BIT));

		/*return the value from the Register depending on the adjustment of it*/

	    Adc_GetCurrentReading(Adc_Id , Adc_Channel , DigitalValue);
	}
	else
	{
		//nothing
	}
	return returnValue;
}


/**************************************************************************************************************************************
 *  Function : Adc_GetsyncType                                                                                                        *
 *  Param    : IN     : Name / Adc_Id                                                                                                 *
 *                      Type / Adc_Id_t                                                                                               *
 *                      Desc / take adc Id which is predefine macro                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Return   : Adc_SyncType_t                                                                                                         *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function is use to return the current sync type (sync or asynchronous)                                            *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/
Adc_SyncType_t Adc_GetsyncType(Adc_Id_t  Adc_Id)
{
	/*currently Adc_id is useless but i but it here for future enhancement*/
	Adc_SyncType_t local_returnValue;
	if(GET_BIT(ADC_BASE_ADDRESS -> ADCSRA , ADC_INTTERUPT_ENABLE_BIT) == ADC_INTERRUPT_DISABLED)
	{
		local_returnValue=ADC_SYNC;
	}
	else
	{
		local_returnValue=ADC_ASYNC;
	}
	return local_returnValue;
}


/**************************************************************************************************************************************
 *  Function : Adc_GetCurrentReading                                                                                                  *
 *  Param    : IN     : Name / Adc_Id                                                                                                 *
 *                      Type / Adc_Id_t                                                                                                 *
 *                      Desc / take adc Id which is predefine macro                                                                   *
 *                                                                                                                                    *
 *                      Name / Adc_Channel                                                                                            *
 *                      Type / Adc_Channel_Gain_Select_t                                                                              *
 *                      Desc / take adc channel which is predefine macro                                                              *
 *                                                                                                                                    *
 *                      Name / RegisterSize                                                                                           *
 *                      Type / Adc_ReadingSize_t                                                                                      *
 *                      Desc / predefined macro used to specify the wanted part of the register(left only macro used                  *
 *                              just for left Adj configuration)                                                                      *
 *                                                                                                                                    *
 *             Output : Name / DigitalValue                                                                                           *
 *                      Type / Adc_RegSize_t*                                                                                         *
 *                      Desc / returns the value of the ADC register after conversion                                                 *
 *                                                                                                                                    *
 *  Return   : Adc_ErrorStatus_t                                                                                                      *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function is synchronous function which returns the current value in the ADC register                              *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/
Adc_ErrorStatus_t Adc_GetCurrentReading(Adc_Id_t  Adc_Id ,Adc_Channel_Gain_Select_t Adc_Channel,Adc_RegSize_t* DigitalValue)
{
	/*future enhancement i need to return value from global variable if the async option is active currently it gets the value from the register every time */
	Adc_ErrorStatus_t returnValue=ADC_E_OK;
	Adc_RegSize_t     local_u16TempVariable=0;
	/*return the value from the Register depending on the adjustment of it*/
	if(gastr_AdcConfigArr[Adc_Id].Adc_RegisterAdjustment == ADC_REG_RIGHT_ADJ)
	{
		if(gastr_AdcConfigArr[Adc_Id].Adc_Resolution==ADC_RESOLUTION_8_BIT)
		{
			local_u16TempVariable=ADC_BASE_ADDRESS ->ADCL>>ADC_RIGHT_ADJ_LOW_PART_OFFSET_VALUE_8_BIT;
			local_u16TempVariable|=((uint16)ADC_BASE_ADDRESS ->ADCH)<<ADC_RIGHT_ADJ_HIGH_PART_OFFSET_VALUE_8_BIT;
		}
		else if(gastr_AdcConfigArr[Adc_Id].Adc_Resolution==ADC_RESOLUTION_10_BIT)
		{
			local_u16TempVariable=ADC_BASE_ADDRESS ->ADCL;
			local_u16TempVariable|=((uint16)ADC_BASE_ADDRESS ->ADCH)<<ADC_RIGHT_ADJ_REG_OFFSET_VALUE;
		}
		else
		{
			returnValue=ADC_E_NOT_OK;
		}
	}
	else if(gastr_AdcConfigArr[Adc_Id].Adc_RegisterAdjustment == ADC_REG_LEFT_ADJ)
	{
		if(gastr_AdcConfigArr[Adc_Id].Adc_Resolution==ADC_RESOLUTION_8_BIT)
		{
			local_u16TempVariable=ADC_BASE_ADDRESS ->ADCH;
		}
		else if(gastr_AdcConfigArr[Adc_Id].Adc_Resolution==ADC_RESOLUTION_10_BIT)
		{
			local_u16TempVariable=ADC_BASE_ADDRESS ->ADCL>>ADC_LEFT_ADJ_LOW_PART_SHIFT_OFFSET;
			local_u16TempVariable|=ADC_BASE_ADDRESS ->ADCH<<ADC_LEFT_ADJ_HIGH_PART_SHIFT_OFFSET;
		}
		else
		{
			returnValue=ADC_E_NOT_OK;
		}
	}
	else{
		returnValue=ADC_E_NOT_OK;
	}
	*DigitalValue=local_u16TempVariable;
	return returnValue;
}


/*********************************************************************************************************************************************************/
