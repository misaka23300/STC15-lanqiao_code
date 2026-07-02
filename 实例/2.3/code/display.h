#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "machine.h"


extern uint8_t seg_list[8];
extern uint8_t led_list[8];


void seg_display(void);
void led_display(void);
void relay(uint8_t state);
#endif