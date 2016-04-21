/**
 * @file buttons.c
 * @author Matthew Atkins
 *
 * @date Created on March 31, 2016, 12:00 AM
 */

#include "buttons.h"

void btn_init() {
    
    WHITE_LED = 0;
    YELLOW_LED = 0;
    ARM_LED = 0;
    BLUE_LED = 0;
    RED_LED = 0;
    
    delay_n_ms(20);
    
    for (uint8_t i = 0; i < 5; i++) {
        WHITE_LED = ~WHITE_LED;
        delay_n_ms(2);
        YELLOW_LED = ~YELLOW_LED;
        YELLOW_LED2 = PORTCbits.RC6;
        delay_n_ms(2);
        ARM_LED = ~ARM_LED;
        delay_n_ms(2);
        BLUE_LED = ~BLUE_LED;
        delay_n_ms(2);
        RED_LED = ~RED_LED;
        delay_n_ms(20);
    }
    delay_n_ms(20);
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
    
    uint8_t i = 10;
    uint8_t j = 0x01;
    
    while (i > 0) {
        
        if (i >= 6) {
            j <<= 1;
        } else {
            j >>= 1;
        }
        
        btn_set_LEDs(j);
        --i;
    }
    
    // If no one turns the device off we are good... Probably.
    return true;
}

void btn_set_LEDs(uint8_t val) {

    WHITE_LED = (val & 0x01) != 0 ? 1 : 0;
    YELLOW_LED = (val & 0x02) != 0 ? 1 : 0;
    ARM_LED = (val & 0x04) != 0 ? 1 : 0;
    BLUE_LED = (val & 0x08) != 0 ? 1 : 0;
    RED_LED = (val & 0x10) != 0 ? 1 : 0;
}