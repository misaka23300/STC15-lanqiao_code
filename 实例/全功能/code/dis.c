#include "dis.h"

uint8_t led[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t seg[8] = {0, 0, 0, 0, 0, 0, 0, 0};

code uint8_t letter[] = {                       //标准字库
    //   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
        0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
    //black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
        0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
        0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46, 0x63};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1
    
// 1 1 0 0 0 1 1 0
//0110 0011

void led_display()
{
    static uchar i;
    static uchar temp;
    static uchar last = 0xFF;

    if (led[i])
    {
        temp = temp | (0x01 << i);
    }
    else
    {
        temp = temp & ~(0x01 << i);
    }

    if (last != temp)
    {
        P0 = ~temp;
        latch(4);
        latch(0);
        last = temp;
    }

    i++;
    if (i == 8) { i = 0; }
}


void seg_display()
{
    static uint8_t i = 0;

    P0 = 0xFF;
    latch(7);
    latch(0);

    P0 = 0x01 << i;
    latch(6);
    latch(0);

    P0 = ~letter[seg[i]];
    latch(7);
    latch(0);

    i++;
    if (i == 8) { i = 0; }
}