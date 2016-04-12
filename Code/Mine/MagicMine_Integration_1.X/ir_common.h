/* 
 * @file   ir_common.h
 * @author: Matthew Atkins
 * @date Created on March 19, 2016, 5:21 PM
 * @author: Rahul Chidurala
 * @date Modified April 3, 2016, 10:21 PM
 */
#ifndef IR_COMMON_H
#define	IR_COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"

#define Cycles15 390UL//394UL//390UL reduced delay by 5 us to get better mirp
#define Cycles30 785UL//789UL//780UL
#define cycleMid 589L//591L//587L //591, use 5 less
#define cycleEnd 195L//197L//183L//192L //197, use 5 less

    //Need CCP4 on Pin 21!!!
    //pwm4.c needed
    
    typedef enum spell_type {
        IR_SPELL_DAMAGE = 0,
        IR_SPELL_STUN = 2,
        IR_SPELL_HEAL = 4
    } ir_spell_id_t;

    /**
     * Struct that represents a single packet of IR data.
     * It is used by the [transmit_ir_packet](@ref transmit_ir_packet) function
     * to configure the data to transmit completely prior to sending it. This
     * helps to avoid sending a bad packet while waiting on data to become
     * available.
     */
    //UNUSED, might implement later -Rahul
    struct ir_packet {
        uint8_t id_h;     /**< The hight byte of the packet id number.*/
        uint8_t id_l;     /**< The low byte of the packet id number.*/
        uint8_t spell_id; /**< The spell id, should be one of the values from the [spell_type](@ref spell_type) enum.*/
        uint8_t str;      /**< The strength of the spell */
        uint8_t uuid;     /**< The UUID for this packet. */
        uint8_t crc;      /**< The CRC checksum value. This is computed from the other fileds and <b>SHOLD NOT</b> be provided. */
    };
    
    const uint8_t id_h = 0xAB;
    const uint8_t id_l = 0xCD;
    uint8_t packet_uuid = 0;    /**< The current value for the packet UUID. This value is incremented after each packet is sent.*/
    uint8_t str = 0x64;         /**< Strength of the spell, just a default value*/
    uint8_t crc = 0;
    
    uint8_t selector_tx = 0b10000000;
    int p_tx; //iterator
    int k_tx; //iterator
    int num_tx; //used for CRC calculation
    bool currentBit_tx;
    uint8_t mirp[6];

    uint8_t counter_rx;
    struct ir_packet mirpRx; //unused because immutable
    
    extern uint8_t IDH,
                   IDL,
                   SPELL,
                   STR,
                   UID,
                   CRC;
    
    uint8_t byteFromCount_rx;
    uint8_t decodedByte_rx;
    uint8_t calculatedCRC_rx;
    extern bool validMIRP_rx;
    
    /**
     * 
     * @param spell_id The type of spell to send.
     */
    
    /**
     * Matt, only need to call this method, rest are internal
     * @TODO did not use ir_packet struct because code already written for array
     * uses the global constants of id_h,id_l, and strength to transmit MIRP
     * Attempts to transmit a MIRP packet with the given [spell_id](@ref spell_id).
     * @param spell_id   takes in 0,2, or 4 for spell id
     * @return   void
     */
    void transmit_ir_packet(ir_spell_id_t spell_id);
    
    
    /**
     * keeps PWM low for 30 cycles
     */
    void waitLow30Cycles(void);
    
    /**
     * keeps PWM low for 15 cycles
     */
    void waitLow15Cycles(void);
    
    /**
     * modulates PWM at 38kHz for 30 cycles
     */
    void modulate30Cycles(void);
    
    /**
     * modulates PWM at 38kHz for 15 cycles
     */
    void modulate15Cycles(void);
    
    /**
     * sends a Manchester Encoded bit '0' (rising edge)
     */
    void sendZero(void);
    
    /**
     * sends a Manchester Encoded bit '1' (falling edge)
     */
    void sendOne(void);
    
    /**
     * iterates through mirp[] array and masks each bit, then sends it in Manchester Encoding 
     * @param mirp  array of size 6 containing id_h,id_l,spell,str,uuid, and crc
     * @return void
     */
    void bangBitsSoftly(uint8_t mirp[]);
    uint8_t getCRC(uint8_t mirp0[]);
    
    /**
     * the starting MIRP protocol of 30 cycles high then 30 cycles low
     */
    void IR_Start(void);
    
    //IR RX
    /**
      * @example usage, put the decode() in a Interrupt On Change or Interrupt on Falling Edge ISR
       void PIN_MANAGER_IOC(void) {
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
    */
    
    /**
     * waits till middle of MIRP encoding to sample
     */
    void waitTillMid(void);
    
    /**
     * waits till end of MIRP encoding
     */
    void waitTillEnd(void);
    
    /**
     * @return true if start is valid/MIRP compliant
     */
    bool checkStart(void);
    
    /**
     * @return  true if CRC calculated is correct
     */
    bool checkCRC();
    
    
    /**
     * uses shorter delays than IR_Start to compensate
     * @return returns 1 decoded byte of MIRP packet
     */
    uint8_t decodeByte(); 
    
    
    /**
     * decodes received IR packet
     * the decoded MIRP is in the struct instance of ir_packet, mirpRx
     * @return true if received a valid MIRP packet (bool validMIRP)
     */
    bool decode(void);


#ifdef	__cplusplus
}
#endif

#endif	/* IR_COMMON_H */