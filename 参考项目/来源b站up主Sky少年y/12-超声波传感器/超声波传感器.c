#include <STC15F2K60S2.H>
#include "intrins.h"
#define uchar unsigned char
#define uint unsigned int

sbit TX=P1^0;
sbit RX=P1^1;

code unsigned char DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,
0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};   //对应着0-9和-共11个字符加上全灭

uchar SMGa[8]={11,11,11,11,11,11,11,11};  //SMGa[0]


void control(char x,y)
{
	switch(x)
	{
		case 4:P2=(P2 & 0x1f)|0x80;break;   //Y4C为高电平
		case 5:P2=(P2 & 0x1f)|0xa0;break;   //5
		case 6:P2=(P2 & 0x1f)|0xc0;break;
		case 7:P2=(P2 & 0x1f)|0xe0;break;
	}
	P0=y;
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
}



void aloneSMG(char pos,value)   //单个数码管显示   
{
	control(7,0xff);         //消影
	control(6,0x01<<pos);    //位选 x=0 x=7
	control(7,DuanMa[value]);//段码
}

void T_Reset()
{
	AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值				//设置定时初始值
  	TF0 = 0;
	TR0 = 1;
	ET0 = 1;//打开对应的中断
	EA = 1;
}
uchar SMGi=0;   //0-7     

//矩阵按键操作
uchar Key_Delay=0;
uchar Wave_Delay=0;
uchar Key_Read()       //读取键值的函数
{
	uint Key_New;
	uchar key_value=0;
	
	P44=0;P42=1;P35=1;P34=1;  //扫描第一列
	Key_New = P3 & 0x0f;      //获取第一列的四行的位置的二进制数值
	
	P44=1;P42=0;P35=1;P34=1;  //扫描第2列
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	P44=1;P42=1;P35=0;P34=1;  //扫描第3列
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	P44=1;P42=1;P35=1;P34=0;  //扫描第4列
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	switch(~Key_New)
	{
		case 0x8000:key_value=4;break;  //S4
		case 0x4000:key_value=5;break;  //S5
		case 0x2000:key_value=6;break;  //S6
		case 0x1000:key_value=7;break;  //S7
		
		case 0x0800:key_value=8;break;  //S8
		case 0x0400:key_value=9;break;  //S9
		case 0x0200:key_value=10;break;  //S10
		case 0x0100:key_value=11;break;  //S11
		
		case 0x0080:key_value=12;break;  //S12
		case 0x0040:key_value=13;break;  //S13
		case 0x0020:key_value=14;break;  //S14
		case 0x0010:key_value=15;break;  //S15
		
		case 0x0008:key_value=16;break;  //S16
		case 0x0004:key_value=17;break;  //S17
		case 0x0002:key_value=18;break;  //S18
		case 0x0001:key_value=19;break;  //S19
		
		default :key_value=0;break;
	}
	return key_value;
}

void Key_pro()
{
	uchar ucKey_Val,ucKey_Down,ucKey_Up,ucKey_old;
	if(Key_Delay<9)return;
	ucKey_Val = Key_Read();                         //7
	ucKey_Down = ucKey_Val & (ucKey_old ^ ucKey_Val);
	ucKey_Up = ~ucKey_Val & (ucKey_old ^ ucKey_Val);
	ucKey_old = ucKey_Val;
	
	switch(ucKey_Down)
	{
		
	}
}

void T1_Server() interrupt 1    //每次执行函数就是1ms  		T1
{
	aloneSMG(SMGi,SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if(++SMGi==8)SMGi=0; 
	if(++Key_Delay==10)Key_Delay=0;
	if(++Wave_Delay==200)Wave_Delay=0;
}

uchar Distance=0;
void Delay12us(void)	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	_nop_();
	i = 33;
	while (--i);
}


uchar Get_Distance()  //单位cm
{
	uint time_Dis=0;
	uchar i=0;
	CMOD=0x01;
	CCON=0x00;
	CH=0x00;CL=0x00;
	for(i=0;i<=7;i++)
	{
		TX=1;
		Delay12us();
		TX=0;
		Delay12us();
	}
	CR=1;
	while((RX==1)&&(CH<0x40));
	CR=0;
	if(CH>=0x40)
	{
		CF=0;
		return 0;
	}
	else
	{
		time_Dis = (CH<<8)|CL;
		return (time_Dis * 0.0172);
	}
}

void main()
{
	T_Reset();
	while(1)
	{
		if(Wave_Delay==199)Distance=Get_Distance();
		Key_pro();
		SMGa[0]=11;
		SMGa[1]=11;
		SMGa[2]=11;
		SMGa[3]=11;
		SMGa[4]=11;
		SMGa[5]=Distance/100%10;
		SMGa[6]=Distance/10%10;
		SMGa[7]=Distance%10;
	}
}
