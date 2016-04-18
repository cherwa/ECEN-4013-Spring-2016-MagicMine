/**
 * @file buttons.c
 * @author Matthew Atkins
 *
 * @date Created on March 31, 2016, 12:00 AM
 */

#include "buttons.h"

void btn_init() {
    
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

    YELLOW_LED = (val & 0x01) != 0 ? 1 : 0;
    WHITE_LED = (val & 0x02) != 0 ? 1 : 0;
    ARM_LED = (val & 0x04) != 0 ? 1 : 0;
    BLUE_LED = (val & 0x08) != 0 ? 1 : 0;
    RED_LED = (val & 0x10) != 0 ? 1 : 0;
}