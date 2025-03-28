#include "kbd.h"

u8 Key_Scan(){
	static u8 key_state=0;
	u8 keynum=0;
	u16 keynew;
	
	P44=0;P42=1;P35=1;P34=1;
	keynew = P3&0x0f;
	P44=1;P42=0;P35=1;P34=1;
	keynew = (keynew<<4) | P3&0x0f;
	P44=1;P42=1;P35=0;P34=1;
	keynew = (keynew<<4) | P3&0x0f;
	P44=1;P42=1;P35=1;P34=0;
	keynew = (keynew<<4) | P3&0x0f;
	
	switch(key_state){
		case 0:
			if(keynew!=0xffff)key_state = 1;
			break;
		case 1:
			if(keynew!=0xffff){
				switch(~keynew){
					case 0x8000:keynum=4;break;
					case 0x4000:keynum=5;break;
					case 0x2000:keynum=6;break;
					case 0x1000:keynum=7;break;
					
					case 0x0800:keynum=8;break;
					case 0x0400:keynum=9;break;
					case 0x0200:keynum=10;break;
					case 0x0100:keynum=11;break;
					
					case 0x0080:keynum=12;break;
					case 0x0040:keynum=13;break;
					case 0x0020:keynum=14;break;
					case 0x0010:keynum=15;break;
					
					case 0x0008:keynum=16;break;
					case 0x0004:keynum=17;break;
					case 0x0002:keynum=18;break;
					case 0x0001:keynum=19;break;
				}
				key_state = 2;
			}
			else key_state = 0;
			break;
		case 2:
			if(keynew==0xffff)key_state = 0;
			break;
	}
	return keynum;
	
}