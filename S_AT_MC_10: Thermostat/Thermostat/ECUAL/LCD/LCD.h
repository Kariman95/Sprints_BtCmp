
/*****************************************************************************
* Module     : LCD
* File Name  : LCD.h
* Description: Header file for the LCD driver
* Author     : Kariman Karam
* Date       : 24/7/2021
******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

/*- INCLUDES -----------------------------------------------*/
#include "../../LIB/BIT_math.h"
#include "../../LIB/Data_types.h"
#include "../../MCAL/DIO/DIO_cfg.h"
#include "../../MCAL/DIO/DIO_init.h"
#include "../../MCAL/DIO/DIO_registers.h"


/*- Preprocessor Macros -----------------------------------------------*/

/* LCD Data bits mode configuration */
#define DATA_BITS_MODE 4

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

#undef UPPER_PORT_PINS /* Use the lower 4-bits in the data port */

/* LCD HW Pins */
/*
#define RS                            PB1
#define RW                            PB2
#define E                             PB3
*/
//#define LCD_CTRL_PORT                 PORTB
//#define LCD_CTRL_PORT_DIR             DDRB
#define LCD_DATA_PORT                 PORTB_R
//#define LCD_DATA_PORT_DIR             DDRD

/* LCD Commands */
#define CLEAR_COMMAND                 0x01
#define FOUR_BITS_DATA_MODE           0x02
#define TWO_LINE_LCD_Four_BIT_MODE    0x28
#define TWO_LINE_LCD_Eight_BIT_MODE   0x38
#define CURSOR_OFF                    0x0C
#define CURSOR_ON                     0x0E
#define SET_CURSOR_LOCATION           0x80

/*- FUNCTION DECLARATIONS ----------------------------------*/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to send command to LCD
*************************************************************************************************/
void LCD_sendCommand(uint8_t u8Command);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display a character on the LCD
*************************************************************************************************/
void LCD_displayCharacter(uint8_t u8Data);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display a string on the LCD
*************************************************************************************************/
void LCD_displayString(const uint8_t *pu8Str);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the LCD
*************************************************************************************************/
void LCD_init(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to clear the screen of the LCD
*************************************************************************************************/
void LCD_clearScreen(void);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display a string with particular row and column
*************************************************************************************************/
void LCD_displayStringRowColumn(uint8_t u8Row, uint8_t u8Col,const uint8_t *pu8Str);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to set the cursor in a particular row and column
*************************************************************************************************/
void LCD_goToRowColumn(uint8_t u8Row, uint8_t u8Col);

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display integer
*************************************************************************************************/
void LCD_intgerToString(uintt16_t u16Data);

#endif /* LCD_H_ */
