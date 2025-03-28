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

	


void Timer0Init(void)		//1����@12.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA  = 1;
}
