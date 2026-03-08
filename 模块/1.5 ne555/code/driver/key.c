#include "key.h"

uint8_t key_scan()
{
    static uint8_t i, state, value;
    uint8_t temp = 99, press = 0xFF;

    // P3 = 0x0F;

    P30 = 1;
    P31 = 1;
    P32 = 1;
    P33 = 1;
    // P34 = 0;
    P35 = 0;
    P42 = 0;
    P44 = 0;
    /* P36 = P42;
    P37 = P44; */

    press = P3 & 0x0F;

    switch (state) {
    case 0: {
        if (press != 0x0F) {
            state = 1;
        }
        break;
    }

    case 1: {
        if (press == 0x0F) {
            state = 0;
        } else {
            P3 = press | 0xF0;
            // P34 = 1; P35 = 1;
            P42 = 1;
            P44 = 1;

            P36 = P42;
            P37 = P44;
            press = P3;

            state = 2;

            switch (press) {
            case 0x77: {
                value = 4;
                break;
            }
            case 0x7B: {
                value = 5;
                break;
            }
            case 0x7D: {
                value = 6;
                break;
            }
            case 0x7E: {
                value = 7;
                break;
            }

            case 0xB7: {
                value = 8;
                break;
            }
            case 0xBB: {
                value = 9;
                break;
            }
            case 0xBD: {
                value = 10;
                break;
            }
            case 0xBE: {
                value = 11;
                break;
            }

            case 0xD7: {
                value = 12;
                break;
            }
            case 0xDB: {
                value = 13;
                break;
            }
            case 0xDD: {
                value = 14;
                break;
            }
            case 0xDE: {
                value = 15;
                break;
            }

            case 0xE7: {
                value = 16;
                break;
            }
            case 0xEB: {
                value = 17;
                break;
            }
            case 0xED: {
                value = 18;
                break;
            }
            case 0xEE: {
                value = 19;
                break;
            }

                // 双按键 一字节计算方法为：左下角开始，先是行列，按下的列为0，其余为1，再是纵列。
                // 比如s4 s5 他们在同一列  -> 0111 0011 -> 0x73
            case 0x73: {
                value = 71;
                break;
            }
            default: {
                state = 0;
            }
            }
        }
    } break;

    case 2: {
        if (press != 0x0F) {
            i++;
            if (i >= 150) {
                i = 0;
                state = 3;
            }
        } else {
            i = 0;
            temp = value;
            value = 0;
            state = 0;
        }
    } break;

    case 3: {
        if (press == 0x0F) {
            temp = value + 20;
            value = 0;
            state = 0;
        }
    } break;
    }
    return temp;
}