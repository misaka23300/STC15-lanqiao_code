#ifndef __MAIN_H__
#define __MAIN_H__

#include "sys.h"
#include "led.h"
#include "seg.h"
#include "key.h"
// #include "sonic.h"

void key_proc();
void seg_proc();
void led_proc();
//void Timer1_Isr(void) interrupt 1;

#endif