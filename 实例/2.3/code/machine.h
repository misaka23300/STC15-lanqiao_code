#ifndef __MACHINE_H__
#define __MACHINE_H__

#include "STC15F2K60S2.H"
#include "intrins.h"


#include "stdio.h"


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;

void batch(uint8_t i);
void clean_display();


#endif