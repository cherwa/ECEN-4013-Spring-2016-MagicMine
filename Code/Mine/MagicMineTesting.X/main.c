/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  @brief This is the main file generated using MPLAB(c) Code Configurator

  @details This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information:
       - Product Revision  :  MPLAB(c) Code Configurator - v3.00
       - Device            :  PIC18F26K22
       - Driver Version    :  2.00
    The generated drivers are tested against the following:
       - Compiler          :  XC8 1.35
       - MPLAB             :  MPLAB X 3.20
 
 * @copyright Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
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

#include <pic18.h>

#include "main.h"

/*
    Main application
 */

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
//    INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
//    INTERRUPT_PeripheralInterruptDisable();
    
    init_logic();
    connect_to_peripherals();
    
}

static void init_logic(void) {
    
}

static void connect_to_peripherals(void) {
    init_Bluetooth_to_PIU();
    
    self_test_passed = bluetooth_to_PIU_online;
    
    init_Bluetooth_to_remote();
    
    self_test_passed = (self_test_passed & bluetooth_to_remote_online);
    
    init_audio_controller();
    
    self_test_passed = (self_test_passed & audio_controller_online);
    
    // All tests passed?
    if (self_test_passed) {
        // Play success pattern
    } else {
        // Play fail pattern on repeat
    }
}

static void init_Bluetooth_to_PIU(void) {
    /** @todo Actually connect to PIU */
    bluetooth_to_PIU_online = true;
}

static void init_Bluetooth_to_remote(void) {
    /** @todo Actually test 4.0 module */
    bluetooth_to_remote_online = true;
}

static void init_audio_controller(void) {
    /** @todo Actually test the audio controller*/
    audio_controller_online = true;
}

/**
 End of File
*/