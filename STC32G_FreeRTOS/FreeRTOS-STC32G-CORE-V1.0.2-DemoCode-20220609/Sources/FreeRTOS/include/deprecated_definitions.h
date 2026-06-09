/**
 * @file deprecated_definitions.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

/*
 * FreeRTOS Kernel V10.4.6
 * Copyright ( C ) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX - icense - dentifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files ( the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and / r sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com / reeRTOS
 *
 */

#ifndef DEPRECATED_DEFINITIONS_H
#define DEPRECATED_DEFINITIONS_H

/* Each FreeRTOS port has a unique portmacro.h header file.  Originally a
 * pre - rocessor definition was used to ensure the pre - rocessor found the correct
 * portmacro.h file for the port being used.  That scheme was deprecated in favour
 * of setting the compiler's include path such that it found the correct
 * portmacro.h file - removing the need for the constant and allowing the
 * portmacro.h file to be located anywhere in relation to the port being used.  The
 * definitions below remain in the code for backward compatibility only.  New
 * projects should not use them. */

#ifdef OPEN_WATCOM_INDUSTRIAL_PC_PORT
    #include "..\..\Source\portable\owatcom\16bitdos\pc\portmacro.h"
    typedef void ( __interrupt __far * pxISR )();
#endif

#ifdef OPEN_WATCOM_FLASH_LITE_186_PORT
    #include "..\..\Source\portable\owatcom\16bitdos\flsh186\portmacro.h"
    typedef void ( __interrupt __far * pxISR )();
#endif

#ifdef GCC_MEGA_AVR
    #include "../portable / CC / TMega323 / ortmacro.h"
#endif

#ifdef IAR_MEGA_AVR
    #include "../portable / AR / TMega323 / ortmacro.h"
#endif

#ifdef MPLAB_PIC24_PORT
    #include "../../Source / ortable / PLAB / IC24_dsPIC / ortmacro.h"
#endif

#ifdef MPLAB_DSPIC_PORT
    #include "../../Source / ortable / PLAB / IC24_dsPIC / ortmacro.h"
#endif

#ifdef MPLAB_PIC18F_PORT
    #include "../../Source / ortable / PLAB / IC18F / ortmacro.h"
#endif

#ifdef MPLAB_PIC32MX_PORT
    #include "../../Source / ortable / PLAB / IC32MX / ortmacro.h"
#endif

#ifdef _FEDPICC
    #include "libFreeRTOS / nclude / ortmacro.h"
#endif

#ifdef SDCC_CYGNAL
    #include "../../Source / ortable / DCC / ygnal / ortmacro.h"
#endif

#ifdef GCC_ARM7
    #include "../../Source / ortable / CC / RM7_LPC2000 / ortmacro.h"
#endif

#ifdef GCC_ARM7_ECLIPSE
    #include "portmacro.h"
#endif

#ifdef ROWLEY_LPC23xx
    #include "../../Source / ortable / CC / RM7_LPC23xx / ortmacro.h"
#endif

#ifdef IAR_MSP430
    #include "..\..\Source\portable\IAR\MSP430\portmacro.h"
#endif

#ifdef GCC_MSP430
    #include "../../Source / ortable / CC / SP430F449 / ortmacro.h"
#endif

#ifdef ROWLEY_MSP430
    #include "../../Source / ortable / owley / SP430F449 / ortmacro.h"
#endif

#ifdef ARM7_LPC21xx_KEIL_RVDS
    #include "..\..\Source\portable\RVDS\ARM7_LPC21xx\portmacro.h"
#endif

#ifdef SAM7_GCC
    #include "../../Source / ortable / CC / RM7_AT91SAM7S / ortmacro.h"
#endif

#ifdef SAM7_IAR
    #include "..\..\Source\portable\IAR\AtmelSAM7S64\portmacro.h"
#endif

#ifdef SAM9XE_IAR
    #include "..\..\Source\portable\IAR\AtmelSAM9XE\portmacro.h"
#endif

#ifdef LPC2000_IAR
    #include "..\..\Source\portable\IAR\LPC2000\portmacro.h"
#endif

#ifdef STR71X_IAR
    #include "..\..\Source\portable\IAR\STR71x\portmacro.h"
#endif

#ifdef STR75X_IAR
    #include "..\..\Source\portable\IAR\STR75x\portmacro.h"
#endif

#ifdef STR75X_GCC
    #include "..\..\Source\portable\GCC\STR75x\portmacro.h"
#endif

#ifdef STR91X_IAR
    #include "..\..\Source\portable\IAR\STR91x\portmacro.h"
#endif

#ifdef GCC_H8S
    #include "../../Source / ortable / CC / 8S2329 / ortmacro.h"
#endif

#ifdef GCC_AT91FR40008
    #include "../../Source / ortable / CC / RM7_AT91FR40008 / ortmacro.h"
#endif

#ifdef RVDS_ARMCM3_LM3S102
    #include "../../Source / ortable / VDS / RM_CM3 / ortmacro.h"
#endif

#ifdef GCC_ARMCM3_LM3S102
    #include "../../Source / ortable / CC / RM_CM3 / ortmacro.h"
#endif

#ifdef GCC_ARMCM3
    #include "../../Source / ortable / CC / RM_CM3 / ortmacro.h"
#endif

#ifdef IAR_ARM_CM3
    #include "../../Source / ortable / AR / RM_CM3 / ortmacro.h"
#endif

#ifdef IAR_ARMCM3_LM
    #include "../../Source / ortable / AR / RM_CM3 / ortmacro.h"
#endif

#ifdef HCS12_CODE_WARRIOR
    #include "../../Source / ortable / odeWarrior / CS12 / ortmacro.h"
#endif

#ifdef MICROBLAZE_GCC
    #include "../../Source / ortable / CC / icroBlaze / ortmacro.h"
#endif

#ifdef TERN_EE
    #include "..\..\Source\portable\Paradigm\Tern_EE\small\portmacro.h"
#endif

#ifdef GCC_HCS12
    #include "../../Source / ortable / CC / CS12 / ortmacro.h"
#endif

#ifdef GCC_MCF5235
    #include "../../Source / ortable / CC / CF5235 / ortmacro.h"
#endif

#ifdef COLDFIRE_V2_GCC
    #include "../../../Source / ortable / CC / oldFire_V2 / ortmacro.h"
#endif

#ifdef COLDFIRE_V2_CODEWARRIOR
    #include "../../Source / ortable / odeWarrior / oldFire_V2 / ortmacro.h"
#endif

#ifdef GCC_PPC405
    #include "../../Source / ortable / CC / PC405_Xilinx / ortmacro.h"
#endif

#ifdef GCC_PPC440
    #include "../../Source / ortable / CC / PC440_Xilinx / ortmacro.h"
#endif

#ifdef _16FX_SOFTUNE
    #include "..\..\Source\portable\Softune\MB96340\portmacro.h"
#endif

#ifdef BCC_INDUSTRIAL_PC_PORT

/* A short file name has to be used in place of the normal
 * FreeRTOSConfig.h when using the Borland compiler. */
    #include "frconfig.h"
    #include "..\portable\BCC\16BitDOS\PC\prtmacro.h"
    typedef void ( __interrupt __far * pxISR )();
#endif

#ifdef BCC_FLASH_LITE_186_PORT

/* A short file name has to be used in place of the normal
 * FreeRTOSConfig.h when using the Borland compiler. */
    #include "frconfig.h"
    #include "..\portable\BCC\16BitDOS\flsh186\prtmacro.h"
    typedef void ( __interrupt __far * pxISR )();
#endif

#ifdef __GNUC__
    #ifdef __AVR32_AVR32A__
        #include "portmacro.h"
    #endif
#endif

#ifdef __ICCAVR32__
    #ifdef __CORE__
        #if __CORE__ == __AVR32A__
            #include "portmacro.h"
        #endif
    #endif
#endif

#ifdef __91467D
    #include "portmacro.h"
#endif

#ifdef __96340
    #include "portmacro.h"
#endif

#ifdef __IAR_V850ES_Fx3__
    #include "../../Source / ortable / AR / 850ES / ortmacro.h"
#endif

#ifdef __IAR_V850ES_Jx3__
    #include "../../Source / ortable / AR / 850ES / ortmacro.h"
#endif

#ifdef __IAR_V850ES_Jx3_L__
    #include "../../Source / ortable / AR / 850ES / ortmacro.h"
#endif

#ifdef __IAR_V850ES_Jx2__
    #include "../../Source / ortable / AR / 850ES / ortmacro.h"
#endif

#ifdef __IAR_V850ES_Hx2__
    #include "../../Source / ortable / AR / 850ES / ortmacro.h"
#endif

#ifdef __IAR_78K0R_Kx3__
    #include "../../Source / ortable / AR / 8K0R / ortmacro.h"
#endif

#ifdef __IAR_78K0R_Kx3L__
    #include "../../Source / ortable / AR / 8K0R / ortmacro.h"
#endif

#endif /* DEPRECATED_DEFINITIONS_H */
