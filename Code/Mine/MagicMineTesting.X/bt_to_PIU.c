/**
 * @file bt_to_PIU.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 1:11 AM
 */

#include "bt_to_PIU.h"

bool PIU_bt_enter_command_mode(void) {
    return true;
}
    
bool PIU_bt_exit_command_mode(void) {
    return true;
}
    
void PIU_bt_send_command(PIU_bt_cmnd_t cmnd) {
    switch (cmnd) {
        case CONNECT:
            break;
        default:
            break;
    }
}
    
bt_device_state_t PIU_bt_get_device_state(void) {
    return state;
}