#include "LEDLogic.h"

uint8_t byte_to_test;
uint8_t bit_to_test;
uint8_t to_return;

void delay_25ms_n_times(uint16_t n) {

    for (n; n > 1; n--) {
        __delay_ms (25);
    }
        __delay_ms (25);
}
    
static inline void LEDOne() {
    LATBbits.LATB5 = 1;   
    Nop();
    Nop();
    LATBbits.LATB5 = 0;
    Nop();
}

static inline void LEDZero() {
    LATBbits.LATB5 = 1;
    Nop();
    LATBbits.LATB5 = 0;
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
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    
}

void playHeal(){

	//Setting all 24 LED's to Green & keeping them on
	for (int i = 0; i < 24; i++) {
		colorGreen();
	}
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    
}

void playStun(void) {
    
    int i;
    
    for (i = 0; i < 12; i++) {
        colorYellow();
    }
    
    for (i = 0; i < 12; i++) {
        colorGreen();
    }
    
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
    __delay_ms(25);
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
        
        draw();
        delay_25ms_n_times(3);
    }
}

void playPattern(LED_Pattern pattern) {
    
    // Disable interrupts
//    PIE4bits.CCP4IE = 0;
    
    switch(pattern) {
        case LED_DAMAGE:
            playDamage();
            break;
        case LED_HEAL:
            playHeal();
            break;
        case LED_STUN_CAST:
            playStun();
            break;
        case LED_SELF_TEST_PASSED:
            pulse();
            break;
    }
    
    clearPattern();
    
    // Re-enable interrupts
//    PIE4bits.CCP4IE = 1;
}

void fill_color(uint8_t grb[]) {
    
    for (uint8_t i = 0; i < PIXEL_COUNT; i++) {
        greenPixels[i] = grb[0];
        redPixels[i] = grb[1];
        bluePixels[i] = grb[2];
    }
}

void draw(void) {
    
    uint8_t pixel;
    int8_t bitCount;
    
    for (pixel = 0; pixel < PIXEL_COUNT; pixel++) {
        
        for (bitCount = 7; bitCount >= 0; bitCount--) {
//            send_bit(isNthBitSet(greenPixels[pixel], 7));
//            send_bit(isNthBitSet(greenPixels[pixel], 6));
//            send_bit(isNthBitSet(greenPixels[pixel], 5));
//            send_bit(isNthBitSet(greenPixels[pixel], 4));
//            send_bit(isNthBitSet(greenPixels[pixel], 3));
//            send_bit(isNthBitSet(greenPixels[pixel], 2));
//            send_bit(isNthBitSet(greenPixels[pixel], 1));
//            send_bit(isNthBitSet(greenPixels[pixel], 0));
//            send_bit(0);
//            send_bit(bit_test(&greenPixels[pixel], &bitCount));
        }
        
        for (bitCount = 7; bitCount >= 0; bitCount--) {
//            send_bit(isNthBitSet(redPixels[pixel], 7));
//            send_bit(isNthBitSet(redPixels[pixel], 6));
//            send_bit(isNthBitSet(redPixels[pixel], 5));
//            send_bit(isNthBitSet(redPixels[pixel], 4));
//            send_bit(isNthBitSet(redPixels[pixel], 3));
//            send_bit(isNthBitSet(redPixels[pixel], 2));
//            send_bit(isNthBitSet(redPixels[pixel], 1));
//            send_bit(isNthBitSet(redPixels[pixel], 0));
//            send_bit(0);
//            send_bit(isNthBitSet(&redPixels[pixel], &bitCount));
        }
        
        for (bitCount = 7; bitCount >= 0; bitCount--) {
//            send_bit(isNthBitSet(bluePixels[pixel], 7));
//            send_bit(isNthBitSet(bluePixels[pixel], 6));
//            send_bit(isNthBitSet(bluePixels[pixel], 5));
//            send_bit(isNthBitSet(bluePixels[pixel], 4));
//            send_bit(isNthBitSet(bluePixels[pixel], 3));
//            send_bit(isNthBitSet(bluePixels[pixel], 2));
//            send_bit(isNthBitSet(bluePixels[pixel], 1));
//            send_bit(isNthBitSet(bluePixels[pixel], 0));
//            send_bit(2);
//            send_bit(isNthBitSet(&bluePixels[pixel], &bitCount));
        }
    }
    
    LATBbits.LATB5 = 0;
}

/** @todo This function needs to be tested extensively for timing.*/

static void send_bit(int8_t val) {
    
    if (val == 0) {
        LATBbits.LATB5 = 1;
        Nop();
        LATBbits.LATB5 = 0;
    } else {
        LATBbits.LATB5 = 1;
        Nop();
        Nop();
        LATBbits.LATB5 = 0;
    }
}

int8_t bit_test(uint8_t* byte_to_test, uint8_t* bit_to_test) {
    
    return (*byte_to_test & (1 << *bit_to_test));
}

static inline int8_t isNthBitSet (const uint8_t c, const uint8_t n) {
    return ((c & mask[n]) != 0);
}
