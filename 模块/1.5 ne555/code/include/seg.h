/**
 * @file seg.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __SEG_H__
#define __SEG_H__

#include "boot.h"

void seg_display();
void seg_set( uint8_t i, uint8_t state );

void relay( bit state );
extern uint8_t seg_value[8];
/* void buzz( bit state ); */

#endif