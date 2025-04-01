#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "sonic.h"
#include "key.h"
#include "display.h"
#include "iic.h"

void key_proc();
void state_proc();
void sonic_proc();

void ADC_proc();
void led_state();
void adjust_out();
#endif