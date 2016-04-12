/** 
 * @file buttons.h
 * @author Matthew Atkins
 *
 * @date Created on March 30, 2016, 11:58 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "remote_main.h"
    
    void btn_init();
    
    bool btn_test_spell_btns(); /**< Tests the spell buttons by flashing them 3 times.*/
    
    bool btn_test_LEDs(); /**< Tests the indicator LEDs by flashing them 3 times.*/
    
    void btn_set_LEDs(uint8_t val);
    
#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */

