#include <avr/io.h>
#include "pacer.h"

static uint16_t pacer_period;

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency)
{
    //Set A
    TCCR1A = 0x00;

    //B is the timer
    TCCR1B = 0x05;

    //Set B
    TCCR1C = 0x00;
    
    // Resets the value of the timer to 0.
    TCNT1 = 0;

    pacer_period = 7812 / pacer_frequency;

    /* TODO: initialise timer/counter peripheral the
       same way as in lab2/lab2-ex2/timer.c but also calculate 
       the timer/counter value from the pacer frequency */
}


/* Pace a while loop.  */
void pacer_wait (void)
{
    while (TCNT1 < pacer_period) {
        continue;
    }

    //Reset after the loop, allowing remainder time to be used instead of resetting each time.
    TCNT1 = 0;
}
