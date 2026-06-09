/**
 * @file main.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "timer.h"
#include "sonic.h"
#include "display.h"
#include "key.h"

void task_loop();
void test();

void display_task();
void key_task();
void freq_task();
void uart_task();
#endif