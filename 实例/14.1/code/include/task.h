#ifndef __TASK_H__
#define __TASK_H__

#include "boot.h"

#include "seg.h"
#include "led.h"
#include "key.h"


#include "uart.h"
#include "ds1302.h"
#include "iic.h"


void start_task(void);
void display_task(void);
void rtc_task(void);
void adc_task(void);
void temp_task(void);
void key_task(void);

#endif

