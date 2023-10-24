#ifndef gameLoop_H
#define gameLoop_H

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744
//This is the header file that contains all functions in gameLoop.c


void runGame(uint8_t* playerNumber, bool* currentTurn, uint8_t* numCommands, char* input, char* commands);
void freeCommands(char* commands, uint8_t* playerNumber, bool* currentTurn, uint8_t* numCommands, char* input);

#endif