#ifndef __DS1302_H__
#define __DS1302_H__

#include "boot.h"

extern uint8_t now_time[3];

uint8_t hex_to_bcd(uint8_t hex);
uint8_t bcd_to_hex(uint8_t bcd);
void ds1302_write();
void ds1302_read();

#endif