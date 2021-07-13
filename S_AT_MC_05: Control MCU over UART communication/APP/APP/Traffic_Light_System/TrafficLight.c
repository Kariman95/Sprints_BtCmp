
/*****************************************************************************
* Task: Car Project
* File Name: CAR.c
* Description: functions for the car control system app
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/

/*- INCLUDES --------------------------------------------------*/
#include "TrafficLight.h"
#include <string.h>


/*- APIs IMPLEMENTATION-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
*************************************************************************************************/
void TrafficLight_Init(void)
{
	DIO_Init();
	LED_Init();
	UART_Init(9600);
}//end TrafficLight_Init


/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
*************************************************************************************************/
void TrafficLight_Update(void)
{
	uint8_t* u8_String = NULL_PTR;
	uint8_t i=0;
	UART_ReceiveString(&u8_String);

	if(strcmp(&u8_String, "start")==0)
	{
		i = 1;
	}//end if

	else if(strcmp(&u8_String, "wait")==0)
	{
		i = 2;
	}//end else if
	else if(strcmp(&u8_String, "stop")==0)
	{
		i = 3;
	}//end else if
	else if(strcmp(&u8_String, "AT")==0)
	{
		i = 4;
	}//end else if

	switch(i)
	{
	case 1:
		u8_String = NULL_PTR;
		LED_ON(LED0);
		LED_OFF(LED1);
		LED_OFF(LED2);
		UART_SendString((uint8_t*)"Green LED is on");
		break;
	case 2:
		u8_String = NULL_PTR;
		LED_OFF(LED0);
		LED_OFF(LED1);
		LED_ON(LED2);
		UART_SendString((uint8_t*)"Yellow LED is on");
		break;
	case 3:
		u8_String = NULL_PTR;
		LED_OFF(LED0);
		LED_ON(LED1);
		LED_OFF(LED2);
		UART_SendString((uint8_t*)"Red LED is on");
		break;
	case 4:
		u8_String = NULL_PTR;
		UART_SendString((uint8_t*)"OK");
		break;
	default:
		u8_String = NULL_PTR;
		LED_OFF(LED0);
		LED_OFF(LED1);
		LED_OFF(LED2);
		UART_SendString((uint8_t*)"Wrong input");
		break;
	}//end switch
}//end TrafficLight_Update
