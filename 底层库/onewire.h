#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include <stdint.h>

/* 修复: 与 onewire.c 实现保持一致, 返回 uint8_t, 单位为 0.1°C 的整数倍 */
uint8_t read_temperature(void);

#endif