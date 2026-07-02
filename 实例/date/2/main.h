#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "led.h"
#include "seg.h"
#include "sonic.h"
#include "key.h"
#include "iic.h"

void key_proc(void);
void state_machine(void);
void sonic_proc(void);
void adc_proc(void);
void check_distance(void);

#endif