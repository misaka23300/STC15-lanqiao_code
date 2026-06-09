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
#include "display.h"
#include "iic.h"
#include "key.h"

void ds1302_proc();
void state_proc();
void key_proc();

#endif