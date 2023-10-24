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
#include "gameLoop.h"

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744


/* This is the C file that runs a memory game on the microcontroller for ENCE260 */



//Data definitions
#define PACER_RATE 500
#define TURN_LIMIT 127

int main (void)
{
    //Initialise backend.
    button_init();
    led_init();
    ir_uart_init();
    system_init ();
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);




    //Enter the MAIN loop. 
    while(1) {

        //Store new pointers in memory.
        char* commands = calloc(sizeof(char), TURN_LIMIT);
        uint8_t* playerNumber = calloc(2, sizeof(uint8_t));
        bool* currentTurn = calloc(2, sizeof(bool));
        uint8_t* numCommands = calloc(TURN_LIMIT, sizeof(uint8_t));
        char* input = calloc(2, sizeof(char));
    

        //resets / initialises the variables we use in the loop. 
        resetVariables(playerNumber, currentTurn, numCommands, input);
        

        //Set the initial turn of player1.
        *currentTurn = checkStartTurn(playerNumber);
        

        //Run the main game logic between 2 players.
        runGame(playerNumber, currentTurn, numCommands, input, commands);
        

        //Free the memory of each player's variables.
        freeCommands(commands, playerNumber, currentTurn, numCommands, input);
    }
}
