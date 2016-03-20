/**
 * @file util_functions.c
 * @author Matthew Atkins
 * @date Created on March 18, 2016, 10:03 PM
 */

#include <pic18.h>

#include "util_functions.h"

void delay_25ms_n_times(uint16_t n) {
    
    for (n; n > 1; n--) {
        __delay_ms (25);
    }
    
    __delay_ms (25);
}