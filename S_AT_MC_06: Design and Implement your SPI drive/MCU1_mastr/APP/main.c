/***************************************************************
* Task		 : SPI driver
* File Name	 : main.c
* Description    : main
* Author	 : Kariman
* Date		 : 13/7/2021
***************************************************************/

/* MASTER MCU */

/*- INCLUDES--------------------------------------------------*/
#include "../MCAL/DIO/DIO_init.h"
#include "../MCAL/DIO/DIO_cfg.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/SPI/SPI_Cfg.h"
#include "../ECUAL/LED/LED.h"

/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	DIO_Init();
	SPI_init();

	while(1)
	{
		SPI_sendData(5);
	}//end while
	return 0;
}//end main
