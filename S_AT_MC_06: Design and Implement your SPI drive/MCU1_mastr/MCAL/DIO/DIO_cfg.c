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

	/* SPI Pins as a Master */
	{ PB4, OUTPUT, NO_CONNECTION },		//SS	3
	{ PB5, OUTPUT, NO_CONNECTION },		//MOSI	4
	{ PB6, INPUT,  NO_CONNECTION },		//MISO	5
	{ PB7, OUTPUT, NO_CONNECTION },		//SCK	6
};
