/*
 * TemoSensor_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */

#ifndef TEMPSENSOR_INC_TEMPSENSOR_CFG_H_
#define TEMPSENSOR_INC_TEMPSENSOR_CFG_H_


/************************************************************************
 *                      Configuration macros                            *
 ************************************************************************/
/*
 * this configuration parameter used to determine the number of Sensors that
 * will be configured in the TempSensor_Lcfg.c file (array of structures)
 * */

typedef uint8 TempSensor_ConfigurationStrSizeType;
#define TEMPSENSOR_NUMBER_OF_CONFIGURED_SENSORS			(TempSensor_ConfigurationStrSizeType)1

/*this value determines the maximum size of the step Per degree*/
typedef uint8 TempSensor_StepInMvPerDergree_t;

/*this value determines the maximum temperature that the variable can handle without overflow*/
typedef sint8 TempSensor_TempValueSize_t;


#endif /* TEMPSENSOR_INC_TEMPSENSOR_CFG_H_ */
