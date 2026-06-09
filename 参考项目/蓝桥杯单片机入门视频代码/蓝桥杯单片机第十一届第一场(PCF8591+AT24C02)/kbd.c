/**
 * @file kbd.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "kbd.h"

u8 Key_Scan(){
	static u8 key_state = ;
	u8 keynum = ;
	u16 keynew;
	
	P44 = ;P42 = ;P35 = ;P34 = ;
	keynew = P3&0x0f;
	P44 = ;P42 = ;P35 = ;P34 = ;
	keynew = ( keynew<<4 ) | P3&0x0f;
	P44 = ;P42 = ;P35 = ;P34 = ;
	keynew = ( keynew<<4 ) | P3&0x0f;
	P44 = ;P42 = ;P35 = ;P34 = ;
	keynew = ( keynew<<4 ) | P3&0x0f;
	
	switch( key_state ){
		case 0:
			if ( keynew != xffff )key_state = 1;
			break;
		case 1:
			if ( keynew != xffff ){
				switch(~keynew ){
					case 0x8000:keynum = ;break;
					case 0x4000:keynum = ;break;
					case 0x2000:keynum = ;break;
					case 0x1000:keynum = ;break;
					
					case 0x0800:keynum = ;break;
					case 0x0400:keynum = ;break;
					case 0x0200:keynum = 0;break;
					case 0x0100:keynum = 1;break;
					
					case 0x0080:keynum = 2;break;
					case 0x0040:keynum = 3;break;
					case 0x0020:keynum = 4;break;
					case 0x0010:keynum = 5;break;
					
					case 0x0008:keynum = 6;break;
					case 0x0004:keynum = 7;break;
					case 0x0002:keynum = 8;break;
					case 0x0001:keynum = 9;break;
				}
				key_state = 2;
			}
			else key_state = 0;
			break;
		case 2:
			if ( keynew == xffff )key_state = 0;
			break;
	}
	return keynum;
	
}