#ifndef __SONIC_H__
#define __SONIC_H__

#include "boot.h"

void sonic_send(void);
uint8_t sonic_measure_mode1(void);
uint8_t sonic_measure_mode2(void);
uint8_t sonic_measure_mode3(void);
#endif