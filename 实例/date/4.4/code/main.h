#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"

#include "ds1302.h"
#include "display.h"
#include "iic.h"
#include "key.h"

void ds1302_proc(void);
void state_proc(void);
void key_proc(void);

#endif