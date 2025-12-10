#include "key.h"

typedef enum {
    wait_press,
    eliminate,
    short_press,
    long_press
} press_task;


uint8_t key_scan()
{

    static press_task state = wait_press;

    static uint8_t value, i;
    uint8_t press = 0xFF, temp = 99;

    P3 = 0x0F;
    P42 = 0; P44 = 0;
    P36 = P42; P37 = P44;

    switch (state)
    {
        case wait_press:
        {
            if (press != 0x0F)
            {
                state = eliminate;
            }
        }
        break;

        case eliminate:
        {
            if (press == 0x0F)
            {
                state = wait_press;
            }
            else
            {
                P3 = press | 0xF0;
                P42 = 1; P44 = 1;
                P36 = P42; P37 = P44;

                press = P3;
                state = short_press;
                switch (press)
                {
                    case 0x77: { value = 4; break; }
                    default: state = wait_press;
                }
            }
        }
        break;

        case short_press:
        {
            if (press != 0x0F)
            {
                i++;
                if (i > 100)
                {
                    i = 0;
                    state = long_press;
                }
            }
            else
            {
                i = 0;
                temp = value;
                value = 0;
                state = wait_press;
            }
        }
        break;

        case long_press:
        {
            if (press == 0x0F)
            {
                temp = value;
                value = 0;
                state = wait_press;
            }
        }
        break;
    }

    return temp;
}