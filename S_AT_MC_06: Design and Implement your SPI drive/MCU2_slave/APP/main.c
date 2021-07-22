/***************************************************************
* Task		 : SPI Driver
* File Name	 : main.c
* Description: main
* Author	 : Kariman
* Date		 : 13/7/2021
***************************************************************/

/* SLAVE MCU */

/*- INCLUDES--------------------------------------------------*/
#include "../MCAL/DIO/DIO_init.h"
#include "../MCAL/DIO/DIO_cfg.h"
#include "../MCAL/DIO/DIO_registers.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/SPI/SPI_Cfg.h"
#include "../ECUAL/LED/LED.h"

/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	uint8_t pu8Data;

	SPI_init();
	DDRC_R = 0xff;

	while(1)
	{
		SPI_receiveData(&pu8Data);
		PORTC_R = pu8Data;
	}//end while
	return 0;
}//end main
