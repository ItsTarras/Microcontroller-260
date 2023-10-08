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

#define PACER_RATE 500
#define MESSAGE_RATE 30

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
}

int main (void)
{
    system_init ();
    //Initialise the tinygl module for writing messages.
    tinygl_init(PACER_RATE);
    //Set the font of the tinygl module:
    tinygl_font_set(&font5x7_1);
    //Set the scroll speed.
    tinygl_text_speed_set(MESSAGE_RATE);
    //Set the text to display:
    tinygl_text("Player1 Push Button\0");
    //Set it to scroll the text
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    //Set the update rate.
    
    /*Set up a pacer with 4hz frequency (1/4 of a second)*/
    button_init();
    led_init();
    ir_uart_init();

    uint8_t playerFound = false;
    uint8_t playerNumber = 0;
    bool gameCompleted = false;
    bool currentTurn = 0;
    bool isPushed = false;

    //ORGANISE HOW WE WILL STORE COMMANDS!
    //I'm thinking we add a char to a string and dynamically increase the size of the array
    //and then read that as what the required input is.
    
    //char memoryList[];

    //Flash a startup sequence to not have players immediately become player 1.
    pacer_init(8);
    for (int i = 0; i < 4; i++) {
        led_on();
        pacer_wait();
        led_off();
        pacer_wait();
    }

    //Start by creating a function that both receives and can have a button clicked.
    pacer_init (PACER_RATE);
    while (!playerFound)
    {
        pacer_wait();
        tinygl_update();

        //Player 2 receive logic.
        if (ir_uart_read_ready_p()) {
            if (ir_uart_getc() == '.') {
                playerFound = true;
                playerNumber = 2;
            }
        }
        //check if player 1 has been selected.
        else if (button_pressed_p()) {
            playerFound = true;
            playerNumber = 1;
            led_on();
            //Send a signal to the other player, letting them know a player has been found.
            ir_uart_putc('.');
            currentTurn = 1;
        }
    }


    //Setting debugging info for player numbers.
    if (playerNumber == 2) {
        tinygl_text("P2");
    } else {
        tinygl_text("P1");
    }

    /*debugging player numbers.
    while(1) {
        pacer_wait();
        tinygl_update();
    }*/


    //Enter the MAIN loop.
    resetPins();
    while(!gameCompleted) {
        while (currentTurn) {
            navswitch_update();
            pacer_wait();
            




            //NORTH LOGIC
            if (navswitch_down_p(NAVSWITCH_NORTH) && !isPushed) {
                
                displayNorth();

                //If key is released. We analyse the press AFTER release, whether it was a match.
                if (navswitch_up_p(NAVSWITCH_NORTH)) {
                    isPushed = true;
                }
            }




            //EAST LOGIC
            else if (navswitch_down_p(NAVSWITCH_EAST) && !isPushed) {
                
                displayEast();

                //If key is released. We analyse the press AFTER release, whether it was a match.
                if (navswitch_up_p(NAVSWITCH_EAST)) {
                    isPushed = true;
                }
            }

            else if (navswitch_down_p(NAVSWITCH_WEST) && !isPushed) {
                
                displayWest();

                //If key is released. We analyse the press AFTER release, whether it was a match.
                if (navswitch_up_p(NAVSWITCH_WEST)) {
                    isPushed = true;
                }
            }


            else if (navswitch_down_p(NAVSWITCH_SOUTH) && !isPushed) {
                
                displaySouth();
                
                //If key is released. We analyse the press AFTER release, whether it was a match.
                if (navswitch_up_p(NAVSWITCH_SOUTH)) {
                    isPushed = true;
                }
            }



            resetPins();


                //Add a north input to the current comparison memory for the game.
                //We need to add a completed round variable, and check if they've won.
                //If they've won, add a single character to the end of the new one, and send it to opponnet.
            //Current player's logic.

            //Receiving player's logic.
        }
    }
}
