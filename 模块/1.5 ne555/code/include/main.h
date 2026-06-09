/**
 * @file main.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "led.h"
#include "seg.h"
#include "key.h"

void key_task();
void shan_task();
void display_task();
void freq_task();

#endif