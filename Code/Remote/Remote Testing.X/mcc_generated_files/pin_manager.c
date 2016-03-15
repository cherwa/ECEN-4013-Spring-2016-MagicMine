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
#include "../remote_main.h"

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
    TRISA = 0x3F;
    ANSELA = 0x10;
    ANSELB = 0x0;
    ANSELC = 0x8;

    OPTION_REGbits.nWPUEN = 0x0;

    // enable interrupt-on-change individually
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


void PIN_MANAGER_IOC(void)
{    
    if((IOCCN0 == 1) && (IOCCF0 == 1))
    {
        // Handling code for IOC on pin RC0 (Red Spell)
        
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
}

/**
 End of File
*/