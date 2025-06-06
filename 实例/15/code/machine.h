#ifndef __MACHINE_H__
#define __MACHINE_H__

#include "STC15F2K60S2.H"

typedef unsigned char uchar;
typedef unsigned int uint;

void clean_display();
void batch(uchar i);
void timer();
void Timer0_Init(void);
void Timer1_Init(void);
void Uart1_Init(void);


#endif