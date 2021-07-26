/***************************************************************
* Task		 : Traffic Light system
* File Name	 : main.c
* Description: main
* Author	 : Kariman
* Date		 : 13/7/2021
***************************************************************/


/*- INCLUDES--------------------------------------------------*/

#include "../MCAL/DIO/DIO_init.h"
#include "../MCAL/DIO/DIO_registers.h"
#include "../MCAL/I2C/I2C.h"


/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	uint8_t u8Add=0;
	uint8_t u8Data=0;

	DIO_Init();

//	PORTB_R = u8Data;
	TWI_initSlave();

	TWI_readDataWithACK(&u8Add);
	TWI_readDataWithACK(&u8Data);
	/*
	TWI_readDataWithACK(&u8Add);
	TWI_readDataWithACK(&u8Data);
	TWI_readDataWithACK(&u8Data);
	*/
	PORTB_R = u8Data;

	while(1);

	return 0;
}//end main
