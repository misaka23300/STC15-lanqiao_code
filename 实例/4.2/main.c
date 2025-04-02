#include "main.h"

enum {

}



int main()
{
    boot_init();

    while (1)
    {


    }

    return 0;
}




void Timer0_Isr(void) interrupt 1
{
    static uint i;
    i++;
    if (i > 30000) { i = 0; }

    seg_display();
    led_display();


}