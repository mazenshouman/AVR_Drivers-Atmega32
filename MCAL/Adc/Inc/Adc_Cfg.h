/*
 *  File 	   : Adc_Cfg.h
 *  Created on : July 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef ADC_INC_ADC_CFG_H_
#define ADC_INC_ADC_CFG_H_

/*
 * this configuration parameter used to determine the number of AdcS that
 * will be configured in the Adc_Lcfg.c file (array of structures)
 * this is not required for this controller as there's only one ADC but for future
 * enhancement purpose
 * */
typedef uint8 Adc_ConfigurationStrSizeType;
#define ADC_NUMBER_OF_CONFIGURED_ADCS			    (Adc_ConfigurationStrSizeType)1

typedef uint16 Adc_RegSize_t;

#endif /* ADC_INC_ADC_CFG_H_ */
