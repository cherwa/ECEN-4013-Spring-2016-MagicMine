/**
 * @file bt_to_remote.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 1:04 AM
 */

#include "bt_to_remote.h"

bool remote_bt_enter_command_mode(void) {
    
    // Enter command mode
    BT_RMT_CMD_LAT = 1;
    
    if (EUSART1_DataReady) {
        e
    }
    
    EUSART1_Write();
    
    return true;
}
    
bool remote_bt_exit_command_mode(void) {
    
    // Set command pin low
    BT_RMT_CMD_LAT = 0;
    return true;
}
    
void remote_bt_send_command(remote_bt_cmnd_t cmnd) {
    
    switch (cmnd) {
        case START_ADVERTISING:
            break;
        case STOP_ADVERTISING:
            break;
        case ARM_SUCCESFUL:
            break;
        case DETONATED:
            break;
        default:
            break;
    }
}
    
bt_device_state_t remote_bt_get_device_state(void) {
    return state;
}