#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "display.h"
#include "key.h"
#include "ds1302.h"


void state_proc();
void key_proc();
void ds1302_proc();

#endif