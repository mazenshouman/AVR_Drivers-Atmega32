/*
 *  File 	   : Dio_MemMap.h
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef DIO_INC_DIO_MEMMAP_H_
#define DIO_INC_DIO_MEMMAP_H_

/************************************************************************
 *				 		H/W registers and Access mechanism              *
 ************************************************************************/

typedef uint8 		       	        Dio_PIN_Reg_Size_t;
typedef uint8		       	        Dio_PORT_Reg_Size_t;
typedef uint8		       	        Dio_DDR_Reg_Size_t;


typedef struct{
	Dio_PIN_Reg_Size_t			  	PIN;
	Dio_DDR_Reg_Size_t			  	RESERVED;
	Dio_PORT_Reg_Size_t			  	PORT;
}Dio_RegType;

#define DIO_BASE_ADDRESS				((volatile Dio_RegType*)(0x30))

#endif /* DIO_INC_DIO_MEMMAP_H_ */
