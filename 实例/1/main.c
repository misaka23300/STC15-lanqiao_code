#include "main.h"

uchar led_flash[]={0,0,0,0,0,0,0,0};
bit seg_flag,led_flag,temp_flag;
/*bit pcf_flag;*/
uchar buz_type=6;
bit buz_2,buz_3,buz_4,buz_5;
//uint ad1,ad2;
uint temp;
void led_proc()
{
 if(led_flag)
 {
   led_flag=0;
	 switch(buz_type)
	 {
		 case 1:led_flash[0]=1;break;
		 case 2:led_flash[0]^=1;break;
		 case 3:led_flash[0]^=1;break;
		 case 4:led_flash[0]^=1;break;
		 case 5:led_flash[0]^=1;break;
		 case 6:led_flash[0]=1;break;
	 }
 }
}

/*
void seg_proc()  //�������ʾ����������ࣩ
{
  uint dis;
	uchar times;
	if(seg_flag)
	{
		seg_flag=0;
		dis=csb_CJ();
		
		if(dis>40)buz_type=6;
		else if(dis>30) buz_type=5;
		else if(dis>20) buz_type=4;
		else if(dis>10) buz_type=3;
		else if(dis>5) buz_type=2;
		else buz_type=1;
		
		if(buz_type<3)    //���û����
		{
		  times++;
			times%=2;
			if(times)
			{
			 setcontent(16,16,dis/10%10,dis%10,16,16,16,buz_type);
			}
			else
			{
			 setcontent(16,16,16,16,16,16,16,16);
			}
		}
		else
			{
			 setcontent(16,16,dis/10%10,dis%10,16,16,16,buz_type);
			}
	}
}
*/

/*
void seg_proc()     // �������ʾ������PCF8591��
{
if(seg_flag)
	{
		seg_flag=0;
		setcontent(ad1/100,ad1/10%10,ad1%10,16,16,ad2/100+32,ad2/10%10,ad2%10);
		if(ad1>50)buz_type=6;
		else if(ad1>40) buz_type=5;
		else if(ad1>30) buz_type=4;
		else if(ad1>20) buz_type=3;
		else if(ad1>10) buz_type=2;
		else buz_type=1;
	}
}
*/
void seg_proc()     // �������ʾ������DS18B20��
{
if(seg_flag)
	{
		seg_flag=0;
		setcontent(16,16,16,16,temp/1000,temp%1000/100+32,temp%100/10,temp%10);
	}
}
/*
void ad_proc()      //PCF8591�ɼ���������
{
if(pcf_flag)
	{
	pcf_flag=0;
	ad2=PCF8591_AD(0X01);//�ɼ����ǹ�������ͨ�������ǵõ��Ľ���ǵ�ѹ�ɼ�ͨ���������0-255�����֣�����ʵ�ʵ�ѹֵ
	delay_ms(10);
	ad1=PCF8591_AD(0X03);//�ɼ����ǵ�ѹ�ɼ�ͨ�������ǵõ��Ľ���ǹ�������ͨ���������0-255�����֣�����ʵ�ʵ�ѹֵ
	
	PCF8591_DA(ad2);
	
	ad2=(int)((ad2/255.0)*500);//�ɼ�������ֵ��ת����Ӧ�ĵ�ѹֵ
	delay_ms(10);
	}
}
*/
void buz_proc()
{
 switch(buz_type)
 {
	 case 1:wmq(6,0);break;
	 case 2:wmq(6,buz_2);break;
	 case 3:wmq(6,buz_3);break;
	 case 4:wmq(6,buz_4);break;
	 case 5:wmq(6,buz_5);break;
	 case 6:wmq(6,1);break;
 }
}

void ds18b20_proc()
{
 float tmp;
	if(temp_flag)
	{
	  temp_flag=0;
		ET0=0;
		tmp=read_temp();
		ET0=1;
		temp=(int)(tmp*100);
	}
}
void main()
{

	sys_init();
  Timer0Init();
  csb_Init();

	while(1)
	{
	
//   key_proc();
 	    seg_proc();
      led_proc();	
      buz_proc();	
		ds18b20_proc();
//   ad_proc();
	}
	
		 

}

void  Timer0interrupt() interrupt 1    //1����
{
  static uint k,cnt;
	k++;
	if(k%3==0) display();                //3����
	if(k%5==0)                           //5����
	{
		led(cnt,led_flash[cnt++]);cnt%=8;
	}	
//	if(k%10==0) key_flag=1;
	if(k%100==0) { led_flag=1; /*pcf_flag=1;*/ } //100����
	if(k%200==0)  seg_flag=1;             //200����
//	
	if(k%750==0) temp_flag=1; 
	
	if(k%40==0) buz_2^=1;
	if(k%80==0) buz_3^=1;
	if(k%100==0) buz_4^=1;
	if(k%150==0) buz_5^=1;
	
	k%=10000;

}

