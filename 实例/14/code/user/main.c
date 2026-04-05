#include "main.h"

// 任务调度时间变量
unsigned char cntr_light = 0;
unsigned char cntr_rtc = 0;
unsigned int  cntr_tmp = 0;
unsigned int  cntr_frq = 0;
unsigned char cntr_key = 0;
unsigned char cntr_dsp = 0;
unsigned char cntr_led = 0;
unsigned int  cntr_3s = 0;

// 频率变量
unsigned int frq = 0; // 频率

// 温度变量
unsigned int temp = 0; // 温度
unsigned int mid_temp = 0;

// 湿度变量
unsigned int hum = 0; // 湿度

// ADC变量
unsigned int adc_light = 0; // 环境光

// 显示状态变量
unsigned char ui = 0; // 切换界面
unsigned char ui_ec = 0; // 回显子界面
unsigned char mid_ui = 0;

// 统计变量
unsigned int sum_temp = 0;
unsigned int sum_hum = 0;
unsigned int max_temp = 0;
unsigned int ave_temp = 0;
unsigned int max_hum = 0;
unsigned int ave_hum = 0;
unsigned int hour = 0;
unsigned int min = 0;
unsigned int count = 0;

// 参数变量
unsigned char para_t = 30; // 默认温度参数:30℃

// 标志变量
bit f_col = 0;

// 1ms中断一次
void initSysTick(void)
{
    AUXR |= 0x04;
    T2L = 0x20;
    T2H = 0xD1;
    AUXR |= 0x10;
    IE2 |= 0x04;
    EA = 1;
}

// 初始化板级外设
void initBsp(void)
{
    // 初始化硬件
    boot_init();
    
    // 初始化UART
    Uart1_Init();
    
    // 初始化日志系统
    log_init(LOG_LEVEL_INFO);
    log_info("System initialization started");
    
    // 初始化传感器
    log_info("Initializing sensors...");
    read_temperature();
    ds1302_write();
    adc_read(0x03);
    log_info("Sensors initialized");
    
    log_info("System initialization completed");
}

// 定时器中断服务函数
void isrSysTick(void) interrupt 12
{
    seg_display();

    if(cntr_light < 200){
        ++cntr_light;
    }
    
    if(cntr_tmp < 200){
        ++cntr_tmp;
    }
    
    if(cntr_rtc < 100){
        ++cntr_rtc;
    }
    
    if(cntr_frq < 1000){
        ++cntr_frq;
    }
    
    if(cntr_led < 100){
        ++cntr_led;
    }
    
    if(cntr_dsp < 50){
        ++cntr_dsp;
    }
        
    if(cntr_key < 10){
        ++cntr_key;
    }
    
    if(cntr_3s > 0){
        --cntr_3s;
    }
}

// 控制任务
void taskControl(void)
{
    static unsigned char led = 0xff;
    static unsigned char old_light = 0;
    static unsigned int old_temp = 0;
    static unsigned char old_hum = 0;
    
    // 100ms 刷新
    if(cntr_led < 100)
        return;
    cntr_led = 0;
    
    if(ui == 0){
        led &= ~1;
        led |= 2;
        led |= 4;
    }else if(ui == 1){
        led &= ~2;
        led |= 1;
        led |= 4;
    }else if(ui == 'T'){
        led &= ~4;
        led |= 1;
        led |= 2;
    }else{
        led |= 1;
        led |= 2;
        led |= 4;
    }
    
    if(temp > para_t*10){
        led ^= (1<<3);
    }else{
        led |= (1<<3);
    }
    
    if(hum == 'S'){
        led &= ~(1<<4);
    }else{
        led |= (1<<4);
    }
    
    /* 启动采集 */
    if((adc_light < 30)&&(old_light > 30)){
        if(cntr_3s == 0){
            f_col = 1;
            mid_ui = ui;
            ui = 'T';
            cntr_3s = 3000;
        }
    }
    /* 返回界面 */
    if((cntr_3s == 0)&&(ui == 'T')){
        ui = mid_ui;
    }

    old_light = adc_light;
    
    /* 温/湿度最大值及平均值计算 */
    if(f_col == 1){
        f_col = 0;
        
        old_temp = temp;
        old_hum = hum;
        
        temp = mid_temp;
        
        /* 频率转湿度 */
        if((frq < 200)||(frq > 2000)){
            hum = 'S';
        }else{
            /* hum = 2frq/45 + 10/9 */
            hum = (unsigned int)((2*frq + 50)/45.0);
            count++;
        }
        
        if(hum != 'S'){
            hour = (now_time[2]/10*10) + (now_time[2]%10);
            min  = (now_time[1]/10*10) + (now_time[1]%10);
            /* 温度最大值 */
            if(temp > max_temp){
                max_temp = temp;
            }
            /* 温度平均值 */
            sum_temp = (count-1)*ave_temp + temp;
            ave_temp = sum_temp/count;
            
            /* 湿度最大值 */
            if(hum > max_hum){
                max_hum = hum;
            }
            /* 湿度平均值 */
            sum_hum = (count-1)*ave_hum + hum*10;
            ave_hum = sum_hum/(count);
        }
    }
    
    /* L6点亮 */
    if(count >= 2){
        if((old_temp < temp)&&(old_hum < hum)){
            led &= ~(1<<5);
        }else{
            led |= (1<<5);
        }
    }

    // 设置LED状态
    P0 = led;
    P2 = (P2 & 0x1F | 0x80);
    P2 &= 0x1F;
}

// 采集任务
void taskCollect(void)
{
    /* 采集温度数据  */
    if(cntr_tmp == 200){
        cntr_tmp = 0;
        float temp_val = read_temperature();
        if (temp_val != 85.0) {
            mid_temp = (unsigned int)(temp_val * 10);
        }
    }
    
    /* 采集环境光数据  */
    if(cntr_light == 200){
        cntr_light = 0;
        adc_light = adc_read(0x01);
    }
    
    /* 采集RTC数据  */
    if(cntr_rtc == 100){
        cntr_rtc = 0;
        ds1302_read();
    }
    
    /* 采集频率数据 */
    if(cntr_frq == 1000){
        cntr_frq = 0;
        frq = freq;
        freq = 0;
    }
        
    if(cntr_key == 10){
        cntr_key = 0;
        uint8_t key = key_scan();
        if (key != 0) {
            taskKey(key);
        }
    }
}

// 按键任务
void taskKey(uint8_t key)
{
    // 按键部分处理
    switch(key){
        /* S4 */
        case 4:
            if(ui != 'T'){
                if(++ui == 3){
                    ui = 0;
                }
            }
            ui_ec = 0;
            break;
        /* S5 */
        case 5:
            if(ui == 1){
                if(++ui_ec == 3){
                    ui_ec = 0;
                }
            }
            break;
        /* S8 */
        case 8:
            if(ui == 2){
                if(para_t < 99){
                    ++para_t;
                }
            }
            break;
        /* S9 */
        case 9:
            if(ui == 2){
                if(para_t > 0){
                    --para_t;
                }
            }
            break;
        /* 长按键 */
        case 29:
            if(ui_ec == 2){
                count = 0;
                hour = 0;
                min = 0;
                temp = 0;
                hum = 0;
                max_temp = 0;
                ave_temp = 0;
                max_hum = 0;
                ave_hum = 0;
            }
            break;
        default:
            break;
    }
}

// 显示任务
void taskDisplay(void)
{
    // 显示部分处理
    if(cntr_dsp < 50){
        return;
    }
    cntr_dsp = 0;
    
    switch(ui){
        case 0:
            // 时间界面
            set_seg(0, now_time[2] / 10 % 10);
            set_seg(1, now_time[2] % 10);
            set_seg(2, 17);
            set_seg(3, now_time[1] / 10 % 10);
            set_seg(4, now_time[1] % 10);
            set_seg(5, 17);
            set_seg(6, now_time[0] / 10 % 10);
            set_seg(7, now_time[0] % 10);
            break;
        case 1:
            if(count != 0){
                /* 回显界面 */
                switch(ui_ec){
                    /* 温度回显 */
                    case 0:
                        set_seg(0, 12);
                        set_seg(1, 16);
                        set_seg(2, max_temp/100);
                        set_seg(3, max_temp%100/10);
                        set_seg(4, 17);
                        set_seg(5, ave_temp/100);
                        set_seg(6, ave_temp%100/10);
                        set_seg(7, ave_temp%10);
                        break;
                    /* 湿度回显 */
                    case 1:
                        set_seg(0, 18);
                        set_seg(1, 16);
                        set_seg(2, max_hum/10);
                        set_seg(3, max_hum%10);
                        set_seg(4, 17);
                        set_seg(5, ave_hum/100);
                        set_seg(6, ave_hum%100/10);
                        set_seg(7, ave_hum%10);
                        break;
                    /* 时间回显 */
                    case 2:
                        set_seg(0, 15);
                        set_seg(1, count/10);
                        set_seg(2, count%10);
                        set_seg(3, hour/10);
                        set_seg(4, hour%10);
                        set_seg(5, 17);
                        set_seg(6, min/10);
                        set_seg(7, min%10);
                        break;
                }
                break;
            }else{
                /* 回显界面 */
                switch(ui_ec){
                    /* 温度回显 */
                    case 0:
                        set_seg(0, 12);
                        set_seg(1, 16);
                        set_seg(2, 10);
                        set_seg(3, 10);
                        set_seg(4, 10);
                        set_seg(5, 10);
                        set_seg(6, 10);
                        set_seg(7, 10);
                        break;
                    /* 湿度回显 */
                    case 1:
                        set_seg(0, 18);
                        set_seg(1, 16);
                        set_seg(2, 10);
                        set_seg(3, 10);
                        set_seg(4, 10);
                        set_seg(5, 10);
                        set_seg(6, 10);
                        set_seg(7, 10);
                        break;
                    /* 时间回显 */
                    case 2:
                        set_seg(0, 15);
                        set_seg(1, count/10);
                        set_seg(2, count%10);
                        set_seg(3, 10);
                        set_seg(4, 10);
                        set_seg(5, 10);
                        set_seg(6, 10);
                        set_seg(7, 10);
                        break;
                }
            }
            break;
        /* 参数界面 */
        case 2:
            set_seg(0, 24);
            set_seg(1, 16);
            set_seg(2, 16);
            set_seg(3, 16);
            set_seg(4, 16);
            set_seg(5, 16);
            set_seg(6, para_t/10);
            set_seg(7, para_t%10);
            break;
        /* 温湿度界面 */
        case 'T':
            set_seg(0, 14);
            set_seg(1, 16);
            set_seg(2, 16);
            set_seg(3, temp/100);
            set_seg(4, temp%100/10);
            set_seg(5, 17);
            if(hum == 'S'){
                set_seg(6, 17);
                set_seg(7, 17);
            }else{
                set_seg(6, hum/10);
                set_seg(7, hum%10);
            }
            break;
    }
}

// 主函数
void main(void)
{
    initSysTick();
    initBsp();
    
    while(1){
        taskCollect();
        taskDisplay();
        taskControl();
    }
}

// 定时器0中断服务函数
void Timer0_Isr(void) interrupt 1 { freq++ }

// 定时器2中断服务函数
void Timer2_Isr(void) interrupt 12 {
    isrSysTick();
}