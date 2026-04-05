#include "main.h"

enum {
    UART_TIME = 500,
};

uint16_t xdata uart_time = 0;

uint16_t cnt = 0;
void main()
{
    boot_init();
    uart_init();

    while (1) {
        if (uart_time >= UART_TIME) {
            uart_time = 0;
            printf("ciallo %d", cnt);
            cnt++;
        }
    }
}

void Timer2_Isr(void) interrupt 12
{
    uart_time++;
}