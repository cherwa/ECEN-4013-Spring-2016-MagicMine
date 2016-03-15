/* 
 * File:   remote_main.h
 * Author: matthew
 *
 * Created on March 14, 2016, 6:46 PM
 */

#ifndef REMOTE_MAIN_H
#define	REMOTE_MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "remote_common.h"

    static volatile SpellType selectedSpell = NO_SELECTION;
    
    void main(void);
    SpellType getSpellType(void);
    void setSpellType(const SpellType spellType);

#ifdef	__cplusplus
}
#endif

#endif	/* REMOTE_MAIN_H */

