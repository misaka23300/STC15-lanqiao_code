#ifndef __DIS_H__
#define __DIS_H__

#include "boot.h"

extern uchar seg[8];
extern uchar led[8];

void led_display();
void seg_display();

#endif