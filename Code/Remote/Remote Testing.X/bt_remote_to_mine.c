/* 
 * File:   bt_remote_to_mine.c
 * Author: Matthew Atkins
 *
 * Created on March 30, 2016, 9:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "bt_remote_to_mine.h"

void bt_init() {
    
    // Wait for connection from mine
    
    do {
        
    } while (EUSART_DataReady);
}

inline void bt_enter_command_mode() {
    
}

inline void bt_enter_MLDP_mode() {
    
}

void bt_detonate() {
    
}

void bt_heartbeat() {
    
}

void bt_set_arm_mode_auto() {
    
}

void bt_set_arm_mode_manual() {
    
}

int16_t bt_get_RSSI() {
    
    uint8_t read_byte;
            
        if (bt_is_connected) {
            
            bt_enter_command_mode();
            
            printf("M\n");

            __delay_ms(5);

            do {

                read_byte = EUSART_Read();
                char_buff[buff_index] = read_byte;
                buff_index++;

            } while (EUSART_DataReady);
            
            uint32_t result = strtoul(char_buff, NULL, 16);
            
            // Do something with result here
        }
} 
