#include <stdio.h>
#include <stdlib.h>
#include "Payment_header.h"

int main()
{
    uint8_t c;
    do
    {
        system("cls");
        readCardData();
        //printCardData();
        printf("\n");

        readTerminalData();
        //printTerminalData();
        //printf("%d\n", linearSearchForCardID());
        printf("\nVerifying Data from the server...\n");

        EN_transStat_t state = checkTransactionStatus();
        if(state == DECLINED)       printf("The Transaction is Declined\n");
        else                        printf("The Transaction is Approved\n");

        printf("\nDo You Want to continue(y/n)?\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c == 'y');

    return 0;
}
