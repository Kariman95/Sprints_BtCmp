/*****************************************************************************
* Task: Car Project
* File Name: DIO_cfg.c
* Description: configuration file for used dio pins
* Author: TEAM2
* Date: 9/7/2021
******************************************************************************/

/*- INCLUDES----------------------------------------------*/
#include "DIO_init.h"


/*- GLOBAL VARIABLES-------------------------------------*/
const strDIOConfigType_t astrDIOConfigParameters[DIO_GROUPS_NO] =
{
/*
	{ PA1, INPUT, PULL_UP_ENABLE },		//BTN0	0
	{ PA2, INPUT, PULL_UP_ENABLE },		//BTN1	1
	{ PA3, INPUT, PULL_UP_ENABLE },		//BTN2	2
	{ PA4, INPUT, PULL_UP_ENABLE },		//BTN3	3
*/
	/*    LCD Control Pins      */
	{ PA5, OUTPUT, NO_CONNECTION },		//RS	0
	{ PA6, OUTPUT, NO_CONNECTION },		//RW	1
	{ PA7, OUTPUT, NO_CONNECTION },		//E		2
	{ PB0, OUTPUT, NO_CONNECTION },		//D4	3
	{ PB1, OUTPUT, NO_CONNECTION },		//D5	4
	{ PB2, OUTPUT, NO_CONNECTION },		//D6	5
	{ PB3, OUTPUT, NO_CONNECTION },		//D7	6

	{ PC1, OUTPUT, NO_CONNECTION },		//LED1	7
	{ PC2, OUTPUT, NO_CONNECTION },		//LED2	8
	{ PC0, OUTPUT, NO_CONNECTION },		//LED0	9

	{ PB4, OUTPUT, NO_CONNECTION },		//SS	10
	{ PB5, OUTPUT, NO_CONNECTION },		//MOSI	11
	{ PB6, INPUT,  NO_CONNECTION },		//MISO	12
	{ PB7, OUTPUT, NO_CONNECTION },		//SCK	13

	{ PD0, INPUT,  NO_CONNECTION },		//RX	14
	{ PD1, OUTPUT, NO_CONNECTION },		//TX	15

	/* Keypad Pins */
	{ PC6, OUTPUT, NO_CONNECTION },		//RA	16
	{ PC7, OUTPUT, NO_CONNECTION },		//RB	17
	{ PD2, OUTPUT, NO_CONNECTION },		//RC	18
	{ PD3, OUTPUT, NO_CONNECTION },		//RD	19
	{ PD4, INPUT,  PULL_UP_ENABLE },	//C1	20
	{ PD5, INPUT,  PULL_UP_ENABLE },	//C2	21
	{ PD6, INPUT,  PULL_UP_ENABLE },	//C3	22
	{ PD7, INPUT,  PULL_UP_ENABLE },	//C4	23

	{ PA0, INPUT,  NO_CONNECTION },		//ADC0	24

	{ PC3, OUTPUT, NO_CONNECTION },		//MOTORIN1	25
	{ PC4, OUTPUT, NO_CONNECTION },		//MOTORIN2	26
	{ PC5, OUTPUT, NO_CONNECTION }		//MOTORIEN1	27
};
