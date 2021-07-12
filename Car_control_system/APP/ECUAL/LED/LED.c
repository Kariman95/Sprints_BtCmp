/*****************************************************************************
* Task: Car Project
* File Name: led.c
* Description: functions for the led driver
* Author: TEAM2
* Date: 9/7/2021
******************************************************************************/

/*- INCLUDES----------------------------------------------*/
#include "LED.h"


/*- APIs IMPLEMENTATION-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to initialize the led
*************************************************************************************************/
enuErrorStatus_t	LED_Init(void)
{
	return DIO_Init();
}//end LED_Init


/*************************************************************************************************
* Parameters (in) : u8_LedNum(index to the led pin)
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to turn the led on
*************************************************************************************************/
enuErrorStatus_t	LED_ON(uint8_t u8_LedNum)
{
	DIO_Write(u8_LedNum, HIGH);
	return E_OK;
}//end LED_ON


/*************************************************************************************************
* Parameters (in) : u8_LedNum(index to the led pin)
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to turn the led off
*************************************************************************************************/
enuErrorStatus_t	LED_OFF(uint8_t u8_LedNum)
{
	DIO_Write(u8_LedNum, LOW);
	return E_OK;

}//end LED_OFF


/*************************************************************************************************
* Parameters (in) : u8_LedNum(index to the led pin)
* Parameters (out): None
* Return Value    : enuErrorStatus_t - For error handling if the user input an invalid parameter
* Description     : A function to toggle the led
*************************************************************************************************/
enuErrorStatus_t	LED_toggle(uint8_t u8_LedNum)
{
	DIO_toggle(u8_LedNum);
	return E_OK;
}
