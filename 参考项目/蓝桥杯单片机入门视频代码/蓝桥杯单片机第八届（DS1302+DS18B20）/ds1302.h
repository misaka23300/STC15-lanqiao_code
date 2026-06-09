/**
 * @file ds1302.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DS1302_H
#define __DS1302_H
#include "main.h"
void Write_Ds1302( unsigned char temp );
void Write_Ds1302_Byte( unsigned char address, unsigned char dat );
unsigned char Read_Ds1302_Byte( unsigned char address );
void DS1302_Settime( u8 hour, min, sec );
#endif
