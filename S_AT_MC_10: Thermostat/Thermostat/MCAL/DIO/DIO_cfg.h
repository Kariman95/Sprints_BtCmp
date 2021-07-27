/*****************************************************************************
* Module     : DIO driver
* File Name  : DIO_cfg.h
* Description: Header file for used DIO pins
* Author     : Kariman Karam
* Date       : 9/7/2021
******************************************************************************/

#ifndef MCAL_DIO_DIO_CFG_H_
#define MCAL_DIO_DIO_CFG_H_

/*- DEFINES -----------------------------------------------*/
#define		DIO_GROUPS_NO	28u


/*   LCD Pins  */
#define   RS	0
#define   RW	1
#define   E		2
#define   D4	3
#define   D5	4
#define   D6	5
#define   D7	6

/*  LED Pins   */
#define   LED1	7
#define   LED2	8
#define   LED0	9

/*  SPI Pins   */
#define   SS	10
#define   MOSI	11
#define   MISO	12
#define   SCK	13

/*  UART Pins  */
#define   RX	14
#define   TX	15

/*  Keypad Pins */
#define   ROWA	16
#define   ROWB	17
#define   ROWC	18
#define   ROWD	19
#define   COL1	20
#define   COL2	21
#define   COL3	22
#define   COL4	23

/* ADC Pins */
#define   ADC0	24

/* Motor Pins */
#define   MOTORIN1	25
#define   MOTORIN2	26
#define   MOTORIEN1	27




/*  Buttons Pins */
#define		BTN0	0
#define		BTN1	1
#define		BTN2	2
#define		BTN3	3

/*  Motor Pins   */
#define     DC1_IN1	7
#define 	DC1_IN2	8
/*  PWM Pin      */
#define     OC0_PIN	9
#define     DC2_IN1	10
#define 	DC2_IN2	11

#endif /* MCAL_DIO_DIO_CFG_H_ */
