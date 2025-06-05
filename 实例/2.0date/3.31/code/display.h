#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "boot.h"

void seg_display();
void set_seg(uchar s0, s1, s2, s3, s4, s5, s6, s7);

void led(uchar i, bit state);
void led_display();

void sandy(uchar i, bit state);

#endif