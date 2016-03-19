#include "LEDLogic.h"
#include "mcc_generated_files/mcc.h"

static void LEDOne() {
    LED_OUT_LAT = 1;
    Nop();
    Nop();
    LED_OUT_LAT = 0;
    Nop();
}

static void LEDZero() {
    LED_OUT_LAT = 1;
    Nop();
    LED_OUT_LAT = 0;
    Nop();
}

static void colorBlack() {
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
}

static void colorRed() {
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();	
}

static void colorGreen() {
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();	
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();	
}

static void colorYellow() {
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
}	

static void colorOrange() {
    //Green
    LEDOne();
    LEDZero();
    LEDOne();
    LEDZero();
    LEDZero();
    LEDOne();
    LEDOne();
    LEDZero();

    //Red
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();

    //Blue
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
}

void clearPattern() {
    for (int i = 0; i < 24; i++) {
        colorBlack();
    }
}

void playDamage(){
	
	//Setting all 24 LED's to Red and blinking 4 times
	for (int i = 0; i < 24; i++) {
		colorRed();
	}
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);	
	
    clearPattern();
	
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);	
}

void playHeal(){

	//Setting all 24 LED's to Green & keeping them on
	for (int i = 0; i < 24; i++) {
		colorGreen();
	}
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
    __delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
    __delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
    __delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
	__delay_ms (25);	
	__delay_ms (25);
}

void playPattern(LED_Pattern pattern) {
    
    // Disable interrupts
    INTERRUPT_PeripheralInterruptDisable();
    
    switch(pattern) {
        case DAMAGE:
            for (int i = 0; i < 4; i++) {
                playDamage();
            } 
            break;
        case HEAL:
            playHeal();
            break;
    }
    
    clearPattern();
    
    // Re-enable interrupts
    INTERRUPT_PeripheralInterruptEnable();
}