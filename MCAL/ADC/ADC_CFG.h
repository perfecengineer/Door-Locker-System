#ifndef ADC_CFG_H
#define ADC_CFG_H

/******************  ADC MAX VOLTAGE  ******************/
#define ADC_AREF_INT	1	//voltage = 2.56V
#define ADC_AREF_EXT	2	//voltage = any value
#define ADC_AVCC		3	//voltage = 5V



/******************  ADC CHANNELS  ******************/
#define ADC_CH0		0b00000
#define ADC_CH1		0b00001
#define ADC_CH2		0b00010
#define ADC_CH3		0b00011
#define ADC_CH4		0b00100
#define ADC_CH5		0b00101
#define ADC_CH6		0b00111



/******************  ADC PRESCALAR  ******************/
#define ADC_PRE_2		1
#define ADC_PRE_4		2
#define ADC_PRE_8		3
#define ADC_PRE_16		4
#define ADC_PRE_32		5
#define ADC_PRE_64		6
#define ADC_PRE_128		7



/******************  ADC INTERRUPT STATE  ******************/
#define ADC_ENABLE_INT		    1
#define ADC_DISENABLE_INT		2

#endif
