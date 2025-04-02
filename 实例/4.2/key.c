#include "key.h"

uchar key_scan()
{
    static uchar state, i, value;
    uchar press, temp;

    P3 = 0x0F;
    P42 = 0; P44 = 0;
    P36 = P42; P37 = P44;

    press = P0 & 0x0F;


    switch (state)
    {
        case 0:
        {
            if (press != 0x0F)
            {
                state = 1;
            }
        }
        break;

        case 1:
        {
            if (press == 0x0F)
            {
                state = 0;
            }
            else
            {
                
            }
        }
        break;
        
    }
}