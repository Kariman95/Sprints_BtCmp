#include <stdio.h>
#include <stdlib.h>
#include "Payment_header.h"

int main()
{
    readCardData();
    //printCardData();
    printf("\n");

    readTerminalData();
    //printTerminalData();
    //printf("%d\n", linearSearchForCardID());


    EN_transStat_t state = checkIfAcceptedAmountByServer();
    if(state == DECLINED)       printf("Declined\n");
    else                        printf("Approved\n");

    return 0;
}
