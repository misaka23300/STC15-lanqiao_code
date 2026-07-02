#ifndef __SONIC_H__
#define __SONIC_H__

#include "machine.h"

//void Timer1_Init(void);
void sendSonic(void);
uchar measureTimer1(void);
void pcaInit(void);
uint16_t measurePCA(void);

#endif
