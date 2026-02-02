#ifndef __DIS_H__
#define __DIS_H__

#include "boot.h"

extern uint8_t seg[8];
extern uint8_t led[8];

void led_display();
void seg_display();

#endif