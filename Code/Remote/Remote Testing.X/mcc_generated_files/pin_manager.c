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
volatile uint16_t arm_button_pressed_start_time = 0;

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
    IOCAP4 = 1;
    IOCAP3 = 1;
    IOCBP6 = 1;
    IOCBN6 = 1;
    IOCBP5 = 1;
    IOCBP4 = 1;
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
    if((IOCAP4 == 1) && (IOCAF4 == 1))
    {
        
        delay_n_ms(2);
        if (BLUE_BTN == 1) {
            IOCAF4 = 0;
            return;
        }
        
        //@TODO Add handling code for IOC on pin RA4
        // BLUE Button
        YELLOW_LED = 0;
        WHITE_LED = 0;
        ARM_LED = armButtonEnabled;
        BLUE_LED = 1;
        RED_LED = 0;
        
        selectedSpell = BLUE_SPELL;
        armButtonEnabled = true;
        
        // clear interrupt-on-change flag
        IOCAF4 = 0;
    }
    else if((IOCAP3 == 1) && (IOCAF3 == 1))
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

        arm_held_for_3_seconds = false;
        
        if (!armButtonEnabled) {
            IOCBF6 = 0;
            return;
        }
        
        delay_n_ms(2);
        if (PORTBbits.RB6 == 1) {
            IOCAF4 = 0;
            arm_button_pressed_start_time = 0;
            return;
        }
        
        while (ARM_BTN == 0) {
            __delay_ms (1);
            arm_button_pressed_start_time++;
            
            if (arm_button_pressed_start_time >= 3000) {
                arm_held_for_3_seconds = true;
                ARM_LED = 0;
                delay_n_ms(2);
                ARM_LED = 1;
                delay_n_ms(2);
                ARM_LED = 0;
                delay_n_ms(2);
                ARM_LED = 1;
                delay_n_ms(2);
                ARM_LED = 0;
                delay_n_ms(2);
                ARM_LED = 1;
                break;
            }
        }
        
//        TMR2_StartTimer();
        if (armedMode == STATE_DISARMED) {
            if (arm_held_for_3_seconds) {

                switch (selectedSpell) {
                    case YELLOW_SPELL:
                        printf("I\n%c\n", 0x10);
                        break;
                    case WHITE_SPELL:
                        printf("I\n%c\n", 0x11);
                        break;
                    case BLUE_SPELL:
                        printf("I\n%c\n", 0x12);
                        break;
                    case RED_SPELL:
                        printf("I\n%c\n", 0x13);
                        break;
                }
                
                armedMode = STATE_MANUAL_MODE;

            } else {

                switch (selectedSpell) {
                    case YELLOW_SPELL:
                        printf("I\n%c\n", 0x20);
                        break;
                    case WHITE_SPELL:
                        printf("I\n%c\n", 0x21);
                        break;
                    case BLUE_SPELL:
                        printf("I\n%c\n", 0x22);
                        break;
                    case RED_SPELL:
                        printf("I\n%c\n", 0x23);
                        break;
                }
                
                armedMode = STATE_AUTOMATIC_MODE;
            }
        } else if (armedMode == STATE_MANUAL_MODE) {
            printf("I\n%c\n", 0x00);
            armedMode = STATE_DISARMED;
            arm_button_pressed_start_time = 0;
            arm_held_for_3_seconds = false;
        }
        
        YELLOW_LED = selectedSpell == YELLOW_SPELL;
        WHITE_LED = selectedSpell == WHITE_SPELL;
        ARM_LED = armButtonEnabled || STATE_MANUAL_MODE;
        BLUE_LED = selectedSpell == BLUE_SPELL;
        RED_LED = selectedSpell == RED_SPELL; 
            
//        TMR2_StopTimer();
        // clear interrupt-on-change flag
        IOCBF6 = 0;        
    }
    else if((IOCBP5 == 1) && (IOCBF5 == 1))
    {
        //@TODO Add handling code for IOC on pin RB5
        // WHITE Button
        
        delay_n_ms(2);
        if (WHITE_BTN == 1) {
            IOCBF5 = 0;
            return;
        }
        
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
    else if((IOCBP4 == 1) && (IOCBF4 == 1))
    {
        //@TODO Add handling code for IOC on pin RB4
        // YELLOW Button
        
        delay_n_ms(2);
        if (YELLOW_BTN == 1) {
            IOCBF4 = 0;
            return;
        }
        
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