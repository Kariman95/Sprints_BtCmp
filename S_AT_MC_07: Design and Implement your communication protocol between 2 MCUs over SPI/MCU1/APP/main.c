/*- INCLUDES--------------------------------------------------*/
//#include "../MCAL/DIO/DIO_init.h"
//#include "../MCAL/DIO/DIO_cfg.h"
//#include "../MCAL/SPI/SPI.h"
//#include "../MCAL/SPI/SPI_Cfg.h"
//#include "../MCAL/UART/UART.h"
#include "APP.h"

/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
//	uint8_t* pu8String;
//	DIO_Init();
//	SPI_init();
//	UART_Init();
	APP_Init();
	while(1)
	{
		APP_Update();
//		UART_ReceiveString(&pu8String);
//		UART_SendString(&pu8String);
//		SPI_sendData(5);
//		SPI_sendString((uint8_t*)"hi");
	}//end while
	return 0;
}//end main
