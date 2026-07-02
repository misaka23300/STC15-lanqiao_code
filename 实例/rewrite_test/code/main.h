 #ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "display.h"
#include "uart.h"
#include "key.h"
#include "sonic.h"


#include <stdio.h>

void boot_init(void);
void task_loop(void);

void led_task(void);
void key_task(void);
void display_task(void);
void uart_task(void);
void calculator_task(void);
void sonic_task(void);


#endif