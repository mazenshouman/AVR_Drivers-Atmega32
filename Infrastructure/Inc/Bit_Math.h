/*
 *  File 	   : Bit_Math.h
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

#ifndef INC_BIT_MATH_H_
#define INC_BIT_MATH_H_

#define SET_BIT(REG,BIT)			                        REG|=(1<<(BIT))
#define CLEAR_BIT(REG,BIT)			                        REG&=~(1<<(BIT))
#define TOGGLE_BIT(REG,BIT)             		            REG^=(1<<(BIT))
#define GET_BIT(REG,BIT)						            (((REG)>>(BIT))&1)
#define SET_VALUE_FOR_BIT_IN_REG(REG,BIT,VALUE)				REG=(((REG)&(~(1<<BIT)))|((VALUE)<<(BIT)))
#define SET_VALUE_FOR_BITS_IN_REG(REG,MASK,OFFSET,VALUE)	REG=(((REG)&(MASK))|((VALUE)<<((OFFSET))&(MASK)))


#endif /* INC_BIT_MATH_H_ */
