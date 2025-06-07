#ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"

#include "key.h"
#include "display.h"


extern uchar seg_list[8];
extern uchar led_list[8];


//void pcaInterrupt() interrupt 7;
void uartSend(uchar *str);

//void Uart1_Isr(void) interrupt 4;
void time_1ms();

void task_loop();
void main();
void key_task();




#endif