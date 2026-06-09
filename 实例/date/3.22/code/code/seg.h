/**
 * @file seg.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __SEG_H__
#define __SEG_H__

#include "boot.h"

void seg_display( void );
void set_seg( uchar s0, s1, s2, s3, s4, s5, s6, s7 );

#endif