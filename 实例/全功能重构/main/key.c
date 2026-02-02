/**
 * @file key.c
 * @brief 按键扫描与去抖/长按识别模块
 * @details 通过读取 P3 口并配合 P4.x 控制列线实现矩阵按键扫描，
 *          使用简单状态机进行去抖与长按判断，返回简化的按键码或默认值。
 * @date 2025-12-10
 */

#include "key.h"

/**
 * @brief 扫描按键并进行去抖与长按识别
 *
 * 本函数为轮询式扫描，内部使用静态局部变量维护状态机：
 * - state: 当前状态（0=空闲,1=检测到按下,2=消抖计时,3=长按确认）
 * - i: 用于消抖/长按计数的计时器
 * - value: 当前解析出的按键短按码
 * - temp: 返回值缓冲，初始为 99 表示无按键
 *
 * 读取流程简述：
 * 1. 将 P3 设置为输入/上拉相关，然后通过 P4 控制列线（P42,P44）扫描。
 * 2. 当检测到按下（press != 0x0F）进入去抖并解析按键码。
 * 3. 若在去抖期内持续按下，计数达到阈值进入长按状态并返回不同码。
 *
 * @return uint8_t 返回按键码：短按返回 value，对应 case 中设置的值；
 *         长按返回 value + 20；无按键返回初始值 99。
 * @note 该函数应被主循环或定时器周期性调用以获得正确的去抖与长按识别。
 */
uint8_t key_scan()
{
    static uint8_t i;
    static uint8_t state;
    static uint8_t value;

    uint8_t press = 0xFF;
    uint8_t temp = 99;

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
                    default: state = 0;
                }
            }
        } break;

        case 2: {
            if (press != 0x0F) {
                i++;
                if (i > 70) {
                    i = 0;
                    state = 3;
                }
            } else {
                i = 0;
                state = 0;
                temp = value;
                value = 0;
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
