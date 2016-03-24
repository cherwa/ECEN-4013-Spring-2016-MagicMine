/** 
 * @file   bt_to_PIU.h
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 12:46 AM
 */

#ifndef BT_TO_PIU_H
#define	BT_TO_PIU_H

#define PIU_BT_FUNC_HEARTBEAT 0x00
#define PIU_BT_FUNC_CONNECT 0x01
#define PIU_BT_FUNC_IR_TX 0x02
#define PIU_BT_FUNC_UPDATE 0x03
#define PIU_BT_FUNC_ACK 0xFF

#define PIU_COLOR_RED 0x00
#define PIU_COLOR_ORANGE 0x01
#define PIU_COLOR_YELLOW 0x02
#define PIU_COLOR_GREEN 0x03
#define PIU_COLOR_CYAN 0x04
#define PIU_COLOR_BLUE 0x05
#define PIU_COLOR_PURPLE 0x06
#define PIU_COLOR_WHITE 0x07
#define PIU_COLOR_BLACK 0xFF

#define PIU_BT_MAC 0x0006667C62F5
#define PIU_BT_PIU_MAC 0x98D3318060F1

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "bt_common.h"
    
    static uint8_t piu_buff[13];
    
    static bt_device_state_t piu_bt_state = BT_STATE_DISCONECTED;
    
    /**
     * Call this function to clear the data buffer. This is not called after reading
     * data using [PIU_bt_read_cmnd_to_buffer](@ref PIU_bt_read_cmnd_to_buffer), and must
     * be called before the next command is read in or there may be lingering data from
     * the last read.
     */
    static inline void PIU_bt_clear_data_buff(void);
    
    /**
     * Enter command mode on the PIU module for any configuration needed.
     * @return true if the module was able to enter command mode, false otherwise.
     */
    bool PIU_bt_enter_command_mode(void);
    
    /**
     * Exit command mode on the PIU module.
     * @return true if we exited from command mode and false otherwise.
     */
    bool PIU_bt_exit_command_mode(void);
    
    /**
     * Send a command 
     * @param cmnd The [bt_cmnd_t](@ref bt_cmnd_t) to send over the PIU Bluetooth
     * interface.
     */
    void PIU_bt_send_command(bt_cmnd_t cmnd);
    
    /**
     * Returns the current state of the Bluetooth device.
     * @return The device state as a [bt_device_state_t](@ref bt_device_state_t) type.
     */
    bt_device_state_t PIU_bt_get_device_state(void);
    
    /**
     * Send the configured Bluetooth packet to the PIU interface.
     * @param packet The packet to send.
     * @warning Make sure that you have configured the fields of the [packet](@ref bt_packet_t)
     * before you send it!
     */
    void PIU_bt_transmit_packet(bt_packet_t packet);
    
    /**
     * Attempts to read the result of a command send to the microcontroller.
     * @param size_to_read The number of bytes to read from the UART module.
     * @warning This function will block until size_to_read bytes have been read.
     * This will be fixed at a later date to time out.
     */
    void PIU_bt_read_cmnd_to_buffer(uint8_t size_to_read);
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_TO_PIU_H */

