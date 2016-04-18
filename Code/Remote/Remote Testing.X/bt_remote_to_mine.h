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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart.h"
#include "bt_common.h"
#include "remote_main.h"

#define BT_MINE_MAC "001EC030D541"
#define BT_REMOTE_MAC "001EC030D557"
    
    bt_device_state_t bt_device_state = false;
    
    extern bool bt_is_connected;
    
    void bt_init();
    
    bool bt_send_command(BT4_command_t cmnd);
    
    void bt_process_packet();
    
    void bt_read_buffer();
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_REMOTE_TO_MINE_H */

