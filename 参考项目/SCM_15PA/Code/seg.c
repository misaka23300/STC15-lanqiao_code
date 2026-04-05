#include "seg.h"


//0123456789-OFF-E                                                                                
code unsigned char segCode[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff,0xC1,0xbf,0x8c,0xC7,0x88, 0x8E,0x89};
static unsigned char segData[8] = {1,2,3,4,5,6,7,8};

//
void setSegData(unsigned char seg_pos, unsigned char content)
{
    segData[seg_pos] = content;
}

//
void segDsp(void)
{
    static unsigned char comBit = 0;
    SEG(0xFF);
    COM(1 << comBit);

    SEG(segCode[segData[comBit]]);

    if(++comBit >= 8){
        comBit = 0;
    }
}