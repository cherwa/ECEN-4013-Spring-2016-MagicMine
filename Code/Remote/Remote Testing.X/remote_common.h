/** 
 * @file remote_common.h
 * @author Matthew Atkins
 *
 * @date March 14, 2016, 6:41 PM
 */

#ifndef REMOTE_COMMON_H
#define	REMOTE_COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
    
    /**
     * enum values are used to indicate a kind of spell. For example, the currently
     * [selected spell] (@ref selectedSpell) will be one of these values. If no selection has been made
     * then this should be reflected by setting this value to NO_SELECTION.
     */
    typedef enum {
        NO_SELECTION,   /**< No spell has been selected yet.*/
        WHITE_SPELL,    /**< Custom spell type.*/
        BLUE_SPELL,     /**< Healing spell.*/
        YELLOW_SPELL,   /**< Stun spell.*/
        RED_SPELL       /**< Damage spell.*/
    } spell_t;

    /**
     * Delays 25 milliseconds n number of times.
     * @param n The number of times to delay.
     */
    void delay_n_ms(uint8_t n);

#ifdef	__cplusplus
}
#endif

#endif	/* REMOTE_COMMON_H */

