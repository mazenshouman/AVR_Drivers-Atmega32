/*
 *  File 	   : Lcd.h
 *  Created on : April 14, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef LCD_INC_LCD_H_
#define LCD_INC_LCD_H_

/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/

typedef uint8 Lcd_IdType;
#define LCD_ID0                                         (Lcd_IdType)0
#define LCD_ID1                                         (Lcd_IdType)1
#define LCD_ID2                                         (Lcd_IdType)2
#define LCD_ID3                                         (Lcd_IdType)3
#define LCD_ID4                                         (Lcd_IdType)4
#define LCD_ID5                                         (Lcd_IdType)5
#define LCD_ID6                                         (Lcd_IdType)6
#define LCD_ID7                                         (Lcd_IdType)7
#define LCD_ID8                                         (Lcd_IdType)8
#define LCD_ID9                                         (Lcd_IdType)9
#define LCD_ID10                                        (Lcd_IdType)10

/*
 * Error state macros
 * */
typedef uint8 Lcd_ErrorStateType;
#define LCD_E_OK                                        (Lcd_ErrorStateType)0
#define LCD_E_NOT_OK                                    (Lcd_ErrorStateType)1
#define LCD_ID_OUTOFRANGE                               (Lcd_ErrorStateType)2
#define LCD_ACTIVE_TYPE_IS_NOT_DEFINED                  (Lcd_ErrorStateType)3
#define LCD_NULL_POINTER                                (Lcd_ErrorStateType)4
#define LCD_UNDEFINED_STATE                             (Lcd_ErrorStateType)5
#define LCD_WRONG_TYPE                                  (Lcd_ErrorStateType)6


typedef uint8 Lcd_ValueType;

typedef uint8 Lcd_DataOrCharacterMemorySelectType;
#define LCD_CGRAM                                       (Lcd_DataOrCharacterMemorySelectType)0
#define LCD_DDRAM                                       (Lcd_DataOrCharacterMemorySelectType)1


#define LCD_CLEAR_DISPLAY_COMMAND                       (Lcd_ValueType)1


/**************************
 *     Entry Mode Set     *
 * ************************/
typedef uint8 Lcd_EntryModeType;


#define LCD_DISPLAY_SHIFT_OFF                           (Lcd_EntryModeType)4
#define LCD_DISPLAY_SHIFT_ON                            (Lcd_EntryModeType)5

/*
 * Macros For AC Increment or Decrement on reading or writting to DDRAM
 * */

#define LCD_ADDRESS_DECREMENT                           (Lcd_EntryModeType)4
#define LCD_ADDRESS_INCREMENT                           (Lcd_EntryModeType)6

/**************************
 *Cursor or display shift *
 **************************/

typedef uint8 Lcd_CursorOrDiplayShiftType;

/*
 * macros for Direction of the shift
 * */

#define LCD_DISPLAY_OR_CURSOR_SHIFT_LEFT               (Lcd_CursorOrDiplayShiftType)16
#define LCD_DISPLAY_OR_CURSOR_SHIFT_RIGHT              (Lcd_CursorOrDiplayShiftType)20

/*
 * macros for Selecting Cursor of Display For Shift
 * */

#define LCD_CURSOR_SHIFT                               (Lcd_CursorOrDiplayShiftType)16
#define LCD_DISPLAY_SHIFT                              (Lcd_CursorOrDiplayShiftType)24

/**************************
 * Display On/Off Control *
 * ************************/

typedef uint8 Lcd_DisplayContorlType;

/*
 * macros for blinking
 * */

#define LCD_BLINKING_OFF                               (Lcd_DisplayContorlType)8
#define LCD_BLINKING_ON                                (Lcd_DisplayContorlType)9

/*
 * macros for cursor
 * */

#define LCD_CURSOR_OFF                                 (Lcd_DisplayContorlType)8
#define LCD_CURSOR_ON                                  (Lcd_DisplayContorlType)10

/*
 * macros for entire Display on/off
 * */

#define LCD_DISPLAY_OFF                                (Lcd_DisplayContorlType)8
#define LCD_DISPLAY_ON                                 (Lcd_DisplayContorlType)12


/***********************
 * function set macros *
 * *********************/

typedef uint8 Lcd_FunctionSetType;


/*
 * Macros for Font (each character size (8*5 or 10*5))
 * */


#define LCD_FONT_5_8                                  (Lcd_FunctionSetType)32
#define LCD_FONT_5_10                                 (Lcd_FunctionSetType)36

/*
 * macros for number of display lines
 * */

#define LCD_ONE_DISPLAY_LINE                         (Lcd_FunctionSetType)32
#define LCD_TWO_DISPLAY_LINE                         (Lcd_FunctionSetType)40

/*
 * macros for data pins (4 bit or 8 bit)
 * */

#define LCD_4_BIT_DATA_MODE                          (Lcd_FunctionSetType)32
#define LCD_8_BIT_DATA_MODE                          (Lcd_FunctionSetType)48







typedef uint8 Lcd_WriteType;
#define LCD_WRITE_DATA                               (Lcd_WriteType)0
#define LCD_WRITE_COMMAND                            (Lcd_WriteType)1






#if 0
/**************************
 *     Entry Mode Set     *
 * ************************/

/*
 * macros for Shift of the entire Address Space when Writing (display shift) when Writing to it
 * */

typedef uint8 Lcd_DisplayShiftOnWritingType;
#define LCD_DISPLAY_SHIFT_ON_WRITING_OFF                (Lcd_DisplayShiftOnWritingType)0
#define LCD_DISPLAY_SHIFT_ON_WRITING_ON                 (Lcd_DisplayShiftOnWritingType)1

/*
 * Macros For AC Increment or Decrement on reading or writting to DDRAM
 * */

typedef uint8 Lcd_AddressIncDecType;
#define LCD_ADDRESS_DECREMENT                           (Lcd_AddressIncDecType)0
#define LCD_ADDRESS_INCREMENT                           (Lcd_AddressIncDecType)2

/**************************
 *Cursor or display shift *
 * ************************/

/*
 * macros for Direction of the shift
 * */

typedef uint8 Lcd_DisplayOrCursorShiftDirectionType;
#define LCD_DISPLAY_OR_CURSOR_SHIFT_LEFT               (Lcd_DisplayOrCursorShiftDirectionType)0
#define LCD_DISPLAY_OR_CURSOR_SHIFT_RIGHT              (Lcd_DisplayOrCursorShiftDirectionType)4

/*
 * macros for Selecting Cursor of Display For Shift
 * */

typedef uint8 Lcd_DisplayOrCursorShiftType;
#define LCD_CURSOR_SHIFT                               (Lcd_DisplayOrCursorShiftType)0
#define LCD_DISPLAY_SHIFT                              (Lcd_DisplayOrCursorShiftType)8

/**************************
 * Display On/Off Control *
 * ************************/

/*
 * macros for blinking
 * */

typedef uint8 Lcd_BlinkingOnOffType;
#define LCD_BLINKING_OFF                               (Lcd_BlinkingOnOffType)0
#define LCD_BLINKING_ON                                (Lcd_BlinkingOnOffType)1

/*
 * macros for cursor
 * */

typedef uint8 Lcd_CursorOnOffType;
#define LCD_CURSOR_OFF                                 (Lcd_CursorOnOffType)0
#define LCD_CURSOR_ON                                  (Lcd_CursorOnOffType)2

/*
 * macros for entire Display on/off
 * */

typedef uint8 Lcd_DisplayOnOffType;
#define LCD_DISPLAY_OFF                                (Lcd_DisplayOnOffType)0
#define LCD_DISPLAY_ON                                 (Lcd_DisplayOnOffType)4

/***********************
 * function set macros *
 * *********************/

/*
 * Macros for Font (each character size (8*5 or 10*5))
 * */

typedef uint8 Lcd_FontSizeType;
#define LCD_FONT_5_8                                  (Lcd_FontSizeType)0
#define LCD_FONT_5_10                                 (Lcd_FontSizeType)4

/*
 * macros for number of display lines
 * */

typedef uint8 Lcd_NumbeOfDisplayLinesType;
#define LCD_ONE_DISPLAY_LINE                         (Lcd_NumbeOfDisplayLinesType)0
#define LCD_TWO_DISPLAY_LINE                         (Lcd_NumbeOfDisplayLinesType)8

/*
 * macros for data pins (4 bit or 8 bit)
 * */

#define LCD_4_BIT_DATA_MODE                          (Lcd_NumberOfDataPinsType)0
#define LCD_8_BIT_DATA_MODE                          (Lcd_NumberOfDataPinsType)16


/*
 * macro like function
 * */

#define LCD_FUNCTION_SET(COMMAND)                    (uint8)(32|COMMAND)
#define LCD_ENTRY_MODE_SET(COMMAND)                  (uint8)(4|COMMAND)
#define LCD_DISPLAY_CONTROL(COMMAND)                 (uint8)(8|COMMAND)
#define LCD_CURSOR_OR_DISPLAT_SHIFT(COMMAND)         (uint8)(16|COMMAND)
#define LCD_SET_CGRAM_ADDRESS(ADRESS)                (uint8)(64|ADDRESS)
#define LCD_SET_DDRAM_DATA(DATA)                     (uint8)(128|DATA)

#endif

/************************************************************************/

/************************************************************************
 *                    Lcd functions' prototype                          *
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

void Lcd_Init(void);

/**************************************************************************************************************************************
 *  Function : Lcd_Write                                                                                                              *
 *  Param    : IN     : Name / Lcd_Id                                                                                                 *
 *                      Type / Lcd_IdType                                                                                             *
 *                      Desc / predefine macro for Lcd id                                                                             *
 *                    : Name / Command                                                                                                *
 *                      Type / Lcd_CommandType                                                                                        *
 *                      Desc / wanted command to be send ORed together for specific command                                           *                                                                                                                       *
 *                    : Name / Value                                                                                                  *
 *                      Type / Lcd_ValueType                                                                                          *
 *                      Desc / wanted value to be written to the LCD                                                                  *
 *             Output:None                                                                                                            *
 *                                                                                                                                    *
 *  Return   : Lcd_ErrorStateType                                                                                                     *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *  Desc     : This function takes the command wanted to be sent to the lcd ored together for specific functionality like             *
 *             entry mode set as if you don't ored it together it will override the previous set value for this functionality         *                                                                                                                *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *                                                                                                                                    *
 *************************************************************************************************************************************/

Lcd_ErrorStateType Lcd_Write(Lcd_IdType Lcd_Id ,Lcd_WriteType Type,Lcd_ValueType Value);




#endif /* LCD_INC_LCD_H_ */

