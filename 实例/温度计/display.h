/**
 * @file display.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <stdint.h>

void led_display();
void sandy(uint8_t i, bit state);
void seg_display();

// extern uint8_t led[8];
// extern uint8_t seg[8];
#endif