#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

void write_datetime(uchar *time_init);
void read_datetime(uchar *now_time);



#endif