#ifndef TIMER_H
#define TIMER_H
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "timer _configer.h"
//CONFIGER THE MODES:
#define Select_Timer   Timer1
#define select_mode    Fast_PWM_mode
#define pin_MODE_OCX   NON_INVERTING_MODE
//CONFIGER THE PRES_CALAR:
#define Select_CLK 		CLK_64

// ********************************the intial function:
void Timer_vIntial(void);
// ******************************input caption value or top value function:
void SET_TOP_Timer1_value(u16 top);
// *******************************timer counter register:
void PRE_LOAD_Timer(u16 k);
//********************************** compare value or duty value:
void SET_OCRX_value(u16 duty);





#endif
