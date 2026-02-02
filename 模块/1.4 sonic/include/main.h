#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "sonic.h"
#include "seg.h"
#include "key.h"

typedef struct {
    uint8_t time;
    uint8_t distance;
    uint8_t mode;
} sonic_t;

typedef struct {
    uint8_t time;
    uint8_t press;
} key_t;



#endif