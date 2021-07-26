/***********************************************************
* Task       : SPI Driver
* File Name  : DIO_cfg.c
* Description: configuration file for used dio pins
* Author     : Kariman
* Date       : 9/7/2021
************************************************************/

/*- INCLUDES----------------------------------------------*/
#include "DIO_init.h"


/*- GLOBAL VARIABLES-------------------------------------*/
const strDIOConfigType_t astrDIOConfigParameters[DIO_GROUPS_NO] =
{
	{ PC0, OUTPUT, NO_CONNECTION },		//LED0	0
	{ PC1, OUTPUT, NO_CONNECTION },		//LED1	1
	{ PC2, OUTPUT, NO_CONNECTION },		//LED2	2

	/* SPI Pins as a Slave */
	{ PB4, INPUT, PULL_UP_ENABLE },		//SS	3
	{ PB5, INPUT, NO_CONNECTION },		//MOSI	4
	{ PB6, OUTPUT,NO_CONNECTION },		//MISO	5
	{ PB7, INPUT, NO_CONNECTION },		//SCK	6
};
