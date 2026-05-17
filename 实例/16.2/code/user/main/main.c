#include "main.h"

enum {
    KEY_TIME = 20,
    DS1302_TIME = 100,
    PCF8591_TIME = 300,
    DS18B20_TIME = 310,
    DISPLAY_TIME = 150,
};

uint8_t idata key_time = 0;
uint8_t idata ds1302_time = 0;
uint16_t idata pcf8591_time = 0;
uint16_t idata ds18b20_time = 0;
uint8_t idata display_time = 0;

void main()
{
    boot_init();

    while (1) {

        if (key_time >= KEY_TIME) {
            key_time = 0; 
            key_task();
        }
        if (ds1302_time >= DS1302_TIME) {
            ds1302_time = 0; 
            ds1302_task();
        }
        if (pcf8591_time >= PCF8591_TIME) {
            pcf8591_time = 0; 
            pcf8591_task();
        }
        if (ds18b20_time >= DS18B20_TIME) {
            ds18b20_time = 0; 
            ds18b20_task(); 
        }
        if (display_time >= DISPLAY_TIME) {
            display_time = 0; 
            display_task(); 
        }
        
    }
}

void Timer2_Isr(void) interrupt 12
{
    seg_display();
    key_time++;
    ds1302_time++;
    pcf8591_time++;
    ds18b20_time++;
    display_time++;
}



