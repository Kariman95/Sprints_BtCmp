/***************************************************
 * File: XO_implementation.h
 * Author: Kariman Karam
 * Date: 1 July 2021
 * Version: 1
 * Description: Global Variables and Declarations of functions for XO Game
 **************************************************/


#include <stdio.h>
#include "XO_header.h"

uint8_t player='X';
uint8_t grid[3][3]= {'1','2','3','4','5','6','7','8','9'};

/*
* Function to print the playground of the game
*/
void printGrid(void)
{
    uint8_t i,j;

    system("cls");  //to remove everything on console

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("     [%c]      ",grid[i][j]);
        }
        printf("\n\n");
    }
}

uint8_t play(void)
{
    uint8_t position;
    fflush(stdin);
    printf("Player(%c), choose a position less than 10: ",player);
    scanf("%c",&position);

    return position;
}

/*
* Function to let the user enter a position to play
*/
enum E_STATUS SavePlayerPosition(char position)
{
    enum E_STATUS status = E_OK;
    uint8_t i,j;

    if(position > 9)
    {
        return E_INVALID;
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(grid[i][j]=='X' || grid[i][j]=='O')
                return E_TAKEN;
            if(grid[i][j]==position)
            {
                printf("in\n");
                grid[i][j] = player;
                if(player == 'X')         player = 'O';
                else if(player == 'O')    player = 'X';
            }
        }
    }

    return status;
}
/*
*Function to check who is the winner and returns it
*/
uint8_t winner(void)
{
    uint8_t X_counter=0;
    uint8_t O_counter=0;
    uint8_t i;
    uint8_t j;
    uint8_t counter=0;
    //check rows
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(grid[i][j]=='X')          X_counter++;
            else if(grid[i][j]=='O')     O_counter++;

            if(X_counter == 3)      return 'X';
            else if(O_counter == 3) return 'O';
        }
        X_counter = 0;
        O_counter = 0;
    }
    X_counter = 0;
    O_counter = 0;
    //check column
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(grid[j][i]=='X')          X_counter++;
            else if(grid[j][i]=='O')     O_counter++;

            if(X_counter == 3)      return 'X';
            else if(O_counter == 3) return 'O';
        }
        X_counter = 0;
        O_counter = 0;
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(grid[j][i]!='X' && grid[j][i]!='O')
                counter++;
        }
    }
    //check diagonals
    if(grid[0][0]=='X' && grid[1][1]=='X' && grid[2][2]=='X')        return 'X';
    else if(grid[0][0]=='O' && grid[1][1]=='O' && grid[2][2]=='O')   return 'O';
    else if(grid[0][2]=='X' && grid[1][1]=='X' && grid[2][0]=='X')   return 'X';
    else if(grid[0][2]=='O' && grid[1][1]=='X' && grid[2][0]=='O')   return 'O';

    if(counter==0)  return 'Z';     //game finished and no winner
    return 'n';                     //game not finished
}
