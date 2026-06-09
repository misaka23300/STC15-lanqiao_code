/**
 * @file ds1302.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"
#include "intrins.h"

//extern uint8_t now_time[3];

void ds1302_read();
void ds1302_write();

#endif