#include "ds1302.h"
#include "log.h"

sbit SCK = P1 ^ 7;
sbit SDA = P2 ^ 3;
sbit RST = P1 ^ 3;

uint8_t code write_address[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};
uint8_t code read_address[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d};

uint8_t set_time[7] = {0x50, 0x59, 0x23, 0x01, 0x01, 0x01, 0x26};
uint8_t now_time[3];

//
void Write_Ds1302(unsigned char temp) {
  unsigned char i;
  for (i = 0; i < 8; i++) {
    SCK = 0;
    SDA = temp & 0x01;
    temp >>= 1;
    SCK = 1;
  }
}

//
void Write_Ds1302_Byte(unsigned char address, unsigned char dat) {
  RST = 0;
  _nop_();
  SCK = 0;
  _nop_();
  RST = 1;
  _nop_();
  Write_Ds1302(address);
  Write_Ds1302(dat);
  RST = 0;
}

//
unsigned char Read_Ds1302_Byte(unsigned char address) {
  unsigned char i, temp = 0x00;
  RST = 0;
  _nop_();
  SCK = 0;
  _nop_();
  RST = 1;
  _nop_();
  Write_Ds1302(address);
  for (i = 0; i < 8; i++) {
    SCK = 0;
    temp >>= 1;
    if (SDA)
      temp |= 0x80;
    SCK = 1;
  }
  RST = 0;
  _nop_();
  SCK = 0;
  _nop_();
  SCK = 1;
  _nop_();
  SDA = 0;
  _nop_();
  SDA = 1;
  _nop_();
  return (temp);
}

uint8_t bcd_to_hex(uint8_t bcd) { return bcd / 16 * 10 + bcd % 16; }

void ds1302_write() {
  uint8_t i;
  Write_Ds1302_Byte(0x8e, 0x00);
  for (i = 0; i < 7; i++) {
    Write_Ds1302_Byte(write_address[i], set_time[i]);
  }
  Write_Ds1302_Byte(0x8e, 0x80);
}

// 检查BCD值是否有效
bit is_valid_bcd(uint8_t bcd, uint8_t max_value) {
  uint8_t high = bcd >> 4;
  uint8_t low = bcd & 0x0F;

  if (high > 9 || low > 9) {
    return 0; // BCD格式无效
  }

  uint8_t decimal = high * 10 + low;
  return (decimal <= max_value);
}

void ds1302_read()
{
	uint8_t i;
	uint8_t temp_time[3];
	bit valid = 1;
	
	log_debug("Reading RTC time...");
	
	// 读取原始BCD数据
	for (i = 0; i < 3; i++) {
		temp_time[i] = Read_Ds1302_Byte(read_address[i]);
	}
	
	// 检查数据有效性
	if (!is_valid_bcd(temp_time[0], 59)) { // 秒
		valid = 0;
		log_error("Invalid RTC second value: 0x%02X", temp_time[0]);
	}
	if (!is_valid_bcd(temp_time[1], 59)) { // 分
		valid = 0;
		log_error("Invalid RTC minute value: 0x%02X", temp_time[1]);
	}
	if (!is_valid_bcd(temp_time[2], 23)) { // 时
		valid = 0;
		log_error("Invalid RTC hour value: 0x%02X", temp_time[2]);
	}
	
	// 如果数据有效，转换并保存
	if (valid) {
		for (i = 0; i < 3; i++) {
			now_time[i] = bcd_to_hex(temp_time[i]);
		}
		log_debug("RTC time read successful: %02d:%02d:%02d", 
				now_time[2], now_time[1], now_time[0]);
	} else {
		log_error("Invalid RTC time data");
	}
	// 否则保持原有值不变
}