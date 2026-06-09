/**
 * @file ds1302.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_Write_Time();
void DS1302_Read_Time();
extern unsigned char Time10[7];

#endif