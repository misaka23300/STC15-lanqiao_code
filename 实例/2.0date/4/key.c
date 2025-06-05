 #include "key.h"

 uchar key_scan()
 {
    static uchar state, value, i;
    uchar temp = 99, press = 0xFF;

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
                    case 0x77: {value = 4; break; }
                    case 0x7B: {value = 5; break; }
                    case 0x7D: {value = 6; break; }
                    case 0x7E: {value = 7; break; }

                    case 0xB7: {value = 8; break; }
                    case 0xBB: {value = 9; break; }
                    default: {state = 0;}
                }
            }
        }
        break;

        case 2:
        {
            if (press != 0x0F)
            {
                i = (i + 1) % 255;
                if (i >= 100)
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
            if (press != 0x0F)
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