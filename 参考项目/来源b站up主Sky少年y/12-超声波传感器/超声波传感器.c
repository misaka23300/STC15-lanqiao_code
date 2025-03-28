#include <STC15F2K60S2.H>
#include "intrins.h"
#define uchar unsigned char
#define uint unsigned int

sbit TX=P1^0;
sbit RX=P1^1;

code unsigned char DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,
0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};   //��Ӧ��0-9��-��11���ַ�����ȫ��

uchar SMGa[8]={11,11,11,11,11,11,11,11};  //SMGa[0]


void control(char x,y)
{
	switch(x)
	{
		case 4:P2=(P2 & 0x1f)|0x80;break;   //Y4CΪ�ߵ�ƽ
		case 5:P2=(P2 & 0x1f)|0xa0;break;   //5
		case 6:P2=(P2 & 0x1f)|0xc0;break;
		case 7:P2=(P2 & 0x1f)|0xe0;break;
	}
	P0=y;
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
}



void aloneSMG(char pos,value)   //�����������ʾ   
{
	control(7,0xff);         //��Ӱ
	control(6,0x01<<pos);    //λѡ x=0 x=7
	control(7,DuanMa[value]);//����
}

void T_Reset()
{
	AUXR &= 0x7F;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ				//���ö�ʱ��ʼֵ
  TF0 = 0;
	TR0 = 1;
	ET0 = 1;//�򿪶�Ӧ���ж�
	EA = 1;
}
uchar SMGi=0;   //0-7     

//���󰴼�����
uchar Key_Delay=0;
uchar Wave_Delay=0;
uchar Key_Read()       //��ȡ��ֵ�ĺ���
{
	uint Key_New;
	uchar key_value=0;
	
	P44=0;P42=1;P35=1;P34=1;  //ɨ���һ��
	Key_New = P3 & 0x0f;      //��ȡ��һ�е����е�λ�õĶ�������ֵ
	
	P44=1;P42=0;P35=1;P34=1;  //ɨ���2��
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	P44=1;P42=1;P35=0;P34=1;  //ɨ���3��
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	P44=1;P42=1;P35=1;P34=0;  //ɨ���4��
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

void T1_Server() interrupt 1    //ÿ��ִ�к�������1ms  		T1
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


uchar Get_Distance()  //��λcm
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
