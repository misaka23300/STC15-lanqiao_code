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
stc_err_t set_seg( uint8_t i, uint8_t state );

#endif