/* 
 * File:   bluetooth_2.h
 * Author: Matthew Atkins
 *
 * Created on April 6, 2016, 10:23 PM
 */

#ifndef BLUETOOTH_2_H
#define	BLUETOOTH_2_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include <string.h>
    
#define BT2_MINE_MAC "0006667C62F5"
#define BT2_PIU_MAC "98D3318060F1"
    
    struct BT_MAGE_packet_t {
        uint8_t function;
        uint8_t data1;
        uint8_t data2;
        uint8_t data3;
        uint8_t crc;
    };
    
    extern bool BT2_is_connected;
    extern struct BT_MAGE_packet_t BT2_packet;

    void BT2_init();
    
    bool BT2_send_packet();
    
    bool BT2_send_heartbeat();
    
    void BT2_read_response();

#ifdef	__cplusplus
}
#endif

#endif	/* BLUETOOTH_2_H */

