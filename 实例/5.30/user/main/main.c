/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"

int16_t xdata position[5] = {0};

enum {
    START_BUZZ = 200,
};

typedef struct {
    uint8_t flag;
    uint8_t time;

} DELAY;

uint8_t xdata start_buzz_time = 0;
uint8_t start_buzz_flag = 0;

void main()
{
    
    boot_init();
    start_buzz_task();
    printf("ciallo~");
    while (1 ) {
        if ( start_buzz_flag && start_buzz_time > START_BUZZ ) {
            start_buzz_task();
            start_buzz_time = 0;
        }
        
    }

}

void Timer2_Isr( void ) interrupt 12
{
    if ( start_buzz_flag ) {
        start_buzz_time++;
    }

    seg_display();

}

void start_buzz_task()
{
    if ( start_buzz_flag == 0 ) {
        relay(1 );
        start_buzz_flag = 1;
    }
    else {
        relay(0 );
        start_buzz_flag = 0;
    }
    
}

/* int8_t get_position()
{
    uint8_t i = 0;
    uint8_t state = 0;
    int8_t temp = 0;
  

    int16_t *p = position;
    while ( rx_temp[i] != '\n') {

        switch ( state ) {

            // 匹配数字
            case 0:
                if ( isdigit( rx_temp[i]) ) {
                    temp = temp * 10 + ( rx_temp[i] - '0');
                }
                else {
                    state = 1;
                }
            break;

            // 匹配逗号
            case 1:
                if ( rx_temp[i] == ',') {

                    *p = temp;
                    p++;
                    state = 0;
                    temp = 0;
                 
                }
                else {
                    state = 2;
                     
                }
            break;

            case 2:
                

                goto exit_loop;
            break;
        }

        i++;
        
    }

    *p = temp;
    exit_loop;
    printf("%d \n", position[0]);
    printf("%d \n", position[1]);
    return 0;
} */