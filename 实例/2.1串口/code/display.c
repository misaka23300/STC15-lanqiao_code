#include "display.h"


uchar led_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uchar seg_array[8];
code uchar letter[] = {                       //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

 
uchar randzNow;
uchar randzLast;

void seg_display()
{
    static uchar i;

    P0 = 0xFF;
    batch(7);

    P0 = 0x01 << i;
    batch(6);

    P0 = ~letter[seg_array];
    batch(7);

    i = i + 1;
    if (i == 8) {i = 0;}
}

void led_display()
{
    static uchar i;
    static uchar temp;
    static uchar last;

    if (led_array[i])
    {
        temp = temp | (0x01 << i);
    }
    else
    {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last)
    {
        P0 = ~temp;
        batch(4);

        last = temp;
    }


    i += 1;
    if (i == 8) { i = 0;}
} 


void relay(bit state)
{
    if (state)
    {
        randzNow = randzNow | 0x10;
    }
    else
    {
        randzNow = randzNow & ~(0x10);
    }

    if (randzNow != ranzLast)
    {
        P0 = randzNow;
        batch(5);
        ranzLast = randzNow;
    }
}

void buzz(bit state)
{
    if (state)
    {
        randzNow = randzNow | 0x40;
    }
    else
    {
        randzNow = randzNow & ~(0x40);
    }

    if (randzNow != randzLast)
    {
        P0 = randzNow;
        batch(5);
        randzLast = randzNow;
    }
}