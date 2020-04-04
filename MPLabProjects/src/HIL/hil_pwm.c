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
    vHILPWM5_SetDutyCycle(PWM_DUTY_CYCLE_50_POURCENT);
    
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
    TRISA &= ~(LED1_PORT_PIN);
    /* 7. Set Pin A0 as PWM5 output*/
    RA0PPS = 0x0D;
}


/*PWM6 uses Timer4 on pin PA1*/
void vHILPWM6_Init(void)
{
    /* 2. Disable PWM6 */
    PWM6CON = 0x00;
    
    /* 3. Set Timer4 prescaler to 199 to have a PWM at 20 kHz, see p341 */
    T4PR = 50U;
    
    /* 4.Set DutyCycle */
    vHILPWM6_SetDutyCycle(PWM_DUTY_CYCLE_50_POURCENT);
    
    /* 5.1. Clear TMR4IF interrupt flag */
    PIR7 &= ~(0x01); 
    
    /* 5.2. Set Fosc/4 as Timer's clock input */
    T4CLK = 0x01;
    
    /* 5.3. Configure the CKPS bits of the T4CON register with the Timer4 prescale value */
    T4CON = 0x00;
    
    /* 5.4. Enable Timer2 */
    T4CON |= 0x80;
    
    /* 6. Enable PWM output pin and wait until Timer4 overflows. */
    PWM6CON = 0x80;
    
    while(TMR4IF != 1U);
    
    /* 7. Enable pin PA1 */
    TRISA &= ~(LED2_PORT_PIN);
    /* 7. Set Pin A1 as PWM5 output*/
    RA1PPS = 0x0E;
}


/*PWM7 uses Timer6 on pin PA2*/
void vHILPWM7_Init(void)
{
    /* 2. Disable PWM7 */
    PWM7CON = 0x00;
    
    /* 3. Set Timer6 prescaler to 199 to have a PWM at 20 kHz, see p341 */
    T6PR = 50U;
    
    /* 4.Set DutyCycle */
    vHILPWM7_SetDutyCycle(PWM_DUTY_CYCLE_50_POURCENT);
    
    /* 5.1. Clear TMR6IF interrupt flag */
    PIR9 &= ~(0x01); 
    
    /* 5.2. Set Fosc/4 as Timer's clock input */
    T6CLK = 0x01;
    
    /* 5.3. Configure the CKPS bits of the T2CON register with the Timer6 prescale value */
    T6CON = 0x00;
    
    /* 5.4. Enable Timer6 */
    T6CON |= 0x80;
    
    /* 6. Enable PWM output pin and wait until Timer6 overflows. */
    PWM7CON = 0x80;
    
    while(TMR6IF != 1U);
    
    /* 7. Enable pin PA2 */
    TRISA &= ~(LED3_PORT_PIN);
    /* 7. Set Pin A2 as PWM7 output*/
    RA2PPS = 0x0F;
}


/*Set the DutyCycle. __u16_DutyCycle must be 10 bits long*/
void vHILPWM5_SetDutyCycle(uint16_t __u16_DutyCycle)
{
    /*DutyCycle low bits*/
    PWM5DCL = (uint8_t)(__u16_DutyCycle << 6U);
    /*DutyCycle high bits*/
    PWM5DCH = (uint8_t)(__u16_DutyCycle >> 2U);
}


/*Set the DutyCycle. __u16_DutyCycle must be 10 bits long*/
void vHILPWM6_SetDutyCycle(uint16_t __u16_DutyCycle)
{
    /*DutyCycle low bits*/
    PWM6DCL = (uint8_t)(__u16_DutyCycle << 6U);
    /*DutyCycle high bits*/
    PWM6DCH = (uint8_t)(__u16_DutyCycle >> 2U);
}


/*Set the DutyCycle. __u16_DutyCycle must be 10 bits long*/
void vHILPWM7_SetDutyCycle(uint16_t __u16_DutyCycle)
{
    /*DutyCycle low bits*/
    PWM7DCL = (uint8_t)(__u16_DutyCycle << 6U);
    /*DutyCycle high bits*/
    PWM7DCH = (uint8_t)(__u16_DutyCycle >> 2U);
}
