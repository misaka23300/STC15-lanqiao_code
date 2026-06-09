/**
 * @file delay.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DELAY_H
#define __DELAY_H

#include "config.h"
#include "timer.h"

void delay_ms(unsigned char ms);

void DelayInit(void);
void DelaySync(u16 ms);

#endif
