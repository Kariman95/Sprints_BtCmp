/*****************************************************************************
* Task       : Thermostat
* File Name  : Thermostat.h
* Description: Header file for Thermostat project
* Author     : Kariman Karam
* Date       : 26/7/2021
******************************************************************************/

#ifndef APP_THERMOSTAT_THERMOSTAT_H_
#define APP_THERMOSTAT_THERMOSTAT_H_

/*- INCLUDES--------------------------------------------------*/
#include "../../ECUAL/KEYPAD/KEYPAD.h"
#include "../../ECUAL/LCD/LCD.h"
#include "../../MCAL/ADC/ADC.h"

/*- APIs DECLARATIONS-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the thermostat
*************************************************************************************************/
void Thermostat_Init(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the thermostat
*************************************************************************************************/
void Thermostat_Update(void);

#endif /* APP_THERMOSTAT_THERMOSTAT_H_ */
