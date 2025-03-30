/* ͷ�ļ��������� */
#include <STC15F2K60S2.H>
#include <Led.h>
#include <Init.h>
#include <Key.h>
#include <Seg.h>
#include <ds1302.h>//ʱ������ר��ͷ�ļ�

/* ��������� */
unsigned char Key_Val,Key_Down,Key_Up,Key_Old;
unsigned char ucLed[8] = {0,0,0,0,0,0,0,0};
unsigned char Seg_Pos;
unsigned char Seg_Buf[8] = {10,10,10,10,10,10,10,10};
unsigned char Seg_Point[8] = {0,0,0,0,0,0,0,0};
unsigned char Key_Slow_Down;
unsigned int Seg_Slow_Down;
unsigned char ucRtc[3] = {0x23,0x59,0x55};//ʱ�����ݴ������ Ĭ��ʱ��23��59��55

/* ���������� */
void Key_Proc()
{
	if(Key_Slow_Down) return;
	Key_Slow_Down=1;
	
	Key_Val = Key_Read();//��ȡ����ֵ
	Key_Down = Key_Val & (Key_Val ^ Key_Old);//����½���
	Key_Up = ~Key_Val & (Key_Val ^ Key_Old);//����½���
	Key_Old = Key_Val;//ɨ�踨������
}

/* ��Ϣ������ */
void Seg_Proc()
{
	if(Seg_Slow_Down) return;
	Seg_Slow_Down=1;
	
	/* ��Ϣ��ȡ���� */
	Read_Rtc(ucRtc);//ʵʱ��ȡʱ������
	
	/* ���ݴ������� */
	Seg_Buf[0]=ucRtc[0] / 16;//ʮ������ȡʮλ
	Seg_Buf[1]=ucRtc[0] % 16;//ʮ������ȡ��λ
	Seg_Buf[2]=11;
	Seg_Buf[3]=ucRtc[1] / 16;//ʮ������ȡʮλ
	Seg_Buf[4]=ucRtc[1] % 16;//ʮ������ȡ��λ
	Seg_Buf[5]=11;
	Seg_Buf[6]=ucRtc[2] / 16;//ʮ������ȡʮλ
	Seg_Buf[7]=ucRtc[2] % 16;//ʮ������ȡ��λ
}

/* ������ʾ���� */
void Led_proc()
{

}

/*��ʱ��0��ʼ��������*/
void Timer0_Init(void)		//1����@12.000MHz
{
	AUXR &= 0x7F;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA = 1;
}

/*��ʱ��0�жϷ�������*/
void Timer0Server() interrupt 1
{
    if(++Key_Slow_Down == 10) Key_Slow_Down = 0;
    if(++Seg_Slow_Down == 100) Seg_Slow_Down = 0;
		if(++Seg_Pos==8) Seg_Pos=0;
		Seg_Disp(Seg_Pos,Seg_Buf[Seg_Pos],Seg_Point[Seg_Pos]);
	  Led_Disp(Seg_Pos,ucLed[Seg_Pos]);

}

/* Main */
void main()
{
	System_Init();
	Timer0_Init();
	Set_Rtc(ucRtc);//�ϵ�ʱ����ʱ��
	while(1)
	{
		Key_Proc();
		Seg_Proc();
		Led_Proc();	
	}
}