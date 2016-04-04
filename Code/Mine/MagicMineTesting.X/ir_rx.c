/* 
 * @file   ir_rx.c
 * @author: Rahul Chidurala
 * @date Modified April 3, 2016, 11:52 PM
 */

#include "ir_common.h"

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


uint8_t decodeByte() 
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


void waitTillMid(void)
{
    __delay_us(cycleMid);    
}

void waitTillEnd(void)
{
    __delay_us(cycleEnd);
}