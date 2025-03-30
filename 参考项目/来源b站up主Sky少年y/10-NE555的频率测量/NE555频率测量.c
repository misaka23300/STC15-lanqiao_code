#include <STC15F2K60S2.H>

#define uchar unsigned char
#define uint unsigned int

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
	AUXR &= 0xBF;			//��ʱ��ʱ��12Tģʽ   T1��ʱ1ms��
	TMOD = 0x06;			//����T1��ʱ��ģʽ T0������
	TL1 = 0x18;				//���ö�ʱ��ʼֵ
	TH1 = 0xFC;				//���ö�ʱ��ʼֵ
	TL0 = 0xff;
	TH0 = 0xff;
	TF1 = 0; TF0 = 0;
	TR1 = 1; TR0 = 1;
	ET0 = 1; ET1 = 1;//�򿪶�Ӧ���ж�
	EA = 1;
	
}

uchar SMGi=0;   //0-7
uint t=0;       
uint count=0,SMG_count=0;   //ne555�ļ�����������   Ƶ��1s���ܹ���ȡ���ٸ�����
void T0_Server() interrupt 1
{
	count++;
}

void T1_Server() interrupt 3    //ÿ��ִ�к�������1ms  		T1
{
	aloneSMG(SMGi,SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if(++SMGi==8)SMGi=0; 
	if(++t==1000)
	{
		t=0;
		SMG_count=count;
		count=0;
	}
}

void main()
{
	T_Reset();
	while(1)
	{
		SMGa[0]=11;
		SMGa[1]=11;
		SMGa[2]=11;
		SMGa[3]=SMG_count/10000%10;
		SMGa[4]=SMG_count/1000%10;
		SMGa[5]=SMG_count/100%10;
		SMGa[6]=SMG_count/10%10;
		SMGa[7]=SMG_count%10;
	}
}
