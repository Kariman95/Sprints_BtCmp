/*****************************************************************************
* Task		 : UART Driver
* File Name	 : UART.c
* Description: functions for UART driver
* Author	 : Kariman
* Date		 : Jul 13, 2021
******************************************************************************/

/*- INCLUDES ----------------------------------*/
#include "UART.h"
#include "UART_registers.h"

enuErrorStatus_t genuInitStatus = E_ERROR;

/*- FUNCTION IMPLEMENTATINS ----------------------------------*/
/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the UART protocol
*************************************************************************************************/
enuErrorStatus_t UART_Init(unsigned short int baudrate)
{
	//uart double speed node
	SET_BIT(UCSRA_R, U2X_B);
	// UART receiver enable
	SET_BIT(UCSRB_R, RXEN_B);

	//UART Transmit enable
	SET_BIT(UCSRB_R, TXEN_B);

	//UART Asynchronous
	CLR_BIT(UCSRC_R, UMSEL_B);

	//parity disable
	CLR_BIT(UCSRC_R, UPM1_B);
	CLR_BIT(UCSRC_R, UPM0_B);

	//STOP bit selection 1 stop bit selected here
	CLR_BIT(UCSRC_R, USBS_B);

	// Character size selection (8 bit data selected here)
	SET_BIT(UCSRC_R, UCSZ0_B);
	SET_BIT(UCSRC_R, UCSZ1_B);
	SET_BIT(UCSRB_R, UCSZ2_B);

	//Set baud rate

	// Baud rate= 9600 .. F_cpu 8MHz
	UBRRH_R=0;
	UBRRL_R=103;

	genuInitStatus = E_OK;

//		UBRRL_R = (uint8_t)baudrate;
//	   /* Set Baud Rate high bits if needed */
//	   if(baudrate > 255)
//	   {
//		   UBRRH_R = (uint8_t)( baudrate >> 8 );
//	   }
//	   else
//	   {
//		   UBRRH_R = 0;
//	   }

	return genuInitStatus;
}//end UART_Init

/*************************************************************************************************
* Parameters (in) : u8_Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendData(uint8_t u8_Data)
{
	if(genuInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	/* Wait for empty transmit buffer */
	while (!(GET_BIT(UCSRA_R, UDRE_B)));

	/* Put data into buffer, sends the data */
	UDR_R=u8_Data;

	return E_OK;
}//end UART_SendData

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu8_Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint8_t* pu8_Data)
{
	if(genuInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	/* Wait for data to be received */
	while(!(GET_BIT(UCSRA_R, RXC_B)));

	/* Get and return received data from buffer */
	*pu8_Data = UDR_R;

	return E_OK;
}//end UART_ReceiveData

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu8_Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART without blocking the system
*************************************************************************************************/
enuErrorStatus_t UART_RecieveDataNoBLOCKING(uint8_t* pu8_Data)
{
	if(genuInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	enuErrorStatus_t enuStatus = E_ERROR;

    if (GET_BIT(UCSRA_R, RXC_B))
    {
        *pu8_Data =UDR_R;
        enuStatus = E_OK;
    }
    else
    {
        /* do nothing */
    }
    return enuStatus;

	return E_OK;
}//end UART_RecieveDataNoBLOCKING

/*************************************************************************************************
* Parameters (in) : u8_Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART without blocking the system
*************************************************************************************************/
enuErrorStatus_t UART_SendDataNoBLOCKING(uint8_t u8_Data)
{
	if(genuInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	enuErrorStatus_t enuStatus = E_ERROR;

    if (GET_BIT(UCSRA_R, UDRE_B))
    {
        UDR_R = u8_Data;
        enuStatus = E_OK;
    }
    else
    {
        /* do nothing */
    }
    return enuStatus;

	return E_OK;
}//end UART_RecieveDataNoBLOCKING


/*************************************************************************************************
* Parameters (in) : u8_String
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send string via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* u8_String)
{
	uint8_t u8_i=0;

	if(genuInitStatus == E_ERROR || u8_String == NULL_PTR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	while (u8_String[u8_i]!='\0')
	{
		UART_SendData(u8_String[u8_i]);
		u8_i++;
	}//end while

	return E_OK;
}//end UART_SendString

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): u8_String
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive string via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* u8_String)
{
	if(genuInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	uint8_t u8_i=0;

	UART_ReceiveData(&u8_String[u8_i]);

	while(u8_String[u8_i] !='$')
	{
		u8_i++;
		UART_ReceiveData(&u8_String[u8_i]);
	}
	u8_String[u8_i]='\0';

	return E_OK;
}//end UART_ReceiveString

