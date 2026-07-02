#ifndef __UART_H__
#define __UART_H__


#include "boot.h"

extern int8_t xdata rx_temp[100];
extern int8_t xdata tx_temp[100];

extern uint8_t xdata rx_receive_done;


int8_t putchar(int8_t Data);
int8_t uart_receive_char(void);
int8_t uart_receive_str(void);

int8_t clear_rx_temp(void);
#endif