/**
 * @file bluetooth_4.c
 * @author Matthew Atkins
 * @date Created on April 7, 2016, 4:09 AM
 */

#include "bluetooth_4.h"
#include "util_functions.h"
#include "LEDs.h"

/**
 * Global variable definitions
 */
int BT4_average_rssi = 0;
BT4_device_state_t BT4_device_state = BT_STATE_DISCONECTED;
bool BT4_is_connected = false;

/**
 * Module variables
 */
static uint8_t BT4_char_buff[15];
static uint8_t BT4_read_byte;
static uint8_t BT4_int_buff[15];
static uint8_t BT4_byte_counter = 0;
static char BT4_cur_rssi[2];

/**
 * Module functions
 */
void write_string(const uint8_t* str);

/**
 * 
 * 
 * 
 */

void write_string(const uint8_t* str) {
    
    while (*str != '\0') {
        EUSART2_Write( *(str++) );
    }
}

void BT4_init() {
    
//    BT4_send_command(BT_CMND_CONNECT);
    
    ANSELBbits.ANSB2 = 0;
    TRISBbits.RB2 = 1;
    
    uint8_t cmnd_buff[30];
    
    sprintf(cmnd_buff, "E,0,%s\n", BT_REMOTE_MAC);
    write_string(cmnd_buff);
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
    BT4_CMND_LAT = 1;
    __delay_us (50);
    BT4_CMND_LAT = 0;
    
    return true;
}
    
void BT4_send_command(BT4_command_t cmnd) {
    
    uint8_t i = 0;
    uint8_t* cmnd_buff[50];
    
    switch (cmnd) {
        
        case BT_CMND_ENTER_MLDP:
            
            write_string("I\n");
            break;
       
        case BT_CMND_CONNECT:
            break;
        
        default:
            
            sprintf(cmnd_buff, "%c\n", cmnd);
            write_string(cmnd_buff);
            break;
    }
}

void BT4_read_to_buffer() {
    
    BT4_byte_counter = 0;
    memset(BT4_char_buff, '\0', sizeof(BT4_char_buff));
    
    while (EUSART2_DataReady && BT4_read_byte != '\n') {
        
        BT4_read_byte = EUSART2_Read();
        
        BT4_char_buff[BT4_byte_counter] = BT4_read_byte;
        
        BT4_byte_counter++;
    }
}

bool BT4_get_RSSI() {
    
    BT4_enter_command_mode();
    BT4_average_rssi = 0;
    memset(BT4_cur_rssi, '\0', sizeof(BT4_cur_rssi));
    
    uint8_t i = 0;
    for (i; i < 128; i++) {
        write_string("M\n");
        
        BT4_read_to_buffer();
    }
    
    
    
    // Divide by 128 since we sampled 128 times
    BT4_average_rssi >>= 7;
    
    return BT4_average_rssi <= 0x4B;
}

void BT4_process_packet() {
    
    if (strstr(BT4_char_buff, BT_CMND_ACK) != NULL) {
        LED_play_pattern(LED_MPU_INIT_SUCCESS);
    } else if (strncmp(BT4_char_buff, "Connected", 9) == 0) {
        BT4_is_connected = true;
    }
}