 #ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "display.h"
#include "key.h"
#include "iic.h"
#include "ds1302.h"

void boot_init(void);
void task_loop(void);
void led_task(void);
void key_task(void);
void display_task(void);
void write_start_times(void);


#endif