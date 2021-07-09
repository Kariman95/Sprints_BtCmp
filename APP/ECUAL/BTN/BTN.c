/*
 * BTN.c
 *
 *  Created on: Jul 9, 2021
 *  Author: Kariman
 */


/*- INCLUDES----------------------------------------------*/
#include "BTN.h"
#include <avr/delay.h>

/*- APIs IMPLEMENTATION-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the button
*************************************************************************************************/
enuErrorStatus_t	BTN_Init(void)
{
	return DIO_Init();
}//end BTN_Init


/*************************************************************************************************
* Parameters (in) : u8_BtnNum(index to the button pin)
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to read the button status (pressed, not_pressed)
*************************************************************************************************/
enuErrorStatus_t	BTN_getState(uint8_t u8_BtnNum, uint8_t* u8_Status)
{
	if(u8_Status == NULL_PTR)	return E_ERROR;
	else
	{
		uint8_t u8_Data;

		DIO_Read(u8_BtnNum, &u8_Data);

		if(u8_Data == LOW)
		{
			_delay_us(10);
			if(u8_Data == LOW)	*u8_Status = PRESSED;
		}//end if
		else if(u8_Data == HIGH)
		{
			_delay_us(10);
			if(u8_Data == HIGH)	*u8_Status = NOT_PRESSED;
		}//end else if

		return E_OK;
	}//end else
}//end BTN_getState
