/* 
 * File:   util_functions.h
 * Author: Matthew Atkins
 *
 * Created on April 7, 2016, 3:34 AM
 */

#ifndef UTIL_FUNCTIONS_H
#define	UTIL_FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
      
#define DEBUG
    
#ifdef DEBUG
    #define LOG(x) sprintf(x); log()
#else
    #define LOG(x)
#endif
    
#include "mcc_generated_files/mcc.h"

    extern uint8_t log_buff[255];
            
    void delay_25ms_n_times(int16_t n);
    
    void log();

#ifdef	__cplusplus
}
#endif

#endif	/* UTIL_FUNCTIONS_H */

