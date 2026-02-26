#ifndef __SEG_H__
#define __SEG_H__

#include "boot.h"

void seg_display();
void set_seg(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t s4, uint8_t s5, uint8_t s6, uint8_t s7);

void relay(bit state);
/* void buzz(bit state); */


#endif