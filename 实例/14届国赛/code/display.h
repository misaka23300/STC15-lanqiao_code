#ifndef __DISPLAY_H__
#define __DISPLAY_H_

#include "boot.h"

void seg_display();
void led_display();
void relay(bit state);
void buzz(bit state);

#endif