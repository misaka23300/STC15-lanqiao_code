/**
 * @file display.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "boot.h"

void led_display();
void seg_display();
void sandy( uint8_t i, bit state );

extern uint8_t idata led[8];
extern uint8_t idata seg[8];

#endif