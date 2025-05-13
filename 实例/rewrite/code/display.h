#ifndef __DISPLAY_H__
#define __DISPLAY_H_

#include "boot.h"

void seg_display();
void led_display();
void relay(bit state);
void buzz(bit state);


void set_seg_value(uchar d0, d1, d2, d3, d4, d5, d6, d7);
void set_seg_list(uchar *list);

#endif