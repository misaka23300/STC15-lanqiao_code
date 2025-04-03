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
                P3 = press | 0xF0;
                P42 = 1; P44 = 1;
                P36 = P42; P37 = P44;

                press = P3;

                state = 2;

                switch (press)
                {

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
                i = 0;
                temp = value;
                value = 0;
                state = 0;
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