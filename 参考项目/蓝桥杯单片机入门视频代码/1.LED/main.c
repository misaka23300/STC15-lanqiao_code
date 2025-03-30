#include <STC15F2K60S2.H>
typedef unsigned char u8;
typedef unsigned int u16;

#define Y4 P2 = (P2&0x1f)|0x80
#define Y5 P2 = (P2&0x1f)|0xa0
#define Y6 P2 = (P2&0x1f)|0xc0
#define Y7 P2 = (P2&0x1f)|0xe0
#define Y0 P2 = (P2&0x1f)
void Delay(u16 xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--){
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);	
	}
	
}


void main(){
	u8 i;
	P0=0xff;Y4;Y0;
	P0=0xaf;Y5;Y0;
	P0=0xff;Y6;Y0;
	P0=0xff;Y7;Y0;
	
	while(1){
		for(i=0;i<8;i++){
			P0=~(0x01<<i);
			Y4;Y0;
			Delay(500);
		}
		for(i=0;i<8;i++){
			P0=~(0x80>>i);
			Y4;Y0;
			Delay(500);
		}
		
	}
}