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

ﭘﮊﺛﺽﮌﭖﺹﻠﺵﻛﺭﺵﭖﺥJ7۰۱J8ﮊﺋﺵﻑﺛﺋﺷﺷﺎﻗﮌﺿ.

ﺑ؟ﺟﻌ3ﭘ۷ﮌﺎﺓ۱ﺯﺱﺻﭨﺑ؟ﮌﮮﺝﻏﺕﺋﺑ؟ﺟﻌ2.

ﺑ؟ﺟﻌ2ﮌﻛﺏﺉﺑﺽﺑ؟ﺟﻌ3ﺛﺽﮌﻁﭖﺛﭖﺥﮌﮮﺝﻏ.

ﺱﻱﺑ؟ﺟﻌ2ﺓ۱ﺯﺱﮌﮮﺝﻏ۲؛MCUﮌﻁﭖﺛﭦﮩﺑﺽﺑ؟ﺟﻌ2ﺿ­ﺹﻱﮌﻛﺏﺉ.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "STC32G_UART.h"
#include "uart2_3.h"

extern void TX2_write2buff(uint8_t dat);

uint16_t Sec_Cnt;    //1ﺣﻣﺙﺩﮌﮮ

/* UARTﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION( vUart2_3Task, pvParameters )
{
    uint8_t i;
    
    Sec_Cnt = 0;

    PrintString2("STC32G UART2-UART3 Test Programme!\r\n");  //UART2ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺓﻳﺑ؟
    PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺓﻳﺑ؟
    while(1)
    {
        Sec_Cnt++;
        if(Sec_Cnt >= (uint16_t)pvParameters)
        {
            Sec_Cnt = 0;
            PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺓﻳﺑ؟
        }

        if(COM2.RX_TimeOut > 0)
        {
            if(--COM2.RX_TimeOut == 0)
            {
                if(COM2.RX_Cnt > 0)
                {
                    for(i=0; i<COM2.RX_Cnt; i++)    TX2_write2buff(RX2_Buffer[i]);    //ﺍﺹﮌﻁﭖﺛﭖﺥﮌﮮﺝﻏﺱ۷ﺗﮮﺑ؟ﺟﻌ2ﮌﻛﺏﺉ
                    COM2.RX_Cnt = 0;   //ﮄﮒﺏﮮﻉﻅﺛﻌﮌﮮ
                }
            }
        }
        
        vTaskDelay(1);
    }
    
    vTaskDelete(NULL);
}   
