#ifndef INTERRUPT_CFG_H
#define INTERRUPT_CFG_H
#include"../DIO/DIO_CFG.h"
// trigger option for Registers

#define sense_INT_ISC1 3 // FOR MUCCR SENSE FOR THE FRIST BIT OF REG 
#define sense_INT_ISC0 2// FOR MUCCR SENSE FOR THE 2ND BIT OF REG
#define  PIE_ENABLED_BIT 7 //FOR GICR
#define  GIE_ENABLED_BIT 7 //FOR SREG
/*
	CLEAR_BIT(SREG,7);
	CLEAR_BIT(DDRD,3);// set pD2 at input
	SET_BIT(PORTD,3);// pull up
	SET_BIT(MCUCR,3);// sense falling for int
	SET_BIT(GICR,7);// Enable pIE for intrabt
	SET_BIT(SREG,7);// enable GIE
*/
// For External INT_pin
#define INT_PORT GROUP_D
#define 3 INT1
#define 2 INT0

#endif