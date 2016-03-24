/**
  TMR4 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr4.h

  @Summary
    This is the generated header file for the TMR4 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for TMR4.
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

#ifndef _TMR4_H
#define _TMR4_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


/**
  Section: Macro Declarations
*/

/**
  Section: TMR4 APIs
*/

/**
  @Summary
    Initializes the TMR4 module.

  @Description
    This function initializes the TMR4 Registers.
    This function must be called before any other TMR4 function is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    main()
    {
        // Initialize TMR4 module
        TMR4_Initialize();

        // Do something else...
    }
    </code>
*/
void TMR4_Initialize(void);

/**
  @Summary
    This function starts the TMR4.

  @Description
    This function starts the TMR4 operation.
    This function must be called after the initialization of TMR4.

  @Preconditions
    Initialize  the TMR4 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR4 module

    // Start TMR4
    TMR4_StartTimer();

    // Do something else...
    </code>
*/
void TMR4_StartTimer(void);

/**
  @Summary
    This function stops the TMR4.

  @Description
    This function stops the TMR4 operation.
    This function must be called after the start of TMR4.

  @Preconditions
    Initialize  the TMR4 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR4 module

    // Start TMR4
    TMR4_StartTimer();

    // Do something else...

    // Stop TMR4;
    TMR4_StopTimer();
    </code>
*/
void TMR4_StopTimer(void);

/**
  @Summary
    Reads the TMR4 register.

  @Description
    This function reads the TMR4 register value and return it.

  @Preconditions
    Initialize  the TMR4 before calling this function.

  @Param
    None

  @Returns
    This function returns the current value of TMR4 register.

  @Example
    <code>
    // Initialize TMR4 module

    // Start TMR4
    TMR4_StartTimer();

    // Read the current value of TMR4
    if(0 == TMR4_ReadTimer())
    {
        // Do something else...

        // Reload the TMR value
        TMR4_Reload();
    }
    </code>
*/
uint8_t TMR4_ReadTimer(void);

/**
  @Summary
    Writes the TMR4 register.

  @Description
    This function writes the TMR4 register.
    This function must be called after the initialization of TMR4.

  @Preconditions
    Initialize  the TMR4 before calling this function.

  @Param
    timerVal - Value to write into TMR4 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TMR4 register
        if(ZERO == TMR4_ReadTimer())
        {
            // Do something else...

            // Write the TMR4 register
            TMR4_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TMR4_WriteTimer(uint8_t timerVal);

/**
  @Summary
    Load value to Period Register.

  @Description
    This function writes the value to PR4 register.
    This function must be called after the initialization of TMR4.

  @Preconditions
    Initialize  the TMR4 before calling this function.

  @Param
    periodVal - Value to load into TMR4 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD1 0x80
    #define PERIOD2 0x40
    #define ZERO    0x00

    while(1)
    {
        // Read the TMR4 register
        if(ZERO == TMR4_ReadTimer())
        {
            // Do something else...

            if(flag)
            {
                flag = 0;

                // Load Period 1 value
                TMR4_LoadPeriodRegister(PERIOD1);
            }
            else
            {
                 flag = 1;

                // Load Period 2 value
                TMR4_LoadPeriodRegister(PERIOD2);
            }
        }

        // Do something else...
    }
    </code>
*/
void TMR4_LoadPeriodRegister(uint8_t periodVal);

/**
  @Summary
    Boolean routine to poll or to check for the match flag on the fly.

  @Description
    This function is called to check for the timer match flag.
    This function is used in timer polling method.

  @Preconditions
    Initialize  the TMR4 module before calling this routine.

  @Param
    None

  @Returns
    true - timer match has occurred.
    false - timer match has not occurred.

  @Example
    <code>
    while(1)
    {
        // check the match flag
        if(TMR4_HasOverflowOccured())
        {
            // Do something else...

            // Reload the TMR4 value
            TMR4_Reload();
        }
    }
    </code>
*/
bool TMR4_HasOverflowOccured(void);

 #ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _TMR4_H
/**
 End of File
*/

