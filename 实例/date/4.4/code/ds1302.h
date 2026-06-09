/**
 * @file ds1302.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

uchar bcd_to_hex( uchar BCD );
void write_datetime( uchar *time );
void read_datatime( uchar *time );

#endif