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
    
    typedef enum {
        DISCONECTED,
        CONNECTED,
        COMMAND_MODE
    } bt_device_state_t;
    
#ifdef	__cplusplus
}
#endif

#endif	/* BT_COMMON_H */

