/*****************************************************************************
* Task       : Thermostat
* File Name  : Thermostat.c
* Description: Header file for Thermostat project
* Author     : Kariman Karam
* Date       : 26/7/2021
******************************************************************************/
#include "../../MCAL/UART/UART.h"
#include "Thermostat.h"
#include <stdlib.h>
#include <avr/delay.h>

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A static function to calculate the temperature value
*************************************************************************************************/
static void Temp_Sensor(uintt16_t* u16Temp)
{
	uintt16_t adc_read = ADC_Read(ADC0);
	uintt16_t volt = ((unsigned long)5000 * adc_read)/1024;
	*u16Temp =  volt /10;
}//end Temp_Sensor

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the thermostat
*************************************************************************************************/
void Thermostat_Init(void)
{
	DIO_Init();
	ADC_init(ADC_PRESCALLER_64,ADC_AVCC);
	LCD_init();

	/* Motor Direction */
	DIO_Write(MOTORIN1, HIGH);
	DIO_Write(MOTORIN2, LOW);

	LCD_displayStringRowColumn(0, 2, (uint8_t*)"Thermostat");
	LCD_displayStringRowColumn(1, 0, (uint8_t*)"Desired Temp= ");
	LCD_displayStringRowColumn(2, 0, (uint8_t*)"Current Temp= ");
}//end Thermostat_Init

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the thermostat
*************************************************************************************************/
void Thermostat_Update(void)
{
	uint8_t   u8KeyBuffer[2];
	uint8_t	  u8Key;
	uintt16_t u16DesiredTemp=0;
	uintt16_t u16CurrentTemp;

	/* Get the current temp from ADC and display it on LCD */
	Temp_Sensor(&u16CurrentTemp);
	LCD_goToRowColumn(2, 13);
	LCD_intgerToString(u16CurrentTemp);

	/* Get the desired temp from Keypad */
	KeyPad_getPressedKey(&u8KeyBuffer[0]);
	_delay_ms(500); /* Press time */
	KeyPad_getPressedKey(&u8KeyBuffer[1]);
	_delay_ms(500); /* Press time */
	KeyPad_getPressedKey(&u8Key);
	_delay_ms(500); /* Press time */
	if(u8Key=='=')
	{
		u16DesiredTemp = ((u8KeyBuffer[0])*10) + (u8KeyBuffer[1]);
//		LCD_goToRowColumn(3, 0);
//		LCD_intgerToString(u16DesiredTemp);
	}

	/* LCD */
	LCD_goToRowColumn(1, 13);
	LCD_intgerToString(u16DesiredTemp);

	/* Check if the current is less or more than the desired temp */
	if(u16CurrentTemp <= u16DesiredTemp)
	{
		DIO_Write(MOTORIEN1, LOW);
	}//end if
	else
	{
		DIO_Write(MOTORIEN1, HIGH);
	}//end else
}//end Thermostat_Update
