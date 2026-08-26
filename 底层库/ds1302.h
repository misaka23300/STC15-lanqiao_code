#ifndef __DS1302_H__
#define __DS1302_H__

#include <stdint.h>

void datetime_write(void);
void datetime_read(void);

extern uint8_t time_now[3];

#endif