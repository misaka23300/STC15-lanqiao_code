/**
 * @file dis.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DIS_H__
#define __DIS_H__

#include "boot.h"

extern uint8_t seg[8];
extern uint8_t led[8];

void led_display();
void seg_display();

#endif