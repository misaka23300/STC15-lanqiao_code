#ifndef __TASK_H__
#define __TASK_H__

#include "key.h"
#include "seg.h"
#include "sonic.h"
#include "led.h"
#include "main.h"
#include "uart.h"

void seg_task(void);
void key_task(void);
void sonic_task(void);
void display_task(void);
void uart_send(void);

#endif