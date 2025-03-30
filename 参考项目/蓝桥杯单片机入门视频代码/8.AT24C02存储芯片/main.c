#include "main.h"

u16 cnt;//��ʱ��0����
u8 num;//�Ӱ���ֵ
u8 at_read;//AT24C02�Ķ�ȡ����ֵ
bit key_flag,led_flag,read_flag;
void main(){
	at_read = AT24C02_Read(0x00);
	Sys_Init();
	Timer0Init();
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(read_flag){
			read_flag=0;
			at_read=AT24C02_Read(0x00);//��ȡ0��ַ������
		}
		if(num){
			AT24C02_Write(0x00,num);//������ֵд��AT24C02
			num=0;
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%10==0)Seg_Set(at_read,16,16,16,16,16,16,16);
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%100==0)read_flag=1;//100ms��һ��AT24C02
	cnt%=1000;
}