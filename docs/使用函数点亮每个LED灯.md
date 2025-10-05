# 使用函数点亮每一个LED灯

 上一节，我们通过简单的代码，控制锁存器和P0口的输出，点亮了LED灯。

这一次，我们来优化优化代码，通过调用函数的形式，自由的控制每一个LED灯的亮灭。

让我们来看怎么实现吧。

```c
#include "led.h"


uint8_t led_value[8] = {0, 0, 0, 0, 0 ,0 ,0 ,0};

void led(uint8_t i, bit state)
{
    static uint8_t temp;
    static uint8_t last = 0xFF;
    
    if (state) {
        temp = temp | (0x01 << i);
    } else {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last) {
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
    static uint8_t i;

    led(i, led_value[i]);
    batch(4);
    batch(0);
    i = (i + 1) % 8;
}
```



我们创建了一个8位的数组，这个数组对应着记录LED灯的状态。

我们为了点灯，要使8位数组和P0的寄存器对应上。

如何实现把数组转为16进制数呢？

肯定要用到for循环进行迭代，依次读取数组，然后写入一个uint8_t的变量中。

```c
uint8_t i;
uint8_t temp = 0x00;
uint8_t led_value[8] = {0, 0, 0, 0, 0, 0, 0, 0};
for (i = 0;i < 8;i++) {
    if (led_value[i] == true) {
    	temp = temp | led_value[i] << i;    
    } else if (led_value[i] == false) {
        temp = temp & ~(led_value[i] << i);    
    }
    
}
```

我们来看最上面的代码，本质也是将数组的8位转为16进制，然后给到P0寄存器。只是将for循环的迭代放在时间片上，每次滴答只执行依次迭代。

变量中temp last的设置可以保留历史值，而比较是否相等，减少了时间片对寄存器P0的无效操作，提高了效率。

