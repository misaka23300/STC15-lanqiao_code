/**
 * @file sonic.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __SONIC_H__
#define __SONIC_H__

#include "machine.h"

void Delay14us();

void pca_init();
void sonic_send();
uint8_t sonic_measure();

#endif