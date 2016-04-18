/* 
 * File:   bluetooth_4_common.h
 * Author: Matthew Atkins
 *
 * Created on April 6, 2016, 10:47 PM
 */

#ifndef BLUETOOTH_4_COMMON_H
#define	BLUETOOTH_4_COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "mcc_generated_files/mcc.h"
    
    typedef enum {
        BT_STATE_DISCONECTED,
        BT_STATE_CONNECTED,
        BT_STATE_ERROR,
        BT_STATE_CMD_MODE,
        BT_STATE_MLDP_MODE
    } BT4_device_state_t;
    
    typedef uint8_t BT4_command_t;
    
    /**
     * Values are used to easily send specific commands using the bluetooth modules
     */
//    typedef struct bt4_commands {
//        uint8_t BT_CMND_DETONATE = 0x00;
//        uint8_t BT_CMND_ARM_MANUAL = 0x01;
//        uint8_t BT_CMND_ARM_AUTO = 0x02;
//        uint8_t BT_CMND_SUCCESS = 0x03;
//        uint8_t BT_CMND_FAILURE = 0x04;
//        uint8_t BT_CMND_CONNECT = 0x05;
//        uint8_t BT_CMND_DISCONECT = 0x06;
//        uint8_t BT_CMND_IS_CONNECTED = 0x07;
//        uint8_t BT_CMND_ENTER_MLDP = 0x08;
//        uint8_t BT_CMND_HEARTBEAT = 0x09;
//        uint8_t BT_CMND_ACK = 0x0A;
//    } BT4_command_t;

#ifdef	__cplusplus
}
#endif

#endif	/* BLUETOOTH_4_COMMON_H */

