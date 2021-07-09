/*
 * main.c
 *
 *  Created on: Jul 9, 2021
 *  Author: Kariman
 */
/*- INCLUDES----------------------------------------------*/
#include <avr/delay.h>

#include "../MCAL/DIO/DIO_cfg.h"
#include "../MCAL/DIO/DIO_init.h"

#include "../ECUAL/BTN/BTN.h"
#include "../ECUAL/LED/LED.h"


int main(void)
{
	uint8_t u8_Status0;

	DIO_Init();

	LED_OFF(LED0);
	LED_OFF(LED1);
	LED_OFF(LED2);

	while(1)
	{
		BTN_getState(BTN0, &u8_Status0);
		if( u8_Status0 == PRESSED)
		{
			LED_toggle(LED0);
			LED_toggle(LED1);
			LED_toggle(LED2);
		}
	}
	return 0;
}
