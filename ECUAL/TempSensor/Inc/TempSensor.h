/*
 *  File 	   : TempSensor.h
 *  Created on : July 15, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef TEMPSENSOR_INC_TEMPSENSOR_H_
#define TEMPSENSOR_INC_TEMPSENSOR_H_

/************************************************************************
 *                           File Includes                               *
 ************************************************************************/

#include "TempSensor_Wrapper.h"
#include "TempSensor_Cfg.h"

/************************************************************************
 *                           Error macros                               *
 ************************************************************************/
typedef uint8 TempSensor_ErrorStatus_t;
#define TEMPSENSOR_E_NOT_OK                                        (Adc_ErrorStatus_t)1
#define TEMPSENSOR_E_OK                                            (Adc_ErrorStatus_t)0

/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/

/*************************************************************
 *              			ADC ID                           *
 *************************************************************/
typedef uint8 TempSensor_Id_t;
#define TEMPSENSOR_ID0                                             (TempSensor_Id_t)0
#define TEMPSENSOR_ID1                                             (TempSensor_Id_t)1
#define TEMPSENSOR_ID2                                             (TempSensor_Id_t)2
#define TEMPSENSOR_ID3                                             (TempSensor_Id_t)3
#define TEMPSENSOR_ID4                                             (TempSensor_Id_t)4


typedef uint16 TempSensor_AdcResolution_t;

typedef uint16 TempSensor_AdcVref_t;


/************************************************************************
 *                        functions' prototypes                         *
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
 *  Desc     : This function return the current temperature from specific sensor                                                      *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/
TempSensor_ErrorStatus_t TempSensor_GetTemperature(TempSensor_Id_t Sensor_Id , TempSensor_TempValueSize_t *CurrentTemp);




#endif /* TEMPSENSOR_INC_TEMPSENSOR_H_ */
