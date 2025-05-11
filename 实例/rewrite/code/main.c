#include "main.h"


void main()
{
    boot_init();

    while (1)
    {
       

        buzz(1);
        Delay500ms();
        buzz(0);
        Delay500ms();
    }

}

