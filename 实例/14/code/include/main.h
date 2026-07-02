#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "ds1302.h"
#include "iic.h"
#include "key.h"
#include "led.h"
#include "log.h"
#include "onewire.h"
#include "seg.h"
#include "uart.h"

void display(void);
void key_task(void);
void freq_task(void);
void adc_task(void);
void temp_task(void);

#endif
