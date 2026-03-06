#include "./Timer.h"//硬件定时器库
#include "./SMG.h"//数码管库
#include "./UART.h"//硬件串口库
#include "./LED.h"//LED库
#include "./Sys.h"//系统库
#include "./config.h"//全局配置库
#include "intrins.h"//KEIL内部库
#include "string.h"//字符串库
#include "stdio.h"//标准输入输出库

//数码管位选表

uchar SMGwei[]={0X01,0X02,0X04,0X08,0X10,0X20,0X40,0X80};

//数码管段选表
uchar SMGduan[]=
{
	0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,
	0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,
};

//数码管显示函数
void SMG_Display(uint num)
{
	volatile uchar wei;//位选值
	static uchar num1,num2,num3;

	num1=num/100;
	num2=num%100/10;
	num3=num%10;

	/***数码管消隐***/
	Write_HC573(0XC0,0XFF);//位选全选中
	Write_HC573(0XE0,0XFF);//段选全关闭
	
	/***数码管显示***/
	Write_HC573(0XC0,SMGwei[wei]);//选择相应的位选
	switch(wei)
	{
		case 0://第一位
			Write_HC573(0XE0,SMGduan[num1]);
			break;
		
		case 1://第二位
			Write_HC573(0XE0,SMGduan[num2]);
		break;
		
		case 2://第三位
			Write_HC573(0XE0,SMGduan[num3]);
		break;
		
		default:
			Write_HC573(0XE0,0XFF);
		break;			
		
	}
	wei++;//位选不断增加,数码管显示完第一位向下一位显示
	if(wei==8) wei=0;//位选到达第八位,自动归零从头扫描
}