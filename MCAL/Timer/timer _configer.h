#include "avr/io.h"
#ifndef TIMER_CONFIGER_H
#define TIMER_CFG_MODE_H
// *************** SELE TIMER ********************
#define Timer0 0
#define Timer1 1 // 16 bit register
#define Timer2 2
// *******************MOdes of timer***********************:
#define Normal_mode 0
#define phase_correct_mode 1
#define CTC_mode 2
#define Fast_PWM_mode 3
//******************* external pin OCX**********************
#define Normal_mode_Disconnected 0
#define Toggle_OCx_on_compare_match_IN_ CTC_Mode_only_OR_Reserved 1
// ************* set OCX on top ***************
#define NON_INVERTING_MODE 2 
// ********************* set on comare value **************************** 
#define INVERTING_MODE 3     

// ****************** SELECT THE CLOCK (pre_scalar) ****************:

#define NO_CLK_SOURSE 0
#define CLK_1 1
#define CLK_8 2
#define CLK_64 3
#define CLK_256 4
#define CLK_1024 5
#define External_clock_source_T0_pin_ClocK_falling _edge 6
#define External_clock_source_T0_pin_ClocK_rising _edge 7

// ***** interrupt enabl Register of perpherial or modes ***********:
#define OVF_EN 0
#define CTC_EN 1
#endif
