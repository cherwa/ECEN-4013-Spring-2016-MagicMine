/**
 * @file buttons.c
 * @author Matthew Atkins
 *
 * @date Created on March 31, 2016, 12:00 AM
 */

#include "buttons.h"

bool btn_test_spell_btns(void) {
    
    btn_set_LEDs (0x0F);
    
    delay_n_ms(20);
    btn_set_LEDs (0x00);
    
    delay_n_ms(10);
    btn_set_LEDs (0x0F);
    
    delay_n_ms(20);
    btn_set_LEDs (0x00);
    
    delay_n_ms(10);
    btn_set_LEDs(0x0F);
    
    delay_n_ms(20);
    btn_set_LEDs (0x00);
    
    // If no one turns the device off we are good... Probably.
    return true;
}

bool btn_test_LEDs(void) {
    
    /** @todo Actually test the LEDs */
    
    return true;
}

void btn_set_LEDs(uint8_t val) {
    
    //WHITE_LED_LAT = val & 0x08;
    //BLUE_LED_LAT = val & 0x04;
    //YELLOW_LED_LAT = val & 0x02;
    //RED_LED_LAT = val & 0x01;
}