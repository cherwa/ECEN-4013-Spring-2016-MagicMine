#include "LEDs.h"
#include "ir_common.h"

/**
 * Global variables
 */
near uint8_t greenPixels[PIXEL_COUNT];
near uint8_t redPixels[PIXEL_COUNT];
near uint8_t bluePixels[PIXEL_COUNT];

/**
 * Module variables
 */
//static uint8_t byte_to_test = 0;
//static uint8_t bit_to_test = 0;
static uint8_t to_return = 0;
static uint8_t bit_test_result;
near static uint8_t mask[] = {128, 64, 32, 16, 8, 4, 2, 1};

/**
 * Module functions
 */
static inline void LEDOne();
static inline void LEDZero();
near static inline void real_draw(void);

// Colors
static void colorBlack();
static void colorBlue();
static void colorBlueTwo();
static void colorGreen();
static void colorOrange();
static void colorPink();
static void colorRed();
static void colorRedTwo();
static void colorYellow();

// Patterns
static void clear_pattern();
static void play_armed();
static void play_damage();
static void play_element_damage();
static void play_heal();
static void play_stun();
static void play_stun_self();
static void play_test_failed();
static void play_test_passed();

static void play_MPU_init_success();
static void play_BT2_init_success();
static void play_BT4_init_success();

/**
* Writes a '1' or a '0' to the LED_OUT pin to the controller on the ring.
* If the value of val is greater than 0, the bit sent will a 1, otherwise
* it sends a 0.
* @param val Values > 0 indicate a '1' should be written and '0' otherwise.
* 
* @todo This function need to be tested!
*/
static inline void send_bit(int8_t val);
static inline int8_t bit_test(uint8_t byte_to_test, uint8_t bit_to_test);
static inline int8_t isNthBitSet(const uint8_t c, const uint8_t n);

/**
 * 
 *  Function definitions
 * 
 */

void LED_init() {
    
    ANSELBbits.ANSB3 = 0;
    TRISBbits.RB3 = 0;
}

// Send time specific HIGH bit
static inline void LEDOne() {
   
    LED_PIN = 1;
    Nop();
    Nop();
    LED_PIN = 0;
    Nop();
}

// Send time specific LOW bit
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

static void clear_pattern() {
    for (int i = 0; i < 24; i++) {
        colorBlack();
    }
    
    __delay_ms (10);
}

static void play_damage(){
	//Setting all 24 LED's to Red and blinking 5 times
	
    for (uint8_t i = 0; i < 24; i++) {
		colorRed();
    }
    
	delay_25ms_n_times(5);
    clear_pattern();
    delay_25ms_n_times(5);
}


static void play_armed(){
	
    //Setting all 24 LED's to Red and blinking rapidly
    int8_t j = 0;
    uint8_t i;
    
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

static void play_element_damage(){
	//Alternates shades of blue, switches 4 times
    
    int8_t j = 0;
    uint8_t i;
    
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

static void play_heal(){
	
    //Setting all 24 LED's to Green & keeping them on
    
    int8_t i;
    
	for (i = 0; i < 24; i++) {
		colorGreen();
	}
    
    delay_25ms_n_times(360);
}

static void play_stun() {
    
    int8_t j = 0;
    uint8_t i;
    
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

static void play_stun_self() {
   
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
        clear_pattern();
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

static void play_test_passed() {
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

static void play_test_failed() {
    int i;
    for (i = 0; i < 24; i++) {
		colorPink();
    }
    delay_25ms_n_times(200);	
}


// Experimental!  
void pulse(void) {
    
    uint8_t pixel;
    uint8_t i = 0;
    
    for (; i < 32; i++) {
        
        for (pixel = 0; pixel < PIXEL_COUNT; pixel++) {
            
            if (i == 0) {
                memset(greenPixels, 0x00, PIXEL_COUNT);
                memset(redPixels, 0x00, PIXEL_COUNT);
                memset(bluePixels, 0x00, PIXEL_COUNT);
            } else {
                greenPixels[pixel] += 0;
                redPixels[pixel] += 0;
                bluePixels[pixel] += 1;
            }
        }
        
        draw();
    }
}

void chase(uint8_t* grb) {
    
    greenPixels[0] = grb[0];
    redPixels[0] = grb[1];
    bluePixels[0] = grb[2];
    
    uint8_t i = 1;
    uint8_t prev_color;
    
    draw();
    delay_25ms_n_times(1);
    
    for (; i < 24; i++) {
        
        prev_color = greenPixels[i-1];
        memset(greenPixels, 0x00, PIXEL_COUNT);
        greenPixels[i] = prev_color;
        
        prev_color = redPixels[i-1];
        memset(redPixels, 0x00, PIXEL_COUNT);
        redPixels[i] = prev_color;
        
        prev_color = bluePixels[i-1];
        memset(bluePixels, 0x00, PIXEL_COUNT);
        bluePixels[i] = prev_color;
        
        draw();
        
        delay_25ms_n_times(1);
    }
}

void fading_chase(uint8_t* grb) {
    
    greenPixels[0] = grb[0];
    redPixels[0] = grb[1];
    bluePixels[0] = grb[2];
    
    uint8_t i = 1;
    uint8_t prev_color;
    
    draw();
    delay_25ms_n_times(1);
    
    for (; i < 24; i++) {
        
        prev_color = greenPixels[i-1];
        memset(greenPixels, 0x00, PIXEL_COUNT);
        greenPixels[i] = prev_color + 0x00;
        
        prev_color = redPixels[i-1];
        memset(redPixels, 0x00, PIXEL_COUNT);
        redPixels[i] = prev_color + 0x0A;
        
        prev_color = bluePixels[i-1];
        memset(bluePixels, 0x00, PIXEL_COUNT);
        bluePixels[i] = prev_color - 0x0A;
        
        draw();
        
        delay_25ms_n_times(1);
    }
}

void chase_with_background(uint8_t* grb, uint8_t* grb_back) {
    
    greenPixels[0] = grb_back[0];
    redPixels[0] = grb_back[1];
    bluePixels[0] = grb_back[2];
    
    uint8_t i = 0;
    
    for (; i < 24; i++) {
        
        memset(greenPixels, grb_back[0], PIXEL_COUNT);
        greenPixels[i] = grb[0];
        
        memset(redPixels, grb_back[1], PIXEL_COUNT);
        redPixels[i] = grb[1];
        
        memset(bluePixels, grb_back[2], PIXEL_COUNT);
        bluePixels[i] = grb[2];
        
        draw();
        
        delay_25ms_n_times(1);
    }
}

static void play_MPU_init_success() {
    
    uint8_t*  grb[3] = {0x50, 0x00, 0x50};
    fill_color(grb);
    
    uint8_t i = 0;
    
    for (; i < 24; i++) {
        
        greenPixels[i] -= 0x05;
        redPixels[i] += 0x05;
        bluePixels[i] -= 0x05;
        
        draw();
        
        delay_25ms_n_times(1);
    }
}

static void play_BT2_init_success() {
    
    uint8_t  grb[3] = {0x00, 0x00, 0x00};
    fill_color(grb);
    
    memset(bluePixels, 0xF0, 13);
    
    uint8_t i = 0;
    
    for (; i < 3; i++) {
        draw();
        delay_25ms_n_times(20);
        clear_pattern();
        delay_25ms_n_times(20);
    }
}


static void play_BT4_init_success() {
    
    uint8_t  grb[3] = {0x00, 0x00, 0xF0};
    fill_color(grb);
    
    uint8_t i = 0;
    
    for (; i < 3; i++) {
        draw();
        delay_25ms_n_times(20);
        clear_pattern();
        delay_25ms_n_times(20);
    }
}

void LED_play_pattern(LED_Pattern pattern) {
    
    // Disable interrupt
    INTERRUPT_GlobalInterruptDisable();
    
    switch(pattern) {
    	case LED_DAMAGE:
            
            for (int8_t i = 0; i < 20; i++) {
                play_damage();
            }    	    
    	    break;
        case LED_ARMED:
                play_armed();
            break;
        case LED_ELEMENT_DAMAGE:
            play_element_damage();
            break;    
        case LED_HEAL:
            play_heal();
            break;
        case LED_STUN_CAST:
            play_stun();
            break;
        case LED_STUN_SELF:
            for (int8_t i = 0; i < 5; i++) {
                clear_pattern();
                play_stun_self();
            }
            break;
        case LED_SELF_TEST_PASSED:
            play_test_passed();
            break;
        case LED_SELF_TEST_FAILED:
            play_test_failed();
            break;
        case LED_CLEAR:
            clear_pattern();
            break;
        case LED_MPU_INIT_SUCCESS:
            play_MPU_init_success();
            break;
        case LED_BT2_INIT_SUCCESS:
            play_BT2_init_success();
            break;
        case LED_BT4_INIT_SUCESS:
            play_BT4_init_success();
            break;
    }
    
    clear_pattern();
    
    // Re-enable interrupts
    INTERRUPT_GlobalInterruptEnable();
}

void random() {
    
    uint8_t i = 0;
    
    for (; i < 24; i++) {
        
        greenPixels[i] = rand() >> 9;
        redPixels[i] = rand() >> 9;
        bluePixels[i] = rand() >> 9;
    }
    
    draw();
        
    delay_25ms_n_times(1);
}

void fill_color(uint8_t* grb) {
    
    memset(greenPixels, grb[0], PIXEL_COUNT);
    memset(redPixels, grb[1], PIXEL_COUNT);
    memset(bluePixels, grb[2], PIXEL_COUNT);
}

void draw(void) {
    real_draw();
}

near static inline void real_draw() {
    near int8_t pixel = 0;
    near uint8_t bitCount;
    
    for (pixel; pixel < PIXEL_COUNT; pixel++) {
        
        for (bitCount = 128; bitCount != 0; bitCount >>= 1) {
//            send_bit(bit_test(&greenPixels[pixel], &bitCount));
            greenPixels[pixel] & bitCount ? LEDOne() : LEDZero();
        }
        
        for (bitCount = 128; bitCount != 0; bitCount >>= 1) {
//            send_bit(isNthBitSet(&redPixels[pixel], &bitCount));
             redPixels[pixel] & bitCount ? LEDOne() : LEDZero();
        }
        
        for (bitCount = 128; bitCount != 0; bitCount >>= 1) {
//            send_bit(isNthBitSet(&bluePixels[pixel], &bitCount));
             bluePixels[pixel] & bitCount ? LEDOne() : LEDZero();
        }
    }
    
    LED_PIN = 0;
}

/** @todo This function needs to be tested extensively for timing.*/

static inline void send_bit(int8_t val) {
    
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

static inline int8_t bit_test(uint8_t byte_to_test, uint8_t bit_to_test) {
    
    return (byte_to_test & (1 << bit_to_test));
}

static inline int8_t isNthBitSet (const uint8_t c, const uint8_t n) {
    return ((c & mask[n]) != 0);
}
