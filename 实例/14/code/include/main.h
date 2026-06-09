/**
 * @file main.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

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

void display();
void key_task();
void freq_task();
void adc_task();
void temp_task();

#endif
