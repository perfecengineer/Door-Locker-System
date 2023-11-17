/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLEAR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOGGLE_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define READ_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#endif
