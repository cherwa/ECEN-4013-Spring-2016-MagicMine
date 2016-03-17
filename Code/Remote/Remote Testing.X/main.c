/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F1579
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

#include "remote_main.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    // Initialize Remote's program to start state
    
    // Connect to all peripherals
    
    // Flash button LEDs
    testSpellButtons();
    
    // Flash indicator LEDs
    testIndicatorLEDs();
    
    if (! (spellButtonsPassed & indicatorLEDsPassed) ) {
        // We have failed so bad if we get here...
        // Show failure
    }
    
    // Try to connect to the mine
    //@TODO Activate Bluetooth module and try to connect to the mine
    
    // Indicate success or failure
    
    while (1)
    {
        // Add your application code
    }
}

void setSpellType(const spell_t spellType) {
    selectedSpell = spellType;
}

static void testSpellButtons(void) {
    
    WHITE_LED_LAT = 1;
    BLUE_LED_LAT = 1;
    YELLOW_LED_LAT = 1;
    RED_LED_LAT = 1;
    
    delay_n_ms(20);
    
    WHITE_LED_LAT = 0;
    BLUE_LED_LAT = 0;
    YELLOW_LED_LAT = 0;
    RED_LED_LAT = 0;
    
    delay_n_ms(10);
    
    
    WHITE_LED_LAT = 1;
    BLUE_LED_LAT = 1;
    YELLOW_LED_LAT = 1;
    RED_LED_LAT = 1;
    
    delay_n_ms(20);
    
    WHITE_LED_LAT = 0;
    BLUE_LED_LAT = 0;
    YELLOW_LED_LAT = 0;
    RED_LED_LAT = 0;
    
    delay_n_ms(10);
    
    WHITE_LED_LAT = 1;
    BLUE_LED_LAT = 1;
    YELLOW_LED_LAT = 1;
    RED_LED_LAT = 1;
    
    delay_n_ms(20);
    
    WHITE_LED_LAT = 0;
    BLUE_LED_LAT = 0;
    YELLOW_LED_LAT = 0;
    RED_LED_LAT = 0;
    
    // If no one turns the device off we are good... Probably.
    spellButtonsPassed = true;
}

static void testIndicatorLEDs(void) {
    
    //@TODO Actually test the LEDs
    
    indicatorLEDsPassed = true;
}

//static bool bluetoothEnterCommandMode(void) {
//    
//    EUSART_Write('$');
//    EUSART_Write('$');
//    EUSART_Write('$');
//    
//    return true;
//}

void sendBluetoothCommand(bluetooth_cmnd_t cmnd) {
        
    switch(cmnd) {
        case CONNECT_TO_MINE:
            // Connect to the mine...
            break;
        case HEARTBEAT:
            // Send the heartbeat to the mine to ensure we are still connected.
            break;
        case RANGE_TEST:
            break;
        case SET_ARM_MODE:
            break;
        case DETONATE:
            EUSART_Write('D'); EUSART_Write('E'); EUSART_Write('T');
            break;
        default:
            printf ("Unknown Command Given...");
            break;
        }
}

/**
 End of File
*/