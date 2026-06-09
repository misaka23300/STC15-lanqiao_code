/**
 * @file main.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "key.h"
#include "onewire.h"
#include "display.h"

void key_proc();

void key_proc();
void state_proc();
void ds18b20_proc();
void delete_0( uchar *list, uchar n, bit negative );
void led_proc( uchar i );

#endif