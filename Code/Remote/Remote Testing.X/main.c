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
#include "mcc_generated_files/mcc.h"

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
    
    // Flash button LEDs
    spellButtonsPassed =  btn_test_spell_btns();
    
    // Flash indicator LEDs
    indicatorLEDsPassed = btn_test_LEDs();
    
    if (! (spellButtonsPassed & indicatorLEDsPassed) ) {
//         We have failed so bad if we get here...
//         Show failure
    }
    
    // Try to connect to the mine
    /** @todo Activate Bluetooth module and try to connect to the mine */
    
    // Indicate success or failure
    
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    __delay_ms (25);
    
    
    __delay_ms(5);
    
    while (1)
    {
        // Add your application code
        printf("Hello World!\n\r");
        __delay_ms(5);
    }
}

void setSpellType(const spell_t spellType) {
    selectedSpell = spellType;
}

bool bluetoothEnterCommandMode() {
    
    EUSART_Write('$');
    EUSART_Write('$');
    EUSART_Write('$');
    
    // Twiddle our thumbs while we wait for data from the module...
    while (!EUSART_DataReady) {}
    
    uint8_t buff[3];
    
    while (eusartRxCount > 0) {
        buff[3 - eusartRxCount] = EUSART_Read();
    }
    
    // Module returns CMD if it entered command mode
    if (buff != "CMD") {
//        indicateError
        
        return false;
    } else {
        return true;
    }
}

/**
 End of File
*/