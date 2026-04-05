#include "rtc.h"


code unsigned char w_rtc_address[7]={0x80,0x82,0x84,0x86,0x88,0x8a,0x8c}; //秒分时日月周年
code unsigned char r_rtc_address[7]={0x81,0x83,0x85,0x87,0x89,0x8b,0x8d}; 

static unsigned char set[6] = {2,3,5,9,5,5};

//
void rtcGet(unsigned char *rtc)
{
 	unsigned char i, *p;
	unsigned char tmp[3];
	
 	p = (unsigned char *)r_rtc_address; 	//地址传递
 	
 	for(i=0;i<3;i++){
	  	tmp[i]=Read_Ds1302_Byte(*p);
	  	p++;
 	}
	
	rtc[0] = (tmp[2] >> 4);
	rtc[1] = (tmp[2] & 0x0F);	
	rtc[2] = (tmp[1] >> 4);
	rtc[3] = (tmp[1] & 0x0F);
	rtc[4] = (tmp[0] >> 4);
	rtc[5] = (tmp[0] & 0x0F);
}

//
void rtcInit(void)
{
 	Write_Ds1302_Byte(0x8E,0X00);
	
	Write_Ds1302_Byte(w_rtc_address[0], (set[4]<<4) | (set[5]));
	Write_Ds1302_Byte(w_rtc_address[1], (set[2]<<4) | (set[3]));
	Write_Ds1302_Byte(w_rtc_address[2], (set[0]<<4) | (set[1]));
	
	Write_Ds1302_Byte(0x8E,0x80);
}