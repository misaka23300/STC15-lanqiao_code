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

ﺽﺣSTCﭖﺥMCUﭖﺥIOﺓﺛﮌﺛﮄﮮﭘﺁ8ﺳﭨﮌﮮﺡﻣﺗﻎ۰۲

ﺵﺿﮌﺝﺷ۶ﺗﻳﺳ۹: ﺥ۲ﺥﻗﮌﮮﺡﻣﮌﺎﻅﺽ.

ﻉﮩﺎﻑ4ﺳﭨLEDﺵﺿﮌﺝﮌﺎﺙﻛ(ﺷ۰ﮌﺎ,ﺓﻅﻅﺽ).

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "rtc.h"
#include "display.h"

static void prvRtcInit( void );
static void prvRtcCounter( void );

void vRtcUpdateDisplay( void );

static uint8_t ucDotState;                              //ﺣﻣﺭﭼﺵﺿﮌﺝﻉﺑﮊ؛

uint8_t ucHour;                                         //ﮌﺎﻅﺽﺎﻛﭼﺟ(ﮌﺎ)
uint8_t ucMinute;                                       //ﮌﺎﻅﺽﺎﻛﭼﺟ(ﺓﻅ)
uint8_t ucSecond;                                       //ﮌﺎﻅﺽﺎﻛﭼﺟ(ﺣﻣ)

/* RTCﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION( vRtcTask, pvParameters )
{
    
    UNUSED( pvParameters );
    
    prvRtcInit();
    while(1)
    {
        prvRtcCounter();
        vRtcUpdateDisplay();
        vTaskDelay(500);
    }
    
    vTaskDelete(NULL);
}   

static void prvRtcInit( void )
{
    ucHour   = 12;                                      //ﺏﺀﮌﺙﭨﺁﮌﺎﺙﻛﻅﭖ
    ucMinute = 0;
    ucSecond = 0;
    ucDotState = 0;
}


/********************** ﺵﺿﮌﺝﮌﺎﻅﺽﭦﺁﮌﮮ ************************/
void vRtcUpdateDisplay( void )
{
    pucLEDBuffer[0] = ucHour >= 10 ? ucHour / 10 : DIS_BLACK;
    pucLEDBuffer[1] = ucHour % 10;
    pucLEDBuffer[2] = ucMinute / 10;
    pucLEDBuffer[3] = ucMinute % 10;
    
    if (ucDotState)
        pucLEDBuffer[1] |= DIS_DOT;                     //ﺷ۰ﮌﺎﭦﮩﭖﺥﺷ۰ﮌﮮﭖﻙﻉﺉﺣﻣﺭﭼ
}

/********************** ﮌﺎﻅﺽﺹﻏﮌﺝﭦﺁﮌﮮ ************************/
static void prvRtcCounter( void )
{
    ucDotState = !ucDotState;
    
    if (!ucDotState) return;

    if(++ucSecond >= 60)
    {
        ucSecond = 0;
        if(++ucMinute >= 60)
        {
            ucMinute = 0;
            if(++ucHour >= 24)
                ucHour = 0;
        }
    }
}
