
/***************************************************************
* Task       : Traffic Light System
* File Name  : TrafficLight.c
* Description: functions for the Traffic Light system app
* Author     : Kariman
* Date       : 22/7/2021
***************************************************************/

/*- INCLUDES -------------------------------------------------*/
#include "APP.h"
#include <string.h>


/*- APIs IMPLEMENTATION---------------------------------------*/

/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
***************************************************************/
void APP_Init(void)
{
	DIO_Init();
	SPI_init();
	UART_Init();

}//end APP_Init


/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
***************************************************************/
void APP_Update(void)
{
	uint8_t pu8String[255];

	SPI_receiveString(pu8String);

	UART_SendString(pu8String);

}//end APP_Update
