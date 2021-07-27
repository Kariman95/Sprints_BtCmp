/***************************************************************
* Task       : Traffic Light System
* File Name  : TrafficLight.c
* Description: functions for the Traffic Light system app
* Author     : Kariman
* Date       : 13/7/2021
***************************************************************/

/*- INCLUDES -------------------------------------------------*/
#include "TrafficLight.h"
#include <string.h>


/*- APIs IMPLEMENTATION---------------------------------------*/

/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
***************************************************************/
void TrafficLight_Init(void)
{
	DIO_Init();
	LED_Init();
	UART_Init();
}//end TrafficLight_Init


/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
***************************************************************/
void TrafficLight_Update(void)
{
	uint8_t pu8String[255];
	uint8_t i=0;
	UART_ReceiveString(pu8String);

	if(strcmp(pu8String, "START")==0)
	{
		i = 1;
	}//end if

	else if(strcmp(pu8String, "WAIT")==0)
	{
		i = 2;
	}//end else if
	else if(strcmp(pu8String, "STOP")==0)
	{
		i = 3;
	}//end else if
	else if(strcmp(pu8String, "AT")==0)
	{
		i = 4;
	}//end else if

	switch(i)
	{
	case 1:
		LED_ON(LED0);
		LED_OFF(LED1);
		LED_OFF(LED2);
		UART_SendString((uint8_t*)"Green LED is on");
		break;

	case 2:
		LED_OFF(LED0);
		LED_OFF(LED1);
		LED_ON(LED2);
		UART_SendString((uint8_t*)"Yellow LED is on");
		break;

	case 3:
		LED_OFF(LED0);
		LED_ON(LED1);
		LED_OFF(LED2);
		UART_SendString((uint8_t*)"Red LED is on");
		break;

	case 4:
		UART_SendString((uint8_t*)"OK");
		break;

	default:
		LED_OFF(LED0);
		LED_OFF(LED1);
		LED_OFF(LED2);
		UART_SendString((uint8_t*)"Wrong input");
		break;
	}//end switch
}//end TrafficLight_Update
