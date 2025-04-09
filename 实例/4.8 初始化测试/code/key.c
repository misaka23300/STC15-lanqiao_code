#include "key.h"

uchar key_scan()
{
    static uchar i;
    static uchar value;
    static uchar state;

    uchar press = 0xFF;
    uchar out = 99;

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
                  /*   case 0x77: { value = 4; break; }
                    case 0x7b: { value = 5; break; }
                    case 0x7d: { value = 6; break; }
                    case 0x7e: { value = 7; break; } */

                /*     case 0xb7: { value = 8; break; }
                    case 0xbb: { value = 9; break; }
                    case 0xbd: { value = 10; break; }
                    case 0xbe: { value = 11; break; }

                    case 0xd7: { value = 12; break; }
                    case 0xdb: { value = 13; break; }
                    case 0xdd: { value = 14; break; }
                    case 0xde: { value = 15; break; } */
                    
                    case 0xe7: { value = 16; break; }
                    case 0xeb: { value = 17; break; }
                    case 0xed: { value = 18; break; }
                    case 0xee: { value = 19; break; }

                    default: { state = 0;}
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
                state = 0;
                out = value;
                value = 0;
            }
        }   
        break;

        case 3:
        {
            if (press == 0x0F)
            {
                state = 0;
                out = value + 20;
                value = 0;
            }

        }
        break;

    }
    return out;
}   