/***************************************************
 * File: Payment_header.h
 * Author: Kariman Karam
 * Date: 3 July 2021
 * Version: 1
 * Description: Typedefs for standard data types
 **************************************************/

#ifndef PAYMENT_H_
#define PAYMENT_H_

#include "Data_Types.h"

/*******************************************************************
 * this struct to hold card data : Card Name, PAN, Expiration Date *
 *******************************************************************/
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
} ST_cardData_t;

/****************************************************************************************************
 * this struct to hold terminal data : Transaction Amount, Max Transaction Amount, Transaction Date *
 ****************************************************************************************************/
typedef struct ST_terminalData_t
{
    float   transAmount;
    float   maxTransAmount;
    uint8_t transactionDate[11];
} ST_terminalData_t;

/*************************************************************
 * this enum to hold transaction status : Declined, Approved *
 *************************************************************/
typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED
} EN_transStat_t;

/******************************************************************************************
 * this struct to hold transaction data : Card Data, Transaction Data, Transaction Status *
 ******************************************************************************************/
typedef struct ST_transaction_t
{
    ST_cardData_t       cardHolderData;
    ST_terminalData_t   transData;
    EN_transStat_t      transStat;
} ST_transaction_t;

/**********************************************************
 * this struct to hold server data : Account Balance, PAN *
 **********************************************************/
typedef struct ST_accountBalance_t
{
    float   balance;
    uint8_t primaryAccountNumber[20];
} ST_accountBalance_t;

/*********************************************************
 * this enum to check function return status : Error, Ok *
 *********************************************************/
typedef enum EN_STATUS_t
{
    EN_ERROR,
    EN_OK
} EN_STATUS_t;

/*********************************
 * Global Variables Declarations *
 *********************************/
ST_cardData_t       ST_cardData;
ST_terminalData_t   ST_terminalData;
EN_transStat_t      EN_transStat;
ST_transaction_t    ST_transaction;

/************************
 * Functions Prototypes *
 ************************/
EN_STATUS_t       readCardData(void);
EN_transStat_t    checkIfExpired(void);
EN_STATUS_t       readTerminalData(void);
EN_transStat_t    checkIfAcceptedAmountByTerminal(void);
EN_STATUS_t       sendTransDataToServer(void);
EN_transStat_t    checkIfPANExists(void);
EN_transStat_t    checkIfAcceptedAmountByServer(void);
uint8_t           linearSearchForCardID(void);
void              printCardData(void);
void              printTerminalData(void);
EN_transStat_t    checkTransactionStatus(void);

#endif // PAYMENT_H_
