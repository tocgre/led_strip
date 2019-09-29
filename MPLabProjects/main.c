#include "system_def.h"
#include "inc/HIL/hil_led.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    vHILLED_Init();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    while (1)
    {
        vHILLED_Set();
        __delay_ms(500);
        vHILLED_Clear();
        __delay_ms(500);
    }
}
/**
 End of File
*/