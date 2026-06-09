/**
 * @file led.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __LED_H__
#define __LED_H__

#include "boot.h"

/* typedef unsigned char  uint8_t;
typedef signed char    int8_t;

typedef unsigned short uint16_t;
typedef signed short   int16_t; */

void led(uint8_t i, bit state);
void led_display();
void set_led(uint8_t i, uint8_t state);

#endif