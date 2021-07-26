/***************************************************************
* Task		 : Traffic Light system
* File Name	 : main.c
* Description: main
* Author	 : Kariman
* Date		 : 13/7/2021
***************************************************************/


/*- INCLUDES--------------------------------------------------*/
#include "../MCAL/DIO/DIO_init.h"
#include "../MCAL/I2C/I2C.h"
#include <avr/delay.h>


/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	DIO_Init();

	TWI_initMatser();

	TWI_start();

	TWI_writeAddress((uint8_t)0x01);

	TWI_writeData(10);

	/*
	TWI_repeatedStart();
	TWI_writeAddress((uint8_t)0x01);
	TWI_writeData(9);
	*/

	TWI_stop();

	while(1)
	{

	}//end while
	return 0;
}//end main
