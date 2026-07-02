#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "led.h"
#include "seg.h"
#include "key.h"




void key_task(void);
void shan_task(void);
void display_task(void);
void freq_task(void);


#endif