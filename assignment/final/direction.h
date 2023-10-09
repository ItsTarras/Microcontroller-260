#ifndef direction_h
#define direction_h

//Resets the pins on the LED matrix.
void resetPins(void);

//Display all directions.
void displayNorth(void);
void displayEast(void);
void displayWest(void);
void displaySouth(void);
char getDirection(void);

#endif