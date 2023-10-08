#include <avr/io.h>
#include "timer.h"

/* Initialise timer.  */
void timer_init (void)
{
    //Set A
    TCCR1A = 0x00;

    //B is the timer
    TCCR1B = 0x05;

    //Set B
    TCCR1C = 0x00;
    
    // Resets the value of the timer to 0.
    TCNT1 = 0;
}


/* Wait for the specified length of time.  */
void timer_delay_ms (uint16_t milliseconds)
{
    //Resetting the timer here means ALWAYS wait 500ms, and not remainder after a task.
    TCNT1 = 0;

    /* TODO: Calculate the timer/counter value needed 
       for the given number of milliseconds. */
    uint16_t top = (7812 / (1000/milliseconds));

    /* TODO: Wait for the timer/couter to reach the 
       value calculated above.  */
    while (TCNT1 < top) {
        continue;
    }
}
