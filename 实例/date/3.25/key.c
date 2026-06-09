#include "key.h"

uint8_t key_scan()
{
    static uint8_t i, state, value;
    uint8_t temp = 99, press = 0xFF;

    P3 = 0x0F;
    P42 = 0; P44 = 0;
    P36 = P42; P36 = P44;

    press = P3 & 0x0F;

    switch (state)
    {
        case 0:
        {
            if (press != 0x0F)
            {
                state = 1;
            }
            break;
        }

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
                P36 = P42; P36 = P44;

                press = P3;

                state = 2;

                switch (press)
                {
                    case 0x77: {value = 4; break;}
                    case 0x7B: {value = 5; break;}
                    case 0x7D: {value = 6; break;}
                    case 0x7E: {value = 7; break;}

                    case 0xB7: {value = 8; break;}
                    case 0xBB: {value = 9; break;}
                    case 0xBD: {value = 10; break;}
                    case 0xBE: {value = 11; break;}

                    case 0xD7: {value = 12; break;}
                    case 0xDB: {value = 13; break;}
                    case 0xDD: {value = 14; break;}
                    case 0xDE: {value = 15; break;}

                    case 0xE7: {value = 16; break;}
                    case 0xEB: {value = 17; break;}
                    case 0xED: {value = 18; break;}
                    case 0xEE: {value = 19; break;}
                    default: {state = 0;}
                }
            }
        }
        break;

        case 2:
        {
            if (press == 0x0F)
            {
                i++;
                if (i >= 150)
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