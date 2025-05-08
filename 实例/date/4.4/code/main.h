#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "ds1302.h"
#include "display.h"
#include "iic.h"
#include "key.h"

void ds1302_proc();
void state_proc();
void key_proc();

#endif