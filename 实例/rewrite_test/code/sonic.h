#ifndef __SONIC_H__
#define __SONIC_H__

#include "machine.h"

//void Timer1_Init();
void sendSonic();
uchar measureTimer1();
void pcaInit();
uint16_t measurePCA();

#endif
