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

extern char player;
extern char grid[3][3];

enum E_STATUS {E_ERROR, E_OK, E_TAKEN, E_INVALID};

void printGrid(void);
char play(void);
enum E_STATUS SavePlayerPosition(char position);
char winner(void);

#endif
