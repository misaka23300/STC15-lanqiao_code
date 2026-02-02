#include "boot.h"

void boot_init(void)
{
	P0M1 = 0;   P0M0 = 0;   //����Ϊ׼˫���
    P1M1 = 0;   P1M0 = 0;   //����Ϊ׼˫���
    P2M1 = 0;   P2M0 = 0;   //����Ϊ׼˫���
    P3M1 = 0;   P3M0 = 0;   //����Ϊ׼˫���
    P4M1 = 0;   P4M0 = 0;   //����Ϊ׼˫���
    P5M1 = 0;   P5M0 = 0;   //����Ϊ׼˫���
    P6M1 = 0;   P6M0 = 0;   //����Ϊ׼˫���
    P7M1 = 0;   P7M0 = 0;   //����Ϊ׼˫���

	P0 = 0xFF;
	latch(4);
	latch(0);

	P0 = 0xFF;
	latch(7);
	latch(0);

	P0 = 0x00;
	latch(6);
	latch(0);

	P0 = 0xAF;
	latch(5);
	latch(0);

	timer_0();
	timer_1();
	EA = 1;

}

// ne555 ������
void timer_0(void)
{
		TMOD = 0x06; 	// 0000 0110
		AUXR &= 0x7F; 	// 0xxx xxxx
		TL0 = 0xFF;
		TH0 = 0xFF;
		TF0 = 0;
		TR0 = 1;
		ET0 = 1;
}

// 1ms
void timer_1(void)
{
	AUXR &= 0xBF;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TL1 = 0x18;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
	ET1 = 1;				//ʹ�ܶ�ʱ��1�ж�
}

void latch(uchar i)
{
	switch (i)
	{
		case 0: {P2 = (P2 & 0x1F); break;}
		case 4: {P2 = (P2 & 0x1F) | 0x80; break;}
		case 5: {P2 = (P2 & 0x1F) | 0xA0; break;}
		case 6: {P2 = (P2 & 0x1F) | 0xC0; break;}
		case 7: {P2 = (P2 & 0x1F) | 0xE0; break;}
	}
}


