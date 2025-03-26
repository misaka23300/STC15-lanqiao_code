#include "sonic.h"

sbit tx = P3 ^ 0;
sbit rx = P3 ^ 1;

void sonic_send()
{
    uchar i;
    for (i = 0;i < 14;i++)
    {
        tx = 1;
        Delay14us();
        tx = 0;
        Delay14us();
    }
}


uchar sonic_measure()
{
   TR1 = 0;
   TH0 = 0; TL0 = 0;
   TF0 = 0;
   
   sonic_send();
   while (rx == 0);
   TR1 = 1;

   while (rx == 1 && TF1 == 0);
   TR1 = 0;

   if (TF1 == 1)
   {
        distance = 99;
        TF1 = 0;
   }
   else
   {
        distance = (uchar) ((TH1 << 8) | TL1) * 0.017;
   }
   return distance;
}