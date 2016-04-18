/* 
 * File:   bt_remote_to_mine.c
 * Author: Matthew Atkins
 *
 * Created on March 30, 2016, 9:44 PM
 */

#include "bt_remote_to_mine.h"

static uint8_t bt_char_buff[15];
static uint8_t bt_byte_counter = 0;
static uint8_t bt_read_byte;

bool bt_is_connected = false;

void bt_init() {
    
    // Wait for connection from mine
    
    while (!bt_is_connected) {
        if (EUSART_DataReady) {

            bt_read_byte = EUSART_Read();

            bt_char_buff[bt_byte_counter] = bt_read_byte;

            bt_byte_counter++;

            if (strstr(bt_char_buff, "Connected") != NULL || strstr(bt_char_buff, "AOK") != NULL) {
                bt_is_connected = true;
                break;
            }   
        }
    }
}

bool bt_send_command(BT4_command_t cmnd) {
    
    switch (cmnd) {
       
        case 0x01:
            
            printf("E,0,%s\n", BT_MINE_MAC);
            bt_read_buffer();
            return strncmp(bt_char_buff, "Connected", sizeof("Connected")) == 0;
            
        default:
            printf("%i\n", cmnd); 
            bt_read_buffer();
            uint8_t temp[] = {BT_CMND_SUCCESS};
            return (strncmp(bt_char_buff, temp, sizeof(BT_CMND_SUCCESS) + 1) == 0);
    }       
}

void bt_read_buffer() {
    
    bt_byte_counter = 0;
    memset(bt_char_buff, '\0', sizeof(bt_char_buff));
    
    do {
        
        if (EUSART_DataReady) {
            bt_read_byte = EUSART_Read();

            bt_char_buff[bt_byte_counter] = bt_read_byte;

            bt_byte_counter++;
        }
        
    } while (bt_byte_counter < 15 && bt_read_byte != '\n');
}

void bt_process_packet() {
    
    uint8_t read_byte;
    
    while (EUSART_DataReady) {
        
        read_byte = EUSART_Read();
        
        switch (read_byte) {
            case 0x20:
                BLUE_LED = 0;
                delay_n_ms(2);
                BLUE_LED = 1;
                delay_n_ms(2);
                BLUE_LED = 0;
                delay_n_ms(2);
                BLUE_LED = 1;
                delay_n_ms(2);
                BLUE_LED = 0;
                delay_n_ms(2);
                BLUE_LED = 1;
                delay_n_ms(2);
                BLUE_LED = selectedSpell == BLUE_SPELL;
                break;
            case 0x30:
                YELLOW_LED = 0;
                WHITE_LED = 0;
                ARM_LED = 1;
                BLUE_LED = 0;
                RED_LED = 0;
                delay_n_ms(2);
                YELLOW_LED = 0;
                WHITE_LED = 1;
                ARM_LED = 0;
                BLUE_LED = 1;
                RED_LED = 0;
                delay_n_ms(2);
                YELLOW_LED = 1;
                WHITE_LED = 0;
                ARM_LED = 0;
                BLUE_LED = 0;
                RED_LED = 1;
                delay_n_ms(2);
                YELLOW_LED = 0;
                WHITE_LED = 0;
                ARM_LED = 1;
                BLUE_LED = 0;
                RED_LED = 0;
                delay_n_ms(2);
                YELLOW_LED = 0;
                WHITE_LED = 1;
                ARM_LED = 0;
                BLUE_LED = 1;
                RED_LED = 0;
                delay_n_ms(2);
                YELLOW_LED = 1;
                WHITE_LED = 0;
                ARM_LED = 0;
                BLUE_LED = 0;
                RED_LED = 1;
                delay_n_ms(2);
                YELLOW_LED = 0;
                WHITE_LED = 0;
                ARM_LED = 1;
                BLUE_LED = 0;
                RED_LED = 0;
                delay_n_ms(2);
                YELLOW_LED = 0;
                WHITE_LED = 1;
                ARM_LED = 0;
                BLUE_LED = 1;
                RED_LED = 0;
                delay_n_ms(2);
                YELLOW_LED = 1;
                WHITE_LED = 0;
                ARM_LED = 0;
                BLUE_LED = 0;
                RED_LED = 1;
                delay_n_ms(2);
                
                reset_to_start();
                break;
        }
    }
}