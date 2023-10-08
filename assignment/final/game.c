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
    //bool gameCompleted = false;

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


    //Setting debugging info for player numbers.
    if (playerNumber == 2) {
        tinygl_text("P2");
    } else {
        tinygl_text("P1");
    }

    //debugging player numbers.
    while(1) {
        pacer_wait();
        tinygl_update();
    }
}
