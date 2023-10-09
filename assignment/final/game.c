#include <avr/io.h>
#include <stdlib.h>
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
#include "direction.h"
#include "playerSelect.h"
#include "countdown.h"
#include "directionsArray.h"

#define PACER_RATE 500
#define MESSAGE_RATE 30
#define TURN_LIMIT 100

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
    
    //Initialise backend.
    button_init();
    led_init();
    ir_uart_init();

    //Store local variables.
    uint8_t playerNumber = 0;
    bool gameCompleted = false;
    bool currentTurn = 0;
    uint8_t numCommands = 1;

    //ORGANISE HOW WE WILL STORE COMMANDS!
    char* commands = calloc(sizeof(char), TURN_LIMIT);


    //I'm thinking we add a char to a string and dynamically increase the size of the array
    //and then read that as what the required input is.
    
    //char memoryList[];

    

    //Start the initial player selection process.
    playerNumber = playerSelect();
    resetPins();

    
    //Set the initial turn of player1.
    if (playerNumber == 1) {
        currentTurn = true;
    } else {
        numCommands = 2;
    }



    //Start by creating a function that both receives and can have a button clicked.
    pacer_init (PACER_RATE);

    //Enter the MAIN loop.
    while(!gameCompleted) {
        if (currentTurn) {
            resetPins();
            //Update the command array in receive.
            //Start a countdown from 3, 2, 1 to display the commands in a sequence.
            //if it's not the first turn.
            if (numCommands != 1) {
                //Do a 3, 2, 1 countdown.
                startCountdown();
                resetPins();

                //Display every direction required from the commands array.

                //Start the loop where we require the player to mimic it.
                for (int i = 0; i < numCommands; i++) {
                    if (commands[i] == 'n') {
                        for (int i = 0; i < 30; i++) {
                            displayNorth();
                            pacer_wait();
                        }

                    } else if (commands[i] == 'e') {
                        
                        for (int i = 0; i < 30; i++) {
                            displayEast();
                            pacer_wait();
                        }
                    } else if (commands[i] == 's') {
                        
                        for (int i = 0; i < 30; i++) {
                            displaySouth();
                            pacer_wait();
                        }
                    } else if (commands[i] == 'w') {
                        for (int i = 0; i < 30; i++) {
                            displayWest();
                            pacer_wait();
                        }
                    }

                    resetPins();
                    for (int i = 0; i < 20; i++) {
                        pacer_wait();
                    }

                }
            } 

            //Flash a text that says 'Input Direction'.
            //Chuck it into the countdown.c file and header.

            //Add the new commands
            char input = getDirection();
            currentTurn = false;

            //Add to our array the input.
            addToArray(input, commands, numCommands - 1);

            //If the player succeeded (or it's turn 0), add a new command to send.
            numCommands += 2;

            
            


            
            //Append the direction character to ours, and also send it to the opponent.

            //Player has finished their turn.
            currentTurn = true;
            

            resetPins();

            //We need to add a completed round variable, and check if they've won.
            //If they've won, add a single character to the end of the new one, and send it to opponnet.
            //Current player's logic.

            
        } else if (ir_uart_read_ready_p()) {
            //Receiving player's logic.
            /* Wait to receive an input. Once you do, add it to your own personal array.*/
            char received = ir_uart_getc();
            if (received == 'n' || received == 'e' || received == 's' || received == 'w') {
                addToArray(received, commands, numCommands);
                currentTurn = true;
            }
        }
    }
}
