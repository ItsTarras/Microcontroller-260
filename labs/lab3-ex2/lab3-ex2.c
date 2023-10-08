#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include <stdlib.h>


#define PACER_RATE 300
#define MESSAGE_RATE 30


void display_character (char character)
{
    char buffer[2];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}


int main (void)
{
    system_init ();
    bool ispushed = false;
    char sentence[] = "Hello World";
    char character = sentence[0];
    size_t index = 0;
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);

    /* TODO: Initialise navigation switch driver.  */
    navswitch_init();

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait ();
        tinygl_update ();
        
        /* TODO: Call the navswitch update function.  */
        navswitch_update();

        /* TODO: Increment character if NORTH is pressed.  */
        if (navswitch_down_p(NAVSWITCH_NORTH) && !ispushed) {
            index += 1;
            if (index >= sizeof(sentence)) {
                index = 0;
            }
            character = sentence[index];
            ispushed = true;
        }
        
        /* TODO: Decrement character if SOUTH is pressed.  */
        else if (navswitch_down_p(NAVSWITCH_SOUTH)&& !ispushed) {
            index -= 1;
            character = sentence[index];
            
            if (index <= 0) {
                index = sizeof(sentence);
            }
            
            ispushed = true;
            
        }

        else if (navswitch_up_p(NAVSWITCH_NORTH) && navswitch_up_p(NAVSWITCH_SOUTH)) {
            ispushed = false;
        }

        display_character (character);
        
    }
    return 0;
}
