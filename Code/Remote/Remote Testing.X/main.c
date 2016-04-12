/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  @file main.c

  @brief This is the main file generated using MPLAB(c) Code Configurator

  @details This header file provides implementations for driver APIs for all modules selected in the GUI.
 * <br>
    Generation Information:
       - Product Revision   :  MPLAB(c) Code Configurator v3.00
       - Device            :  PIC16F1579
       - Driver Version    :  2.00
 * <p>
    The generated drivers are tested against the following:
       - Compiler          :  XC8 1.35
       - MPLAB             :  MPLAB X 3.20
 
@copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include "remote_main.h"

// Global vars
volatile spell_t selectedSpell = NULL;
volatile arm_mode_t armedMode = STATE_DISARMED;
volatile bool armButtonEnabled = false;
volatile bool connectedToMine = false;
volatile bool arm_held_for_3_seconds = false;

/**
 * @brief Main application
 */
void main()
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
    
    YELLOW_LED = 1;
    delay_n_ms(40);
    WHITE_LED = 1;
    delay_n_ms(40);
    ARM_LED = 1;
    delay_n_ms(40);
    BLUE_LED = 1;
    delay_n_ms(40);
    RED_LED = 1;
    delay_n_ms(40);
    
    connect_to_peripherals();
    
    // Flash indicator LEDs
//    indicatorLEDsPassed = btn_test_LEDs();
    
//    if (! (spellButtonsPassed & indicatorLEDsPassed) ) {
//         We have failed so bad if we get here...
//         Show failure
//    }
    
    // Indicate success or failure
    
    while (1)
    {
        // Add your application code 
//        printf("I\n");
//        printf("%c\n", 0x0A);
//        delay_n_ms(40);
    }
}

void connect_to_peripherals() {
    
    // Flash button LEDs
    btn_init();
//    spellButtonsPassed =  btn_test_spell_btns();
    
//    do {
//        bt_init();
//    } while(!bt_is_connected);
    BLUE_LED = 1;
    WHITE_LED = 1;
    delay_n_ms(2);
    BLUE_LED = 0;
    WHITE_LED = 0;
    delay_n_ms(2);
    BLUE_LED = 1;
    WHITE_LED = 1;
    delay_n_ms(2);
    BLUE_LED = 0;
    WHITE_LED = 0;
    delay_n_ms(2);
    BLUE_LED = 1;
    WHITE_LED = 1;
}
/**
 End of File
*/