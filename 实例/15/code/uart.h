#ifndef __UART_H__
#define __UART_H__

#include "machine.h"


enum {
    RECEIVE_LEN = 16
};

typedef struct {
    uint8_t receive_data[RECEIVE_LEN];
    uint8_t out_time;
    uint8_t out_time_flag;
    uint8_t index;
    uint8_t time;
    uint8_t receive_data_flag;
} UART;

extern idata UART uart;

typedef struct {
    uint8_t x;
    uint8_t y;
} INPUT;

extern INPUT input;

//void uart_send(uchar *str);
//void uart_receive() interrupt 4;
void get_position(); // uart.receive_data -> input.x input.y

char putchar(char c);
#endif