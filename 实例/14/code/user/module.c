#include "module.h"
#include "main.h"

// 模块初始化函数
void module_init(void)
{
    // 硬件初始化
    boot_init();
    
    // 初始化UART
    Uart1_Init();
    
    // 初始化日志系统
    log_init(LOG_LEVEL_INFO);
    log_info("System initialization started");
    
    // 功能模块初始化
    log_info("Initializing sensors...");
    read_temperature();
    ds1302_write();
    adc_read(0x03);
    log_info("Sensors initialized");
    
    log_info("System initialization completed");
}

// 模块任务函数
void module_task(void) {
  // 按键任务
  if (key_time >= KEY_TIME) {
    key_task();
    key_time = 0;
  }

  // 频率检测任务
  if (freq_time >= FREQ_TIME) {
    freq_time = 0;
    freq_task();
  }

  // 实时时钟任务
  if (rtc_time >= RTC_TIME) {
    ds1302_read();
    rtc_time = 0;
  }

  // ADC采样任务
  if (adc_time >= ADC_TIME) {
    adc_time = 0;
    adc_task();
  }

  // 温度检测任务
  if (temp_time >= TEMP_TIME) {
    temp_time = 0;
    temp_task();
  }

  // 显示5秒后恢复
  if (dis_5_time >= 3000) {
    display_5_flag = 0;
    display_state = display_last_state;
    dis_5_time = 0;
  }

  // LED闪烁控制
  if (led_1ms_time >= LED_1MS_TIME) {
    led_1ms_time = 0;
    led_1ms_flag = ~led_1ms_flag;
  }
}