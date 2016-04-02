/**
  Main Source File

  @authors Microchip Technology Inc.
  @authros Matthew Atkins

  @file main.c

  @brief This is the main file generated using MPLAB(c) Code Configurator and the main function of the program.

  @detail
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information:
      - Product Revision  :  MPLAB(c) Code Configurator - v3.00
      - Device            :  PIC18F26K22
      - Driver Version    :  2.00
    The generated drivers are tested against the following:
      - Compiler          :  XC8 1.35
      - MPLAB             :  MPLAB X 3.20
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


static bool readyFlag = false; /**< Flag indicating if the start command has been issued.*/
static arm_state_t arm_state = ARM_DISARMED; /**< Field containg the current armmed status of the mine.*/
/*
                         Main application
 */

/**
 * The main program...
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
//    INTERRUPT_PeripheralInterruptDisable();
    
    delay_25ms_n_times(80);
    
    putchar('\n');
    putchar('\n');
    
    uint8_t data;
    int i = 0;
    
    init();
    
    do {
        
        if (EUSART1_DataReady) {
            
            for (i = 0; i < 15; i++) {
                data = EUSART1_Read();
                charBuff[i] = data;
                
                if (data == '\n') {
                    break;
                }
            }
            
            processCommand(charBuff);
            memcpy(charBuff, '\0', sizeof(charBuff));
        }
    } while (1);
}

/**
 * Delays 25 milliseconds n times for a total delay of  (25ms * n).
 * @param n The number of time to delay.
 */
void delay_25ms_n_times(int16_t n) {
    for (n; n >= 0; n--) {
        __delay_ms (25);
    }
}

void init(void) {
    
    printf("Ready!\n");
    printf("command:> ");
}

/**
 * Processes a command received from the URAT module and execute it if possible.
 * Prints an error if an invalid command is given. The 'help' command may be
 * given to list available commands.
 * @param cmnd The command to execute.
 */
void processCommand(const char* cmnd) {
    
    if (strncmp(cmnd, "start", 5) == 0) {
        
        readyFlag = true;
        
        printf("Starting...\n");
        printf("Initialize program to start state...");
        delay_25ms_n_times(20);
        printf("Done!\t\n");
        printf("Connecting to peripherals...");
        delay_25ms_n_times(20);
        printf("Done!\t\n");
        printf("Connect to PUI...");
        delay_25ms_n_times(20);
        printf("Done!\t\n");
        printf("Waiting for interrupt...\n\n");
        printf("command:> ");
        
        return;
    } else if (strncmp(cmnd, "help", 4) == 0) {
        printCommandList();
        return;
    }
    
    if (readyFlag == false) {
        printf("[ERROR] Please start mine with 'start' first!\n\n");
        return;
    }
    
    if (strncmp(cmnd, "arm_manual", 10) == 0) {
        
        if (arm_state != ARM_DISARMED) {
            printf("[ERROR] Mine is already armed and must be detonated before rearming!\n\n");
            return;
        }
        
        printf("Manual arm command received, arming in manual mode.\n\n");
        arm_state = ARM_MANUAL;
        
    } else if (strncmp(cmnd, "arm_auto", 8) == 0) {
        
        printf("Automatic arm command received, arming in auto mode.\n\n");
        arm_state = ARM_AUTO;
        
    } else if (strncmp(cmnd, "ir_data", 7) == 0) {
        printf("Hit with MIRP packet of type: ");
        
        char tempBuff[3];
        for (int i = 0; i < 3; i++) {
            tempBuff[i] = cmnd[9 + i];
        }
        
        if (strncmp(tempBuff, "DMG", 3) == 0) {
           
            printf("DAMAGE! Detonating!\n");
            printf("Delay 1.5 seconds...");
            delay_25ms_n_times(40);
            printf("Done!\t\n");
            printf("Emit Damage IR packet...");
            delay_25ms_n_times(40);
            printf("Done!\t\n");
            printf("Display detonate LED pattern...");
            delay_25ms_n_times(40);
            printf("Done!\t\n");
            printf("Play detonate audio...");
            delay_25ms_n_times(40);
            printf("Done!\t\n");
            printf("Inform player using remote that mine has detonated...");
            delay_25ms_n_times(40);
            printf("Done!\t\n");
            printf("Reset to disarmed state...");
            arm_state = ARM_DISARMED;
            delay_25ms_n_times(40);
            printf("Done!\t\n");
            printf("Return from detonate subroutine.\n\n");
            
        } else if (strncmp(tempBuff, "STN", 3) == 0) {
            
            printf("STUN! Becoming stunned for 10 seconds!\n");
            printf("Disable Interrupts...");
            delay_25ms_n_times(20);
            printf("Done!\t\n");
            printf("Display LED pattern...");
            delay_25ms_n_times(20);
            printf("Done!\t\n");
            printf("Play stunned audio...");
            delay_25ms_n_times(20);
            printf("Done!\t\n");
            printf("Twiddling our thumbs for 10 seconds...");
            delay_25ms_n_times(20);
            printf("(Fast forward...) Done!\t\n");
            printf("Enable Interrupts...");
            delay_25ms_n_times(20);
            printf("Done!\t\n");
            printf("Return from stunned subroutine.\n\n");
            
        } else {
            printf("Unknown type for ir_data: %s", tempBuff);
        }
        
        memcpy(tempBuff, '\0', sizeof(tempBuff));
        
    } else if (strncmp(cmnd, "ir_send", 7) == 0) {
        
        printf("Sending MIRP packet with a ");
        
        char tempBuff[3];
        for (int i = 0; i < 3; i++) {
            tempBuff[i] = cmnd[9 + i];
        }
        
        if (strncmp(tempBuff, "DMG", 3) == 0) {
            printf("DAMAGE payload...");
            delay_25ms_n_times(40);
            printf("Done!\n\n");
        } else if (strncmp(tempBuff, "HEL", 3) == 0) {
            printf("HEAL payload...!");
            delay_25ms_n_times(40);
            printf("Done!\n\n");
        } else {
            printf("[ERROR] Unknown type for ir_send: %s\n\n", tempBuff);
        }
        
        memcpy(tempBuff, '\0', sizeof(tempBuff));
        
    } else if (strncmp(cmnd, "motion_trigger", 14) == 0) {
        printf("Detected tampering! Detonating!\n");
        printf("Delay 1.5 seconds...");
        delay_25ms_n_times(40);
        printf("Done!\t\n");
        printf("Emit Damage IR packet...");
        delay_25ms_n_times(40);
        printf("Done!\t\n");
        printf("Display detonate LED pattern...");
        delay_25ms_n_times(40);
        printf("Done!\t\n");
        printf("Play detonate audio...");
        delay_25ms_n_times(40);
        printf("Done!\t\n");
        printf("Inform player using remote that mine has detonated...");
        delay_25ms_n_times(40);
        printf("Done!\t\n");
        printf("Reset to disarmed state...");
        arm_state = ARM_DISARMED;
        delay_25ms_n_times(40);
        printf("Done!\t\n");
        printf("Return from detonate subroutine.\n\n");
    
    } else if (strncmp(cmnd, "exit", 4) == 0) {
    
        arm_state = ARM_DISARMED;
        readyFlag = false;
        printf("Goodbye!");
        Reset();
        
    } else {
        printf("Unknown command given: %s\n\n", cmnd);
    }
    
    printf("command:>");
}

/**
 * Prints the list of available commands to the console.
 */
void printCommandList(void) {
    
    printf("help:\n\tPrints this help message.\n\n");
    
    printf("start\n\tSimulates the power being turned on to the mine.\n\n");
    
    printf("arm_manual:\n\tArms the mine in manual mode.\n\n");
    
    printf("arm_auto:\n\tArms the mine in automatic mode.\n\n");
    printf("ir_data -TYPE:\n\tSimulates a <TYPE> type IR packet being received.\n");
    printf("\tValid types are: DMG and STN for damage and stun resp.\n\n");
    
    printf("ir_send -TYPE:\n\tSends the MIRP packet with a payload of TYPE.\n");
    printf("\tValid types are: DMG and HEL for damage and heal resp.\n\n");       
    
    printf("motion_trigger:\n\tSimulates a motion event large enough to be considered tampering.\n\n");
    
    printf("exit:\n\tEnds the current session.");
}

/**
 End of File
*/