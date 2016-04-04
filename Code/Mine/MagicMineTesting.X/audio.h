/**
 * @file audio.h
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 5:54 PM
 */

#ifndef AUDIO_H
#define	AUDIO_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define AUDIO_PAM_SD LATBbits.LATB0;
    
#include "mcc_generated_files/mcc.h"
    
    typedef enum audio_files {
        AUDIO_DAMAGE_CAST = 0x0000,
        AUDIO_HEAL_CAST = 0x0001,
        AUDIO_STUN_CAST = 0x0002,
        AUDIO_STUN_HIT = 0x0003,
        AUDIO_STUN_END = 0x0004,
        AUDIO_CUSTOM_CAST = 0x0005
    } audio_file_t;
    
    void audio_init(void);
    
    void audio_play(audio_file_t file);
    
#ifdef	__cplusplus
}
#endif

#endif	/* AUDIO_H */

