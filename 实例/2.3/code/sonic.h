#ifndef __SONIC_H__
#define __SONIC_H__

#include "machine.h"

void Delay14us();

void pca_init();
void sonic_send();
uint8_t sonic_measure();

#endif