#ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "math.h"       // ->
#include "string.h"     // -> strcmp();
#include "stdio.h"

#include "key.h"
#include "display.h"
#include "uart.h"
#include "sonic.h"


enum {
    CCAP0_TIME = 1000,
    UART_LEN = 16,
    KEY_TIME = 20,
    FREQ_TIME = 1000,
    UART_TIME = 10,
    SONIC_TIME = 1000
};


//xdata uint setPcaTime = CCAP0_TIME;


typedef struct {
    uchar time;
    uchar press;

} KEY;

idata KEY key;


typedef struct {
    uint time;
    long times;
    long times_out;
} FREQ;

idata FREQ freq;


typedef struct {
    uchar now_x;
    uchar now_y;


} CAR;

idata CAR car;


typedef struct
{
    uint time;
    uchar distance;
} SONIC;

idata SONIC sonic;

//void pcaInterrupt() interrupt 7;
void uartSend(uchar *str);

//void Uart1_Isr(void) interrupt 4;
void time_1ms();

void task_loop();
void main();
void key_task();


/* void free_state(uchar x, uchar y); */
void freq_task();
void number_display(uint i);


void uart_task();


#endif