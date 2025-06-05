#ifndef __DS1302_H__
#define __DS1302_H__

#include "machine.h"

// 写入时间数据 数组类型为BCD码
void write_datetime(uchar *time_init);

// 读取时间数据 返回HEX码
void read_datetime(uchar *now_time);


#endif