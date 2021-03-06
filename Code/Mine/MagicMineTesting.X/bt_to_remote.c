/**
 * @file bt_to_remote.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 1:04 AM
 */

#include "bt_to_remote.h"

//Global variable definitions
int BT4M_average_rssi = 0;
uint8_t BT4M_cur_rssi[2] = {0, 0};
bt_device_state_t BT4M_device_state = BT_STATE_DISCONECTED;

void BT4M_init() {
    
    BT4M_send_command(BT_CMND_CONNECT);
}

bool BT4M_enter_command_mode(void) {
    
    // Enter command mode
    BT4M_CMD_LAT = 1;
    __delay_us (50);
    BT4M_CMD_LAT = 0;
    
    return true;
}
    
void BT4M_send_command(bt_cmnd_t cmnd) {
    
    uint8_t i = 0;
    
    switch (cmnd) {
        
        case BT_CMND_ENTER_MLDP:
            
            EUSART2_Write('i');
            EUSART2_Write('\n');
            break;
       
        case BT_CMND_CONNECT:
            
            EUSART2_Write('e');
            EUSART2_Write(',');
            EUSART2_Write('0');
            EUSART2_Write(',');
            
            for (i; i < 10; i++) {
               EUSART2_Write(BT_REMOTE_MAC[i]);
            }
            
            EUSART2_Write('\n');
            
            break;
        
        default:
            EUSART2_Write(cmnd);
            __delay_us (100);
            EUSART2_Write('\n');
            break;
    }
    
    
}

void BT4M_read_buffer() {
    
    BT4M_byte_counter = 0;
    memset(BT4M_char_buff, '\0', sizeof(BT4M_char_buff));
    
    do {
        
        BT4M_read_byte = EUSART2_Read();
        
        BT4M_char_buff[BT4M_byte_counter] = BT4M_read_byte;
        
        BT4M_byte_counter++;
        
    } while (EUSART2_DataReady && BT4M_read_byte != '\n');
    
    BT4M_process_packet(BT4M_char_buff);
}

bool BT4M_get_RSSI() {
    
    BT4M_enter_command_mode();
    EUSART2_Write('M');
    EUSART2_Write('\n');
    BT4M_average_rssi = 0;
    BT4M_cur_rssi[0] = '\0';
    BT4M_cur_rssi[1] = '\0';
    
    uint8_t i = 0;
    for (i; i < 128; i++) {
        BT4M_read_buffer();
    }
    
    BT4M_average_rssi >>= 7;
    
    return BT4M_average_rssi <= 0x4B;
}