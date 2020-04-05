/*
 *  File 	   : Port_MemMap.h
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef PORTDRIVER_INC_PORT_MEMMAP_H_
#define PORTDRIVER_INC_PORT_MEMMAP_H_

/************************************************************************
 *				 		H/W registers and Access mechanism              *
 ************************************************************************/

typedef uint8 		       	  PIN_Reg_Size_t;
typedef uint8		       	  PORT_Reg_Size_t;
typedef uint8		       	  DDR_Reg_Size_t;


typedef struct{
	PIN_Reg_Size_t			  RESERVED;
	DDR_Reg_Size_t			  DDR;
	PORT_Reg_Size_t			  PORT;
}PORT_RegType;


#define PORT_BASE_ADDRESS			((volatile PORT_RegType*)(0x30))




#endif /* PORTDRIVER_INC_PORT_MEMMAP_H_ */
