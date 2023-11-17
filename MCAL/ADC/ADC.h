#ifndef ADC_H
#define ADC_H

#include "ADC_CFG.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"


/******************  ADC CONFIGRATION  ******************/

#define 	ADC_VOLTAGE		ADC_AREF_INT
#define 	ADC_CHANNEL		ADC_CH0
#define 	ADC_PRESCALAR	ADC_PRE_64
#define 	ADC_INT_MODE	ADC_DISABLE_INT



/******************  FUNCTIONS PROTOTYPE  ******************/
void ADC_VoidInit(void);

void ADC_VoidStartConversion(void);

u16 ADC_u16ReadData(u8 ADC_u8CopyChannelId);

#endif
