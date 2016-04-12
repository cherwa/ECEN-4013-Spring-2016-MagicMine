/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F1579
        Version           :  1.01
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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define IO_RA0_TRIS               TRISA0
#define IO_RA0_LAT                LATA0
#define IO_RA0_PORT               RA0
#define IO_RA0_WPU                WPUA0
#define IO_RA0_ANS                ANSA0
#define IO_RA0_SetHigh()    do { LATA0 = 1; } while(0)
#define IO_RA0_SetLow()   do { LATA0 = 0; } while(0)
#define IO_RA0_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define IO_RA0_GetValue()         RA0
#define IO_RA0_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define IO_RA0_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define IO_RA0_SetPullup()    do { WPUA0 = 1; } while(0)
#define IO_RA0_ResetPullup()   do { WPUA0 = 0; } while(0)
#define IO_RA0_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define IO_RA0_SetDigitalMode()   do { ANSA0 = 0; } while(0)


// get/set IO_RA1 aliases
#define IO_RA1_TRIS               TRISA1
#define IO_RA1_LAT                LATA1
#define IO_RA1_PORT               RA1
#define IO_RA1_WPU                WPUA1
#define IO_RA1_ANS                ANSA1
#define IO_RA1_SetHigh()    do { LATA1 = 1; } while(0)
#define IO_RA1_SetLow()   do { LATA1 = 0; } while(0)
#define IO_RA1_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define IO_RA1_GetValue()         RA1
#define IO_RA1_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define IO_RA1_SetPullup()    do { WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()   do { WPUA1 = 0; } while(0)
#define IO_RA1_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()   do { ANSA1 = 0; } while(0)


// get/set IO_RA2 aliases
#define IO_RA2_TRIS               TRISA2
#define IO_RA2_LAT                LATA2
#define IO_RA2_PORT               RA2
#define IO_RA2_WPU                WPUA2
#define IO_RA2_ANS                ANSA2
#define IO_RA2_SetHigh()    do { LATA2 = 1; } while(0)
#define IO_RA2_SetLow()   do { LATA2 = 0; } while(0)
#define IO_RA2_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define IO_RA2_GetValue()         RA2
#define IO_RA2_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define IO_RA2_SetPullup()    do { WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()   do { WPUA2 = 0; } while(0)
#define IO_RA2_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()   do { ANSA2 = 0; } while(0)


// get/set IO_RA3 aliases
#define IO_RA3_TRIS               TRISA3
#define IO_RA3_PORT               RA3
#define IO_RA3_WPU                WPUA3
#define IO_RA3_GetValue()         RA3
#define IO_RA3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define IO_RA3_SetPullup()    do { WPUA3 = 1; } while(0)
#define IO_RA3_ResetPullup()   do { WPUA3 = 0; } while(0)


// get/set IO_RA4 aliases
#define IO_RA4_TRIS               TRISA4
#define IO_RA4_LAT                LATA4
#define IO_RA4_PORT               RA4
#define IO_RA4_WPU                WPUA4
#define IO_RA4_ANS                ANSA4
#define IO_RA4_SetHigh()    do { LATA4 = 1; } while(0)
#define IO_RA4_SetLow()   do { LATA4 = 0; } while(0)
#define IO_RA4_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define IO_RA4_GetValue()         RA4
#define IO_RA4_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define IO_RA4_SetPullup()    do { WPUA4 = 1; } while(0)
#define IO_RA4_ResetPullup()   do { WPUA4 = 0; } while(0)
#define IO_RA4_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define IO_RA4_SetDigitalMode()   do { ANSA4 = 0; } while(0)


// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISB4
#define IO_RB4_LAT                LATB4
#define IO_RB4_PORT               RB4
#define IO_RB4_WPU                WPUB4
#define IO_RB4_ANS                ANSB4
#define IO_RB4_SetHigh()    do { LATB4 = 1; } while(0)
#define IO_RB4_SetLow()   do { LATB4 = 0; } while(0)
#define IO_RB4_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define IO_RB4_GetValue()         RB4
#define IO_RB4_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define IO_RB4_SetPullup()    do { WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()   do { WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()   do { ANSB4 = 0; } while(0)


// get/set IO_RB5 aliases
#define IO_RB5_TRIS               TRISB5
#define IO_RB5_LAT                LATB5
#define IO_RB5_PORT               RB5
#define IO_RB5_WPU                WPUB5
#define IO_RB5_ANS                ANSB5
#define IO_RB5_SetHigh()    do { LATB5 = 1; } while(0)
#define IO_RB5_SetLow()   do { LATB5 = 0; } while(0)
#define IO_RB5_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define IO_RB5_GetValue()         RB5
#define IO_RB5_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define IO_RB5_SetPullup()    do { WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()   do { WPUB5 = 0; } while(0)
#define IO_RB5_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()   do { ANSB5 = 0; } while(0)


// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISB6
#define IO_RB6_LAT                LATB6
#define IO_RB6_PORT               RB6
#define IO_RB6_WPU                WPUB6
#define IO_RB6_SetHigh()    do { LATB6 = 1; } while(0)
#define IO_RB6_SetLow()   do { LATB6 = 0; } while(0)
#define IO_RB6_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define IO_RB6_GetValue()         RB6
#define IO_RB6_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define IO_RB6_SetPullup()    do { WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()   do { WPUB6 = 0; } while(0)


// get/set IO_RC0 aliases
#define IO_RC0_TRIS               TRISC0
#define IO_RC0_LAT                LATC0
#define IO_RC0_PORT               RC0
#define IO_RC0_WPU                WPUC0
#define IO_RC0_ANS                ANSC0
#define IO_RC0_SetHigh()    do { LATC0 = 1; } while(0)
#define IO_RC0_SetLow()   do { LATC0 = 0; } while(0)
#define IO_RC0_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define IO_RC0_GetValue()         RC0
#define IO_RC0_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

#define IO_RC0_SetPullup()    do { WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()   do { WPUC0 = 0; } while(0)
#define IO_RC0_SetAnalogMode()   do { ANSC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()   do { ANSC0 = 0; } while(0)


// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISC1
#define IO_RC1_LAT                LATC1
#define IO_RC1_PORT               RC1
#define IO_RC1_WPU                WPUC1
#define IO_RC1_ANS                ANSC1
#define IO_RC1_SetHigh()    do { LATC1 = 1; } while(0)
#define IO_RC1_SetLow()   do { LATC1 = 0; } while(0)
#define IO_RC1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define IO_RC1_GetValue()         RC1
#define IO_RC1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define IO_RC1_SetPullup()    do { WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()   do { WPUC1 = 0; } while(0)
#define IO_RC1_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()   do { ANSC1 = 0; } while(0)


// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISC1
#define IO_RC1_LAT                LATC1
#define IO_RC1_PORT               RC1
#define IO_RC1_WPU                WPUC1
#define IO_RC1_ANS                ANSC1
#define IO_RC1_SetHigh()    do { LATC1 = 1; } while(0)
#define IO_RC1_SetLow()   do { LATC1 = 0; } while(0)
#define IO_RC1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define IO_RC1_GetValue()         RC1
#define IO_RC1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define IO_RC1_SetPullup()    do { WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()   do { WPUC1 = 0; } while(0)
#define IO_RC1_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()   do { ANSC1 = 0; } while(0)


// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISC1
#define IO_RC1_LAT                LATC1
#define IO_RC1_PORT               RC1
#define IO_RC1_WPU                WPUC1
#define IO_RC1_ANS                ANSC1
#define IO_RC1_SetHigh()    do { LATC1 = 1; } while(0)
#define IO_RC1_SetLow()   do { LATC1 = 0; } while(0)
#define IO_RC1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define IO_RC1_GetValue()         RC1
#define IO_RC1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define IO_RC1_SetPullup()    do { WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()   do { WPUC1 = 0; } while(0)
#define IO_RC1_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()   do { ANSC1 = 0; } while(0)



/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/