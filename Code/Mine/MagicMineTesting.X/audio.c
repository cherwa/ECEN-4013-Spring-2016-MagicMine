/**
 * @file audio.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 6:03 PM
 */

#include "audio.h"
#include "util_functions.h"

void audio_init() {
    
    /** @todo energizes 20 after figuring out how to determine if the devices busy.*/
    PAM_SD_LAT = 1;
    WTV_CLOCK_LAT = 0;
    WTV_RESET_LAT = 1;
    
    WTV_RESET_LAT = 0;
    __delay_ms (5);
    
    WTV_CLOCK_LAT = 1;
    WTV_RESET_LAT = 1;
}

void audio_play(audio_file_t command) {
    
//    PAM_SD_LAT = 1;
    __delay_ms (20);
    audio_send_command(command);
    __delay_ms (10);
    audio_send_command(AUDIO_VOLUME_6);
//    delay_25ms_n_times(120);
//    PAM_SD_LAT = 0;
}

void audio_send_command(audio_file_t command) {
    
    uint16_t mask = 0x8000;
    
    WTV_CLOCK_LAT = 0;
    __delay_ms (2);
    
    for (mask; mask > 0; mask >>=1) {
        
        WTV_CLOCK_LAT = 0;
        __delay_us (50);
        
        if (command & mask) {
            WTV_DATA_LAT = 1;
        } else {
            WTV_DATA_LAT = 0;
        } 
        
        __delay_us (50);
        
        WTV_CLOCK_LAT = 1;
        __delay_us (100);
        
        if (mask > 1) {
            WTV_CLOCK_LAT = 0;
            __delay_ms (2);
        }
    }
}