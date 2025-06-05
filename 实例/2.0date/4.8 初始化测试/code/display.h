#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "boot.h"

void led_display();
void seg_display();
void sandy(uchar i, bit state);

extern uchar idata led[8];
extern uchar idata seg[8];

#endif