#include "util_functions.h"

uint8_t log_buff[255] = '\0';

void delay_25ms_n_times(int16_t n) {
    for (; n >= 0; n--) {
            __delay_ms (25);
    }
}

void log() {
    
    printf("[LOG]   %s\n",log_buff);
}