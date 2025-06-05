#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

uchar bcd_to_hex(uchar BCD);
void read_datetime(uchar *time);
void write_datetime(uchar *time);

#endif