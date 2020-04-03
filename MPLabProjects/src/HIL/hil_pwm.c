/* 
 * File:   hil_pwm.c
 * Author: tocgr
 *
 * Created on 07 octobre 2019
 */

#include "../../inc/HIL/hil_pwm.h"
#include "../../inc/HIL/hil_led.h"

/*PWM5 uses Timer2 on pin PA0*/
void vHILPWM5_Init(void)
{
    /* 2. Disable PWM5 */
    PWM5CON = 0x00;
    
    /* 3. Set Timer2 prescaler to 199 to have a PWM at 20 kHz, see p341 */
    T2PR = 50U;
    
    /* 4.Set DutyCycle */
    vHILPWM_SetDutyCycle(PWM_DUTY_CYCLE_50_POURCENT);
    
    /* 5.1. Clear TMR2IF interrupt flag */
    PIR4 &= ~(0x04); 
    
    /* 5.2. Set Fosc/4 as Timer's clock input */
    T2CLK = 0x01;
    
    /* 5.3. Configure the CKPS bits of the T2CON register with the Timer2 prescale value */
    T2CON = 0x00;
    
    /* 5.4. Enable Timer2 */
    T2CON |= 0x80;
    
    /* 6. Enable PWM output pin and wait until Timer2 overflows. */
    PWM5CON = 0x80;
    
    while(TMR2IF != 1U);
    
    /* 7. Enable pin PA0 */
    TRISA &= ~(LED_PORT_PIN);
    /* 7. Set Pin A0 as PWM5 output*/
    RA0PPS = 0x0D;
    
    /* 8.  */
//    PWM5CON = 0x80;
}


/*Set the DutyCycle. __u16_DutyCycle must be 10 bits long*/
void vHILPWM_SetDutyCycle(uint16_t __u16_DutyCycle)
{
    /*DutyCycle low bits*/
    PWM5DCL = (uint8_t)(__u16_DutyCycle << 6U);
    /*DutyCycle high bits*/
    PWM5DCH = (uint8_t)(__u16_DutyCycle >> 2U);
            
}
