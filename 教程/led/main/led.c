#include "led.h"


uint8_t led_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};




void led_display()
{
    static uint8_t i = 0;
    static uint8_t temp = 0x00;
    static uint8_t last = 0xFF;

    if (led_array[i]) {
        temp = temp | (0x01 << i);
    } else {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last) {
        P0 = ~temp;
        latch(4);
        latch(0);

        last = temp;
    }

    i++;
    if (i >= 8) {
        i = 0;
    }

}

/**
 * @param i 为控制哪个led灯
 * @param state 为控制的led灯的状态
 */
void led_set(uint8_t i, uint8_t state)
{
    if (i < 8) {
        led_array[i] = state;
    }
}