#ifndef _IIC_H
#define _IIC_H

void AT24C02_Write(unsigned char *dat,unsigned char addr,unsigned char num);
void AT24C02_Read(unsigned char *dat,unsigned char addr,unsigned char num);

#endif