/* 
 * File:   main.h
 * Author: Matthew Atkins
 *
 * Created on March 21, 2016, 4:54 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include <string.h>
    
    typedef enum {
        ARM_DISARMED,
        ARM_MANUAL,
        ARM_AUTO
    } arm_state_t;
    
    static arm_state_t arm_state;
    static uint8_t charBuff[15];
    
    void delay_25ms_n_times(int16_t n);
    
    void init(void);
    void processCommand(const char* cmnd);
    void printCommandList(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

