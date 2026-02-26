#include "display.h"

uint8_t led[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t seg[8] = {0, 0, 0, 0, 0, 0, 0, 0};

const uint8_t letter[] = {                       
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46, 0x63};    

void led_display()
{
    static uint8_t i;
    static uint8_t last = 0xFF, tmp;
    bit state;

    state = led[i];

    if (state){
        tmp = tmp | (0x01 << i);
    }else{
        tmp = tmp & ~(0x01 << i);
    }

    if (last != tmp){
        P0 = ~tmp;
        latch(4);
        latch(0);

        last = tmp;
    }

    i = (i + 1) % 8;
}

void sandy(uint8_t i,bit state)
{
    static uint8_t last = 0xFF, tmp;

    if (state){
        tmp = tmp | (0x01 << i);
    }else{
        tmp = tmp & ~(0x01 << i);
    }

    if (last != tmp){
        P0 = tmp;
        latch(5);
        latch(0);

        last = tmp;
    }
}

void seg_display()
{
    static uchar i;
    P0 = 0xFF;
    latch(7);
    latch(0);

    P0 = 0x01 << i;
    latch(6);
    latch(0);

    P0 = ~letter[seg[i]];
    latch(7);
    latch(0);

    i = (i + 1) % 8;
}