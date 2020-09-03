/*
 *  File 	   : Adc_LCfg.c
 *  Created on : July 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/


#include "Std_Types.h"
#include "Adc.h"
#include "Adc_Lcfg.h"

/************************************************************************
 *      creating instance and initializing configuration structure      *
 ************************************************************************/

Adc_ConfigType gastr_AdcConfigArr[ADC_NUMBER_OF_CONFIGURED_ADCS]=
{
		/*          Initial Channel                                   Prescaler                                   RegisterAdjustment                                   wanted resolution                                      VoltageReference 	                              InterruptState                                      AutoTriggerState                             AutoTriggerSources                          IntialState*/
				{ADC_SINGLE_ENDED_ADC4                   ,          ADC_PRESCALER_64               ,               ADC_REG_RIGHT_ADJ              ,                  ADC_RESOLUTION_10_BIT                 ,               ADC_VREF_INTERNAL_2_56                  ,         ADC_INTERRUPT_DISABLED                 ,         ADC_AUTOTRIGGER_DISABLED          ,            ADC_AUTO_TRIGGER_NONE            ,     ADC_CURRENT_STATE_ENABLED}
		/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
};



/*************************************************************************************************/
