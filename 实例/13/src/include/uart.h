#ifndef __UART_H__
#define __UART_H__

#include "boot.h"

typedef struct {
  uint8_t tx : 1;
  uint8_t rx : 1;
} uart_flag_t;

extern uint8_t xdata uart_tx_buf[100];
extern uint8_t xdata uart_rx_buf[100];

void uart_tag_init();

void uart_send_byte(uint8_t byte);
void uart_send_str(uint8_t* str);
int8_t putchar(int8_t chars);

uint8_t uart_receive_byte();
void uart_receive_str();

#endif