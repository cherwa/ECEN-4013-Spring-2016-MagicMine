/* 
 * @file   ir_tx.c
 * @author: Rahul Chidurala
 * @date Modified April 3, 2016, 11:52 PM
 */

#include "ir_common.h"

//Matt, only need to call this method, rest are internal
//@TODO did not use ir_packet struct because code already written for array
//uses the global constants of id_h,id_l, and strength to transmit MIRP
//@param spell_id   takes in 0,2, or 4 for spell id
//@return   void
void transmit_ir_packet(ir_spell_id_t spell_id)
{
    //disable interrupts
    INTCONbits.GIE = 0;
    INTCONbits.PEIE = 0;
    
    mirp[0] = id_h;
    mirp[1] = id_l;
    mirp[2] = spell_id;
    mirp[3] = str;
    mirp[4] = packet_uuid;
    mirp[5] = crc;
        
    IR_Start();
    bangBitsSoftly(mirp);
    
    //delay so packets do not overlap if called more than once
    __delay_ms(40);
    
    //enable interrupts
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}

//iterates through mirp[] array and masks each bit, then sends it in Manchester Encoding
//@param mirp[]     takes in a size 6 array and iterates through it
//@return void
void bangBitsSoftly(uint8_t mirp[])
{
    for(k_tx=0; k_tx<6; k_tx++)
    {
        selector_tx = 0b10000000;
        for(p_tx=7; p_tx>=0; --p_tx)
        {
            currentBit_tx = ((mirp[k_tx] & selector_tx) >> p_tx) ; //gets the bit
            if(currentBit_tx)
            {
                sendOne();
            }
            else
            {
                sendZero();
            }
            selector_tx = selector_tx>>1; //sets up for next bit
        }
    }
    TMR2_StopTimer();
    mirp[4] = mirp[4]+1; //increment UID
    mirp[5] = getCRC(mirp); //recalculate CRC
}

//
uint8_t getCRC(uint8_t mirp0[])
{
        num_tx = 0;
        for(k_tx=0; k_tx<5; k_tx++) //6th byte is CRC
        {
                num_tx += mirp0[k_tx];
        }
        return (0xFF - num_tx);
}

//modulates PWM at 38kHz for 15 cycles
void modulate15Cycles(void) 
{
    TMR2_StartTimer(); //turns on PWM
    __delay_us(Cycles15); //394
}

//modulates PWM at 38kHz for 30 cycles
void modulate30Cycles(void) 
{
    TMR2_StartTimer(); //turns on PWM
    __delay_us(Cycles30); //790, 800 
}

//keeps PWM low for 15 cycles
void waitLow15Cycles(void)
{
    TMR2_StopTimer(); //turns off PWM and sets output low
    __delay_us(Cycles15); //394.7 us = 15 cycles
}

//keeps PWM low for 30 cycles
void waitLow30Cycles(void)
{
    TMR2_StopTimer(); //turns off PWM and sets output low
    __delay_us(Cycles30); //790
}

//the starting MIRP protocol of 30 cycles high then 30 cycles low
void IR_Start(void)
{
    //____|----
    modulate30Cycles();  //on 30 cycles
    //____|----___
    waitLow30Cycles();  //off 30 cycles
}

//sends a Manchester Encoded bit '1' (falling edge)
void sendOne(void)
{
    modulate15Cycles();
    waitLow15Cycles();
}

//sends a Manchester Encoded bit '0' (rising edge)
void sendZero(void)
{
    waitLow15Cycles();
    modulate15Cycles();
}
