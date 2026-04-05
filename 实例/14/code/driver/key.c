#include "key.h"

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

    //P34 = 0;
    P35 = 0;
    P42 = 0;
    P44 = 0;

    // 获取列
    P36 = P42;
    P37 = P44;
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
            P3 = press | 0xF0;// 屏蔽p34改为0xe0
            
    
            //P34 = 1; 
            P35 = 1;
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
