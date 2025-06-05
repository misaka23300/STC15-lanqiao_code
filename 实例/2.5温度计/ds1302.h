#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

void init_time();
void read_time();
void write_time(uchar* time);

// extern uchar now_time[7];
#endif