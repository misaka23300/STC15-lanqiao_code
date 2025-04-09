#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

extern idata uchar time_now[3];

void datetime_write(uchar *time);
void datetime_read(uchar *time);

#endif