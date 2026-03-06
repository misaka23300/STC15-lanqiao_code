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

ﺎﺝﭺﮮﺏﮊﭨﻱﺽﻌSTC32Gﺳ۹ﻅﺊﺟﻊﺷﺝﺩ؛ﭖﺥﮌﭖﺹﻠﺵﻛﺛﺋﺷﺷﺎﻓﺷﺑﺎﻗﮌﺿ۰۲

ﺱ۷ﺗﮮADCﺎﺭﺙﺁﺍﺑﺙﮰﺟﻌADCﻅﭖ۲؛ﺕﻱﺝﻏADCﻅﭖﺭﻟﻅﺣﺙﮰﺡﻣﺳ۹1~16.

ﺍﺑﺙﮰﻅﭨﻅ۶ﺏﻅﭖ۴ﺙﮰﺍﺑﺵﺡ, ﺎﭨﻅ۶ﺏﻅﭘﻓﺙﮰﺱ؛ﮌﺎﺍﺑﺵﺡ, ﺥﮄﺹﻱﺛ،ﭨﻕﺽﺷﺎﭨﺟﺭﺿ۳ﻅ۹ﭖﺥﺛﻕﺗﻳ.

ﺙﮰﺍﺑﺵﺡﺏ؛ﺗﮮ1ﺣﻣﭦﮩ,ﺛ،ﺻﺿ10ﺙﮰ/ﺣﻣﭖﺥﺯﻋﭘﺫﮊﻕﺗ۸ﻅﻊﺙﮰﮌﻛﺏﺉ. ﺽﺣﭨ۶ﻅﭨﺷﻟﺻ۹ﺙﮞﺎﻗKeyCodeﮌﮄﺓﮦﺓﮄ0ﭺﺑﺧﺷﭘﺵﺙﮰﮌﮄﺓﮦﺍﺑﺵﺡ.

ﭖﺊﻁﻳﮌﺎﺙﻛﺙﮰ:
ﺙﮰﺡﻣ1: ﺷ۰ﮌﺎ+.
ﺙﮰﺡﻣ2: ﺷ۰ﮌﺎ-.
ﺙﮰﺡﻣ3: ﺓﻅﻅﺽ+.
ﺙﮰﺡﻣ4: ﺓﻅﻅﺽ-.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "STC32G_ADC.h"

#include "adckey.h"
#include "rtc.h"
//#include "display.h"

#define ADCKEY_CHANNEL          0                       //ADCﺍﺑﺙﮰﭖﺥﮌﻛﺫﻣﺱ۷ﭖﭺ۲۷P1.0۲۸
#define ADC_OFFSET              64                      //ADCﺍﺑﺙﮰﺭ۷ﺣﻟﮌﺎﭖﺥﺩ،ﺎﻧﺓﭘﺳ۶


static void prvAdcKeyInit( void );
static void prvAdcCalculateKey( void );
static void prvAdcKeyEvent( void );


static uint8_t ucKeyState;                              //ADCﺍﺑﺙﮰﻉﺑﮊ؛
static uint8_t ucKeyState1;
static uint8_t ucKeyState2;
static uint8_t ucKeyState3;
static uint8_t ucKeyHoldCnt;                            //ﺙﮰﺍﺑﺵﺡﺙﺩﮌﺎ

uint8_t ucKeyCode;                                      //ﺕﺋﺽﺣﭨ۶ﮌﺗﺽﺣﭖﺥﺙﮰﺡﻣ, 1~16ﺽﺷﺷ۶

/* ADCﺍﺑﺙﮰﺭ۷ﺣﻟﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION( vAdcKeyTask, pvParameters )
{
    
	UNUSED( pvParameters );

    prvAdcKeyInit();
    while(1)
    {
        prvAdcCalculateKey();
        prvAdcKeyEvent();

        vTaskDelay(10);
    }
    
    vTaskDelete(NULL);
}   

static void prvAdcKeyInit( void )
{
//    P1M1 |= 0x01;                                       //ﺭﻟﻅﺣ P1.0 ﺳ۹ ADC ﮌﻛﺫﻣﺟﻌ
//    P1M0 &= ~0x01;

    ucKeyState  = 0;
    ucKeyState1 = 0;
    ucKeyState2 = 0;
    ucKeyState3 = 0;                                    //ﺙﮰﻉﺑﮊ؛
    ucKeyHoldCnt = 0;                                   //ﺙﮰﺍﺑﺵﺡﺙﺩﮌﺎ
    ucKeyCode = 0;                                      //ﺕﺋﺽﺣﭨ۶ﮌﺗﺽﺣﭖﺥﺙﮰﺡﻣ, 1~16ﺽﺷﺷ۶
}

/***************** ADCﺙﮰﺧﮊﺙﺩﺯﻙﺙﮰﺡﻣ *****************************
ﭖﻝﺡﺓﭦﺱﺫﻥﺙﹼﺯﻙﺓ۷ﺭﻟﺙﺩ: Coody
ﺎﺝADCﺙﮰﺧﮊﺓﺛﺍﺕﺿﻌﭦﻎﭘﻓﮌﭖﺙﮌﺎﻲﺩﺓﺭﻟﺙﺩﻅﺷ, ﺹﻠﻅ۳ﭼﺯﺩﻛﺳﺫﭘ۷ﺟﺭﺟﺟ, ﺙﺑﮌﺗﺍﺑﺙﮰﮌﺗﺽﺣﭖﺙﭖﻝﺥ۳,ﭘﺙﭦﻎﺟﺭﺟﺟ.
16ﺕﺉﺙﮰ,ﭺﻥﺡﻍﺭﺵﺕﺊﺕﺉﺙﮰﭘﺿﺽ۵ﭖﺥADCﻅﭖﺳ۹ (4096 / 16) * k = 256 * k, k = 1 ~ 16, ﮊﻊﺎﻭﭖﺥ, k=16ﮌﺎ,ﭘﺿﺽ۵ﭖﺥADCﻅﭖﮌﮄ4095.
ﭖ،ﮌﮄﮌﭖﺙﮌﭨﻕﺽﺷﺩ،ﺎﻧ,ﺿﮨﺧﺷﭘﺵﮌﺎﺵﻐﻅﺩﻁﻗﺕﺉﺩ،ﺎﻧ, ADC_OFFSETﺳ۹+-ﺩ،ﺎﻧ, ﺿﮨADCﻅﭖﺿﻌ (256*k-ADC_OFFSET) ﺽﻣ (256*k+ADC_OFFSET)ﻅ؟ﺙﻛﺳ۹ﺙﮰﺽﺷﺷ۶.
ﺙﻛﺕﮪﺻﭨﭘ۷ﭖﺥﮌﺎﺙﻛ,ﺝﺱﺎﺭﺹﻱﺻﭨﺑﺳADC,ﺎﺫﺫﻝ10ms.
ﺳ۹ﭼﺯﺎﻎﺣﻗﺧﺙﺫﭨﭖﺥADCﻅﭖﺳﮩﺧﺷ, ﭨﮨﻁﻑﺎﻎﺣﻗADCﺿﻌﺭﺵﺭﮮﭨﮨﺵﺡﺛﭖﮌﺎﺳﮩﺧﺷ, ﮌﺗﺽﺣﭼ؛ﺷﺋ3ﺑﺳADCﻅﭖﺝﻱﺿﻌﺩ،ﺎﻧﺓﭘﺳ۶ﺥﻌﮌﺎ, ADCﻅﭖﺎﺧﺫﺵﺳ۹ﺽﺷﺷ۶.
ﺻﺿﺭﺵﺯﻙﺓ۷, ﺥﻎﺎ۲ﻅ۳ﭘﭼﺙﮰﺓﮄﺏ۲ﺟﺭﺟﺟ.
**********************************************/
static void prvAdcCalculateKey( void )
{
    uint16_t usResult;
    uint8_t i;
    uint16_t j;
    
    usResult = Get_ADCResult(ADCKEY_CHANNEL);
    
    if(usResult < (256 - ADC_OFFSET))
    {
        ucKeyState = 0;                                 //ﺙﮰﻉﺑﮊ؛ﺗﻠ0
        ucKeyHoldCnt = 0;
    }
    
    j = 256;
    for (i = 1; i <= 16; i++)
    {
        if ((usResult >= (j - ADC_OFFSET)) &&
            (usResult <= (j + ADC_OFFSET)))
           break;                                       //ﺧﺷﭘﺵﮌﮄﺓﮦﺿﻌﺩ،ﺎﻧﺓﭘﺳ۶ﺥﻌ
        j += 256;
    }
    
    ucKeyState3 = ucKeyState2;
    ucKeyState2 = ucKeyState1;
    
    if (i > 16)
        ucKeyState1 = 0;                                //ﺙﮰﺳﻐﺷ۶
    else                                                //ﺙﮰﺽﺷﺷ۶
    {
        ucKeyState1 = i;
        if ((ucKeyState3 == ucKeyState2) &&
            (ucKeyState2 == ucKeyState1) &&
            (ucKeyState3 > 0) &&
            (ucKeyState2 > 0) &&
            (ucKeyState1 > 0))
        {
            if (ucKeyState == 0)                        //ﭖﻌﺻﭨﺑﺳﺙﮞﺎﻗﭖﺛ
            {
                ucKeyCode = i;                          //ﺎ۲ﺑﮔﺙﮰﺡﻣ
                ucKeyState = i;                         //ﺎ۲ﺑﮔﺙﮰﻉﺑﮊ؛
                ucKeyHoldCnt = 0;
            }
            
            if (ucKeyState == i)                        //ﭼ؛ﺷﺋﺙﮞﺎﻗﭖﺛﺱ؛ﺻﭨﺙﮰﺍﺑﻉﺧ
            {
                if (++ucKeyHoldCnt >= 100)              //ﺍﺑﺵﺡ1ﺣﻣﭦﮩ,ﺻﺿ10ﺑﺳﺣﺟﺣﻣﭖﺥﺯﻋﭘﺫRepeat Key
                {
                    ucKeyHoldCnt = 90;
                    ucKeyCode  = i;                     //ﺎ۲ﺑﮔﺙﮰﺡﻣ
                }
            }
            else
                ucKeyHoldCnt = 0;                       //ﺍﺑﺵﺡﮌﺎﺙﻛﺙﺩﮌﮮﺗﻠ0
        }
    }
}

static void prvAdcKeyEvent( void )
{
    uint8_t ucCode;
    
    ucCode = ucKeyCode;
    ucKeyCode = 0;
    
    if (ucCode > 0)                                     //ﺽﺷﺙﮰﺍﺑﺵﺡ
    {
//        pucLEDBuffer[6] = ucCode / 10;                  //ﺵﺿﮌﺝﺙﮰﺡﻣ
//        pucLEDBuffer[7] = ucCode % 10;                  //ﺵﺿﮌﺝﺙﮰﺡﻣ

        switch (ucCode)
        {
        case 1:                                         //hour +1
            if (++ucHour >= 24)
                ucHour = 0;
            break;
        case 2:                                         //hour -1
            if (--ucHour >= 24)
                ucHour = 23;
            break;
        case 3:                                         //minute +1
            ucSecond = 0;
            if (++ucMinute >= 60)
                ucMinute = 0;
            break;
        case 4:                                         //minute -1
            ucSecond = 0;
            if (--ucMinute >= 60)
                ucMinute = 59;
            break;
        default:
            return;
        }
        
        vRtcUpdateDisplay();
    }
}


