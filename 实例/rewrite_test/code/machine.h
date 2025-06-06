#ifndef __MACHINE_H__
#define __MACHINE_H__



#include "STC15F2K60S2.H"
#include "intrins.h"
 
typedef unsigned char uchar;
typedef unsigned int uint;

void batch(uchar i);
void Timer1_Init(void);
void Delay500ms(void);
void Delay14us(void);
void clean_display();


#endif