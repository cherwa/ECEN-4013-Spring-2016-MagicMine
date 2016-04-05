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
    
    const uint8_t** BT_MINE_MAC = "001EC0D557";
    const uint8_t** BT_REMOTE_MAC = "001EC0D541";
    
    static uint8_t BT4M_byte_counter = 0;
    
    uint8_t BT4M_char_buff[15];
    uint8_t BT4M_read_byte;
    
    uint8_t BT4M_int_buff[15];
    
    extern int BT4M_average_rssi;
    extern char BT4M_cur_rssi[2];
    
    extern bt_device_state_t BT4M_device_state;
    
    void BT4M_init(void);
    
    bool BT4M_enter_command_mode(void);
    
    void BT4M_send_command(bt_cmnd_t cmnd);
    
    void BT4M_process_packet(uint8_t* packet);
    
    bool BT4M_get_RSSI();
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_TO_REMOTE_H */

