/* 
 * File:   mainLoop.h
 * Author: matthew
 *
 * Created on March 8, 2016, 3:20 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MAINLOOP_H
#define	MAINLOOP_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define DEBUG
    
#ifdef DEBUG
#define DEBUG_PRINT(x) printf("%s", #x)
#else
#define DEBUG_PRINT(...) do {} while (false)
#endif

    typedef enum state {
        ERROR,
        STARTING,
        IDLE,
        DISARMED,
        ARMED_REMOTE,
        ARMED_MANUAL,
        STUNED,
        DETONATED
    } State;
    
    // Properties
    bool isInitialized = false; // Is the mine ready?
    State currentState = IDLE;
    int main();
    bool initialize();
    
#ifdef	__cplusplus
}
#endif

#endif	/* MAINLOOP_H */

