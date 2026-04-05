#include "main.h"

void main(void)
{
    initSysTick();
    initFrqTimer();
    buzOff();
    delay10Ms();
    rtcInit();
    // initDAC();

    while(1){
        getFrq();
        keyScan();
        uiDsp();
        uiKey();
        uiLed();
    }
}