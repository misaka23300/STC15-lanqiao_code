#ifndef __TIMER_H__
#define __TIMER_H__

#include "machine.h"

enum {
    UART_LEN = 16
};



typedef struct{
    uint8_t receive_data[UART_LEN];
    uint8_t index;
    uint8_t out_time;
    uint8_t out_time_flag;
    uint8_t time;
} UART;

extern UART uart;


void Timer0Init(void);
void Timer1Init(void);
void UartInit(void);
char putchar(char c);
void timer();


#endif