/*
 * DIO_cfg.c
 *
 *  Created on: Jul 9, 2021
 *  Author: Kariman
 */

/*- INCLUDES----------------------------------------------*/
#include "DIO_init.h"


/*- GLOBAL VARIABLES-------------------------------------*/
const strDIOConfigType_t astrDIOConfigParameters[DIO_GROUPS_NO] =
{
	{ PA0, INPUT, PULL_UP_ENABLE },		//BTN0	0
	{ PA1, INPUT, PULL_UP_ENABLE },		//BTN1	1
	{ PA2, INPUT, PULL_UP_ENABLE },		//BTN2	2
	{ PC0, OUTPUT, NO_CONNECTION },		//LED0	3
	{ PC1, OUTPUT, NO_CONNECTION },		//LED1	4
	{ PC2, OUTPUT, NO_CONNECTION },		//LED2	5
	{ PA3, INPUT, PULL_UP_ENABLE }		//BTN3	6
};
