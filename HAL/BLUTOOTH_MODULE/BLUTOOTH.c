#include "BLUTOOTH.h"
#include "avr/io.h"
#include "../../MCAL/UART/usart.h"
#include "../../UTILS/BIT_MATH.h"
void BLUTOOTH_vInit(void)
{
	UART_vInit();
	SET_BIT(DDRD,1);
	CLEAR_BIT(DDRD,0);
}
u16 BLUTOOTH_RECIV(void)
{
	u16 return_value = 0;
	return_value = UART_RECIV();
	return return_value;
	
}
void BLUTOOTH_Trans(u16 data)
{
	UART_Trans(data);
}
