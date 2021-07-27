/*****************************************************************************
* Module     : KEYPAD
* File Name  : KEYPAD.c
* Description: Source file for the Keypad driver
* Author     : Kariman Karam
* Date       : 23/7/2021
******************************************************************************/

/*- INCLUDES----------------------------------------------*/
#include "KEYPAD.h"

/*- APIs IMPLEMENTATION-----------------------------------*/
enuErrorStatus_t KeyPad_getPressedKey(uint8_t* u8Key)
{
	uint8_t u8Data;

	while(1)
	{
		DIO_Write(ROWA, LOW);
		DIO_Write(ROWB, HIGH);
		DIO_Write(ROWC, HIGH);
		DIO_Write(ROWD, HIGH);
		DIO_Read(COL1, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 7;
			return E_OK;
		}
		DIO_Read(COL2, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 8;
			return E_OK;
		}
		DIO_Read(COL3, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 9;
			return E_OK;
		}
		DIO_Read(COL4, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = '/';
			return E_OK;
		}

		DIO_Write(ROWB, LOW);
		DIO_Write(ROWA, HIGH);
		DIO_Write(ROWC, HIGH);
		DIO_Write(ROWD, HIGH);
		DIO_Read(COL1, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 4;
			return E_OK;
		}
		DIO_Read(COL2, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 5;
			return E_OK;
		}
		DIO_Read(COL3, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 6;
			return E_OK;
		}
		DIO_Read(COL4, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = '*';
			return E_OK;
		}

		DIO_Write(ROWC, LOW);
		DIO_Write(ROWB, HIGH);
		DIO_Write(ROWA, HIGH);
		DIO_Write(ROWD, HIGH);
		DIO_Read(COL1, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 1;
			return E_OK;
		}
		DIO_Read(COL2, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 2;
			return E_OK;
		}
		DIO_Read(COL3, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 3;
			return E_OK;
		}
		DIO_Read(COL4, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = '-';
			return E_OK;
		}

		DIO_Write(ROWD, LOW);
		DIO_Write(ROWB, HIGH);
		DIO_Write(ROWC, HIGH);
		DIO_Write(ROWA, HIGH);
		DIO_Read(COL1, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 'N';
			return E_OK;
		}
		DIO_Read(COL2, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = 0;
			return E_OK;
		}
		DIO_Read(COL3, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = '=';
			return E_OK;
		}
		DIO_Read(COL4, &u8Data);
		if(u8Data==LOW)
		{
			*u8Key = '+';
			return E_OK;
		}

//		return E_ERROR;
	}//end while
}//end KeyPad_getPressedKey
