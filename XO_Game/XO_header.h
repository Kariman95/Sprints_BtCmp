/***************************************************
 * File: XO_header.h
 * Author: Kariman Karam
 * Date: 1 July 2021
 * Version: 1
 * Description: Prototypes of XO Game
 **************************************************/

#ifndef XO_H_
#define Xo_H_

#include "Data_Types.h"

extern uint8_t player;
extern uint8_t grid[3][3];

enum E_STATUS {E_ERROR, E_OK, E_TAKEN, E_INVALID};

void printGrid(void);
uint8_t play(void);
enum E_STATUS SavePlayerPosition(char position);
uint8_t winner(void);

#endif
