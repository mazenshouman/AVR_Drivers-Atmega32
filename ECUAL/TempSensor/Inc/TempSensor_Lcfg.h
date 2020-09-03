/*
 *  File 	   : TempSensor_Lcfg.h
 *  Created on : July 15, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */
#ifndef TEMPSENSOR_INC_TEMPSENSOR_LCFG_H_
#define TEMPSENSOR_INC_TEMPSENSOR_LCFG_H_

/************************************************************************
 *                      Configuration Structure                         *
 ************************************************************************/
typedef struct{
	TempSensor_AdcId_t              TempSensor_Adc_Id;
	TempSensor_Channel_t            TempSensor_Channel;
	TempSensor_StepInMvPerDergree_t TempSensor_StepInMvPerDergree;
	TempSensor_TempValueSize_t      TempSensor_MaxTemp;
	TempSensor_TempValueSize_t      TempSensor_MinTemp;
	TempSensor_AdcResolution_t      TempSensor_AdcResolution;
	TempSensor_AdcVref_t            TempSensor_AdcVref;
}TempSensor_ConfigType;


/************************************************************************
 *                      Externed Structure instance                     *
 ************************************************************************/

extern TempSensor_ConfigType gastr_TempSensorConfigArr[];


/************************************************************************/


#endif /* TEMPSENSOR_INC_TEMPSENSOR_LCFG_H_ */
