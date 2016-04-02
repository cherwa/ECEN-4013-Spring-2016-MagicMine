#include "ir_common.h"
#define Cycles15 390UL//394UL
#define Cycles30 780UL//780UL

uint8_t num = 0;
int length = 47; //one less than the bits for forloop
int i=0,j=0,k=0,p=0,counter=0;
bool previousBit, nextBit;
uint8_t selector = 0b10000000;
uint8_t mirp0[6];

void IR_Start(void)
{
    /*
    //----__----__
    modulate30Cycles();  //on 30 cycles

    waitLow15Cycles();  //off 15 cycles

    modulate30Cycles();  //on 30 cycles
    
    waitLow15Cycles();  //off 15 cycles
    */
    
    //----___
    modulate30Cycles();  //on 30 cycles

    waitLow30Cycles();  //off 30 cycles
    
}



uint8_t getCRC(uint8_t mirp0[])
{
        num = 0;
        for(k=0; k<5; k++) //6th byte is CRC
        {
                num += mirp0[k];
        }
        return (0xFF - num);
}

void getBitStream(uint8_t mirp0[], bool toTransmit[])
{
    counter = 0;
    for(k=0; k<6; k++)
    {
        selector = 0b10000000;
        for(p=7; p>=0; --p)
        {
            toTransmit[counter] = ((mirp0[k] & selector) >> p) ; //gets the bit
            selector = selector>>1; //sets up for next bit
        }
    }
}

bool currentBit;
void bangBitsSoftly(uint8_t mirp[])
{
    counter = 0;
    for(k=0; k<6; k++)
    {
        selector = 0b10000000;
        for(p=7; p>=0; --p)
        {
            currentBit = ((mirp0[k] & selector) >> p) ; //gets the bit
            if(currentBit)
            {
                sendOne();
            }
            else
            {
                sendZero();
            }
            selector = selector>>1; //sets up for next bit
        }
    }
    TMR2_StopTimer();
    mirp[4] = mirp[4]++; //increment UID
    mirp[5] = getCRC(mirp); //recalculate CRC
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

void bangBitsHard(uint8_t mirp0[], bool toTransmit[])
{
    if(toTransmit[0] == 1)
    {
        //start bit ends with a low
        //__--
        waitLow15Cycles(); //15 cycles which is midpoint of cycle
        //turn high here after 15 cycles!
        modulate15Cycles();
    }
    else
    {
        //__----__
        //turn high here
        modulate15Cycles(); //wait 15 cycles
        //turn off here
        waitLow15Cycles();
    }
   
    for(i=1; i<length; i++)
    {
        previousBit = toTransmit[i-1];
        nextBit = toTransmit[i];
        //if(previousBit == 0 && nextBit == 0)
        if(!previousBit && !nextBit)
        {
            //__--__--
            waitLow15Cycles(); //394.7 us is 15 cycles which is midpoint of cycle
            modulate15Cycles();
        }
        //else if(previousBit == 0 && nextBit == 1)
        else if(!previousBit && nextBit)
        {
            //__----__
            modulate15Cycles(); 
            //modulate_us(370); //less modulation 
            waitLow15Cycles();
        }
        //else if(previousBit == 1 && nextBit == 0)
        else if(previousBit && !nextBit)
        {
            //--____--
            waitLow15Cycles();
            modulate15Cycles(); 
 
        }
//        else if(previousBit == 1 && nextBit == 1)
        else
        {
            //--__--__
            modulate15Cycles();
            waitLow15Cycles();
        }
    }

    //for last bit
    previousBit = toTransmit[46];
    nextBit = toTransmit[47];
    if(previousBit == 0 && nextBit == 0)
    {
        //__--__--
        waitLow15Cycles();
        modulate15Cycles();
    }
    else if(previousBit == 0 && nextBit == 1)
    {
        //__----__
        modulate15Cycles();
        waitLow15Cycles();
    }
    else if(previousBit == 1 && nextBit == 0)
    {
        //--____--
        waitLow15Cycles();
        modulate15Cycles();

    }
    else if(previousBit == 1 && nextBit == 1)
    {
        //--__--__
        modulate15Cycles();
        waitLow15Cycles();
    }

    //end it by setting PWM off
    TMR2_StopTimer();
    mirp0[4] = mirp0[4]++; //increment UID
    mirp0[5] = getCRC(mirp0); //recalculate CRC
    
    getBitStream(mirp0,toTransmit); //recalculate bit stream
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

int b=0;
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

void waitLow_us(int time)
{
    TMR2_StopTimer(); //turns off PWM and sets output low
    __delay_us(time); //790
}

void modulate_us(int time)
{
    TMR2_StartTimer(); //turns on PWM
    __delay_us(time); //790, 800 
}

int a=0;
void wait1Sec(void)
{
    for(a=0; a<20; a++)
    {
        __delay_ms(20);
    }
}