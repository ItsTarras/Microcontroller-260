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
#include "playerSelect.h"

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744
//This is a c module that deals with the commands array of the game. It contains a command that adds a character to the array.

void addToArray(char c, char* array, int size)
{
    //This sets the value of a character array to be a specific input character.
    array[size] = c;
}