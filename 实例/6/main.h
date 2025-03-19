#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "led.h"
#include "key.h"
#include "seg.h"
#include "sonic.h"
#include "onewire.h"

void key_proc(uchar press);
void state_proc();
void temp_proc();


#endif