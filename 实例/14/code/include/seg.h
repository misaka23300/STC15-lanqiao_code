#ifndef __SEG_H__
#define __SEG_H__

#include "boot.h"

extern uint8_t seg_value[8];

void seg_display();
void set_seg(uint8_t i, uint8_t state);

#endif