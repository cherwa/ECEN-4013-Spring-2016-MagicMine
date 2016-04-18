#include "bluetooth_2.h"

/**
 * Global variable definitions
 */

bool BT2_is_connected = false;
struct BT_MAGE_packet_t BT2_packet;

/**
 * Global module variables
 */
static uint8_t read_byte;
static uint8_t byte_count = 0;
static bool read_start_byte = false;
static uint8_t char_buff[255];

void BT2_init() {
 
    bool conected_to_PIU = false;
    
    if (conected_to_PIU) {
        return;
    }
    
    while (!conected_to_PIU) {
        
        if (EUSART1_DataReady) {
            
            read_byte = EUSART1_Read();
            
            char_buff[byte_count] = read_byte;
            byte_count++;
            
            printf("BUF: %s\n", char_buff);
            
            if (strstr(char_buff, "8060F1") != NULL) {
                conected_to_PIU = true;
            }
        }
    }
    
    printf("Connected\n");
    
//    printf("\x3C\x01%c%c%c\xFE",0x00, 0x00, 0x00);
    BT2_packet.function = 0x01; BT2_packet.data1 = 0x00; BT2_packet.data2 = 0x00; BT2_packet.data3 = 0x00;
    
    if (BT2_send_packet()) {
        
        BT2_is_connected = true;
    }
}

bool BT2_send_packet() {
    
    //Compute CRC byte
    
    BT2_packet.crc = 0xFF - (BT2_packet.function + BT2_packet.data1 + BT2_packet.data2 + BT2_packet.data3);
    
    printf("\x3C%c%c%c%c%c", BT2_packet.function, BT2_packet.data1, BT2_packet.data2, BT2_packet.data3, BT2_packet.crc);
    
    
    // Wait for ACK from PIU
    BT2_read_response();
    
    if (strstr(char_buff, "\x3C\xFF\x00\x00\x00\x00") != NULL) {
        return true;
    }
    
    return false;
}

bool BT2_send_heartbeat() {
    printf("\x3C%c%c%c%c\xFF", 0x00, 0x00, 0x00, 0x00);
    
    // Wait for ACK from PIU
//    BT2_read_response();
    
    return true;
//    if (strstr(char_buff, "\x3C\xFF\x00\x00\x00\x00") != NULL) {
//        BT2_send_heartbeat();
//    } else {
//        return true;
//    }
}

void BT2_read_response() {
    
    // Clear byte buffer and reset byte_count
    memset(char_buff, '\0', sizeof(char_buff));
    byte_count = 0;
    read_start_byte = false;
    
    // All PIU responses should be 6 bytes
    
    // Read the first byte so we can see if we if a new start byte comes in
    while (byte_count < 6) {
        
        if (EUSART1_DataReady) {
            
            read_byte = EUSART1_Read();
            
            char_buff[byte_count] = read_byte;
            byte_count++;
            
            if (read_byte == 0x3C) {
                
                if (!read_start_byte && byte_count == 1) {
                    read_start_byte = true;
                } else {
                    // Something has gone wrong! Start over and try to read this
                    // packet instead.
                    
                    char_buff[0] = read_byte;
                    byte_count = 1;
                }
            }
        }
    }
}