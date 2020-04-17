/*
 *  File 	   : Lcd.c
 *  Created on : April 17, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_types.h"
#include "Dio_Lcfg.h"
#include "Dio.h"
#include "Lcd_Wrapper.h"
#include "Lcd_Cfg.h"
#include "Lcd.h"
#include "Lcd_Lcfg.h"
#include <util/delay.h>

/*not complete yet i will continue coding for it later (i think i wont need it)*/
#ifdef LCD_ACTIVATE_STATES

typedef uint8 Lcd_FunctionStatesType;
#define LCD_NUMBER_OF_FUNCTIONS_WITH_STATE_COUNTER          (Lcd_FunctionStatesType)4


typedef uint8 Lcd_LocalStateCounterType;

/************************************************************************
 *              private Array used to save the lcd states in            *
 *                          case of realtime usage                     `*
 ************************************************************************/
Lcd_LocalStateCounterType garr_LcdStateCounter[LCD_NUMBER_OF_CONFIGURED_KEYPADS][LCD_NUMBER_OF_FUNCTIONS_WITH_STATE_COUNTER];

#endif


/************************************************************************
 *                               Macros And Types                       *
 ************************************************************************/
#define LCD_NUMBER_OF_DATA_LINES_MASK                           (0x30)
#define LCD_SHIFT_MASK                                          (0x05)

#define LCD_GET_LOWEST_BIT(VALUE)                               (VALUE&1)
#define LCD_GET_LOWER_NIBBLE(VALUE)                             (VALUE&0x0F)
#define LCD_MOVE_HIGH_NIBBLE_TO_LOW_NIBBLE(VALUE)               (VALUE>>=4)
/************************************************************************/

/************************************************************************
 *                     Function's Implementation                        *
 ************************************************************************/

/**************************************************************************************************************************************
 *  Function : Lcd_Init                                                                                                               *
 *  Param    : IN     : Name / none                                                                                                   *
 *                      Type / void                                                                                                   *
 *                      Desc / none                                                                                                   *
 *                                                                                                                                    *
 *             Output : Name / none                                                                                                   *
 *                                                                                                                                    *
 *  Return   : none                                                                                                                   *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function initialize The Lcd to be ready to take command and data from user and initialize local                   *
 *             structure for each lcd defined                                                                                         *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

void Lcd_Init(void)
{
	/*
	 * we don't need to initialize the lcd as the internal reset circuit will do the job for us
	 * but we must make our configuration for it.
	 * if the hardware reset or software reset performed then there will be a problem as the internal circuit won't work
	 * at this moment we have to initialize lcd (same operations performed by the internal reset circuit)
	 * */

	Lcd_ConfigurationStrSizeType u8_localCounterForId=0;
	for(u8_localCounterForId=0 ; u8_localCounterForId<LCD_NUMBER_OF_CONFIGURED_KEYPADS ; ++u8_localCounterForId)
	{



		switch(gastr_LcdConfigArr[u8_localCounterForId].Lcd_FunctionSet & LCD_NUMBER_OF_DATA_LINES_MASK)
		{
			/*write value to the lcd*/
			case LCD_4_BIT_DATA_MODE:
				/*
				 * the first line is mandatory in case of internal reset not working
				 * and we need to initialize the lcd
				 * */

				Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , 0x33);

				/*
				 * this line is mandatory in all cases without it the lcd won't work in 4 bit mode
				 * */

				Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , 0x32);
				break;
			case LCD_8_BIT_DATA_MODE:
				Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , 0x30);
				break;
		}
#ifdef LCD_INTERAL_RESET_OPERATIONS
		/*
		 * write Clear display Command
		 * */

		Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , LCD_CLEAR_DISPLAY_COMMAND);

		/*
		 * display clear command needs 1.52 ms which stated in the datasheet
		 * but protues seems to need only 150 us at 8 MHZ clock and it works fine on hardware
		 * without delay :D
		 * */

		_delay_us(500);

#endif


		/*
		 * write Lcd_FunctionSet Command
		 * */

		Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , gastr_LcdConfigArr[u8_localCounterForId].Lcd_FunctionSet);

		/*
		 * write Lcd_DisplayControl Command
		 * */

		Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , gastr_LcdConfigArr[u8_localCounterForId].Lcd_DisplayControl);


		/*
		 * write Lcd_EntryMode Command
		 * */

		Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , gastr_LcdConfigArr[u8_localCounterForId].Lcd_EntryMode);

		/*
		 * write Lcd_CursorOrDiplayShift Command
		 * */
		if((gastr_LcdConfigArr[u8_localCounterForId].Lcd_EntryMode&LCD_SHIFT_MASK) == LCD_DISPLAY_SHIFT_ON)
		{
			Lcd_Write(u8_localCounterForId , LCD_WRITE_COMMAND , gastr_LcdConfigArr[u8_localCounterForId].Lcd_CursorOrDiplayShift);
		}

	}

}

/**************************************************************************************************************************************
 *  Function : Lcd_Write                                                                                                              *
 *  Param    : IN     : Name / Lcd_Id                                                                                                 *
 *                      Type / Lcd_IdType                                                                                             *
 *                      Desc / predefine macro for Lcd id                                                                             *
 *                    : Name / Type                                                                                                   *
 *                      Type / Lcd_WriteType                                                                                          *
 *                      Desc / Selects between command and data                                                                       *
 *                    : Name / Value                                                                                                  *
 *                      Type / Lcd_ValueType                                                                                          *
 *                      Desc / wanted value to be written to the LCD                                                                  *
 *             Output:None                                                                                                            *
 *                                                                                                                                    *
 *  Return   : Lcd_ErrorStateType                                                                                                     *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function takes the value wanted to be sent to the lcd. In case of command it must be ored together                *
 *             for specific functionality like entry mode set as if you don't ored it together it will override                       *
 *             the previous set value for this functionality OR data                                                                  *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Lcd_ErrorStateType Lcd_Write(Lcd_IdType Lcd_Id ,Lcd_WriteType Type,Lcd_ValueType Value)
{
	Lcd_ErrorStateType returnState=LCD_E_OK;
	Lcd_NumberOfDataPinsType u8_localCounterForPins=0;
	Lcd_ValueType            u8_localLowerValue=0;

	if(Lcd_Id <NUMBER_ZERO || Lcd_Id > LCD_NUMBER_OF_CONFIGURED_KEYPADS )
	{
		returnState=LCD_ID_OUTOFRANGE;
	}
	else
	{
		/*
		 * set value of R/W pin low to make it write to the lcd
		 * */

		Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_R_W] , STD_LOW);

		/*
		 * set value of RS pin depending on the value of the type (data or command)
		 * */

		switch(Type)
		{
			case LCD_WRITE_COMMAND:

				/*
				 * set RS pin Low for commands
				 * */

				Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_RS] , STD_LOW);
				break;
			case LCD_WRITE_DATA:

				/*
				 * set RS pin high for data
				 * */

				Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_RS] , STD_HIGH);
				break;
			default:
				returnState=LCD_WRONG_TYPE;
				break;
		}

		if(returnState==LCD_E_OK)
		{
			/*switch between the 4 data line and 8 data lines*/

			switch(gastr_LcdConfigArr[Lcd_Id].Lcd_FunctionSet & LCD_NUMBER_OF_DATA_LINES_MASK)
			{

				case LCD_4_BIT_DATA_MODE:

					/*
					 * save the lower part of the data
					 * */

					u8_localLowerValue=LCD_GET_LOWER_NIBBLE(Value);

					/*
					 * move the higher part of the data to the lower part
					 * */

					LCD_MOVE_HIGH_NIBBLE_TO_LOW_NIBBLE(Value);
					Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_E] , STD_HIGH);
					for(u8_localCounterForPins=NUMBER_ZERO ; u8_localCounterForPins<NUMBER_FOUR ; ++u8_localCounterForPins)
					{
						Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_DataPinsArr[u8_localCounterForPins] , LCD_GET_LOWEST_BIT(Value));
						Value>>=1;
					}
					Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_E] , STD_LOW);

					/*
					 * the high part of the data has been latched
					 * */

					Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_E] , STD_HIGH);
					for(u8_localCounterForPins=NUMBER_ZERO ; u8_localCounterForPins<NUMBER_FOUR ; ++u8_localCounterForPins)
					{
						Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_DataPinsArr[u8_localCounterForPins] , LCD_GET_LOWEST_BIT(u8_localLowerValue));
						u8_localLowerValue>>=1;
					}
					Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_E] , STD_LOW);

					break;
				case LCD_8_BIT_DATA_MODE:
					Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_E] , STD_HIGH);
					for(u8_localCounterForPins=NUMBER_ZERO ; u8_localCounterForPins<NUMBER_EIGHT ; ++u8_localCounterForPins)
					{
						Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_DataPinsArr[u8_localCounterForPins] , LCD_GET_LOWEST_BIT(Value));
						Value>>=1;
					}
					Lcd_WriteChannel(gastr_LcdConfigArr[Lcd_Id].Lcd_ControlPinsArr[LCD_E] , STD_LOW);
					break;
				default:
					break;
			}

		}
	}
	return returnState;
}

