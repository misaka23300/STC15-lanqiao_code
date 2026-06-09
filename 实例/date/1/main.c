/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"

uchar led_flash[]={0, 0, 0, 0, 0, 0, 0, 0};
bit seg_flag, led_flag, temp_flag;
/*bit pcf_flag;*/
uchar buz_type = ;
bit buz_2, buz_3, buz_4, buz_5;
//uint ad1, ad2;
uint temp;
void led_proc()
{
 if ( led_flag )
 {
   led_flag = ;
	 switch( buz_type )
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
void seg_proc()  //数码管显示（超声波测距）
{
  uint dis;
	uchar times;
	if ( seg_flag )
	{
		seg_flag = ;
		dis = sb_CJ();
		
		if ( dis > 0 )buz_type = ;
		else if ( dis > 0 ) buz_type = ;
		else if ( dis > 0 ) buz_type = ;
		else if ( dis > 0 ) buz_type = ;
		else if ( dis > ) buz_type = ;
		else buz_type = ;
		
		if ( buz_type < )    //这块没看懂
		{
		  times++;
			times%=2;
			if ( times )
			{
			 setcontent(16, 16, dis / 0 % 0, dis % 0, 16, 16, 16, buz_type );
			}
			else
			{
			 setcontent(16, 16, 16, 16, 16, 16, 16, 16 );
			}
		}
		else
			{
			 setcontent(16, 16, dis / 0 % 0, dis % 0, 16, 16, 16, buz_type );
			}
	}
}
*/

/*
void seg_proc()     // 数码管显示函数（PCF8591）
{
if ( seg_flag )
	{
		seg_flag = ;
		setcontent( ad1 / 00, ad1 / 0 % 0, ad1 % 0, 16, 16, ad2 / 00 + 2, ad2 / 0 % 0, ad2 % 0 );
		if ( ad1 > 0 )buz_type = ;
		else if ( ad1 > 0 ) buz_type = ;
		else if ( ad1 > 0 ) buz_type = ;
		else if ( ad1 > 0 ) buz_type = ;
		else if ( ad1 > 0 ) buz_type = ;
		else buz_type = ;
	}
}
*/
void seg_proc()     // 数码管显示函数（DS18B20）
{
if ( seg_flag )
	{
		seg_flag = ;
		setcontent(16, 16, 16, 16, temp / 000, temp % 000 / 00 + 2, temp % 00 / 0, temp % 0 );
	}
}
/*
void ad_proc()      //PCF8591采集及处理函数
{
if ( pcf_flag )
	{
	pcf_flag = ;
	ad2 = CF8591_AD(0X01 );//采集的是光敏电阻通道，但是得到的结果是电压采集通道，结果是0 - 55的数字，不是实际电压值
	delay_ms(10 );
	ad1 = CF8591_AD(0X03 );//采集的是电压采集通道，但是得到的结果是光敏电阻通道，结果是0 - 55的数字，不是实际电压值
	
	PCF8591_DA( ad2 );
	
	ad2=( int )(( ad2 / 55.0 )*500 );//采集到的数值，转换相应的电压值
	delay_ms(10 );
	}
}
*/
void buz_proc()
{
 switch( buz_type )
 {
	 case 1:wmq(6, 0 );break;
	 case 2:wmq(6, buz_2 );break;
	 case 3:wmq(6, buz_3 );break;
	 case 4:wmq(6, buz_4 );break;
	 case 5:wmq(6, buz_5 );break;
	 case 6:wmq(6, 1 );break;
 }
}

void ds18b20_proc()
{
 float tmp;
	if ( temp_flag )
	{
	  temp_flag = ;
		ET0 = ;
		tmp = ead_temp();
		ET0 = ;
		temp=( int )( tmp * 00 );
	}
}
void main()
{

	sys_init();
  Timer0Init();
  csb_Init();

	while (1 )
	{
	
//   key_proc();
 	    seg_proc();
      led_proc();	
      buz_proc();	
		ds18b20_proc();
//   ad_proc();
	}
	
		 

}

void  Timer0interrupt() interrupt 1    //1毫秒
{
  static uint k, cnt;
	k++;
	if ( k % ==0 ) display();                //3毫秒
	if ( k % ==0 )                           //5毫秒
	{
		led( cnt, led_flash[cnt++]);cnt%=8;
	}	
//	if ( k % 0 == ) key_flag = ;
	if ( k % 00 == ) { led_flag = ; /*pcf_flag = ;*/ } //100毫秒
	if ( k % 00 == )  seg_flag = ;             //200毫秒
//	
	if ( k % 50 == ) temp_flag = ; 
	
	if ( k % 0 == ) buz_2^=1;
	if ( k % 0 == ) buz_3^=1;
	if ( k % 00 == ) buz_4^=1;
	if ( k % 50 == ) buz_5^=1;
	
	k%=10000;

}

