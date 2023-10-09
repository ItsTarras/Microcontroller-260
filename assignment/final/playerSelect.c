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
    
uint8_t playerSelect(void)
{
    bool playerFound = false;
    uint8_t playerNumber = 0;

    //Flash a startup sequence to not have players immediately become player 1.
    pacer_init(8);
    for (int i = 0; i < 4; i++) {
        led_on();
        pacer_wait();
        led_off();
        pacer_wait();
    }

    pacer_init(500);


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

    return playerNumber;
}