#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "seg.h"
#include "led.h"
#include "key.h"
#include "iic.h"
#include "ds1302.h"

void freq_proc(void);
void state_proc(void);
void delete_0(uchar *arr, uchar j);
void key_proc(void);
void ds1302_proc(void);
void DAC_proc(void);
void led_proc(void);
#endif