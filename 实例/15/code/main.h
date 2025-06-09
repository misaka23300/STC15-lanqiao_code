#ifndef __MAIN_H__
#define __MAIN_H__

#include "machine.h"
#include "math.h"       // ->
#include "string.h"     // -> strcmp();

#include "key.h"
#include "display.h"
#include "uart.h"

enum {
    CCAP0_TIME = 1000,
    UART_LEN = 16,
    KEY_TIME = 20,
    FREQ_TIME = 1000
};


uint setPcaTime = CCAP0_TIME;

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

void uart_send_commond();

#endif