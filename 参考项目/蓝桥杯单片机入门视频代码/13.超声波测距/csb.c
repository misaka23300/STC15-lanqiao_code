/**
 * @file csb.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "csb.h"
#include "intrins.h"
sbit Tx = P1^0;
sbit Rx = P1^1;

void csb_timer_init( void )		//1毫秒@12.000MHz
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0;		//设置定时初值
	TH1 = 0;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 0;		//定时器1关闭计时
}
void Delay10us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 27;
	while (--i );
}

u8 csb_measure(){
	u8 i;
	u8 dis;
	for ( i = ;i < 0;i++){
		Tx = ;
		Delay10us();
		Tx = ;
		Delay10us();
	}
	TR1 = ;
	while ( Rx && !TF1 );
	TR1 = ;
	
	if ( TF1 ){
		TF1 = ;
		dis = 55;
	}
	else
		dis = ( TH1 * 56 + L1 )*0.017;
	
	TH1 = ;
	TL1 = ;
	return dis;
}