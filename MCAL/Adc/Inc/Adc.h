/*
 *  File 	   : Adc.h
 *  Created on : July 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef ADC_INC_ADC_H_
#define ADC_INC_ADC_H_


/************************************************************************
 *                           File Includes                               *
 ************************************************************************/
#include "Adc_MemMap.h"
#include "Adc_Cfg.h"

/************************************************************************
 *                           Error macros                               *
 ************************************************************************/
typedef uint8 Adc_ErrorStatus_t;
#define ADC_E_NOT_OK                                        (Adc_ErrorStatus_t)1
#define ADC_E_OK                                            (Adc_ErrorStatus_t)0

/************************************************************************
 *                         Macros And Types                             *
 ************************************************************************/

/*************************************************************
 *              			ADC ID                           *
 *************************************************************/
typedef uint8 Adc_Id_t;
#define ADC_ID0                                             (Adc_Id_t)0
#define ADC_ID1                                             (Adc_Id_t)1
#define ADC_ID2                                             (Adc_Id_t)2
#define ADC_ID3                                             (Adc_Id_t)3
#define ADC_ID4                                             (Adc_Id_t)4

/*************************************************************
 *              			Sync Type                        *
 *************************************************************/
typedef uint8 Adc_SyncType_t;
#define ADC_SYNC       										(Adc_SyncType_t)0
#define ADC_ASYNC                                           (Adc_SyncType_t)1

/*************************************************************
 *              			ADMUX REG                        *
 *************************************************************/

/******************************************************
 *              voltage Reference macros              *
 ******************************************************/
/* please take in your consideration that if you are willing to connect the Aref Pin on the board, you Must not select internal voltage or AVcc voltage
 * as this will result to short circuit
 * */
typedef uint8 Adc_VRef_t;
#define ADC_VREF_AREF	                                    (Adc_VRef_t)0
#define ADC_VREF_AVCC	                                    (Adc_VRef_t)64
#define ADC_VREF_INTERNAL_2_56                              (Adc_VRef_t)192


/******************************************************
 *              Register Adjustment macros            *
 ******************************************************/
typedef uint8 Adc_RegAdjustment_t;
#define ADC_REG_RIGHT_ADJ                                   (Adc_RegAdjustment_t)0
#define ADC_REG_LEFT_ADJ                                    (Adc_RegAdjustment_t)32


/******************************************************
 *              Channel Select macros                 *
 ******************************************************/
typedef uint8 Adc_Channel_Gain_Select_t;
#define ADC_SINGLE_ENDED_ADC0                               (Adc_Channel_Gain_Select_t)0
#define ADC_SINGLE_ENDED_ADC1                               (Adc_Channel_Gain_Select_t)1
#define ADC_SINGLE_ENDED_ADC2                               (Adc_Channel_Gain_Select_t)2
#define ADC_SINGLE_ENDED_ADC3                               (Adc_Channel_Gain_Select_t)3
#define ADC_SINGLE_ENDED_ADC4                               (Adc_Channel_Gain_Select_t)4
#define ADC_SINGLE_ENDED_ADC5                               (Adc_Channel_Gain_Select_t)5
#define ADC_SINGLE_ENDED_ADC6                               (Adc_Channel_Gain_Select_t)6
#define ADC_SINGLE_ENDED_ADC7                               (Adc_Channel_Gain_Select_t)7
#define ADC_DIFFERENTIAL_ADC0_ADC0_GAIN_10					(Adc_Channel_Gain_Select_t)8
#define ADC_DIFFERENTIAL_ADC1_ADC0_GAIN_10					(Adc_Channel_Gain_Select_t)9
#define ADC_DIFFERENTIAL_ADC0_ADC0_GAIN_200					(Adc_Channel_Gain_Select_t)10
#define ADC_DIFFERENTIAL_ADC1_ADC0_GAIN_200					(Adc_Channel_Gain_Select_t)11
#define ADC_DIFFERENTIAL_ADC2_ADC0_GAIN_10					(Adc_Channel_Gain_Select_t)12
#define ADC_DIFFERENTIAL_ADC3_ADC0_GAIN_10					(Adc_Channel_Gain_Select_t)13
#define ADC_DIFFERENTIAL_ADC2_ADC0_GAIN_200					(Adc_Channel_Gain_Select_t)14
#define ADC_DIFFERENTIAL_ADC3_ADC0_GAIN_200					(Adc_Channel_Gain_Select_t)15
#define ADC_DIFFERENTIAL_ADC0_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)16
#define ADC_DIFFERENTIAL_ADC1_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)17
#define ADC_DIFFERENTIAL_ADC2_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)18
#define ADC_DIFFERENTIAL_ADC3_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)19
#define ADC_DIFFERENTIAL_ADC4_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)20
#define ADC_DIFFERENTIAL_ADC5_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)21
#define ADC_DIFFERENTIAL_ADC6_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)22
#define ADC_DIFFERENTIAL_ADC7_ADC1_GAIN_1					(Adc_Channel_Gain_Select_t)23
#define ADC_DIFFERENTIAL_ADC0_ADC2_GAIN_1					(Adc_Channel_Gain_Select_t)24
#define ADC_DIFFERENTIAL_ADC1_ADC2_GAIN_1					(Adc_Channel_Gain_Select_t)25
#define ADC_DIFFERENTIAL_ADC2_ADC2_GAIN_1					(Adc_Channel_Gain_Select_t)26
#define ADC_DIFFERENTIAL_ADC3_ADC2_GAIN_1					(Adc_Channel_Gain_Select_t)27
#define ADC_DIFFERENTIAL_ADC4_ADC2_GAIN_1					(Adc_Channel_Gain_Select_t)28



/*************************************************************
 *              			ADCSRA REG                        *
 *************************************************************/

/******************************************************
 *                     Prescaler macros               *
 ******************************************************/

/*Note that: Adc need clock fre 50-200 KH to produce the full resolution (10 bit)*/
typedef uint8 Adc_Prescaler_t;
#define ADC_PRESCALER_2                                     (Adc_Prescaler_t)0
#define ADC_PRESCALER_4                                     (Adc_Prescaler_t)2
#define ADC_PRESCALER_8                                     (Adc_Prescaler_t)3
#define ADC_PRESCALER_16                                    (Adc_Prescaler_t)4
#define ADC_PRESCALER_32                                    (Adc_Prescaler_t)5
#define ADC_PRESCALER_64                                    (Adc_Prescaler_t)6
#define ADC_PRESCALER_128                                   (Adc_Prescaler_t)7


/******************************************************
 *                     Interrupt macros               *
 ******************************************************/
typedef uint8 Adc_InterruptState_t;
#define ADC_INTERRUPT_DISABLED                              (Adc_InterruptState_t)0
#define ADC_INTERRUPT_ENABLED								(Adc_InterruptState_t)8

#define ADC_INTTERUPT_FLAG_BIT                              4
#define ADC_INTTERUPT_ENABLE_BIT							3


/******************************************************
 *               AutoTrigger macros Part1             *
 ******************************************************/
/*
 * it doesn't matter if you select the source first or enable this bit as long as the enable bit of the adc is disabled
 * preferable order:
 * 1-select source
 * 2-enable auto-trigger bit
 * 3-enable the ADC
 * */
/*
 *Note: auto trigger if enabled works only on the rising edge of the interrupt flag of the selected source
 * so for any Interrupt other than the ADC interrupt flag we have to clear the flag in order to the ADC continue Auto Trigger
 * and also interrupt flag will be raised even if the global interrupt is disabled
 */
typedef uint8 Adc_AutoTriggerState_t;
#define ADC_AUTOTRIGGER_DISABLED							(Adc_AutoTriggerState_t)0
#define ADC_AUTOTRIGGER_ENABLED							    (Adc_AutoTriggerState_t)32


/******************************************************
 *               Start Convertion Bit                 *
 ******************************************************/
#define ADC_START_CONVERTION_BIT                            6

/******************************************************
 *             ADC Enable/Disable Macros              *
 ******************************************************/
typedef uint8 Adc_CurretState_t;
#define ADC_CURRENT_STATE_DISABLED                          (Adc_CurretState_t)0
#define ADC_CURRENT_STATE_ENABLED                           (Adc_CurretState_t)128

#define ADC_ENABLE_BIT                                      7

/*************************************************************
 *              			SFIOR REG                        *
 *************************************************************/
/******************************************************
 *               AutoTrigger macros part2             *
 ******************************************************/
/*the source select bit must be set to one in order to this configuration reflect on the system*/
typedef uint8 Adc_AutoTriggerSources_t;
#define ADC_AUTO_TRIGGER_FREE_RUNNING						(Adc_AutoTriggerSources_t)0x00
#define ADC_AUTO_TRIGGER_ANALOG_COMPARATOR                  (Adc_AutoTriggerSources_t)0x20
#define ADC_AUTO_TRIGGER_EXTI0                              (Adc_AutoTriggerSources_t)0x40
#define ADC_AUTO_TRIGGER_TIMER0_COM                         (Adc_AutoTriggerSources_t)0x60
#define ADC_AUTO_TRIGGER_TIMER0_OVF                         (Adc_AutoTriggerSources_t)0x80
#define ADC_AUTO_TRIGGER_TIMER1_COMB                        (Adc_AutoTriggerSources_t)0xA0
#define ADC_AUTO_TRIGGER_TIMER1_OVF                         (Adc_AutoTriggerSources_t)0xC0
#define ADC_AUTO_TRIGGER_TIMER1_CAP                         (Adc_AutoTriggerSources_t)0xE0
#define ADC_AUTO_TRIGGER_NONE							    (Adc_AutoTriggerSources_t)0x00

/************************************************************************/

typedef uint8 Adc_Resolution_t;
#define ADC_RESOLUTION_8_BIT                                 (Adc_Resolution_t)0
#define ADC_RESOLUTION_10_BIT								 (Adc_Resolution_t)1


/************************************************************************
 *                        functions' prototypes                         *
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
void Adc_Init(void);


/**************************************************************************************************************************************
 *  Function : Adc_StartConversionSync                                                                                                *
 *  Param    : IN     : Name / Adc_Id                                                                                                 *
 *                      Type / Adc_Id_t                                                                                               *
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
Adc_ErrorStatus_t Adc_StartConversion(Adc_Id_t  Adc_Id , Adc_Channel_Gain_Select_t Adc_Channel,Adc_RegSize_t* DigitalValue);

/**************************************************************************************************************************************
 *  Function : Adc_GetCurrentReading                                                                                                  *
 *  Param    : IN     : Name / Adc_Id                                                                                                 *
 *                      Type / Adc_Id_t                                                                                               *
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
Adc_ErrorStatus_t Adc_GetCurrentReading(Adc_Id_t  Adc_Id ,Adc_Channel_Gain_Select_t Adc_Channel,Adc_RegSize_t* DigitalValue);


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
Adc_SyncType_t Adc_GetsyncType(Adc_Id_t  Adc_Id);

/*********************************************************************************************************************************************************/




#endif /* ADC_INC_ADC_H_ */
