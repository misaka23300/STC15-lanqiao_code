#include "main.h"

sonic_t sonic;
key_t key;
led_t leds;
seg_state_t seg_state;

/* 任务函数*/

void key_task() {
    key.press = key_scan();

    // 切换显示画面
    if (key.press == 4) {
        while_plus(&seg_state.mode, 0, 2);

        // 切换测距方式
    } else if (key.press == 5) {
        while_plus(&sonic.mode, 0, 2);
    } else if (key.press == 99) {
        set_led(5, 1);
    }
}

void sonic_task() {
    if (sonic.mode == 0) {
        sonic.distance = sonic_measure_mode1();
    } else if (sonic.mode == 1) {
        sonic.distance = sonic_measure_mode2();
    } else if (sonic.mode == 2) {
        sonic.distance = sonic_measure_mode3();
    }
}

void display_state() {
    switch (seg_state.mode) {
    case dis_init:
        {
            set_seg(0, 12); // C
            set_seg(1, 18);
            set_seg(2, 18);
            set_seg(3, 18);

            set_seg(4, 18);
            set_seg(5, 18);
            set_seg(6, 18);
            set_seg(7, 19);
        }
        break;

    case dis_sonic:
        {
            set_seg(0, sonic.distance / 100 % 10); // C
            set_seg(1, sonic.distance / 10 % 10);
            set_seg(2, sonic.distance % 10);
            set_seg(3, 16);

            set_seg(4, 16);
            set_seg(5, 16);
            set_seg(6, 16);
            set_seg(7, sonic.mode);
        }
        break;

    case dis_key:
        {
            set_seg(0, key.press / 10 % 10);
            set_seg(1, key.press % 10);
            set_seg(2, 16);
            set_seg(3, 16);

            set_seg(4, 16);
            set_seg(5, 16);
            set_seg(6, 16);
            set_seg(7, 16);
        }
    }
}

/* 主函数*/

void main_init() {
    // sonic.mode = 1;
    //  set_seg(7, 1);
    // seg_state.mode = 0;
    // display_state();
    //  Delay1000ms();
    // seg_state.mode = 1;
}

void main() {
    boot_init();
    main_init();
    set_led(7, 1);
    while (1) {
        if (sonic.time >= SONIC_TIME) {
            sonic.time = 0;
            sonic_task();
            set_led(7, 0);
        }

        if (key.time >= KEY_TIME) {
            key.time = 0;
            set_led(6, 1);
            key_task();
            set_led(6, 0);
            set_led(7, 1);
        }

        if (seg_state.time >= SEG_STATE_TIME) {
            seg_state.time = 0;
            display_state();
        }

        if (leds.time >= LED_TIME) {
            leds.time = 0;
            led_display();
        }
    }
}

void Timer2_Isr(void) interrupt 12 {
    seg_display();

    if (sonic.time < SONIC_TIME) { sonic.time++; }

    if (key.time < KEY_TIME) { key.time++; }

    if (seg_state.time < SEG_STATE_TIME) { seg_state.time++; }

    if (leds.time < LED_TIME) { leds.time++; }
}

