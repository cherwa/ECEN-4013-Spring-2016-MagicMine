/** 
 * @file   bt_to_remote.h
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 12:46 AM
 */

#ifndef BT_TO_REMOTE_H
#define	BT_TO_REMOTE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "bt_common.h"
#include <string.h>
    
    static uint8_t BT4M_byte_counter = 0;
    
    uint8_t BT4M_char_buff[15];
    uint8_t BT4M_read_byte;
    
    uint8_t BT4M_int_buff[15];
    
    extern int BT4M_average_rssi;
    extern uint8_t BT4M_cur_rssi[2];
    
    static bt_device_state_t state = BT_STATE_DISCONECTED;
    
    bool BT4M_enter_command_mode(void);
    
    bool BT4M_exit_command_mode(void);
    
    void BT4M_send_command(bt_cmnd_t cmnd);
    
    bt_device_state_t BT4M_get_device_state(void);
    
    void BT4M_process_packet(uint8_t* packet);
    
    bool BT4M_get_RSSI();
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_TO_REMOTE_H */

