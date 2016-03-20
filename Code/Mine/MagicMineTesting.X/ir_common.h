/* 
 * @file   ir_common.h
 * @author: Matthew Atkins
 * @date Created on March 19, 2016, 5:21 PM
 */

#ifndef IR_COMMON_H
#define	IR_COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum spell_type {
        IR_SPELL_DAMAGE = 0,
        IR_SPELL_STUN = 2,
        IR_SPELL_HEAL = 4
    } ir_spell_id_t;

    struct ir_packet {
        const uint8_t id_h;
        const uint8_t id_l;
        const uint8_t spell_id;
        const uint8_t uuid;
        const uint8_t crc;
    };
    
    const uint8_t id_h = 0;
    const uint8_t id_l = 1;
    
    uint8_t packet_uuid = 0;
    
    void transmit_ir_packet(ir_spell_id_t spell_id);

#ifdef	__cplusplus
}
#endif

#endif	/* IR_COMMON_H */

