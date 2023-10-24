#ifndef PACER_H
#define PACER_H

#include "system.h"

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744
//This is the header file for the pacer. It is required to run the pacer functions.

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency);


/* Pace a while loop.  */
void pacer_wait (void);

#endif //PACER_H
