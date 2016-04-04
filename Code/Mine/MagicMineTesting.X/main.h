/** 
 * @file main.h
 * @author Matthew Atkins
 * @date Created on March 18, 2016, 10:45 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdio.h>
#include "bt_to_PIU.h"
#include "bt_to_remote.h"
#include "bt_common.h"
#include "util_functions.h"
#include "LEDLogic.h"
#include "ir_common.h"
#include "audio.h"
    
    /**
     * Values used to indicate the current state of the mine. These are used
     * throughout to control the devices behavior at specific times. For example
     * if the mine receives IR date while stunned it will simply ignore the
     * packet.
     */
    typedef enum device_state {
        DEV_STATE_DISARMED,     /**< The device is disarmed and may now be armed.*/
        DEV_STATE_ARMED_AUTO,   /**< The device has been armed in auto mode.*/
        DEV_STATE_ARMED_MANUAL, /**< The device has been aremed in manual mode.*/
        DEV_STATE_STUNNED       /**< The device is currently stunned and will igore further input.*/
    } device_state_t;
    
    /** 
     * @name Peripheral Status Flags
     *  Indicates if a peripheral passed its self test and is ready for use.
     */
    ///@{
    bool bluetooth_to_PIU_online = false;
    bool bluetooth_to_remote_online = false;
    bool audio_controller_online = false;
    bool self_test_passed = false;
    ///@}
    
    device_state_t device_state = DEV_STATE_DISARMED;
    
    // Static functions
    
    /**
     * Initializes the program logic to it's starting conditions. This function
     * is called after enabling interrupts from [main](@ref main).
     */
    static void init_logic(void);
    
    /**
     * Attempts to connect to and configure peripheral devices, such as the
     * Bluetooth modules and audio controller. If all tests are
     * passed it will flash the LED ring green 3 times to indicate success, 
     * or red if there a problem was detected. 
     * 
     * @warning This is obviously not comprehensive, some devices, such as the PIRs
     *  are too basic to test meaningfully. <br>
     *  
     * @warning If any of the self tests fail, the device will loop the
     *  [self test failed pattern](@ref SELF_TEST_FAILED) until reset.
     */
    static void connect_to_peripherals(void);
    
   /**
    * @name Self Test Functions
    * These functions will attempt to connect to and configure their
    * corresponding device.
    */
    ///@{
    static void init_Bluetooth_to_PIU(void);
    
    static void init_Bluetooth_to_remote(void);
    
    static void init_audio_controller(void);
    
    static void init_LEDs(void);
    ///@}
    
    /**
     * @name Control Logic Functions
     * These functions make up the bulk of managing the mines behavior in
     * different operating modes.
     */
    ///@{
    /**
     * Begins the stun subroutine on the mine. In this state, the mine will ignore
     * incoming IR data and any request from the remote to detonate it. It will
     * also ignore any date from the accelerometer that indicates tampering
     * if armed in autonomous mode. It will also indicate that it has been stunned
     * using both visual and aural indicators.
     */
    void stunned(void);
    /**
     * Begins the detonate subroutine. The mine will emit the appropriate IR
     * packet for it's current payload, indicate that a damage spell has been
     * cast using visual and aural indicators.
     */
    void detonate(void);
    ///@}
#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

