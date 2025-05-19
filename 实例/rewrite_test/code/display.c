#include "display.h"

uchar code letter[] = {                       //标准字库
    //   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
        0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
    //black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
        0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
        0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

uchar seg[8] = {0, 0 ,0, 0, 0, 0, 0 ,0};
uchar led[8] = {0, 0 ,0, 0, 0, 0, 0 ,0};


static uchar randz_now;
static uchar randz_last = 0xFF;
 
void set_seg_value(uchar d0, d1, d2, d3, d4, d5, d6, d7)
{
    seg[0] = d0;
    seg[1] = d1;
    seg[2] = d2;
    seg[3] = d3; 
    seg[4] = d4; 
    seg[5] = d5;
    seg[6] = d6;
    seg[7] = d7;
}

void set_seg_list(uchar *list)
{
    seg[0] = list[0];
    seg[1] = list[1];
    seg[2] = list[2];
    seg[3] = list[3];
    seg[4] = list[4];
    seg[5] = list[5];
    seg[6] = list[6];
    seg[7] = list[7];

}


void set_led_value(uchar d0, d1, d2, d3, d4, d5, d6, d7)
{
    led[0] = d0;
    led[1] = d1;
    led[2] = d2;
    led[3] = d3; 
    led[4] = d4; 
    led[5] = d5;
    led[6] = d6;
    led[7] = d7;
}


void seg_display()
{
    static uchar i;

    P0 = 0xFF;
    batch(7);
    
    P0 = 0x01 << i;
    batch(6);

    P0 = ~letter[seg[i]]; 
    batch(7);

    i = i + 1;
    if (i == 8) { i = 0; }
}

void led_display()
{
    static uchar i;
    static uchar now;
    static uchar last;

    if (led[i])
    {
        now = now | (0x01 << i);
    }
    else
    {
        now = now & ~(0x01 << i);
    }

    if (last != now)
    {
        P0 = ~now;
        batch(4);

        last = now;
    }

    i = i + 1;
    if (i == 8) { i = 0; }
}


// 继电器 4

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
        batch(5);
        randz_last = randz_now;
    }
}

// 蜂鸣器 6
void buzz(bit state)
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
        batch(5);
        randz_last = randz_now;
    }
}


