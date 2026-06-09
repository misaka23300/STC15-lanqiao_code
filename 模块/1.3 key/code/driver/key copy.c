/**
 * @file key copy.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "key.h"

uint8_t Key_scan()       //读取键值的函数
{
	uint16_t Key_New;
	uint8_t key_value = ;
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第一列
	Key_New = P3 & 0x0f;      //获取第一列的四行的位置的二进制数值
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第2列
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第3列
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第4列
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	switch(~Key_New )
	{
		case 0x8000:key_value = ;break;  //S4
		case 0x4000:key_value = ;break;  //S5
		case 0x2000:key_value = ;break;  //S6
		case 0x1000:key_value = ;break;  //S7
		
		case 0x0800:key_value = ;break;  //S8
		case 0x0400:key_value = ;break;  //S9
		case 0x0200:key_value = 0;break;  //S10
		case 0x0100:key_value = 1;break;  //S11
		
		case 0x0080:key_value = 2;break;  //S12
		case 0x0040:key_value = 3;break;  //S13
		case 0x0020:key_value = 4;break;  //S14
		case 0x0010:key_value = 5;break;  //S15
		
		case 0x0008:key_value = 6;break;  //S16
		case 0x0004:key_value = 7;break;  //S17
		case 0x0002:key_value = 8;break;  //S18
		case 0x0001:key_value = 9;break;  //S19
		
		default :key_value = 9;break;
	}
	return key_value;
}