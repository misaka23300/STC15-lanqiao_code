#ifndef __DS1302_H__
#define __DS1302_H__

#include <stdint.h>

/* DS1302 时钟芯片驱动
 * 引脚分配：
 *   SDA - P2^3 (数据)
 *   SCK - P1^7 (时钟)  
 *   RST - P2^7 (复位/片选)
 */

/* 初始化写入默认时间到 DS1302 */
void datetime_write(void);
/* 从 DS1302 读取当前时间到 time_now 全局数组 */
void datetime_read(void);

/* 当前时间存储 [秒, 分, 时] (BCD 格式已转为十进制) */
extern uint8_t time_now[3];

#endif