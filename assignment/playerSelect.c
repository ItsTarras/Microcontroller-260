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
#define TURN_LIMIT 127
#define FLASH_TIME 40

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744

/* This is the c file that contains player select logic. It has function definitions for an LED startup sequence, a start turn check, and the playerSelect loop, 
as well as being able to reset the playerSelect variables for a new game. */

void startupFlash(uint8_t speed)
{
    //Flash a startup sequence to not have players immediately become player 1. Flash slowly (pacer hz = speed)
    pacer_init(speed);
    for (int i = 0; i < 4; i++) {
        led_on();
        pacer_wait();
        led_off();
        pacer_wait();
    }

    //Reset the pacer speed to the pacer rate.
    pacer_init(PACER_RATE);
}


bool checkStartTurn(uint8_t* playerNumber)
{
    //This returns whether the player is the starting one or not.
    return (*playerNumber == 1);
}


void resetVariables(uint8_t* playerNumber, bool* currentTurn, uint8_t* numCommands, char* input)
{
    //Redefine variables at the start of every game:
    *playerNumber = 0;
    *currentTurn = false;
    *numCommands = 0;
    *input = '0';
    *playerNumber = playerSelect();
}


uint8_t playerSelect(void)
{   
    //This function sits the players inside a loop, and returns when a starting player has been selected.

    //Set the scroll speed.
    tinygl_text_speed_set(30);
    //Set the text to display:
    
    //Set it to scroll the text
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    //Set the update rate.
    tinygl_text("Player1 Push Button\0");
    bool playerFound = false;
    uint8_t playerNumber = 0;

    //Run the startup flash.
    startupFlash(8);

    //Select the starting player.
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
        }
    }

    //Reset the matrix.
    resetPins();

    return playerNumber;
}