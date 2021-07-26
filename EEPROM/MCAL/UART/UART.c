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

enuErrorStatus_t genuUARTInitStatus = E_ERROR;

/*- FUNCTION IMPLEMENTATINS ----------------------------------*/
/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the UART protocol
*************************************************************************************************/
enuErrorStatus_t UART_Init(void)
{
//    UBRRH_R = (BAUDRATE>>8);                      // shift the register right by 8 bits
//    UBRRL_R = BAUDRATE;                           // set baud


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

	genuUARTInitStatus = E_OK;

	//Set baud rate
//	uint16_t UBRRVAL=(F_CPU/(u16_Baudrate*16UL))-1;
//	UBRRL_R=UBRRVAL; 			//low byte
//	UBRRH_R=(UBRRVAL>>8); 	//high byte

	return genuUARTInitStatus;
}//end UART_Init

/*************************************************************************************************
* Parameters (in) : u16Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendData(uint8_t u8Data)
{
	if(genuUARTInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	/* Wait for empty transmit buffer */
	while (!(GET_BIT(UCSRA_R, UDRE_B)));

	/* Put data into buffer, sends the data */
	UDR_R = u8Data;

	return E_OK;
}//end UART_SendData

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu16Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint8_t* pu8Data)
{
	if(genuUARTInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	/* Wait for data to be received */
	while(!(GET_BIT(UCSRA_R, RXC_B)));

	/* Get and return received data from buffer */
	*pu8Data = UDR_R;

	return E_OK;
}//end UART_ReceiveData

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu16Data
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive data via UART
*************************************************************************************************/
enuErrorStatus_t UART_RecieveDataNoBLOCK(uint8_t* pu8Data)
{
	if(genuUARTInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	enuErrorStatus_t enuStatus = E_ERROR;

    if (GET_BIT(UCSRA_R, RXC_B))
    {
        *pu8Data = UDR_R;
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
* Parameters (in) : u16Data
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send data via UART without blocking the system
*************************************************************************************************/
enuErrorStatus_t UART_SendDataNoBLOCK(uint8_t u8Data)
{
	if(genuUARTInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	enuErrorStatus_t enuStatus = E_ERROR;

    if (GET_BIT(UCSRA_R, UDRE_B))
    {
        UDR_R = u8Data;
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
* Parameters (in) : pu8String
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to send string via UART
*************************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* pu8String)
{
	uint8_t u8i=0;

	if(genuUARTInitStatus == E_ERROR || pu8String == NULL_PTR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	for(u8i=0; u8i<MAXSIZE; u8i++)
	{
		UART_SendData(pu8String[u8i]);
		if(pu8String[u8i] =='\0')
		{
			break;
		}
	}
	UART_SendData('\r');
	UART_SendData('\n');

	return E_OK;
}//end UART_SendString

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): pu8String
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to receive string via UART
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* pu8String)
{
	uint8_t u8i=0;

	if(genuUARTInitStatus == E_ERROR)
	{
		//if uart is not initialized
		return E_ERROR;
	}//end if

	for(u8i=0; u8i<MAXSIZE; u8i++)
	{
		UART_ReceiveData(&pu8String[u8i]);
		if(pu8String[u8i] =='\r' || pu8String[u8i] =='\n')
		{
			break;
		}
	}
	pu8String[u8i]='\0';
	return E_OK;
}//end UART_ReceiveString

