/* 
 * File:   LEDs.h
 * Author: Matthew Atkins
 *
 * Created on April 7, 2016, 3:16 AM
 */

#ifndef LEDS_H
#define	LEDS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "util_functions.h"
#include <string.h>
#include <stdlib.h>
    
    bool last_pattern_was_heal = false;
    
/**
 * Returns a value greater than 0 if the bit in 'var' is a '1' or 0 otherwise.
 * This works by left shifting a single 1 by 'pos' and bitwise anding the result.
 * For example:
 * @code{.c}
 * uint8_t var = 0b00001000;
 * uint8_t pos = 3;
 * 
 * result = bit_test(var, pos)
 * @endcode
 * 
 * will set result to 0b00001000 since bit_test will left shift '1' over by 3
 * which results in (0b00001000 & 0b00001000) which is equal to 0b00001000.
 */
//#define bit_test(var, pos) ((var) & (1 << pos))
#define PIXEL_COUNT 24
#define LED_PIN LATBbits.LATB3
   
    /**
     * Enumerators specify predefined sequences for the LED ring to display.
     */
    typedef enum patterns {
        LED_ARMED,              /**< Indicates the mine has been armed.*/
        LED_DAMAGE,             /**< Indicates a Damage spell has been cast.*/
        LED_ELEMENT_DAMAGE,     /**< Indicates a Element Damage spell has been cast.*/
        LED_HEAL,               /**< Indicates a Healing spell has been cast.*/
        LED_STUN_CAST,          /**< Indicates that the mine has cast a Stun spell <b>not that it has been stunned</b>.*/
        LED_STUN_SELF,          /**< Indicates that the mine itself is currently Stunned.*/
        LED_SELF_TEST_PASSED,   /**< Indicates that all self tests have passed.*/
        LED_SELF_TEST_FAILED,   /**< Indicates that one of the self tests have failed.*/
        LED_CLEAR,
        LED_MPU_INIT_SUCCESS,
        LED_BT2_INIT_SUCCESS,
        LED_BT4_INIT_SUCCESS
    } LED_Pattern;
    
//    const uint8_t PIXEL_COUNT = 24; /**< A constant value for the number of pixels in the ring.*/
    
    /**
     * @name LED Pixel Buffers
     * These arrays of bytes are used to store the GRB color values for each
     * pixel that will be sent when the [draw()](@ref draw) function is called.
     */
    ///@{
//    extern near uint8_t greenPixels[PIXEL_COUNT];
//    extern near uint8_t redPixels[PIXEL_COUNT];
//    extern near uint8_t bluePixels[PIXEL_COUNT];
    ///@}
    
    void LED_init();
    
    /**
     * Plays the specified pattern on the LED ring.
     * @param pattern The pattern to play.
     * 
     * @warning Due to the specific timing requirements of the NeoPixels display
     *  driver this function <b>is not interruptible</b> and will disable
     *  peripheral interrupts to prevent timing skew.
     */
    void LED_play_pattern(LED_Pattern pattern);
    
    /**
     * Fills the pixels buffers with color passed in grb. The order of the values
     * is the same as the NeoPixels themselves: GRB.
     * @param grb The GRB color to fill with.
     * 
     * @code{.c}
     * uint8_t color[3];
     * color[0] = 128; // Value for green
     * color[1] = 128; // Value for red
     * color[2] = 128; // Value for blue
     * 
     * fill_color(color);
     * @endcode
     * The above will turn on the ring to 50% white.
     */
     void fill_color(uint8_t* grb);
    
    /**
     * Iterates over the color values stored in the [pixel buffers](@ref LED Pixel Buffers)
     * and calls [send_bit](@ref send_bit) to write the corresponding bit of the
     * 24bit sequence for each pixel.
     * 
     * @warning Due to the specific timing requirements of the NeoPixels display
     *  driver this function <b>is not interruptible</b> and will disable
     *  peripheral interrupts to prevent timing skew.
     * 
     * @todo This function needs to be tested!
     */
    void draw();
    
    void chase(uint8_t* grb);
    
    void fading_chase(uint8_t* grb);
    
    void chase_with_background(uint8_t* grb, uint8_t* grb_back);
    
    void random();
    
    void pulse_2();
    
#ifdef	__cplusplus
}
#endif

#endif	/* LEDS_H */

