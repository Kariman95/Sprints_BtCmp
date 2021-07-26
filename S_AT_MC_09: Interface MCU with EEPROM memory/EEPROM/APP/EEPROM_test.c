///*
// * EEPROM_test.c
// *
// *  Created on: Jul 26, 2021
// *      Author: Kariman
// */
//
///*- INCLUDES--------------------------------------------------*/
//
//#include "../MCAL/DIO/DIO_init.h"
//#include "../MCAL/DIO/DIO_registers.h"
//#include "../ECUAL/EEPROM_driver/EEPROM.h"
//#include <avr/delay.h>
//
//
///*- MAIN FUNCTION---------------------------------------------*/
//int main(void)
//{
//	uint8_t u8Data;
//	DIO_Init();
////	PORTB_R = 0xff;
//	/* Init EEPROM */
//	EEPROM_init();
//
//	EEPROM_writeByte(0x0311, 0x05); /* Write 0x0F in the external EEPROM */
//	_delay_ms(10);
//	EEPROM_readByte(0x0311, &u8Data);  /* Read 0x0F from the external EEPROM */
//	while(1)
//	{
//		PORTB_R = u8Data; /* out the read value from the external EEPROM */
//	}
//	return 0;
//}//end main
