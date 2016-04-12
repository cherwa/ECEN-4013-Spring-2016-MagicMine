/* 
 * File:   bluetooth_4.h
 * Author: Matthew Atkins
 *
 * Created on April 7, 2016, 4:08 AM
 */

#ifndef BLUETOOTH_4_H
#define	BLUETOOTH_4_H

/** @todo remove this after configuring the pins! */
#define BT4_CMND_LAT LATBbits.LATB1

#define BT_MINE_MAC "001EC030D541"
#define BT_REMOTE_MAC "001EC030D557"

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
#include "bluetooth_4_common.h"
    
    extern int BT4_average_rssi;
    
    extern BT4_device_state_t BT4_device_state;
    
    extern bool BT4_is_connected;
    
    void BT4_init();
    
    bool BT4_enter_command_mode();
    
    void BT4_send_command(BT4_command_t cmnd);
    
    void BT4_read_to_buffer();
    
    bool BT4_get_RSSI();
        
    void BT4_process_packet();

#ifdef	__cplusplus
}
#endif

#endif	/* BLUETOOTH_4_H */

