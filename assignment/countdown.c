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
#include "direction.h"

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744

//This is the c file that contains a countdown function, that displays a countdown timer on the board.

void startCountdown(void) {
    /* This function is used to display a countdown timer before running another command. It is set to 3 seconds by default, 
    with 1 blank second (so the user cna adjust to the now blank matrix). */

    //Assuming the pacer is still 500hz/s, wait for a few seconds with a countdown display.
    resetPins();

    //Initialise the text for the matrix.
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    tinygl_text_speed_set (10);
    tinygl_text("321 ");
    
    //Pacer loop that waits for 4 seconds.
    for (int i = 0; i < 2000; i++) {
        tinygl_update();
        pacer_wait();
    }

    //Resets the text back to the normal rate.
    tinygl_text_speed_set (30);

    //resets the matrix pins back to a high state (off).
    resetPins();
}
