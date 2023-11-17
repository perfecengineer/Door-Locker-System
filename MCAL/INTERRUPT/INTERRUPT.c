#include "INTERRUPT.h"
#include"../../UTILS/BIT_MATH.h"
#include "avr/interrupt.h"
static volatile void (*ptr_fun1)(void) = NULL;

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	ptr_fun1();
}
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	ptr_fun1();
} 
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	ptr_fun1();
} 
void SET_CALL_BACK(void (*fun_ptr)(void),u8 x)
{
	switch(x)
	{
		case 1:
					ptr_fun1 = fun_ptr;
		break;
		case 2:
					ptr_fun1 = fun_ptr;
		break;
		case 3:
					ptr_fun1 = fun_ptr;
		break;		
	}
} 
void INT1_Enable()
{

	CLEAR_BIT(SREG,7);
	CLEAR_BIT(DDRD,3);// set pD2 at input
	SET_BIT(PORTD,3);// pull up
	SET_BIT(MCUCR,3);// sense falling for int
	SET_BIT(GICR,7);// Enable pIE for intrabt
	SET_BIT(SREG,7);// enable GIE
}