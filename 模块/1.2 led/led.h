#ifndef __LED_H__
#define __LED_H__

#include "stc15f2k60s2.h"
#include "intrins.h"
#include <stdint.h>

void led(uint8_t i, bit state);
void led_display();
void latch(uint8_t i);
void Delay500ms(void);


#endif