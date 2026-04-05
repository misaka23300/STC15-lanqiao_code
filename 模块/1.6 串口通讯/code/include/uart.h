#ifndef __UART_H__
#define __UART_H__


#include "boot.h"
#include "string.h"
#include "stdio.h"

void uart_init();
int8_t putchar(int8_t c);

#endif