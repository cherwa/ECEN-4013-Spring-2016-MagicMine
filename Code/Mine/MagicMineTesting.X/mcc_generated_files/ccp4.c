/**
  CCP4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp4.c

  @Summary
    This is the generated driver implementation file for the CCP4 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for CCP4.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC18F26K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
*/

#include <xc.h>
#include "ccp4.h"
#include "../LEDLogic.h"
#include "../util_functions.h"

/**
  Section: Capture Module APIs
*/

void CCP4_Initialize(void)
{
    // Set the CCP4 to the options selected in the User Interface

    // CCP4M Falling edge; DC4B 0; 
    CCP4CON = 0x04;    

    // CCPR4L 0; 
    CCPR4L = 0x00;    

    // CCPR4H 0; 
    CCPR4H = 0x00;    
    
    // Selecting Timer 1
    CCPTMRS1bits.C4TSEL = 0x0;

    // Clear the CCP4 interrupt flag
    PIR4bits.CCP4IF = 0;

    // Enable the CCP4 interrupt
    PIE4bits.CCP4IE = 1;
}

void CCP4_CaptureISR(void)
{
    CCP_PERIOD_REG_T module;

    // Clear the CCP4 interrupt flag
//    PIR4bits.CCP4IF = 0;
    
    // Copy captured value.
    module.ccpr4l = CCPR4L;
    module.ccpr4h = CCPR4H;
    
    // Return 16bit captured value
    CCP4_CallBack(module.ccpr4_16Bit);
}

void CCP4_CallBack(uint16_t capturedValue)
{
    
    if (capturedValue > 40192) {
        PIR4bits.CCP4IF = 0;
        return;
    }
    
    // Add your code here
    if (last_pattern_was_heal) {
        last_pattern_was_heal = 0;
        playPattern(LED_DAMAGE);
    } else {
        last_pattern_was_heal = 1;
        playPattern(LED_HEAL);
    }
    
    // REMOVE AFTER PROTOTYPING
    delay_25ms_n_times(80);
    PIR4bits.CCP4IF = 0;
}
/**
 End of File
*/