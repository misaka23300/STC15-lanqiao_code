#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

void ds1302_write();
void ds1302_read();
extern uint8_t now_time[3];
#endif