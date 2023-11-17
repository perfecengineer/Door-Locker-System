
#include "DIO.h"
#include "DIO_CFG.h"
#include "avr/io.h"
#include "../../UTILS/BIT_MATH.h"
#include "../../UTILS/STD_TYPES.h"


void SET_PIN_DIR(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_DIR)
{
	if (PIN_DIR == OUTPUT)
	{
		switch (PORT_NAME)
		{
			case GROUP_A:
			SET_BIT(DDRA,PIN_NUMBER);
			break;
			case GROUP_B:
			SET_BIT(DDRB,PIN_NUMBER);
			break;
			case GROUP_C:
			SET_BIT(DDRC,PIN_NUMBER);
			break;
			case GROUP_D:
			SET_BIT(DDRD,PIN_NUMBER);
			break;
		}
	}
	else 
	{
		switch (PORT_NAME)
		{
			case GROUP_A:
			CLEAR_BIT(DDRA,PIN_NUMBER);
			break;
			case GROUP_B:
			CLEAR_BIT(DDRB,PIN_NUMBER);
			break;
			case GROUP_C:
			CLEAR_BIT(DDRC,PIN_NUMBER);
			break;
			case GROUP_D:
			CLEAR_BIT(DDRD,PIN_NUMBER);
			break;
		}		
	}
}

void SET_PIN_VALUE(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_VALUE)
{
	if (PIN_VALUE == HIGH)
	{
		switch (PORT_NAME)
		{
			case GROUP_A:
			SET_BIT(PORTA,PIN_NUMBER);
			break;
			case GROUP_B:
			SET_BIT(PORTB,PIN_NUMBER);
			break;
			case GROUP_C:
			SET_BIT(PORTC,PIN_NUMBER);
			break;
			case GROUP_D:
			SET_BIT(PORTD,PIN_NUMBER);
			break;
		}		
	}
	else
	{
		switch (PORT_NAME)
		{
			case GROUP_A:
			CLEAR_BIT(PORTA,PIN_NUMBER);
			break;
			case GROUP_B:
			CLEAR_BIT(PORTB,PIN_NUMBER);
			break;
			case GROUP_C:
			CLEAR_BIT(PORTC,PIN_NUMBER);
			break;
			case GROUP_D:
			CLEAR_BIT(PORTD,PIN_NUMBER);
			break;
		}		
	}
}

u8 READ_PIN_VALUE(u8 PORT_NAME, u8 PIN_NUMBER)
{
	u8 value;
	switch (PORT_NAME)
	{
		case GROUP_A:
		value = READ_BIT(PINA,PIN_NUMBER);
			break;
		case GROUP_B:
		value = READ_BIT(PINB,PIN_NUMBER);
			break;
		case GROUP_C:
		value = READ_BIT(PINC,PIN_NUMBER);
			break;
		case GROUP_D:
		value = READ_BIT(PIND,PIN_NUMBER);
			break;		
	}
	return value;
}


void SET_GROUP_DIR(u8 PORT_NAME, u8 PORT_DIR)
{
		switch (PORT_NAME)
		{
			case GROUP_A:
			DDRA = PORT_DIR;
			break;
			case GROUP_B:
			DDRB = PORT_DIR;
			break;
			case GROUP_C:
			DDRC = PORT_DIR;
			break;
			case GROUP_D:
			DDRD = PORT_DIR;
			break;
			default:break;
		}
	
}

void SET_GROUP_VALUE(u8 PORT_NAME, u8 GROUP_VALUE)
{
		switch (PORT_NAME)
		{
			case GROUP_A:
		    PORTA = GROUP_VALUE;
			break;
			case GROUP_B:
		    PORTB = GROUP_VALUE;
			break;
			case GROUP_C:
		    PORTC = GROUP_VALUE;
			break;
			case GROUP_D:
		    PORTD = GROUP_VALUE;
			break;
			default:break;

		}		
}


u8 READ_GROUP_VALUE(u8 PORT_NAME)
{
	u8 value;
	switch (PORT_NAME)
	{
		case GROUP_A:
		value = PINA;
			break;
		case GROUP_B:
		value = PINB;
			break;
		case GROUP_C:
		value = PINC;
			break;
		case GROUP_D:
		value = PIND;
			break;		
	}
	return value;
}
