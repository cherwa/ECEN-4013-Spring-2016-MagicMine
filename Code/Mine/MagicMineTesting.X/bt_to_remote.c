/**
 * @file bt_to_remote.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 1:04 AM
 */

#include "bt_to_remote.h"

bool remote_bt_enter_command_mode(void) {
    
    // Enter command mode
    BT_RMT_CMD_LAT = 1;
    
    return true;
}
    
bool remote_bt_exit_command_mode(void) {
    
    // Set command pin low
    BT_RMT_CMD_LAT = 0;
    return true;
}
    
void remote_bt_send_command(bt_cmnd_t cmnd) {
    
    switch (cmnd) {
        case BT_CMND_START_ADVERTISING:
            break;
        case BT_CMND_STOP_ADVERTISING:
            break;
        default:
            break;
    }
}
    
bt_device_state_t remote_bt_get_device_state(void) {
    return state;
}