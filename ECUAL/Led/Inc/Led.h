/*
 * Led.h
 *
 *  Created on: ??�/??�/????
 *      Author: Mazen Sh
 */

#ifndef LED_INC_LED_H_
#define LED_INC_LED_H_


/************************************************************************
 *                       Macros And Types                               *
 ************************************************************************/

typedef uint8 Led_IdType;
#define LED_ID0                                     (Led_IdType)0
#define LED_ID1                                     (Led_IdType)1
#define LED_ID2                                     (Led_IdType)2
#define LED_ID3                                     (Led_IdType)3
#define LED_ID4                                     (Led_IdType)4
#define LED_ID5                                     (Led_IdType)5
#define LED_ID6                                     (Led_IdType)6
#define LED_ID7                                     (Led_IdType)7
#define LED_ID8                                     (Led_IdType)8
#define LED_ID9                                     (Led_IdType)9
#define LED_ID10                                    (Led_IdType)10
#define LED_ID11                                    (Led_IdType)11
#define LED_ID12                                    (Led_IdType)12
#define LED_ID13                                    (Led_IdType)13
#define LED_ID14                                    (Led_IdType)14
#define LED_ID15                                    (Led_IdType)15
#define LED_ID16                                    (Led_IdType)16
#define LED_ID17                                    (Led_IdType)17
#define LED_ID18                                    (Led_IdType)18
#define LED_ID19                                    (Led_IdType)19
#define LED_ID20                                    (Led_IdType)20
#define LED_ID21                                    (Led_IdType)21
#define LED_ID22                                    (Led_IdType)22
#define LED_ID23                                    (Led_IdType)23
#define LED_ID24                                    (Led_IdType)24
#define LED_ID25                                    (Led_IdType)25
#define LED_ID26                                    (Led_IdType)26
#define LED_ID27                                    (Led_IdType)27
#define LED_ID28                                    (Led_IdType)28
#define LED_ID29                                    (Led_IdType)29
#define LED_ID30                                    (Led_IdType)30
#define LED_ID31                                    (Led_IdType)31
#define LED_ID32                                    (Led_IdType)32
#define LED_ID33                                    (Led_IdType)33
#define LED_ID34                                    (Led_IdType)34
#define LED_ID35                                    (Led_IdType)35
#define LED_ID36                                    (Led_IdType)36
#define LED_ID37                                    (Led_IdType)37
#define LED_ID38                                    (Led_IdType)38
#define LED_ID39                                    (Led_IdType)39
#define LED_ID40                                    (Led_IdType)40

typedef uint8 Led_ErrorStateType;
#define E_OK                                        (Led_ErrorStateType)0
#define E_NOT_OK                                    (Led_ErrorStateType)1
#define LED_ID_UNDEFINED                            (Led_ErrorStateType)2


typedef uint8 Led_CurrentDirectionType;
#define LED_SOURCING                                (Led_CurrentDirectionType)0
#define LED_SINKING                                 (Led_CurrentDirectionType)1


typedef uint8 Led_InitialState;
#define LED_OFF                                     (Led_InitialState)0
#define LED_ON                                      (Led_InitialState)1

/************************************************************************/

/************************************************************************
 *                    PORT functions' prototype                         *
 ************************************************************************/


void Led_Init(void);

Led_ErrorStateType Led_On(Led_IdType Led_Id);

Led_ErrorStateType Led_Off(Led_IdType Led_Id);



#endif /* LED_INC_LED_H_ */
