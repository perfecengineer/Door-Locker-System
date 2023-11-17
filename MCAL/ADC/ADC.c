#include "avr/io.h"
#include "../DIO/DIO.h"
#include "../DIO/DIO_CFG.h"
#include "ADC.h"

void ADC_VoidInit(void)
{
	#if ADC_VOLTAGE == ADC_AREF_INT

	SET_BIT(ADMUX, 7);
	SET_BIT(ADMUX, 6);

	#elif ADC_VOLTAGE == ADC_AREF_EXT

	CLEAR_BIT(ADMUX, 7);
	CLEAR_BIT(ADMUX, 6);

	#elif ADC_VOLTAGE == ADC_AVCC
	CLEAR_BIT(ADMUX, 7);
	SET_BIT(ADMUX, 6);

	#endif


	ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL & 0x1F);
	SET_BIT(ADCSRA, 7);

	#if ADC_INT_MODE == ADC_DISABLE_INT
	CLEAR_BIT(ADCSRA, 3);

	#elif ADC_INT_MODE == ADC_ENABLE_INT
	SET_BIT(ADCSRA, 3);

	#endif


	#if ADC_PRESCALAR == ADC_PRE_128
	SET_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 0);

	#elif ADC_PRESCALAR == ADC_PRE_64
	SET_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 1);
	CLEAR_BIT(ADCSRA, 0);

	#elif ADC_PRESCALAR == ADC_PRE_32
	SET_BIT(ADCSRA, 2);
	CLEAR_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 0);

	#elif ADC_PRESCALAR == ADC_PRE_16
	SET_BIT(ADCSRA, 2);
	CLEAR_BIT(ADCSRA, 1);
	CLEAR_BIT(ADCSRA, 0);

	#elif ADC_PRESCALAR == ADC_PRE_8
	CLEAR_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 0);

	#elif ADC_PRESCALAR == ADC_PRE_4
	CLEAR_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 1);
	CLEAR_BIT(ADCSRA, 0);

	#elif ADC_PRESCALAR == ADC_PRE_2
	CLEAR_BIT(ADCSRA, 2);
	CLEAR_BIT(ADCSRA, 1);
	CLEAR_BIT(ADCSRA, 0);

	#endif

}


void ADC_VoidStartConversion(void)
{
	SET_BIT(ADCSRA, 6);
}


u16 ADC_u16ReadData(u8 ADC_u8CopyChannelId)
{
		ADMUX = (ADMUX & 0xE0) | (ADC_u8CopyChannelId & 0x1F);
		ADC_VoidStartConversion();

		#if ADC_INT_MODE == ADC_DISABLE_INT

		while(READ_BIT(ADCSRA, 4) == 0);
		SET_BIT(ADCSRA, 4);

		#elif ADC_INT_MODE == ADC_ENABLE_INT

		#endif

		return ADC;
}
