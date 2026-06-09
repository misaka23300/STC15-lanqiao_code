/**
 * @file ds1302.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DS1302_H__
#define __DS1302_H__

#include <stdint.h>

void datetime_write( uint8_t *time );
void datetime_read( uint8_t *time );

extern uint8_t time_now[3];

#endif