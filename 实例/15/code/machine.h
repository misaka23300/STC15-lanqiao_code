#ifndef __MACHINE_H__
#define __MACHINE_H__

#include "STC15F2K60S2.H"

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;

void clean_display();
void batch(uchar i);
void timer();

void Delay14us(void);



#endif