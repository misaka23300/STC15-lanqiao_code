#ifndef __NE555_H__
#define __NE555_H__

#include "boot.h"

void ne555_init();
uint get_ne555_freq();
bit get_ne555_flag();
void clear_ne555_flag();

#endif