#include "seg.h"

uchar code duan[] = {
    //   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71,
    // black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00, 0x40, 0x76, 0x1E, 0x70, 0x38, 0x37, 0x5C, 0x73, 0x3E, 0x78, 0x3D, 0x67, 0x50, 0x37, 0x6E,
    0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF, 0x46
}; // 0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

uchar dsp[] = {16, 16, 16, 16, 16, 16, 16, 16};

void setdsp(uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6, uchar c7, uchar c8) {
    dsp[0] = c1;
    dsp[1] = c2;
    dsp[2] = c3;
    dsp[3] = c4;
    dsp[4] = c5;
    dsp[5] = c6;
    dsp[6] = c7;
    dsp[7] = c8;
}

void display() {
    static uchar p;

    P0 = 0xFF;
    Y6;
    Y0;

    P0 = ~duan[dsp[p]];
    Y7;
    Y0;

    P0 = 0x01 << p;
    Y6;
    Y0;

    p++;
    p %= 8;
}