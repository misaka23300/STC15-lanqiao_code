#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "boot.h"

void led_display(void);
void seg_display(void);
void sandy(uint8_t i, bit state);

extern uint8_t idata led[8];
extern uint8_t idata seg[8];

#endif