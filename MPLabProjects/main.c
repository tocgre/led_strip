#include "system_def.h"
#include "inc/HIL/hil_led.h"
#include "inc/HIL/hil_pwm.h"

/*
  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F25K42
        Driver Version    :  2.00
*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
    // Initialize the device
    /* Fosc = 16 MHz /4 */
    SYSTEM_Initialize();
//    vHILLED_Init();
    vHILPWM5_Init();
    vHILPWM6_Init();
    vHILPWM7_Init();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();
    
    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();
    
    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();
    
    uint8_t _u8_VitesseMontee = 2U;
    uint8_t _u8_VitesseDescente = 2U;
    
    
    while (1U)
    {
        for(uint16_t __u16_Counter = 0U; __u16_Counter < (PWM_DUTY_CYCLE_100_POURCENT - _u8_VitesseMontee); __u16_Counter += _u8_VitesseMontee)
        {
            vHILPWM5_SetDutyCycle(__u16_Counter);
            vHILPWM6_SetDutyCycle(__u16_Counter);
            vHILPWM7_SetDutyCycle(__u16_Counter);
            __delay_ms(10U);
        }
        for(uint16_t __u16_Counter2 = PWM_DUTY_CYCLE_100_POURCENT; __u16_Counter2 > (0U + _u8_VitesseDescente); __u16_Counter2 -= _u8_VitesseDescente)
        {
            vHILPWM5_SetDutyCycle(__u16_Counter2);
            vHILPWM6_SetDutyCycle(__u16_Counter2);
            vHILPWM7_SetDutyCycle(__u16_Counter2);
            __delay_ms(10U);
        }
    }
}
/**
 End of File
*/