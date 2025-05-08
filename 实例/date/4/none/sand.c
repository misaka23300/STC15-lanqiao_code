#include "sand.h"

void sandy(uchar i, bit state)
{
    // 4 6
    static uchar last = 0xFF, tmp;
    if (state)
    {
        tmp = tmp & ~(0x01 << i);
    }
    else
    {
        tmp = tmp | ~(0x01 << i);
    }

    if (tmp != last)
    {
        P0 = tmp;
        Y5;
        Y0;

        last = tmp;
    }
}