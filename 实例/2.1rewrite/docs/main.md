# 

定时器定时1ms,每一毫秒会产生中断,执行中断中的函数。

```c
定时器
void Timer1_Init(void)		//1毫秒@12.000MHz
{
	AUXR |= 0x40;			//定时器时钟1T模式
	TMOD &= 0x0F;			//设置定时器模式
	TL1 = 0x20;				//设置定时初始值
	TH1 = 0xD1;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	ET1 = 1;				//使能定时器1中断
}

```

## 时间片的建立

时间片由定时器进行驱动,定时器需要定时1ms,也就是每一毫秒执行中断函数.

中断函数可以配置每个任务执行的时间间隔,如果变量加到对应时间间隔,则由main的while循环执行任务的函数.

所以建立时间片,需要:

1. 任务执行的间隔
2. 任务执行的函数
3. 记录任务时间的变量

任务执行的间隔为常量,可以用`enum`和`define`定义,一节省rom和ram.

```c
#define LED_TASK 20
enum {
    LED_TASK = 20
};
```

任务执行的函数由`main.c`的`while`循环调用,当记录任务时间的变量由中断函数由0加到间隔时间时,执行任务函数,任务函数执行完后,把记录时间的变量置为0.

```c
while (1)
{
    if (led.time == LED_TASK)
    {
        led_proc();
        led.time = 0;
    }
}
```

中断函数每1秒执行一次,为了避免阻塞任务,中断函数执行时间不应过长,也不能有死循环.

```c
void timer_1_1ms() interrupt 3
{
	if (led.time < LED_TASK) { led.time++; }
}
```

## 任务需要的参数

```c
typedef struct {
    uchar time;
    uchar  led[8];
}
```

### 数据的传入与传出

数据传入:

```c
void seg_display(uchar* seg)
{
    
}



void main()
{
	uchar seg[8] = {0, 0, 0 ,0, 0, 0, 0, 0};
    
    set_display(seg)
}
```

数据输出

```c
void date_time(uchar* now_time)
{
    not_time[0] = 1;
    now_time[1] = 2;
    now_time[2] = 3;
}

typedef struct{
    uchar time[3];
} RTC;

RTC rtc;

void main()
{
    date_time(rtc.time);
}

```



