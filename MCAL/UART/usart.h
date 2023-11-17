#ifndef USART_H
#define USART_H
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"

void UART_vInit(void);
u16 UART_RECIV(void);
void UART_Trans(u16 data);

#endif