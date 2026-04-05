#ifndef __LED_H__
#define __LED_H__

#include "boot.h"


void set_led(uint8_t i, bit_t state);
void relay(bit state);
void buzz(bit state);

#endif