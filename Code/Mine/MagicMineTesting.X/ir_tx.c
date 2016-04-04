/** 
 * @file   ir_tx.c
 * @author: Rahul Chidurala
 * @date Modified April 3, 2016, 11:52 PM
 */

#include "ir_common.h"

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

uint8_t getCRC(uint8_t mirp0[])
{
        num_tx = 0;
        for(k_tx=0; k_tx<5; k_tx++) //6th byte is CRC
        {
                num_tx += mirp0[k_tx];
        }
        return (0xFF - num_tx);
}


void modulate15Cycles(void) 
{
    TMR2_StartTimer(); //turns on PWM
    __delay_us(Cycles15); //394
}

void modulate30Cycles(void) 
{
    TMR2_StartTimer(); //turns on PWM
    __delay_us(Cycles30); //790, 800 
}


void waitLow15Cycles(void)
{
    TMR2_StopTimer(); //turns off PWM and sets output low
    __delay_us(Cycles15); //394.7 us = 15 cycles
}


void waitLow30Cycles(void)
{
    TMR2_StopTimer(); //turns off PWM and sets output low
    __delay_us(Cycles30); //790
}


void IR_Start(void)
{
    //____|----
    modulate30Cycles();  //on 30 cycles
    //____|----___
    waitLow30Cycles();  //off 30 cycles
}

void sendOne(void)
{
    modulate15Cycles();
    waitLow15Cycles();
}

void sendZero(void)
{
    waitLow15Cycles();
    modulate15Cycles();
}