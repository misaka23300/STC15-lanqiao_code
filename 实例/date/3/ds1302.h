#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

void init_time();
void write_time(uchar *time);
void read_time();



#endif