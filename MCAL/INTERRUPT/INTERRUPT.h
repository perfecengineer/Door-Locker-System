#ifndef INTERRUPT_H
#define INTERRUPT_H
#include"../../UTILS/STD_TYPES.h"
#include "avr/interrupt.h"
#define NULL ((void*)0)
void SET_CALL_BACK(void (*fun_ptr)(void),u8 x);
void INT1_Enable(void);
void INT0_Enable(void);
void INT2_Enable(void);
#endif