#include "audio.h"

void audio_init() {

    ANSELCbits.ANSC2 = 0;
    ANSELCbits.ANSC5 = 0;
    TRISCbits.RC0 = 0;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    TRISCbits.RC5 = 0;
    
    audio_reset();
    delay_25ms_n_times (80);
    audio_send_command(AUDIO_VOLUME_4);
}

/**
 * software reset? or maybe before each command is sent
 * 
 */
void audio_reset(void)
{
   PAM_SD_LAT = 1;
   WTV_CLOCK_LAT = 0;
   WTV_RESET_LAT = 1;
   
   WTV_RESET_LAT = 0;
   __delay_ms(5);
   
   WTV_DATA_LAT = 1;
   WTV_CLOCK_LAT = 1;
   WTV_RESET_LAT = 1;
}

/**
 * Bit Bang serial data using Dclk and Din
 * clock low 2ms, mask used to examine each bit in command using bitwise AND
 * 50us setup time, data bit, 50us hold time, rising clock edge, 100us second 
 * half of clock cycle, cannot compare unsigned int to zero so check if mask has
 * finished all 16 bits, 2ms delay prior
 * to each data bit, finish with clock idle high 20ms
 * clock period is 2.2ms
 * 
 * @param command 16 bit command or voice file address
 */
void audio_send_command(uint16_t command)
{   
    
    uint16_t mask = 0x8000;
    // beginning of data/clock period
    WTV_CLOCK_LAT = 0;
    __delay_ms(2);
    
    // loop 16 times for each bit in command
    for(mask; mask > 0; mask >>=1)
    {
        // clock low and setup time
        WTV_CLOCK_LAT = 0;
        __delay_us(50);
        
        // data bit and hold time
        if(command & mask)
        {
            WTV_DATA_LAT = 1;
        }
        else
        {
            WTV_DATA_LAT = 0;
        }
        __delay_us(50);
       
        
        //clock rising edge and second half of period
        WTV_CLOCK_LAT = 1;
        __delay_us(100);
        
        //mask empty
        if(mask > 0x0001)
        {
            WTV_CLOCK_LAT = 0;
            __delay_ms(2);
        }
    }
    
}
