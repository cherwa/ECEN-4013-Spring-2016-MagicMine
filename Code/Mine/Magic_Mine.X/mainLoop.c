#include "mainLoop.h"

int main() {
    
    // Initialize the mine to the start state
    if ( initialize() ) {
        
        DEBUG_PRINT("Initialization Successful!");
        isInitialized = true;
        
        
        
    } else {
        DEBUG_PRINT("Initialization Failed!");
    }
    
    return 0;
}

bool initialize() {
    
    if (isInitialized) {
        return true;
    }
    
    currentState = STARTING;
    
    return true;
}