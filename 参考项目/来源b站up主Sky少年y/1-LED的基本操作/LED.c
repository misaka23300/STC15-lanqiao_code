#include <STC15F2K60S2.H>
#include "intrins.h"

char led=0x9b;

#define on(x)	led&=~(1<<x);     //�򿪵ƹ�
#define off(x) led|=1<<x;        //�رյƹ�
#define tog(x)led^=1<<x;       //�ƹ���˸

void control(char x,y)
{
	switch(x)
	{
		case 4:P2=(P2 & 0x1f)|0x80;break; //Y4C������Ϊ�͵�ƽ
		case 5:P2=(P2 & 0x1f)|0xa0;break;
		case 6:P2=(P2 & 0x1f)|0xc0;break;
		case 7:P2=(P2 & 0x1f)|0xe0;break;
	}
	P0=y;
}


void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



void main()
{
	control(4,0xff); //��LED��Y4Cʹ��
	P0=led;
	while(1)
	{
		on(0);on(1); //����L1 L2
		P0=led;
		Delay500ms();Delay500ms();
		off(0);P0=led;Delay500ms();Delay500ms();
		off(1);P0=led;Delay500ms();Delay500ms();
	}
}

