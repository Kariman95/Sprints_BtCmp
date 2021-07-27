/*****************************************************************************
* Module     : LCD
* File Name  : LCD.h
* Description: Source file for the LCD driver
* Author     : Kariman Karam
* Date       : 24/7/2021
******************************************************************************/

/*- INCLUDES -----------------------------------------------*/
#include "LCD.h"
#include <avr/delay.h>
#include <stdlib.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to initialize the LCD
*************************************************************************************************/
void LCD_init(void)
{
	/* Configure the control pins(E,RS,RW) as output pins */
	/* Configure the lowest 4 bits of the data port as output pins */
	DIO_Init();
	
	/* initialize LCD in 4-bit mode */
	LCD_sendCommand(FOUR_BITS_DATA_MODE);
	/* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE);

	/* cursor off */
	LCD_sendCommand(CURSOR_OFF);
	/* clear LCD at the beginning */
	LCD_sendCommand(CLEAR_COMMAND);
}//end LCD_init

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to send command to LCD
*************************************************************************************************/
void LCD_sendCommand(uint8_t u8Command)
{
	/* Instruction Mode RS=0 */
	DIO_Write(RS, LOW);
	/* write data to LCD so RW=0 */
	DIO_Write(RW, LOW);
	/* delay for processing Tas = 50ns */
	_delay_ms(1);
	/* Enable LCD E=1 */
	DIO_Write(E, HIGH);
	/* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((u8Command & 0xF0) >> 4);

	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* disable LCD E=0 */
	DIO_Write(E, LOW);
	/* delay for processing Th = 13ns */
	_delay_ms(1);
	/* Enable LCD E=1 */
	DIO_Write(E, HIGH);
	/* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	/* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (u8Command & 0x0F);
	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* disable LCD E=0 */
	DIO_Write(E, LOW);
	/* delay for processing Th = 13ns */
	_delay_ms(1);
}//end LCD_sendCommand

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display a character on the LCD
*************************************************************************************************/
void LCD_displayCharacter(uint8_t u8Data)
{
	/* Data Mode RS=1 */
	DIO_Write(RS, HIGH);
	/* write data to LCD so RW=0 */
	DIO_Write(RW, LOW);
	/* delay for processing Tas = 50ns */
	_delay_ms(1);
	/* Enable LCD E=1 */
	DIO_Write(E, HIGH);
	/* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	/* out the highest 4 bits of the required data to the data bus D4 --> D7 */
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((u8Data & 0xF0) >> 4);
	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* disable LCD E=0 */
	DIO_Write(E, LOW);
	/* delay for processing Th = 13ns */
	_delay_ms(1);
	/* Enable LCD E=1 */
	DIO_Write(E, HIGH);
	/* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	/* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (u8Data & 0x0F);
	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);
	/* disable LCD E=0 */
	DIO_Write(E, LOW);
	/* delay for processing Th = 13ns */
	_delay_ms(1);
}//end LCD_displayCharacter

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display a string on the LCD
*************************************************************************************************/
void LCD_displayString(const uint8_t *pu8Str)
{
	uint8_t u8I = 0;
	while(pu8Str[u8I] != '\0')
	{
		LCD_displayCharacter(pu8Str[u8I]);
		u8I++;
	}
	/***************** Another Method ***********************
	while((*pu8Str) != '\0')
	{
		LCD_displayCharacter(*pu8Str);
		pu8Str++;
	}		
	*********************************************************/
}//end LCD_displayString

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to set the cursor in a particular row and column
*************************************************************************************************/
void LCD_goToRowColumn(uint8_t u8Row, uint8_t u8Col)
{
	uint8_t u8Address;
	
	/* first of all calculate the required address */
	switch(u8Row)
	{
		case 0:
				u8Address=u8Col;
				break;
		case 1:
				u8Address=u8Col+0x40;
				break;
		case 2:
			    u8Address=u8Col+0x10;
				break;
		case 3:
				u8Address=u8Col+0x50;
				break;
	}					
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(u8Address | SET_CURSOR_LOCATION);
}//end LCD_goToRowColumn

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display a string with particular row and column
*************************************************************************************************/
void LCD_displayStringRowColumn(uint8_t u8Row, uint8_t u8Col, const uint8_t *pu8Str)
{
	/* go to to the required LCD position */
	LCD_goToRowColumn(u8Row, u8Col);
	/* display the string */
	LCD_displayString(pu8Str);
}//end LCD_displayStringRowColumn

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to display integer
*************************************************************************************************/
void LCD_intgerToString(uintt16_t u16Data)
{
	/* String to hold the ascii result */
   uint8_t strBuff[16];
   itoa(u16Data, strBuff, 10); /* 10 for decimal */
   LCD_displayString(strBuff);
}//end LCD_intgerToString

/*************************************************************************************************
* Parameters (in) : None
* Parameters (out): None
* Return Value    : void
* Description     : A function to clear the screen of the LCD
*************************************************************************************************/
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display 
}//end LCD_clearScreen
