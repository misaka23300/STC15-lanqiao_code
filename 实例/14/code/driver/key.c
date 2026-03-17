#include "key.h"

uint8_t key_scan()
{
    static uint8_t state, value, i;
    uint8_t press = 0xFF, temp = 99;
    P3 = 0x0F;
    P42 = 0;
    P44 = 0;
    P36 = P42;
    P37 = P44;

    press = P3 & 0x0F;

    switch (state) {
    case 0: {
        if (press != 0x0F) {
            state = 1;
        }
    } break;

    case 1: {
        if (press == 0x0F) {
            state = 0;
        } else {
            P3 = press | 0xF0;
            P42 = 1;
            P44 = 1;
            P36 = P42;
            P37 = P44;

            press = P3;
            state = 2;

            switch (press) {
            case 0x77:
                value = 4;
                break;
            case 0x7b:
                value = 5;
                break;
            case 0x7d:
                value = 6;
                break;
            default:
                state = 0;
            }
        }
    } break;

    case 2: {
        if (press != 0x0F) {
            i++;
            if (i > 100) {
                i = 0;
                state = 3;
            }
        } else {
            state = 0;
            temp = value;
            value = 0;
            i = 0;
        }
    } break;

    case 3: {
        if (press == 0x0F) {
            state = 0;
            temp = value + 20;
            value = 0;
        }
    } break;
    }

    return temp;
}

uint8_t key_read() // 读取键值的函数
{
    uint16_t Key_New;
    uint8_t key_value = 0;

    P44 = 0;
    P42 = 1;
    P35 = 1;
    //P34 = 1; // 扫描第一列
    Key_New = P3 & 0x0f; // 获取第一列的四行的位置的二进制数值

    P44 = 1;
    P42 = 0;
    P35 = 1;
    //P34 = 1; // 扫描第2列
    Key_New = (Key_New << 4) | (P3 & 0x0f);

    P44 = 1;
    P42 = 1;
    P35 = 0;
    //P34 = 1; // 扫描第3列
    Key_New = (Key_New << 4) | (P3 & 0x0f);

    P44 = 1;
    P42 = 1;
    P35 = 1;
    //P34 = 0; // 扫描第4列
    Key_New = (Key_New << 4) | (P3 & 0x0f);

    switch (~Key_New) {
    case 0x8000:
        key_value = 4;
        break; // S4
    case 0x4000:
        key_value = 5;
        break; // S5
    case 0x2000:
        key_value = 6;
        break; // S6
    case 0x1000:
        key_value = 7;
        break; // S7

    case 0x0800:
        key_value = 8;
        break; // S8
    case 0x0400:
        key_value = 9;
        break; // S9
    case 0x0200:
        key_value = 10;
        break; // S10
    case 0x0100:
        key_value = 11;
        break; // S11

    case 0x0080:
        key_value = 12;
        break; // S12
    case 0x0040:
        key_value = 13;
        break; // S13
    case 0x0020:
        key_value = 14;
        break; // S14
    case 0x0010:
        key_value = 15;
        break; // S15

    case 0x0008:
        key_value = 16;
        break; // S16
    case 0x0004:
        key_value = 17;
        break; // S17
    case 0x0002:
        key_value = 18;
        break; // S18
    case 0x0001:
        key_value = 19;
        break; // S19

    default:
        key_value = 0;
        break;
    }
    return key_value;
}
