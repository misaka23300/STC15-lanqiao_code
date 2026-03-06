#include "onewire.h"

//٥ﺄﻁ¬ﺩﻉﺅﻏ٢؟ﺭﺳﺗ١ﻑﺥﺗﻱ
void Delay_OneWire(unsigned int t)  
{
	//ﺯ؛٦ﺎﺱﺍ٥ﺃ٨ﺅﺭﺳﺗ١
	u8 i;
	while(t--){
		for(i=0;i<12;i++);
	}
}

//٥ﺄﻁ¬ﺩﻉﺫ٤٢ﻋﻁﻐ
void Write_DS18B20(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		DQ = 0;
		DQ = dat&0x01;
		Delay_OneWire(5);
		DQ = 1;
		dat >>= 1;
	}
	Delay_OneWire(5);
}

//٥ﺄﻁ¬ﺩﻉ٦ﺀ٢ﻋﻁﻐ
unsigned char Read_DS18B20(void)
{
	unsigned char i;
	unsigned char dat;
  
	for(i=0;i<8;i++)
	{
		DQ = 0;
		dat >>= 1;
		DQ = 1;
		if(DQ)
		{
			dat |= 0x80;
		}	    
		Delay_OneWire(5);
	}
	return dat;
}

//DS18B20٣ﻰﺗﺱ؛ﺥ
bit init_ds18b20(void)
{
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


float rd_temperature(void){
	u8 low,high;
	int T;
	init_ds18b20();
	Write_DS18B20(0xcc);
	Write_DS18B20(0x44);
	Delay_OneWire(200);
	
	init_ds18b20();
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);
	low = Read_DS18B20();
	high = Read_DS18B20();
	T = high<<8 | low;
	return T/16.0;
}