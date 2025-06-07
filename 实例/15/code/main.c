#include "main.h"


enum {
    CCAP0_TIME = 1000,
    UART_LEN = 16,
    KEY_TIME = 20
};

uint setPcaTime;
uchar receiveData[UART_LEN];

typedef struct {
    uchar time;
    uchar press;

} KEY;

KEY key;


long times;



// PCA_______________________________________

void pcaInterrupt() interrupt 7
{
    if (CCF0)
    {
        CCF0 = 0;
        setPcaTime += CCAP0_TIME;

        CCAP0L = setPcaTime;
        CCAP0H = setPcaTime >> 8;
        
        time_1ms();
    }
}


// 串口_______________________________________

// str -> 指针地址
// *str -> 指针的取值
void uartSend(uchar *str)
{       
    while (*str != '\0')
    {
        SBUF = *str;
        while (TI == 0);
        TI = 0;
        str++;
    }
}


void Uart1_Isr(void) interrupt 4
{
	//uchar Data;
    //static uchar index;
       
	if (RI)				//检测串口1接收中断
	{
				//清除串口1接收中断请求位
        ET0 = 0;
        P0 = SBUF;

        ET0 = 1;
        batch(4);
        RI = 0;	
        /* if (Data != '\n' && index < (UART_LEN - 1))
        {
            receiveData[index] = Data;
            index++;
        }
        else
        {
            receiveData[index] = '\0';
            index = 0;
            
        } */
        //uartSend("ciallo~");
	}
    //uartSend("ciallo.cc");
    
}


// 任务调度_______________________________________


void time_1ms()
{
    seg_display();
    led_display();

    if (key.time < KEY_TIME) { key.time++; }
    times++;

 }


void task_loop()
{
    if (key.time == KEY_TIME)
    {
        key_task();
        key.time = 0;
    }
}

void main()
{
    uchar message[] = "start";
    clean_display();
    timer();
    uartSend("start");
    while (1)
    {
        task_loop();
    }
}


// _________________________________________任务函数

void key_task()
{
    key.press = key_scan();
    /* if (key.press != 99)
    {
        seg_list[0] = key.press / 10;
        seg_list[1] = key.press / 10 % 10;
    } */
   seg_list[3] = times / 10000 % 10;
   seg_list[4] = times / 1000 % 10;
   seg_list[5] = times / 100 % 10;
   seg_list[6] = times / 10 % 10;
   seg_list[7] = times % 10;

}


