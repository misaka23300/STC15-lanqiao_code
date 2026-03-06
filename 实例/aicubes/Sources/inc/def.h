#ifndef __DEF_H__
#define __DEF_H__

/////////////////////////////////////////////////

typedef bit                     BOOL;

typedef unsigned char           BYTE;
typedef unsigned int            WORD;
typedef unsigned long           DWORD;

typedef signed   char           CHAR;
typedef signed   int            INT;
typedef signed   long           LONG;
                                
typedef unsigned char           uint8_t;
typedef unsigned int            uint16_t;
typedef unsigned long           uint32_t;

typedef signed   char           int8_t;
typedef signed   int            int16_t;
typedef signed   long           int32_t;
                                
typedef unsigned char           uint8;
typedef unsigned int            uint16;
typedef unsigned long           uint32;

typedef signed   char           int8;
typedef signed   int            int16;
typedef signed   long           int32;
                                
typedef unsigned char           u8;
typedef unsigned int            u16;
typedef unsigned long           u32;

typedef signed   char           s8;
typedef signed   int            s16;
typedef signed   long           s32;

/////////////////////////////////////////////////

#ifndef NULL
#define NULL                    0
#endif

#ifndef LOW
#define LOW                     0
#endif

#ifndef HIGH
#define HIGH                    1
#endif

#ifndef FALSE
#define FALSE                   0
#endif

#ifndef TRUE
#define TRUE                    1
#endif

#ifndef DISABLE
#define DISABLE                 0
#endif

#ifndef ENABLE
#define ENABLE                  1
#endif

/////////////////////////////////////////////////

#ifndef min
#define min(a, b)               ((a) < (b) ? (a) : (b))
#endif

#ifndef max
#define max(a, b)               ((a) > (b) ? (a) : (b))
                                
#endif

#ifndef LOBYTE
#define LOBYTE(n)               ((BYTE)(n))
#endif

#ifndef HIBYTE
#define HIBYTE(n)               ((BYTE)(((WORD)(n) >> 8) & 0xff))
#endif

#ifndef LOWORD
#define LOWORD(n)               ((WORD)(n))
#endif

#ifndef HIWORD
#define HIWORD(n)               ((WORD)(((DWORD)(n) >> 16) & 0xffff))
#endif

#ifndef MAKEWORD
#define MAKEWORD(l, h)          ((WORD)(((BYTE)(l)) | ((WORD)((BYTE)(h))) << 8))
#endif

#ifndef MAKELONG
#define MAKELONG(l, h)          ((DWORD)(((WORD)(l)) | ((DWORD)((WORD)(h))) << 16))
#endif

#ifndef BYTE0
#define BYTE0(n)                LOBYTE(n)
#endif

#ifndef BYTE1
#define BYTE1(n)                HIBYTE(n)
#endif

#ifndef BYTE2
#define BYTE2(n)                LOBYTE(HIWORD(n))
#endif

#ifndef BYTE3
#define BYTE3(n)                HIBYTE(HIWORD(n))
#endif

#ifndef WORD0
#define WORD0(n)                LOWORD(n)
#endif

#ifndef WORD2
#define WORD2(n)                HIWORD(n)
#endif

/////////////////////////////////////////////////

#define BIT0                    0x01
#define BIT1                    0x02
#define BIT2                    0x04
#define BIT3                    0x08
#define BIT4                    0x10
#define BIT5                    0x20
#define BIT6                    0x40
#define BIT7                    0x80
#define BIT(b)                  (BIT##b)

#define BIT_LN                  0x0f
#define BIT_HN                  0xf0
#define BIT_ALL                 0xff

#define PIN_0                   BIT0
#define PIN_1                   BIT1
#define PIN_2                   BIT2
#define PIN_3                   BIT3
#define PIN_4                   BIT4
#define PIN_5                   BIT5
#define PIN_6                   BIT6
#define PIN_7                   BIT7

#define PIN_ALL                 BIT_ALL

/////////////////////////////////////////////////

#define CLR_REG_BIT(r, b)       ((r) &= ~(b))
#define SET_REG_BIT(r, b)       ((r) |= (b))
#define CPL_REG_BIT(r, b)       ((r) ^= (b))
#define READ_REG_BIT(r, b)      ((r) & (b))

#define READ_REG(r)             (r)
#define WRITE_REG(r, v)         ((r) = (v))
#define CLR_REG(r)              ((r) = 0)
#define MODIFY_REG(r, clr, set) ((r) = (((r) & ~(clr)) | ((set) & (clr))))

/////////////////////////////////////////////////

#endif


