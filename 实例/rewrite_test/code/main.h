 #ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "display.h"


void boot_init();
void task_loop();
void led_task();
void key_task();
void display_task();
void write_start_times();


#endif