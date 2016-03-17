/* 
 * File:   remote_main.h
 * Author: matthew
 *
 * Created on March 14, 2016, 6:46 PM
 */

#ifndef REMOTE_MAIN_H
#define	REMOTE_MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "remote_common.h"
#include "bluetooth_commands.h"
    
    typedef enum {
        DISARMED,
        MANUAL_MODE,
        AUTOMATIC_MODE
    } arm_mode_t;
    
    static volatile spell_t selectedSpell = NO_SELECTION;
    
    void main(void);
    void setSpellType(const spell_t spellType);
    
    // Self test functions.
    static bool spellButtonsPassed = false;
    static bool indicatorLEDsPassed = false;
    
    // Status/Enable parameters
    static volatile arm_mode_t armedMode = DISARMED;
    static volatile bool armButtonEnabled = false;
    
    /**
     * Tests the spell buttons by flashing them 3 times
     */
    static void testSpellButtons(void);
    
    /**
     * Tests the indicator LEDs by flashing them 3 times.
     */
    static void testIndicatorLEDs(void);
    
    static bool bluetoothEnterCommandMode(void);
    void sendBluetoothCommand(bluetooth_cmnd_t cmnd);
    
#ifdef	__cplusplus
}
#endif

#endif	/* REMOTE_MAIN_H */

