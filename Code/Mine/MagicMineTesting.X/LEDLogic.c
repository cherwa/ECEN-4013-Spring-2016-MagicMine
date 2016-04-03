#include "LEDLogic.h"
#include "util_functions.h"
uint8_t byte_to_test;
uint8_t bit_to_test;
uint8_t to_return;

//Sending time specific HIGH bit
static inline void LEDOne() {
   
    LED_PIN = 1;
    Nop();
    Nop();
    LED_PIN = 0;
    Nop();
}

//Sending time specific LOW bit
static inline void LEDZero() {

    LED_PIN = 1;
    Nop();
    LED_PIN = 0;
    Nop();
}

static void colorBlack() {
    //Green
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    //Red    
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
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

static void colorRed() {
    //Green
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
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

static void colorRedTwo() {
    //Green
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
    //Red
	LEDZero();
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

static void colorGreen() {
    //Green	
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
    //Red	
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
	LEDZero();
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

static void colorYellow() {
    //Green
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
	LEDOne();
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

static void colorBlue() {
    //Green
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();

    //Red
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();

    //Blue
    LEDZero();
    LEDZero();
    LEDOne();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDOne();
}

static void colorBlueTwo() {
    //Green
    LEDOne();
    LEDOne();
    LEDZero();
    LEDZero();
    LEDOne();
    LEDZero();
    LEDZero();
    LEDOne();

    //Red
    LEDZero();
    LEDOne();
    LEDOne();
    LEDZero();
    LEDZero();
    LEDOne();
    LEDOne();
    LEDZero();

    //Blue
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
}

static void colorPink() {
    //Green
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
    LEDZero();
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
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
    LEDOne();
}
void clearPattern() {
    for (int i = 0; i < 24; i++) {
        colorBlack();
    }
    
    __delay_ms (10);
}

void playDamage(){
	//Setting all 24 LED's to Red and blinking 5 times
	
    for (uint8_t i = 0; i < 24; i++) {
		colorRed();
    }
    
	delay_25ms_n_times(5);
    clearPattern();
    delay_25ms_n_times(5);
}


void playArmed(){
	
    //Setting all 24 LED's to Red and blinking rapidly
    int8_t j = 0;
    int8_t i;
    
	while (j < 5) {	
		
        for (i = 0; i < 24; i++) {
			
            if(i % 2) {
				colorRed();
			} else {
				colorRedTwo();
			}
		}
		
        delay_25ms_n_times(11);
		
        for (i = 0; i < 24; i++) {
			
            if(i % 2){
				colorRedTwo();
			} else {
				colorRed();
			}
		}	
		
        delay_25ms_n_times(11);
        
        j++;
	}
}

void playElementDamage(){
	//Alternates shades of blue, switches 4 times
    
    int8_t j = 0;
    int8_t i;
    
	while (j < 10) {	
		
        for (i = 0; i < 24; i++) {
			
            if(i % 2) {
				colorBlue();
			} else {
				colorBlueTwo();
			}
		}
		
        delay_25ms_n_times(11);
		
        for (i = 0; i < 24; i++) {
			
            if(i % 2){
				colorBlueTwo();
			} else {
				colorBlue();
			}
		}	
		
        delay_25ms_n_times(11);
        
        j++;
	}
}

void playHeal(){
	
    //Setting all 24 LED's to Green & keeping them on
    
    int8_t i;
    
	for (i = 0; i < 24; i++) {
		colorGreen();
	}
    
    delay_25ms_n_times(360);
}

void playStun() {
    
    int8_t j = 0;
    int8_t i;
    
	while (j < 10) {	
		
        for (i = 0; i < 24; i++) {
			
            if(i % 2) {
				colorRed();
			} else {
				colorYellow();
			}
		}
		
        delay_25ms_n_times(11);
		
        for (i = 0; i < 24; i++) {
			
            if(i % 2){
				colorYellow();
			} else {
				colorRed();
			}
		}	
		
        delay_25ms_n_times(11);
        
        j++;
	}
}

void playStunSelf() {
   
    int8_t i;
    for (i = 0; i < 24; i++) {
		colorYellow();
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
}

void playTestPassed() {
    int i;
    for ( i = 0; i < 6; i++) {
		colorRed();
    }
	for (i = 0; i < 6; i++) {
		colorYellow();
    }
    for (i = 0; i < 6; i++) {
		colorGreen();
    }
    for (i = 0; i < 6; i++) {
		colorBlue();
    }
    delay_25ms_n_times(200);
    
}

void playTestFailed() {
    int i;
    for (i = 0; i < 24; i++) {
		colorPink();
    }
    delay_25ms_n_times(200);	
}


// Experimental!  
void pulse(void) {
    
    int8_t pixel;
    
    for (int8_t i = 0; i < 64; i++) {
        
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

void LED_play_pattern(LED_Pattern pattern) {
    
    // Disable interrupt
    INTERRUPT_GlobalInterruptDisable();
    
    switch(pattern) {
    	case LED_DAMAGE:
            
            for (int8_t i = 0; i < 20; i++) {
                playDamage();
            }    	    
    	    break;
        case LED_ARMED:
                playArmed();
            break;
        case LED_ELEMENT_DAMAGE:
            playElementDamage();
            break;    
        case LED_HEAL:
            playHeal();
            break;
        case LED_STUN_CAST:
            playStun();
            break;
        case LED_STUN_SELF:
            for (int8_t i = 0; i < 5; i++) {
                clearPattern();
                playStunSelf();
            }
            break;
        case LED_SELF_TEST_PASSED:
            playTestPassed();
            break;
        case LED_SELF_TEST_FAILED:
            playTestFailed();
            break;
            
    }
    
    clearPattern();
    
    // Re-enable interrupts
    INTERRUPT_GlobalInterruptEnable();
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
    
    LED_PIN = 0;
}

/** @todo This function needs to be tested extensively for timing.*/

static void send_bit(int8_t val) {
    
    if (val == 0) {
        LED_PIN = 1;
        Nop();
        LED_PIN = 0;
    } else {
        LED_PIN = 1;
        Nop();
        Nop();
        LED_PIN = 0;
    }
}

int8_t bit_test(uint8_t* byte_to_test, uint8_t* bit_to_test) {
    
    return (*byte_to_test & (1 << *bit_to_test));
}

static inline int8_t isNthBitSet (const uint8_t c, const uint8_t n) {
    return ((c & mask[n]) != 0);
}
