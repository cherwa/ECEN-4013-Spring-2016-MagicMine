/**
 * @author modified by Rahul Chidurala
 * @date April 4,2016
 * TMR2 needed for IR TX
 */

/**
  TMR2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr2.c

  @Summary
    This is the generated driver implementation file for the TMR2 driver using MPLAB� Code Configurator

  @Description
    This source file provides APIs for TMR2.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC18F26K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
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
#include "tmr2.h"

/**
  Section: TMR2 APIs
 */

void TMR2_Initialize(void) {
    // Set TMR2 to the options selected in the User Interface

    // TMR2ON off; T2OUTPS 1:1; T2CKPS 1:1; 
    T2CON = 0x00;

    // PR2 104; 
    PR2 = 0x68;

    // TMR2 0x0; 
    TMR2 = 0x00;

    // Clearing IF flag.
    PIR1bits.TMR2IF = 0;

    // Start TMR2
    TMR2_StartTimer();
}

void TMR2_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    // CCP4M PWM; DC4B 48;
    CCP4CON = 0x3C;
    T2CONbits.TMR2ON = 1;
}

void TMR2_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    //while(PORTBbits.RB0 >= 0.2){}
//    while(PORTBbits.RB0 >= 0.3)//ensures only turn off timer when PWM is low
//    {
//        //TMR2 = 0; //forces next cycle I think
//        __delay_us(1);
//    }
    //Pg 186
    //Note 2: Clearing the CCPxCON register will
    //relinquish control of the CCPx pin.
    CCP4CON = 0; //relinquishes control of PWM
    LATBbits.LB0 = 0; //drive it low
    T2CONbits.TMR2ON = 0;
}

uint8_t TMR2_ReadTimer(void) {
    uint8_t readVal;

    readVal = TMR2;

    return readVal;
}

void TMR2_WriteTimer(uint8_t timerVal) {
    // Write to the Timer2 register
    TMR2 = timerVal;
}

void TMR2_LoadPeriodRegister(uint8_t periodVal) {
    PR2 = periodVal;
}

bool TMR2_HasOverflowOccured(void) {
    // check if  overflow has occurred by checking the TMRIF bit
    bool status = PIR1bits.TMR2IF;
    if (status) {
        // Clearing IF flag.
        PIR1bits.TMR2IF = 0;
    }
    return status;
}
/**
  End of File
 */