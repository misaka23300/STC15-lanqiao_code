#ifndef __TIMER_H__
#define __TIMER_H__

#include "machine.h"

enum {
    UART_LEN = 16
};



typedef struct{
    uchar receive_data[UART_LEN];
    uchar index;
    uchar out_time;
    uchar out_time_flag;
    uchar time;
} UART;

extern UART uart;


void Timer0Init(void);
void Timer1Init(void);
void UartInit(void);
char putchar(char c);
void timer();


#endif