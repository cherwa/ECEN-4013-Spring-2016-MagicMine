/* 
 * @file   ir_rx.c
 * @author: Rahul Chidurala
 * @date Modified April 3, 2016, 11:52 PM
 */

#include "ir_common.h"

/*
 * example usage, put the decode() in a Interrupt On Change or Interrupt on Falling Edge ISR
 * void PIN_MANAGER_IOC(void) {
    if ((IOCB4 == 1) && (RBIF == 1)) {
        //@TODO Add handling code for IOC on pin RB4
        INTCONbits.GIE = 0;
        INTCONbits.PEIE = 0;
        decode();
        // clear interrupt-on-change flag
        RBIF = 0;
        counter = 0;
        INTCONbits.GIE = 1;
        INTCONbits.PEIE = 1;
    }
    
}
 * 
 */

//decodes received IR packet
//The decoded MIRP is in the struct instance of ir_packet, mirpRx
//@return   true if validMIRP
bool decode(void)
{
    validMIRP_rx = 0;
    if(checkStart())
    {
        if(!PORTBbits.RB4)
        {
            if(checkStart()) 
            {
                mirpRx.id_h = decodeByte();
                mirpRx.id_l = decodeByte();
                mirpRx.spell_id = decodeByte();
                mirpRx.str = decodeByte();
                mirpRx.uuid = decodeByte();
                mirpRx.crc = decodeByte();
            }
            validMIRP_rx = checkCRC();
            counter_rx = 0;
        }
    }
    else //just added this
    {
        __delay_ms(39); //wait out rest of packet
    }
    return validMIRP_rx;
}


//@return   returns the decoded byte of MIRP packet
uint8_t decodeByte() //uses shorter delays than IR START to compensate 
{
    counter_rx = 0;
    decodedByte_rx = 0;
    while(counter_rx < 8)
    {
        __delay_us(585);
        if(PORTBbits.RB4 == 1)
        {
            decodedByte_rx |= (0x80 >> ((counter_rx%8)));//(0x01 << (0x08-(counter%8)));
        }
        else
        {
            decodedByte_rx &= (0xFF ^ (0x80 >> (counter_rx%8)));//(0x01 << (0x08-(counter%8)));
        }
        counter_rx++;
        __delay_us(190);
    }
    return decodedByte_rx;
}

//@return   true if start is valid
bool checkStart(void)
{
    waitTillMid();//__delay_us(cycleMid);
    if(PORTBbits.RB4 == 0)
    {
        waitTillEnd();//__delay_us(cycleEnd);
        waitTillMid();//__delay_us(cycleMid);

        if(PORTBbits.RB4 == 1)
        {
            waitTillEnd();//__delay_us(cycleEnd);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

//@return   true if CRC calculated is correct
bool checkCRC()
{
    calculatedCRC_rx = (0xFF - (mirpRx.id_h+mirpRx.id_l+mirpRx.spell_id+mirpRx.str+mirpRx.uuid));
    if(calculatedCRC_rx == mirpRx.crc)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//waits till middle of MIRP encoding to sample
void waitTillMid(void)
{
    __delay_us(cycleMid);    
}

//waits till end of MIRP encoding
void waitTillEnd(void)
{
    __delay_us(cycleEnd);
}