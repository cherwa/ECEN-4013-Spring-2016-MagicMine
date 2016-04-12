/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F1579
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20

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

#include <xc.h>
#include "pin_manager.h"
#include <stdbool.h>
#include <pic16f1579.h>
#include "../remote_main.h"
#include "tmr2.h"
#include "../bt_common.h"

/** 
 * The time that the arm button was first pressed when selecting an arming mode.
 * This is used to see how long the button has been held down.
 * <br>
 * If the button has been held down for more than 3 seconds, then the arming mode
 * is set to [MANUAL_MODE](@ref MANUAL_MODE) otherwise it is set to [AUTOMATIC_MODE](@ref AUTOMATIC_MODE).
 */
uint16_t armButtonPressedStartTime;

void PIN_MANAGER_Initialize(void)
{
    LATB = 0x0;
    LATA = 0x0;
    LATC = 0x0;
    WPUA = 0x20;
    WPUB = 0x80;
    WPUC = 0xCC;
    TRISB = 0xF0;
    TRISC = 0xEC;
    TRISA = 0x38;
    ANSELA = 0x0;
    ANSELB = 0x0;
    ANSELC = 0xCC;

    OPTION_REGbits.nWPUEN = 0x1;

    // enable interrupt-on-change individually
    IOCAN4 = 1;
    IOCAN3 = 1;
    IOCBP6 = 1;
    IOCBN6 = 1;
    IOCBN5 = 1;
    IOCBN4 = 1;
    // enable interrupt-on-change globally    
    INTCONbits.IOCIE = 1;   
    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    RXPPSbits.RXPPS = 0x0015;   //RC5->EUSART:RX;
    RC4PPSbits.RC4PPS = 0x0009;   //RC4->EUSART:TX;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
    GIE = state;
}


void PIN_MANAGER_IOC(void)
{    
    if((IOCAN4 == 1) && (IOCAF4 == 1))
    {
        //@TODO Add handling code for IOC on pin RA4
        // BLUE Button
        YELLOW_LED = 0;
        WHITE_LED = 0;
        ARM_LED = armButtonEnabled;
        BLUE_LED = 1;
        RED_LED = 0;
        
        selectedSpell = BLUE_SPELL;
        armButtonEnabled = true;
        
        bt_send_command(BT_CMND_ACK);
        
        // clear interrupt-on-change flag
        IOCAF4 = 0;
    }
    else if((IOCAN3 == 1) && (IOCAF3 == 1))
    {
        //@TODO Add handling code for IOC on pin RA3
        // RED Button
        
        YELLOW_LED = 0;
        WHITE_LED = 0;
        ARM_LED = armButtonEnabled;
        BLUE_LED = 0;
        RED_LED = 1;
        
        selectedSpell = RED_SPELL;
        armButtonEnabled = true;
        
        // clear interrupt-on-change flag
        IOCAF3 = 0;        
    }
    else if((IOCBN6 == 1) && (IOCBF6 == 1) || (IOCBP6 == 1) && (IOCBF6 == 1))
    {
        //@TODO Add handling code for IOC on pin RB6
        // ARM Button

        if (!armButtonEnabled) {
            IOCBF6 = 0;
            return;
        }
        
        TMR2_StartTimer();

            YELLOW_LED = 1;
            WHITE_LED = 1;
            ARM_LED = armButtonEnabled;
            BLUE_LED = 1;
            RED_LED = 1; 
            
            TMR2_StopTimer();
        // clear interrupt-on-change flag
        IOCBF6 = 0;        
    }
    else if((IOCBN5 == 1) && (IOCBF5 == 1))
    {
        //@TODO Add handling code for IOC on pin RB5
        // WHITE Button
        
        YELLOW_LED = 0;
        WHITE_LED = 1;
        ARM_LED = armButtonEnabled;
        BLUE_LED = 0;
        RED_LED = 0;
        
        selectedSpell = WHITE_SPELL;
        armButtonEnabled = true;
        
        // clear interrupt-on-change flag
        IOCBF5 = 0;        
    }
    else if((IOCBN4 == 1) && (IOCBF4 == 1))
    {
        //@TODO Add handling code for IOC on pin RB4
        // YELLOW Button
        
        YELLOW_LED = 1;
        WHITE_LED = 0;
        ARM_LED = armButtonEnabled;
        BLUE_LED = 0;
        RED_LED = 0;
        
        selectedSpell = YELLOW_SPELL;
        armButtonEnabled = true;
        
        // clear interrupt-on-change flag
        IOCBF4 = 0;
    }
    }
        
/**
 End of File
*/