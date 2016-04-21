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
    
#include "mcc_generated_files/mcc.h"
    
    typedef enum bt_state {
        BT_STATE_DISCONECTED,
        BT_STATE_CONNECTED,
        BT_STATE_ERROR,
        BT_STATE_CMD_MODE,
        BT_STATE_MLDP_MODE
    } bt_device_state_t;
    
    /**
     * Values are used to easily send specific commands using the bluetooth modules
     */
    
    typedef enum bt4_commands {
        BT_CMND_DETONATE = 0x00,
        BT_CMND_ARM_MANUAL = 0x01,
        BT_CMND_ARM_AUTO = 0x02,
        BT_CMND_SUCCESS = 0x03,
        BT_CMND_FAILURE = 0x04,
        BT_CMND_CONNECT = 0x05,
        BT_CMND_DISCONECT = 0x06,
        BT_CMND_IS_CONNECTED = 0x07,
        BT_CMND_ENTER_MLDP = 0x08,
        BT_CMND_HEARTBEAT = 0x09,
        BT_CMND_ACK = 0x0A
    } BT4_command_t;
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_COMMON_H */

