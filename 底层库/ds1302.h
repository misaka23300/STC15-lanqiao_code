#ifndef __DS1302_H__
#define __DS1302_H__

#include <stdint.h>

void datetime_write(void);
void datetime_read(void);
uint8_t hex_to_bcd(uint8_t hex);
uint8_t bcd_to_hex(uint8_t bcd);

void Write_Ds1302_Byte(uint8_t address, uint8_t dat);
uint8_t Read_Ds1302_Byte(uint8_t address);

extern uint8_t time_now[3];

#endif