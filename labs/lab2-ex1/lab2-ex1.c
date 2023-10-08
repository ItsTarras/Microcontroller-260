#include <avr/io.h>
#include "system.h"
#include "led.h"

bool delayTicks(uint16_t number)
{
    /* Delays the counter by a specified amount, then resets the timer. */
    while (TCNT1 < number) {
        continue;
    }

    TCNT1 = 0;
    return true;
}

int main (void)
{
    system_init ();
    led_init ();
    
    //Set A
    TCCR1A = 0x00;

    //B is the timer
    TCCR1B = 0x05;

    //Set B
    TCCR1C = 0x00;
    
    while (1)
    {
        /* Turn LED on.  */
        led_set (LED1, 1);
        
        //Delay the timer by 500ms (3906 ticks).
        delayTicks(3906 / 2);
        
        /* Turn LED off.  */
        led_set (LED1, 0);
        
        /* TODO: wait for 500 milliseconds.  */
        delayTicks(3906 * 3 / 2);
    }
    
}
