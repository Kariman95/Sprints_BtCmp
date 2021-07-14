/***************************************************************
* Task       : Traffic Light System
* File Name  : TrafficLight.h
* Description: header file for taffic light app
* Author     : Kariman
* Date       : 13/7/2021
***************************************************************/

#ifndef APP_TRAFFIC_LIGHT_SYSTEM_TRAFFICLIGHT_H_
#define APP_TRAFFIC_LIGHT_SYSTEM_TRAFFICLIGHT_H_

/*- INCLUDES -------------------------------------------------*/
#include "../../ECUAL/LED/LED.h"
#include "../../MCAL/UART/UART.h"

/*- APIs DECLARATIONS-----------------------------------------*/

/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the application
***************************************************************/
void TrafficLight_Init(void);


/***************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to update the application
***************************************************************/
void TrafficLight_Update(void);


#endif /* APP_TRAFFIC_LIGHT_SYSTEM_TRAFFICLIGHT_H_ */
