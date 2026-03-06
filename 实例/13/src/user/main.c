#include "main.h"

/**
 * 定时器分配：
 *      timer0 ->
 *      timer1 -> 1ms时间片
 *      timer2 -> 串口波特率发生器
 */

void key_task();
void display_task();
void temp_task();
void rtc_task();
void uart_task();

uint8_t uart_rx_buffer;
uint8_t uart_rx_flag;

typedef struct {
  uint16_t run_time;
  uint16_t TASK_TIME;
  void (*task_func)(void);
} task_t;

void task_run(task_t* t) {
  if (t->run_time >= t->TASK_TIME) {
    t->task_func();
    t->run_time = 0;
  }
}

void task_1ms(task_t* t) { t->run_time++; }

task_t led_task_t = {0, 10, led_display};

task_t temp_task_t = {0, 900, temp_task};
int16_t temp_10;

task_t key_task_t = {0, 30, key_task};
uint8_t key_press;

task_t rtc_task_t = {0, 100, rtc_task};

task_t display_task_t = {0, 200, display_task};

task_t uart_task_t = {0, 50, uart_task};

uint8_t display_state = 0;

int8_t temp_argument = 23;     // 初始温度设定值为23℃
int8_t rtc_display_state = 0;  // 初始时钟显示模式为小时:分钟

int8_t relay_5s_flag = 0;  // 继电器5秒标志
uint16_t tick_100ms = 0;   // 100ms计数器
uint8_t flag_100ms = 0;    // 100ms闪烁标志

float temp_data;

void key_task() {
  key_press = key_scan();

  if (key_press == 12) {  // S4键，切换显示状态
    display_state += 1;
    if (display_state == 3) {
      display_state = 0;
    }
  } else if (key_press == 16) {  // S8键，在设定状态下增加温度
    if (display_state == 2) {
      if (temp_argument < 99) temp_argument += 1;
    }
  } else if (key_press ==
             17) {  // S7键，在设定状态下减少温度，在时钟状态下切换显示模式
    if (display_state == 2) {
      if (temp_argument > 10) temp_argument -= 1;
    } else if (display_state == 1) {
      rtc_display_state += 1;
      if (rtc_display_state == 2) {
        rtc_display_state = 0;
      }
    }
  }
}

void temp_task() {
  temp_data = read_temperature();
  printf("读取温度：%d \r \n", (uint8_t)temp_data);
  if (temp_data > temp_argument) {
    relay(1);                // 温度高于设定值，开启继电器
    led_set(3, flag_100ms);  // LED3闪烁
  } else {
    relay(0);       // 温度低于设定值，关闭继电器
    led_set(3, 0);  // LED3熄灭
  }
}

void rtc_task() {
  datetime_read();

  if (time_now[1] == 0 && time_now[2] == 0) {
    relay(1);
    led_set(3, flag_100ms);
    led_set(1, 1);
    relay_5s_flag = 1;
  }
  if (relay_5s_flag && time_now[2] == 5) {
    relay(0);
    led_set(3, 0);
    led_set(1, 0);
    relay_5s_flag = 0;
  }
}

void display_task() {
  uint8_t sign;
  uint16_t abs_temp;

  switch (display_state) {
    case 0: {
      temp_10 = (int16_t)(temp_data * 10);
      sign = 0;  // 0表示正，16表示负
      abs_temp = temp_10;

      if (temp_10 < 0) {
        sign = 16;  // 负号
        abs_temp = -temp_10;
      }

      set_seg(25, 1, sign, 16, 16, abs_temp / 100 % 10,
              abs_temp / 10 % 10 + 32,  // 加32显示带小数点的数字
              abs_temp % 10);
    } break;

    case 1: {
      if (rtc_display_state == 0) {
        set_seg(25, 2, 16, time_now[2] / 10 % 10, time_now[2] % 10, 17,
                time_now[1] / 10 % 10, time_now[1] % 10);
      } else if (rtc_display_state == 1) {
        set_seg(25, 2, 16, time_now[1] / 10 % 10, time_now[1] % 10, 17,
                time_now[0] / 10 % 10, time_now[0] % 10);
      }

    } break;

    case 2: {
      set_seg(25, 3, 16, 16, 16, 16, temp_argument / 10 % 10,
              temp_argument % 10);
    } break;

    default:
      break;
  }
}

void uart_task() {
  // 回显接收到的数据
  if (uart_rx_flag) {
    uart_send_byte(uart_rx_buffer);
    uart_rx_flag = 0;
  }
}

void main() {
  boot_init();
  // led_set(0, 1);
  uart_tag_init();
  // sprintf(uart_tx_buf, "Welcome to XMF system\r\n");
  // uart_send_str((uint8_t*)uart_tx_buf);
  Delay14us();
  printf("ciallo \r \n");
  datetime_write();
  while (1) {
    task_run(&led_task_t);
    task_run(&temp_task_t);
    task_run(&key_task_t);
    task_run(&rtc_task_t);
    task_run(&display_task_t);
    task_run(&uart_task_t);

    if (tick_100ms >= 100) {
      if (flag_100ms == 1) {
        flag_100ms = 0;
      } else {
        flag_100ms = 1;
      }
      tick_100ms = 0;
    }
  }
}
 
void Timer2_Isr(void) interrupt 12 {
  task_1ms(&led_task_t);
  task_1ms(&temp_task_t);
  task_1ms(&key_task_t);
  task_1ms(&rtc_task_t);
  task_1ms(&display_task_t);
  task_1ms(&uart_task_t);

  seg_display();

  if (tick_100ms < 100) {
    tick_100ms++;
  }
}
