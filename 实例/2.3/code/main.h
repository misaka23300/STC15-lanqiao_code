#ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "timer.h"
#include "sonic.h"
#include "display.h"
#include "key.h"







void task_loop(void);
void test(void);

void display_task(void);
void key_task(void);
void freq_task(void);
void uart_task(void);
#endif