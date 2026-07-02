#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

extern uint8_t time_now[3];

void date_write(void);
void date_read(void);


#endif