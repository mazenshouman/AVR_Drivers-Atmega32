/*
 *  File 	   : TempSensor.c
 *  Created on : July 15, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */


/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_types.h"
#include "Bit_Math.h"
#include "Adc.h"
#include "TempSensor.h"
#include "TempSensor_Lcfg.h"


/************************************************************************
 *                              Global Varibales                        *
 ************************************************************************/


/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/


/************************************************************************/

/************************************************************************
 *                     Function's Implementation                        *
 ************************************************************************/
/**************************************************************************************************************************************
 *  Function : TempSensor_GetTemperature                                                                                              *
 *  Param    : IN     : Name / Sensor_Id                                                                                              *
 *                      Type / TempSensor_Id_t                                                                                        *
 *                      Desc / take Senesor Id which is predefine macro                                                               *
 *                                                                                                                                    *
 *             Output : Name / CurrentTemp                                                                                            *
 *                      Type / TempSensor_TempValueSize_t*                                                                            *
 *                      Desc / returns the current temperature in the give pointer                                                    *
 *                                                                                                                                    *
 *  Return   : TempSensor_ErrorStatus_t                                                                                               *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the current temperature from specific sensor (Sync Function)                                      *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/
TempSensor_ErrorStatus_t TempSensor_GetTemperature(TempSensor_Id_t Sensor_Id , TempSensor_TempValueSize_t *CurrentTemp)
{
	TempSensor_ErrorStatus_t local_returnValue=TEMPSENSOR_E_OK;
	TempSensor_AdcRegSize_t local_DigitalValue;
	if(Sensor_Id >= TEMPSENSOR_NUMBER_OF_CONFIGURED_SENSORS)
	{
		local_returnValue=TEMPSENSOR_E_NOT_OK;
	}
	else
	{
		/*check if the adc configure as sync or asyc to select the correct API*/
		/*this need to be changed and handled by call back function*/
		if(TempSensor_GetAdcSycType(gastr_TempSensorConfigArr[Sensor_Id].TempSensor_Adc_Id) == TempSensor_ADC_SYNC)
		{
			TempSensor_StartConversion(gastr_TempSensorConfigArr[Sensor_Id].TempSensor_Adc_Id , gastr_TempSensorConfigArr[Sensor_Id].TempSensor_Channel , &local_DigitalValue );
		}
		else
		{
		}

		/*temp = analog vlaue / StepPerDegree
		 * analog value = digital value * AdcStep*/
		*CurrentTemp = ((uint32)local_DigitalValue*gastr_TempSensorConfigArr[Sensor_Id].TempSensor_AdcVref)/(gastr_TempSensorConfigArr[Sensor_Id].TempSensor_StepInMvPerDergree * gastr_TempSensorConfigArr[Sensor_Id].TempSensor_AdcResolution);

	}
	return local_returnValue;
}





