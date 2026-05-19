#ifndef __UART_H__
#define __UART_H__

#include "boot.h"

int8_t putchar(int8_t Data);
int uart_send_byte(int8_t Data);
void uart_send_str(int8_t *str);

extern xdata int8_t receive_temp[100];
extern xdata int8_t send_temp[100];


#endif