# 使用函数点亮每一个LED灯

 上一节，我们通过简单的代码，控制锁存器和P0口的输出，点亮了LED灯。

这一次，我们来优化优化代码，通过调用函数的形式，自由的控制每一个LED灯的亮灭。

让我们来看怎么实现吧。

```c
#include "led.h"


uchar led_value[8] = {0, 0, 0, 0, 0 ,0 ,0 ,0};

void led(uchar i, bit state)
{
    static uchar temp;
    static uchar last = 0xFF;
    
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

uint8_t set_led(uint8_t i, bit state)
{
    if (i < 8) {
    	led_value[i] = state;    
    }
}

void led_display()
{
    static uchar i;

    led(i, led_value[i]);
    i = (i + 1) % 8;
}
```



