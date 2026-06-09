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

#include "display.h"

void task_loop();
void test();

void display_task();

void freq_task();
#endif