#include "sys.h"

void Sys_Init(){
	P0 = 0xff;Y4;Y0;
	P0 &=0xaf;Y5;Y0;
	P0 = 0xff;Y6;Y0;
	P0 = 0xff;Y7;Y0;
}

void Delay(u16 xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--){
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);		
	}

}

void Timer1Init(void)		//1����@12.000MHz
{
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0x18;		//���ö�ʱ��ֵ
	TH1 = 0xFC;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	ET1 = 1;
	EA = 1;
	
}
void Timer2Init(void)		//500΢��@12.000MHz
{


	AUXR &= 0xFB;		//��ʱ��ʱ��12Tģʽ
	T2L = 0x18;		//���ö�ʱ��ֵ
	T2H = 0xFC;		//���ö�ʱ��ֵ
	AUXR |= 0x10;		//��ʱ��2��ʼ��ʱ




	IE2 |= 0x04;
}



