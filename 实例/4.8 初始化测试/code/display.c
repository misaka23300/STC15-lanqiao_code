#include "display.h"


uchar idata led[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uchar idata seg[8] = {0, 0, 0, 0, 0, 0, 0 ,0};

const uchar code letter[] = {                       //标准字库
    //   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
        0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
    //black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
        0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
        0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

void led_display()
{
    static uchar temp, last = 0xFF;
    static uchar i;

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
        batch(4);
        batch(0);

        last = temp;
    }

    i = (i + 1) % 8;
}

void seg_display()
{
    static uchar i;

    P0 = 0xFF;
    batch(7);
    batch(0);

    P0 = 0x01 << i;
    batch(6);
    batch(0);

    P0 = ~letter[seg[i]];
    batch(7);
    batch(0);

    i = (i + 1) % 8;
}

//
void sandy(uchar i, bit state)
{
    static uchar temp, last = 0xFF;
    if (state)
    {
        temp = temp | (0x01 << i);
    }
    else
    {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last)
    {
        P0 = temp;
        batch(5);
        batch(0);
        last = temp;
    }
}