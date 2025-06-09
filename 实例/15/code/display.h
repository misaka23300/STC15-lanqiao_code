#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "machine.h"



void seg_display();
/* void set_seg(uchar a0, a1, a2, a3, a4, a5, a6, a7);
void seg_seg_list(uchar * list); */
void led_display();
void relay(bit state);
void buzz(bit state);

extern uchar seg_list[8];
extern uchar led_list[8];


#endif