#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"


#define PACER_RATE 500
#define MESSAGE_RATE 10

int main (void)
{
    system_init();

    //Initialise the tinygl module for writing messages.
    tinygl_init(PACER_RATE);

    //Set the font of the tinygl module:
    tinygl_font_set(&font5x7_1);

    //Set the scroll speed.
    tinygl_text_speed_set(MESSAGE_RATE);

    //Set the text to display:
    tinygl_text("Peepee Poopoo\0");

    //Set it to scroll the text
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);

    //Set the update rate.
    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        
        /* TODO: Call the tinygl update function. */
        tinygl_update();
        
    }
    return 0;
}
