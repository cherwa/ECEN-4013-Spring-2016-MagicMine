/**
  TMR3 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr3.h

  @Summary
    This is the generated header file for the TMR3 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for TMR3.
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

#ifndef _TMR3_H
#define _TMR3_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

#define TMR3_INTERRUPT_TICKER_FACTOR    30

/**
  Section: TMR3 APIs
*/

/**
  @Summary
    Initializes the TMR3

  @Description
    This routine initializes the TMR3.
    This routine must be called before any other TMR3 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    TMR3_Initialize();
    </code>
*/
void TMR3_Initialize(void);

/**
  @Summary
    Start TMR3

  @Description
    This routine is used to  Start TMR3.

  @Preconditions
    The TMR3_Initialize() routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR3 module

    // Start TMR3
    TMR3_StartTimer();

    while(1)
    {
    }
    </code>
 */
void TMR3_StartTimer(void);

/**
  @Summary
    Stop TMR3

  @Description
    This routine is used to  Stop TMR3.

  @Preconditions
    The TMR3_Initialize() routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    None

  @Example
    </code>
    TMR3_Initialize();

    TMR3_StartTimer();
    if(TMR3_HasOverflowOccured())
    {
        TMR3_StopTimer();
    }
    <code>
 */
void TMR3_StopTimer(void);

/**
  @Summary
    Read TMR3 register.

  @Description
    This routine is used to  Read TMR3 register.

  @Preconditions
    The TMR3_Initialize() routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    TMR3 value at the time of the function call read as a 16-bit value

  @Example
    <code>
    uint16_t timerVal=0;

    TMR3_Initialize();

    TMR3_StartTimer();

    // some delay or code

    TMR3_StopTimer();

    timerVal=TMR3_ReadTimer();
    </code>
 */
uint16_t TMR3_ReadTimer(void);

/**
  @Summary
    Write TMR3 register.

  @Description
    This routine is used to Write TMR3 register.

  @Preconditions
    The TMR3_Initialize() routine should be called
    prior to use this routine.

  @Param
    timerVal : Timer value to be loaded

  @Returns
    None

  @Example
    <code>
    TMR3_Initialize();
    TMR3_WriteTimer(0x055);
    TMR3_StartTimer();
    </code>
 */
void TMR3_WriteTimer(uint16_t timerVal);

/**
  @Summary
    Reload TMR3 register.

  @Description
    This routine is used to reload TMR3 register.

  @Preconditions
    The TMR3_Initialize() routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    TMR3_Initialize();
    TMR3_StartTimer();

    if(TMR3_HasOverflowOccured())
    {
        TMR3_StopTimer();
    }

    TMR3_Reload();}
    </code>
*/
void TMR3_Reload(void);

/**
  @Summary
    Starts the single pulse acquisition in TMR3 gate operation.

  @Description
    This function starts the single pulse acquisition in TMR3 gate operation.
    This function must be used when the TMR3 gate is enabled.

  @Preconditions
    Initialize  the TMR3 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    //enable TMR3 singlepulse mode
    TMR3_StartSinglePulseAcquistion();

    //check TMR3 gate status
    if(TMR3_CheckGateValueStatus()== 0)
    {
        xVal = TMR3_ReadTimer();
    }

    // wait untill gate interrupt occured
    while(TMR3GIF == 0)
    {
    }

    yVal = TMR3_ReadTimer();
    </code>
*/
void TMR3_StartSinglePulseAcquisition(void);

/**
  @Summary
    Check the current state of Timer1 gate.

  @Description
    This function reads the TMR3 gate value and return it.
    This function must be used when the TMR3 gate is enabled.

  @Preconditions
    Initialize  the TMR3 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    //enable TMR3 singlepulse mode
    TMR3_StartSinglePulseAcquistion();

    //check TMR3 gate status
    if(TMR3_CheckGateValueStatus()== 0)
    {
        xVal = TMR3_ReadTimer();
    }

    //wait untill gate interrupt occured
    while(TMR3IF == 0)
    {
    }

    yVal = TMR3_ReadTimer();
    </code>
*/
uint8_t TMR3_CheckGateValueStatus(void);

/**
  @Summary
    Implements ISR

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Returns
    None

  @Param
    None
*/
void TMR3_ISR(void);

/**
  @Summary
    CallBack function.

  @Description
    This routine is called by the Interrupt Manager.

  @Preconditions
    The TMR3_Initialize() routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    None
*/
void TMR3_CallBack(void);

/**
  @Summary
    Set Timer Interrupt Handler

  @Description
    This sets the function to be called during the ISR

  @Preconditions
    Initialize  the TMR3 module with interrupt before calling this.

  @Param
    Address of function to be set

  @Returns
    None
*/
 void TMR3_SetInterruptHandler(void *InterruptHandler);

/**
  @Summary
    Timer Interrupt Handler

  @Description
    This is a function pointer to the function that will be called during the ISR

  @Preconditions
    Initialize  the TMR3 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void (*TMR3_InterruptHandler)(void);

/**
  @Summary
    Default Timer Interrupt Handler

  @Description
    This is the default Interrupt Handler function

  @Preconditions
    Initialize  the TMR3 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void TMR3_DefaultInterruptHandler(void);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _TMR3_H
/**
 End of File
*/