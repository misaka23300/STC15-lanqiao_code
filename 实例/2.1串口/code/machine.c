/**
 * @file machine.c
 * @brief 机器控制模块
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "machine.h"

void latch( uint8_t i )
{
    switch ( i )
    {
        case 4: { P2 = ( P2 & 0x1F ) | 0x80; break; }
        case 5: { P2 = ( P2 & 0x1F ) | 0xA0; break; }
        case 6: { P2 = ( P2 & 0x1F ) | 0xC0; break; }
        case 7: { P2 = ( P2 & 0x1F ) | 0xE0; break; }
    }

    P2 = P2 & 0x1F;
}