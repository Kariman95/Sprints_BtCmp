/***************************************************************
* Task		 : UART driver
* File Name	 : testCasesMain.c
* Description: main
* Author	 : Kariman
* Date		 : 13/7/2021
***************************************************************/


/*- INCLUDES--------------------------------------------------*/
#include "../MCAL/DIO/DIO_init.h"
#include "../MCAL/UART/UART_TestCases.h"
/*- MAIN FUNCTION---------------------------------------------*/

int main(void)
{
	DIO_Init();
	UART_Init();

	if(Test_UART_Init()==E_OK)
	{
		UART_SendString((uint8_t*)"Test_UART_Init passed");
	}
	else
	{
		UART_SendString((uint8_t*)"Test_UART_Init failed");
	}

	if(Test_UART_ReceiveData()==E_OK)
	{
		UART_SendString((uint8_t*)"Test_UART_ReceiveData passed");
	}
	else
	{
		UART_SendString((uint8_t*)"Test_UART_ReceiveData failed");
	}

	if(Test_UART_ReceiveString()==E_OK)
	{
		UART_SendString((uint8_t*)"Test_UART_ReceiveString passed");
	}
	else
	{
		UART_SendString((uint8_t*)"Test_UART_ReceiveString failed");
	}

	if(Test_UART_SendData()==E_OK)
	{
		UART_SendString((uint8_t*)"Test_UART_SendData passed");
	}
	else
	{
		UART_SendString((uint8_t*)"Test_UART_SendData failed");
	}

	if(Test_UART_SendString()==E_OK)
	{
		UART_SendString((uint8_t*)"Test_UART_SendString passed");
	}
	else
	{
		UART_SendString((uint8_t*)"Test_UART_SendString failed");
	}

	while(1)
	{
	}//end while
	return 0;
}//end main
