#ifndef __LED_H__
#define __LED_H__

#include "boot.h"

extern uint8_t led_value[8];
void led_display();
void led_set(uint8_t position, bit value);

#endif