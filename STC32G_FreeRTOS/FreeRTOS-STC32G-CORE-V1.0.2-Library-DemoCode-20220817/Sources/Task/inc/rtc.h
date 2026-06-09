/**
 * @file rtc.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef RTC_H
#define RTC_H

/* RTCﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION( vRtcTask, pvParameters );

void vRtcUpdateDisplay( void );

extern uint8_t ucHour;                                  //RTCﺎﻛﭼﺟ(ﮌﺎ)
extern uint8_t ucMinute;                                //RTCﺎﻛﭼﺟ(ﺓﻅ)
extern uint8_t ucSecond;                                //RTCﺎﻛﭼﺟ(ﺣﻣ)

#endif
