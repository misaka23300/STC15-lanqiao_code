#include "key.h"
extern u8 flag;
u8 Key_Scan(){
	static u8 key_state=0;
	u8 keynum=0;
	u8 keypress=P3&0x0f;
	
	switch(key_state){
		case 0:
			if(keypress!=0x0f)key_state=1;
			break;
		case 1:
			if(keypress!=0x0f){
				if(keypress==0x07)keynum=4;
				if(keypress==0x0b)keynum=5;
				if(keypress==0x0d)keynum=6;
				if(keypress==0x0e)keynum=7;
				key_state=2;
			}
			else key_state=0;
			break;
		case 2:
			if(keypress==0x0f){key_state=0;flag=0;}
			break;
		
				
	}
	return keynum;
	
}