/*****************************************************************************
* Task: Car Project
* File Name: main.c
* Description: main
* Author: TEAM2
* Date: 12/7/2021
******************************************************************************/


/*- INCLUDES----------------------------------------------*/
#include "Traffic_Light_System/TrafficLight.h"
#include <string.h>

/*- MAIN FUNCTION----------------------------------------------*/
int main(void)
{
	uint8_t* u8_String;
	uint8_t i =0;
	TrafficLight_Init();

	while(1)
	{
//		UART_ReceiveString(&u8_String);
//		UART_SendString(&u8_String);
////		i = strcmp(&u8_String, "start");
//		if(strcmp(&u8_String, "start")==0)
//		{
//			LED_ON(LED0);
//		}
		TrafficLight_Update();


	}
	return 0;
}
