#include "main.h"

uchar a_flag, b_flag;
uchar led_flag, seg_flag, key_flag;
uchar led_T[] = {16, 16, 16, 16, 16, 16, 16, 16};

uchar num;

void key_proc() {
    if (key_flag) {
        key_flag = 0;
        num = scankey();
        switch (num) {
            case 4:
                a_flag++;
                a_flag %= 3;
                break;
            case 5:
                b_flag++;
                b_flag %= 3;
                break;
        }
    }
}

void seg_proc() {
    if (seg_flag) {
        seg_flag = 0;
        switch (a_flag) {
            case 0:
                if (num != 99)
                    setdsp(num / 10, num % 10, 17, 5, 9, 17, 5, 0);
                break;
            case 1:
                setdsp(24, 33, 4, 5, 25, 32, 0, 6);
                break;
            case 2:
                switch (b_flag) {
                    case 0:
                        setdsp(10, 1, 2, 3, 5, 5, 0, 6);
                        break;
                    case 1:
                        setdsp(10, 2, 17, 17, 17, 17, 17, 17);
                        break;
                    case 2:
                        setdsp(10, 3, 17, 17, 17, 17, 17, 17);
                        break;
                }
                break;
        }
    }
}

void led_proc() {
    if (led_flag) {
        led_flag = 0;
    }
    switch (a_flag) {
        case 0:
            led_T[0] = 0;
            break;
        case 1:
            led_T[1] = 0;
            break;
        case 2:
            led_T[2] = 0;
            break;
    }
}

void main() {
    sys_init();
    Timer0_Init();
    while (1) {
        led_proc();
        seg_proc();
        key_proc();
    }
}

void Timer1_Isr(void) interrupt 1 {
    static uint k, cnt;
    display();
    // if(k%10==0)display();
    if (k % 5 == 0) {
        led(cnt, led_T[cnt++]);
        cnt %= 8;
    }
    if (k % 10 == 0) led_flag = 1;
    if (k % 15 == 0) key_flag = 1;
    if (k % 10 == 0) seg_flag = 1;
    k++;
    if (k >= 30000) {
        k = 1;
    }
}