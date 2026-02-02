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
    uint16_t time;
    long times;
    long times_out;
} FREQ;
idata FREQ freq;


typedef sturct {
    uchar mode;     // 0 -> 空闲    1 -> 运行   2 -> 等待
} STATE;

xdata STATE state;

typedef struct {
    uint16_t going[2];    // 0 -> x   // 1 -> y
    uint16_t now[2];
} POSITION;

idata POSITION position;

typedef struct {
    float value;
    uint8_t r;
    uint8_t b;
    uint8_t argument_state;
} SPEED;

xdata SPEED speed;

typedef struct {
    uint16_t time;
    uint8_t value;
    uint8_t is_day_no_night;
} PCF8591;

xdata PCF8591 adc;


typedef struct 
{
    uint8_t state;
} DISPLAY;

xdata DISPLAY display;



typedef struct
{
    uint16_t time;
    uint8_t distance;
    uint8_t lock;
} SONIC;

idata SONIC sonic;


typedef struct {
    uint8_t time;
    uint8_t press;

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


void number_display(uint16_t i);





#endif