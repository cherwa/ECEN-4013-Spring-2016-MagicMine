#include "mcc_generated_files/mcc.h"
#include "Wtv020sd16p.h"
#include "util_functions.h"

//
//Wtv020sd16p::Wtv020sd16p(int resetPin,int clockPin,int dataPin,int busyPin) {
//  _resetPin=resetPin;
//  _clockPin=clockPin;
//  _dataPin=dataPin;
//  _busyPin=busyPin;
//
//}

void reset(){
  _clockPin = HIGH;
  _resetPin =  HIGH;
  //Reset pulse.
  _resetPin, LOW;
  __delay_ms (5);
  _resetPin = HIGH;
  //Reset idle to start bit. 
  _clockPin = HIGH;
  delay_25ms_n_times(12);
}

void playVoice(int voiceNumber){  
  sendCommand(voiceNumber);
  _busyPinState = PORTCbits.RC4;
  while(_busyPinState == HIGH){
    _busyPinState = PORTCbits.RC4;
  }
}

void asyncPlayVoice(int voiceNumber){
  sendCommand(voiceNumber);
}

void stopVoice(){
  sendCommand(HALT);
}

void pauseVoice(){
  sendCommand(PLAY_PAUSE);
}

void mute(){
  sendCommand(VOLUME_MIN);
}

void unmute(){
  sendCommand(VOLUME_MAX);
}

void sendCommand(unsigned int command) {
  //Start bit Low level pulse.
  _clockPin = LOW;
  __delay_ms (2);
  for (unsigned int mask = 0x8000; mask > 0; mask >>= 1) {
    //Clock low level pulse.
    _clockPin = LOW;
//    delayMicroseconds(50);
    __delay_us (50);
//    __delay_us (150);
    //Write data setup.
    if (command & mask) {
      _dataPin = HIGH;
    }
    else {
      _dataPin = LOW;
    }
    //Write data hold.
//    delayMicroseconds(50);
    __delay_us (50);
    //Clock high level pulse.
    _clockPin = HIGH;
//    delayMicroseconds(100);
    __delay_us (100);
    if (mask>0x0001){
      //Stop bit high level pulse.
      __delay_ms (2);      
    }
  }
  //Busy active high from last data bit latch.
  __delay_ms (20);
}
