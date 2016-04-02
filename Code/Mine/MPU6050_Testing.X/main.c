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
        Device            :  PIC18F24K22
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

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
//    INTERRUPT_GlobalInterruptLowEnable();

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
    
    uint16_t        dataAddress;
    uint8_t         sourceData[6] = {  0x55, 0x55, 0x45,
                                       0x67, 0x23, 0x16}; 
    uint8_t         *pData;
    uint16_t        nCount;

    uint8_t         writeBuffer[3];
    uint8_t         *pD;
    uint16_t        counter, timeOut;

    I2C1_MESSAGE_STATUS status = I2C1_MESSAGE_PENDING;

    dataAddress = 0x10;             // starting EEPROM address 
    pD = sourceData;                // initialize the source of the data
    nCount = 6;                    // number of bytes to write
    
    while (1)
    {
        // Add your application code

        for (counter = 0; counter < nCount; counter++)
        {

            // build the write buffer first
            // starting address of the EEPROM memory
            writeBuffer[0] = (dataAddress >> 8);                // high address
            writeBuffer[1] = (uint8_t)(dataAddress);            // low low address

            // data to be written
            writeBuffer[2] = *pD++;

            // Now it is possible that the slave device will be slow.
            // As a work around on these slaves, the application can
            // retry sending the transaction
            timeOut = 0;
            while(status != I2C1_MESSAGE_FAIL)
            {
                printf("Sending message...\n");
                // write one byte to EEPROM (3 is the number of bytes to write)
                I2C1_MasterWrite(writeBuffer,
                                 3,
                                 0x68,
                                 &status);

                // wait for the message to be sent or status has changed.
                while(status == I2C1_MESSAGE_PENDING);
                
                    printf("Message pending...\n");
                    
                    if (status == I2C1_MESSAGE_COMPLETE)
                        break;

                printf("Message complete...\n");
                // if status is  I2C1_MESSAGE_ADDRESS_NO_ACK,
                //               or I2C1_DATA_NO_ACK,
                // The device may be busy and needs more time for the last
                // write so we can retry writing the data, this is why we
                // use a while loop here

                // check for max retry and skip this byte
                if (timeOut == 100) {
                    printf("Timeout!\n");
                    break;
                } else
                    timeOut++;
            }

            if (status == I2C1_MESSAGE_FAIL)
            {
                printf("Message failed!\n");
                break;
            }
            dataAddress++;

        }
    }
}
/**
 End of File
*/