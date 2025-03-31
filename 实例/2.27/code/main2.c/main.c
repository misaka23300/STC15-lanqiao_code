#include "main.h"

void main()
{
    boot_init();

    read_temperature();

    while (1)
    {

    }
}

struct{
    bit flag;
} seg;

struct {
    bit flag;
} key;

timer_1_1ms() interrupt 12
{
    static uint i;
    i++;
    if (i > 30000)
    {
        i = 0;
    }

    if (i % 1 == 0) {
        seg.flag = 1;
    }
        
    if (i % 15 == 0) {
        key.flag = 1;
    }
        
}