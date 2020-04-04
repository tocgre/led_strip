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
#define LED1_PORT_PIN                (0x01)  /*Pin RA0 if PORTA*/
#define LED2_PORT_PIN                (0x02)  /*Pin RA1 if PORTA*/
#define LED3_PORT_PIN                (0x04)  /*Pin RA2 if PORTA*/

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_DEF_H */

