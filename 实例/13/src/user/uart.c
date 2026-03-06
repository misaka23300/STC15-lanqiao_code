#include "uart.h"

uint8_t xdata uart_tx_buf[100];
uint8_t xdata uart_rx_buf[100];

uart_flag_t uart_flag;

volatile uint8_t uart_count;

// 串口初始化
void uart_tag_init() {
  uint8_t i;

  uart_flag.tx = 0;
  uart_flag.rx = 0;

  uart_count = 0;

  for (i = 0; i < sizeof(uart_rx_buf) - 1; i++) {
    uart_rx_buf[i] = 0x00;
  }
}

// 串口发送数据
void uart_send_byte(uint8_t byte) {
  while (uart_flag.tx);
  SBUF = byte;
  uart_flag.tx = 1;
}

/**
 *传入了字符串的指针，*str表示指针的取值，str表示指针。
 */
void uart_send_str(uint8_t* str) {
  while (*str) {
    putchar(*str);
    str++;
  }
}

int8_t putchar(int8_t chars) {
  SBUF = chars;
  while (!TI);
  TI = 0;
  return chars;
}

// 串口接收数据
uint8_t uart_receive_byte() {
  uint8_t byte;
  byte = SBUF;
  uart_flag.rx = 1;
  return byte;
}

void uart_receive_str() {
  static uint8_t Data;
  if (uart_count < sizeof(uart_rx_buf) - 1) {
    Data = SBUF;
    uart_rx_buf[uart_count] = Data;

    if (uart_count > 0 && uart_rx_buf[uart_count - 1] == 0x0d &&
        uart_rx_buf[uart_count] == 0x0a) {
      uart_count = 0;
    } else {
      uart_count++;
    }
  }
}

void Uart1_Isr(void) interrupt 4 {
  if (TI)  // 检测串口1发送中断
  {
    TI = 0;  // 清除串口1发送中断请求位
    uart_flag.tx = 0;
  }
  if (RI)  // 检测串口1接收中断
  {
    RI = 0;  // 清除串口1接收中断请求位
    uart_flag.rx = 0;
    uart_receive_str();
  }
}