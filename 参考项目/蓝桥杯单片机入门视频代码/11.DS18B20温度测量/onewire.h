#ifndef __ONEWIRE_H
#define __ONEWIRE_H

#include "main.h"

sbit DQ = P1^4;  

float rd_temperature(void);  

#endif
