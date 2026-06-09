/**
 * @file onewire.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __ONEWIRE_H
#define __ONEWIRE_H

#include "main.h"

sbit DQ = P1^4;  

float rd_temperature( void );  

#endif
