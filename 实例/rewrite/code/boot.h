#ifndef __BOOT_H__
#define __BOOT_H__

typedef unsigned char uchar;
typedef unsigned int uint;

#include "STC15F2K60S2.H"
#include "intrins.h"
 

void boot_init();
void batch(uchar i);
void Timer1_Init(void);
void Delay500ms(void);
void clean_display();
#endif