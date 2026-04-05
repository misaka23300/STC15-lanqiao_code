#ifndef __SOFT_UART_H
#define __SOFT_UART_H

#include "config.h"

/* 如果要使用 printf, 定义 USE_STDIO 宏即可 */
#ifdef USE_STDIO
#include <stdio.h>
#define print printf
#else
void print(char *);
#endif

#ifdef DEBUG
#define LOG(str) \
    print(str); \
    print("\r\n")
#else
#define LOG(str)
#endif

#endif
