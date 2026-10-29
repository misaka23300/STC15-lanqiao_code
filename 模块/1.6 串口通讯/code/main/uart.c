#include "uart.h"

uint8_t xdata rx_buf[100];
uint8_t xdata tx_buf[100];

void uart_init() {
  memset(rx_buf, 0x00, sizeof(rx_buf));
  memset(tx_buf, 0x00, sizeof(tx_buf));
  printf("初始化完成");
}

int8_t putchar(int8_t c) {
  ES = 0;          // 发送期间关闭串口中断，避免 TI 被中断服务函数抢占清零
  SBUF = c;
  while (!TI)
    ;
  TI = 0;
  ES = 1;
  return c;
}

void Uart1_Isr(void) interrupt 4 {
  if (RI) // 检测串口1接收中断
  {
    RI = 0; // 清除串口1接收中断请求位
  }
}