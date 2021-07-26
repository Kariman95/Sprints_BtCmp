/***************************************************************
* Task       : UART and SPI communication
* File Name	 : APP.h
* Description: header file
* Author     : Kariman
* Date       : 22/7/2021
***************************************************************/

#ifndef APP_APP_H_
#define APP_APP_H_


/*- INCLUDES -------------------------------------------------*/
#include "../MCAL/DIO/DIO_init.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/UART/UART.h"

/*- APIs DECLARATIONS-----------------------------------------*/

/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
***************************************************************/
void APP_Init(void);


/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
***************************************************************/
void APP_Update(void);


#endif /* APP_APP_H_ */
