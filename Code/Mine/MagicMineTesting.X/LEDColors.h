/* 
 * File:   LEDColors.h
 * Author: matthew
 *
 * Created on March 9, 2016, 10:02 PM
 */

#ifndef LEDCOLORS_H
#define	LEDCOLORS_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum patterns {
        DAMAGE,
        HEAL
    } LED_Pattern;
    
    void playPattern(LED_Pattern pattern);
    
    int counter = 0;

#ifdef	__cplusplus
}
#endif

#endif	/* LEDCOLORS_H */

