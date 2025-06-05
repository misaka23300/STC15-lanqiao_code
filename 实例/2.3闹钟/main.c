#include "main.h"

bit key_flag, smg_flag, led_flag, nz_flag, settle_flag, flash_flag, nz_arrive, sec_flag;

uchar duso_type = 0;
uchar time_flag = 0;

uchar led[8] = {0, 0, 0, 0, 0, 0 ,0 ,0};
uchar clock[3] = {0, 0 ,0};
uchar tmp[3] = {0, 0, 0};
uchar n_clock[3] = {99,99,99};

uchar s4_times = 0;
uchar s7_times = 0;

void led_proc()
{
    if (led_flag)
    {
        led_flag = 0;
        if (nz_flag)
        {
            if (nz_arrive)
            {
                led[0] ^= 1;
                led[1] ^= 1;
            }
            else
            {
                led[0] = 0;
                led[1] = 0;
            }
        }
    }
}


void smg_proc()
{
    if (smg_flag)
    {
        smg_flag = 0;
        switch (disp_type)
        {
            case 0:
            {
                if (nz_flag)
                {
                    if (nz_arrive)
                    {
                        if (flash_flag)
                        {
                            flash_flag = 0;
                            // 显示空
                            setcontent(16,16,17,16,16,17,16,16);
                        }
                        else
                        {
                            // 正常显示
                            setcontent(
                                clock[0] / 10, clock[0] % 10,
                                17,
                                clock[1] / 10, clock[1] % 10,
                                17,
                                clock[2] / 10, clock[2] % 10,
                            );
                        }
                    }
                    else
                    {
                        setcontent(
                            clock[0] / 10, clock[0] % 10,
                            17,
                            clock[1] / 10, clock[1] % 10,
                            17,
                            clock[2] / 10, clock[2] % 10,
                        );
                    }
                }

                // 显示时钟
                else
                {
                    setcontent(
                        clock[0]/10, clock[0]%10,
                        17,
                        clock[1]/10, clock[1]%10,
                        17,
                        clock[2]/10, clock[2]%10
                    )
                }
                
            }
            break;
        }
    }
}