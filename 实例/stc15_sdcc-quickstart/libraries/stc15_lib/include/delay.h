
#ifndef __DELAY_H
#define __DELAY_H

#include "config.h"
#include "timer.h"

void delay_ms(unsigned char ms);

void DelayInit(void);
void DelaySync(u16 ms);

#endif
