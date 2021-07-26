/*
 * EEPROM_task.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Kariman
 */

#include "EEPROM_task.h"
#include "../../MCAL/DIO/DIO_init.h"
#include "../../MCAL/DIO/DIO_registers.h"
#include <string.h>
#include <stdlib.h>
#include <avr/delay.h>

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
*************************************************************************************************/
void App_Init(void)
{
	DIO_Init();
	UART_Init();
	EEPROM_init();
}//END App_Init

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
*************************************************************************************************/
void App_Update(void)
{
	uint8_t pu8String[255];
	uint8_t pu8AddString[16];
	uint8_t pu8DataString[2];
	uintt16_t u16Address;
	uint8_t u8Data;

	UART_SendString((uint8_t*)"Enter a command: ");
	UART_ReceiveString(pu8String);

	if(strcmp(pu8String, (uint8_t*)"WRITE")==0)
	{
		UART_SendString((uint8_t*)"Enter Address: ");
		UART_ReceiveString(pu8AddString);
		u16Address = atoi(pu8AddString);
		UART_SendString((uint8_t*)"OK");
		UART_SendString((uint8_t*)"Enter Data: ");
		UART_ReceiveData(&u8Data);
		u8Data=u8Data-'0';
		UART_SendString((uint8_t*)"\rOK");
		EEPROM_writeByte(u16Address, u8Data);
	}//end if
	else if(strcmp(pu8String, (uint8_t*)"READ")==0)
	{
		UART_SendString((uint8_t*)"Enter Address: ");
		UART_ReceiveString(pu8AddString);
		u16Address = atoi(pu8AddString);
		UART_SendString((uint8_t*)"OK");
		_delay_ms(10);
		EEPROM_readByte(u16Address, &u8Data);
		UART_SendString((uint8_t*)"The data stored is: ");
		UART_SendData(u8Data+'0');
		UART_SendData('\r');
		PORTB_R = u8Data;
	}//end else if
}//END App_Update
