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
#include "dis.h"
#include "ds1302.h"
#include "iic.h"
#include "onewire.h"
#include "sonic.h"

void delete_0( uint8_t *list, uint8_t len, uint8_t is_negative );

#endif