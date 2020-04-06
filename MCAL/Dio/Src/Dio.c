/*
 *  File 	   : Dio.c
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Dio_Lcfg.h"
#include "Dio.h"

/************************************************************************
 *        Private Includes (macros used inside this file only)          *
 ************************************************************************/
#include "Dio_MemMap.h"


/************************************************************************
 *                              macros                                  *
 ************************************************************************/
#define     NUMBER_OF_BITS_IN_REG                   8
#define     GET_DIO_BASE_ADDRESS(PORT)              (DIO_BASE_ADDRESS+PORT)

/************************************************************************
 *                     Function's Implementation                        *
 ************************************************************************/


/**************************************************************************************************************************************
 *  Function : Dio_ReadChannel                                                                                                        *
 *  Param    : IN     : Name / ChannelId                                                                                              *
 *                      Type / Dio_ChannelType                                                                                        *
 *                      Desc / take channel ID which is predefine macro                                                               *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : Dio_LevelType                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *	Desc     : This function return the level of passed channel ID                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
	/*
	 * get the reg offset
	 * */

	Dio_PortType  u8_RegOffset = (Dio_PortType)(ChannelId/NUMBER_OF_BITS_IN_REG);

	/*
	 * get actual pin number
	 * */

	Dio_ChannelType u8_ActualPinNumber = (Dio_ChannelType)(ChannelId%NUMBER_OF_BITS_IN_REG);

	/*
	 * return the value of the wanted channel
	 * */

	return GET_BIT(GET_DIO_BASE_ADDRESS(u8_RegOffset)-> PIN , u8_ActualPinNumber );

}

/**************************************************************************************************************************************
 *  Function : Dio_WriteChannel                                                                                                       *
 *  Param    : IN     : Name / ChannelId                                                                                              *
 *                      Type / Dio_ChannelType                                                                                        *
 *                      Desc / take channel ID which is predefine macro                                                               *
 *                                                                                                                                    *
 *                      Name / Level                                                                                                  *
 *                      Type / Dio_LevelType                                                                                          *
 *                      Desc / take wanted value to write at the given channel                                                        *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : Dio_LevelType                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function writes the level to the given channel ID                                                                 *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){
	/*
	 * get the reg offset
	 * */

	Dio_PortType  u8_RegOffset = (Dio_PortType)(ChannelId/NUMBER_OF_BITS_IN_REG);

	/*
	 * get actual pin number
	 * */

	Dio_ChannelType u8_ActualPinNumber = (Dio_ChannelType)(ChannelId%NUMBER_OF_BITS_IN_REG);

	/*
	 * set the value in the wanted channel
	 * */

	SET_BIT(GET_DIO_BASE_ADDRESS(u8_RegOffset)-> PORT , u8_ActualPinNumber );
}

/**************************************************************************************************************************************
 *  Function : Dio_ReadPort                                                                                                           *
 *  Param    : IN     : Name / PortId                                                                                                 *
 *                      Type / Dio_PortType                                                                                           *
 *                      Desc / take Port ID which is predefine macro                                                                  *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : void                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function return the level of given port ID                                                                        *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
	/*
	 * return the value of the wanted Port
	 * */
	return (GET_DIO_BASE_ADDRESS(PortId)->PIN);
}


/**************************************************************************************************************************************
 *  Function : Dio_WritePort                                                                                                          *
 *  Param    : IN     : Name / PortId                                                                                                 *
 *                      Type / Dio_PortType                                                                                           *
 *                      Desc / take PORT ID which is predefine macro                                                                  *
 *                                                                                                                                    *
 *                      Name / Level                                                                                                  *
 *                      Type / Dio_PortLevelType                                                                                      *
 *                      Desc / take wanted value to write at the given port                                                           *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : void                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function writes the level to the given PORT ID                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
	/*
	 *set value in the given register
	 */
	GET_DIO_BASE_ADDRESS(PortId)->PORT = Level;
}

/**************************************************************************************************************************************
 *  Function : Dio_ReadChannelGroup                                                                                                   *
 *  Param    : IN     : Name / ChannelGroupIdPtr                                                                                      *
 *                      Type / const Dio_ChannelGroupType*                                                                            *
 *                      Desc / take structure which is defined type                                                                   *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : void                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function takes structue contains the port number, the mask which specifies the wanted pin wanted to read          *
 *             its value and the offset which determines the location of the first pin the mask                                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr){
	/*
	 * mask the register with the given mask value and then shift the register to the right with the offset value
	 * */

	return ((GET_DIO_BASE_ADDRESS(ChannelGroupIdPtr->port)->PIN & ChannelGroupIdPtr->mask) >> ChannelGroupIdPtr->offset);

}

/**************************************************************************************************************************************
 *  Function : Dio_WriteChannelGroup                                                                                                  *
 *  Param    : IN     : Name / ChannelGroupIdPtr                                                                                      *
 *                      Type / const Dio_ChannelGroupType*                                                                            *
 *                      Desc / take Port ID which is predefine macro                                                                  *
 *                                                                                                                                    *
 *                      Name / Level                                                                                                  *
 *                      Type / Dio_PortLevelType                                                                                      *
 *                      Desc / take wanted value to write at the given port without shift                                             *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : void                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc    : This function takes structue contains the value wanted to be written on the specific register                           *
 *            on certain pin with offset value and number of pins define by the mask value each high value equals to pin              *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level){
	/*
	 * mask the register with the given mask then shift the value with the given offset and or both
	 * of them and set the value in the given register
	 * */

	SET_VALUE_FOR_BITS_IN_REG(GET_DIO_BASE_ADDRESS(ChannelGroupIdPtr->port)->PORT,ChannelGroupIdPtr->mask,ChannelGroupIdPtr->offset,Level);

}

/**************************************************************************************************************************************
 *  Function : Dio_FlipChannel                                                                                                        *
 *  Param    : IN     : Name / ChannelId                                                                                              *
 *                      Type / Dio_ChannelType                                                                                        *
 *                      Desc / take channel ID which is predefine macro                                                               *
 *                                                                                                                                    *
 *             Output : None                                                                                                          *
 *                                                                                                                                    *
 *  Return   : Dio_LevelType                                                                                                          *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function takes structue contains the port number, the mask which specifies the wanted pin wanted to read          *
 *			   its value and the offset which determines the location of the first pin the mask                                       *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
	/*
	 * get the reg offset
	 * */

	Dio_PortType  u8_RegOffset = (Dio_PortType)(ChannelId/NUMBER_OF_BITS_IN_REG);

	/*
	 * get actual pin number
	 * */

	Dio_ChannelType u8_ActualPinNumber = (Dio_ChannelType)(ChannelId%NUMBER_OF_BITS_IN_REG);

	/*
	 * flip the wanted channel value and return the value after the operation
	 * */

	TOGGLE_BIT(GET_DIO_BASE_ADDRESS(u8_RegOffset)->PORT,u8_ActualPinNumber);

	return GET_BIT(GET_DIO_BASE_ADDRESS(u8_RegOffset)->PORT , u8_ActualPinNumber);
}


/**************************************************************************************************************************************/
