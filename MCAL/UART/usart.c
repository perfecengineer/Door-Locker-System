#include "USART.h"
#include "avr/io.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
void UART_vInit(void)
{
	UCSRC = (1<<7) | (1<<3) | (1<<2) | (1<<1);
	SET_BIT( UCSRB,2);
	// TO accecs the reg UCSRA
	//SET_BIT( UCSRC,7);
	// TO select the mode
	CLEAR_BIT( UCSRC,6);
	//TO double the speed of boad rate
	 SET_BIT( UCSRA,1);
	 // TO DIS play interrupt
	 CLEAR_BIT(UCSRB,5);
	 // TO DSELECT THE parity
	// CLEAR_BIT(UCSRC,5);
	// CLEAR_BIT(UCSRC,4);
	 // TO select the stop bit
	// CLEAR_BIT(UCSRC,3);
	 // TO enable Tx and Rx
	 SET_BIT( UCSRB,3);
	 SET_BIT( UCSRB,4);
	 // TO SELECT THE boud rate 9600
	 CLEAR_BIT( UCSRC,7);
	 UBRRL = 103;
}
void UART_Trans(u16 data)
{
	UDR = data;
	while(READ_BIT( UCSRA,6) != 1);
	SET_BIT(UCSRA,6);
}
u16 UART_RECIV(void)
{
	while(READ_BIT( UCSRA,7) != 1); // while(READ_BIT( UCSRA,5) != 0);
	SET_BIT(UCSRA,7);
	return UDR;
}