#include "remote_common.h"

void delay_n_ms(uint8_t n) {
    
    for (n; n >= 1; n--) {
        __delay_ms (25);
    }
    
    __delay_ms (25);
}

uint8_t byte_from_hex(uint8_t data) {
    
    if (data > '9') {
        data += 9;
    }
    
    return (data & 0x0F);
}