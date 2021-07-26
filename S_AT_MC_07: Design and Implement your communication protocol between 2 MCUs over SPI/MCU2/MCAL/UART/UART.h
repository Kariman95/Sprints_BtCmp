/*****************************************************************************
* Task		 : UART Driver
* File Name	 : UART.h
* Description: header file for UART driver
* Author	 : Kariman
* Date		 : Jul 13, 2021
******************************************************************************/

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/Data_types.h"
#include "../../LIB/BIT_math.h"

#define     F_CPU    8000000UL
#define 	MAXSIZE	 255

// define some macros
//#define BAUD 9600                                   // define baud
//#define BAUDRATE (((F_CPU)/(16UL*BAUD))-1)            // set baud rate value for UBRR

/*- FUNCTION PROTOTYPES ----------------------------------*/
/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the UART protocol
*************************************************************************************************/
enuErrorStatus_t UART_Init(void);

/*************************************************************************************************
* Parameters (in) : u16Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendData(uint8_t u16Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu16Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint8_t* pu16Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu16Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART
*************************************************************************************************/
enuErrorStatus_t UART_RecieveDataNoBLOCK(uint8_t* pu16Data);

/*************************************************************************************************
* Parameters (in) : pu8String
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send string via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* pu8String);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu8String
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive string via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* pu8String);

/*************************************************************************************************
* Parameters (in) : u16Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART without blocking the system
*************************************************************************************************/
enuErrorStatus_t UART_SendDataNoBLOCK(uint8_t u16Data);


#endif /* MCAL_UART_UART_H_ */
