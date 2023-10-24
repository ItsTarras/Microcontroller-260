#ifndef direction_h
#define direction_h

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744
//This is the header file for direction.c

//Resets the pins on the LED matrix.
void resetPins(void);

//Display all directions.
void displayNorth(void);
void displayEast(void);
void displayWest(void);
void displaySouth(void);
char getDirection1(void);
char getDirection2(void);
void mimicDirection(char* commands, uint8_t numCommands, int FLASH_TIME);
bool copySequence(uint8_t numCommands, char* commands, int PACER_RATE);

#endif