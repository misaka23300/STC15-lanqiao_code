
#ifndef RTC_H
#define RTC_H


/* RTCﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION_PROTO( vRtcTask, pvParameters );

void vRtcUpdateDisplay( void );

extern uint8_t ucHour;                                  //RTCﺎﻛﭼﺟ(ﮌﺎ)
extern uint8_t ucMinute;                                //RTCﺎﻛﭼﺟ(ﺓﻅ)
extern uint8_t ucSecond;                                //RTCﺎﻛﭼﺟ(ﺣﻣ)


#endif
