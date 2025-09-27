#include "stc15F2k60s2.h"
#include "stdbool.h"

int main()
{
    P0 = 0xFF;
    P2 = (P2 & 0x1F) | 0xC0;
    P2 = P2 & 0x1F;

    P0 = 0xFF;
    P2 = (P2 & 0x1F) | 0xE0;
    P2 = P2 & 0x1F;

    P0 = ~0x01;
    P2 = (P2 & 0x1F) | 0x80;
    P2 = P2 & 0x1F;
    while(true);
}