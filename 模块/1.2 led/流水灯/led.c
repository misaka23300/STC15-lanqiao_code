#include "led.h"


uint8_t led_value[8] = {0, 0, 0, 0, 0 ,0 ,0 ,0};


void main()
{
    uint8_t i;
    while (1) {
        for (i = 0;i < 8;i++) {
            led(i, 1);
            Delay500ms();
        }
        for (i = 8;i > 0;i--) {
            led(i, 0);
            Delay500ms();
        }

    }
}




void led(uint8_t i, bit state)
{
    static uint8_t temp;
    static uint8_t last = 0xFF;

    if (state)
    {
        temp = temp | (0x01 << i);
    }
    else
    {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last)
    {
        P0 = ~temp;
        batch(4);
        batch(0);

        last = temp;
    }
}

void led_display()
{
    static uint8_t i;

    led(i, led_value[i]);
    i = (i + 1) % 8;
}

void batch(uint8_t i)
{
    siwtch(i):
    {
        case 4: {P2 = (P2 & 0x1F) | 0x80;break;}
        case 6: {P2 = (P2 & 0x1F) | 0x80;break;}
        case 7: {P2 = (P2 & 0x1F) | 0x80;break;}
        case 0: {P2 = (P2 & 0x1F);break;}
    }
}

void Delay500ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
