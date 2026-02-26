#ifndef __LED_H__
#define __LED_H__

#include "boot.h"

void led(uint8_t i, bit state);
void led_display();
void led_set(uint8_t i,uint8_t state);


#endif