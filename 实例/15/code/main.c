#include "main.h"


enum {
    CCAP0_TIME = 1000,
    UART_LEN = 16,
    KEY_TIME = 20,
    FREQ_TIME = 1000
};

uint setPcaTime;
uchar receiveData[UART_LEN];
uchar delay_send_flag;
uchar send_temp[];

typedef struct {
    uchar time;
    uchar press;

} KEY;

KEY key;


idata long times;
idata uint time_1000;

typedef struct {
    uint time;
    long times;
    long times_out;
} FREQ;

FREQ freq;

typedef struct {
    uchar now_x;
    uchar now_y;


} CAR;

CAR car;



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
    uchar Data;
    static uchar index;

    uchar receive_ciallo[] = "ciallo";

    if (RI)
    {
        RI = 0;
        Data = SBUF;

        if (Data != '\n' && index < (UART_LEN - 1))
        {
            receiveData[index] = Data;
            index++;
        }
        else
        {
            receiveData[index] = '\0';
            index = 0;
        }

        


    }

    /* uchar Data[UART_LEN];
    static uchar index;
    uchar receive_ciallo[] = "ciallo"; 

	if (RI)				//检测串口1接收中断
	{
				//清除串口1接收中断请求位
        RI = 0;
        Data[index] = SBUF;
        
        if (Data[index] != '\n' && index < (UART_LEN - 1))
        {
            receiveData[index] = Data;
            index++;
        }
        else
        {
            receiveData[index] = '\0';
            index = 0;
        }

        if (strcmp(Data, receive_ciallo) == 0)
        {
            //uartSend("ciallo~");
        }
	} */

    
    
    
}

// 频率
void Timer0_Isr(void) interrupt 1
{
    freq.times++;
}


// 任务调度_______________________________________


void time_1ms()
{
    seg_display();
    led_display();

    if (key.time < KEY_TIME) { key.time++; }
    if (freq.time < FREQ_TIME) { freq.time++; }

    time_1000++;
    if (time_1000 == 1000)
    {
        time_1000 = 0;
        times++;
    }
    
 }


void task_loop()
{
    if (key.time == KEY_TIME)
    {
        key_task();        
        key.time = 0;
    }

    if (freq.time == FREQ_TIME)
    {
        freq.time = 0;
        freq_task();
    }

    if (delay_send_flag)
    {
        delay_send_flag = 0;
        //uartSend();
    }
}

void main()
{
    //uchar message[] = "start";
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
}



/* void free_state(uchar xx, yy)
{
    uchar distance_x;
    uchar distance_y;
		uchar distance;
    distance_x = car.x - xx;
    distance_y = car.y - yy;

    distance = distance_x * distance_x + distance_y *distance_y;
    distance = sqrt(distance);

} */


void freq_task()
{
    freq.times_out = freq.times;
    freq.times = 0;
    
}


void number_display(uint i)
{
    seg_list[3] = i / 10000 % 10;
    seg_list[4] = i / 1000 % 10;
    seg_list[5] = i / 100 % 10;
    seg_list[6] = i / 10 % 10;
    seg_list[7] = i % 10;

}

void delay_send_uart()
{

}