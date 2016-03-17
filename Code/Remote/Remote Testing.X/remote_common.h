/* 
 * File:   remote_common.h
 * Author: matthew
 *
 * Created on March 14, 2016, 6:41 PM
 */

#ifndef REMOTE_COMMON_H
#define	REMOTE_COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
    
    typedef enum {
        NO_SELECTION,
        WHITE_SPELL,
        BLUE_SPELL,
        YELLOW_SPELL,
        RED_SPELL
    } spell_t;

    /**
     * 
     * Delays 25 milliseconds n number of times.
     * 
     * @param n The number of times to delay.
     */
    void delay_n_ms(uint8_t n);

#ifdef	__cplusplus
}
#endif

#endif	/* REMOTE_COMMON_H */

