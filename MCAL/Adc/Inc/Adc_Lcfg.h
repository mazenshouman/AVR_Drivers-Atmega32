/*
 *  File 	   : Adc_Lcfg.h
 *  Created on : July 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef ADC_INC_ADC_LCFG_H_
#define ADC_INC_ADC_LCFG_H_


/************************************************************************
 *                      Configuration Structure                         *
 ************************************************************************/
typedef struct{
	Adc_Channel_Gain_Select_t           Adc_InitalChannel:5;
	Adc_Prescaler_t                     Adc_Prescaler:3;
	Adc_RegAdjustment_t		            Adc_RegisterAdjustment:6;
	Adc_Resolution_t                    Adc_Resolution:2;
	Adc_VRef_t                          Adc_VoltageReference;
	Adc_InterruptState_t                Adc_InterruptState:4;
	Adc_AutoTriggerState_t              Adc_AutoTriggerState:6;
	Adc_AutoTriggerSources_t            Adc_AutoTriggerSources;
	Adc_CurretState_t                   Adc_IntialState;
}Adc_ConfigType;


/************************************************************************
 *                      Externed Structure instance                     *
 ************************************************************************/

extern Adc_ConfigType gastr_AdcConfigArr[];


/************************************************************************/

#endif /* ADC_INC_ADC_LCFG_H_ */
