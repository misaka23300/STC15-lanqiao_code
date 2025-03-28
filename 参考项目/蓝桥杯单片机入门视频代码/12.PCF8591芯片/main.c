#include "main.h"
u8 channel=0x03;//Ĭ�ϲ���ͨ����AIN3
u16 cnt;//��ʱ��0����
u8 num;//�Ӱ���ֵ
u8 ad;
u16 analog;
bit key_flag,led_flag,ad_mea;
void main(){
	Sys_Init();
	Timer0Init();
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(num==4){
			channel = 0x03;//������λ����ѹֵ
			num=0;
		}
		if(num==5){
			channel = 0x01;//�������������ѹֵ
			num=0;
		}
		if(ad_mea){
			ad_mea=0;
			ad = PCF8591_ADin(channel);
			analog = (int)(ad/255.0*5*100);//���������������ʾģ���ѹֵ
			Seg_Set(channel,16,16,16,16,analog/100+32,analog/10%10,analog%10);
			PCF8591_DAout(ad);//����ȡ�ĵ�ѹֵ�����OUT��
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%100==0)ad_mea=1;//ÿ��100ms��һ�ε�ѹֵ
	cnt%=1000;
}