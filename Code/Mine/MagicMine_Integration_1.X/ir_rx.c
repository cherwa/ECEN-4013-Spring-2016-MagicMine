/* 
 * @file   ir_rx.c
 * @author: Rahul Chidurala
 * @date Modified April 3, 2016, 11:52 PM
 */

#include "ir_common.h"

uint8_t IDH, IDL,SPELL, STR, UID, CRC;
bool validMIRP_rx = false;

bool decode(void)
{
    validMIRP_rx = 0;
    if(!PORTBbits.RB5)
    {
        if(checkStart()) 
        {
            /*mirpRx.id_h = decodeByte();
            mirpRx.id_l = decodeByte();
            mirpRx.spell_id = decodeByte();
            mirpRx.str = decodeByte();
            mirpRx.uuid = decodeByte();
            mirpRx.crc = decodeByte();*/
            /*mirp[0] = decodeByte(); //id_h
            mirp[1] = decodeByte(); //id_l
            mirp[2] = decodeByte(); //spell
            mirp[3] = decodeByte(); //str
            mirp[4] = decodeByte(); //uuid
            mirp[5] = decodeByte(); //crc*/
            IDH = decodeByte();
            IDL = decodeByte();
            SPELL = decodeByte();
            STR = decodeByte();
            UID = decodeByte();
            CRC = decodeByte();
        }
        validMIRP_rx = checkCRC();
    }
    counter_rx = 0; //move this out here
    return validMIRP_rx;
}


uint8_t decodeByte() 
{
    counter_rx = 0;
    decodedByte_rx = 0;
    while(counter_rx < 8)
    {
        __delay_us(585);
        if(PORTBbits.RB5 == 1)
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
    if(PORTBbits.RB5 == 0)
    {
        waitTillEnd();//__delay_us(cycleEnd);
        waitTillMid();//__delay_us(cycleMid);

        if(PORTBbits.RB5 == 1)
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
    calculatedCRC_rx = (0xFF - (IDH+IDL+SPELL+STR+UID));//(0xFF - (mirp[0]+mirp[1]+mirp[2]+mirp[3]+mirp[4]));//(0xFF - (mirpRx.id_h+mirpRx.id_l+mirpRx.spell_id+mirpRx.str+mirpRx.uuid));
    if(calculatedCRC_rx == CRC)//mirp[5])//mirpRx.crc)
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