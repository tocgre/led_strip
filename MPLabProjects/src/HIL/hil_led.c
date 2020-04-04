/* 
 * File:   hil_led.c
 * Author: tocgr
 *
 * Created on 29 septembre 2019, 22:35
 */

#include "../../inc/HIL/hil_led.h"

void vHILLED_Init(void)
{
    /*Set LED pin in Output mode*/
    TRISA &= ~(LED1_PORT_PIN);
}


void vHILLED_Set(void)
{
    LED_PORT |= LED1_PORT_PIN;
}


void vHILLED_Clear(void)
{
    LED_PORT &= ~(LED1_PORT_PIN);
}
