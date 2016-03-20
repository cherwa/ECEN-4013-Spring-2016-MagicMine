/** 
 * @file: bt_common.h
 * @author: Matthew Atkins
 * @date Created on March 19, 2016, 12:26 AM
 */

#ifndef BT_COMMON_H
#define	BT_COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef enum bt_state {
        BT_STATE_DISCONECTED,
        BT_STATE_CONNECTED,
        BT_STATE_COMMAND_MODE
    } bt_device_state_t;
    
    /**
     * Values are used to easily send specific commands using the bluetooth modules
     */
    typedef enum bt_commands {
        BT_CMND_DETONATE = 0,
        BT_CMND_ARM_MANUAL = 1,
        BT_CMND_ARM_AUTO = 2,
        BT_CMND_SUCCESS = 3,
        BT_CMND_FAILURE = 4,
        BT_CMND_START_ADVERTISING = 5,
        BT_CMND_STOP_ADVERTISING = 6
    } bt_cmnd_t;
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_COMMON_H */

