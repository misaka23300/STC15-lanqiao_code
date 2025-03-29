#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "sonic.h"
#include "seg.h"
#include "display.h"
#include "onewire.h"
#include "key.h"


void state_proc();
void ds18b20_proc();
void delete_0(uchar *a, j, bit negative);


void key_proc();
#endif