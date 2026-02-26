#include "seg.h"
#include "boot.h"

static int8_t randz_now = 0;
static int8_t randz_last = 0;

const uint8_t letter[] = {                                              //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1
uint8_t seg_value[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void seg_display()
{
    static uint8_t i;

    P0 = 0xFF;
    latch(7);
    latch(0);

    P0 = 0x01 << i;
    latch(6);
    latch(0);

    P0 = ~letter[seg_value[i]];
    latch(7);
    latch(0);
    
    i = (i + 1) % 8;
}

void set_seg(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t s4, uint8_t s5, uint8_t s6, uint8_t s7)
{
    seg_value[0] = s0;
    seg_value[1] = s1;
    seg_value[2] = s2;
    seg_value[3] = s3;
    seg_value[4] = s4;
    seg_value[5] = s5;
    seg_value[6] = s6;
    seg_value[7] = s7;
}

void relay(bit state)
{
    if (state)
    {
        randz_now = randz_now | (0x10);
    }
    else
    {
        randz_now = randz_now & ~(0x10);
    }

    if (randz_now != randz_last)
    {
        P0 = randz_now;
        latch(4);

        randz_last = randz_now;
    }
}

/* void buzz(bit state)
{
    if (state)
    {
        randz_now = randz_now | (0x40);
    }
    else
    {
        randz_now = randz_now & ~(0x40);
    }

    if (randz_now != randz_last)
    {
        P0 = randz_now;
        latch(4);

        randz_last = randz_now;
    }
} */