/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ﺫﻝﺗﻳﺻ۹ﺿﻌﺏﮊﺷﮨﻅﺷﮌﺗﺽﺣﺑﺯﺑﻲﺡﻣ,ﮄﻣﺿﻌﺏﮊﺷﮨﻅﺷﻉ۱ﺣﺊﮌﺗﺽﺣﭼﺯSTCﭖﺥﻉﮌﭼﺵﺙﺍﺏﮊﺷﮨ            */
/*---------------------------------------------------------------------*/


/*************  ﺗ۵ﺥﻎﺯﭖﺣﺊ    **************

ﺎﺝﭺﮮﺏﮊﭨﻱﺽﻌSTC32Gﺳ۹ﻅﺊﺟﻊﺷﺝﺩ؛ﭖﺥﮌﭖﺹﻠﺵﻛ9ﺛﺋﺷﺷﺎﻓﺷﺑﺎﻗﮌﺿ.

ﺱ۷ﺗﮮP5.4ﺟﻌﮌﻛﺏﺉﭖﺱﭖﻝﺩﺛﮄﮮﭘﺁﺽﺷﺿﺑﺓﻛﺣﻱﺩﺊ.

ﺷﺷﭼﺷﺭ۷ﺣﻟﺍﺑﺙﮰﺣﺟﺕﺉﺍﺑﺙﮰﺍﺑﺵﺡﭦﮩﺓﻛﺣﻱﺩﺊﺵﮞﺻﭨﺭﻱ.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "MatrixKey.h"

/****************************** ﺽﺣﭨ۶ﭘ۷ﺻﮒﭦﻡ ***********************************/

sbit BEEP = P5^4;

uint8_t cntms;
uint8_t KeyCode;    //ﺕﺋﺽﺣﭨ۶ﮌﺗﺽﺣﭖﺥﺙﮰﺡﻣ, 1~16ﺽﺷﺷ۶
uint8_t IO_KeyState, IO_KeyState1, IO_KeyHoldCnt;    //ﺷﺷﭼﺷﺙﮰﺧﮊﺎﻛﭼﺟ

void MatrixKeyScan(void);

/* RTCﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION_PROTO( vMatrixKeyTask, pvParameters )
{
    UNUSED( pvParameters );
    
    P5M1 &= ~0x10;   P5M0 |= 0x10;   //ﺭﻟﻅﺣP5.4ﺳ۹ﺱﺩﺱﮞﮌﻛﺏﺉ
    BEEP = 1;  //ﺓﻛﺣﻱﺩﺊﺗﻊﺎﻁ
    while(1)
    {
        if(cntms > 0)
        {
            cntms--;
        }
        else
        {
            BEEP = 1;    //ﺓﻛﺣﻱﺩﺊﺗﻊﺎﻁ
        }

        MatrixKeyScan();
        if(KeyCode > 0)  //ﺽﺷﺙﮰﺍﺑﺵﺡ
        {
            KeyCode = 0;
            BEEP = 0;    //ﺓﻛﺣﻱﺩﺊﺵﮞﺩﻭ
            cntms = 5;   //ﺏﻅﺷﺋﮌﺎﺙﻛ 5*50ms
        }
        
        vTaskDelay(50);
    }
    
    vTaskDelete(NULL);
}   

/*****************************************************
    ﺷﺷﭼﺷﺙﮰﺭ۷ﺣﻟﺏﮊﺷﮨ
    ﮌﺗﺽﺣXYﺎﻠﻁﺻ4x4ﺙﮰﭖﺥﺓﺛﺓ۷۲؛ﻅﭨﺥﻎﭖ۴ﺙﮰ۲؛ﺯﻋﭘﺫﺟﮞ

   Y     P04      P05      P06      P07
          |        |        |        |
X         |        |        |        |
P00 ---- K00 ---- K01 ---- K02 ---- K03 ----
          |        |        |        |
P01 ---- K04 ---- K05 ---- K06 ---- K07 ----
          |        |        |        |
P02 ---- K08 ---- K09 ---- K10 ---- K11 ----
          |        |        |        |
P03 ---- K12 ---- K13 ---- K14 ---- K15 ----
          |        |        |        |
******************************************************/

uint8_t code T_KeyTable[16] = {0,1,2,0,3,0,0,0,4,0,0,0,0,0,0,0};

void IO_KeyDelay(void)
{
    uint8_t i;
    i = 60;
    while(--i)  ;
}

void MatrixKeyScan(void)    //50ms call
{
    uint8_t  j;

    j = IO_KeyState1;   //ﺎ۲ﺑﮔﺭﺵﺻﭨﺑﺳﻉﺑﮊ؛

    P0 = 0xf0;  //Xﭖﺱ۲؛ﭘﭼY
    IO_KeyDelay();
    IO_KeyState1 = P0 & 0xf0;

    P0 = 0x0f;  //Yﭖﺱ۲؛ﭘﭼX
    IO_KeyDelay();
    IO_KeyState1 |= (P0 & 0x0f);
    IO_KeyState1 ^= 0xff;   //ﺫ۰ﺓﺑ
    
    if(j == IO_KeyState1)   //ﭼ؛ﺷﺋﭼﺛﺑﺳﭘﭼﺵﻓﭖﺫ
    {
        j = IO_KeyState;
        IO_KeyState = IO_KeyState1;
        if(IO_KeyState != 0)    //ﺽﺷﺙﮰﺍﺑﺵﺡ
        {
            F0 = 0;
            if(j == 0)  F0 = 1; //ﭖﻌﺻﭨﺑﺳﺍﺑﺵﺡ
            else if(j == IO_KeyState)
            {
                if(++IO_KeyHoldCnt >= 20)   //1ﺣﻣﭦﮩﻅﻊﺙﮰ
                {
                    IO_KeyHoldCnt = 18;
                    F0 = 1;
                }
            }
            if(F0)
            {
                j = T_KeyTable[IO_KeyState >> 4];
                if((j != 0) && (T_KeyTable[IO_KeyState& 0x0f] != 0)) 
                    KeyCode = (j - 1) * 4 + T_KeyTable[IO_KeyState & 0x0f] + 16;    //ﺙﺩﺯﻙﺙﮰﺡﻣ۲؛17~32
            }
        }
        else    IO_KeyHoldCnt = 0;
    }
    P0 = 0xff;
}
