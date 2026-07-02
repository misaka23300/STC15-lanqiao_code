#ifndef __SONIC_H__
#define __SONIC_H__

#include "machine.h"

void Delay14us(void);

void pca_init(void);
void sonic_send(void);
uint8_t sonic_measure(void);

#endif