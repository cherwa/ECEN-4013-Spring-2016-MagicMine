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

#include "bt_common.h"

    typedef enum {
        CONNECT
    } PIU_bt_cmnd_t;

    static bt_device_state_t state = DISCONECTED;
    
    bool PIU_bt_enter_command_mode(void);
    
    bool PIU_bt_exit_command_mode(void);
    
    void PIU_bt_send_command(PIU_bt_cmnd_t cmnd);
    
    bt_device_state_t PIU_bt_get_device_state(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_TO_PIU_H */

