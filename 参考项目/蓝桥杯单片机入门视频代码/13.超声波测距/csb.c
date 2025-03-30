#include "csb.h"
#include "intrins.h"
sbit Tx = P1^0;
sbit Rx = P1^1;


void csb_timer_init(void)		//1����@12.000MHz
{
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0;		//���ö�ʱ��ֵ
	TH1 = 0;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 0;		//��ʱ��1�رռ�ʱ
}
void Delay10us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 27;
	while (--i);
}

u8 csb_measure(){
	u8 i;
	u8 dis;
	for(i=0;i<10;i++){
		Tx=1;
		Delay10us();
		Tx=0;
		Delay10us();
	}
	TR1=1;
	while(Rx && !TF1);
	TR1=0;
	
	if(TF1){
		TF1=0;
		dis=255;
	}
	else
		dis = (TH1*256+TL1)*0.017;
	
	TH1=0;
	TL1=0;
	return dis;
}