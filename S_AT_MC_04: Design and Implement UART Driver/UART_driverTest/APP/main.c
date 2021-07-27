/***************************************************************
* Task		 : UART driver
* File Name	 : main.c
* Description: main
* Author	 : Kariman
* Date		 : 13/7/2021
***************************************************************/


/*- INCLUDES--------------------------------------------------*/
#include "../MCAL/DIO/DIO_init.h"
#include "../MCAL/UART/UART.h"
/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	uint8_t pu8String[255];
	DIO_Init();
	UART_Init();

	while(1)
	{
		UART_ReceiveString(pu8String);

		UART_SendString(pu8String);
	}//end while
	return 0;
}//end main
