/**
 * @file bluetooth_4.c
 * @author Matthew Atkins
 * @date Created on April 7, 2016, 4:09 AM
 */

#include "bluetooth_4.h"

/**
 * Global variable definitions
 */
uint16_t BT4_average_rssi = 0;
BT4_device_state_t BT4_device_state = BT_STATE_DISCONECTED;
bool BT4_is_connected = false;

/**
 * Module variables
 */
static uint8_t BT4_char_buff[15];
static uint8_t BT4_read_byte;
static uint8_t BT4_int_buff[15];
static uint8_t BT4_byte_counter = 0;
static char BT4_cur_rssi[3];

/**
 * Module functions
 */

/**
 * 
 * 
 * 
 */

void BT4_write_string(const uint8_t* str) {
    
    while (*str != '\0') {
        EUSART2_Write( *(str++) );
    }
}

void BT4_init() {
    
//    BT4_send_command(BT_CMND_CONNECT);
    
    ANSELBbits.ANSB1 = 0;
    TRISBbits.RB1 = 0;
    
    uint8_t cmnd_buff[30];
    
    sprintf(cmnd_buff, "E,0,%s\n", BT_REMOTE_MAC);
    BT4_write_string(cmnd_buff);
    __delay_ms (20);
        
    while (!BT4_is_connected) {
        if (EUSART2_DataReady) {

            BT4_read_byte = EUSART2_Read();

            BT4_char_buff[BT4_byte_counter] = BT4_read_byte;

            BT4_byte_counter++;

            if (strstr(BT4_char_buff, "Connected") != NULL || strstr(BT4_char_buff, "AOK") != NULL) {
                BT4_is_connected = true;
                break;
            }   
        }
    }
}

bool BT4_enter_command_mode() {
    
    // Enter command mode
//    BT4_CMND_LAT = 0;
//    __delay_ms (10);
    BT4_CMND_LAT = 1;
    delay_25ms_n_times(8);
    BT4_CMND_LAT = 0;
    
    return true;
}
    
void BT4_send_command(const BT4_command_t cmnd) {
    
    uint8_t i = 0;
    uint8_t* cmnd_buff[50];
    
    switch (cmnd) {
        
        case 0x04:
            
            BT4_write_string("I\n");
            break;
       
        case 0x04:
            break;
        
        default:
            
            sprintf(cmnd_buff, "%c\n", cmnd);
            BT4_write_string(cmnd_buff);
            break;
    }
}

void BT4_read_to_buffer() {
    
    BT4_byte_counter = 0;
    memset(BT4_char_buff, '\0', sizeof(BT4_char_buff));
    BT4_read_byte = '\0';
    
    while (BT4_read_byte != '\n') {
        
        if (EUSART2_DataReady) {
        
            BT4_read_byte = EUSART2_Read();

            BT4_char_buff[BT4_byte_counter] = BT4_read_byte;

            BT4_byte_counter++;
        }
    }
}

bool BT4_get_RSSI() {
    
//    printf("Entering command mode!\n");
    
    BT4_enter_command_mode();
    BT4_average_rssi = 0;
//    memset(BT4_cur_rssi, '\0', sizeof(BT4_cur_rssi));
    
    uint8_t cur_val;
    
//    printf("Starting data collection...");
    
    uint8_t i = 0;
    for (; i < 128; i++) {
        
        memset(BT4_char_buff, '\0', sizeof(BT4_char_buff));
        BT4_byte_counter = 0;
        
        BT4_write_string("M\n");
        
        while (1) {
            BT4_read_byte = EUSART2_Read();

            if (BT4_read_byte == '\n') {
                break;
            } else if (BT4_read_byte == '-') {
                continue;
            }
                        
            BT4_char_buff[BT4_byte_counter] = BT4_read_byte;
            BT4_byte_counter++;
        };        
        
        cur_val = strtol(BT4_char_buff, NULL, 16);
        
        BT4_average_rssi += cur_val;
        
        __delay_ms (10);
    }

    // Divide by 128 since we sampled 128 times
//    BT4_average_rssi >>= 7;
    BT4_average_rssi /= 128;
    
    printf("Done!\nAverage RSSI: %X", BT4_average_rssi);
    
//    BT4_write_string("I\n");
    BT4_CMND_LAT = 1;
    
//    return BT4_average_rssi <= 0x4B;
    return BT4_average_rssi <= BT4_1M_THRESHOLD;
}

void BT4_process_packet(const uint8_t byte) {
    
    switch (byte) {
        case 0x00:
            
            detonate_device();
            break;
        
        case 0x10:
            arm_device(DEVICE_STATE_ARMED_MANUAL, 'Y');
            break;
        
        case 0x11:
            arm_device(DEVICE_STATE_ARMED_MANUAL, 'W');
            break;
        
        case 0x12:
            arm_device(DEVICE_STATE_ARMED_MANUAL, 'B');
            break;
        
        case 0x13:
            arm_device(DEVICE_STATE_ARMED_MANUAL, 'R');
            break;
        
        case 0x20:
            arm_device(DEVICE_STATE_ARMED_AUTO, 'Y');
            break;
        
        case 0x21:
            arm_device(DEVICE_STATE_ARMED_AUTO, 'W');
            break;
        
        case 0x22:
            arm_device(DEVICE_STATE_ARMED_AUTO, 'B');
            break;
        
        case 0x23:
            arm_device(DEVICE_STATE_ARMED_AUTO, 'R');           
            break;
        
        case 0x05:
            break;
        
        case 0x06:
            break;
        
        case 0x07:
            break;
        
        case 0x08:
            break;
        
        case 0x09:
            break;
        
        case 0x0A:
            break;            
    }
    
//    if (get_device_state() == DEVICE_STATE_ARMED_AUTO) {
//        IOCB4 = 1;
//    }
}