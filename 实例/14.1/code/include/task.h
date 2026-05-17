#ifndef __TASK_H__
#define __TASK_H__

#include "boot.h"

#include "seg.h"
#include "led.h"
#include "key.h"


#include "uart.h"
#include "ds1302.h"
#include "iic.h"


void start_task();
void display_task();
void rtc_task();
void adc_task();
void temp_task();
void key_task();

#endif

