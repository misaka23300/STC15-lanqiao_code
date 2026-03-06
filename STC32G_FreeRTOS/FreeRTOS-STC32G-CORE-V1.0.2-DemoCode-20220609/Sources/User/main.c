
/*
 * FreeRTOS STC port V1.0.2
 * 
 * STC32G12K128ﺗ۵ﺥﻎﺙﮨﺛﻠ۲ﭦ
 *    2ﻉﻠ CAN, 3ﻉﻠLin, USB, 32ﺳﭨ 8051, RMB5,
 *    ﺕﻑﺝ،ﻉﺙ12ﺳﭨADC, DMA ﻅ۶ﺏﻅ(TFTﺎﮌﺩﭼ, ADC, 4ﻉﻠﺑ؟ﺟﻌ, SPI, I2C )
 *  
 *  ﺕﺊﺳﭨﺽﺣﭨ۶ﺿﻌﭦﮩﺷﺋﭖﺥﮌﺗﺽﺣﺗﮮﺏﮊﻅﺷ۲؛ﺫﻝﺗﻳﺓ۱ﺵﻅﺽﺷﺎﭨﻁﮮﺫﺓﭖﺥﭖﻊﺓﺛﭨﮨﻁﻑ
 *  ﺽﺷﺟﺭﺕﺥﺭﺩﭖﺥﭖﻊﺓﺛ۲؛ﮄﻣﭦﺱSTCﭼ۹ﺵﭖ۲؛ﺽﺭSTCﺗﻋﺓﺛﺛﺋﺷﺷﺱﺏﺻﭨﺷﻐﺕﺥﺎ۱ﺕﮰﺷﺡﺍﮔﺎﺝ
 *
 *  ﺫﮪﺥﻲﭖﺥﺑﻲﺡﻣﭨﮨﺳﺥﻁﺡﻅﺷﺷﻟﺻ۹ﺻﮮﺽﺣﺎﺝﺏﮊﺷﮨﺍﮰﻅﺷﭖﺥﺎﺟﺓﻅﺻﺩﻅﺎﺑﻲﺡﻣ۲؛ﮄﻣﺿﻌﺥﻲﭖﺥ
 *  ﺑﻲﺡﻣﭨﮨﺳﺥﻁﺡﻅﺷﻉ۱ﺣﺊﺎﺳﺟﺙﭨﮨﮌﺗﺽﺣﭼﺯSTCﭖﺥFreeRTOSﭖﺥﺻﺩﻅﺎﺑﻲﺡﻣ
*/

#include "FreeRTOS.h"
#include "task.h"

#include "display.h"
#include "rtc.h"
#include "ntc.h"
#include "adckey.h"
#include "uart2_3.h"
#include "MatrixKey.h"
#include "DebugPrintf.h"

void vSystemInit( void );

void main( void )
{
    /* ﺵﭖﺱﺏﺏﺀﮌﺙﭨﺁ */
    vSystemInit();

	/* ﺑﺑﺛ۷ﺫﺳﺳﮦ */
    xTaskCreate((TaskFunction_t )vDisplayTask,
                (const char*    )"DISPLAY",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES + 1),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vRtcTask,
                (const char*    )"RTC",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES + 1),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vAdcKeyTask,
                (const char*    )"ADCKEY",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vNtcTask,
                (const char*    )"NTC",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vUart2_3Task,
                (const char*    )"UART2_3",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )1000,  //ﻉ۱ﺻﻗpvParametersﺎﺳﮌﮮﺑ،ﭖﻊﻅﺓﭨﮨﻁﻑﭼ۱ﺙﺑﮌﮮﮌﺎﻅﭨﺽﺷﭖﺱ24ﺳﭨﮌﮄﺽﺷﺷ۶ﺳﭨ۲؛ﻉﻧﺕﻑ8ﺳﭨﺎﻓﺻﻣﮌﺎﭨﻕﻉﺿﭘﺁﮊﻧ0. ﺟﺭﺱ۷ﺗﮮﺎﻛﭼﺟﭨﮨﻁﻑﺏ۲ﭼﺟﺑ،ﺯﺱ32ﻉﻅﺛﻌﮌﮮﺝﻏ.
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vMatrixKeyTask,
                (const char*    )"MatrixKey",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);

    /* ﺩﮪﭘﺁﺫﺳﺳﮦﭖﺊﭘﺫﺩﺊﺟ۹ﮌﺙﺫﺳﺳﮦﭖﺊﭘﺫ */
    vTaskStartScheduler();

    /* ﻁﮮﺏ۲ﮄﻠﺟﺉﺵﺡﺎﭨﭨﻕﺿﺯﺷﺷﭖﺛﺑﺯﺑ۵ */
    while (1);
}

/* ﺵﭖﺱﺏﺏﺀﮌﺙﭨﺁﺑﻲﺡﻣ */
void vSystemInit( void )
{
    WTST = 0;     //ﺭﻟﻅﺣﺏﮊﺷﮨﻅﺕﭼﻧﺹﺽﮌﺎﺎﺳﮌﮮ۲؛ﺕﺏﻅﭖﺳ۹0ﺟﺭﺛ،CPUﻅﺑﺷﺷﻅﺕﭼﻧﭖﺥﺯﻋﭘﺫﺭﻟﻅﺣﺳ۹ﻉﻧﺟﮞ
    EAXFR = 1;    //ﭺ۸ﻁﺗﺙﺥﺑﮔﺩﺊ(XFR)ﺓﺣﺳﮌﮌﺗﺥﻎ
    CKCON = 0;    //ﮊﻕﺕﻑﺓﺣﺳﮌXRAMﺯﻋﭘﺫ

    P0M1 = 0x00;   P0M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    P1M1 = 0x00;   P1M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    P2M1 = 0x00;   P2M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    P3M1 = 0x00;   P3M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    P4M1 = 0x00;   P4M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    P5M1 = 0x00;   P5M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    P6M1 = 0x00;   P6M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    P7M1 = 0x00;   P7M0 = 0x00;     //ﺭﻟﻅﺣﺳ۹ﻉﺙﺯ،ﺵﮨﺟﻌ
    
//    DebugPrintfInit();
//    printf("STC32G FreeRTOS ﺎﻗﮌﺿﺏﮊﺷﮨ!\r\n");
}
