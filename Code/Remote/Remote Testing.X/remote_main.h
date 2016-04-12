/** 
 * @file remote_main.h
 * @author Matthew Atkins
 *
 * @date March 14, 2016, 6:46 PM
 */

#ifndef REMOTE_MAIN_H
#define	REMOTE_MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
#define YELLOW_LED LATAbits.LATA0
#define WHITE_LED LATAbits.LATA1
#define ARM_LED LATAbits.LATA2
#define BLUE_LED LATCbits.LATC0
#define RED_LED LATCbits.LATC1
#define YELLOW_BTN PORTBbits.PORTB4
#define WHITE_BTN PORTBbits.PORTB5
#define ARM_BTN PORTBbits.PORTB6
#define BLUE_BTN PORTAbits.PORTA4
#define RED_BTN PORTAbits.PORTA3

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "remote_common.h"
#include "bt_remote_to_mine.h"
#include "buttons.h"
    
    /**
     * Values are used to indicate the current arming mode
     * of the device or if it is currently disarmed.
     */
    typedef enum {
        STATE_DISARMED,       /**< The mine is disarmed and may be armed.*/
        STATE_MANUAL_MODE,    /**< The mine is armed in manual mode.*/
        STATE_AUTOMATIC_MODE  /**< The mine is armed in auto mode.*/
    } arm_mode_t;
    
    /** 
     * The currently selected spell as selected by the user
     * using the spell selections button. <b>Once this is set, it should
     * not be changed until the game is over or the mine is detonated!</b>
     */
    extern volatile spell_t selectedSpell;
    
    // Self test pass/fail indicators.
    bool spellButtonsPassed;    /**< true if [testSpellButtons](@ref testSpellButtons) is successful*/
    bool indicatorLEDsPassed;   /**< true if [testIndicatorLEDs](@ref testIndicatorLEDs) is successful*/
    bool spellButtonsPassed = false;
    bool indicatorLEDsPassed = false;
    
    // Status/Enable parameters
    extern volatile arm_mode_t armedMode;   /**< inidicates the current arming mode for the mine.*/
    extern volatile bool armButtonEnabled;     /**< set to true to enable the arm button to send a detonate command to the mine.*/
    extern volatile bool connectedToMine;      /**< set to true if the remote has established a bluetooth connection to the mine. */
    extern volatile bool arm_held_for_3_seconds;
    
    void main();
    
    void connect_to_peripherals();
    
#ifdef	__cplusplus
}
#endif

#endif	/* REMOTE_MAIN_H */

