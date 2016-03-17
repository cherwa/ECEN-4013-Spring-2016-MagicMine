/* 
 * File:   bluetooth_commands.h
 * Author: matthew
 *
 * Created on March 15, 2016, 2:49 PM
 */

#ifndef BLUETOOTH_COMMANDS_H
#define	BLUETOOTH_COMMANDS_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum {
        CONNECT_TO_MINE,
        HEARTBEAT,
        RANGE_TEST,
        SET_ARM_MODE,
        DETONATE
    } bluetooth_cmnd_t;


#ifdef	__cplusplus
}
#endif

#endif	/* BLUETOOTH_COMMANDS_H */

