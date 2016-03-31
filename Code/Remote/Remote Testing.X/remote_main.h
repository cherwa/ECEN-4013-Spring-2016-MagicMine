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

#include <stdio.h>
#include "remote_common.h"
#include "bluetooth_commands.h"
#include "buttons.h"
    
    /**
     * Values are used to indicate the current arming mode
     * of the device or if it is currently disarmed.
     */
    typedef enum {
        DISARMED,       /**< The mine is disarmed and may be armed.*/
        MANUAL_MODE,    /**< The mine is armed in manual mode.*/
        AUTOMATIC_MODE  /**< The mine is armed in auto mode.*/
    } arm_mode_t;
    
    /** 
     * The currently selected spell as selected by the user
     * using the spell selections button. <b>Once this is set, it should
     * not be changed until the game is over or the mine is detonated!</b>
     */
    extern volatile spell_t selectedSpell = NO_SELECTION;
    
    // Self test pass/fail indicators.
    extern bool spellButtonsPassed = false;    /**< true if [testSpellButtons](@ref testSpellButtons) is successful*/
    extern bool indicatorLEDsPassed = false;   /**< true if [testIndicatorLEDs](@ref testIndicatorLEDs) is successful*/
    
    // Status/Enable parameters
    extern volatile arm_mode_t armedMode = DISARMED;   /**< inidicates the current arming mode for the mine.*/
    extern volatile bool armButtonEnabled = false;     /**< set to true to enable the arm button to send a detonate command to the mine.*/
    extern volatile bool connectedToMine = false;      /**< set to true if the remote has established a bluetooth connection to the mine. */
    
    void main();
    
    /**
     * Set the currently selected spell type to the given [spell type](@ref spell_t)
     *  and attempts to send this to the mine.
     * @param spellType The spell type to set the mines payload to.
     */
    void setSpellType(spell_t spellType);
    
    bool bluetoothEnterCommandMode(); /**< Attempts to set the Bluetooth module to command mode.*/
    
#ifdef	__cplusplus
}
#endif

#endif	/* REMOTE_MAIN_H */

