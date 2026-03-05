#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "sonic.h"
#include "seg.h"
#include "key.h"
#include "led.h"

enum {
    SONIC_TIME = 400,
    KEY_TIME = 20,
    SEG_STATE_TIME = 90,
    LED_TIME = 30,
};

typedef struct {
    uint16_t time;
    uint8_t distance;
    uint8_t mode;
} sonic_t;

typedef struct {
    uint8_t time;
} led_t;

typedef struct {
    uint8_t time;
    uint8_t press;
} key_t;

typedef enum {
    dis_init,
    dis_sonic,
    dis_key,
} display_mode_t;

typedef struct {
    display_mode_t mode;
    uint8_t time;
} seg_state_t;



#endif