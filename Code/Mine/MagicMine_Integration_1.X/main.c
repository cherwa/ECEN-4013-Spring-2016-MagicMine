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

#include "main.h"
#include "bluetooth_4.h"

/**
 * Global variable definition
 */

/**
 * Module function definitions
 */

static void initialize();

/**
 * Module variables
 */

typedef enum {
        DEVICE_STATE_INIT,
        DEVICE_STATE_UNARMED,
        DEVICE_STATE_ARMED_AUTO,
        DEVICE_STATE_ARMED_MANUAL,
        DEVICE_STATE_STUNNED
    } mine_state_t;
    
    static current_state = DEVICE_STATE_INIT;

/*
                         Main application
 */
void main(void)
{
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
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("Starting...\n");
    
    // Initialize system
    initialize();
    
    uint8_t clr[3];
    clr[0] = 0x00;
    clr[1] = 0x00;
    clr[2] = 0xF0;
//    fill_color(clr);
    
    uint8_t bg[3];
    bg[0] = 0x00;
    bg[1] = 0x0A;
    bg[2] = 0x00;
    
    uint8_t i = 0;
    
    uint8_t read_byte;
    
    while (1) {
                
        if (EUSART2_DataReady) {
            read_byte = EUSART2_Read();
            if (read_byte == 0x0A) {
                audio_send_command(AUDIO_DAMAGE_CAST);

                   for (i = 0; i < 10; i++) {
                       random();
                   }

//                   current_state = DEVICE_STATE_UNARMED;
                   LED_play_pattern(LED_CLEAR);
            }
        }
        
        if (current_state == DEVICE_STATE_STUNNED) {
            continue;
        }
        
        if(accel_motion_detect()) {
            
            // Blow up!
            transmit_ir_packet(0);
            
            accel_calculate_offset(100);
//            current_state = DEVICE_STATE_UNARMED;
            
            audio_send_command(AUDIO_DAMAGE_CAST);
            
            fading_chase(clr);
            LED_play_pattern(LED_CLEAR);
        }
        
        if (validMIRP_rx && IDH == 0xAB && IDL == 0xCD && STR == 0x64) {
            
            validMIRP_rx = false;
            
            switch (SPELL) {
                case 0x00:
                               
                    audio_send_command(AUDIO_DAMAGE_CAST);

                   for (i = 0; i < 10; i++) {
                       random();
                   }

//                   current_state = DEVICE_STATE_UNARMED;
                   LED_play_pattern(LED_CLEAR);
                   break;
                   
                case 0x02:
                    
                    audio_send_command(AUDIO_STUN_HIT);
                    
//                    current_state = DEVICE_STATE_STUNNED;
                    LED_play_pattern(LED_STUN_CAST);
                    break;
                case 0x04:
                    
                    audio_send_command(AUDIO_HEAL_CAST);
                    
//                    current_state = DEVICE_STATE_UNARMED;
                    LED_play_pattern(LED_HEAL);
                    break;
            }
        }
    }
}

static void initialize() {
    
    if (current_state != DEVICE_STATE_INIT) {
        return;
    }
    
    LED_init();
    pulse();
    LED_play_pattern(LED_CLEAR);
    
    audio_init();
    // Connect to peripherals
    
    accel_initialize_MPU();
    
    delay_25ms_n_times(40);
    
    if (accel_test_connection()) {
        LED_play_pattern(LED_MPU_INIT_SUCCESS);
    } else {
        LED_play_pattern(LED_SELF_TEST_FAILED);
    }
     
//    do {
//        BT2_init();
//    } while (!BT2_is_connected);
    LED_play_pattern(LED_BT2_INIT_SUCCESS);
    
    do {
        BT4_init();
    } while (!BT4_is_connected);
    LED_play_pattern(LED_BT4_INIT_SUCESS);
    
    audio_send_command(0x0009);
    LED_play_pattern(LED_SELF_TEST_PASSED);
    
    current_state = DEVICE_STATE_UNARMED;
}