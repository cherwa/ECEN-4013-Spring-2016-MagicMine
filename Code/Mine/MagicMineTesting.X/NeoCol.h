#include "mcc_generated_files/mcc.h"
//#device ADC = 16

//#FUSES NOWDT                    //No Watch Dog Timer
//#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
//#FUSES NOBROWNOUT               //No brownout reset
//#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
//#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)

//#use delay(clock=8000000,crystal=20000000)

#define bit_test(var, pos) ((var) & (1<<(pos)))
#define output_high LATBbits.LATB1 = 0
#define output_low LATBbits.LATB1 = 0

#define NeoPin LATBbits.LATB1
#define NeoNum 24
#define RAND_MAX 64
#define ALL_OUT 0x00
#define ALL_IN  0xFF
//#byte PORTA = 0xF80
//typedef bool int1;

extern void neoMain();