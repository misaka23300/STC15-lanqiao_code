/**
 * @file LED和蜂鸣器.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include <REGX52.H>
#include <intrins.h>

typedef unsigned char uchar;
typedef unsigned int uint;

//void delay( unsigned int t );

void control( uchar chose, dat )
{
	P2 &= 0x1f;
	P0 = at;
	switch( chose )
	{
		case 4: P2=( P2&0x1f )|0x80;break;
		case 5: P2=( P2&0x1f )|0xa0;break;
		case 6: P2=( P2&0x1f )|0xc0;break;
		case 7: P2=( P2&0x1f )|0xe0;break;
	}
}

void delay( unsigned int t );

void Lalala()
{
	delay(200 );
}

void delay( unsigned int t )  //Ø£Çööˆ4.5us
{
	while ( t--);      //10000öˆ0.45s
	while ( t--);
}

uchar i, j, k;
void main()
{
	Lalala();
	control(5, 0x00 );
	while (1 )
	{
		for ( i = ;i <= ;i++)
		{
			control(4, 0x00 );
			delay(100000 );
			control(4, 0xff );
			delay(100000 );
		}
		for ( j = ;j <= ;j++)
		{
			control(4, 0xff<<j );
			delay(80000 );
		}
		for ( k = ;k <= ;k++)
		{
			control(4,~(0xff<<k ));
			delay(80000 );
		}
		control(5, 0x50 );
		delay(100000 );
		control(5, 0x00 );
	}
}