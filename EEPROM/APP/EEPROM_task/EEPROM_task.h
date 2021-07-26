/*
 * EEPROM_task.h
 *
 *  Created on: Jul 26, 2021
 *      Author: Kariman
 */

#ifndef APP_EEPROM_TASK_EEPROM_TASK_H_
#define APP_EEPROM_TASK_EEPROM_TASK_H_

/*- INCLUDES --------------------------------------------------*/
#include "../../ECUAL/EEPROM_driver/EEPROM.h"
#include "../../MCAL/UART/UART.h"
#include "../../MCAL/I2C/I2C.h"

/*- APIs DECLARATIONS-----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
*************************************************************************************************/
void App_Init(void);


/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
*************************************************************************************************/
void App_Update(void);


#endif /* APP_EEPROM_TASK_EEPROM_TASK_H_ */
