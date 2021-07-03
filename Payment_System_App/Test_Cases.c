/***************************************************
 * File: Test_Cases.c
 * Author: Kariman Karam
 * Date: 3 July 2021
 * Version: 1
 * Description: Test Cases for Payment App
 **************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "Payment_header.h"

void TestApprovedPayment(void)
{
    readCardData();
    readTerminalData();

    if(checkTransactionStatus() == APPROVED)
    {
        printf("Accepted Transaction\n Test Case 1 Passed\n");
    }
    else
    {
        printf("Declined Transaction\n Test Case 1 Failed\n");
    }
}

void TestDeclinedForExpiredCard(void)
{
    readCardData();
    readTerminalData();

    if(checkIfExpired() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 2 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 2 Failed\n");
    }
}

void TestForDeclinedAmountByServer(void)
{
    readCardData();
    readTerminalData();

    if(checkIfAcceptedAmountByServer() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 3 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 3 Failed\n");
    }
}

void TestForDeclinedAmountByTerminal(void)
{
    readCardData();
    readTerminalData();

    if(checkIfAcceptedAmountByTerminal() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 3 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 3 Failed\n");
    }
}

void TestFor_PAN_NotExist(void)
{
    readCardData();
    readTerminalData();

    if(checkIfPANExists() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 3 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 3 Failed\n");
    }
}

int main(void)
{
    TestApprovedPayment();
    TestDeclinedForExpiredCard();
    TestForDeclinedAmountByServer();
    TestForDeclinedAmountByTerminal();
    TestFor_PAN_NotExist();
    return 0;
}
