/**
 * @file bt_to_PIU.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 1:11 AM
 */

#include "bt_to_PIU.h"
#include "main.h"
#include <string.h>

static inline void PIU_bt_clear_data_buff(void) {
    memcpy(piu_buff, '\0', sizeof(piu_buff));
}

bool PIU_bt_enter_command_mode(void) {
    
    TX2REG = '$'; TX2REG = '$'; TX2REG  = '$';
    
    PIU_bt_read_cmnd_to_buffer(3);
    
    if (strncmp(piu_buff, "CMD", 3) == 0) {
        PIU_bt_clear_data_buff();
        return true;
    } else {
        PIU_bt_clear_data_buff();
        return false;
    }
}
    
bool PIU_bt_exit_command_mode(void) {
    
    TX2REG = '-'; TX2REG = '-'; TX2REG = '-'; TX2REG = '\n';
    
    return true;
}
    
void PIU_bt_send_command(bt_cmnd_t cmnd) {

    switch (cmnd) {
        case BT_CMND_IS_CONNECTED:
            
            PIU_bt_enter_command_mode();
            
            TX2REG = 'G'; TX2REG = 'R'; TX2REG = '\n';
            
            PIU_bt_read_cmnd_to_buffer(12);
            
            if (strncmp(piu_buff, PIU_BT_PIU_MAC, sizeof(PIU_BT_PIU_MAC)) == 0) {
                PIU_bt_exit_command_mode();
                piu_bt_state = BT_STATE_CONNECTED;
            } else {
                PIU_bt_exit_command_mode();
                piu_bt_state = BT_STATE_DISCONECTED;
            }
            
            break;
    }
}
    
bt_device_state_t PIU_bt_get_device_state(void) {
    return piu_bt_state;
}

void PIU_bt_transmit_packet(bt_packet_t packet) {
    
    // Compute the CRC byte
    packet.crc = 0xFF - (packet.func + packet.data1 + packet.data2 + packet.data3);
    
    TX2REG = packet.start;
    TX2REG = packet.func;
    TX2REG = packet.data1;
    TX2REG = packet.data2;
    TX2REG = packet.data3;
    TX2REG = packet.crc;
}

void PIU_bt_read_cmnd_to_buffer(uint8_t size_to_read) {
    
    memcpy(piu_buff, '\0', sizeof(piu_buff));
    
    uint8_t read_byte;
    
    do {
        
        if (EUSART2_DataReady) {
            
            for (uint8_t i = 0; i <= size_to_read; i++) {
                read_byte = EUSART1_Read();
                piu_buff[i] = read_byte;
                
                if (read_byte == '\n' || read_byte == '\0') {
                    break;
                }
            }
        }
    } while (sizeof(piu_buff) < size_to_read);
}