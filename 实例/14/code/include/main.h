#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "led.h"
#include "seg.h"
#include "key.h"
#include "ds1302.h"
#include "iic.h"
#include "onewire.h"


void display();
void key_task();
void freq_task();
void adc_task();
void temp_task();

#endif

