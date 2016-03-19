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
#include "NeoCol.h"
#include "LEDLogic.h"
    
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
#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

