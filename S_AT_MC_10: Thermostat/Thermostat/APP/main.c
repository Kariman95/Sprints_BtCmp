/***************************************************************
* Task		 : Thermostat
* File Name	 : main.c
* Description: main
* Author	 : Kariman Karam
* Date		 : 26/7/2021
***************************************************************/


/*- INCLUDES--------------------------------------------------*/
#include "Thermostat/Thermostat.h"
#include "../MCAL/UART/UART.h"
#include <avr/delay.h>

/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	Thermostat_Init();

	while(1)
	{
		Thermostat_Update();
	}//end while
	return 0;
}//end main
