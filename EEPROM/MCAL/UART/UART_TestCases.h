/*****************************************************************************
* Task		 : UART Driver
* File Name	 : UART_TestCases.c
* Description: Header file for Test Cases for UART driver
* Author	 : Kariman
* Date		 : Jul 13, 2021
******************************************************************************/

#ifndef MCAL_UART_UART_TESTCASES_H_
#define MCAL_UART_UART_TESTCASES_H_

#include "UART.h"

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test UART initialization
*************************************************************************************************/
enuErrorStatus_t Test_UART_Init(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test sending data via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_SendData(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test sending string via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_SendString(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test receiving data via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_ReceiveData(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test receiving string via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_ReceiveString(void);


#endif /* MCAL_UART_UART_TESTCASES_H_ */
