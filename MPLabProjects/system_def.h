/* 
 * File:   system_def.h
 * Author: tocgr
 *
 * Created on 29 septembre 2019, 22:40
 */

#ifndef SYSTEM_DEF_H
#define	SYSTEM_DEF_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include <stdint.h>

    
/***************DEFINE*****************/
#define LED_PORT                     (PORTA)
#define LED_PORT_PIN                 (0x01)  /*Pin RA0 if PORTA*/

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_DEF_H */

