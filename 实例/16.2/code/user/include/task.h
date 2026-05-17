#ifndef __TASK_H__
#define __TASK_H__

#include "boot.h"

#include "led.h"
#include "seg.h"
#include "key.h"
#include "ds1302.h"
#include "sonic.h"
#include "onewire.h"

void start_task();
void key_task();
void display_task();
void sonic_task();
void ds18b20_task();
void pcf8591_task();
void freq_task();
void ds1302_task();

#endif