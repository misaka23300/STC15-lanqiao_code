#inlcude "main.h"

enum {

}

struct list {
    bit flag;
    uchar value;
}


// pcf8591

// led
extern led_value[8];

struct {
    bit flag;
} led;

// seg
struct {
    bit flag;
} seg;

// key
struct {
    bit flag;
} key;


// 继电器
struct {
    bit flag;
} sandy;


void main()
{
    boot_init();

    while (1)
    {

    }
}


void Timer2_Isr(void) interrupt 12
{
    static uint i;
    i++;
    if (i > 30000)
    {
        i = 0;
    }


}