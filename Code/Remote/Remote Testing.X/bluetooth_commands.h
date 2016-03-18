/** 
 * @file bluetooth_commands.h
 * @author Matthew Atkins
 *
 * @date March 15, 2016, 2:49 PM
 * @warning <b>IF YOU ARE GOING TO INTERACT WITH THE BLUETOOTH MODULES, YOU _MUST_ INCLUDE THIS HEADER</b>
 */

#ifndef BLUETOOTH_COMMANDS_H
#define	BLUETOOTH_COMMANDS_H

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * The values in this enum are used to select common commands to 
     * sent via Bluetooth.
     */
    typedef enum {
        CONNECT_TO_MINE,        /**< Attempt to connect to the mine.*/
        HEARTBEAT,              /**< Send a 'heartbeat' to ensure connectivity to the mine.*/
        RANGE_TEST,             /**< Use BLE to get proximity to the mine.*/
        SET_ARM_MODE_MANUAL,    /**< Send command to set mine to manual detonation mode. */
        SET_ARM_MODE_AUTO,      /**< Send command to set mine to auto detonation mode.*/
        DETONATE                /**< Send command to detonate the mine <b>if in manual mode.<b>*/
    } bluetooth_cmnd_t;


#ifdef	__cplusplus
}
#endif

#endif	/* BLUETOOTH_COMMANDS_H */

