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
#include "iic.h"

enum {
    CCAP0_TIME = 1000,
    UART_LEN = 16,
    KEY_TIME = 20,
    FREQ_TIME = 1000,
    UART_TIME = 10,
    SONIC_TIME = 1000
};


typedef struct {
    uint time;
    long times;
    long times_out;
} FREQ;
idata FREQ freq;


typedef sturct {
    uchar mode;     // 0 -> 空闲    1 -> 运行   2 -> 等待
} STATE;

xdata STATE state;

typedef struct {
    uint going[2];    // 0 -> x   // 1 -> y
    uint now[2];
} POSITION;

idata POSITION position;

typedef struct {
    float value;
    uchar r;
    uchar b;
    uchar argument_state;
} SPEED;

xdata SPEED speed;

typedef struct {
    uint time;
    uchar value;
    uchar is_day_no_night;
} PCF8591;

xdata PCF8591 adc;


typedef struct 
{
    uchar state;
} DISPLAY;

xdata DISPLAY display;



typedef struct
{
    uint time;
    uchar distance;
    uchar lock;
} SONIC;

idata SONIC sonic;


typedef struct {
    uchar time;
    uchar press;

} KEY;

idata KEY key;




void time_1ms();
void task_loop();
void main();

void key_task();
void freq_task();
void uart_task();
void adc_task();
void display_task();
void speed_task();
void sonic_task();


void number_display(uint i);





#endif