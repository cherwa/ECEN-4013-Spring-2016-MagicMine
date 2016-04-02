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
    
    static bt_device_state_t state = BT_STATE_DISCONECTED;
    
    bool remote_bt_enter_command_mode(void);
    
    bool remote_bt_exit_command_mode(void);
    
    void remote_bt_send_command(bt_cmnd_t cmnd);
    
    bt_device_state_t remote_bt_get_device_state(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_TO_REMOTE_H */

