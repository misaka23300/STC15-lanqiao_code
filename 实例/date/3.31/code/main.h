#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "sonic.h"
#include "key.h"
#include "display.h"
#include "iic.h"

void key_proc(void);
void state_proc(void);
void sonic_proc(void);

void ADC_proc(void);
void led_state(void);
void adjust_out(void);
#endif