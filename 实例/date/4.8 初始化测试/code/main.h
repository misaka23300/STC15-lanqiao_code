#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "display.h"
#include "key.h"
#include "ds1302.h"


void state_proc(void);
void key_proc(void);
void ds1302_proc(void);

#endif