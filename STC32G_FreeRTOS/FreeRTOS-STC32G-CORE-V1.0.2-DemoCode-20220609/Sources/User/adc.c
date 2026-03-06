#include "FreeRTOS.h"
#include "task.h"

#include "adc.h"

void vAdcInit( void )
{
    ADCTIM = 0x3f;		                                //ﺭﻟﻅﺣ ADC ﺥﻌﺎﺟﮌﺎﺷﮨ۲؛ADCﺎﺭﺹﻱﮌﺎﺙﻛﺛ۷ﺻﻠﺭﻟﻉﻧﺑﮩﻅﭖ
    ADCCFG = 0x2f;		                                //ﺭﻟﻅﺣ ADC ﮌﺎﻅﺽﺳ۹ﺵﭖﺱﺏﮌﺎﻅﺽ/2/16/16
    ADC_CONTR = 0x80;                                   //ﮌﺗﺥﻎ ADC ﺥ۲ﺟﻠ
}

//========================================================================
// ﭦﺁﮌﮮ: uint16_t usAdcGetResult(uint8_t ucChannel)
// ﺣﻟﮌﺉ: ﺎﻠﺹﺁﺓ۷ﭘﭼﺻﭨﺑﺳADCﺛﻕﺗﻳ.
// ﺎﺳﮌﮮ: ucChannel: ﺹ۰ﺿﮦﺻ۹ﻉ۹ﭨﭨﭖﺥADC.
// ﺓﭖﭨﻊ: 12ﺳﭨADCﺛﻕﺗﻳ.
// ﺍﮔﺎﺝ: V1.0, 2012-10-22
//========================================================================
uint16_t usAdcGetResult(uint8_t ucChannel)              //ucChannel:ADCﺱ۷ﭖﭺ,ﺫ۰ﻅﭖﺓﭘﺳ۶0~15
{
    uint16_t usResult;

    ADC_RES = 0;
    ADC_RESL = 0;

    ADC_CONTR = (ADC_CONTR & 0xF0) | 0x40 | ucChannel;  //ﺩﮪﭘﺁ AD ﻉ۹ﭨﭨ
    _nop_();
    _nop_();
    _nop_();
    _nop_();

    while((ADC_CONTR & 0x20) == 0);                     //ﭖﺫﺑﮮADCﻉ۹ﭨﭨﺛﻕﮌﺋ
    ADC_CONTR &= ~0x20;                                 //ﮄﮒﺏﮮADCﺛﻕﮌﺋﺎﻡﻅﺝ
    usResult = (((uint16_t)ADC_RES << 8) | ADC_RESL);

    return usResult;
}
