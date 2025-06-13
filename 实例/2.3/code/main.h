#ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "timer.h"
#include "sonic.h"
#include "display.h"
#include "key.h"







void task_loop();
void test();

void display_task();
void key_task();
void freq_task();
#endif