#include <avr/io.h>
#include "system.h"

int main (void)
{
    system_init ();

    //Set Data directory of port D as an input so that pin 7 is used.
    DDRD &= ~(1<<7);

    //Set data directory of port c as an output, so that pin 2 is used
    DDRC |= (1<<2);

    while (1)
    {
        //If the pin 7 of port D has been pushed.
        if ((PIND & (1<<7)) != 0) {
            PORTC |= (1<<2);
            } else {
            PORTC &= ~(1<<2);
        }
    }
}
