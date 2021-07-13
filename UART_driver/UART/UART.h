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

/*- FUNCTION PROTOTYPES ----------------------------------*/
/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the UART protocol
*************************************************************************************************/
enuErrorStatus_t UART_Init(unsigned short int baudrate);

/*************************************************************************************************
* Parameters (in) : u8_Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendData(uint8_t u8_Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu8_Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint8_t* pu8_Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu8_Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART
*************************************************************************************************/
enuErrorStatus_t UART_RecieveDataNoBLOCKING(uint8_t* pu8_Data);

/*************************************************************************************************
* Parameters (in) : u8_String
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send string via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* u8_String);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): u8_String
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive string via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* u8_String);

/*************************************************************************************************
* Parameters (in) : u8_Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART without blocking the system
*************************************************************************************************/
enuErrorStatus_t UART_SendDataNoBLOCKING(uint8_t pu8_Data);


#endif /* MCAL_UART_UART_H_ */
