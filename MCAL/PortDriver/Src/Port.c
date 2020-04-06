/*
 *  File 	   : Port.c
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Port_Cfg.h"
#include "Port_Lcfg.h"
#include "Port.h"
    

/************************************************************************
 *        Private Includes (macros used inside this file only)          *
 ************************************************************************/
#include "Port_MemMap.h"



/************************************************************************
 *                              macros                                  *
 ************************************************************************/

#define		NUMBER_OF_BITS_IN_REG					8
#define 	GET_PORT_BASE_ADDRESS(PORT)   		    (PORT_BASE_ADDRESS+PORT)

/************************************************************************
 *                     Function's Implementation                        *
 ************************************************************************/


/**************************************************************************************************************************************
 *  Function : Dio_ReadChannel                                                                                                        *
 *  Param    : IN     : Name / None                                                                                                   *
 *                      Type / void                                                                                                   *
 *                      Desc / None                                                                                                   *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *	Return   : ErrorStatus_t                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *	Desc     : This function uses linking configuration structure to configure pins define in                                         *
 *				PORT_LCFG and externed here to configure pins                                                                         *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

ErrorStatus_t Port_Init(void){
	ErrorStatus_t returnError=E_OK;
	Port_NumberOfConfiguredPinsType u8_localLoopCounter=0;
	Port_PortType u8_PortNumber=0;
	Port_PinType u8_PinActualNumber=0;

	for(u8_localLoopCounter=0 ; u8_localLoopCounter < NUMBER_OF_CONFIGURED_PINS ; ++u8_localLoopCounter){

		/*
		 * this line gets the port value which when added to the base address will access the correct DDR reg
		 **/

		u8_PortNumber =(Port_PortType) ((gastr_ConfigArr[u8_localLoopCounter].Channel_ID / NUMBER_OF_BITS_IN_REG));

		/*
		 * this line gets the actual pin number for the selected port so if the value of the entered pin is for ex 10 this means
		 * port C PIN 2
		 * */

		u8_PinActualNumber = (Port_PinType) (gastr_ConfigArr[u8_localLoopCounter].Channel_ID % NUMBER_OF_BITS_IN_REG);

		/*
		 * this line sets the selected direction in the DDR register
		 *
		 * */

		SET_VALUE_FOR_BIT_IN_REG(GET_PORT_BASE_ADDRESS(u8_PortNumber) -> DDR,u8_PinActualNumber,gastr_ConfigArr[u8_localLoopCounter] . Channel_Direction);
#if 0
		GET_PORT_BASE(u8_PortNumber)-> DDR = ((GET_PORT_BASE(u8_PortNumber)-> DDR) & (~(1<<u8_PinActualNumber))) | ((gastr_ConfigArr[u8_localLoopCounter] . Channel_Direction)<<u8_PinActualNumber);
#endif

		/*
		 * if the port direction selected as input this check the resistor attachment value
		 * */

		if(gastr_ConfigArr[u8_localLoopCounter] . Channel_Direction == PORT_PIN_IN){
			SET_VALUE_FOR_BIT_IN_REG(GET_PORT_BASE_ADDRESS(u8_PortNumber) -> PORT ,u8_PinActualNumber,gastr_ConfigArr[u8_localLoopCounter] .channel_Attachment);
		}
		/*
		 * if the pin was configured as output and the pull up resistor is activated then report error
		 * */
		else if(gastr_ConfigArr[u8_localLoopCounter] . Channel_Direction == PORT_PIN_OUT && gastr_ConfigArr[u8_localLoopCounter] .channel_Attachment == PULL_UP_RES){
			/*report error*/
			returnError=PORT_PULL_UP_RES_WRONG_USE;
		}
		else{
			/*
			 * do nothing
			 * */
		}
	}
	return returnError;
}


/****************************************************************************/




