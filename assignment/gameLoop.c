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

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744

/* This c file contains the majority of game logic we run. 
It contains a large while loop that aims to handle logic for each player, their turn, and what to do while they're in the game.
It also contains a function that resets the game's variables at the end.*/

//Data definitions
#define PACER_RATE 500
#define MESSAGE_RATE 30
#define TURN_LIMIT 127
#define FLASH_TIME 40

/*This is the main logic of the gameplay*/

void runGame(uint8_t* playerNumber, bool* currentTurn, uint8_t* numCommands, char* input, char* commands)
{
    
    while(1) {

        /*This is the logic for the current players turn, if it 
        is the players go*/

        if (*currentTurn) {
            //Ensure trhe matrix is cleaned.
            resetPins();

            //Establish a locla loop variable.
            bool completed = true;


            /*Start a countdown from 3, 2, 1 to display the commands in a sequence.
            if it's not the first turn.*/
            if (*numCommands != 0) {
                //Do a 3, 2, 1 countdown.
                startCountdown();
                
                //Flash the saved sequence
                mimicDirection(commands, *numCommands, FLASH_TIME);
                
                //Flash the LED to let the player know it's their turn.
                startupFlash(12);
                led_on();
                
                //NOW WE NEED THE PLAYER TO MIMIC IT PROPERLY.
                completed = copySequence(*numCommands, commands, PACER_RATE);
            } 


        
            //If the player completed the mimic, OR it is the first turn.
            if (completed) {
                //Give visual feedback that it's this player's go to add a command.
                startupFlash(20);
                led_on();

                //Flash a text that says 'Add'.
                resetPins();
                tinygl_text("Add");
                tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);

                //Run through it once.
                for (int i = 0; i < PACER_RATE; i++) {
                    tinygl_update();
                    pacer_wait();
                    resetPins();
                }

                //Add the new commands, depending on the player number.
                if (*playerNumber == 1) {
                    *input = getDirection1();
                } else {
                    *input = getDirection2();
                }
                
                //Append the direction character to ours, and also send it to the opponent.
                addToArray(*input, commands, *numCommands);

                //Send the signal to the opponent.
                ir_uart_putc(*input);

                //No longer this player's turn.
                *currentTurn = false;

                //Add to the number of commands, keeping track of the count.
                *numCommands += 1;

                //Reset the pins
                resetPins();

                //No longer this player's turn. LED off.
                led_off();

            } else {
                //The player failed the mimic. Display LOSER information until they decide to restart the game.
                //send an infrared signal to the opponent, saying we lost.

                //Set up the tinygl module.
                ir_uart_putc('L');
                led_off();
                tinygl_text(" LOSER");
                tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
                tinygl_text_speed_set (MESSAGE_RATE);

                //Continue flashing LOSER until they've decided to restart.
                while(true) {
                    //flash to word LOSER.
                    pacer_wait();
                    tinygl_update();
                    navswitch_update();

                    //Push the navswitch down if they want to restart. (Breaks out of the external while loop).
                    if (navswitch_down_p(NAVSWITCH_PUSH)) {
                        resetPins();
                        break;
                    }               
                }
                break;
            }


        } else if ((*currentTurn == false) && ir_uart_read_ready_p()) {
            //If it is not this player's turn, they are thrown into receive mode.

            //Reset the pacer timing, as well as clear the matrix to blank.
            pacer_init(PACER_RATE);
            resetPins();

            /* Wait to receive an input. Once you do, add it to your own personal array.*/
            const char received = ir_uart_getc();
            
            //Each player sends and receives different commands, as to not accidentally receive their own.
            if (*playerNumber == 2) {
                if (received == 'n' || received == 'e' || received == 's' || received == 'w') {
                    addToArray(received, commands, *numCommands);
                    *currentTurn = true;
                    *numCommands += 1;
                    led_on();
                }
            } else if (received == 'u' || received == 'd' || received == 'l' || received == 'r') {
                addToArray(received, commands, *numCommands);
                *currentTurn = true;
                *numCommands += 1;
                led_on();
            } 
            
            //If we receive a signal that says the other player lost:
            if (received == 'L') {
                //Set up our tinygl module.
                pacer_init(PACER_RATE);
                tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
                tinygl_text_speed_set (MESSAGE_RATE);
                tinygl_text(" WINNER");

                //Begin displaying WINNER.
                while (1) {
                    tinygl_update();
                    pacer_wait();
                    navswitch_update();
                    //If the player wishes to restart the game by pushing the joystick.
                    if (navswitch_down_p(NAVSWITCH_PUSH)) {
                        resetPins();
                        break;
                    }          
                }
                break;
            } 
        }
    }
}


void freeCommands(char* commands, uint8_t* playerNumber, bool* currentTurn, uint8_t* numCommands, char* input)
{
    //This frees the memory so we don't have a memory issue later down the line.
    free(commands);
    free(playerNumber);
    free(currentTurn);
    free(numCommands);
    free(input);
}