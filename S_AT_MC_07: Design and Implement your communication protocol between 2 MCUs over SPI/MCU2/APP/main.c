/*- INCLUDES--------------------------------------------------*/
//#include "../MCAL/DIO/DIO_init.h"
//#include "../MCAL/DIO/DIO_cfg.h"
//#include "../MCAL/DIO/DIO_registers.h"
//#include "../MCAL/SPI/SPI.h"
//#include "../MCAL/SPI/SPI_Cfg.h"
//#include "../ECUAL/LED/LED.h"
//#include <string.h>
#include "APP.h"

/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
//	uint8_t pu8Data;
//	uint8_t* pu8Str;
//
//	SPI_init();
//	DDRC_R = 0xff;
	APP_Init();

	while(1)
	{
		APP_Update();

//		SPI_receiveData(&pu8Data);
//		PORTC_R = pu8Data;

//		SPI_receiveString(&pu8Str);
//		if(strcmp(&pu8Str,"hi")==0)
//		{
//			PORTC_R = 0x02;
//		}
	}//end while
	return 0;
}//end main
