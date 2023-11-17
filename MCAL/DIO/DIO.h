#ifndef DIO_H
#define DIO_H

#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"

  // This function shall set the direction of any pin
void SET_PIN_DIR(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_DIR);

  // This function shall set the value of any pin
void SET_PIN_VALUE(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_VALUE);

  // This function shall read the value of any pin
u8 READ_PIN_VALUE(u8 PORT_NAME, u8 PIN_NUMBER);
void SET_GROUP_DIR(u8 PORT_NAME, u8 PORT_DIR);
void SET_GROUP_VALUE(u8 PORT_NAME, u8 GROUP_VALUE);
u8 READ_GROUP_VALUE(u8 PORT_NAME);


#endif
