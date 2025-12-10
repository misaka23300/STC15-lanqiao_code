#include "machine.h"


void clean_display()
{
    
    P0M1 = 0;   P0M0 = 0;   //设置为准双向口
    P1M1 = 0;   P1M0 = 0;   //设置为准双向口
    P2M1 = 0;   P2M0 = 0;   //设置为准双向口
    P3M1 = 0;   P3M0 = 0;   //设置为准双向口
    P4M1 = 0;   P4M0 = 0;   //设置为准双向口
    P5M1 = 0;   P5M0 = 0;   //设置为准双向口
    P6M1 = 0;   P6M0 = 0;   //设置为准双向口
    P7M1 = 0;   P7M0 = 0;   //设置为准双向口
    P3M0 = 0x00; P3M1 = 0x10; 


    P0 = 0xFF;
    latch(4);

    P0 = 0xAF;
    latch(5);

    P0 = 0x00;
    latch(6);

    P0 = 0xFF;
    latch(7);

}

void latch(uint8_t i)
{
    switch (i)
    {
        case 4: { P2 = (P2 & 0x1F) | 0x80; break; }
        case 5: { P2 = (P2 & 0x1F) | 0xA0; break; }
        case 6: { P2 = (P2 & 0x1F) | 0xC0; break; }
        case 7: { P2 = (P2 & 0x1F) | 0xE0; break; }
        
    }
		P2 = (P2 & 0x1F);
}


