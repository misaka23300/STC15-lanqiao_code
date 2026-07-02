#ifndef __SEG_H__
#define __SEG_H__

#include "boot.h"


void seg_display(void);
stc_err_t set_seg(uint8_t i, uint8_t state);


#endif