#include "system.h"
#include "pio.h"

/* Include the pacer module from the previous lab.
   You must have completed this before starting this lab2-exercise.  */
#include "pacer.h"

void resetPins(void)
{
        
    //Initialises the matrix Rows.
    pio_config_set(PB6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB0_PIO, PIO_OUTPUT_HIGH);

    //Initialises the matrix Columns
    pio_config_set(PC6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PB7_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PC4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PC7_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(PC5_PIO, PIO_OUTPUT_HIGH);

}


int main (void)
{
    system_init ();
    
    resetPins();
    /* Set up pacer with a frequency of 100 Hz.  
        This gives 50Hz alternating between the 2 states.*/
    pacer_init (100);

    while (1)
    {
        //Activates two corner pins on the same row.
        resetPins();
        pio_config_set(PB0_PIO, PIO_OUTPUT_LOW);
        pio_config_set(PB6_PIO, PIO_OUTPUT_LOW);
        pio_config_set(PC6_PIO, PIO_OUTPUT_LOW);
        pacer_wait();

        //Activates a single pin
        resetPins();
        pio_config_set(PB6_PIO, PIO_OUTPUT_LOW);
        pio_config_set(PC5_PIO, PIO_OUTPUT_LOW);
        pacer_wait();
    }
}
