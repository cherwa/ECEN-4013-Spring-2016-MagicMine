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
#include <stdint.h>
#include "pin_manager.h"
#include <stdbool.h>
#include "../remote_main.h"

uint16_t t_start = 0;

void PIN_MANAGER_Initialize(void)
{
    LATB = 0x0;
    LATA = 0x0;
    LATC = 0x0;
    WPUA = 0x3F;
    WPUB = 0xF0;
    WPUC = 0xFF;
    TRISB = 0x80;
    TRISC = 0x21;
    TRISA = 0xF;
    ANSELA = 0x0;
    ANSELB = 0x0;
    ANSELC = 0x8;

    OPTION_REGbits.nWPUEN = 0x0;

    // enable interrupt-on-change individually
    IOCBN7 = 1;
    IOCCN0 = 1;
    IOCAN2 = 1;
    IOCAN1 = 1;
    IOCAN0 = 1;
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

uint16_t armedButtonPressedStartTime;

void PIN_MANAGER_IOC(void)
{    
    if((IOCBP7 == 1) && (IOCBF7 == 1)) {
        // Check to see if we are armed first
        if (armedMode != DISARMED) {
        
            //Handling code for IOC on positive edge pin RB7 
            uint16_t diff = armedButtonPressedStartTime - TMR1_ReadTimer();
            
            // Timer 1 has it's period set to 25ms so, 3s / 25ms = 120
            if (diff >= 120) {
                // Manual Mode

                // Blink to indicate mode selection
                for (uint8_t i = 0; i < 3; i++) {
                    TRISBbits.TRISB6 = 1;
                    delay_n_ms(5);
                    TRISBbits.TRISB6 = 0;
                    delay_n_ms(20);
                }

                armedMode = MANUAL_MODE;
                armButtonEnabled = true;
                TRISBbits.TRISB6 = 1;

            } else {
                // Auto-mode
               
                // Blink to indicate mode selection
                for (uint8_t i = 0; i < 3; i++) {
                    TRISBbits.TRISB6 = 1;
                    delay_n_ms(5);
                    TRISBbits.TRISB6 = 0;
                    delay_n_ms(20);
                }
                
                armedMode = AUTOMATIC_MODE;
                armButtonEnabled = false;
                TRISBbits.TRISB6 = 0;
            }
        } else {
            // We are already armed, make sure we are in manual mode and try
            // to detonate
            if (armedMode == MANUAL_MODE) {
                // Send the detonate command via bluetooth.
                
                sendBluetoothCommand(DETONATE);
                
                // Did it work?
                while (!EUSART_DataReady) {}
                    
                    
                uint8_t readData = EUSART_Read();

                if (readData == 'Y') {
                    // Clean up the armed state since we detonated successfully
                    armedMode = DISARMED;
                    armButtonEnabled = false;
                    TRISBbits.TRISB6 = 0;
                } else {
                    // We did not detonate successfully!

                    // Indicate error here
                }
                    
            }
        }
        
        // clear interrupt-on-change flag
        IOCBF7 = 0;
    }
    else if((IOCBN7 == 1) && (IOCBF7 == 1))
    {
        //Handling code for IOC falling edge on pin RB7
        // Record start time
        armedButtonPressedStartTime = TMR1_ReadTimer();
        
        // clear interrupt-on-change flag
        IOCBF7 = 0;
    }
    else if((IOCCN0 == 1) && (IOCCF0 == 1))
    {
        //Handling code for IOC on pin RC0 (White Spell)
        
        setSpellType(RED_SPELL);
        WHITE_LED_LAT = 0;
        BLUE_LED_LAT = 0;
        YELLOW_LED_LAT = 0;
        RED_LED_LAT = 1;
        // clear interrupt-on-change flag
        IOCCF0 = 0;
    }
    else if((IOCAN2 == 1) && (IOCAF2 == 1))
    {
        // Handling code for IOC on pin RA2 (Yellow Spell)
        
        setSpellType(YELLOW_SPELL);
        WHITE_LED_LAT = 0;
        BLUE_LED_LAT = 0;
        YELLOW_LED_LAT = 1;
        RED_LED_LAT = 0;
        
        // clear interrupt-on-change flag
        IOCAF2 = 0;        
    }
    else if((IOCAN1 == 1) && (IOCAF1 == 1))
    {
        // Handling code for IOC on pin RA1 (Blue Spell)
        
        setSpellType(BLUE_SPELL);
        WHITE_LED_LAT = 0;
        BLUE_LED_LAT = 1;
        YELLOW_LED_LAT = 0;
        RED_LED_LAT = 0;
        
        // clear interrupt-on-change flag
        IOCAF1 = 0;        
    }
    else if((IOCAN0 == 1) && (IOCAF0 == 1))
    {
        // Handling code for IOC on pin RA0 (White Spell)
        
        setSpellType(WHITE_SPELL);
        WHITE_LED_LAT = 1;
        BLUE_LED_LAT = 0;
        YELLOW_LED_LAT = 0;
        RED_LED_LAT = 0;
        // clear interrupt-on-change flag
        IOCAF0 = 0;        
    }
    
    // If a spell was selected, activate the arm button!
    if (selectedSpell != NO_SELECTION) {
        armButtonEnabled = true;
        TRISBbits.TRISB6 = 1;
    }
}

/**
 End of File
*/