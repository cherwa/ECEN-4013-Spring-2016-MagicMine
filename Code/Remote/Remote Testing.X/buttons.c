/**
 * @file buttons.c
 * @author Matthew Atkins
 *
 * @date Created on March 31, 2016, 12:00 AM
 */

#include "buttons.h"

void btn_init() {
    
//    ANSELAbits.ANSA0 = 0;
//    ANSELAbits.ANSA1 = 0;
//    ANSELAbits.ANSA2 = 0;
//    ANSELCbits.ANSC0 = 0;
//    ANSELCbits.ANSC1 = 0;
//    
//    TRISAbits.TRISA0 = 0;
//    TRISAbits.TRISA1 = 0;
//    TRISAbits.TRISA2 = 0;
//    TRISCbits.TRISC0 = 0;
//    TRISCbits.TRISC1 = 0;
    
    YELLOW_LED = 1;
    WHITE_LED = 1;
    ARM_LED = 0;
    BLUE_LED = 1;
    RED_LED = 1;
}

bool btn_test_spell_btns(void) {
    
//    btn_set_LEDs (0x0F);
//    
//    delay_n_ms(20);
//    btn_set_LEDs (0x00);
//    
//    delay_n_ms(10);
//    btn_set_LEDs (0x0F);
//    
//    delay_n_ms(20);
//    btn_set_LEDs (0x00);
//    
//    delay_n_ms(10);
//    btn_set_LEDs(0x0F);
//    
//    delay_n_ms(20);
//    btn_set_LEDs (0x00);
    
    uint8_t i = 0x10;
    
    btn_set_LEDs(0xFF);
    
    // If no one turns the device off we are good... Probably.
    return true;
}

bool btn_test_LEDs(void) {
    
    /** @todo Actually test the LEDs */
    
    return true;
}

void btn_set_LEDs(uint8_t val) {
    
    
    LATAbits.LATA0 = (val & 0x01) != 0 ? 1 : 0;
    LATAbits.LATA1 = (val & 0x02) != 0 ? 1 : 0;
    LATAbits.LATA2 = (val & 0x04) != 0 ? 1 : 0;
    LATCbits.LATC0 = (val & 0x08) != 0 ? 1 : 0;
    LATCbits.LATC2 = (val & 0x10) != 0 ? 1 : 0;
}