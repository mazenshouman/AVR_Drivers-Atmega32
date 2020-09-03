/*
 *  File 	   : Adc_MemMap.h
 *  Created on : July 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */


#ifndef ADC_INC_ADC_MEMMAP_H_
#define ADC_INC_ADC_MEMMAP_H_

/************************************************************************
 *                    H/W registers and Access mechanism                *
 ************************************************************************/

typedef uint8 Adc_Reg_Size_t;


typedef struct{
	Adc_Reg_Size_t 			ADCL;
	Adc_Reg_Size_t 			ADCH;
	Adc_Reg_Size_t 			ADCSRA;
	Adc_Reg_Size_t 			ADMUX;
}Adc_RegType;


#define ADC_BASE_ADDRESS  ((volatile Adc_RegType*)(0x24))


/* this register is used to specify the autoTrigger source for ADC*/

#define ADC_SFIOR   	  *((volatile Adc_Reg_Size_t*)(0x50))


#endif /* ADC_INC_ADC_MEMMAP_H_ */
