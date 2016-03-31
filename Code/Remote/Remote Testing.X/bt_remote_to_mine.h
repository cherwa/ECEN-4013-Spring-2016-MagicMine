/* 
 * File:   bt_remote_to_mine.h
 * Author: Matthew Atkins
 *
 * Created on March 30, 2016, 9:35 PM
 */

#ifndef BT_REMOTE_TO_MINE_H
#define	BT_REMOTE_TO_MINE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart.h"
#include "bluetooth_commands.h"

#define BT_MINE_MAC 0x001
#define BT_REMOTE_MAC 0x001
    
    static uint8_t char_buff[15];
    static uint8_t buff_index = 0;
    bool bt_is_connected = false;
    
    void bt_init();
    
    inline void bt_enter_command_mode();
    
    inline void bt_enter_MLDP_mode();
    
    void bt_detonate();
    
    void bt_heartbeat();
    
    void bt_set_arm_mode_auto();
    
    void bt_set_arm_mode_manual();
    
    int16_t bt_get_RSSI();
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_REMOTE_TO_MINE_H */

