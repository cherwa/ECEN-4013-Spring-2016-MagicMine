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

    /**
     * Enumerators specify predefined sequences for the LED ring to display.
     */
    typedef enum patterns {
        DAMAGE,             /**< Indicates a damage spell has been cast.*/
        HEAL,               /**< Indicates a healing spell has been cast.*/
        STUN_CAST,          /**< Indicates that the mine has cast a stun spell <b>not that it has been stunned</b>.*/
        STUN_SELF,          /**< Indicates that the mine itself is currently stunned.*/
        SELF_TEST_PASSED,   /**< Indicates that all self tests have passed.*/
        SELF_TEST_FAILED    /**< Indicates that one of the self tests have failed.*/
    } LED_Pattern;
    
    /**
     * Plays the specified pattern on the LED ring.
     * @param pattern The pattern to play.
     * 
     * @warning Due to the specific timing requirements of the NeoPixels display
     *  driver this function <b>is not interruptible</b> and will disable
     *  peripheral interrupts to prevent timing skew.
     */
    void playPattern(LED_Pattern pattern);
    
    int counter = 0;

#ifdef	__cplusplus
}
#endif

#endif	/* LEDLOGIC_H */

