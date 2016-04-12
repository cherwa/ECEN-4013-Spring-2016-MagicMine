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
        Device            :  PIC18F26K22
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

// get/set IR_TX aliases
#define IR_TX_TRIS               TRISB0
#define IR_TX_LAT                LATB0
#define IR_TX_PORT               RB0
#define IR_TX_WPU                WPUB0
#define IR_TX_ANS                ANSB0
#define IR_TX_SetHigh()    do { LATB0 = 1; } while(0)
#define IR_TX_SetLow()   do { LATB0 = 0; } while(0)
#define IR_TX_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define IR_TX_GetValue()         RB0
#define IR_TX_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define IR_TX_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define IR_TX_SetPullup()    do { WPUB0 = 1; } while(0)
#define IR_TX_ResetPullup()   do { WPUB0 = 0; } while(0)
#define IR_TX_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define IR_TX_SetDigitalMode()   do { ANSB0 = 0; } while(0)


// get/set BT4M_CMD aliases
#define BT4M_CMD_TRIS               TRISB2
#define BT4M_CMD_LAT                LATB2
#define BT4M_CMD_PORT               RB2
#define BT4M_CMD_WPU                WPUB2
#define BT4M_CMD_ANS                ANSB2
#define BT4M_CMD_SetHigh()    do { LATB2 = 1; } while(0)
#define BT4M_CMD_SetLow()   do { LATB2 = 0; } while(0)
#define BT4M_CMD_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define BT4M_CMD_GetValue()         RB2
#define BT4M_CMD_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define BT4M_CMD_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define BT4M_CMD_SetPullup()    do { WPUB2 = 1; } while(0)
#define BT4M_CMD_ResetPullup()   do { WPUB2 = 0; } while(0)
#define BT4M_CMD_SetAnalogMode()   do { ANSB2 = 1; } while(0)
#define BT4M_CMD_SetDigitalMode()   do { ANSB2 = 0; } while(0)


// get/set LED_OUT aliases
#define LED_OUT_TRIS               TRISB3
#define LED_OUT_LAT                LATB3
#define LED_OUT_PORT               RB3
#define LED_OUT_WPU                WPUB3
#define LED_OUT_ANS                ANSB3
#define LED_OUT_SetHigh()    do { LATB3 = 1; } while(0)
#define LED_OUT_SetLow()   do { LATB3 = 0; } while(0)
#define LED_OUT_Toggle()   do { LATB3 = ~LATB3; } while(0)
#define LED_OUT_GetValue()         RB3
#define LED_OUT_SetDigitalInput()    do { TRISB3 = 1; } while(0)
#define LED_OUT_SetDigitalOutput()   do { TRISB3 = 0; } while(0)

#define LED_OUT_SetPullup()    do { WPUB3 = 1; } while(0)
#define LED_OUT_ResetPullup()   do { WPUB3 = 0; } while(0)
#define LED_OUT_SetAnalogMode()   do { ANSB3 = 1; } while(0)
#define LED_OUT_SetDigitalMode()   do { ANSB3 = 0; } while(0)


// get/set PIR_INT aliases
#define PIR_INT_TRIS               TRISB4
#define PIR_INT_LAT                LATB4
#define PIR_INT_PORT               RB4
#define PIR_INT_WPU                WPUB4
#define PIR_INT_ANS                ANSB4
#define PIR_INT_SetHigh()    do { LATB4 = 1; } while(0)
#define PIR_INT_SetLow()   do { LATB4 = 0; } while(0)
#define PIR_INT_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define PIR_INT_GetValue()         RB4
#define PIR_INT_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define PIR_INT_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define PIR_INT_SetPullup()    do { WPUB4 = 1; } while(0)
#define PIR_INT_ResetPullup()   do { WPUB4 = 0; } while(0)
#define PIR_INT_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define PIR_INT_SetDigitalMode()   do { ANSB4 = 0; } while(0)


// get/set IR_RX aliases
#define IR_RX_TRIS               TRISB5
#define IR_RX_LAT                LATB5
#define IR_RX_PORT               RB5
#define IR_RX_WPU                WPUB5
#define IR_RX_ANS                ANSB5
#define IR_RX_SetHigh()    do { LATB5 = 1; } while(0)
#define IR_RX_SetLow()   do { LATB5 = 0; } while(0)
#define IR_RX_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define IR_RX_GetValue()         RB5
#define IR_RX_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define IR_RX_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define IR_RX_SetPullup()    do { WPUB5 = 1; } while(0)
#define IR_RX_ResetPullup()   do { WPUB5 = 0; } while(0)
#define IR_RX_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define IR_RX_SetDigitalMode()   do { ANSB5 = 0; } while(0)


// get/set IR_RX aliases
#define IR_RX_TRIS               TRISB5
#define IR_RX_LAT                LATB5
#define IR_RX_PORT               RB5
#define IR_RX_WPU                WPUB5
#define IR_RX_ANS                ANSB5
#define IR_RX_SetHigh()    do { LATB5 = 1; } while(0)
#define IR_RX_SetLow()   do { LATB5 = 0; } while(0)
#define IR_RX_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define IR_RX_GetValue()         RB5
#define IR_RX_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define IR_RX_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define IR_RX_SetPullup()    do { WPUB5 = 1; } while(0)
#define IR_RX_ResetPullup()   do { WPUB5 = 0; } while(0)
#define IR_RX_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define IR_RX_SetDigitalMode()   do { ANSB5 = 0; } while(0)


// get/set IR_RX aliases
#define IR_RX_TRIS               TRISB5
#define IR_RX_LAT                LATB5
#define IR_RX_PORT               RB5
#define IR_RX_WPU                WPUB5
#define IR_RX_ANS                ANSB5
#define IR_RX_SetHigh()    do { LATB5 = 1; } while(0)
#define IR_RX_SetLow()   do { LATB5 = 0; } while(0)
#define IR_RX_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define IR_RX_GetValue()         RB5
#define IR_RX_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define IR_RX_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define IR_RX_SetPullup()    do { WPUB5 = 1; } while(0)
#define IR_RX_ResetPullup()   do { WPUB5 = 0; } while(0)
#define IR_RX_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define IR_RX_SetDigitalMode()   do { ANSB5 = 0; } while(0)


// get/set WTV_CLOCK aliases
#define WTV_CLOCK_TRIS               TRISC0
#define WTV_CLOCK_LAT                LATC0
#define WTV_CLOCK_PORT               RC0
#define WTV_CLOCK_SetHigh()    do { LATC0 = 1; } while(0)
#define WTV_CLOCK_SetLow()   do { LATC0 = 0; } while(0)
#define WTV_CLOCK_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define WTV_CLOCK_GetValue()         RC0
#define WTV_CLOCK_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define WTV_CLOCK_SetDigitalOutput()   do { TRISC0 = 0; } while(0)



// get/set WTV_DATA aliases
#define WTV_DATA_TRIS               TRISC1
#define WTV_DATA_LAT                LATC1
#define WTV_DATA_PORT               RC1
#define WTV_DATA_SetHigh()    do { LATC1 = 1; } while(0)
#define WTV_DATA_SetLow()   do { LATC1 = 0; } while(0)
#define WTV_DATA_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define WTV_DATA_GetValue()         RC1
#define WTV_DATA_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define WTV_DATA_SetDigitalOutput()   do { TRISC1 = 0; } while(0)



// get/set PAM_SD aliases
#define PAM_SD_TRIS               TRISC2
#define PAM_SD_LAT                LATC2
#define PAM_SD_PORT               RC2
#define PAM_SD_ANS                ANSC2
#define PAM_SD_SetHigh()    do { LATC2 = 1; } while(0)
#define PAM_SD_SetLow()   do { LATC2 = 0; } while(0)
#define PAM_SD_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define PAM_SD_GetValue()         RC2
#define PAM_SD_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define PAM_SD_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define PAM_SD_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define PAM_SD_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set WTV_RESET aliases
#define WTV_RESET_TRIS               TRISC5
#define WTV_RESET_LAT                LATC5
#define WTV_RESET_PORT               RC5
#define WTV_RESET_ANS                ANSC5
#define WTV_RESET_SetHigh()    do { LATC5 = 1; } while(0)
#define WTV_RESET_SetLow()   do { LATC5 = 0; } while(0)
#define WTV_RESET_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define WTV_RESET_GetValue()         RC5
#define WTV_RESET_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define WTV_RESET_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define WTV_RESET_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define WTV_RESET_SetDigitalMode()   do { ANSC5 = 0; } while(0)


// get/set WTV_RESET aliases
#define WTV_RESET_TRIS               TRISC5
#define WTV_RESET_LAT                LATC5
#define WTV_RESET_PORT               RC5
#define WTV_RESET_ANS                ANSC5
#define WTV_RESET_SetHigh()    do { LATC5 = 1; } while(0)
#define WTV_RESET_SetLow()   do { LATC5 = 0; } while(0)
#define WTV_RESET_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define WTV_RESET_GetValue()         RC5
#define WTV_RESET_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define WTV_RESET_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define WTV_RESET_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define WTV_RESET_SetDigitalMode()   do { ANSC5 = 0; } while(0)


// get/set WTV_RESET aliases
#define WTV_RESET_TRIS               TRISC5
#define WTV_RESET_LAT                LATC5
#define WTV_RESET_PORT               RC5
#define WTV_RESET_ANS                ANSC5
#define WTV_RESET_SetHigh()    do { LATC5 = 1; } while(0)
#define WTV_RESET_SetLow()   do { LATC5 = 0; } while(0)
#define WTV_RESET_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define WTV_RESET_GetValue()         RC5
#define WTV_RESET_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define WTV_RESET_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define WTV_RESET_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define WTV_RESET_SetDigitalMode()   do { ANSC5 = 0; } while(0)



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