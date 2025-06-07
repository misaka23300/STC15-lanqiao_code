#include "display.h"


code uchar letter[] = {                       //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

uchar seg_list[8] = {17, 17, 17, 17, 17, 17, 17, 17};
uchar led_list[8] = {0, 0, 0, 0, 0, 0 ,0 ,0};

uchar randz_now;
uchar randz_last = 0xFF;


// ___________________________________________________________数码管显示

void seg_display()
{
    static uchar i;

    P0 = 0xFF;
    batch(7);

    P0 = 0x01 << i;
    batch(6);

    P0 = ~letter[seg_list[i]];
    batch(7);

    i++;
    if (i == 8) { i = 0; }
}

void set_seg(uchar a0, a1, a2, a3, a4, a5, a6, a7)
{
    seg_list[0] = a0;
    seg_list[1] = a1;
    seg_list[2] = a2;
    seg_list[3] = a3;

    seg_list[4] = a4;
    seg_list[5] = a5;
    seg_list[6] = a6;
    seg_list[7] = a7;
}

void seg_seg_list(uchar * list)
{
    seg_list[0] = list[0];
    seg_list[1] = list[1];
    seg_list[2] = list[2];
    seg_list[3] = list[3];

    seg_list[4] = list[4];
    seg_list[5] = list[5];
    seg_list[6] = list[6];
    seg_list[7] = list[7];
}

// ____________________________________________________LED灯显示

void led_display()
{
    static uchar i;
    static uchar temp;
    static uchar last = 0xFF;
    if (led_list[i])
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

    i++;
    if (i == 8) { i = 0; }
}

void set_led()
{

}     

// __________________________________________________继电器与超声波

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
        batch(4);

        randz_last = randz_now;
    }
}

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
        batch(4);

        randz_last = randz_now;
    }
}