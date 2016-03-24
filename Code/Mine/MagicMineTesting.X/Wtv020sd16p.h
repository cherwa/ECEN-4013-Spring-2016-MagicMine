/* 
 * File:   Wtv020sd16p.h
 * Author: Matthew Atkins
 *
 * Created on March 22, 2016, 7:15 AM
 */

#ifndef WTV020SD16P_H
#define	WTV020SD16P_H

#ifdef	__cplusplus
extern "C" {
#endif

#define _resetPin LATC2
#define _clockPin LATC3
#define _dataPin LATC5
#define _busyPin LATC4
    
    uint16_t PLAY_PAUSE = 0xFFFE;
    uint16_t HALT = 0xFFFF;
    uint16_t VOLUME_MIN = 0xFFF0;
    uint16_t VOLUME_MAX = 0xFFF7;
    
//    Wtv020sd16p(int resetPin,int clockPin,int dataPin,int busyPin);
    void reset();
    void playVoice(int voiceNumber);
    void asyncPlayVoice(int voiceNumber);
    void stopVoice();
    void pauseVoice();
    void mute();
    void unmute();

    void sendCommand(unsigned int command);
    int _busyPinState = HIGH;

#ifdef	__cplusplus
}
#endif

#endif	/* WTV020SD16P_H */

