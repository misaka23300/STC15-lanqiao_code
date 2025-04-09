#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

void datetime_write(uchar *time);
void datetime_read(uchar *time);

extern idata uchar time_now[3];

#endif