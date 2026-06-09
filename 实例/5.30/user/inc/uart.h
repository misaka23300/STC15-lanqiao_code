/**
 * @file uart.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __UART_H__
#define __UART_H__

#include "boot.h"

extern int8_t xdata rx_temp[100];
extern int8_t xdata tx_temp[100];

extern uint8_t xdata rx_receive_done;

int8_t putchar( int8_t Data );
int8_t uart_receive_char();
int8_t uart_receive_str();

int8_t clear_rx_temp();
#endif