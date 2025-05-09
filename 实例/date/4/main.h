#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "onewire.h"
#include "seg.h"
#include "key.h"
#include "led.h"

void key_proc();
void state_machine();
void temperature_proc();
void adjust_proc();
void argument_proc();
void hex_to_seg(char *output, char input);
void delete_0(uchar* arrays, uchar j);

#endif