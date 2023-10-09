#include <avr/io.h>
#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "led.h"
#include "button.h"
#include "ledmat.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"


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

void displayNorth(void)
{
    // Displays a north facing arrow.
    resetPins();
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pacer_wait();
    resetPins();
}

void displayEast(void)
{
    //Displays an east facing arrow.
    resetPins();
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);    
    pacer_wait();
    resetPins();
}

void displayWest(void)
{
    //Displays a west facing arrow.
    resetPins();
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);    
    pacer_wait();
    resetPins();
}

void displaySouth(void)
{
    //Displays an arrow that faces... you guessed it. SOUTH!
        // Displays a north facing arrow.
    resetPins();
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_LOW);
    pacer_wait();

    resetPins();
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_LOW);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_LOW);
    pacer_wait();
    resetPins();
}

char getDirection(void)
{
    bool isPushed = false;

    while (!isPushed) {
        navswitch_update();
        
        
        //NORTH LOGIC
        if (navswitch_down_p(NAVSWITCH_NORTH)) {
            //If key is released. We analyse the press AFTER release, whether it was a match.
            while (!isPushed) {
                displayNorth();
                navswitch_update();
                pacer_wait();
                if (navswitch_up_p(NAVSWITCH_NORTH)) {
                    isPushed = true;
                    resetPins();
                }
            }
            resetPins();
            return 'n';
        }




        //EAST LOGIC
        else if (navswitch_down_p(NAVSWITCH_EAST)) {
            //Sit inside the loop.
            while (!isPushed) {
                displayEast();
                navswitch_update();
                pacer_wait();
                if (navswitch_up_p(NAVSWITCH_EAST)) {
                    isPushed = true;
                    resetPins();
                }
            }
            resetPins();
            return 'e';
        }

        //WEST LOGIC
        else if (navswitch_down_p(NAVSWITCH_WEST)) {
            //Sit in the loop
            while(!isPushed) {
                displayWest();
                navswitch_update();
                pacer_wait();
                if (navswitch_up_p(NAVSWITCH_WEST)) {
                    isPushed = true;
                    resetPins();
                }
            }
            resetPins();
            return 'w';
        }


        else if (navswitch_down_p(NAVSWITCH_SOUTH)) {
            while(!isPushed) {
                displaySouth();
                navswitch_update();
                pacer_wait();
                if (navswitch_up_p(NAVSWITCH_SOUTH)) {
                    isPushed = true;
                    resetPins();
                }
            }
            resetPins();
            return 's';
        }
    }

    //Default to a return value it will never reach.
    return '1';
}