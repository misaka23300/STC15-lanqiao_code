#ifndef __TASK_H__
#define __TASK_H__

#include "boot.h"

#include "led.h"
#include "seg.h"
#include "key.h"
#include "ds1302.h"
#include "sonic.h"
#include "onewire.h"

void start_task(void);
void key_task(void);
void display_task(void);
void sonic_task(void);
void ds18b20_task(void);
void pcf8591_task(void);
void freq_task(void);
void ds1302_task(void);

#endif