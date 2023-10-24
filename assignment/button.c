#include <avr/io.h>
#include "button.h"

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744

//This contains helper c modules to check if the button on the microcontroller has been pressed.

/** Return non-zero if button pressed.  */
int button_pressed_p (void)
{
    return (PIND & (1<<7));
}


/** Initialise button1.  */
void button_init (void)
{
    DDRD &= ~(1<<7);
}

