/***************************************************
 * File: Payment_implementation.c
 * Author: Kariman Karam
 * Date: 3 July 2021
 * Version: 1
 * Description: Declarations of functions for Payment System App
 **************************************************/

#include <stdio.h>
#include <string.h>
#include "Payment_header.h"



//Server Database
ST_accountBalance_t ST_accountBalance[20] = {100.00 , "123456789",
                                             6000.00, "234567891",
                                             3250.25, "567891234",
                                             1500.12, "456789123",
                                             500.00 , "258649173",
                                             2100.00, "654823719",
                                             0.00   , "971362485",
                                             1.00   , "793148625",
                                             10.12  , "123123456",
                                             0.55   , "456789321"
                                            };

/***********************************************
 * this function reads card data from terminal *
 ***********************************************/
EN_STATUS_t       readCardData(void)
{
    printf("Please Enter Card Data:\n");
    printf("Please Enter the Card Holder Name:\n");
    fflush(stdin);
    gets(ST_cardData.cardHolderName);

    printf("Please Enter the Primary Account Number:\n");
    fflush(stdin);
    gets(ST_cardData.primaryAccountNumber);

    printf("Please Enter the Expiry Date:\n");
    fflush(stdin);
    gets(ST_cardData.cardExpirationDate);
}

/**********************************************
 * this function prints card data to terminal *
 **********************************************/
void              printCardData(void)
{
    printf("Your Card Data is:\n");
    printf("Card Holder Name:\n");
    puts(ST_cardData.cardHolderName);

    printf("Primary Account Number:\n");
    puts(ST_cardData.primaryAccountNumber);

    printf("Expiry Date:\n");
    puts(ST_cardData.cardExpirationDate);

    printf("\n");
}

/*************************************************
 * this function to check if the card is expired *
 *************************************************/
EN_transStat_t    checkIfExpired(void)
{
    uint8_t i = strlen(ST_cardData.cardExpirationDate);
    uint8_t j = strlen(ST_terminalData.transactionDate);

    if(ST_cardData.cardExpirationDate[i] < ST_terminalData.transactionDate[j])
    {
        return DECLINED;
    }
    else if(ST_cardData.cardExpirationDate[i-1] < ST_terminalData.transactionDate[j-1])
    {
        return DECLINED;
    }
    else if(ST_cardData.cardExpirationDate[i-1] > ST_terminalData.transactionDate[j-1])
    {
        return APPROVED;
    }
    else if(ST_cardData.cardExpirationDate[i-1] == ST_terminalData.transactionDate[j-1])
    {
        i = i-3;
        j = j-3;
        if(ST_cardData.cardExpirationDate[i] < ST_terminalData.transactionDate[j])
        {
            return DECLINED;
        }
        else if(ST_cardData.cardExpirationDate[i-1] < ST_terminalData.transactionDate[j-1])
        {
            return DECLINED;
        }
        else if(ST_cardData.cardExpirationDate[i-1] > ST_terminalData.transactionDate[j-1])
        {
            return APPROVED;
        }
    }

}

/*************************************
 * this function reads terminal data *
 *************************************/
EN_STATUS_t       readTerminalData(void)
{
    ST_terminalData.maxTransAmount = 5000.00;

    printf("Please Enter Terminal Data:\n");
    printf("Please Enter the Transaction Amount:\n");
    fflush(stdin);
    scanf("%f",&ST_terminalData.transAmount);

    printf("Please Enter the Transaction Date DD/MM/Year:\n");
    fflush(stdin);
    gets(ST_terminalData.transactionDate);
}

/**************************************************
 * this function prints terminal data to terminal *
 **************************************************/
void              printTerminalData(void)
{
    printf("Terminal Data:\n");
    printf("Transaction Amount:\n");
    printf("%.2f\n",ST_terminalData.transAmount);

    printf("Transaction Date DD/MM/Year:\n");
    puts(ST_terminalData.transactionDate);

    printf("Max Transaction Amount:\n");
    printf("%.2f\n",ST_terminalData.maxTransAmount);
}

/*************************************************************
 * this function check If the amount is Accepted By Terminal *
 *************************************************************/
EN_transStat_t    checkIfAcceptedAmountByTerminal(void)
{
    if((double)ST_terminalData.transAmount <= (double)ST_terminalData.maxTransAmount)
    {
        return APPROVED;
    }
    else
    {
        return DECLINED;
    }
}
EN_STATUS_t       sendTransDataToServer(void)
{

}

/****************************************************************
 * this function searches for an element in the server database *
 ****************************************************************/
uint8_t linearSearchForCardID(void)
{
    uint8_t i;

    //printf("in search \n");

    for(i=0; i<10; i++)
    {
        //printf("in for inside search\n");
        if (strcmp(ST_accountBalance[i].primaryAccountNumber, ST_cardData.primaryAccountNumber) == 0)
        {
            //printf("\n***id=%d***\n",i);
            return i;
        }

    }

    return -1;
}

/*************************************************************
 * this function check If the amount is Accepted By Terminal *
 *************************************************************/
EN_transStat_t    checkIfPANExists(void)
{
    uint8_t cardID = linearSearchForCardID();

    //printf("cardID=%d   in PAN\n",cardID);
    if(cardID == 255)
    {
        //printf("in if inside PAN\n");
        return DECLINED;
    }
    else
    {
        //printf("in else inside PAN\n");
        return APPROVED;
    }
}


EN_transStat_t    checkIfAcceptedAmountByServer(void)
{
    uint8_t cardID = linearSearchForCardID();

    if((double)ST_accountBalance[cardID].balance >= (double)ST_terminalData.transAmount)
    {
        return APPROVED;
    }
    else
    {
        return DECLINED;
    }
}


EN_transStat_t  checkTransactionStatus(void)
{
    if(   checkIfAcceptedAmountByServer()   == APPROVED
            && checkIfAcceptedAmountByTerminal() == APPROVED
            && checkIfExpired()                  == APPROVED
            && checkIfPANExists()                == APPROVED)
    {
        return APPROVED;
    }
    else
    {
        return DECLINED;
    }
}
