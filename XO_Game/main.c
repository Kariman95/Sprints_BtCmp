#include <stdio.h>
#include <stdlib.h>
#include "XO_header.h"

int main()
{
    uint8_t check,pos;
    
    while(winner()=='n')    //while game not finished
    {
        printGrid();
        pos=play();
        SavePlayerPosition(pos);
        printGrid();
    }
    check = winner();
    if(check == 'X')        printf("X is the winner");
    else if(check == 'O')   printf("O is the winner");
    else                    printf("No winner");
    return 0;
}

