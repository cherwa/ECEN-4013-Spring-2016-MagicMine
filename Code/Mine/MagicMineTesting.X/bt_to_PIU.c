/**
 * @file bt_to_PIU.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 1:11 AM
 */

#include "bt_to_PIU.h"
//#include "main.h"

static inline void PIU_bt_clear_data_buff(void) {
    memcpy(piu_buff, '\0', sizeof(piu_buff));
}

bool PIU_bt_enter_command_mode(void) {
    
    TX1REG = '$'; TX1REG = '$'; TX1REG  = '$';
    
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
    
    TX1REG = '-'; TX1REG = '-'; TX1REG = '-'; TX1REG = '\n';
    
    return true;
}
/** @deprecated */
void PIU_bt_send_command(bt_cmnd_t cmnd) {

    switch (cmnd) {
        case BT_CMND_IS_CONNECTED:
            
            PIU_bt_enter_command_mode();
            
            TX1REG = 'G'; TX1REG = 'R'; TX1REG = '\n';
            
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

bool PIU_bt_transmit_packet(bt_packet_t packet) {
    
    // Compute the CRC byte
    packet.crc = 0xFF - (packet.func + packet.data1 + packet.data2 + packet.data3);
    
    TX1REG = packet.start;
    __delay_us(100);
    TX1REG = packet.func;
    __delay_us(100);
    TX1REG = packet.data1;
    __delay_us(100);
    TX1REG = packet.data2;
    __delay_us(100);
    TX1REG = packet.data3;
    __delay_us(100);
    TX1REG = packet.crc;
    __delay_us(100);
    
    byte_counter = 0;
    
    do {
        if (EUSART1_DataReady) {
            read_byte = EUSART1_Read();
            piu_buff[byte_counter] = read_byte;
            byte_counter++;
        }
    } while(byte_counter < 6);
    
    if ( strncmp(piu_buff, PIU_HEARTBEAT_PACKET, 6) ){
        return true;
    } else {
        return false;
    }
}

void PIU_bt_read_cmnd_to_buffer(uint8_t size_to_read) {
    
    memcpy(piu_buff, '\0', sizeof(piu_buff));
    
    uint8_t read_byte;
    
    do {
        
        if (EUSART1_DataReady) {
            
            for (uint8_t i = 0; i <= size_to_read; i++) {
                read_byte = EUSART1_Read();
                piu_buff[i] = read_byte;
                
                if (read_byte == '\n' || read_byte == '\0') {
                    break;
                }
            }
        }
    } while (byte_counter < size_to_read);
}