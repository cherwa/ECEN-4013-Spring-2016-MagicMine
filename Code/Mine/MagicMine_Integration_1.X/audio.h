/* 
 * File:   audio.h
 * Author: Robert
 *
 * Created on March 23, 2016, 2:55 PM
 */

#ifndef AUDIO_H
#define	AUDIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#define WTV_CLOCK_LAT LATCbits.LATC0
#define WTV_DATA_LAT LATCbits.LATC1
#define PAM_SD_LAT LATCbits.LATC2
#define WTV_RESET_LAT LATCbits.LATC5
    
#include "mcc_generated_files/mcc.h"
#include "util_functions.h"
    
    typedef enum audio_files {
        AUDIO_DAMAGE_CAST = 0x0000,
        AUDIO_HEAL_CAST = 0x0001,
        AUDIO_STUN_CAST = 0x0002,
        AUDIO_STUN_HIT = 0x0003,
        AUDIO_STUN_END = 0x0004,
        AUDIO_CUSTOM_CAST = 0x0005,
        AUDIO_FIRE = 0x0006,
        AUDIO_START_UP = 0x0007,
        AUDIO_SHES_GONNA_BLOW = 0x0008,
        AUDIO_VOLUME_MUTE = 0xFFF0,
        AUDIO_VOLUME_1 = 0xFFF1,
        AUDIO_VOLUME_2 = 0xFFF2,
        AUDIO_VOLUME_3 = 0xFFF3,
        AUDIO_VOLUME_4 = 0xFFF4,
        AUDIO_VOLUME_5 = 0xFFF5,
        AUDIO_VOLUME_6 = 0xFFF6,
        AUDIO_VOLUME_MAX = 0xFFF7
    } audio_file_t;
    
    void audio_init(void);
    
    void audio_reset(void);
    void audio_send_command(uint16_t command);

#ifdef	__cplusplus
}
#endif

#endif	/* AUDIO_H */

