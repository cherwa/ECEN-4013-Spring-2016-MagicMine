/** 
 * @file LEDLogic.h
 * @author Matthew Atkins
 * @date Created on March 9, 2016, 10:02 PM
 */

#ifndef LEDLOGIC_H
#define	LEDLOGIC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "mcc_generated_files/mcc.h"
    
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
    
    /**
     * Enumerators specify predefined sequences for the LED ring to display.
     */
    typedef enum patterns {
        LED_ARMED,              /**< Indicates the mine has been armed.*/
        LED_DAMAGE,             /**< Indicates a damage spell has been cast.*/
        LED_HEAL,               /**< Indicates a healing spell has been cast.*/
        LED_STUN_CAST,          /**< Indicates that the mine has cast a stun spell <b>not that it has been stunned</b>.*/
        LED_STUN_SELF,          /**< Indicates that the mine itself is currently stunned.*/
        LED_SELF_TEST_PASSED,   /**< Indicates that all self tests have passed.*/
        LED_SELF_TEST_FAILED    /**< Indicates that one of the self tests have failed.*/
    } LED_Pattern;
    
    static inline void LEDOne();
    static inline void LEDZero();
    
    extern uint8_t byte_to_test;
    extern uint8_t bit_to_test;
    extern uint8_t to_return;
    
//    const uint8_t PIXEL_COUNT = 24; /**< A constant value for the number of pixels in the ring.*/
    
    /**
     * @name LED Pixel Buffers
     * These arrays of bytes are used to store the GRB color values for each
     * pixel that will be sent when the [draw()](@ref draw) function is called.
     */
    ///@{
    uint8_t greenPixels[PIXEL_COUNT];
    uint8_t redPixels[PIXEL_COUNT];
    uint8_t bluePixels[PIXEL_COUNT];
    ///@}
    
    uint8_t bit_test_result;
    unsigned char mask[] = {128, 64, 32, 16, 8, 4, 2, 1};
    
    
    /**
     * Plays the specified pattern on the LED ring.
     * @param pattern The pattern to play.
     * 
     * @warning Due to the specific timing requirements of the NeoPixels display
     *  driver this function <b>is not interruptible</b> and will disable
     *  peripheral interrupts to prevent timing skew.
     */
    void playPattern(LED_Pattern pattern);
    
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
    void draw(void);
    
    /**
     * Writes a '1' or a '0' to the LED_OUT pin to the controller on the ring.
     * If the value of val is greater than 0, the bit sent will a 1, otherwise
     * it sends a 0.
     * @param val Values > 0 indicate a '1' should be written and '0' otherwise.
     * 
     * @todo This function need to be tested!
     */
    static void send_bit(int8_t val);
    
    static inline int8_t isNthBitSet(const uint8_t c, const uint8_t n);
    
    int8_t bit_test(uint8_t* byte_to_test, uint8_t* bit_to_test);

#ifdef	__cplusplus
}
#endif

#endif	/* LEDLOGIC_H */

