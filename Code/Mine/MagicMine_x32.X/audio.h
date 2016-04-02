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

#include "mcc_generated_files/mcc.h"
    
    
    namespace Audio {
    
        typedef enum audio_files {
            AUDIO_DAMAGE_CAST,
            AUDIO_HEAL_CAST,
            AUDIO_STUN_CAST,
            AUDIO_STUN_HIT,
            AUDIO_STUN_END,
            AUDIO_CUSTOM_CAST
        } audio_file_t;

        void Audio::play_audio_file(audio_file_t file);

    }
#ifdef	__cplusplus
}
#endif

#endif	/* AUDIO_H */

