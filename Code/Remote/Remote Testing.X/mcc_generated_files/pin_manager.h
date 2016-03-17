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

// get/set WHITE_SPELL aliases
#define WHITE_SPELL_TRIS               TRISA0
#define WHITE_SPELL_LAT                LATA0
#define WHITE_SPELL_PORT               RA0
#define WHITE_SPELL_WPU                WPUA0
#define WHITE_SPELL_ANS                ANSA0
#define WHITE_SPELL_SetHigh()    do { LATA0 = 1; } while(0)
#define WHITE_SPELL_SetLow()   do { LATA0 = 0; } while(0)
#define WHITE_SPELL_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define WHITE_SPELL_GetValue()         RA0
#define WHITE_SPELL_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define WHITE_SPELL_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define WHITE_SPELL_SetPullup()    do { WPUA0 = 1; } while(0)
#define WHITE_SPELL_ResetPullup()   do { WPUA0 = 0; } while(0)
#define WHITE_SPELL_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define WHITE_SPELL_SetDigitalMode()   do { ANSA0 = 0; } while(0)


// get/set BLUE_SPELL aliases
#define BLUE_SPELL_TRIS               TRISA1
#define BLUE_SPELL_LAT                LATA1
#define BLUE_SPELL_PORT               RA1
#define BLUE_SPELL_WPU                WPUA1
#define BLUE_SPELL_ANS                ANSA1
#define BLUE_SPELL_SetHigh()    do { LATA1 = 1; } while(0)
#define BLUE_SPELL_SetLow()   do { LATA1 = 0; } while(0)
#define BLUE_SPELL_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define BLUE_SPELL_GetValue()         RA1
#define BLUE_SPELL_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define BLUE_SPELL_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define BLUE_SPELL_SetPullup()    do { WPUA1 = 1; } while(0)
#define BLUE_SPELL_ResetPullup()   do { WPUA1 = 0; } while(0)
#define BLUE_SPELL_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define BLUE_SPELL_SetDigitalMode()   do { ANSA1 = 0; } while(0)


// get/set YELLOW_SPELL aliases
#define YELLOW_SPELL_TRIS               TRISA2
#define YELLOW_SPELL_LAT                LATA2
#define YELLOW_SPELL_PORT               RA2
#define YELLOW_SPELL_WPU                WPUA2
#define YELLOW_SPELL_ANS                ANSA2
#define YELLOW_SPELL_SetHigh()    do { LATA2 = 1; } while(0)
#define YELLOW_SPELL_SetLow()   do { LATA2 = 0; } while(0)
#define YELLOW_SPELL_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define YELLOW_SPELL_GetValue()         RA2
#define YELLOW_SPELL_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define YELLOW_SPELL_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define YELLOW_SPELL_SetPullup()    do { WPUA2 = 1; } while(0)
#define YELLOW_SPELL_ResetPullup()   do { WPUA2 = 0; } while(0)
#define YELLOW_SPELL_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define YELLOW_SPELL_SetDigitalMode()   do { ANSA2 = 0; } while(0)


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


// get/set IO_RA5 aliases
#define IO_RA5_TRIS               TRISA5
#define IO_RA5_LAT                LATA5
#define IO_RA5_PORT               RA5
#define IO_RA5_WPU                WPUA5
#define IO_RA5_SetHigh()    do { LATA5 = 1; } while(0)
#define IO_RA5_SetLow()   do { LATA5 = 0; } while(0)
#define IO_RA5_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define IO_RA5_GetValue()         RA5
#define IO_RA5_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define IO_RA5_SetPullup()    do { WPUA5 = 1; } while(0)
#define IO_RA5_ResetPullup()   do { WPUA5 = 0; } while(0)


// get/set YELLOW_LED aliases
#define YELLOW_LED_TRIS               TRISB4
#define YELLOW_LED_LAT                LATB4
#define YELLOW_LED_PORT               RB4
#define YELLOW_LED_WPU                WPUB4
#define YELLOW_LED_ANS                ANSB4
#define YELLOW_LED_SetHigh()    do { LATB4 = 1; } while(0)
#define YELLOW_LED_SetLow()   do { LATB4 = 0; } while(0)
#define YELLOW_LED_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define YELLOW_LED_GetValue()         RB4
#define YELLOW_LED_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define YELLOW_LED_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define YELLOW_LED_SetPullup()    do { WPUB4 = 1; } while(0)
#define YELLOW_LED_ResetPullup()   do { WPUB4 = 0; } while(0)
#define YELLOW_LED_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define YELLOW_LED_SetDigitalMode()   do { ANSB4 = 0; } while(0)


// get/set RED_LED aliases
#define RED_LED_TRIS               TRISB5
#define RED_LED_LAT                LATB5
#define RED_LED_PORT               RB5
#define RED_LED_WPU                WPUB5
#define RED_LED_ANS                ANSB5
#define RED_LED_SetHigh()    do { LATB5 = 1; } while(0)
#define RED_LED_SetLow()   do { LATB5 = 0; } while(0)
#define RED_LED_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define RED_LED_GetValue()         RB5
#define RED_LED_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define RED_LED_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define RED_LED_SetPullup()    do { WPUB5 = 1; } while(0)
#define RED_LED_ResetPullup()   do { WPUB5 = 0; } while(0)
#define RED_LED_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define RED_LED_SetDigitalMode()   do { ANSB5 = 0; } while(0)


// get/set ARM_BUTTON_LED aliases
#define ARM_BUTTON_LED_TRIS               TRISB6
#define ARM_BUTTON_LED_LAT                LATB6
#define ARM_BUTTON_LED_PORT               RB6
#define ARM_BUTTON_LED_WPU                WPUB6
#define ARM_BUTTON_LED_SetHigh()    do { LATB6 = 1; } while(0)
#define ARM_BUTTON_LED_SetLow()   do { LATB6 = 0; } while(0)
#define ARM_BUTTON_LED_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define ARM_BUTTON_LED_GetValue()         RB6
#define ARM_BUTTON_LED_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define ARM_BUTTON_LED_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define ARM_BUTTON_LED_SetPullup()    do { WPUB6 = 1; } while(0)
#define ARM_BUTTON_LED_ResetPullup()   do { WPUB6 = 0; } while(0)


// get/set ARM_BUTTON aliases
#define ARM_BUTTON_TRIS               TRISB7
#define ARM_BUTTON_LAT                LATB7
#define ARM_BUTTON_PORT               RB7
#define ARM_BUTTON_WPU                WPUB7
#define ARM_BUTTON_SetHigh()    do { LATB7 = 1; } while(0)
#define ARM_BUTTON_SetLow()   do { LATB7 = 0; } while(0)
#define ARM_BUTTON_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define ARM_BUTTON_GetValue()         RB7
#define ARM_BUTTON_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define ARM_BUTTON_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define ARM_BUTTON_SetPullup()    do { WPUB7 = 1; } while(0)
#define ARM_BUTTON_ResetPullup()   do { WPUB7 = 0; } while(0)


// get/set RED_SPELL aliases
#define RED_SPELL_TRIS               TRISC0
#define RED_SPELL_LAT                LATC0
#define RED_SPELL_PORT               RC0
#define RED_SPELL_WPU                WPUC0
#define RED_SPELL_ANS                ANSC0
#define RED_SPELL_SetHigh()    do { LATC0 = 1; } while(0)
#define RED_SPELL_SetLow()   do { LATC0 = 0; } while(0)
#define RED_SPELL_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define RED_SPELL_GetValue()         RC0
#define RED_SPELL_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define RED_SPELL_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

#define RED_SPELL_SetPullup()    do { WPUC0 = 1; } while(0)
#define RED_SPELL_ResetPullup()   do { WPUC0 = 0; } while(0)
#define RED_SPELL_SetAnalogMode()   do { ANSC0 = 1; } while(0)
#define RED_SPELL_SetDigitalMode()   do { ANSC0 = 0; } while(0)


// get/set WHITE_LED aliases
#define WHITE_LED_TRIS               TRISC1
#define WHITE_LED_LAT                LATC1
#define WHITE_LED_PORT               RC1
#define WHITE_LED_WPU                WPUC1
#define WHITE_LED_ANS                ANSC1
#define WHITE_LED_SetHigh()    do { LATC1 = 1; } while(0)
#define WHITE_LED_SetLow()   do { LATC1 = 0; } while(0)
#define WHITE_LED_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define WHITE_LED_GetValue()         RC1
#define WHITE_LED_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define WHITE_LED_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define WHITE_LED_SetPullup()    do { WPUC1 = 1; } while(0)
#define WHITE_LED_ResetPullup()   do { WPUC1 = 0; } while(0)
#define WHITE_LED_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define WHITE_LED_SetDigitalMode()   do { ANSC1 = 0; } while(0)


// get/set BLUE_LED aliases
#define BLUE_LED_TRIS               TRISC2
#define BLUE_LED_LAT                LATC2
#define BLUE_LED_PORT               RC2
#define BLUE_LED_WPU                WPUC2
#define BLUE_LED_ANS                ANSC2
#define BLUE_LED_SetHigh()    do { LATC2 = 1; } while(0)
#define BLUE_LED_SetLow()   do { LATC2 = 0; } while(0)
#define BLUE_LED_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define BLUE_LED_GetValue()         RC2
#define BLUE_LED_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define BLUE_LED_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define BLUE_LED_SetPullup()    do { WPUC2 = 1; } while(0)
#define BLUE_LED_ResetPullup()   do { WPUC2 = 0; } while(0)
#define BLUE_LED_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define BLUE_LED_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set BLUE_LED aliases
#define BLUE_LED_TRIS               TRISC2
#define BLUE_LED_LAT                LATC2
#define BLUE_LED_PORT               RC2
#define BLUE_LED_WPU                WPUC2
#define BLUE_LED_ANS                ANSC2
#define BLUE_LED_SetHigh()    do { LATC2 = 1; } while(0)
#define BLUE_LED_SetLow()   do { LATC2 = 0; } while(0)
#define BLUE_LED_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define BLUE_LED_GetValue()         RC2
#define BLUE_LED_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define BLUE_LED_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define BLUE_LED_SetPullup()    do { WPUC2 = 1; } while(0)
#define BLUE_LED_ResetPullup()   do { WPUC2 = 0; } while(0)
#define BLUE_LED_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define BLUE_LED_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set BLUE_LED aliases
#define BLUE_LED_TRIS               TRISC2
#define BLUE_LED_LAT                LATC2
#define BLUE_LED_PORT               RC2
#define BLUE_LED_WPU                WPUC2
#define BLUE_LED_ANS                ANSC2
#define BLUE_LED_SetHigh()    do { LATC2 = 1; } while(0)
#define BLUE_LED_SetLow()   do { LATC2 = 0; } while(0)
#define BLUE_LED_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define BLUE_LED_GetValue()         RC2
#define BLUE_LED_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define BLUE_LED_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define BLUE_LED_SetPullup()    do { WPUC2 = 1; } while(0)
#define BLUE_LED_ResetPullup()   do { WPUC2 = 0; } while(0)
#define BLUE_LED_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define BLUE_LED_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set IO_RC6 aliases
#define IO_RC6_TRIS               TRISC6
#define IO_RC6_LAT                LATC6
#define IO_RC6_PORT               RC6
#define IO_RC6_WPU                WPUC6
#define IO_RC6_ANS                ANSC6
#define IO_RC6_SetHigh()    do { LATC6 = 1; } while(0)
#define IO_RC6_SetLow()   do { LATC6 = 0; } while(0)
#define IO_RC6_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define IO_RC6_GetValue()         RC6
#define IO_RC6_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define IO_RC6_SetPullup()    do { WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()   do { WPUC6 = 0; } while(0)
#define IO_RC6_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()   do { ANSC6 = 0; } while(0)


// get/set IO_RC7 aliases
#define IO_RC7_TRIS               TRISC7
#define IO_RC7_LAT                LATC7
#define IO_RC7_PORT               RC7
#define IO_RC7_WPU                WPUC7
#define IO_RC7_ANS                ANSC7
#define IO_RC7_SetHigh()    do { LATC7 = 1; } while(0)
#define IO_RC7_SetLow()   do { LATC7 = 0; } while(0)
#define IO_RC7_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define IO_RC7_GetValue()         RC7
#define IO_RC7_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

#define IO_RC7_SetPullup()    do { WPUC7 = 1; } while(0)
#define IO_RC7_ResetPullup()   do { WPUC7 = 0; } while(0)
#define IO_RC7_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode()   do { ANSC7 = 0; } while(0)



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