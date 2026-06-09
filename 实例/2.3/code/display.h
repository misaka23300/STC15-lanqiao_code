/**
 * @file display.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "machine.h"

extern uint8_t seg_list[8];
extern uint8_t led_list[8];

void seg_display();
void led_display();
void relay( uint8_t state );
#endif