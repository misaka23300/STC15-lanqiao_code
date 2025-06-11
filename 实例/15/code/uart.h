#ifndef __UART_H__
#define __UART_H__

#include "machine.h"


enum {
    RECEIVE_LEN = 16
};

typedef struct {
    uchar receive_data[RECEIVE_LEN];
    uchar out_time;
    uchar out_time_flag;
    uchar index;
    uchar time;
    uchar receive_data_flag;
} UART;

extern idata UART uart;

typedef struct {
    uchar x;
    uchar y;
} INPUT;

extern INPUT input;

//void uart_send(uchar *str);
//void uart_receive() interrupt 4;
void get_position(); // uart.receive_data -> input.x input.y

char putchar(char c);
#endif