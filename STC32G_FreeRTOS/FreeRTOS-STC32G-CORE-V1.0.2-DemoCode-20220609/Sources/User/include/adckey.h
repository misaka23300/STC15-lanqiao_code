/**
 * @file adckey.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef ADCKEY_H
#define ADCKEY_H

/* ADCﺍﺑﺙﮰﺭ۷ﺣﻟﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION_PROTO( vAdcKeyTask, pvParameters );

extern uint8_t ucKeyCode;                               //ﺕﺋﺽﺣﭨ۶ﮌﺗﺽﺣﭖﺥﺙﮰﺡﻣ, 1~16ﺽﺷﺷ۶

#endif
