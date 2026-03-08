#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

void datetime_write(uint8_t *time);
void datetime_read(uint8_t *time);

extern uint8_t time_now[3];

#endif