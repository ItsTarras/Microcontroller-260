#ifndef playerSelect_H
#define playerSelect_H

//twe36 Tarras Weir 99406503
//lhe73 Luke Henry Paiti 42335744
// This is the header file for playerSelect.c. It is needed to run the functions contained within.

uint8_t playerSelect(void);
void startupFlash(uint8_t speed);
void resetVariables(uint8_t* playerNumber, bool* currentTurn, uint8_t* numCommands, char* input);
bool checkStartTurn(uint8_t* playerNumber);

#endif