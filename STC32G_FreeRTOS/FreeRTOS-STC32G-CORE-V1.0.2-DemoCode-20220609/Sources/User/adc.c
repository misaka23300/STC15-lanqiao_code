#include "FreeRTOS.h"
#include "task.h"

#include "adc.h"

void vAdcInit( void )
{
    ADCTIM = 0x3f;		                                //设置 ADC 内部时序，ADC采样时间建议设最大值
    ADCCFG = 0x2f;		                                //设置 ADC 时钟为系统时钟/2/16/16
    ADC_CONTR = 0x80;                                   //使能 ADC 模块
}

//========================================================================
// 函数: uint16_t usAdcGetResult(uint8_t ucChannel)
// 描述: 查询法读一次ADC结果.
// 参数: ucChannel: 选择要转换的ADC.
// 返回: 12位ADC结果.
// 版本: V1.0, 2012-10-22
//========================================================================
uint16_t usAdcGetResult(uint8_t ucChannel)              //ucChannel:ADC通道,取值范围0~15
{
    uint16_t usResult;

    ADC_RES = 0;
    ADC_RESL = 0;

    ADC_CONTR = (ADC_CONTR & 0xF0) | 0x40 | ucChannel;  //启动 AD 转换
    _nop_();
    _nop_();
    _nop_();
    _nop_();

    while((ADC_CONTR & 0x20) == 0);                     //等待ADC转换结束
    ADC_CONTR &= ~0x20;                                 //清除ADC结束标志
    usResult = (((uint16_t)ADC_RES << 8) | ADC_RESL);

    return usResult;
}
