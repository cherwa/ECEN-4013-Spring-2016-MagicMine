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
        BT_STATE_CMD_MODE,
        BT_STATE_MLDP_MODE
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
        BT_CMND_CONNECT = 5,
        BT_CMND_DISCONECT = 6,
        BT_CMND_IS_CONNECTED = 7
    } bt_cmnd_t;
    
    typedef struct bt_packet {
        uint8_t start;  //= 0x3C;
        uint8_t func;   //= 0x00;
        uint8_t data1;  //= 0x00;
        uint8_t data2;  //= 0x00;
        uint8_t data3;  //= 0x00;
        uint8_t crc;    //= 0xFF;
    } bt_packet_t;
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_COMMON_H */

