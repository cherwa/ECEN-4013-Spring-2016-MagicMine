#include "LEDLogic.h"
#include "util_functions.h"

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

// Experimental!  
void pulse(void) {
    
    uint8_t pixel;
    
    for (uint8_t i = 0; i < 64; i++) {
        
        for (pixel = 0; pixel < PIXEL_COUNT; pixel++) {
            
            if (i == 0) {
                greenPixels[i] = 0;
                redPixels[i] = 0;
                bluePixels[i] = 0;
            } else {
                greenPixels[i] += 4;
                redPixels[i] += 4;
                bluePixels[i] += 4;
            }
        }
        
        delay_25ms_n_times(3);
    }
}

void playPattern(LED_Pattern pattern) {
    
    // Disable interrupts
    INTERRUPT_PeripheralInterruptDisable();
    
    switch(pattern) {
        case LED_DAMAGE:
            for (int i = 0; i < 4; i++) {
                playDamage();
            } 
            break;
        case LED_HEAL:
            playHeal();
            break;
        case LED_SELF_TEST_PASSED:
            pulse();
            break;
    }
    
    clearPattern();
    
    // Re-enable interrupts
    INTERRUPT_PeripheralInterruptEnable();
}

static void fill_color(uint8_t* grb) {
    
    for (uint8_t i = 0; i < PIXEL_COUNT; i++) {
        greenPixels[i] = grb[0];
        redPixels[i] = grb[1];
        bluePixels[i] = grb[2];
    }
}

static void draw(void) {
    
    uint8_t pixel;
    int8_t bitCount;
    
    for (pixel = 0; pixel < PIXEL_COUNT; pixel++) {
        
        for (bitCount = 7; bitCount >= 0; bitCount--) {
            send_bit(bit_test(greenPixels[pixel], bitCount));
        }
        
        for (bitCount = 7; bitCount >= 0; bitCount--) {
            send_bit(bit_test(redPixels[pixel], bitCount));
        }
        
        for (bitCount = 7; bitCount >= 0; bitCount--) {
            send_bit(bit_test(bluePixels[pixel], bitCount));
        }
    }
}

/** @todo This function needs to be tested extensively for timing.*/

static void send_bit(uint8_t val) {
    
    switch (val) {
        case 1:
            LED_OUT_LAT = 1;
            Nop();
            Nop();
            break;
        case 0:
            LED_OUT_LAT = 0;
            break;
    }
}