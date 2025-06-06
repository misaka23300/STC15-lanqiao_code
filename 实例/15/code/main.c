#include "main.h"




void Timer1_Isr(void) interrupt 3
{

    
}


void task_loop()
{

}

void boot_init()
{
    clean_display();
    timer();
}

void main()
{
    boot_init();

    while (1)
    {
        task_loop();
    }
}


