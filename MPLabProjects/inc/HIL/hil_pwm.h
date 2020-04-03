/* 
 * File:   hil_pwm.h
 * Author: tocgr
 *
 * Created on 7 octobre 2019, 19:25
 */

#ifndef HIL_PWM_H
#define	HIL_PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../../system_def.h"
    

#define PWM_DUTY_CYCLE_0_POURCENT                          (0U)
#define PWM_DUTY_CYCLE_50_POURCENT                         (102U) /* Egal à T2PR/2 */
#define PWM_DUTY_CYCLE_100_POURCENT                        (204U) /* Duty Cycle Ratio = 1 sur l'équation 24-3 p341*/
    
extern void                 vHILPWM5_Init                  (void);
extern void                 vHILPWM_SetDutyCycle           (uint16_t __u16_DutyCycle);


#ifdef	__cplusplus
}
#endif

#endif	/* HIL_PWM_H */

