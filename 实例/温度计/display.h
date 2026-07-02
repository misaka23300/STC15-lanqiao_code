#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <stdint.h>

void led_display(void);
void sandy(uint8_t i,bit state);
void seg_display(void);

// extern uint8_t led[8];
// extern uint8_t seg[8];
#endif