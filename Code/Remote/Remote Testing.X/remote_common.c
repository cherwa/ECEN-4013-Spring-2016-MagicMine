#include "remote_common.h"

void delay_n_ms(uint8_t n) {
    
    for (n; n >= 1; n--) {
        __delay_ms (25);
    }
    
    __delay_ms (25);
}