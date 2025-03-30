#include "main.h"
#define wan(x) x/10000
#define qian(x) x/1000%10
#define bai(x) x/100%10
#define shi(x) x/10%10
#define ge(x) x%10

u16 freq;
u16 cnt;//��ʱ��0����
u8 num;//�Ӱ���ֵ
bit key_flag,led_flag,freq_flag;
void main(){
	Sys_Init();
	NE555_Init();
	Timer1Init();//�ĳɶ�ʱ��1��ʼ��
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(freq_flag){
			freq_flag=0;
			TR0 = 0;//�ر�T0;
			freq = TH0*256 + TL0;
			TR0 = 1;//�ٴδ�
			TH0 = 0;
			TL0 = 0;//��ռ�����
			
			//�ж�freq��ֵ��С��ʾ���������
			if(freq<10)
				Seg_Set(16,16,16,16,16,16,16,ge(freq));
			else if(freq<100)
				Seg_Set(16,16,16,16,16,16,shi(freq),ge(freq));
			else if(freq<1000)
				Seg_Set(16,16,16,16,16,bai(freq),shi(freq),ge(freq));
			else if(freq<10000)
				Seg_Set(16,16,16,16,qian(freq),bai(freq),shi(freq),ge(freq));
			else 
				Seg_Set(16,16,16,wan(freq),qian(freq),bai(freq),shi(freq),ge(freq));
		}

		
	}
}


//�жϺŸ�Ϊ3
void Timer1_Int() interrupt 3{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%1000==0)freq_flag=1;//1����ó���ʱ��0�еļ�����ֵ��������Ƶ��
	cnt%=1000;
}