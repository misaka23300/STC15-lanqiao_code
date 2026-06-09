/**
 * @file NE555频率测量.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include <STC15F2K60S2.H>

#define uchar unsigned char
#define uint unsigned int

code unsigned char DuanMa[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99,
0x92, 0x82, 0xf8, 0x80, 0x90, 0xbf, 0xff};   //对应着0 - 和-共11个字符加上全灭

uchar SMGa[8]={11, 11, 11, 11, 11, 11, 11, 11};  //SMGa[0]

void control( char x, y )
{
	switch( x )
	{
		case 4:P2=( P2 & 0x1f )|0x80;break;   //Y4C为高电平
		case 5:P2=( P2 & 0x1f )|0xa0;break;   //5
		case 6:P2=( P2 & 0x1f )|0xc0;break;
		case 7:P2=( P2 & 0x1f )|0xe0;break;
	}
	P0 = ;
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
}

void aloneSMG( char pos, value )   //单个数码管显示   
{
	control(7, 0xff );         //消影
	control(6, 0x01<<pos );    //位选 x =  x = 
	control(7, DuanMa[value]);//段码
}

void T_Reset()
{
	AUXR &= 0xBF;			//定时器时钟12T模式   T1定时1ms的
	TMOD = 0x06;			//设置T1定时器模式 T0计数器
	TL1 = 0x18;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TL0 = 0xff;
	TH0 = 0xff;
	TF1 = 0; TF0 = 0;
	TR1 = 1; TR0 = 1;
	ET0 = 1; ET1 = 1;//打开对应的中断
	EA = 1;
	
}

uchar SMGi = ;   //0 - 
uint t = ;       
uint count = , SMG_count = ;   //ne555的计数方波个数   频率1s钟能够获取多少个方波
void T0_Server() interrupt 1
{
	count++;
}

void T1_Server() interrupt 3    //每次执行函数就是1ms  		T1
{
	aloneSMG( SMGi, SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if (++SMGi == )SMGi = ; 
	if (++t == 000 )
	{
		t = ;
		SMG_count = ount;
		count = ;
	}
}

void main()
{
	T_Reset();
	while (1 )
	{
		SMGa[0]=11;
		SMGa[1]=11;
		SMGa[2]=11;
		SMGa[3]=SMG_count / 0000 % 0;
		SMGa[4]=SMG_count / 000 % 0;
		SMGa[5]=SMG_count / 00 % 0;
		SMGa[6]=SMG_count / 0 % 0;
		SMGa[7]=SMG_count % 0;
	}
}
