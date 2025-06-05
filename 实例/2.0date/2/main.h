#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "led.h"
#include "seg.h"
#include "sonic.h"
#include "key.h"
#include "iic.h"

void key_proc();
void state_machine();
void sonic_proc();
void adc_proc();
void check_distance();

#endif