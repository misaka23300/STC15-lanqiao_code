#include "main.h"
float T;//�¶�ֵ
int real_T;//������ʾ
u16 cnt;//��ʱ��0����
u8 num;//�Ӱ���ֵ
bit key_flag,led_flag,tmp_mea;
void main(){
	Sys_Init();
	Timer0Init();
	//����ϵ���ʾ85�������
	T = rd_temperature();//�ȶ�һ��
	Delay(1000);//��ʱ1s�Ϳɽ��
	
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(tmp_mea){
			tmp_mea=0;
			
			ET0=0;//�ر��жϣ���ֹӰ��ʱ��
			T = rd_temperature();//��ȡ�¶�ֵ
			ET0=1;//��ȡ�����������ж�
			
			real_T=(int)(T*100);//��ȡС�������λ
			if(real_T<0){
				real_T=-real_T;
				Seg_Set(16,16,16,17,real_T/1000,real_T/100%10+32,real_T/10%10,real_T%10);
			}
			else 
				Seg_Set(16,16,16,16,real_T/1000,real_T/100%10+32,real_T/10%10,real_T%10);
				
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%500==0)tmp_mea=1;//ÿ��500ms��һ���¶�
	cnt%=1000;
}