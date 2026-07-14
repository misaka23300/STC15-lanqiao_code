#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

#include <stdint.h>

void Write_DS18B20(uint8_t dat);
uint8_t Read_DS18B20(void);
bit init_ds18b20(void);
float read_temperature(void);

#endif