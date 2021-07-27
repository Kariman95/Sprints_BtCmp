/*****************************************************************************
* Task		 : UART Driver
* File Name	 : UART_TestCases.c
* Description: Test Cases for UART driver
* Author	 : Kariman
* Date		 : Jul 13, 2021
******************************************************************************/

/*- INCLUDES----------------------------------------------*/
#include "UART_TestCases.h"

/*- GLOBAL VARIABLES----------------------------------------------*/
extern enuErrorStatus_t genuUARTInitStatus;


/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test UART initialization
*************************************************************************************************/
enuErrorStatus_t Test_UART_Init(void)
{
	return genuUARTInitStatus;
}//end Test_UART_Init

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test sending data via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_SendData(void)
{
	return UART_SendData('k');
}//end Test_UART_Init

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test sending string via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_SendString(void)
{
	return UART_SendString((uint8_t*)"Hello");
}//end Test_UART_Init

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test receiving data via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_ReceiveData(void)
{
	uint8_t pu8_Data;
	return UART_ReceiveData(&pu8_Data);
}//end Test_UART_Init

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to test receiving string via UART
*************************************************************************************************/
enuErrorStatus_t Test_UART_ReceiveString(void)
{
	uint8_t *u8_String;
	return UART_ReceiveString(&u8_String);
}//end Test_UART_Init

