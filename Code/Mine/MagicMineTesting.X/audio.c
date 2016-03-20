/**
 * @file audio.c
 * @author Matthew Atkins
 * @date Created on March 19, 2016, 6:03 PM
 */

#include "audio.h"
#include "ir_common.h"

void play_audio_file(audio_file_t file) {
 
    ///@todo Actually play the file
    
    switch (file) {
        case AUDIO_DAMAGE_CAST:
            break;
        case AUDIO_HEAL_CAST:
            break;
        case AUDIO_STUN_CAST:
            break;
        case AUDIO_STUN_HIT:
            break;
        case AUDIO_STUN_END:
            break;
        case AUDIO_CUSTOM_CAST:
            break;
        default:
            break;
    }
}