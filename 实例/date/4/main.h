#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "onewire.h"
#include "seg.h"
#include "key.h"
#include "led.h"

void key_proc(void);
void state_machine(void);
void temperature_proc(void);
void adjust_proc(void);
void argument_proc(void);
void hex_to_seg(char *output, char input);
void delete_0(uchar* arrays, uchar j);

#endif