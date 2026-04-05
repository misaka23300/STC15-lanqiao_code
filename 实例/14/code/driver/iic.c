#include "iic.h"
#include "log.h"

sbit scl = P2 ^ 0;
sbit sda = P2 ^ 1;
#define DELAY_TIME 10

//
static void I2C_Delay(unsigned char n) {
  do {
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
  } while (n--);
}

//
void I2CStart(void) {
  sda = 1;
  scl = 1;
  I2C_Delay(DELAY_TIME);
  sda = 0;
  I2C_Delay(DELAY_TIME);
  scl = 0;
}

//
void I2CStop(void) {
  sda = 0;
  scl = 1;
  I2C_Delay(DELAY_TIME);
  sda = 1;
  I2C_Delay(DELAY_TIME);
}

//
void I2CSendByte(unsigned char byt) {
  unsigned char i;

  for (i = 0; i < 8; i++) {
    scl = 0;
    I2C_Delay(DELAY_TIME);
    if (byt & 0x80) {
      sda = 1;
    } else {
      sda = 0;
    }
    I2C_Delay(DELAY_TIME);
    scl = 1;
    byt <<= 1;
    I2C_Delay(DELAY_TIME);
  }

  scl = 0;
}

//
unsigned char I2CReceiveByte(void) {
  unsigned char da;
  unsigned char i;
  for (i = 0; i < 8; i++) {
    scl = 1;
    I2C_Delay(DELAY_TIME);
    da <<= 1;
    if (sda)
      da |= 0x01;
    scl = 0;
    I2C_Delay(DELAY_TIME);
  }
  return da;
}

//
unsigned char I2CWaitAck(void) {
  unsigned char ackbit;

  scl = 1;
  I2C_Delay(DELAY_TIME);
  ackbit = sda;
  scl = 0;
  I2C_Delay(DELAY_TIME);

  return ackbit;
}

//
void I2CSendAck(unsigned char ackbit) {
  scl = 0;
  sda = ackbit;
  I2C_Delay(DELAY_TIME);
  scl = 1;
  I2C_Delay(DELAY_TIME);
  scl = 0;
  sda = 1;
  I2C_Delay(DELAY_TIME);
}

uint8_t adc_read(uint8_t address)
{
    uint8_t Data = 0;
    bit ack_received;
    
    log_debug("Reading ADC channel 0x%02X...", address);
    
    // 发送开始信号
    I2CStart();
    
    // 发送设备地址（写）
    I2CSendByte(0x90);
    ack_received = I2CWaitAck();
    if (!ack_received) {
        I2CStop();
        log_error("ADC device address error");
        return 0; // 通信失败，返回0
    }

    // 发送寄存器地址
    I2CSendByte(address);
    ack_received = I2CWaitAck();
    if (!ack_received) {
        I2CStop();
        log_error("ADC register address error");
        return 0; // 通信失败，返回0
    }

    // 停止通信
    I2CStop();

    // 重新开始通信
    I2CStart();
    
    // 发送设备地址（读）
    I2CSendByte(0x91);
    ack_received = I2CWaitAck();
    if (!ack_received) {
        I2CStop();
        log_error("ADC read address error");
        return 0; // 通信失败，返回0
    }

    // 接收数据
    Data = I2CReceiveByte();
    I2CSendAck(1); // 发送非应答信号

    // 停止通信
    I2CStop();
    
    log_debug("ADC read successful: 0x%02X", Data);
    
    return Data;
}
