#ifndef _CONFIG_H
#define _CONFIG_H

#include <STC15F2K60S2.H>

//数据类型定义
typedef unsigned char uchar;
typedef unsigned char u8;
typedef unsigned int uint;
typedef unsigned int u16;
typedef unsigned long ulong;
typedef unsigned long u32;

//定义主频
#define MAIN_FOSC 12000000L

//定义HC573写入数据
#define Write_HC573(reg,dat) {P2=P2&0X1F|reg;P0=dat;P2&=0X1F;}

#endif