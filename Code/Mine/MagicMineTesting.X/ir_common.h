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
        const uint8_t id_h;     /**< The hight byte of the packet id number.*/
        const uint8_t id_l;     /**< The low byte of the packet id number.*/
        const uint8_t spell_id; /**< The spell id, should be one of the values from the [spell_type](@ref spell_type) enum.*/
        const uint8_t str;  	/**< The strength of the spell */
        const uint8_t uuid;     /**< The UUID for this packet. */
        const uint8_t crc;      /**< The CRC checksum value. This is computed from the other fileds and <b>SHOLD NOT</b> be provided. */
    };
    
    const uint8_t id_h = 0;
    const uint8_t id_l = 1;
    uint8_t packet_uuid = 0;    /**< The current value for the packet UUID. This value is incremented after each packet is sent.*/
    uint8_t str = 0x64;         /**< Strength of the spell, just a default value*/
    uint8_t crc = 0;
    
    uint8_t selector_tx = 0b10000000;
    int p_tx; //iterator
    int k_tx; //iterator
    int num_tx; //used for CRC calculation
    bool currentBit_tx;
    uint8_t mirp[6];

    /**
     * Attempts to transmit a MIRP packet with the given [spell_id](@ref spell_id).
     * @param spell_id The type of spell to send.
     */
    void transmit_ir_packet(ir_spell_id_t spell_id);
    void waitLow30Cycles(void);
    void waitLow15Cycles(void);
    void modulate30Cycles(void);
    void modulate15Cycles(void);
    void sendZero(void);
    void sendOne(void);
    void bangBitsSoftly(uint8_t mirp[]);
    uint8_t getCRC(uint8_t mirp0[]);
    void IR_Start(void);

#ifdef	__cplusplus
}
#endif

#endif	/* IR_COMMON_H */

