#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "machine.h"


extern uchar seg_list[8];
extern uchar led_list[8];


void seg_display();
void led_display();
void relay(uchar state);
#endif