#include "key.h"

uchar key_scan()
{
    static uchar state, value, i;
    uchar press = 0xFF, temp = 99;

    P3 = 0x0F;
    P42 = 0; P44 = 0;
    P36 = P42; P37 = P44;

    press = P3 & 0x0F;

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
                P3 = press | 0xF0;
                P42 = 1; P44 = 1;
                P36 = P42; P37 = P44;
            
                press = P3;
                state = 2;

                switch (press)
                {
                    case 0x77: {value = 4; break;}
                    case 0x7b: {value = 5; break;}
                    case 0xb7: {value = 6; break;}
                    case 0xbb: {value = 7; break;}
                    default: {state = 0;}
                }

            }
        }
        break;

        case 2:
        {
            if (press != 0x0F)
            {
                i++;
                if (i > 100)
                {
                    i = 0;
                    state = 3;
                }
            }
            else
            {
                temp = value;
                value = 0;
                state = 0;
                i = 0;
            }
        }
        break;

        case 3:
        {
            if (press == 0x0F)
            {
                temp = value + 20;
                value = 0;
                state = 0;
            }
        }
        break;
    }

    return temp;
}