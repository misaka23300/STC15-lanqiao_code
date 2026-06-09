/**
 * @file ds1302.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

void datetime_write();
void datetime_read();
void display_task();
extern uint8_t time_now[3];

#endif