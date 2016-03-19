/**
 * @file bt_to_remote.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 1:04 AM
 */

#include "bt_to_remote.h"

bool remote_bt_enter_command_mode(void) {
    return true;
}
    
bool remote_bt_exit_command_mode(void) {
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