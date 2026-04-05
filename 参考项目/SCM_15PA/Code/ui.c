#include "ui.h"


extern bdata unsigned char flag;

static unsigned char uiIndex = 0;
static unsigned char uiParaIndex = 1;
static unsigned char uiRecdIndex = 1;
static unsigned int  paraMax = 2000;
static int paraOffset = 0;
static unsigned int frqMax = 0;
static unsigned char rtcTime[6];
static unsigned char frqMaxTime[6];
static unsigned char led = 0xFF;
extern unsigned int frq;
static unsigned int frq_adjust = 0;
unsigned char frq_error_flag = 0;

//
void getFrq(void) 
{
    unsigned char dac_val = 0;

    if((flag & 0x20) == 0)
        return;
    flag &= ~0x20;

    rtcGet(rtcTime);

    frq_adjust = frq + paraOffset;
    frq_error_flag = 0;

	if(paraOffset < 0){
		if (frq < -paraOffset){
    		frq_error_flag = 1;
		}
	}

    //频率错误判断
    if(frq_error_flag == 0){

        //频率最大值处理
        if(frqMax <= frq_adjust){
            frqMax = frq_adjust;
            frqMaxTime[0] = rtcTime[0];
            frqMaxTime[1] = rtcTime[1];
            frqMaxTime[2] = rtcTime[2];
            frqMaxTime[3] = rtcTime[3];
            frqMaxTime[4] = rtcTime[4];
            frqMaxTime[5] = rtcTime[5];
        }

        //DAC输出处理
        if(frq_adjust <= 500){
            setDAC(255 * 0.2);    
        }else if((500 < frq_adjust) && (frq_adjust < paraMax)){
            //保留小数点--- 
            //dac_val = 51.0*(4.0*((frq_adjust - 500.0)/(paraMax - 500.0) + 1.0));
            dac_val = 255.0*(4.0*(float)(frq_adjust - 500)/(paraMax - 500) + 1)/5.0;
            setDAC(dac_val);        //ADJUST

        }else{
            setDAC(255); 
        }
    }else{
		setDAC(0);
	}
}

//
void uiRecd(unsigned char recd_num)
{
    setSegData(0, 17);      //H

    if(recd_num == 0x1){
        //F:频率回显
        setSegData(1, 16);
        setSegData(2, 10);
        setSegData(3, frqMax > 10000   ? frqMax/10000      :   10);
        setSegData(4, frqMax > 1000    ? frqMax%10000/1000 :   10);
        setSegData(5, frqMax > 100     ? frqMax%1000/100   :   10);
        setSegData(6, frqMax > 10      ? frqMax%100/10     :   10);   
        setSegData(7, frqMax % 10);            
    }else if(recd_num == 0x2){
        //A:时间回显
        setSegData(1, 15);  
        setSegData(2, frqMaxTime[0]);
        setSegData(3, frqMaxTime[1]);
        setSegData(4, frqMaxTime[2]);
        setSegData(5, frqMaxTime[3]);
        setSegData(6, frqMaxTime[4]);
        setSegData(7, frqMaxTime[5]);
    }
}

//
void uiFrq(void)
{
    setSegData(0, 16);  //F
    setSegData(1, 10);
    setSegData(2, 10);
	
	if(frq_error_flag == 1){
		setSegData(3, 10);
		setSegData(4, 10);
		setSegData(5, 10);
		setSegData(6, 14);
		setSegData(7, 14);
		
	}else{
		setSegData(3, frq_adjust > 10000   ? frq_adjust/10000      :   10);
		setSegData(4, frq_adjust > 1000    ? frq_adjust%10000/1000 :   10);
		setSegData(5, frq_adjust > 100     ? frq_adjust%1000/100   :   10);
		setSegData(6, frq_adjust > 10      ? frq_adjust%100/10     :   10);   
		setSegData(7, frq_adjust % 10); 
	}
}

//
void uiRTC(void)
{
    
    setSegData(0, rtcTime[0]);
    setSegData(1, rtcTime[1]);
    setSegData(2, 12);
    setSegData(3, rtcTime[2]);
    setSegData(4, rtcTime[3]);
    setSegData(5, 12);
    setSegData(6, rtcTime[4]);
    setSegData(7, rtcTime[5]);
}

//
void uiPara(unsigned char para_num)
{
    setSegData(0, 13);  //P
    setSegData(1, para_num);
    setSegData(2, 10);
    setSegData(3, 10);

    if(para_num == 0x1){
        setSegData(4, paraMax/1000);
        setSegData(5, 0);
        setSegData(6, 0);
        setSegData(7, 0);  
    }else if(para_num == 0x2){
        if(paraOffset > 0){
            //正数符号位熄灭
            setSegData(4, 10);
            setSegData(5, paraOffset/100);
            setSegData(6, 0);
        }else if(paraOffset < 0){
            //负数显示符号好
            setSegData(4, 12); 
            setSegData(5, -paraOffset/100); 
            setSegData(6, 0);
        }else{
            setSegData(4, 10);
            setSegData(5, 10);
            setSegData(6, 10);
        }

        setSegData(7, 0); 
    }
}


//
void uiDsp(void)
{
    //
    if((flag & 0x01) == 0)
        return;
    flag &= ~0x02;

    switch(uiIndex){
        case 0:
            uiFrq();
            break;
        case 1:
            uiPara(uiParaIndex);
            break;
        case 2:
            uiRTC();
            break;
        case 3:
            uiRecd(uiRecdIndex);
            break;
    }
}

//
void uiLed(void)
{	
    //LED ---- 100ms
    if((flag & 4) == 0)
        return;
    flag &= ~4;

    //LD1 -- 频率界面指示灯
    if(uiIndex == 0){
        led ^= 1;
    }else{
        led |= 1;
    }
	
	//LD2指示灯控制
	if((frq_adjust > paraMax) && (frq_error_flag == 0)){
		led ^= 2;		
	}else{
		if(frq_adjust <= paraMax){
			led |= 2;
		}else{
			led &= ~2;
		}
	}
    LED(led);
}

//
void uiKey(void)
{
    if(keyGet() == 4){
        keySet(255);
        if(++uiIndex >= 4){
            uiIndex = 0;
        }
        if(uiIndex == 1){
            //参数的默认界面
            uiParaIndex = 1;
        }
        if(uiIndex == 3){
            //回显的默认界面
            uiRecdIndex = 1;
        }
    }else if(keyGet() == 5){
        keySet(255);
        if(uiIndex == 1){
            if(++uiParaIndex == 3){
                uiParaIndex = 1;
            }
        }
        if(uiIndex == 3){
            if(++uiRecdIndex == 3){
                uiRecdIndex = 1;
            }
        }
    }else if(keyGet() == 8){
        keySet(255);
        if(uiIndex == 1){
            //超限参数
            if(uiParaIndex == 1){
                paraMax += 1000;
                if(paraMax == 10000){
                    paraMax = 1000;
                }
            }
            //校准值参数
            if(uiParaIndex == 2){
                paraOffset += 100;
                if(paraOffset == 1000){
                    paraOffset = -900;
                }
            }
        }
    }else if(keyGet() == 9){
        keySet(255);
        if(uiIndex == 1){
            //超限参数
            if(uiParaIndex == 1){
                paraMax -= 1000;
                if(paraMax == 0){
                    paraMax = 9000;
                }
            }
            //校准值参数
            if(uiParaIndex == 2){
                paraOffset -= 100;
                if(paraOffset == -1000){
                    paraOffset = 900;
                }
            }
        }
    }
}