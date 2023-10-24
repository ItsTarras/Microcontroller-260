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
#include "countdown.h"
#include "../fonts/font5x7_1.h"

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744

/*This c file deals with the matrix directions, as well as any direction-alligned checks.
 this can involve displaying directions on the board, as well as checking an input of a user and comparing it to the directions,
 and flashing sequences depending on the commands.*/

void resetPins(void)
{
    /* This function is used to reset the matrix to a blank state. It's used often. */
        
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




void mimicDirection(char* commands, uint8_t numCommands, int FLASH_TIME)
{
    /* This is thefunction that will display the commands tha the user needs to mimic. Each command is displayed for a short period in squential order. */

    //Runs through the commands, and displays the associated direction.
    for (int i = 0; i < numCommands; i++) {
        if (commands[i] == 'n' || commands[i] == 'u') {
            for (int i = 0; i < FLASH_TIME; i++) {
                displayNorth();
                pacer_wait();
            }

        } else if (commands[i] == 'e' || commands[i] == 'r') {
            
            for (int i = 0; i < FLASH_TIME; i++) {
                displayEast();
                pacer_wait();
            }
        } else if (commands[i] == 's' || commands[i] == 'd') {
            
            for (int i = 0; i < FLASH_TIME; i++) {
                displaySouth();
                pacer_wait();
            }
        } else if (commands[i] == 'w' || commands[i] == 'l') {
            for (int i = 0; i < FLASH_TIME; i++) {
                displayWest();
                pacer_wait();
            }
        }

        /* At the end of each directional display, leave the matrix blank for a small period, so we have a divider between directions.
        If we had two wests for example, it would otherwise have a long west displayed, so we need to breka it up */
        resetPins();
        for (int i = 0; i < ((FLASH_TIME + 5)/ 2); i++) {
            pacer_wait();
        }
    }

    //Reset the display
    resetPins();
}

//For Player 1
char getDirection1(void)
{
    /* This function gets the input of a player, and returns a signal unique to the playernumber. This is specifically for player 1.*/

    //Sets a local loop variable.
    bool isPushed = false;

    //Start the main loop for the ogic.
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

        //SOUTH LOGIC
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


char getDirection2(void)
{
    /* This function gets the input of a player, and returns a signal unique to the playernumber. This is specifically for player 2.*/

    //Set up a local loop variable.
    bool isPushed = false;

    //Start the main loop
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
            return 'u';
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
            return 'r';
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
            return 'l';
        }

        //SOUTH LOGIC
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
            return 'd';
        }
    }

    //Default to a return value it will never reach.
    return '1';
}


bool copySequence(uint8_t numCommands, char* commands, int PACER_RATE)
{
    /*This command compares the players input to the actual sequence and 
    return whether or not they succeeded*/
    char attempt = '0';
    bool success = true;
    bool completedMimic = false;

    // Loop while player attempts to mimic direcitons
    while(!completedMimic) {
        pacer_init(PACER_RATE);
        for (int i = 0; i < numCommands; i++) {
            if (i % 2 == 0) {
                attempt = getDirection1();
            } else {
                attempt = getDirection2();
            }
            if (attempt != commands[i]) {
                //The user failed the input.
                return false;
            }
        }
        completedMimic = true;
    }
    resetPins();

    return success;
}