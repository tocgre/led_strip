/* 
 * File:   hil_led.h
 * Author: tocgr
 *
 * Created on 29 septembre 2019, 22:35
 */

#ifndef HIL_LED_H
#define	HIL_LED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../../system_def.h"
    
extern void                 vHILLED_Init                   (void);
extern void                 vHILLED_Set                    (void);
extern void                 vHILLED_Clear                  (void);


#ifdef	__cplusplus
}
#endif

#endif	/* HIL_LED_H */

