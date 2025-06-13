#ifndef __SONIC_H__
#define __SONIC_H__

#include "machine.h"

void Delay14us();

void pca_init();
void sonic_send();
uchar sonic_measure();

#endif