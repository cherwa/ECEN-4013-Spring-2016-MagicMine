/* 
 * File:   main.h
 * Author: Matthew Atkins
 *
 * Created on April 6, 2016, 10:34 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>
#include "bluetooth_2.h"
#include "bluetooth_4.h"
#include "LEDs.h"
#include "ir_common.h"
#include "accel.h"
#include "audio.h"
    
    typedef enum {
        DEVICE_STATE_INIT,
        DEVICE_STATE_UNARMED,
        DEVICE_STATE_ARMED_AUTO,
        DEVICE_STATE_ARMED_MANUAL,
        DEVICE_STATE_STUNNED
    } mine_state_t;
    
    extern volatile mine_state_t current_state;
    
    extern volatile uint8_t selected_spell;
    
    extern volatile uint8_t arm_indicator_counter;
    
    void arm_device(const mine_state_t arm_mode, const uint8_t sel_spell);
    
    void detonate_device();
    
    void stun_device();
    
#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

