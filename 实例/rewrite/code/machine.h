#ifndef __MACHINE_H__
#define __MACHINE_H__

typedef unsigned char uchar;
typedef unsigned int uint;

#include "STC15F2K60S2.H"
#include "intrins.h"
 

void batch(uchar i);
void Timer1_Init(void);
void Delay500ms(void);
void clean_display();


#endif