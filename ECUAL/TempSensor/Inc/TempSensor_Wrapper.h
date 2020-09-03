/*
 * TempSensor_Wrapper.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */

#ifndef TEMPSENSOR_INC_TEMPSENSOR_WRAPPER_H_
#define TEMPSENSOR_INC_TEMPSENSOR_WRAPPER_H_

/************************************************************************
 *                   Wrappers for Macros and Types                      *
 ************************************************************************/
#define TempSensor_Channel_t                    Adc_Channel_Gain_Select_t
#define TempSensor_AdcId_t                      Adc_Id_t
#define TempSensor_ADC_SYNC                     ADC_SYNC
#define TempSensor_ADC_ASYNC                    ADC_ASYNC
#define TempSensor_AdcRegSize_t                 Adc_RegSize_t

/************************************************************************
 *                        Wrappers for APIS                             *
 ************************************************************************/

#define TempSensor_StartConversion      Adc_StartConversion
#define TempSensor_GetReadings		    Adc_GetCurrentReading
#define TempSensor_GetAdcSycType        Adc_GetsyncType

/************************************************************************/


#endif /* TEMPSENSOR_INC_TEMPSENSOR_WRAPPER_H_ */
