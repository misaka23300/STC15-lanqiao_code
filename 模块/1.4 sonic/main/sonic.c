#include "sonic.h"

sbit tx = P1 ^ 0;
sbit rx = P1 ^ 1;

extern void sonic_send() {
    uint8_t i;
    for (i = 0; i < 6; i++) {
        tx = 1;
        Delay14us();
        tx = 0;
        Delay14us();
    }
}

uint8_t sonic_measure_mode1() {
    uint8_t distance;

    TR1 = 0;
    TL1 = 0;
    TH1 = 0;
    TF1 = 0;

    sonic_send();
    while (rx == 0);

    TR1 = 1;

    while (rx == 1 && TF1 == 0);
    TR1 = 0;

    if (TF1 == 1) {
        distance = 255;
    } else {
        distance = (uint8_t) ((TH1 << 8) | TL1) * 0.017;
    }

    return distance;
}

uint8_t sonic_measure_mode2() {
    uint8_t distance;

    TR1 = 0;
    TL1 = 0;
    TH1 = 0;
    TF1 = 0;

    tx = 1;
    Delay14us();
    tx = 0;
    Delay14us();

    while (rx == 0);

    TR1 = 1;

    while (rx == 1 && TF1 == 0);
    TR1 = 0;

    if (TF1 == 1) {
        distance = 255;
    } else {
        distance = (uint8_t) ((TH1 << 8) | TL1) * 0.017;
    }

    return distance;
}

uint8_t sonic_measure_mode3() {
    uint16_t time_Dis = 0;
    uint8_t i = 0;
    CMOD = 0x01;
    CCON = 0x00;
    CH = 0x00;
    CL = 0x00;

    tx = 1;
    Delay14us();
    tx = 0;
    Delay14us();

    CR = 1;
    while ((rx == 1) && (CH < 0x40));
    CR = 0;
    if (CH >= 0x40) {
        CF = 0;
        return 0;
    } else {
        time_Dis = (CH << 8) | CL;
        return (time_Dis * 0.0172);
    }
}
