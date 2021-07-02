/***************************************************
 * File: Test_Cases.c
 * Author: Kariman Karam
 * Date: 1 July 2021
 * Version: 1
 * Description: Declarations of 10 Test Cases for XO Game
 **************************************************/

#include<stdlib.h>
#include "XO_header.h"

//test cases
enum E_STATUS Test_Win_X_Horizontal(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][0] = 'X';
    grid[0][1] = 'X';
    grid[0][2] = 'X';

    if(winner() == 'X')     status = E_OK;
    return status;
}

enum E_STATUS Test_Win_O_Horizontal(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][0] = 'O';
    grid[0][1] = 'O';
    grid[0][2] = 'O';

    if(winner() == 'O')     status = E_OK;
    return status;
}

enum E_STATUS Test_Win_X_Vertical(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][0] = 'X';
    grid[1][0] = 'X';
    grid[2][0] = 'X';

    if(winner() == 'X')     status = E_OK;
    return status;
}

enum E_STATUS Test_Win_O_Vertical(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][0] = 'O';
    grid[1][0] = 'O';
    grid[2][0] = 'O';

    if(winner() == 'O')     status = E_OK;
    return status;
}

enum E_STATUS Test_Win_X_Diagonal(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][0] = 'X';
    grid[1][1] = 'X';
    grid[2][2] = 'X';

    if(winner() == 'X')     status = E_OK;
    return status;
}

enum E_STATUS Test_Win_O_Diagonal(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][0] = 'O';
    grid[1][1] = 'O';
    grid[2][2] = 'O';

    if(winner() == 'O')     status = E_OK;
    return status;
}

enum E_STATUS Test_Win_X_Opposite_Diagonal(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][2] = 'X';
    grid[1][1] = 'X';
    grid[2][0] = 'X';

    if(winner() == 'X')     status = E_OK;
    return status;
}

enum E_STATUS Test_Win_O_Opposite_Diagonal(void)
{
    enum E_STATUS status = E_ERROR;

    grid[0][2] = 'O';
    grid[1][1] = 'O';
    grid[2][0] = 'O';

    if(winner() == 'O')     status = E_OK;
    return status;
}

enum E_STATUS Test_Invalid_Position(void)
{
    enum E_STATUS status;

    status = SavePlayerPosition(10);

    return status;
}

enum E_STATUS Test_Taken_Position(void)
{
    enum E_STATUS status;
    grid[0][0]='X';
    player = 'X';
    status = SavePlayerPosition(1);
    return status;
}

int main(void)
{

    enum E_STATUS status;
    status = Test_Win_X_Horizontal();
    if(status==E_OK)    printf("Test Case 1 passed\n");
    else                printf("Test Case 1 failed\n");

    status = Test_Win_O_Horizontal();
    if(status==E_OK)    printf("Test Case 2 passed\n");
    else                printf("Test Case 2 failed\n");

    status = Test_Win_X_Vertical();
    if(status==E_OK)    printf("Test Case 3 passed\n");
    else                printf("Test Case 3 failed\n");

    status = Test_Win_O_Vertical();
    if(status==E_OK)    printf("Test Case 4 passed\n");
    else                printf("Test Case 4 failed\n");

    status = Test_Win_X_Diagonal();
    if(status==E_OK)    printf("Test Case 5 passed\n");
    else                printf("Test Case 5 failed\n");

    status = Test_Win_O_Diagonal();
    if(status==E_OK)    printf("Test Case 6 passed\n");
    else                printf("Test Case 6 failed\n");

    status = Test_Win_X_Opposite_Diagonal();
    if(status==E_OK)    printf("Test Case 7 passed\n");
    else                printf("Test Case 7 failed\n");

    status = Test_Win_O_Opposite_Diagonal();
    if(status==E_OK)    printf("Test Case 8 passed\n");
    else                printf("Test Case 8 failed\n");

    status = Test_Invalid_Position();
    if(status==E_INVALID)    printf("Test Case 9 passed\n");
    else                     printf("Test Case 9 failed\n");

    status = Test_Taken_Position();
    if(status==E_TAKEN)    printf("Test Case 10 passed\n");
    else                   printf(" %d Test Case 10 failed\n",status);
    return 0;
}

