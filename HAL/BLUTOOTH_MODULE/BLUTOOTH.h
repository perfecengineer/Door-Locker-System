#ifndef BLUTOOTH_H
#define BLUTOOTH_H

#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"

void BLUTOOTH_vInit(void);
u16 BLUTOOTH_RECIV(void);
void BLUTOOTH_Trans(u16 data);



#endif
