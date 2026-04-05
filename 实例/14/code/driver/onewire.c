#include "onewire.h"
#include "log.h"

sbit DQ = P1 ^ 4;
//
void Delay_OneWire(unsigned int t) {
  unsigned char i;
  while (t--) {
    for (i = 0; i < 12; i++)
      ;
  }
}

//
void Write_DS18B20(unsigned char dat) {
  unsigned char i;
  for (i = 0; i < 8; i++) {
    DQ = 0;
    DQ = dat & 0x01;
    Delay_OneWire(5);
    DQ = 1;
    dat >>= 1;
  }
  Delay_OneWire(5);
}

//
unsigned char Read_DS18B20(void) {
  unsigned char i;
  unsigned char dat;

  for (i = 0; i < 8; i++) {
    DQ = 0;
    dat >>= 1;
    DQ = 1;
    if (DQ) {
      dat |= 0x80;
    }
    Delay_OneWire(5);
  }
  return dat;
}

//
bit init_ds18b20(void) {
  bit initflag = 0;

  DQ = 1;
  Delay_OneWire(12);
  DQ = 0;
  Delay_OneWire(80);
  DQ = 1;
  Delay_OneWire(10);
  initflag = DQ;
  Delay_OneWire(5);

  return initflag;
}

float read_temperature()
{
	float temp = 85.0; // 默认值为85.0，表示读取失败
	unsigned char low, high;
	bit init_ok;
	
	log_debug("Reading temperature...");
	
	// 初始化DS18B20
	init_ok = init_ds18b20();
	if (!init_ok) {
		log_error("Temperature sensor initialization failed");
		return temp; // 初始化失败，返回默认值
	}

	// 发送温度转换命令
	Write_DS18B20(0xcc);
	Write_DS18B20(0x44);

	// 等待转换完成（至少750ms）
	Delay_OneWire(800);

	// 重新初始化
	init_ok = init_ds18b20();
	if (!init_ok) {
		log_error("Temperature sensor read initialization failed");
		return temp; // 初始化失败，返回默认值
	}

	// 发送读取命令
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);

	// 读取温度数据
	low = Read_DS18B20();
	high = Read_DS18B20();

	// 计算温度值
	temp = (high << 8 | low) / 16.0;
	
	// 检查温度值是否有效
	if (temp == 85.0 || temp < -55.0 || temp > 125.0) {
		log_error("Invalid temperature value: %.1f°C", temp);
		return 85.0; // 返回默认值
	}
	
	log_debug("Temperature read successful: %.1f°C", temp);

	return temp;
}