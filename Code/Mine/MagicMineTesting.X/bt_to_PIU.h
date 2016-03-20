/** 
 * @file   bt_to_PIU.h
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 12:46 AM
 */

#ifndef BT_TO_PIU_H
#define	BT_TO_PIU_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "bt_common.h"

    static bt_device_state_t state = BT_STATE_DISCONECTED;
    
    bool PIU_bt_enter_command_mode(void);
    
    bool PIU_bt_exit_command_mode(void);
    
    bool PIU_bt_connect_to_PIU(void);
    
    void PIU_bt_send_command(bt_cmnd_t cmnd);
    
    bt_device_state_t PIU_bt_get_device_state(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_TO_PIU_H */

