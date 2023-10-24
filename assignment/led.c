#include <avr/io.h>
#include "led.h"

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744
//This is a c file that plays with the LED of the microcontroller, and cna initialise it, and turn it on or off.


/** Turn LED1 on.  */
void led_on (void)
{
    PORTC |= (1<<2);
}


/** Turn LED1 off.  */
void led_off (void)
{
    PORTC &= ~(1<<2);
}


/** Initialise LED1.  */
void led_init (void)
{
    DDRC |= (1<<2);
}
