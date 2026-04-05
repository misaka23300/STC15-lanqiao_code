#include "delay.h"

/********************** 软件延时 **************************/

void delay_ms(uint8_t ms)
{
	uint16_t i;
	do
	{
		i = MAIN_Fosc / 13000;
		while (--i)
			; //14T per loop
	} while (--ms);
}

void delay_10us()
{
	unsigned char i;

#if (MAIN_Fosc == 11059200L)
	_nop_();
	i = 25;
#elif (MAIN_Fosc == 12000000L)
	_nop_();
	_nop_();
	i = 27;
#elif (MAIN_Fosc == 16000000L)
	_nop_();
	_nop_();
	i = 37;
#elif (MAIN_Fosc == 22118400L)
	_nop_();
	_nop_();
	_nop_();
	i = 52;
#elif (MAIN_Fosc == 24000000L)
	_nop_();
	_nop_();
	i = 57;
#else
#error "soft_uart not support this clock frequency !"
#endif

	while (--i)
		;
}

void delay_100us()
{
	unsigned char i, j;

#if (MAIN_Fosc == 11059200L)
	_nop_();
	_nop_();
	i = 2;
	j = 15;
#elif (MAIN_Fosc == 12000000L)
	i = 2;
	j = 39;
#elif (MAIN_Fosc == 16000000L)
	i = 2;
	j = 139;
#elif (MAIN_Fosc == 22118400L)
	i = 3;
	j = 35;
#elif (MAIN_Fosc == 24000000L)
	i = 3;
	j = 82;
#else
#error "soft_uart not support this clock frequency !"
#endif

	do
	{
		while (--j)
			;
	} while (--i);
}

/******************* 定时器延时，使用定时器 T0 **********************/

#define T0_IsTimeout() TF0 == 1
#define T0_ResetTimeout() TF0 = 0

u8 _unit;
u16 _loopMax, _loopCount, _lastReloadVal;

void DelayInit()
{
	TIM_InitTypeDef timerDef;
	timerDef.TIM_Mode = TIM_16BitAutoReload;
	timerDef.TIM_ClkOut = DISABLE;
	timerDef.TIM_ClkSource = TIM_CLOCK_1T;
	timerDef.TIM_Interrupt = DISABLE;
	timerDef.TIM_Polity = PolityLow;
	timerDef.TIM_Run = DISABLE;
	timerDef.TIM_Value = 0x00;

	_unit = Main_Fosc_KHZ / 1000U;

	Timer_Inilize(Timer0, &timerDef);
}

void DelaySync(u16 ms)
{
	unsigned long val = ms * _unit * 1000UL;
	_loopMax = val / 0x10000U + 1;
	_lastReloadVal = 0x10000U - (val % 0x10000U);
	_loopCount = 0;

	TR0 = 0;

	Timer0_Load(_loopMax == 1 ? _lastReloadVal : 0x00);

	TR0 = 1;

	while (_loopCount < _loopMax)
	{
		while (!T0_IsTimeout())
			;

		T0_ResetTimeout();

		_loopCount++;

		if (_loopCount == _loopMax - 1)
		{
			Timer0_Load(_lastReloadVal);
		}
	}

	TR0 = 0;
}