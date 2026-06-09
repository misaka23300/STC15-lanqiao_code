#include "ne555.h"

uint count = 0;
uint freq = 0;
bit ne555_flag = 0;

void ne555_init()
{
    AUXR &= 0x7F;
    TMOD &= 0xF0;
    TMOD |= 0x06;
    TL0 = 0;
    TH0 = 0;
    TF0 = 0;
    TR0 = 1;
}

void timer_1_ne555() interrupt 3
{
    static uint16_t i;
    i++;
    if (i >= 1000)
    {
        i = 0;
        freq = (TH0 << 8) | TL0;
        TH0 = 0;
        TL0 = 0;
        ne555_flag = 1;
    }
}

uint get_ne555_freq()
{
    return freq;
}

bit get_ne555_flag()
{
    return ne555_flag;
}

void clear_ne555_flag()
{
    ne555_flag = 0;
}