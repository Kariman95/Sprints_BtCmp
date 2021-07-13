/*****************************************************************************
* Task: Car Project
* File Name: main.c
* Description: main
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/


/*- INCLUDES----------------------------------------------*/
#include "Car_control_system/CAR.h"
#include "../MCAL/UART/UART.h"
#include "../ECUAL/LED/LED.h"
#include "../MCAL/UART/UART_TestCases.h"
#include <avr/delay.h>

/*- MAIN FUNCTION----------------------------------------------*/
int main(void)
{
	uint8_t *u8_Data = NULL_PTR;
//	App_Init();
	DIO_Init();
	UART_Init(9600);

//	if(		Test_UART_Init()
//			&& Test_UART_ReceiveData()
//			&& Test_UART_ReceiveString() && Test_UART_SendData()
//			&& Test_UART_SendString() == E_OK
//	  )
//	{
//		LED_ON(LED0);
//	}

	while(1)
	{
//		UART_ReceiveData(&u8_Data);
//		UART_SendData(u8_Data);

//		UART_RecieveDataNoBLOCKING(&u8_Data);
//		UART_SendDataNoBLOCKING('a');

		UART_ReceiveString(&u8_Data);
		UART_SendString(&u8_Data);

		u8_Data = NULL_PTR;
	}
	return 0;
}
